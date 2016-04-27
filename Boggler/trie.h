//
//  trie.h
//  Boggler
//
//  Created by Stephen Zhang on 4/27/16.
//  Copyright © 2016 stephen.zhang. All rights reserved.
//

#ifndef trie_h
#define trie_h

#import <string>
#import <fstream>

class TrieNode {
private:
    char m_char = '\0';
    bool m_eow = false;
    TrieNode* m_children[26] = { nullptr };
    
    void addNode(TrieNode* newNode);
public:
    TrieNode(char initialChar);
    TrieNode() : TrieNode('\0') {};
    
    bool isEoW() { return m_eow; };
    void setEoW(bool eow) { m_eow = eow; };
    
    char getCharacter() { return m_char; };
    TrieNode* getChildAt(int index) { return m_children[index]; };
    
    bool findWord(std::string word);
    
    void generateTrie(std::ofstream file);
};

#endif /* trie_h */
