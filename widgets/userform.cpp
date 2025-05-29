#include "userform.h"
#include "ui_userform.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

UserForm::UserForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserForm),
    modoEdicion(false)
{
    ui->setupUi(this);
      cargarListasDesdeBD();
}

UserForm::~UserForm()
{
    delete ui;
}




void UserForm::setDatosUsuario(const QString &dni,
                               const QString &nombre,
                               const QString &telefono,
                               const QString &email,
                               const QString &departamento,
                               const QString &empresa,
                               const QString &estado,
                               const QString &foto,
                               const QString &rol)
{
    modoEdicion = true;
    dniOriginal = dni;

    ui->txtDni->setText(dni);
    ui->txtNombre->setText(nombre);
    ui->txtTelefono->setText(telefono);
    ui->txtEmail->setText(email);
    ui->comboBoxDepartamento->setCurrentText(departamento);
    ui->comboBoxEmpresa->setCurrentText(empresa);
    ui->comboBoxEstado->setCurrentText(estado);
    ui->txtImagen->setText(foto);
    ui->comboBoxRol->setCurrentText(rol);

    // Opcional: deshabilitar el cambio de DNI si no quieres que se pueda cambiar
    ui->txtDni->setDisabled(true);
}


bool UserForm::existeUsuario(const QString &dni)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM usuarios WHERE dni = :dni");
    query.bindValue(":dni", dni);
    if (!query.exec()) {
        qDebug() << "Error en consulta existeUsuario:" << query.lastError().text();
        return false;
    }
    if (query.next()) {
        return query.value(0).toInt() > 0;
    }
    return false;
}

void UserForm::on_btnGuardar_clicked()
{
    QString dni = ui->txtDni->text().trimmed();
    QString nombre = ui->txtNombre->text().trimmed();
    QString telefono = ui->txtTelefono->text().trimmed();
    QString email = ui->txtEmail->text().trimmed();
    QString departamento = ui->comboBoxDepartamento->currentText();
    QString empresa = ui->comboBoxEmpresa->currentText();
    QString estado = ui->comboBoxEstado->currentText();
    QString foto = ui->txtImagen->text().trimmed();
    QString rol = ui->comboBoxRol->currentText();

    if (dni.isEmpty() || nombre.isEmpty()) {
        QMessageBox::warning(this, "Datos incompletos", "Debe completar el DNI y el Nombre.");
        return;
    }

    QSqlQuery query;

    if (modoEdicion) {
        // UPDATE
        query.prepare(R"(
            UPDATE usuarios SET
                nombre = :nombre,
                telefono = :telefono,
                email = :email,
                departamento = :departamento,
                empresa = :empresa,
                estado = :estado,
                foto = :foto,
                rol = :rol
            WHERE dni = :dni
        )");

        query.bindValue(":dni", dniOriginal);  // Clave original
    } else {
        // INSERT
        if (existeUsuario(dni)) {
            QMessageBox::warning(this, "Error", "Ya existe un usuario con ese DNI.");
            return;
        }

        query.prepare(R"(
            INSERT INTO usuarios (dni, nombre, telefono, email, departamento, empresa, estado, foto, rol)
            VALUES (:dni, :nombre, :telefono, :email, :departamento, :empresa, :estado, :foto, :rol)
        )");

        query.bindValue(":dni", dni);
    }

    // Comunes a ambos
    query.bindValue(":nombre", nombre);
    query.bindValue(":telefono", telefono);
    query.bindValue(":email", email);
    query.bindValue(":departamento", departamento);
    query.bindValue(":empresa", empresa);
    query.bindValue(":estado", estado);
    query.bindValue(":foto", foto);
    query.bindValue(":rol", rol);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error al guardar", "No se pudo guardar el usuario: " + query.lastError().text());
        return;
    }

    emit usuarioGuardado();
    accept();
}


void UserForm::on_btnExaminar_clicked()
{
    QString archivo = QFileDialog::getOpenFileName(this,
                                                   tr("Seleccionar imagen"),
                                                   QString(),
                                                   tr("Archivos de imagen (*.png *.jpg *.bmp)"));
    if (!archivo.isEmpty()) {
        ui->txtImagen->setText(archivo);
    }
}

QStringList UserForm::getUsuario() const
{
    QStringList datos;
    datos << ui->txtDni->text().trimmed()
          << ui->txtNombre->text().trimmed()
          << ui->txtTelefono->text().trimmed()
          << ui->txtEmail->text().trimmed()
          << ui->comboBoxDepartamento->currentText()
          << ui->comboBoxEmpresa->currentText()
          << ui->comboBoxEstado->currentText()
          << ui->txtImagen->text().trimmed()
          << ui->comboBoxRol->currentText();

    return datos;
}



void UserForm::cargarListasDesdeBD()
{
    // Limpiamos combos
    ui->comboBoxDepartamento->clear();
    ui->comboBoxEmpresa->clear();
    ui->comboBoxEstado->clear();
    ui->comboBoxRol->clear();

    // Cargar departamentos
    QSqlQuery queryDep("SELECT nombre FROM departamentos ORDER BY nombre");
    if (!queryDep.exec()) {
        qDebug() << "Error al cargar departamentos:" << queryDep.lastError().text();
    }
    while (queryDep.next()) {
        ui->comboBoxDepartamento->addItem(queryDep.value(0).toString());
    }

    // Cargar empresas
    QSqlQuery queryEmp("SELECT nombre FROM empresas ORDER BY nombre");
    if (!queryEmp.exec()) {
        qDebug() << "Error al cargar empresas:" << queryEmp.lastError().text();
    }
    while (queryEmp.next()) {
        ui->comboBoxEmpresa->addItem(queryEmp.value(0).toString());
    }

    // Cargar estados fijos
    QStringList estados = {"Activo", "Suspendido", "Inactivo"};
    ui->comboBoxEstado->addItems(estados);

    // Cargar roles fijos
    QStringList roles = {"AdminTotal", "AdminEmpresa", "Usuario"};
    ui->comboBoxRol->addItems(roles);
}


void UserForm::setModoAdminEmpresa(bool esAdminEmpresa)
{
    m_esAdminEmpresa = esAdminEmpresa;

    // Si es admin_empresa, deshabilita el combo o campo empresa para que no se pueda cambiar
    ui->comboBoxEmpresa->setEnabled(!m_esAdminEmpresa);
}

