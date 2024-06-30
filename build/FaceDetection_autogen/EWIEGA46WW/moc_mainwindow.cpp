/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FaceExtractionWorker_t {
    QByteArrayData data[11];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FaceExtractionWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FaceExtractionWorker_t qt_meta_stringdata_FaceExtractionWorker = {
    {
QT_MOC_LITERAL(0, 0, 20), // "FaceExtractionWorker"
QT_MOC_LITERAL(1, 21, 15), // "progressUpdated"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 8), // "progress"
QT_MOC_LITERAL(4, 47, 18), // "extractionFinished"
QT_MOC_LITERAL(5, 66, 9), // "faceCount"
QT_MOC_LITERAL(6, 76, 10), // "logMessage"
QT_MOC_LITERAL(7, 87, 7), // "message"
QT_MOC_LITERAL(8, 95, 15), // "displayLastFace"
QT_MOC_LITERAL(9, 111, 8), // "filePath"
QT_MOC_LITERAL(10, 120, 7) // "process"

    },
    "FaceExtractionWorker\0progressUpdated\0"
    "\0progress\0extractionFinished\0faceCount\0"
    "logMessage\0message\0displayLastFace\0"
    "filePath\0process"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FaceExtractionWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       6,    1,   45,    2, 0x06 /* Public */,
       8,    1,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void FaceExtractionWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FaceExtractionWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->progressUpdated((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->extractionFinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->logMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->displayLastFace((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->process(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FaceExtractionWorker::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FaceExtractionWorker::progressUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FaceExtractionWorker::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FaceExtractionWorker::extractionFinished)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FaceExtractionWorker::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FaceExtractionWorker::logMessage)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FaceExtractionWorker::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FaceExtractionWorker::displayLastFace)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FaceExtractionWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FaceExtractionWorker.data,
    qt_meta_data_FaceExtractionWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FaceExtractionWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FaceExtractionWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FaceExtractionWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FaceExtractionWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void FaceExtractionWorker::progressUpdated(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FaceExtractionWorker::extractionFinished(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FaceExtractionWorker::logMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FaceExtractionWorker::displayLastFace(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[298];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 27), // "on_selectFileButton_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 32), // "on_selectOutputDirButton_clicked"
QT_MOC_LITERAL(4, 73, 29), // "on_extractFacesButton_clicked"
QT_MOC_LITERAL(5, 103, 31), // "on_stopExtractionButton_clicked"
QT_MOC_LITERAL(6, 135, 34), // "on_fpsComboBox_currentIndexCh..."
QT_MOC_LITERAL(7, 170, 5), // "index"
QT_MOC_LITERAL(8, 176, 21), // "handleProgressUpdated"
QT_MOC_LITERAL(9, 198, 8), // "progress"
QT_MOC_LITERAL(10, 207, 24), // "handleExtractionFinished"
QT_MOC_LITERAL(11, 232, 9), // "faceCount"
QT_MOC_LITERAL(12, 242, 16), // "handleLogMessage"
QT_MOC_LITERAL(13, 259, 7), // "message"
QT_MOC_LITERAL(14, 267, 21), // "handleDisplayLastFace"
QT_MOC_LITERAL(15, 289, 8) // "filePath"

    },
    "MainWindow\0on_selectFileButton_clicked\0"
    "\0on_selectOutputDirButton_clicked\0"
    "on_extractFacesButton_clicked\0"
    "on_stopExtractionButton_clicked\0"
    "on_fpsComboBox_currentIndexChanged\0"
    "index\0handleProgressUpdated\0progress\0"
    "handleExtractionFinished\0faceCount\0"
    "handleLogMessage\0message\0handleDisplayLastFace\0"
    "filePath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    1,   63,    2, 0x08 /* Private */,
       8,    1,   66,    2, 0x08 /* Private */,
      10,    1,   69,    2, 0x08 /* Private */,
      12,    1,   72,    2, 0x08 /* Private */,
      14,    1,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Float,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   15,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_selectFileButton_clicked(); break;
        case 1: _t->on_selectOutputDirButton_clicked(); break;
        case 2: _t->on_extractFacesButton_clicked(); break;
        case 3: _t->on_stopExtractionButton_clicked(); break;
        case 4: _t->on_fpsComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->handleProgressUpdated((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 6: _t->handleExtractionFinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->handleLogMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->handleDisplayLastFace((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
