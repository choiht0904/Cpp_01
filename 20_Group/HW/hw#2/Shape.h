#ifndef WEEK11_SHAPE_H
#define WEEK11_SHAPE_H


class Shape {
    Shape* next;
protected:
    virtual void draw() = 0;
public:
    Shape() {
        next = NULL;
    }
    virtual ~Shape() {

    }
    void paint();
    Shape* add(Shape* p);
    Shape* getNext() {
        return next;
    }
};


#endif //WEEK11_SHAPE_H
