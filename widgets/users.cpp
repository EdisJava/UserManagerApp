#include "users.h"
#include "ui_users.h"
#include "UserForm.h"

#include <QMessageBox>
#include <QStandardItemModel>
#include <QDebug>

Users::Users(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Users),
    model(new QStandardItemModel(this)),
    dao(),  // Instancia de UsuarioDAO
    userForm(nullptr)  // Inicializar puntero userForm
{
    ui->setupUi(this);
    ui->listView->setModel(model);

    // Configurar label de foto
    ui->labelFoto->setAlignment(Qt::AlignCenter);
    ui->labelFoto->setText("Sin foto");
    ui->labelFoto->setMinimumSize(150, 150);

    // Cargar usuarios desde la BD al abrir
    cargarUsuarios();

    // Conectar clic sobre lista para mostrar datos
    connect(ui->listView, &QListView::clicked, this, &Users::on_listView_clicked);
}

Users::~Users()
{
    delete userForm; // Liberar memoria si fue creado
    delete ui;
}

void Users::cargarUsuarios()
{
    QString errorMsg;
    listaUsuarios = dao.listarUsuarios("", errorMsg);  // Carga todos sin filtro

    if (!errorMsg.isEmpty()) {
        QMessageBox::critical(this, tr("Error al cargar usuarios"), errorMsg);
        return;
    }

    model->clear();
    for (const QVariantMap &usuario : listaUsuarios) {
        QString nombre = usuario.value("nombre").toString();
        QStandardItem *item = new QStandardItem(nombre);
        model->appendRow(item);
    }

    ui->listView->setModel(model);

    if (!listaUsuarios.isEmpty()) {
        QModelIndex firstIndex = model->index(0, 0);
        ui->listView->setCurrentIndex(firstIndex);
        on_listView_clicked(firstIndex);
    } else {
        ui->labelFoto->clear();
        ui->labelFoto->setText("Sin foto");
    }
}

void Users::on_btnAddUser_clicked()
{
    UserForm form(&dao, this); // Crear formulario modal

    if (form.exec() == QDialog::Accepted) {
        QVariantMap nuevoUsuario = form.getUserData();

        QString errorMsg;
        if (!dao.insertarUsuario(nuevoUsuario, errorMsg)) {
            QMessageBox::critical(this, tr("Error al insertar usuario"), errorMsg);
        } else {
            cargarUsuarios();
        }
    }
}

void Users::on_btnEditUser_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    if (!index.isValid())
        return;

    QVariantMap usuario = listaUsuarios.at(index.row());

    UserForm form(&dao, this);
    form.setUserData(usuario);

    if (form.exec() == QDialog::Accepted) {
        QVariantMap usuarioActualizado = form.getUserData();

        QString errorMsg;
        if (!dao.actualizarUsuario(usuarioActualizado, errorMsg)) {
            QMessageBox::critical(this, tr("Error al actualizar usuario"), errorMsg);
        } else {
            cargarUsuarios();
        }
    }
}

void Users::on_btnDeleteUser_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    if (!index.isValid())
        return;

    QVariantMap usuario = listaUsuarios.at(index.row());

    if (usuario.value("nombre").toString().toLower() == "admin") {
        QMessageBox::warning(this, tr("Aviso"), tr("No se puede eliminar el usuario admin."));
        return;
    }

    QString errorMsg;
    if (!dao.eliminarUsuario(usuario.value("dni").toString(), errorMsg)) {
        QMessageBox::critical(this, tr("Error al eliminar usuario"), errorMsg);
    } else {
        cargarUsuarios();
    }
}

void Users::on_listView_clicked(const QModelIndex &index)
{
    if (!index.isValid())
        return;

    QVariantMap usuario = listaUsuarios.at(index.row());

    QString rutaFoto = usuario.value("foto").toString().trimmed();

    if (!rutaFoto.isEmpty()) {
        QPixmap pixmap(rutaFoto);

        if (!pixmap.isNull()) {
            ui->labelFoto->setPixmap(pixmap.scaled(ui->labelFoto->size(),
                                                   Qt::KeepAspectRatio,
                                                   Qt::SmoothTransformation));
            ui->labelFoto->setText("");
        } else {
            qDebug() << "No se pudo cargar la imagen desde esa ruta:" << rutaFoto;
            ui->labelFoto->setText("Foto no válida");
            ui->labelFoto->setPixmap(QPixmap());
        }
    } else {
        ui->labelFoto->setText("Sin foto");
        ui->labelFoto->setPixmap(QPixmap());
    }
}

void Users::abrirUserFormConDatos(const QVariantMap &datos)
{
    // Si userForm no está creado, crear la instancia una vez
    if (!userForm)
        //userForm = new UserForm(&dao, this);

    // Cargar datos en el formulario
    userForm->setUserData(datos);

    // Mostrar formulario como ventana independiente no modal (puedes cambiar exec() si quieres modal)
    userForm->show();
    userForm->raise();
    userForm->activateWindow();
}

void Users::on_btnAgregarUsuario_clicked()
{
    if (!userForm)
        userForm = new UserForm(&dao, this);  // ← ahora pasamos &dao y this

    userForm->show();
    userForm->raise();
    userForm->activateWindow();
}

void Users::setEmpresaFiltro(const QString &empresa)
{
    empresaFiltro = empresa;
    cargarUsuarios();  // Asegúrate de que esta función recargue la lista con el filtro aplicado
}
