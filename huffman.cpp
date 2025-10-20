#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

class Huffman {
public:
    Node* root;
    unordered_map<char, string> huffmanCode;

    Huffman() {
        root = nullptr;
    }

    void buildTree(const string& text) {
        unordered_map<char, int> freq;
        for (char ch : text) freq[ch]++;

        priority_queue<Node*, vector<Node*>, Compare> pq;
        for (auto pair : freq) {
            pq.push(new Node(pair.first, pair.second));
        }

        while (pq.size() > 1) {
            Node* left = pq.top(); pq.pop();
            Node* right = pq.top(); pq.pop();

            Node* newNode = new Node('\0', left->freq + right->freq);
            newNode->left = left;
            newNode->right = right;
            pq.push(newNode);
        }

        root = pq.top();
    }

    void encode(Node* node, string str) {
        if (!node) return;

        if (!node->left && !node->right) {
            huffmanCode[node->ch] = str;
        }

        encode(node->left, str + "0");
        encode(node->right, str + "1");
    }

    string encodeText(const string& text) {
        string encoded = "";
        for (char ch : text) encoded += huffmanCode[ch];
        return encoded;
    }

    void decodeText(const string& encoded) {
        Node* curr = root;
        cout << "\nDecoded text: ";
        for (char bit : encoded) {
            if (bit == '0') curr = curr->left;
            else curr = curr->right;

            if (!curr->left && !curr->right) {
                cout << curr->ch;
                curr = root;
            }
        }
        cout << endl;
    }

    void printCodes() {
        cout << "\nHuffman Codes:\n";
        for (auto pair : huffmanCode)
            cout << pair.first << " : " << pair.second << endl;
    }
};

int main() {

    string text;
    cin >> text;

    Huffman h;
    h.buildTree(text);
    h.encode(h.root, "");
    h.printCodes();

    string encoded = h.encodeText(text);
    cout << "\nEncoded text: " << encoded << endl;

    h.decodeText(encoded);

    return 0;
}
