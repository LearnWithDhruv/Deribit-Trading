#include "PositionManager.hpp"
#include <json/json.h>
#include <iostream>
#include bits/stdc++.h


PositionManager::PositionManager(ApiClient& apiClient) : apiClient(apiClient) {}

void PositionManager::displayPositions() {
    unordered_map<string, string> params;
    string response = apiClient.sendRequest("/private/get_positions", params);
    
    Json::Value jsonResponse;
    Json::Reader reader;
    if (reader.parse(response, jsonResponse)) {
        for (const auto& position : jsonResponse["result"]) {
            cout << "Instrument: " << position["instrument_name"].asString() << "\n";
            cout << "Size: " << position["size"].asString() << "\n";
            cout << "Entry Price: " << position["average_price"].asString() << "\n";
            cout << "P&L: " << position["floating_profit_loss"].asString() << "\n";
            cout << "-------------------\n";
        }
    } else {
        cerr << "Failed to parse position data." << endl;
    }
}
