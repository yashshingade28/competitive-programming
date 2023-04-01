class trie {
   private:
    struct node {
        std::unordered_map<char, node*> children;
        int noofends, noofpasses;

        node() : noofends(0), noofpasses(0) {}
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

    bool find(const std::string& word) {
        node* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                return false;
            }
            current = current->children[c];
        }
        return (current->noofends > 0);
    }

    bool extract(const std::string& word) {
        if (!find(word)) return false;
        node* current = root;
        for (char c : word) {
            current = current->children[c];
            current->noofpasses -= 1;
        }
        current->noofends -= 1;
        return true;
    }

    bool erase(const std::string& word) {
        node* current = root;
        std::stack<std::pair<node*, char>> backtrack;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                return false;
            }
            backtrack.push(std::make_pair(current, c));
            current = current->children[c];
        }
        if (current->noofends == 0) {
            return false;
        }
        current->noofends -= 1;
        while (!backtrack.empty()) {
            auto [parent, c] = backtrack.top();
            backtrack.pop();
            parent->children[c]->noofpasses -= 1;
            if (parent->children[c]->noofpasses == 0) {
                parent->children.erase(c);
            }
        }
        return true;
    }
};
