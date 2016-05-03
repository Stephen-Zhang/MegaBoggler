#include "stdafx.h"

BoggleSolver::BoggleSolver(TrieNode* root, SolverBoard* board) {
	m_boardGraph = board;
	m_trieRoot = root;

	char first_node_new = board->getCharAt(0);
	
	m_board_stack.push(0);
	m_trie_stack.push(m_trieRoot->GetChildAt(first_node_new));
}

void BoggleSolver::solve() {
	while (m_board_stack.size() > 0) {
		int currBoardNode = m_board_stack.front();
		TrieNode* currentTrieNode = m_trie_stack.front();

		m_board_stack.pop();
		m_trie_stack.pop();

		if (currentTrieNode->IsEoW()) {
			if (!currentTrieNode->IsFound()) {
				currentTrieNode->SetFound();
				m_foundWords.push_back(&(currentTrieNode->GetStr()));
			}
		}

		int* neighbors = m_boardGraph->getNeighborsChar(currBoardNode);
		for (int i = 0; i < 8; i++) {
			int index = *(neighbors + i);
			char letter = m_boardGraph->getCharAt(index);
			if (!m_boardGraph->hasBeenVisited(index)) {
				TrieNode* childRoot = m_trieRoot->GetChildAt(m_boardGraph->getCharAt(index));
				if (childRoot != nullptr) {
					m_board_stack.push(index);
					m_trie_stack.push(childRoot);
				}
				m_boardGraph->setVisited(index);
			}

			TrieNode* nextNodeInTrie = currentTrieNode->GetChildAt(m_boardGraph->getCharAt(index));
			if (nextNodeInTrie != nullptr) {
				m_board_stack.push(index);
				m_trie_stack.push(nextNodeInTrie);
			}
		}
	}
}