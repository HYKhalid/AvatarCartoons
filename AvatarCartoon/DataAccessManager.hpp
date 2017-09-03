//
//  DataAccessManager.hpp
//  AvatarCartoon
//
//  Created by Hassan Yar Khalid  on 02/09/2017.
//  Copyright © 2017 Hassan Yar Khalid . All rights reserved.
//

//  DEVELOPER NOTES:-
//  ****************************************************************************************/
//  Main Data Access Layer Class, uses two unordered lists with key(int: Avatar/Asset IDs)
//  to store assets and avatars models against. Allows constant lookup times if required.
//  Exposes getters because the application description suggested that data communication
//  is one way for now. But Enabling communication to be two way would only require minimal
//  effort from here on

//  Another possible solution for this task could have been to implement serializers and
//  deserializers on both the Data-side descriptors and the view side models. For Example
//  Serializing the AvatarModel would have turned the class defination/properties into a single
//  JSON-styled string. This string could then be passed through a thin Obj-C wrapper to the
//  view where it would be deserialized into a model class instance. This would require JSON
//  parsing capabilities on both the Data-Side and the View-side. And if the view required
//  more than just Data from the underlying C++ Layer(processing for propriety algos etc) then
//  a messaging protocol would possibly be needed to be established aswell to marshall processing
//  requests.
//  ****************************************************************************************/

#ifndef DataAccessManager_hpp
#define DataAccessManager_hpp

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "json/json.h"
#include "AssetModel.hpp"
#include "AvatarModel.hpp"
#include "Constants.h"
using namespace std;
using namespace Json;

class DataAccessManager {
public:
    DataAccessManager();
    ~DataAccessManager();
    void loadDataFromJson();
    vector<int>* getAvatarModelIDList();
    AssetModel* getAssetModelForID(int a_intAssetID);
    AvatarModel* getAvatarModelForID(int a_intAvatarID);
    AssetModel* getAvatarAssetForAssetType(eAssetType a_eType, int a_intAvatarID);
    
private:
    void initializeAssetsDict(Value* m_ptrJsonRoot);
    void initializeAvatarsDict(Value* m_ptrJsonRoot);
    
    unordered_map<int, AssetModel*>* m_ptrAssetModelDict;
    unordered_map<int, AvatarModel*>* m_ptrAvatarModelDict;
};

#endif /* DataAccessManager_hpp */
