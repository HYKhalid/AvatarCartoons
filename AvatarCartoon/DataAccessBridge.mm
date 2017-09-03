//
//  DataAccessBridge.m
//  AvatarCartoon
//
//  Created by Hassan Yar Khalid  on 02/09/2017.
//  Copyright © 2017 Hassan Yar Khalid . All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DataAccessBridge.h"
#import "AvatarViewModel.h"

#include "DataAccessManager.hpp"

@implementation DataAccessBridge

-(id) init {
    self  = [super init];
    DataAccessManager* dam = new DataAccessManager;
    dam->loadDataFromJson();
    self.networkManagerObj = (void*) dam;
    self.avatarViewModelList = [[NSMutableArray alloc] init];
    [self setAvatarViewModelList];
    return self;
}

-(void) dealloc {
    DataAccessManager* dam = (DataAccessManager*) self.networkManagerObj;
    delete dam;
}

-(void) setAvatarViewModelList {
    DataAccessManager* dam = (DataAccessManager*) self.networkManagerObj;
    vector<int>* list = dam->getAvatarModelIDList();
    
    for(int avatarID : *list) {
        AvatarViewModel* ptrViewModel = [[AvatarViewModel alloc] initWithID: avatarID];
        AvatarModel* ptrAvatarModel = dam->getAvatarModelForID(avatarID);
        if(ptrAvatarModel) {
            ptrViewModel.avatarFaceURL = [NSString stringWithUTF8String: ptrAvatarModel->getAvatarAssetImageURL(Face).c_str()];
            ptrViewModel.avatarHatURL = [NSString stringWithUTF8String: ptrAvatarModel->getAvatarAssetImageURL(Hat).c_str()];
            ptrViewModel.avatarBeardURL = [NSString stringWithUTF8String: ptrAvatarModel->getAvatarAssetImageURL(Beard).c_str()];
            ptrViewModel.avatarShirtURL = [NSString stringWithUTF8String: ptrAvatarModel->getAvatarAssetImageURL(Shirt).c_str()];
        }
        
        [[self avatarViewModelList] addObject:ptrViewModel];
    }
}

-(NSMutableArray*) getAvatarIDList {
    DataAccessManager* dam = (DataAccessManager*) self.networkManagerObj;
    vector<int>* list = dam->getAvatarModelIDList();
    
    NSMutableArray *nsList = [NSMutableArray array];
    for(int ID : *list) {
        NSNumber* n = [NSNumber numberWithInt:ID];
        [nsList addObject:n];
    }
    
    return nsList;
}

-(NSMutableArray*) getAssetListForAvatarID:(NSInteger) theAvatarID {
    DataAccessManager* dam = (DataAccessManager*) self.networkManagerObj;
    int avatarID = (int) theAvatarID;
    vector<int> list = dam->getAvatarModelForID(avatarID)->getAvatarAssetsList();
    
    NSMutableArray *nsList = [NSMutableArray array];
    for(int ID : list) {
        NSNumber* n = [NSNumber numberWithInt:ID];
        [nsList addObject:n];
    }
    
    return nsList;
}

-(NSString*) getImageURLForAssetID:(NSInteger) theAssetID {
    DataAccessManager* dam = (DataAccessManager*) self.networkManagerObj;
    int assetID = (int) theAssetID;
    string imageURL = dam->getAssetModelForID(assetID)->getAssetImgURL();
    NSString* nsImageURL = [NSString stringWithUTF8String:imageURL.c_str()];
    return nsImageURL;
}

@end
