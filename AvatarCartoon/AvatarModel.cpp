//
//  AvatarModel.cpp
//  AvatarCartoon
//
//  Created by Hassan Yar Khalid  on 02/09/2017.
//  Copyright © 2017 Hassan Yar Khalid . All rights reserved.
//

#include "AvatarModel.hpp"
#include "Constants.h"

AvatarModel::AvatarModel() {
    m_ptrAssetsDict = new unordered_map<string, AssetModel*>();
}

AvatarModel::AvatarModel(int a_intID, string a_strDate, int a_intGender) {
    m_intAvatarID = a_intID;
    m_intAvatarGender = a_intGender;
    m_strAvatarDateCreated = a_strDate;
    m_ptrAssetsDict = new unordered_map<string, AssetModel*>();
}

AvatarModel::~AvatarModel() {
    
}

void AvatarModel::setAvatarID(int a_intAvatarID) {
    m_intAvatarID = a_intAvatarID;
}

void AvatarModel::setAvatarDateCreated(string a_strDateString) {
    m_strAvatarDateCreated = a_strDateString;
}

void AvatarModel::setAvatarGender(int a_intAvatarGender) {
    m_intAvatarGender = a_intAvatarGender;
}

void AvatarModel::setAvatarAssetsList(vector<int> a_assetsList) {
    if(m_assetsList.size() > 0) {
        m_assetsList.erase(m_assetsList.begin(), m_assetsList.end());
    }
    
    for(int assetID : a_assetsList) {
        m_assetsList.push_back(assetID);
    }
}

void AvatarModel::addAssetModelToAvatar(AssetModel* a_ptrAssetModel) {
    if(a_ptrAssetModel != nullptr) {
        m_ptrAssetsDict->insert(make_pair(a_ptrAssetModel->getAssetType(), a_ptrAssetModel));
    }
}

AssetModel* AvatarModel::getAvatarAsset(eAssetType a_eType) {
    string assetKey = "";
    AssetModel* ptrAssetModel = new AssetModel();
    switch (a_eType) {
        case Hat:
            assetKey = HAT_ASSET_KEY;
            break;
        case Face:
            assetKey = FACE_ASSET_KEY;
            break;
        case Beard:
            assetKey = BEARD_ASSET_KEY;
            break;
        case Shirt:
            assetKey = SHIRT_ASSET_KEY;
            break;
    }
    
    if(assetKey != "" && m_ptrAssetsDict->size() > 0) {
        auto it = m_ptrAssetsDict->find(assetKey);
        if(it != m_ptrAssetsDict->end()) {
            ptrAssetModel = it->second;
        }
    }
    
    return ptrAssetModel;
}

string AvatarModel::getAvatarAssetImageURL(eAssetType a_eType) {
    AssetModel* ptrAsset = this->getAvatarAsset(a_eType);
    string url = ptrAsset->getAssetImgURL();
    return url;
}

int AvatarModel::getAvatarID() {
    return m_intAvatarID;
}

string AvatarModel::getAvatarDateCreated() {
    return m_strAvatarDateCreated;
}

int AvatarModel::getAvatarGender() {
    return m_intAvatarGender;
}

vector<int> AvatarModel::getAvatarAssetsList() {
    return m_assetsList;
}
