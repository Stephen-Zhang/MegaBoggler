class BoggleSolver {
private:
	std::queue<int> m_board_stack;
	std::queue<TrieNode*> m_trie_stack;

	SolverBoard* m_boardGraph;
	TrieNode* m_trieRoot;


public:
	std::vector<std::string*> m_foundWords;

	BoggleSolver(TrieNode* root, SolverBoard* board);

	void solve();
};