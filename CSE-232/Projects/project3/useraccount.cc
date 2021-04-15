#include "useraccount.h"

bool Portfolio::AssetExists(Asset testAsset){
    for (Asset asset: assets_){
        if (asset.name == testAsset.name){
            return true;
        }
    }
    return false;
}

Asset Portfolio::AddAsset(Asset asset){
    if (!AssetExists(asset)){
        assets_.push_back(asset);
        return asset;
    } else {
    }
    
    return asset;
}

bool User::withdraw(Asset asset){
    return false;
}