#include "stdafx.h"

BoggleSolver::BoggleSolver(TrieNode* root, SolverBoard* board) {
	m_boardGraph = board;
	m_trieRoot = root;

	char first_node_new = board->getCharAt(0);
	
	//Initialize the stacks with the (0,0) node
	m_board_stack.push_back(0);
	m_trie_stack.push_back(m_trieRoot->GetChildAt(first_node_new));
}

void BoggleSolver::solve() {
	while (m_board_stack.size() > 0) {
		//Pop and store first element
		int currBoardNode = m_board_stack.back();
		TrieNode* currentTrieNode = m_trie_stack.back();
		m_board_stack.pop_back();
		m_trie_stack.pop_back();

		int* neighbors = m_boardGraph->getNeighborsChar(currBoardNode);
		for (int i = 0; i < 8; i++) {
			int index = *(neighbors + i);
			//If neighbor is invalid, ignore
			if (index == -1) {
				continue;
			}

			char letter = m_boardGraph->getCharAt(index);

			//If this is the first time letter is being seen, add that node to stack and flag it.
			if (!m_boardGraph->hasBeenVisited(index)) {
				TrieNode* childRoot = m_trieRoot->GetChildAt(letter);
				if (childRoot != nullptr) {
					m_board_stack.push_back(index);
					m_trie_stack.push_back(childRoot);
				}
				m_boardGraph->setVisited(index);
			}

			TrieNode* nextNodeInTrie = currentTrieNode->GetChildAt(letter);
			//If next letter is in trie, add to stack.
			if (nextNodeInTrie != nullptr) {
				if (nextNodeInTrie->IsEoW()) {
					//If next letter in tree is the end of a word, add to found words.
					//Need to add this node also because of cases like cat // cats
					if (!nextNodeInTrie->IsFound()) {
						nextNodeInTrie->SetFound();
						m_foundWords.push_back(nextNodeInTrie->GetStr());
					}
				}
				m_board_stack.push_back(index);
				m_trie_stack.push_back(nextNodeInTrie);
			}
		}
	}
}