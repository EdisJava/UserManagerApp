#include "UserForm.h"
#include "ui_UserForm.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QFileInfo>
#include <QDir>
#include <QFrame>
#include <QPalette>

// Constructor del formulario de usuario
UserForm::UserForm(UsuarioDAO* dao, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserForm),
    dao(dao)  // Se guarda el puntero al DAO para acceder a métodos externos
{
    ui->setupUi(this);

    // Cargar opciones de departamentos y empresas desde la BD
    cargarDepartamentosYEmpresas();

    // Añadir roles disponibles al comboBox con su valor interno
    ui->comboBoxRol->addItem("Admin Total", "admin");
    ui->comboBoxRol->addItem("Admin de Empresa", "adminempresa");
    ui->comboBoxRol->addItem("Usuario Estándar", "usuario");

    // Añadir estados posibles
    ui->comboBoxEstado->addItem("Activo", "activo");
    ui->comboBoxEstado->addItem("Inactivo", "inactivo");
    ui->comboBoxEstado->addItem("Suspendido", "suspendido");

    // Configurar etiqueta de previsualización de imagen
    ui->labelPreviewImage->setText("Previsualización");
    ui->labelPreviewImage->setAlignment(Qt::AlignCenter);
    ui->labelPreviewImage->setFrameShape(QFrame::Box);

    // Validación visual del DNI a medida que se escribe
    connect(ui->lineEditDni, &QLineEdit::textChanged, this, &UserForm::validarVisualmenteDNI);
}

// Destructor
UserForm::~UserForm()
{
    delete ui;
}

// Cargar datos de departamentos y empresas desde la base de datos
void UserForm::cargarDepartamentosYEmpresas()
{
    ui->comboBoxDepartamento->clear();
    ui->comboBoxEmpresa->clear();

    QString error;

    // Obtener lista de departamentos
    QList<QVariantMap> departamentos = dao->listarDepartamentos(error);
    if (!error.isEmpty()) {
        QMessageBox::warning(this, "Error", "Error al cargar departamentos:\n" + error);
    }
    for (const QVariantMap &dep : departamentos) {
        ui->comboBoxDepartamento->addItem(dep.value("nombre").toString(), dep.value("id"));
    }

    // Obtener lista de empresas
    QList<QVariantMap> empresas = dao->listarEmpresas(error);
    if (!error.isEmpty()) {
        QMessageBox::warning(this, "Error", "Error al cargar empresas:\n" + error);
    }
    for (const QVariantMap &emp : empresas) {
        ui->comboBoxEmpresa->addItem(emp.value("nombre").toString(), emp.value("id"));
    }
}

// Establecer datos en el formulario a partir de un mapa
void UserForm::setUserData(const QVariantMap &data)
{
    ui->lineEditDni->setText(data.value("dni").toString());
    ui->lineEditNombre->setText(data.value("nombre").toString());
    ui->lineEditTelefono->setText(data.value("telefono").toString());
    ui->lineEditEmail->setText(data.value("email").toString());

    // Seleccionar departamento correspondiente
    int idxDept = ui->comboBoxDepartamento->findData(data.value("departamento"));
    if (idxDept != -1) ui->comboBoxDepartamento->setCurrentIndex(idxDept);

    // Seleccionar empresa correspondiente
    int idxEmp = ui->comboBoxEmpresa->findData(data.value("empresa"));
    if (idxEmp != -1) ui->comboBoxEmpresa->setCurrentIndex(idxEmp);

    // Seleccionar rol correspondiente
    int idxRol = ui->comboBoxRol->findData(data.value("rol"));
    if (idxRol != -1) ui->comboBoxRol->setCurrentIndex(idxRol);

    // Seleccionar estado correspondiente
    int idxEstado = ui->comboBoxEstado->findData(data.value("estado"));
    if (idxEstado != -1) ui->comboBoxEstado->setCurrentIndex(idxEstado);

    // Cargar foto si está disponible
    QString rutaFoto = data.value("foto").toString().replace('\\', '/');
    if (!rutaFoto.isEmpty()) {
        QPixmap pixmap(rutaFoto);
        if (!pixmap.isNull()) {
            ui->labelPreviewImage->setPixmap(pixmap.scaled(ui->labelPreviewImage->size(),
                                                           Qt::KeepAspectRatio,
                                                           Qt::SmoothTransformation));
            ui->lineEditFoto->setText(rutaFoto);
        } else {
            ui->labelPreviewImage->setText("No se pudo cargar la imagen");
            ui->lineEditFoto->clear();
        }
    } else {
        // Si no hay foto, mostrar texto por defecto
        ui->labelPreviewImage->setText("Previsualización");
        ui->labelPreviewImage->setPixmap(QPixmap());
        ui->lineEditFoto->clear();
    }
}

// Recuperar los datos del formulario en forma de QVariantMap
QVariantMap UserForm::getUserData() const
{
    QVariantMap data;
    data["dni"] = ui->lineEditDni->text().trimmed();
    data["nombre"] = ui->lineEditNombre->text().trimmed();
    data["telefono"] = ui->lineEditTelefono->text().trimmed();
    data["email"] = ui->lineEditEmail->text().trimmed();
    data["departamento"] = ui->comboBoxDepartamento->currentData();
    data["empresa"] = ui->comboBoxEmpresa->currentData();
    data["rol"] = ui->comboBoxRol->currentData();
    data["estado"] = ui->comboBoxEstado->currentData();
    data["foto"] = ui->lineEditFoto->text().trimmed();
    return data;
}

// Botón Guardar: validaciones mínimas antes de cerrar con aceptación
void UserForm::on_btnGuardar_clicked()
{
    QVariantMap usuario = getUserData();

    if (usuario["dni"].toString().isEmpty()) {
        QMessageBox::warning(this, "Validación", "El DNI es obligatorio.");
        return;
    }

    if (usuario["nombre"].toString().isEmpty()) {
        QMessageBox::warning(this, "Validación", "El nombre es obligatorio.");
        return;
    }

    // Aquí se podrían añadir más validaciones (email, teléfono, etc.)

    accept();  // Cierra el formulario con estado Accepted
}

// Botón Cancelar: cierra el formulario sin guardar
void UserForm::on_btnCancelar_clicked()
{
    reject();  // Cierra el formulario con estado Rejected
}

// Botón para seleccionar una imagen de foto de usuario
void UserForm::on_btnSeleccionarFoto_clicked()
{
    QString ruta = QFileDialog::getOpenFileName(this,
                                                tr("Seleccionar foto"),
                                                QDir::homePath(),
                                                tr("Imágenes (*.png *.jpg *.jpeg *.bmp)"));

    if (ruta.isEmpty())
        return;

    QFileInfo info(ruta);
    if (!info.exists() || !info.isFile()) {
        QMessageBox::warning(this, "Error", "Archivo no válido.");
        return;
    }

    QPixmap pixmap;
    if (!pixmap.load(ruta)) {
        ui->labelPreviewImage->setPixmap(QPixmap());
        ui->labelPreviewImage->setText("No se pudo cargar la imagen");
        QMessageBox::warning(this, "Error", "No se pudo cargar la imagen seleccionada.");
        return;
    }

    // Mostrar la imagen seleccionada redimensionada
    ui->labelPreviewImage->setPixmap(pixmap.scaled(ui->labelPreviewImage->size(),
                                                   Qt::KeepAspectRatio,
                                                   Qt::SmoothTransformation));
    ui->labelPreviewImage->setText("");  // Quitar texto por defecto
    ui->lineEditFoto->setText(ruta.replace('\\', '/'));  // Guardar ruta
}

// Validación visual del campo DNI (rojo si es incorrecto)
void UserForm::validarVisualmenteDNI(const QString &dni)
{
    QPalette palette = ui->lineEditDni->palette();

    // Verificar longitud y formato del DNI
    if (dni.length() != 9) {
        palette.setColor(QPalette::Base, QColor(255, 200, 200));  // fondo rojo claro
        ui->lineEditDni->setPalette(palette);
        return;
    }

    QString numeros = dni.left(8);
    QChar letra = dni.at(8).toUpper();

    bool ok;
    int num = numeros.toInt(&ok);
    if (!ok) {
        palette.setColor(QPalette::Base, QColor(255, 200, 200));
        ui->lineEditDni->setPalette(palette);
        return;
    }

    // Comprobar letra del DNI
    static const QString letras = "TRWAGMYFPDXBNJZSQVHLCKE";
    int pos = num % 23;

    if (letra == letras.at(pos)) {
        palette.setColor(QPalette::Base, Qt::white);  // válido
    } else {
        palette.setColor(QPalette::Base, QColor(255, 200, 200));  // inválido
    }

    ui->lineEditDni->setPalette(palette);
}
