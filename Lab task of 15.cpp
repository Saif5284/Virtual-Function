#include <iostream>
#include <string>

class Garment
{
public:
    Garment(const std::string& name) : name_(name) {}

    virtual std::string getName() const = 0;
    virtual double calculatePrice() const = 0;

protected:
    std::string name_;
};

class Upper : public Garment
{
public:
    Upper(const std::string& name, int collarSize) : Garment(name), collarSize_(collarSize) {}

    virtual int getCollarSize() const = 0;

protected:
    int collarSize_;
};

class Lower : public Garment
{
public:
    Lower(const std::string& name, int waistSize) : Garment(name), waistSize_(waistSize) {}

    virtual int getWaistSize() const = 0;

protected:
    int waistSize_;
};

class Shirt : public Upper
{
public:
    Shirt(const std::string& name, int collarSize, double price) : Upper(name, collarSize), price_(price) {}

    std::string getName() const override { return name_; }
    double calculatePrice() const override { return price_; }
    int getCollarSize() const override { return collarSize_; }

private:
    double price_;
};

class Pajama : public Lower
{
public:
    Pajama(const std::string& name, int waistSize, double price) : Lower(name, waistSize), price_(price) {}

    std::string getName() const override { return name_; }
    double calculatePrice() const override { return price_; }
    int getWaistSize() const override { return waistSize_; }

private:
    double price_;
};

class Trouser : public Lower
{
public:
    Trouser(const std::string& name, int waistSize, double price) : Lower(name, waistSize), price_(price) {}

    std::string getName() const override { return name_; }
    double calculatePrice() const override { return price_; }
    int getWaistSize() const override { return waistSize_; }

private:
    double price_;
};

const int MAX_ITEMS = 10;

int main()
{
    std::cout << "Welcome to the online clothing store!" << std::endl;

    Garment* shoppingCart[MAX_ITEMS];
    int numItems = 0;

    while (true)
    {
        std::cout << "Please choose an option:" << std::endl;
        std::cout << "1. Add an item to the shopping cart" << std::endl;
        std::cout << "2. Remove an item from the shopping cart" << std::endl;
        std::cout << "3. View items in the shopping cart" << std::endl;
        std::cout << "4. Checkout" << std::endl;
        std::cout << "5. Exit" << std::endl;

        int option;

