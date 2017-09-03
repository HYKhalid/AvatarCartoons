//
//  DataAccessManager.cpp
//  AvatarCartoon
//
//  Created by Hassan Yar Khalid  on 02/09/2017.
//  Copyright © 2017 Hassan Yar Khalid . All rights reserved.
//

#include "DataAccessManager.hpp"
#include "NetworkManager.hpp"

DataAccessManager::DataAccessManager() {
    m_ptrAssetModelDict = new unordered_map<int, AssetModel*>();
    m_ptrAvatarModelDict = new unordered_map<int, AvatarModel*>();
}

DataAccessManager::~DataAccessManager() {
    
}

void DataAccessManager::loadDataFromJson() {
    Value* ptrAssetsJsonRoot = NetworkManager::getInstance()->getJSONFromURL(ASSETS_DATA_URL);
    initializeAssetsDict(ptrAssetsJsonRoot);
    
    Value* ptrAvatarsJsonRoot = NetworkManager::getInstance()->getJSONFromURL(AVATARS_DATA_URL);
    initializeAvatarsDict(ptrAvatarsJsonRoot);
}

void DataAccessManager::initializeAssetsDict(Value* a_ptrJsonRoot) {
    if(m_ptrAssetModelDict->size() > 0) {
        m_ptrAssetModelDict->clear();
    }
    
    if(a_ptrJsonRoot && a_ptrJsonRoot->isMember(ASSET_ROOT_KEY)) {
        Value rootObj = *a_ptrJsonRoot;
        for(Value asset : rootObj[ASSET_ROOT_KEY]) {
            if(asset.isMember(ASSET_ID_KEY) && asset.isMember(ASSET_URL_KEY) && asset.isMember(ASSET_TYPE_KEY)) {
                int id = asset[ASSET_ID_KEY].asInt();
                string type = asset[ASSET_TYPE_KEY].asString();
                string url = asset[ASSET_URL_KEY].asString();
                
                AssetModel* ptrAssetModel = new AssetModel(id, type, url);
                m_ptrAssetModelDict->insert(make_pair(id, ptrAssetModel));
            }
        }
    }
}

void DataAccessManager::initializeAvatarsDict(Value* a_ptrJsonRoot) {
    if(m_ptrAvatarModelDict->size() > 0) {
        m_ptrAvatarModelDict->clear();
    }
    
    if(a_ptrJsonRoot && a_ptrJsonRoot->isMember(AVATAR_ROOT_KEY)) {
        Value rootObj = *a_ptrJsonRoot;
        for(Value asset : rootObj[AVATAR_ROOT_KEY]) {
            if(asset.isMember(AVATAR_ID_KEY) && asset.isMember(AVATAR_CREATED_KEY)
               && asset.isMember(AVATAR_GENDER_KEY ) && asset.isMember(AVATAR_ASSETS_KEY)) {
                int id = asset[AVATAR_ID_KEY].asInt();
                string createdDate = asset[AVATAR_CREATED_KEY].asString();
                int gender = asset[AVATAR_GENDER_KEY].asInt();
                AvatarModel* ptrAvatarModel = new AvatarModel(id, createdDate, gender);
                
                vector<int> assetsList;
                for(Value assetID : asset[AVATAR_ASSETS_KEY]) {
                    int id = assetID.asInt();
                    assetsList.push_back(id);
                    AssetModel* ptrAssetModel = this->getAssetModelForID(id);
                    ptrAvatarModel->addAssetModelToAvatar(ptrAssetModel);
                }
                
                ptrAvatarModel->setAvatarAssetsList(assetsList);
                m_ptrAvatarModelDict->insert(make_pair(id, ptrAvatarModel));
            }
        }
    }
}

vector<int>* DataAccessManager::getAvatarModelIDList() {
    vector<int>* avatarIDList = new vector<int>();
    for(AvatarMapEntry avatarMapEntry : *m_ptrAvatarModelDict) {
        avatarIDList->push_back(avatarMapEntry.first);
    }
    
    return avatarIDList;
}

AssetModel* DataAccessManager::getAssetModelForID(int a_intAssetID) {
    AssetModel* ptrAssetModel = nullptr;
    if(m_ptrAssetModelDict->size() > 0) {
        auto it = m_ptrAssetModelDict->find(a_intAssetID);
        if(it != m_ptrAssetModelDict->end()) {
            ptrAssetModel = it->second;
        }
    }
    return ptrAssetModel;
}

AvatarModel* DataAccessManager::getAvatarModelForID(int a_intAvatarID) {
    AvatarModel* ptrAvatarModel = nullptr;
    if(m_ptrAvatarModelDict->size() > 0) {
        auto it = m_ptrAvatarModelDict->find(a_intAvatarID);
        if(it != m_ptrAvatarModelDict->end()) {
            ptrAvatarModel = it->second;
        }
    }
    return ptrAvatarModel;
}

AssetModel* DataAccessManager::getAvatarAssetForAssetType(eAssetType a_eType, int a_intAvatarID) {
    AvatarModel* ptrAvatarModel = this->getAvatarModelForID(a_intAvatarID);
    AssetModel* ptrAssetModel = nullptr;
    if(ptrAvatarModel != nullptr) {
        ptrAssetModel = ptrAvatarModel->getAvatarAsset(a_eType);
    }
    
    return ptrAssetModel;
}
