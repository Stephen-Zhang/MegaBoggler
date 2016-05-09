#include "stdafx.h"

TrieNode::TrieNode(char initChar) {
    m_char = initChar;
	memset(m_children, 0, sizeof(TrieNode*) * 26);
}

bool isLowerAlphabet(char c) {
	return (c <= 122 && c >= 97);
}

void TrieNode::GenerateTrie(std::string filepath) {
	std::string line;
	std::ifstream dictionary;

	dictionary.open(filepath);
	while (getline(dictionary, line)) {
		//Protection from any words that contain character that are not ASCII between 97 and 122
		if (!std::all_of(line.begin(), line.end(), isLowerAlphabet) || line.size() == 0) {
			continue;
		}
		this->AddWord(line);
	}
	dictionary.close();
}

void TrieNode::AddWord(std::string word) {
	TrieNode* childNode;
	char letter = word.at(0);
	childNode = this->GetChildAt(letter - 'a');
	if (childNode != NULL && word.size() > 1) {
		childNode->AddWord(word.substr(1));
	}
	else {
		childNode = new TrieNode(letter);
		childNode->m_str = this->m_str + std::string(1, letter);

		this->m_children[letter - 'a'] = childNode;

		//If last char, set the next node to End of Word, else keep travelling down trie
		if (word.size() == 1) {
			childNode->SetEoW();
		}
		else {
			childNode->AddWord(word.substr(1));
		}
	}
}