//
//  AssetModel.hpp
//  AvatarCartoon
//
//  Created by Hassan Yar Khalid  on 02/09/2017.
//  Copyright © 2017 Hassan Yar Khalid . All rights reserved.
//

//  Asset Model/Descriptor class

#ifndef AssetModel_hpp
#define AssetModel_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

//  DEVELOPER NOTES:-
//  ****************************************************************************************/
//  enum used to query the different kinds of assets available in the API,
//  makes it easier to use switches in DAL instead of multiple if/else statements
//  ****************************************************************************************/

enum eAssetType {
    Hat,
    Beard,
    Face,
    Shirt
};

class AssetModel {
public:
    AssetModel();
    virtual ~AssetModel();
    AssetModel(int a_intAssetID, string a_strAssetType, string a_strAssetURL);
    
    int getAssetID();
    string getAssetType();
    string getAssetImgURL();
    void setAssetID(int a_intAssetID);
    void setAssetType(string a_strAssetType);
    void setAssetImgURL(string a_strAssetURL);
    
private:
    int m_intAssetID;
    string m_strAssetType;
    string m_strAssetImgURL;
};

#endif /* AssetModel_hpp */
