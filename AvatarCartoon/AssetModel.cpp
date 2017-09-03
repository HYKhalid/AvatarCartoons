//
//  AssetModel.cpp
//  AvatarCartoon
//
//  Created by Hassan Yar Khalid  on 02/09/2017.
//  Copyright © 2017 Hassan Yar Khalid . All rights reserved.
//

#include "AssetModel.hpp"

AssetModel::AssetModel() {
    
}

AssetModel::AssetModel(int a_intAssetID, string a_strAssetType, string a_strAssetURL) {
    m_intAssetID = a_intAssetID;
    m_strAssetType = a_strAssetType;
    m_strAssetImgURL = a_strAssetURL;
}

AssetModel::~AssetModel() {
    
}

void AssetModel::setAssetID(int a_intAssetID) {
    m_intAssetID = a_intAssetID;
}

void AssetModel::setAssetType(string a_strAssetType) {
    m_strAssetType = a_strAssetType;
}

void AssetModel::setAssetImgURL(string a_strAssetURL) {
    m_strAssetImgURL = a_strAssetURL;
}

int AssetModel::getAssetID() {
    return m_intAssetID;
}

string AssetModel::getAssetType() {
    return m_strAssetType;
}

string AssetModel::getAssetImgURL() {
    return m_strAssetImgURL;
}
