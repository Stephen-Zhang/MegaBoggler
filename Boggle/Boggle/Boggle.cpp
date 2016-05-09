#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc != 3) {
		return 0;
	}

	//This is some janky way of fixing the _TCHAR to const char* so that I can cast to string...
	//Unsure of a better way to do this, but I'm sure there is. Could also modify main to take char* but unsure what requirements of the program are.
	std::wstring arg1(argv[1]);
	std::wstring arg2(argv[2]);

	std::string dictionary(arg1.begin(), arg1.end());
	std::string board(arg2.begin(), arg2.end());


	TrieNode* root = new TrieNode();
	root->GenerateTrie(dictionary);

	SolverBoard* boggleBoard = SolverBoard::GenerateBoard(board);

	BoggleSolver* solver = new BoggleSolver(root, boggleBoard);
	solver->solve();

	std::sort(solver->m_foundWords.begin(), solver->m_foundWords.end());

	std::ofstream resultFile;
	resultFile.open("SZhang_MegaBoggle_Results.txt");
	resultFile << "Number of words found: " << solver->m_foundWords.size() << "\n";

	for (uint32_t i = 0; i < solver->m_foundWords.size(); i++) {
		resultFile << solver->m_foundWords[i] << '\n';
	}

	resultFile.close();
}

