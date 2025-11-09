#include <QtWidgets>
#include <cmath>

int main(int argc, char** argv){
    QApplication app(argc, argv);

    QMainWindow w; w.setWindowTitle("Табулювання функції");

    auto aEdit=new QLineEdit("-3.141593");
    auto bEdit=new QLineEdit("3.141593");
    auto hEdit=new QLineEdit("0.314159");

    auto grid=new QGridLayout;
    grid->addWidget(new QLabel("Ліва межа"),0,0); grid->addWidget(aEdit,0,1);
    grid->addWidget(new QLabel("Права межа"),1,0); grid->addWidget(bEdit,1,1);
    grid->addWidget(new QLabel("Крок"),2,0);       grid->addWidget(hEdit,2,1);
    grid->addWidget(new QLabel("y = sin(x) + 1"),3,0,1,2,Qt::AlignHCenter);

    auto cbScreen=new QCheckBox("На екран"); cbScreen->setChecked(true);
    auto cbArray=new QCheckBox("У масив");
    auto cbDeriv=new QCheckBox("Похідна");
    auto gb=new QGroupBox("Виведення");
    auto vgb=new QVBoxLayout(gb);
    vgb->addWidget(cbScreen); vgb->addWidget(cbArray); vgb->addWidget(cbDeriv);

    auto memo=new QTextEdit; memo->setAcceptRichText(false); memo->setWordWrapMode(QTextOption::NoWrap);

    auto central=new QWidget;
    auto lay=new QVBoxLayout(central);
    auto top=new QHBoxLayout; top->addLayout(grid); top->addWidget(gb);
    lay->addLayout(top); lay->addWidget(memo,1);
    w.setCentralWidget(central);

    auto actTab=new QAction("Протабулювати"); actTab->setShortcut(QKeySequence("Ctrl+T"));
    auto actClr=new QAction("Очистити поле виведення");
    auto actQuit=new QAction("Вийти"); actQuit->setShortcut(QKeySequence("Ctrl+Q"));
    auto menu=w.menuBar()->addMenu("Обчислення");
    menu->addAction(actTab); menu->addAction(actClr); menu->addSeparator(); menu->addAction(actQuit);

    memo->setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(memo,&QWidget::customContextMenuRequested,[&](const QPoint& p){
        QMenu m; m.addAction(actClr); m.addSeparator(); m.addAction(actQuit); m.exec(memo->mapToGlobal(p));
    });

    QObject::connect(actTab,&QAction::triggered,[&](){
        bool ok1,ok2,ok3;
        double a=aEdit->text().toDouble(&ok1), b=bEdit->text().toDouble(&ok2), h=hEdit->text().toDouble(&ok3);
        if(!ok1||!ok2||!ok3||h<=0){ memo->append("bad"); return; }
        if(a>b) std::swap(a,b);
        QVector<double> ax, ay;
        memo->append("x\ty");
        double mn=std::sin(a)+1, mx=mn; int cnt=0;
        for(double x=a; x<=b+1e-12; x+=h){
            double y=std::sin(x)+1;
            if(cbDeriv->isChecked()){
                double dy=std::cos(x);
                if(cbScreen->isChecked()) memo->append(QString("%1\t%2\t y'=%3").arg(x,0,'f',6).arg(y,0,'f',6).arg(dy,0,'f',6));
            } else {
                if(cbScreen->isChecked()) memo->append(QString("%1\t%2").arg(x,0,'f',6).arg(y,0,'f',6));
            }
            if(cbArray->isChecked()){ ax.push_back(x); ay.push_back(y); }
            if(y<mn) mn=y; if(y>mx) mx=y;
            if(y>0.5 && y<1.0) cnt++;
        }
        memo->append(QString("min=%1, max=%2, in(0.5;1)=%3").arg(mn,0,'f',6).arg(mx,0,'f',6).arg(cnt));
    });

    QObject::connect(actClr,&QAction::triggered,[&](){ memo->clear(); });
    QObject::connect(actQuit,&QAction::triggered,[&](){ QApplication::exit(0); });

    w.resize(720,480);
    w.show();
    return app.exec();
}
