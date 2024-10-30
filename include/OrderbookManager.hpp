#ifndef ORDERBOOK_MANAGER_HPP
#define ORDERBOOK_MANAGER_HPP

#include bits/stdc++.h

#include "ApiClient.hpp"
// #include <string>
// #include <vector>
// #include <utility>

class OrderbookManager {
public:
    OrderbookManager(ApiClient& apiClient);
    void displayOrderbook(const string& symbol);

private:
    ApiClient& apiClient;
};

#endif
