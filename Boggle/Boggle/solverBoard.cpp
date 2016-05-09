#include "stdafx.h"

SolverBoard* SolverBoard::GenerateBoard(std::string filepath) {
	std::ifstream csvFile;
	std::string line;
	std::string token;
	uint32_t x = 0;
	uint32_t y = 0;

	SolverBoard* newBoard = new SolverBoard();

	csvFile.open(filepath);
	while (getline(csvFile, line)) {
		x = 0;
		std::stringstream tokenizer(line);
		while (getline(tokenizer, token, ',')) {
			//For each token, transform ASCII to 0-25, from 97-122 for ease of access in trie later.
			newBoard->m_new_board.push_back(token.at(0) - 'a');
			newBoard->m_new_visitedNodes.push_back(false);
			x++;
		}
		y++;
	}
	csvFile.close();

	//Counted the rows and cols while generating the board.
	newBoard->cols = x;
	newBoard->rows = y;
	
	return newBoard;
}

int* SolverBoard::getNeighborsChar(int index) {
	int counter = 0;

	for (int32_t x = -1; x <= 1; x++) {
		for (int32_t y = -1; y <= 1; y++) {
			int neighbor_index = (index + (x * this->rows) + y);
			//Ignore current index
			if (neighbor_index == index) {
				continue;
			}
			//-1 if outside boundaries
			if (neighbor_index < 0 ||
				neighbor_index >= this->rows * this->cols) {
				m_neighbors[counter++] = -1;
			}
			else {
				m_neighbors[counter++] = neighbor_index;
			}
		}
	}
	return m_neighbors;
}