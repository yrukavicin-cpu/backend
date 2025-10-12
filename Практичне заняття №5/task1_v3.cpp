#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Player {
    char surname[64];
    int points;
};

int main() {
    int n;
    if (!(cin >> n) || n <= 0 || n > 1000) return 0;
    Player a[1000], b[1000];
    for (int i = 0; i < n; ++i) cin >> a[i].surname >> a[i].points;

    FILE* fp = fopen("FOOT", "wb");
    if (!fp) return 0;
    fwrite(a, sizeof(Player), n, fp);
    fclose(fp);

    fp = fopen("FOOT", "rb");
    if (!fp) return 0;
    size_t m = fread(b, sizeof(Player), n, fp);
    fclose(fp);

    for (size_t i = 0; i + 1 < m; ++i)
        for (size_t j = 0; j + 1 < m - i; ++j)
            if (b[j].points < b[j+1].points) {
                Player t = b[j]; b[j] = b[j+1]; b[j+1] = t;
            }

    int k = m < 3 ? (int)m : 3;
    for (int i = 0; i < k; ++i)
        cout << b[i].surname << " " << b[i].points << "\n";
    return 0;
}