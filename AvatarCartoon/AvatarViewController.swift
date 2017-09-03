//
//  ViewController.swift
//  AvatarCartoon
//
//  Created by Hassan Yar Khalid  on 02/09/2017.
//  Copyright © 2017 Hassan Yar Khalid . All rights reserved.
//

//  DEVELOPER NOTES:-
//  ****************************************************************************************/
//  Simple View controller class with a collection View and a Container View
//  The ImageViews fetch images asynchronously URLs and an Image Cache
//  To avoid making repeated requests for the same images.
//  ****************************************************************************************/

import UIKit

class AvatarViewController: UIViewController {

    var dataBridge: DataAccessBridge?
    @IBOutlet weak var avatarIconCollectionView: UICollectionView!
    @IBOutlet weak var avatarFaceImageView: UIImageView!
    @IBOutlet weak var avatarShirtImageView: UIImageView!
    @IBOutlet weak var avatarHatImageView: UIImageView!
    @IBOutlet weak var avatarBeardImageView: UIImageView!
    @IBOutlet weak var avatarIDLabel: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        dataBridge = DataAccessBridge()
        avatarIconCollectionView.reloadData()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        if let bridge = dataBridge {
            for val in bridge.getAvatarIDList() {
                print("AVATAR ID: \(val)")
                for assetID in bridge.getAssetList(forAvatarID: val as! Int) {
                    print("Asset: \(assetID)")
                }
            }
            
            for viewModel in bridge.avatarViewModelList {
                if let vm = viewModel as? AvatarViewModel {
                    print("VIEW: \(vm.avatarID)")
                }
            }
            
            
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        self.collectionView(self.avatarIconCollectionView, didSelectItemAt: IndexPath(row: 0, section: 0))
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
}

//MARK:- UI methods
extension AvatarViewController {
    
    func updateAvatar(with viewModel: AvatarViewModel) {
        self.avatarIDLabel.text =  "Avatar ID: \(viewModel.avatarID)"
        self.resetAvatarAsset(view: self.avatarFaceImageView, with: viewModel.avatarFaceURL)
        self.resetAvatarAsset(view: self.avatarHatImageView, with: viewModel.avatarHatURL)
        self.resetAvatarAsset(view: self.avatarBeardImageView, with: viewModel.avatarBeardURL)
        self.resetAvatarAsset(view: self.avatarShirtImageView, with: viewModel.avatarShirtURL)
    }
    
    func resetAvatarAsset(view imageView: UIImageView, with url: String) {
        if url != "" {
            imageView.fetchImageFromURL(urlString: url)
            imageView.isHidden = false
        } else {
            imageView.isHidden = true
        }
    }
}

//MARK:- Collection View delegate methods
extension AvatarViewController: UICollectionViewDelegate, UICollectionViewDataSource, UICollectionViewDelegateFlowLayout {
    
    func numberOfSections(in collectionView: UICollectionView) -> Int {
        return 1
    }
    
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        let count = (dataBridge != nil) ? dataBridge!.avatarViewModelList.count : 0
        return count
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        var cell = collectionView.dequeueReusableCell(withReuseIdentifier: "AvatarIconCell", for: indexPath)
        if let bridge = dataBridge , let avatarCell = cell as? AvatarIconCell {
            if let dataModel = bridge.avatarViewModelList.object(at: indexPath.row) as? AvatarViewModel {
                avatarCell.viewModel = dataModel
                avatarCell.setupCell()
                cell = avatarCell
            }
        }
        
        return cell
    }
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize {
        let cellCount: CGFloat = CGFloat(collectionView.numberOfItems(inSection: 0))
        let width = self.view.frame.width/cellCount
        let height = self.avatarIconCollectionView.frame.height * 0.95
        return CGSize(width: width, height: height)
    }
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        if let bridge = dataBridge, let viewModel = bridge.avatarViewModelList.object(at: indexPath.row) as? AvatarViewModel {
            self.updateAvatar(with: viewModel)
        }
    }
    
}

