#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    if (!in || !out) return 1;

    in >> skipws;

    char c;
    while (!in.eof()) {
        in.get(c);
        if (in.eof()) break;
        if (c == ' ') c = '|';
        out << c;
    }

    in.close();
    out.close();

    return 0;
}
