//
//  AvatarIconCell.swift
//  AvatarCartoon
//
//  Created by Hassan Yar Khalid  on 02/09/2017.
//  Copyright © 2017 Hassan Yar Khalid . All rights reserved.
//

import UIKit

class AvatarIconCell: UICollectionViewCell {
    
    @IBOutlet weak var avatarIDLabel: UILabel!
    
    var viewModel: AvatarViewModel?
    
    override func awakeFromNib() {
        super.awakeFromNib()
        self.layer.masksToBounds = true
        self.layer.cornerRadius = 6
    }

    func setupCell() {
        
        if let avatarData = self.viewModel {
            self.avatarIDLabel.text = String(avatarData.avatarID)
        }
    }
}
