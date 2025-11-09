#include <QtWidgets>

struct Telement{
protected:
    Telement* left; Telement* right;
    Telement(Telement* l, Telement* r):left(l),right(r){}
public:
    virtual ~Telement(){ delete left; delete right; }
    virtual double result()=0;
};

struct Number: Telement{
    double v;
    Number(double x):Telement(nullptr,nullptr),v(x){}
    double result(){ return v; }
};

struct Plus: Telement{
    Plus(Telement*l,Telement*r):Telement(l,r){}
    double result(){ return left->result()+right->result(); }
};

struct Mult: Telement{
    Mult(Telement*l,Telement*r):Telement(l,r){}
    double result(){ return left->result()*right->result(); }
};

static QString stripsp(QString s){ s.remove(' '); return s; }

static int find_op(const QString& s, QChar c){
    for(int i=0;i<s.size();++i) if(s[i]==c) return i;
    return -1;
}

static Telement* form(QString s, double x){
    s=stripsp(s);
    int p=find_op(s,'+');
    if(p>0){
        QString s1=s.left(p), s2=s.mid(p+1);
        return new Plus(form(s1,x), form(s2,x));
    }
    p=find_op(s,'*');
    if(p>0){
        QString s1=s.left(p), s2=s.mid(p+1);
        return new Mult(form(s1,x), form(s2,x));
    }
    if(s=="x") return new Number(x);
    bool ok=false; double v=s.toDouble(&ok);
    return new Number(ok?v:0.0);
}

int main(int argc,char** argv){
    QApplication app(argc,argv);

    QMainWindow w; w.setWindowTitle("Обчислення виразу");

    auto eExpr1=new QLineEdit("x");
    auto eExpr2=new QLineEdit("x*x+2*x+4");
    auto eX=new QLineEdit("1");
    auto cmb=new QComboBox; cmb->setEditable(true); cmb->addItems({"2","3","4"}); cmb->setCurrentText("2");

    auto eOut1=new QLineEdit; eOut1->setReadOnly(true);
    auto eOut2=new QLineEdit; eOut2->setReadOnly(true);

    auto bCalc=new QPushButton("Обчислити");
    auto bClear=new QPushButton("Очистити");
    auto bQuit=new QPushButton("Вихід");

    auto grid=new QGridLayout;
    grid->addWidget(new QLabel("Вираз 1"),0,0); grid->addWidget(eExpr1,0,1,1,3);
    grid->addWidget(new QLabel("Вираз 2"),1,0); grid->addWidget(eExpr2,1,1,1,3);
    grid->addWidget(new QLabel("x ="),2,0);     grid->addWidget(eX,2,1);
    grid->addWidget(new QLabel("Знаків після крапки"),2,2); grid->addWidget(cmb,2,3);
    grid->addWidget(new QLabel("Результат 1"),3,0); grid->addWidget(eOut1,3,1,1,3);
    grid->addWidget(new QLabel("Результат 2"),4,0); grid->addWidget(eOut2,4,1,1,3);

    auto btns=new QHBoxLayout; btns->addWidget(bCalc); btns->addWidget(bClear); btns->addWidget(bQuit);

    auto central=new QWidget; auto lay=new QVBoxLayout(central);
    lay->addLayout(grid); lay->addLayout(btns);
    w.setCentralWidget(central);

    QObject::connect(bCalc,&QPushButton::clicked,[&](){
        bool okx=false; double xv=eX->text().toDouble(&okx);
        bool okd=false; int dec=cmb->currentText().toInt(&okd);
        if(!okx||!okd||dec<0) { eOut1->setText("bad"); eOut2->setText("bad"); return; }
        Telement* t1=form(eExpr1->text(),xv);
        Telement* t2=form(eExpr2->text(),xv);
        double r1=t1->result(), r2=t2->result();
        eOut1->setText(QString::number(r1,'f',dec));
        eOut2->setText(QString::number(r2,'f',dec));
        delete t1; delete t2;
    });
    QObject::connect(bClear,&QPushButton::clicked,[&](){ eOut1->clear(); eOut2->clear(); });
    QObject::connect(bQuit,&QPushButton::clicked,[&](){ QApplication::exit(0); });

    auto menu=w.menuBar()->addMenu("Файл");
    auto aCalc=new QAction("Обчислити"); aCalc->setShortcut(QKeySequence("Ctrl+Enter"));
    auto aQuit=new QAction("Вийти"); aQuit->setShortcut(QKeySequence("Ctrl+Q"));
    menu->addAction(aCalc); menu->addSeparator(); menu->addAction(aQuit);
    QObject::connect(aCalc,&QAction::triggered,bCalc,&QPushButton::click);
    QObject::connect(aQuit,&QAction::triggered,&app,&QApplication::quit);

    w.resize(560,220);
    w.show();
    return app.exec();
}
