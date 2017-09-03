//
//  AvatarViewModel.h
//  AvatarCartoon
//
//  Created by Hassan Yar Khalid  on 02/09/2017.
//  Copyright © 2017 Hassan Yar Khalid . All rights reserved.
//

//  DEVELOPER NOTES:-
//  ****************************************************************************************/
//  Light View-Side Model holding the avatar ID and the image URLs
//  that will be queried for a given Avatar model. A list of View models
//  is held by the DataAccessBridge.
//  ****************************************************************************************/

#ifndef AvatarViewModel_h
#define AvatarViewModel_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface AvatarViewModel : NSObject

@property (nonatomic, assign) int avatarID;
@property (nonatomic, strong) NSString* avatarFaceURL;
@property (nonatomic, strong) NSString* avatarHatURL;
@property (nonatomic, strong) NSString* avatarBeardURL;
@property (nonatomic, strong) NSString* avatarShirtURL;

-(id) initWithID: (int)avatarID;
@end

#endif /* AvatarViewModel_h */
