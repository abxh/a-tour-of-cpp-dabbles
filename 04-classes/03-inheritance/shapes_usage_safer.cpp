#include "shapes.h"
#include <iostream>
#include <istream>
#include <memory>

enum class Kind { circle, smiley };

std::unique_ptr<Shape> read_shape(std::istream& is){

    Kind k;
    Point p;
    int r;
    Circle* e1 = new Circle{p,r};
    Circle* e2 = new Circle{p,r};
    Circle* m = new Circle{p,r};

    switch (k) {
    case Kind::circle:
        return std::unique_ptr<Shape>{new Circle{p, r}};
    case Kind::smiley:
        Smiley* ps = new Smiley{p, r};
        ps->add_eye(e1);
        ps->add_eye(e2);
        ps->set_mouth(m);
        return std::unique_ptr<Shape>{ps}; 
    }
}

void user() {
    std::vector<std::unique_ptr<Shape>> v;
    while (std::cin) {
        v.push_back(read_shape(std::cin));
    }
    // draw_all(v);
    // rotate_all(v, 45);

    // All shapes are implicitly destroyed.
}
