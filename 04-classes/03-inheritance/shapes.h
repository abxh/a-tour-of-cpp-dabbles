
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
    virtual Point center() const = 0;
    virtual void move(Point to) = 0;

    virtual void draw() const = 0;
    virtual void rotate(int angle) = 0;

    virtual ~Shape() {}
};

inline void draw_all(std::vector<Shape*>& v) {
    for (auto p : v) {
        p->draw();
    }
}

inline void rotate_all(std::vector<Shape*>& v, int angle) {
    for (auto p : v) {
        p->rotate(angle);
    }
}

class Circle : public Shape {
public:
    Circle(Point p, int rr);

    Point center() const override { return x; }
    void move(Point to) override { x = to; }
    void draw() const override;
    void rotate(int) override {};

private:
    Point x;
    int r;
};

class Smiley : public Circle {
public:
    Smiley(Point p, int r) : Circle{p, r}, mouth{nullptr} {}
    ~Smiley() {
        delete mouth;
        for (auto p : eyes) {
            delete p;
        }
    }
    void move(Point to) override;
    void draw() const override;
    void rotate(int) override;

    void add_eye(Shape* s) { eyes.push_back(s); }
    void set_mouth(Shape* s);
    virtual void wink(int wink_eye_index);
private:
    std::vector<Shape*> eyes;
    Shape* mouth;
};

inline void Smiley::draw() const {
    Circle::draw();
    for (auto p : eyes) {
        p->draw();
    }
    mouth->draw();
}
