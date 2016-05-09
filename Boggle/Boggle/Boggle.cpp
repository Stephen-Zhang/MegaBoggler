#include "stdafx.h"

/************************************************************************/
/* TODOs                                                                
/* - Make filepaths read in from cmdline
/* - Make things have debug defines so I can print when in debug mode
/* - Test Solver
/* - Optimize speed
/* - Profit???
/************************************************************************/

int _tmain(int argc, _TCHAR* argv[])
{
	TrieNode* root = new TrieNode();

	/************************************************************************/
	/* Insert dictionary into Trie Structure                                */
	/************************************************************************/
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	root->GenerateTrie("words.txt");
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> trieTimer = std::chrono::duration_cast<std::chrono::duration<float>>(t2 - t1);
	std::cout << "Generating Trie Time: " << trieTimer.count() * 1000;

	std::cout << "\n";

	/************************************************************************/
	/* Generate the csv into a data structure that you can use             */
	/************************************************************************/
	std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();
	SolverBoard* boggleBoard = SolverBoard::GenerateBoard("1000.txt");
	std::chrono::high_resolution_clock::time_point t4 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> boardTimer = std::chrono::duration_cast<std::chrono::duration<float>>(t4 - t3);
	std::cout << "Generating Boggle Board Graph: " << boardTimer.count() * 1000;

	std::cout << "\n";

	/************************************************************************/
	/* Create instance of solver with trie and board passed in              */
	/************************************************************************/
	BoggleSolver* solver = new BoggleSolver(root, boggleBoard);
	std::chrono::high_resolution_clock::time_point t5 = std::chrono::high_resolution_clock::now();
	solver->solve();
	std::chrono::high_resolution_clock::time_point t6 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> solverTimer = std::chrono::duration_cast<std::chrono::duration<float>>(t6 - t5);
	std::cout << "Generating Solver: " << solverTimer.count() * 1000;

	std::cout << "\n";

	//for (uint32_t i = 0; i < solver->m_foundWords.size(); i++) {
	//	std::cout << *(solver->m_foundWords.at(i)) << '\n';
	//}

	//std::getchar();
}

