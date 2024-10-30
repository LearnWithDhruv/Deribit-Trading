#include <iostream>
#include <string>

#include bits/stdc++.h
#include <json/json.h>
#include <fstream>
#include "ApiClient.hpp"
#include "OrderManager.hpp"
#include "PositionManager.hpp"
#include "OrderbookManager.hpp"

void loadConfig(const string& filepath, string& apiKey, string& apiSecret, string& baseUrl, string& defaultSymbol) {
    ifstream configFile(filepath, ifstream::binary);
    Json::Value config;
    configFile >> config;

    apiKey = config["apiKey"].asString();
    apiSecret = config["apiSecret"].asString();
    baseUrl = config["baseUrl"].asString();
    defaultSymbol = config["defaultSymbol"].asString();
}

int main() {
    string apiKey, apiSecret, baseUrl, defaultSymbol;
    loadConfig("config/config.json", apiKey, apiSecret, baseUrl, defaultSymbol);

    ApiClient apiClient(apiKey, apiSecret);  
    OrderManager orderManager(apiClient);
    PositionManager positionManager(apiClient);
    OrderbookManager orderbookManager(apiClient);

    int choice;
    while (true) {
        cout << "Order Management System\n";
        cout << "1. Place Order\n2. Cancel Order\n3. Modify Order\n4. View Positions\n5. View Orderbook\n6. Exit\n";
        cout << "Select an option: ";
        cin >> choice;

        if (choice == 1) {
            Order order;
            cout << "Enter symbol (default: " << defaultSymbol << "): ";
            cin >> order.symbol;
            cout << "Enter order type (limit, market): ";
            cin >> order.type;
            cout << "Enter side (buy, sell): ";
            cin >> order.side;
            cout << "Enter price: ";
            cin >> order.price;
            cout << "Enter quantity: ";
            cin >> order.quantity;
            
            string response = orderManager.placeOrder(order);
            cout << "Order placed: " << response << std::endl;

        } else if (choice == 2) {
            string orderId;
            cout << "Enter order ID to cancel: ";
            cin >> orderId;
            if (orderManager.cancelOrder(orderId)) {
                std::cout << "Order canceled successfully.\n";
            } else {
                std::cout << "Failed to cancel order.\n";
            }

        } else if (choice == 3) {
            string orderId;
            double newPrice;
            cout << "Enter order ID to modify: ";
            cin >> orderId;
            cout << "Enter new price: ";
            cin >> newPrice;
            
            if (orderManager.modifyOrder(orderId, newPrice)) {
                std::cout << "Order modified successfully.\n";
            } else {
                std::cout << "Failed to modify order.\n";
            }

        } else if (choice == 4) {
            positionManager.displayPositions();
        } else if (choice == 5) {
            string symbol;
            cout << "Enter symbol for orderbook (default: " << defaultSymbol << "): ";
            cin >> symbol;
            orderbookManager.displayOrderbook(symbol);
        } else {
            break;
        }
    }

    return 0;
}
