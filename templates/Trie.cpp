//mridul1809
#include<bits/stdc++.h>
using namespace std;

class Trie {

public:

	//N is number of possible characters in a string
	const static int N = 26;

	//baseChar defines the base character for possible characters
	//like '0' for '0','1','2'... as possible characters in string 
    const static char baseChar = 'a';

	struct TrieNode
	{
		int next[N];
		//if isEnd is set to true , a string ended here
		bool isEnd;
	};

	//the implementation is via vector and each position in this vector
	//is similar as new pointer in pointer type implementation
	vector <TrieNode> tree;

	//Base Constructor
	Trie ()
	{
		tree.push_back(TrieNode());
	}

	//inserting a string in trie
	void insert(const string &s)
    {
        int p = 0;
        for(int i=0;i<s.size();i++)
        {
            if(tree[p].next[s[i]-baseChar] == 0)
            {
                tree.push_back(TrieNode());
                tree[p].next[s[i]-baseChar] = tree.size()-1;
            }

            p = tree[p].next[s[i]-baseChar];
        }
        tree[p].isEnd = true;
    }

    //check if a string exists as prefix
    bool checkPrefix(const string &s)
    {
    	int p = 0;
    	for(int i=0;i<s.size();i++)
    	{
    		if(tree[p].next[s[i]-baseChar] == 0)
    			return false;

    		p = tree[p].next[s[i]-baseChar];
    	}
    	return true;
    }

    //check is string exists
    bool checkString(const string &s)
    {
    	int p = 0;
    	for(int i=0;i<s.size();i++)
    	{
    		if(tree[p].next[s[i]-baseChar] == 0)
    			return false;

    		p = tree[p].next[s[i]-baseChar];
    	}

    	return tree[p].isEnd;
    }
};

string s,temp;
int main()
{
    Trie trie = Trie();

    cout << trie.checkString("hello") << endl;

    trie.insert("hello");

    cout << trie.checkPrefix("hell") << endl;

    cout << trie.checkString("hell") << endl;

    cout << trie.checkString("hello") << endl;
    
    return 0;
}