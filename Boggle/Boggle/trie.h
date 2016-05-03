class TrieNode {
private:
    char m_char = '\0';
    bool m_eow = false;
	bool m_found = false;

	std::string m_str;
	TrieNode* m_children[26];

	TrieNode(char initialChar);
	void AddWord(std::string word);

public:
	TrieNode() : TrieNode('\0') { m_str = ""; };

	char GetCharacter() { return m_char; };
	std::string GetStr() { return m_str; };

	bool IsEoW() { return m_eow; };
    void SetEoW() { m_eow = true; };

	bool IsFound() { return m_found; };
	void SetFound() { m_found = true; };

    bool FindWord(std::string word);
	void GenerateTrie(std::string filepath);

	TrieNode* GetChildAt(int index) { return m_children[index - 'a']; };
};
