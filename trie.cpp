class trie {
    class node {
    public:
        std::unordered_map<char, node*> children;
        int noofends , noofpasses;

        node() : noofends(0) , noofpasses(0) {}
    };

    node* root;

public:
    trie() { root = new node(); }

    void insert(const std::string& word) {
        node* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new node();
            }
            current = current->children[c];
            current->noofpasses += 1;
        }
        current->noofends += 1;
    }

    bool search(const std::string& word) {
        node* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                return false;
            }
            current = current->children[c];
        }
        return (current->noofends > 0);
    }

    void extract(const std::string& word) {
        assert(search(word) == true);
        node* current = root;
        for (char c : word) {
            current = current->children[c];
            current->noofpasses -= 1;
        }
        current->noofends -= 1;
    }
};
