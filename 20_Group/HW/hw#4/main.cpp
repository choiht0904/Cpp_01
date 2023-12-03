#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

class Machine {
    map<string, int> m;
    string str[5]= { "Coffee","Sugar","CREAM", "Water","Cup" };
public:
    Machine() {
        cout << "------��ǰ Ŀ�� ���Ǳ��մϴ�.------" << endl;
        for (int i = 0; i < 5; i++) {
            m[str[i]] = 3;
        }
        show();
        menu();
    }

    void coffee() {
        if (!ingredient()) return;
        cout << "���ִ� Ŀ�� ���Խ��ϴ�~~" << endl;
        m[str[0]]--;
        m[str[3]]--;
        m[str[4]]--;
    }
    void sugarCoffee() {
        if (!ingredient()) return;
        cout << "���ִ� ���� Ŀ�� ���Խ��ϴ�~~" << endl;
        m[str[0]]--;
        m[str[1]]--;
        m[str[3]]--;
        m[str[4]]--;
    }
    void blackCoffee() {
        if (!ingredient()) return;
        cout << "���ִ� Ŀ�� ���Խ��ϴ�~~" << endl;
        m[str[0]]--;
        m[str[3]]--;
        m[str[4]]--;
    }

    void fill() {
        cout << "��� ���� ä��ϴ�.~~" << endl;
        for (int i = 0; i < 5; i++) {
            m[str[i]] = 3;
        }
    }
    void show() {
        for (int i = 0; i < 5; i++) {
            cout << setw(8) << left << str[i];
            for (int j = 0; j < m[str[i]]; j++) cout << '*';
            cout << endl;
        }
        cout << endl;
    }
    int ingredient() {
        int t = 0;
        for (int i = 0; i < 5; i++) {
            if (m[str[i]] == 0) {
                t = 1;
                break;
            }
        }
        if (t == 0) return 1;
        else {
            cout << "��ᰡ �����մϴ�..." << endl;
            return 0;
        }
    }

    void menu() {
        int n;
        while (true) {
            cout << "���� Ŀ��:0, ���� Ŀ��:1, �� Ŀ��:2, ä���:3, ����:4>> ";
            cin >> n;
            switch (n) {
                case 0: coffee(); break;
                case 1: sugarCoffee(); break;
                case 2: blackCoffee(); break;
                case 3: fill(); break;
                case 4: return;
            }
            show();
        }
    }
};

int main() {
    Machine machine;
}