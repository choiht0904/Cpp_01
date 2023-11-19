#include <iostream>
#include "Shape.h"
using namespace std;

void Shape::draw() {
    cout << "--Shape--" << endl;
}

void Shape::paint() {
    draw();
}

Shape *Shape::add(Shape *p) {
    this->next = p;
    return p;
}

