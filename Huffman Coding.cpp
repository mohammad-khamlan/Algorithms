#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class Node {
public:
	char ch;
	int freq;
	Node *left, *right;
};
	struct comp
	{
		bool operator()(Node* l, Node* r)
		{
			return l->freq > r->freq;
		}
	};

	Node* getNode(char ch, int freq, Node* left, Node* right) {
		Node* node = new Node();

		node->ch = ch;
		node->freq = freq;
		node->left = left;
		node->right = right;

		return node;
	}


	string en = "";


	string generate() {
		unordered_map<string, char> Hex;
		Hex["0000"] = '0';
		Hex["0001"] = '1';
		Hex["0010"] = '2';
		Hex["0011"] = '3';
		Hex["0100"] = '4';
		Hex["0101"] = '5';
		Hex["0110"] = '6';
		Hex["0111"] = '7';
		Hex["1000"] = '8';
		Hex["1001"] = '9';
		Hex["1010"] = 'A';
		Hex["1011"] = 'B';
		Hex["1100"] = 'C';
		Hex["1101"] = 'D';
		Hex["1110"] = 'E';
		Hex["1111"] = 'F';

		string binary = en;

		string hexa = "";
		for (int i = 0; i < binary.length()/4; i++) {
			hexa += Hex[en.substr(0, 4)];
			en.erase(0, 4);
		}
		int length = hexa.length();
		return hexa.substr(length - 6);
	}

	string prefix = "http://tinyurl.com/";
	unordered_map<string, string> enco;

	string encodehuff(Node* root, string str, unordered_map<char, string> &huffmanCode)
	{
		if (root == nullptr)
			return "";

		if (!root->left && !root->right) {
			huffmanCode[root->ch] = str;
		}

		encodehuff(root->left, str + "0", huffmanCode);
		en += "0";
		encodehuff(root->right, str + "1", huffmanCode);
		en += "1";
		return "";
	}

	string buildHuffmanTree(string text) {

		unordered_map<char, int> freq;
		for (int i = 0; i < text.length(); i++) {
			freq[text[i]]++;
		}

		priority_queue<Node*, vector<Node*>, comp> pq;


		for (auto pair : freq) {
			pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
		}

		while (pq.size() != 1)
		{

			Node *left = pq.top(); pq.pop();
			Node *right = pq.top();	pq.pop();

			int sum = left->freq + right->freq;
			pq.push(getNode('\0', sum, left, right));
		}

		Node* root = pq.top();

		unordered_map<char, string> huffmanCode;

		encodehuff(root, "", huffmanCode);
		
		string hexa = generate();

		
		string tinyurl = prefix + hexa;

		enco[text] = en;
		enco[en] = tinyurl;
		enco[tinyurl] = text;
		return tinyurl;
	}
	string encode(string longUrl) {
		return buildHuffmanTree(longUrl);
	}

	string decode(string shortUrl) {
		return enco[shortUrl];
	}



int main() {
	cout << "https://www.google.ps/" << endl;
	cout<< buildHuffmanTree("https://www.google.ps/")<<endl;
}








