
#include <vector>

typedef struct Point {
    union {
        struct {
            float x;
            float y;
        };
        float e[2];
    };
} Point;

class Shape {
public:
    Shape(const Shape&) = delete;
    Shape& operator=(const Shape&) = delete;

    Shape(Shape &&)=delete;
    Shape& operator=(Shape&&)=delete;

    virtual Point center() const = 0;
    virtual void move(Point to) = 0;

    virtual void draw() const = 0;
    virtual void rotate(int angle) = 0;

    virtual ~Shape() {}
};
