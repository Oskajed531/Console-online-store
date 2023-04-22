#pragma once
// SklepInternetowy.cpp : Definiuje funkcje biblioteki statycznej.
//
#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Product {
private:
    string name;
    double price;
    int quantity;

public:
    Product(string name, double price, int quantity) {
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }

    Product() { }

    string getName() {
        return this->name;
    }

    double getPrice() {
        return this->price;
    }

    int getQuantity() {
        return this->quantity;
    }

    void setQuantity(int quantity) {
        this->quantity = quantity;
    }
};

class ShoppingCart {
private:
    vector<Product> products;

public:
    void addProduct(Product product) {
        this->products.push_back(product);
    }

    void removeProduct(Product product) {
        for (int i = 0; i < this->products.size(); i++) {
            if (this->products[i].getName() == product.getName()) {
                this->products.erase(this->products.begin() + i);
            }
        }
    }

    double getTotalPrice() {
        double totalPrice = 0;
        for (int i = 0; i < this->products.size(); i++) {
            totalPrice += this->products[i].getPrice() * this->products[i].getQuantity();
        }
        return totalPrice;
    }
};

class Customer {
private:
    string name;
    ShoppingCart cart;

public:
    Customer(string name) {
        this->name = name;
    }
    Customer() {};

    string getName() {
        return this->name;
    }

    ShoppingCart getShoppingCart() {
        return this->cart;
    }
};

class OnlineStore {
private:
    vector<Product> products;
    vector<Customer> customers;

public:
    void addProduct(Product product) {
        this->products.push_back(product);
    }

    void addCustomer(Customer customer) {
        this->customers.push_back(customer);
    }

    Customer getCustomerByName(string name) {
        for (int i = 0; i < this->customers.size(); i++) {
            if (this->customers[i].getName() == name) {
                return this->customers[i];
            }
        }
    }

    Product getProductByName(string name) {
        for (int i = 0; i < this->products.size(); i++) {
            if (this->products[i].getName() == name) {
                return this->products[i];
            }
        }
    }
};

// Klasa reprezentuj¹ca kategoriê produktu
class Category {
private:
    string name;
    vector<Product> products;

public:
    Category(string name) {
        this->name = name;
    }

    string getName() {
        return this->name;
    }

    void addProduct(Product product) {
        this->products.push_back(product);
    }

    vector<Product> getProducts() {
        return this->products;
    }
};

// Klasa reprezentuj¹ca zamówienie
class Order {
private:
    Customer customer;
    vector<Product> products;
    double totalPrice;
    string shippingAddress;
    string paymentMethod;

public:
    Order(Customer customer, vector<Product> products, string shippingAddress, string paymentMethod) {
        this->customer = customer;
        this->products = products;
        this->shippingAddress = shippingAddress;
        this->paymentMethod = paymentMethod;

        this->totalPrice = 0;
        for (int i = 0; i < this->products.size(); i++) {
            this->totalPrice += this->products[i].getPrice() * this->products[i].getQuantity();
        }
    }

    Customer getCustomer() {
        return this->customer;
    }

    vector<Product> getProducts() {
        return this->products;
    }

    double getTotalPrice() {
        return this->totalPrice;
    }

    string getShippingAddress() {
        return this->shippingAddress;
    }

    string getPaymentMethod() {
        return this->paymentMethod;
    }
};

// Klasa reprezentuj¹ca historiê zamówieñ dla klienta
class OrderHistory {
private:
    Customer customer;
    vector<Order> orders;

public:
    OrderHistory(Customer customer) {
        this->customer = customer;
    }

    void addOrder(Order order) {
        this->orders.push_back(order);
    }

    vector<Order> getOrders() {
        return this->orders;
    }
};

// Klasa reprezentuj¹ca informacje o dostawie
class DeliveryInfo {
private:
    string deliveryCompany;
    string trackingNumber;

public:
    DeliveryInfo(string deliveryCompany, string trackingNumber) {
        this->deliveryCompany = deliveryCompany;
        this->trackingNumber = trackingNumber;
    }

    string getDeliveryCompany() {
        return this->deliveryCompany;
    }

    string getTrackingNumber() {
        return this->trackingNumber;
    }
};

// Klasa reprezentuj¹ca kupon rabatowy
class Coupon {
private:
    string code;
    double discount;

public:
    Coupon(string code, double discount) {
        this->code = code;
        this->discount = discount;
    }

    string getCode() {
        return this->code;
    }

    double getDiscount() {
        return this->discount;
    }
};

// Klasa reprezentuj¹ca opcjê dostawy
class ShippingOption {
private:
    string name;
    double price;

public:
    ShippingOption(string name, double price) {
        this->name = name;
        this->price = price;
    }

    string getName() {
        return this->name;
    }

    double getPrice() {
        return this->price;
    }
};

// Klasa reprezentuj¹ca komentarz klienta dotycz¹cy produktu
class ProductReview {
private:
    Customer customer;
    Product product;
    string review;
    int rating;

public:
    ProductReview(Customer customer, Product product, string review, int rating) {
        this->customer = customer;
        this->product = product;
        this->review = review;
        this->rating = rating;
    }

    Customer getCustomer() {
        return this->customer;
    }

    Product getProduct() {
        return this->product;
    }

    string getReview() {
        return this->review;
    }

    int getRating() {
        return this->rating;
    }
};
