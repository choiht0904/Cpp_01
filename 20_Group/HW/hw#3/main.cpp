#include <iostream>
#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
using namespace std;

class UI {
public:
    static int showMenu() {
        int num;
        cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
        cin >> num;
        return num;
    }

    static int showOptions() {
        int num;
        cout << "��:1, ��:2, �簢��:3 >> ";
        cin >> num;
        return num;
    }

    static int showDelete() {
        int num;
        cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
        cin >> num;
        return num;
    }

    static void showShapes(vector<Shape*> &v, vector<Shape*>::iterator &it) {
        int i = 0;
        for(it = v.begin(); it != v.end(); it++, i++){
            cout << i << ": ";
            v.at(i)->paint();
        }

    }
};

class GraphicEditor {
    vector<Shape*> v;
    vector<Shape*>::iterator it;
public:
    GraphicEditor() {
        cout << "�׷��� �������Դϴ�." << endl;
        run();
    }
    void run() {
        while(true) {
            int num = UI::showMenu();
            if(num == 1) {
                insertShape();
            } else if(num == 2) {
                deleteShape();
            } else if(num == 3) {
                UI::showShapes(v, it);
            } else if(num == 4) {
                break;
            }
        }
    }

    void insertShape() {
        int num = UI::showOptions();
        switch(num) {
            case 1:
                v.push_back(new Line);
                break;
            case 2:
                v.push_back(new Circle);
                break;
            case 3:
                v.push_back(new Rect);
                break;
            default:
                cout << "�߸��� �Է��Դϴ�." << endl;
                break;
        }
    }

    void deleteShape() {
        int index = UI::showDelete();

        if(index >= v.size() || index < 0) {
            return;
        }

        it = v.begin();
        Shape* shape = *(it + index);
        v.erase(it + index);
        delete shape;
        return;

    }
};

int main() {
    GraphicEditor graphicEditor;
}