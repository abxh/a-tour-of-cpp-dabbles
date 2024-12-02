#include "shapes.h"
#include <iostream>
#include <istream>

enum class Kind { circle, smiley };

Shape* read_shape(std::istream& is){

    Kind k;
    Point p;
    int r;
    Circle* e1 = new Circle{p,r};
    Circle* e2 = new Circle{p,r};
    Circle* m = new Circle{p,r};

    switch (k) {
    case Kind::circle:
        return new Circle{p, r};
    case Kind::smiley:
        Smiley* ps = new Smiley{p, r};
        ps->add_eye(e1);
        ps->add_eye(e2);
        ps->set_mouth(m);
        return ps; 
    }
}

void user() {
    std::vector<Shape*> v;
    while (std::cin) {
        v.push_back(read_shape(std::cin));
    }
    draw_all(v);
    rotate_all(v, 45);
    for (auto p : v) {
        delete p;
    }
}
