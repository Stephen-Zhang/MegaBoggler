class TrieNode {
private:
    char m_char = '\0';
    bool m_eow = false;
	TrieNode* m_children[26];

public:
    TrieNode(char initialChar);
    TrieNode() : TrieNode('\0') {};
    
    bool IsEoW() { return m_eow; };
    void SetEoW() { m_eow = true; };
    
    char GetCharacter() { return m_char; };
    TrieNode* GetChildAt(int index) { return m_children[index]; };
    
    bool FindWord(std::string word);
	void AddWord(std::string word);

	void AddNode(TrieNode* newNode);

	void GenerateTrie(std::string filepath);
};
