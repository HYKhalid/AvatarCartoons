//
//  DataAccessBridge.h
//  AvatarCartoon
//
//  Created by Hassan Yar Khalid  on 02/09/2017.
//  Copyright © 2017 Hassan Yar Khalid . All rights reserved.
//

//  DEVELOPER NOTES:-
//  ****************************************************************************************/
//  Header for the Objective-C++ implementation that wraps around
//  the underlying DataAccessManager to expose data required by
//  the app to display the avatars.
//  ****************************************************************************************/

#ifndef DataAccessBridge_h
#define DataAccessBridge_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface DataAccessBridge : NSObject
@property(nonatomic) void* networkManagerObj;
@property(nonatomic) NSMutableArray* avatarViewModelList;

-(void) setAvatarViewModelList;
-(NSMutableArray*) getAvatarIDList;
-(NSMutableArray*) getAssetListForAvatarID: (NSInteger) theAvatarID;
-(NSString*) getImageURLForAssetID: (NSInteger) theAssetID;

@end

#endif /* DataAccessBridge_h */
