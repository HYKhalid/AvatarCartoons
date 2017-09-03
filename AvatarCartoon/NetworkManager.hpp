//
//  NetworkManager.hpp
//  AvatarCartoon
//
//  Created by Hassan Yar Khalid  on 02/09/2017.
//  Copyright © 2017 Hassan Yar Khalid . All rights reserved.
//

//  DEVELOPER NOTES:-
//  ****************************************************************************************/
//  Singleton Network Manager class that user curl to request data from URL
//  and JsonCpp to read it
//  ****************************************************************************************/

#ifndef NetworkManager_hpp
#define NetworkManager_hpp

#include <iostream>
#include <string>
#include "curl/curl.h"
#include "json/json.h"
using namespace std;
using namespace Json;

class NetworkManager {
public:
    virtual ~NetworkManager();
    static NetworkManager* getInstance();
    Value* getJSONFromURL(string a_strURL);
    
private:
    NetworkManager();
    
    CURL* m_ptrCURL;
    static size_t  callback(const char* in, size_t size, size_t num, string* out);
    static NetworkManager* m_ptrSharedInstance;
};

#endif /* NetworkManager_hpp */
