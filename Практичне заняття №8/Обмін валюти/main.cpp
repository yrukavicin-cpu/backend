#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>

int main(int argc, char** argv){
    QApplication app(argc, argv);

    QWidget w; w.setWindowTitle("Обмін валюти");

    auto buy  = new QRadioButton("Купівля");
    auto sell = new QRadioButton("Продаж");
    sell->setChecked(true);

    auto l1=new QLabel("Курс купівлі");
    auto l2=new QLabel("Курс продажу");
    auto l3=new QLabel("=>");
    auto l4=new QLabel("Сума, грн");

    auto e1=new QLineEdit("40.00");
    auto e2=new QLineEdit("41.20");
    auto e3=new QLineEdit("20");
    auto e4=new QLineEdit; e4->setReadOnly(true);

    e1->setToolTip("Введіть курс купівлі");
    e2->setToolTip("Введіть курс продажу");
    e3->setToolTip("Введіть суму в доларах");

    auto calc = new QPushButton("Обчислити");
    auto clear= new QPushButton("Очистити");
    auto quit = new QPushButton("Вихід");

    QObject::connect(buy, &QRadioButton::clicked, [&](){ l3->setText("<="); e3->setFocus(); });
    QObject::connect(sell,&QRadioButton::clicked,[&](){ l3->setText("=>"); e3->setFocus(); });

    QObject::connect(calc,&QPushButton::clicked,[&](){
        bool ok1,ok2,ok3;
        double f1=e1->text().toDouble(&ok1);
        double f2=e2->text().toDouble(&ok2);
        double f3=e3->text().toDouble(&ok3);
        if(!ok1||!ok2||!ok3){ e4->setText("bad"); return; }
        double f4 = buy->isChecked() ? f1*f3 : f2*f3;
        e4->setText(QString::number(f4,'f',2));
    });
    QObject::connect(clear,&QPushButton::clicked,[&](){ e3->clear(); e4->clear(); e3->setFocus(); });
    QObject::connect(quit ,&QPushButton::clicked,[&](){ QApplication::exit(0); });

    auto top = new QHBoxLayout;
    top->addWidget(buy); top->addWidget(sell); top->addStretch(); top->addWidget(l3);

    auto g = new QGridLayout;
    g->addWidget(l1,0,0); g->addWidget(e1,0,1);
    g->addWidget(l2,1,0); g->addWidget(e2,1,1);
    g->addWidget(new QLabel("Сума, USD"),2,0); g->addWidget(e3,2,1);
    g->addWidget(l4,3,0); g->addWidget(e4,3,1);

    auto btns = new QHBoxLayout;
    btns->addWidget(calc); btns->addWidget(clear); btns->addWidget(quit);

    auto main = new QVBoxLayout(&w);
    main->addLayout(top);
    main->addLayout(g);
    main->addLayout(btns);

    w.resize(420,220);
    w.show();
    return app.exec();
}
