#include "stdafx.h"

TrieNode::TrieNode(char initChar) {
    m_char = initChar;
	memset(m_children, 0, sizeof(TrieNode*) * 26);
}

bool TrieNode::FindWord(std::string word) {
	char firstChar = word.at(0);
	if (word.size() == 1) {
		return this->IsEoW();
	}
	else {
		word = word.substr(1);
		TrieNode* nextNode = this->GetChildAt(firstChar);
		if (nextNode != NULL) {
			return nextNode->FindWord(word);
		}
	}
}

void TrieNode::GenerateTrie(std::string filepath) {
	std::string line;
	std::ifstream dictionary;

	dictionary.open(filepath);
	while (getline(dictionary, line)) {
		if (line.find('\'') != std::string::npos) {
			continue;
		}
		this->AddWord(line);
	}
	dictionary.close();
}

void TrieNode::AddNode(TrieNode* newNode) {
	int newNodeLetter = int(newNode->GetCharacter()) % 97;
	m_children[newNodeLetter] = newNode;
}

void TrieNode::AddWord(std::string word) {
	TrieNode* childNode;
	char letter = word.at(0);
	childNode = new TrieNode(word.at(0));

	this->AddNode(childNode);

	if (word.size() == 1) {
		//Last Character to create, so update accordingly
		childNode->SetEoW();
	}
	else {
		childNode->AddWord(word.substr(1));
	}
}