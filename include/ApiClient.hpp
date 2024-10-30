#ifndef API_CLIENT_HPP
#define API_CLIENT_HPP

#include bits/stdc++.h

// #include <unordered_map>

class ApiClient {
public:
    ApiClient(const string& apiKey, const string& apiSecret);
    std::string sendRequest(const string& endpoint, const unordered_map<std::string, std::string>& params);
    
private:
    string apiKey;
    string apiSecret;
    string baseUrl;
    
    string authenticate(); 
};

#endif
