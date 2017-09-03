//
//  Extensions.swift
//  AvatarCartoon
//
//  Created by Hassan Yar Khalid  on 02/09/2017.
//  Copyright © 2017 Hassan Yar Khalid . All rights reserved.
//

//  DEVELOPER NOTES:-
// ****************************************************************************************/
// Extensions for NSCache that provides a shared Instance of NSCache for the Application
// The UIImageView extension provides a method on imageViews in the app to asynchronously
// fetch an image when it is requested. Checks if the image has already been downloaded in
// the cache, if YES then retrieves the stored image and returns, if NO then the image is 
// fetched from the server, returned and stored in the cache for future requests.
// ****************************************************************************************/

import Foundation
import UIKit

let avatarAssetImageCache = NSCache<NSString, AnyObject>.sharedInstance

extension NSCache {
    class var sharedInstance: NSCache<NSString, AnyObject> {
        let cache = NSCache<NSString, AnyObject>();
        cache.name = "AvatarImageAssetsCache"
        cache.countLimit = 30
        cache.totalCostLimit = 15*1024*1024 //15MB
        return cache
    }
}

extension UIImageView {
    public func fetchImageFromURL(urlString: String) {
        if let cachedImage = avatarAssetImageCache.object(forKey: urlString as NSString) {
            self.image = cachedImage as? UIImage
        } else {
            URLSession.shared.dataTask(with: NSURL(string: urlString)! as URL, completionHandler: {[weak self] (data, response, error) -> Void in
                
                if error == nil, let url = response?.url, let downloadData = data, let downloadedImage = UIImage(data: downloadData) {
                    DispatchQueue.main.async() {
                        self?.image = downloadedImage
                        avatarAssetImageCache.setObject(downloadedImage, forKey: url.absoluteString as NSString)
                    }
                    
                } else {
                    print("Failed to set Image")
                }
            }).resume()
        }
    }
}
