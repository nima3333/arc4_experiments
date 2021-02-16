//
// Created by Nima Alikhani on 17/02/2021.
//
#include "Attack.h"

Attack::Attack(std::string key) {
    this->key = std::move(key);
}

std::vector<int> Attack::attack() {
    std::vector<int> predictedKey = std::vector<int>();

    for(int i=0;i<5;i++){
        std::vector<int> iv = std::vector<int>{3+i, 255, 3};
        EncryptedGroup group = this->generator.generate(iv,"Test", 25000);
        int key_byte = attack_i(i, group);
        predictedKey.push_back(key_byte);
    }

    return predictedKey;
}

int Attack::attack_i(int i, EncryptedGroup group) {
    // Implement in rc4 partial KSA
    return 0;
}
