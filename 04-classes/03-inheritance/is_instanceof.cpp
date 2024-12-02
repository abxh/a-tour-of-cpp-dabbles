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

void m() {
    Shape* ps {read_shape(std::cin)};
    if (Smiley* p = dynamic_cast<Smiley*>(ps)) { // warning: dynamic_cast may throw!
        // p is similar to ps
    } else {
        // ps is not similar to ps (not derived)
    }
}
