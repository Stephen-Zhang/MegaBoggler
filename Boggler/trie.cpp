//
//  trie.cpp
//  Boggler
//
//  Created by Stephen Zhang on 4/27/16.
//  Copyright © 2016 stephen.zhang. All rights reserved.
//

#include "trie.h"

TrieNode::TrieNode(char initChar) {
    m_char = initChar;
}

/*********
 * addNode
 *********
 * Adds a node to the current node. Helper function for generateTrie.
 *
 * params:
 *   TrieNode* newNode - pointer to the node being added to current one.
 *
 * return:
 *   None
 */
void TrieNode::addNode(TrieNode *newNode) {
    int newNodeLetter = int(newNode->getCharacter()) % 97;
    m_children[newNodeLetter] = newNode;
}


