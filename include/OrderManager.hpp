#ifndef ORDER_MANAGER_HPP
#define ORDER_MANAGER_HPP

#include "ApiClient.hpp"
#include "Order.hpp"

class OrderManager {
public:
    OrderManager(ApiClient& apiClient);
    string placeOrder(const Order& order);
    bool cancelOrder(const string& orderId);
    bool modifyOrder(const string& orderId, double newPrice);

private:
    ApiClient& apiClient;
};

#endif
