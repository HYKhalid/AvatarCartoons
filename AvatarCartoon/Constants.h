//
//  Constants.h
//  AvatarCartoon
//
//  Created by Hassan Yar Khalid  on 02/09/2017.
//  Copyright © 2017 Hassan Yar Khalid . All rights reserved.
//

#ifndef Constants_h
#define Constants_h

#include <string>
using namespace std;

enum eDataDictType {
    AvatarData,
    AssetData
};

typedef unordered_map<int, AssetModel*>::const_iterator AssetMapIterator;
typedef pair<int, AvatarModel*> AvatarMapEntry;

static const string ASSETS_DATA_URL  = "https://s3.eu-central-1.amazonaws.com/wolf3d/Assignments/Simple+Avatar+App/Assets.js";
static const string AVATARS_DATA_URL = "https://s3.eu-central-1.amazonaws.com/wolf3d/Assignments/Simple+Avatar+App/Avatars.js";

static const string ASSET_ID_KEY        = "id";
static const string ASSET_URL_KEY       = "url";
static const string ASSET_ROOT_KEY      = "assets";
static const string ASSET_TYPE_KEY      = "type";

static const string HAT_ASSET_KEY       = "hat";
static const string FACE_ASSET_KEY      = "face";
static const string BEARD_ASSET_KEY     = "beard";
static const string SHIRT_ASSET_KEY     = "shirt";

static const string AVATAR_ROOT_KEY     = "avatars";
static const string AVATAR_GENDER_KEY   = "gender";
static const string AVATAR_ASSETS_KEY   = "assets";
static const string AVATAR_ID_KEY       = "avatarid";
static const string AVATAR_CREATED_KEY  = "created";

#endif /* Constants_h */
