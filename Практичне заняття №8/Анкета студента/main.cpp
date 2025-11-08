#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QHBoxLayout>

int main(int argc, char** argv){
    QApplication app(argc, argv);

    QWidget w; w.setWindowTitle("Анкета студента (2 PNG)");

    auto title = new QLabel("Анкета студента");
    auto info  = new QLabel("ПІБ: Рукавіцин Юрій Вікторович\nГрупа: Alk-43\nХобі: Аудіофіл");
    title->setStyleSheet("font-weight:700; font-size:18px; color:purple;");

    auto img = new QLabel; img->setFixedSize(320,240); img->setScaledContents(true);

    QPixmap p1("portrait.png");
    QPixmap p2("art.png");

    auto bPortrait = new QPushButton("Портрет");
    auto bArt      = new QPushButton("Арт");
    auto bHide     = new QPushButton("Убрать");

    QObject::connect(bPortrait,&QPushButton::clicked,[&](){
        img->setPixmap(p1);
    });
    QObject::connect(bArt,&QPushButton::clicked,[&](){
        img->setPixmap(p2);
    });
    QObject::connect(bHide,&QPushButton::clicked,[&](){
        img->clear();
    });

    auto buttons = new QHBoxLayout;
    buttons->addWidget(bPortrait);
    buttons->addWidget(bArt);
    buttons->addWidget(bHide);

    auto v = new QVBoxLayout(&w);
    v->addWidget(title);
    v->addWidget(info);
    v->addWidget(img);
    v->addLayout(buttons);

    w.resize(400, 420);
    w.show();
    return app.exec();
}
