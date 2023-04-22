#include "SklepInternetowy.h"

int main() {
	// Tworzenie nowego sklepu internetowego
	OnlineStore onlineStore = OnlineStore();

	// Dodawanie produktów do sklepu
	onlineStore.addProduct(Product("Apple", 0.99, 10));
	onlineStore.addProduct(Product("Banana", 0.59, 20));
	onlineStore.addProduct(Product("Orange", 0.79, 15));

	// Dodawanie kategorii do sklepu
	Category fruitCategory = Category("Fruit");
	fruitCategory.addProduct(onlineStore.getProductByName("Apple"));
	fruitCategory.addProduct(onlineStore.getProductByName("Banana"));
	fruitCategory.addProduct(onlineStore.getProductByName("Orange"));

	// Dodawanie klientów do sklepu
	onlineStore.addCustomer(Customer("John Doe"));
	onlineStore.addCustomer(Customer("Jane Doe"));

	// Pobieranie koszyka zakupowego klienta
	Customer customer = onlineStore.getCustomerByName("John Doe");
	ShoppingCart cart = customer.getShoppingCart();

	// Dodawanie produktów do koszyka zakupowego
	cart.addProduct(onlineStore.getProductByName("Apple"));
	cart.addProduct(onlineStore.getProductByName("Banana"));
	cart.addProduct(onlineStore.getProductByName("Orange"));

	// Obliczanie ca³kowitej ceny produktów w koszyku zakupowym
	double totalPrice = cart.getTotalPrice();

	// Wypisywanie informacji o koszyku zakupowym
	cout << "Total price: " << totalPrice << endl;

	// Tworzenie nowego zamówienia
	vector<Product> products;
	products.push_back(onlineStore.getProductByName("Apple"));
	products.push_back(onlineStore.getProductByName("Banana"));
	Order order = Order(customer, products, "123 Main St", "Visa");

	// Wypisywanie informacji o zamówieniu
	cout << "Customer: " << order.getCustomer().getName() << endl;
	cout << "Total price: " << order.getTotalPrice() << endl;
	cout << "Shipping address: " << order.getShippingAddress() << endl;
	cout << "Payment method: " << order.getPaymentMethod() << endl;

	return 0;
}