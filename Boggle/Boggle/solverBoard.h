class SolverBoard {
private:
	SolverBoard() { };

	std::vector<char> m_new_board;
	std::vector<bool> m_new_visitedNodes;
	int cols = 0;
	int rows = 0;

	int m_neighbors[8];

public:
	static SolverBoard* GenerateBoard(std::string filepath);
	int* getNeighborsChar(int index);

	char getCharAt(int location) { return m_new_board[location]; };
	bool hasBeenVisited(int index) { return m_new_visitedNodes[index]; };
	void setVisited(int index) { m_new_visitedNodes[index] = true; };
};