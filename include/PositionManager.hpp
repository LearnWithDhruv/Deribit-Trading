#ifndef POSITION_MANAGER_HPP
#define POSITION_MANAGER_HPP

#include "ApiClient.hpp"

class PositionManager {
public:
    PositionManager(ApiClient& apiClient);
    void displayPositions();

private:
    ApiClient& apiClient;
};

#endif
