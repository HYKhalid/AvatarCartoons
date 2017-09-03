//
//  AvatarModel.hpp
//  AvatarCartoon
//
//  Created by Hassan Yar Khalid  on 02/09/2017.
//  Copyright © 2017 Hassan Yar Khalid . All rights reserved.
//

//  DEVELOPER NOTES:-
//  *********************************************************************************************/
//  Avatar Model/descriptor class, uses unorderd_map with key(avatar type string (face, hat etc.))
//  The use of unordered map helps respective asset models to be accessible in constant time(O(1))
//  *********************************************************************************************/

#ifndef AvatarModel_hpp
#define AvatarModel_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "AssetModel.hpp"
using namespace std;

class AvatarModel {
public:
    AvatarModel();
    virtual ~AvatarModel();
    AvatarModel(int a_intID, string a_strDate, int a_intGender);
    
    void setAvatarID(int a_intAvatarID);
    void setAvatarGender(int a_intAvatarGender);
    void setAvatarDateCreated(string a_strDateString);
    void setAvatarAssetsList(vector<int> a_assetsList);
    
    void addAssetModelToAvatar(AssetModel* a_ptrAssetModel);
    
    int getAvatarID();
    int getAvatarGender();
    string getAvatarDateCreated();
    vector<int> getAvatarAssetsList();
    AssetModel* getAvatarAsset(eAssetType a_eType);
    string getAvatarAssetImageURL(eAssetType a_eType);
    
private:
    int m_intAvatarID;
    int m_intAvatarGender;
    vector<int> m_assetsList;
    string m_strAvatarDateCreated;
    unordered_map<string, AssetModel*>* m_ptrAssetsDict;
    
};

#endif /* AvatarModel_hpp */
