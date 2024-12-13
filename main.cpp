#include "widget.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "learn002_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    // QPushButton btn;
    Widget w;
    // btn.setParent(&w);
    // btn.setText("崩潰"); //由于对象树机制，被连续释放导致崩溃，需要把bnt的定义放到w后面
    w.show();
    return a.exec();
}
