//
//  main.cpp
//  Boggler
//
//  Created by Stephen Zhang on 4/27/16.
//  Copyright © 2016 stephen.zhang. All rights reserved.
//

#include <iostream>
#include "trie.h"

int main(int argc, const char * argv[]) {
    TrieNode* root = new TrieNode();
    root->addNode(new TrieNode('z'));
    std::cout << root->getChildAt(20) << '\n';
}
