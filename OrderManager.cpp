#include "OrderManager.hpp"
#include <json/json.h>

OrderManager::OrderManager(ApiClient& apiClient) : apiClient(apiClient) {}

string OrderManager::placeOrder(const Order& order) {
    std::unordered_map<string, string> params = {
        {"instrument_name", order.symbol},
        {"type", order.type},
        {"side", order.side},
        {"price", std::to_string(order.price)},
        {"amount", std::to_string(order.quantity)}
    };
    
    std::string response = apiClient.sendRequest("/private/buy", params);
    return response;
}

bool OrderManager::cancelOrder(const string& orderId) {
    unordered_map<string, string> params = { {"order_id", orderId} };
    
    string response = apiClient.sendRequest("/private/cancel", params);
    return response.find("success") != std::string::npos;
}

bool OrderManager::modifyOrder(const string& orderId, double newPrice) {
    if (cancelOrder(orderId)) {
        Order modifiedOrder;
        modifiedOrder.orderId = orderId;
        modifiedOrder.price = newPrice;

        string response = placeOrder(modifiedOrder);
        return !response.empty();
    }
    return false;
}
