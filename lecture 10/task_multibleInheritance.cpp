#include <iostream>


class Drawable {
public:
    
    virtual void draw() const = 0; // Pure virtual function
    virtual ~Drawable() = default; // Virtual destructor 
};


class Circle : public Drawable {
public:
    void draw() const override {
        std::cout << "Drawing a Circle" << std::endl;
    }
};

class Rectangle : public Drawable {
public:
    void draw() const override {
        std::cout << "Drawing a Rectangle" << std::endl;
    }
};

class Triangle : public Drawable {
public:
    void draw() const override {
        std::cout << "Drawing a Triangle" << std::endl;
    }
};


int main() {
   
    Circle circle;
    Rectangle rectangle;
    Triangle triangle;


    Drawable* drawable1 = &circle;
    Drawable* drawable2 = &rectangle;
    Drawable* drawable3 = &triangle;

  
    drawable1->draw();
    drawable2->draw();
    drawable3->draw();

    return 0;
}
