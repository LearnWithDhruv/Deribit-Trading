#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>

struct Order {
    string orderId;
    string symbol;
    string side;    
    double price;
    double quantity;
    string type;    
};

#endif
