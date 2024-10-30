#include "OrderbookManager.hpp"
#include <json/json.h>
#include <iostream>
#include bits/stdc++.h


OrderbookManager::OrderbookManager(ApiClient& apiClient) : apiClient(apiClient) {}

void OrderbookManager::displayOrderbook(const string& symbol) {
    std::unordered_map<string, string> params = { {"instrument_name", symbol} };
    std::string response = apiClient.sendRequest("/public/get_order_book", params);

    Json::Value jsonResponse;
    Json::Reader reader;
    if (reader.parse(response, jsonResponse)) {
        cout << "Orderbook for " << symbol << "\n";
        cout << "Bids:\n";
        for (const auto& bid : jsonResponse["result"]["bids"]) {
            cout << "Price: " << bid[0].asDouble() << " | Quantity: " << bid[1].asDouble() << "\n";
        }
        
        cout << "\nAsks:\n";
        for (const auto& ask : jsonResponse["result"]["asks"]) {
            cout << "Price: " << ask[0].asDouble() << " | Quantity: " << ask[1].asDouble() << "\n";
        }
    } else {
        std::cerr << "Failed to parse orderbook data." << std::endl;
    }
}
