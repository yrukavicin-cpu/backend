інструкція (shell macOS):

clang++ -std=c++17 task1.cpp -o task1

echo "1 0 6.283185 1.570796" | ./task1

ввод: <func_id> <a> <b> <h>
func_id: 1=sin(x)  2=cos(x)  3=exp(x)  4=x^2
x f(x) на відрізку [a,b] з шагом h.


clang++ -std=c++17 task2.cpp -o task2

echo "4 0 1 10" | ./task1
ввод: <func_id> <a> <b> <n>
func_id: 1=sin(x)  2=cos(x)  3=exp(x)  4=x^2
n -число розбивок

echo - для зручності тестування 