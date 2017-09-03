//
//  NetworkManager.cpp
//  AvatarCartoon
//
//  Created by Hassan Yar Khalid  on 02/09/2017.
//  Copyright © 2017 Hassan Yar Khalid . All rights reserved.
//

#include "NetworkManager.hpp"

NetworkManager* NetworkManager::m_ptrSharedInstance;

NetworkManager::NetworkManager() {
    curl_global_init(CURL_GLOBAL_SSL);
}

NetworkManager::~NetworkManager() {
    curl_global_cleanup();
}

NetworkManager* NetworkManager::getInstance() {
    if(m_ptrSharedInstance == nullptr) {
        m_ptrSharedInstance = new NetworkManager();
    }
    return m_ptrSharedInstance;
}

size_t NetworkManager::callback(const char *in, size_t size, size_t num, string *out) {
    const size_t totalBytes(size * num);
    out->append(in, totalBytes);
    return totalBytes;
}

Value* NetworkManager::getJSONFromURL(string a_strURL) {
    m_ptrCURL = curl_easy_init();
    curl_easy_setopt(m_ptrCURL, CURLOPT_URL, a_strURL.c_str());
    curl_easy_setopt(m_ptrCURL, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
    curl_easy_setopt(m_ptrCURL, CURLOPT_TIMEOUT, 10);
    curl_easy_setopt(m_ptrCURL, CURLOPT_FOLLOWLOCATION, 1L);
    
    // Response information.
    int httpCode(0);
    unique_ptr<string> httpData(new string());
    curl_easy_setopt(m_ptrCURL, CURLOPT_WRITEFUNCTION, callback);
    curl_easy_setopt(m_ptrCURL, CURLOPT_WRITEDATA, httpData.get());
    
    // Run our HTTP GET command, capture the HTTP response code, and clean up.
    curl_easy_perform(m_ptrCURL);
    curl_easy_getinfo(m_ptrCURL, CURLINFO_RESPONSE_CODE, &httpCode);
    curl_easy_cleanup(m_ptrCURL);
    
    Value* jsonData = nullptr;
    if (httpCode == 200) {
        cout << "\nGot successful response from " << a_strURL << std::endl;
        //Value jsonData;
        jsonData = new Value();
        Reader jsonReader;
        if (jsonReader.parse(*httpData, *jsonData)) {
            cout<<"JSON Data successfully Read"<<endl;
        }
        else {
            cout<<"Could not parse HTTP data as JSON"<<endl;
            cout<<"HTTP data was:\n" << *httpData.get()<<endl;
        }
    }
    else {
        cout<<"Couldn't GET from "<<a_strURL<<" - exiting"<<endl;
    }
    
    return jsonData;
}
