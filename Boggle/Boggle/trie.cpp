#include "stdafx.h"

//TODO: Make Find Word work correctly with QU, but rest of impl should use chars

static const int THREAD_COUNT = 26;

TrieNode::TrieNode(char initChar) {
    m_char = initChar;
	memset(m_children, 0, sizeof(TrieNode*) * 26);
}

bool isLowerAlphabet(char c) {
	return (c <= 122 && c >= 97);
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
		else {
			return false;
		}
	}
}

void TrieNode::GenerateTrie(std::string filepath) {
	std::string line;
	std::ifstream dictionary;

	dictionary.open(filepath);
	while (getline(dictionary, line)) {
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
	childNode = this->GetChildAt(letter);
	if (childNode != NULL && word.size() > 1) {
		childNode->AddWord(word.substr(1));
	}
	else {
		childNode = new TrieNode(letter);
		childNode->m_str = this->m_str + std::string(1, letter);

		this->m_children[letter - 'a'] = childNode;

		if (word.size() == 1) {
			//Last Character to create, so update accordingly
			childNode->SetEoW();
		}
		else {
			childNode->AddWord(word.substr(1));
		}
	}
}