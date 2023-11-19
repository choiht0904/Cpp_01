#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
using namespace std;

class UI {
public:
    static int showMenu() {
        int num;
        cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
        cin >> num;
        return num;
    }

    static int showOptions() {
        int num;
        cout << "선:1, 원:2, 사각형:3 >> ";
        cin >> num;
        return num;
    }

    static int showDelete() {
        int num;
        cout << "삭제하고자 하는 도형의 인덱스 >> ";
        cin >> num;
        return num;
    }

    static void showShapes(Shape* p) {
        int num = 0;
        while(p != NULL) {
            cout << num << ": ";
            num++;
            p->paint();
            p = p->getNext();
        }
    }
};

class GraphicEditor {
    Shape *pStart;
    Shape *pLast;
public:
    GraphicEditor() {
        pStart = NULL;
        pLast = NULL;
    }
    void run() {
        int num;
        cout << "그래픽 에디터입니다." << endl;
        while(true) {
            num = UI::showMenu();
            if(num == 1) {
                insertShape();
            } else if(num == 2) {
                deleteShape();
            } else if(num == 3) {
                UI::showShapes(pStart);
            } else if(num == 4) {
                break;
            }
        }
    }

    void insertShape() {
        int num = UI::showOptions();
        switch(num) {
            case 1:
                if(pStart == NULL) {
                    pStart = new Line();
                    pLast = pStart;
                } else {
                    pLast = pLast->add(new Line());
                }
                break;
            case 2:
                if(pStart == NULL) {
                    pStart = new Circle();
                    pLast = pStart;
                } else {
                    pLast = pLast->add(new Circle());
                }
                break;
            case 3:
                if(pStart == NULL) {
                    pStart = new Rect();
                    pLast = pStart;
                } else {
                    pLast = pLast->add(new Rect());
                }
                break;
            default:
                cout << "잘못된 입력입니다." << endl;
                break;
        }
    }

    void deleteShape() {
        int index = UI::showDelete();
        int currentIndex = 0;
        Shape* currentShape = pStart;
        Shape* previousShape = NULL;

        if(pStart == NULL) {
            return;
        }

        if(index == 0) {
            if(pStart->getNext() != NULL) {
                pStart = pStart->getNext();
            } else {
                pStart = NULL;
            }
            delete currentShape;
        } else {
            while(currentIndex != index) {
                previousShape = currentShape;
                currentShape = currentShape->getNext();
                currentIndex++;
            }

            previousShape->add(currentShape->getNext());

            if(currentShape->getNext() == NULL) {
                pLast = previousShape;
            }

            delete currentShape;
        }
    }
};

int main() {
    GraphicEditor graphicEditor;
    graphicEditor.run();
}