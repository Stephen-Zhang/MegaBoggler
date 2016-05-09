class BoggleSolver {
private:
	std::vector<int> m_board_stack;
	std::vector<TrieNode*> m_trie_stack;

	SolverBoard* m_boardGraph;
	TrieNode* m_trieRoot;


public:
	std::vector<std::string> m_foundWords;

	BoggleSolver(TrieNode* root, SolverBoard* board);

	void solve();
};