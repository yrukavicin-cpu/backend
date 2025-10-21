#include <iostream>
using namespace std;

class Emploee {
public:
    int id;
    double salary;
};

int main(){
    int n;
    cin>>n;
    Emploee e[100];
    for(int i=0;i<n;i++){
        cin>>e[i].id>>e[i].salary;
    }
    for(int i=0;i<n;i++){
        cout<<e[i].id<<" "<<e[i].salary<<"\n";
    }
    return 0;
}
