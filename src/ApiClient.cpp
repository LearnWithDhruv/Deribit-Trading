#include "ApiClient.hpp"

#include <iostream>
#include bits/stdc++.h
#include <curl/curl.h>   
#include <json/json.h>  

ApiClient::ApiClient(const string& apiKey, const string& apiSecret)
    : apiKey(apiKey), apiSecret(apiSecret), baseUrl("https://test.deribit.com/api/v2") {}

std::string ApiClient::sendRequest(const string& endpoint, const unordered_map<string, string>& params) {
    CURL* curl;
    CURLcode res;
    std::string response;

    curl = curl_easy_init();
    if (curl) {
        std::string url = baseUrl + endpoint + "?";

        for (const auto& param : params) {
            url += param.first + "=" + param.second + "&";
        }
        
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [](void* contents, size_t size, size_t nmemb, string* response) -> size_t {
            response->append((char*)contents, size * nmemb);
            return size * nmemb;
        });
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "cURL error: " << curl_easy_strerror(res) << std::endl;
        }
        
        curl_easy_cleanup(curl);
    }
    return response;
}
