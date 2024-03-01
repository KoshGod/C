#include <iostream>
#include <string>

class StationeryShop {
public:
    virtual void display() = 0;
    virtual void buy() = 0;
};

class Pen : public StationeryShop {
private:
    std::string brand;
    float price;
public:
    Pen(std::string brand, float price) : brand(brand), price(price) {}

    void display() override {
        std::cout << "Pen: " << brand << ", Price: " << price << std::endl;
    }

    void buy() override {
        std::cout << "Buying pen: " << brand << std::endl;
    }
};

class Notebook : public StationeryShop {
private:
    int pages;
    float price;
public:
    Notebook(int pages, float price) : pages(pages), price(price) {}

    void display() override {
        std::cout << "Notebook: " << pages << " pages, Price: " << price << std::endl;
    }

    void buy() override {
        std::cout << "Buying notebook with " << pages << " pages" << std::endl;
    }
};

int main() {
    Pen pen("Parker", 2.5);
    Notebook notebook(100, 1.0);

    pen.display();
    pen.buy();

    notebook.display();
    notebook.buy();

    return 0;
}
