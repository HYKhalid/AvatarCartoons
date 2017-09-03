//
//  AvatarViewModel.m
//  AvatarCartoon
//
//  Created by Hassan Yar Khalid  on 02/09/2017.
//  Copyright © 2017 Hassan Yar Khalid . All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AvatarViewModel.h"

@implementation AvatarViewModel
-(id) initWithID:(int)avatarID {
    self = [super init];
    if(self) {
        self.avatarID = avatarID;
        self.avatarFaceURL = @"";
        self.avatarHatURL = @"";
        self.avatarBeardURL = @"";
        self.avatarShirtURL = @"";
    }
    
    return self;
}

@end
