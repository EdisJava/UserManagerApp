TEMPLATE = subdirs

SUBDIRS += \
    Database \
    models \
    widgets

# Asegura el orden de compilación
models.depends = Database
widgets.depends = Database
