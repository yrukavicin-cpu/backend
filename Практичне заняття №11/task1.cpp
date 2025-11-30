#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <cstdlib>
using namespace std;

struct Telement {
    Telement *left, *right;
    Telement(Telement* L = 0, Telement* R = 0) { left = L; right = R; }
    virtual ~Telement() { delete left; delete right; }
    virtual double rezult() { return 0; }
    virtual Telement* copy() { return new Telement(); }
    virtual Telement* differ() { return new Telement(); }
    virtual void set_vars(double X, double R) {
        if (left) left->set_vars(X, R);
        if (right) right->set_vars(X, R);
    }
};

struct Real : Telement {
    double f;
    Real(double F) : Telement(0, 0) { f = F; }
    double rezult() { return f; }
    Telement* copy() { return new Real(f); }
    Telement* differ() { return new Real(0); }
};

struct Var : Telement {
    char name;
    double v;
    Var(char n) : Telement(0, 0) { name = n; v = 0; }
    double rezult() { return v; }
    Telement* copy() { return new Var(name); }
    Telement* differ() {
        if (name == 'x' || name == 'X') return new Real(1);
        else return new Real(0);
    }
    void set_vars(double X, double R) {
        if (name == 'x' || name == 'X') v = X;
        else v = R;
    }
};

struct Plus : Telement {
    Plus(Telement* L, Telement* R) : Telement(L, R) {}
    double rezult() { return left->rezult() + right->rezult(); }
    Telement* copy() { return new Plus(left->copy(), right->copy()); }
    Telement* differ() { return new Plus(left->differ(), right->differ()); }
};

struct Minus : Telement {
    Minus(Telement* L, Telement* R) : Telement(L, R) {}
    double rezult() { return left->rezult() - right->rezult(); }
    Telement* copy() { return new Minus(left->copy(), right->copy()); }
    Telement* differ() { return new Minus(left->differ(), right->differ()); }
};

struct Mult : Telement {
    Mult(Telement* L, Telement* R) : Telement(L, R) {}
    double rezult() { return left->rezult() * right->rezult(); }
    Telement* copy() { return new Mult(left->copy(), right->copy()); }
    Telement* differ() {
        return new Plus(
            new Mult(left->differ(), right->copy()),
            new Mult(left->copy(), right->differ())
        );
    }
};

struct Div : Telement {
    Div(Telement* L, Telement* R) : Telement(L, R) {}
    double rezult() { return left->rezult() / right->rezult(); }
    Telement* copy() { return new Div(left->copy(), right->copy()); }
    Telement* differ() {
        return new Div(
            new Minus(
                new Mult(left->differ(), right->copy()),
                new Mult(left->copy(), right->differ())
            ),
            new Mult(right->copy(), right->copy())
        );
    }
};

struct Sin;
struct Cos;

struct Sin : Telement {
    Sin(Telement* L) : Telement(L, 0) {}
    double rezult() { return sin(left->rezult()); }
    Telement* copy() { return new Sin(left->copy()); }
    Telement* differ();
};

struct Cos : Telement {
    Cos(Telement* L) : Telement(L, 0) {}
    double rezult() { return cos(left->rezult()); }
    Telement* copy() { return new Cos(left->copy()); }
    Telement* differ();
};

Telement* Sin::differ() {
    return new Mult(left->differ(), new Cos(left->copy()));
}

Telement* Cos::differ() {
    return new Mult(new Real(-1), new Mult(left->differ(), new Sin(left->copy())));
}

string trim(string s) {
    int a = 0;
    int b = (int)s.size() - 1;
    while (a <= b && isspace((unsigned char)s[a])) a++;
    while (b >= a && isspace((unsigned char)s[b])) b--;
    if (a > b) return "";
    return s.substr(a, b - a + 1);
}

int posFromEnd(string s, char op) {
    int d = 0;
    for (int i = (int)s.size() - 1; i >= 0; i--) {
        if (s[i] == ')') d++;
        else if (s[i] == '(') d--;
        else if (d == 0 && s[i] == op) return i;
    }
    return -1;
}

Telement* form(string expr) {
    string s = trim(expr);
    if (s.empty()) return new Real(0);
    if (s.size() >= 5 && s.substr(0, 4) == "sin(" && s[s.size() - 1] == ')') {
        return new Sin(form(s.substr(4, s.size() - 5)));
    }
    if (s.size() >= 5 && s.substr(0, 4) == "cos(" && s[s.size() - 1] == ')') {
        return new Cos(form(s.substr(4, s.size() - 5)));
    }
    if (s.front() == '(' && s.back() == ')') {
        int d = 0;
        int ok = 1;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') d++;
            else if (s[i] == ')') d--;
            if (d == 0 && i != (int)s.size() - 1) ok = 0;
        }
        if (ok) return form(s.substr(1, s.size() - 2));
    }
    int p = posFromEnd(s, '+');
    if (p > 0) return new Plus(form(s.substr(0, p)), form(s.substr(p + 1)));
    p = posFromEnd(s, '-');
    if (p > 0) return new Minus(form(s.substr(0, p)), form(s.substr(p + 1)));
    p = posFromEnd(s, '*');
    if (p > 0) return new Mult(form(s.substr(0, p)), form(s.substr(p + 1)));
    p = posFromEnd(s, '/');
    if (p > 0) return new Div(form(s.substr(0, p)), form(s.substr(p + 1)));
    if (s == "x" || s == "X") return new Var('x');
    if (s == "r" || s == "R") return new Var('r');
    double v = atof(s.c_str());
    return new Real(v);
}

int main() {
    string texpr, sexpr;
    cout << "Введіть математичну модель часу t(x,r):\n";
    getline(cin, texpr);
    cout << "Введіть математичну модель шляху s(x,r):\n";
    getline(cin, sexpr);
    double X, R;
    cout << "Введіть значення x:\n";
    cin >> X;
    cout << "Введіть значення параметра r:\n";
    cin >> R;
    int dig;
    cout << "Введіть кількість знаків після десяткової крапки:\n";
    cin >> dig;

    Telement* t = form(texpr);
    Telement* s = form(sexpr);
    Telement* s1 = s->differ();
    Telement* s2 = s1->differ();
    Telement* s3 = s2->differ();

    t->set_vars(X, R);
    s->set_vars(X, R);
    s1->set_vars(X, R);
    s2->set_vars(X, R);
    s3->set_vars(X, R);

    cout.setf(ios::fixed);
    cout << setprecision(dig);
    cout << "t(x,r) = " << t->rezult() << "\n";
    cout << "s(x,r) = " << s->rezult() << "\n";
    cout << "швидкість s'(x) = " << s1->rezult() << "\n";
    cout << "прискорення s''(x) = " << s2->rezult() << "\n";
    cout << "третя похідна s'''(x) = " << s3->rezult() << "\n";

    delete s3;
    delete s2;
    delete s1;
    delete s;
    delete t;
    return 0;
}
