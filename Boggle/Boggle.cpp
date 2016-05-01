// Boggle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	TrieNode* root = new TrieNode();

	/************************************************************************/
	/* Insert dictionary into Trie Structure                                */
	/************************************************************************/
	root->GenerateTrie("english-words.20");

	/************************************************************************/
	/*  Generate the csv into a data structure that you can use             */
	/************************************************************************/
	

	std::getchar();
}

