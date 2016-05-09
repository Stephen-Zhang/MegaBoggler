class SolverBoard {
private:
	std::vector<char> m_new_board;
	std::vector<bool> m_new_visitedNodes;
	int cols;
	int rows;
	int m_neighbors[8];

	SolverBoard() { };

public:
	//Method to generate a board. No public constructors
	static SolverBoard* GenerateBoard(std::string filepath);

	int* getNeighborsChar(int index);

	char getCharAt(int location) { return m_new_board[location]; };
	bool hasBeenVisited(int index) { return m_new_visitedNodes[index]; };
	void setVisited(int index) { m_new_visitedNodes[index] = true; };

	int getRows() { return rows; };
	int getCols() { return cols; };
};