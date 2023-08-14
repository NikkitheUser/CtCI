#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;
enum State {
    UnVisited, Visited, Visiting
};

class Node {
public:
    explicit Node(string word_id) : 
        word(word_id), state(UnVisited), prev(nullptr) {}

    string word;
    State state;
    Node *prev; // explicitly for BFS shortest path

    bool operator==(const Node &other) const {
        return (word == other.word);
    }
};

namespace std {
    template <>
    struct hash<Node> {
        std::size_t operator()(const Node& k) const {
            return ((hash<string>()(k.word)));
        }
    };
}


class Graph {
public:
    Graph(const vector<string> &words)
        : words_ref(words) {
        map_defaults();
        analyize_lev1_word_rel();
        add_inv_graph();
    }

    void traverse_all() {
        for (auto& i : graph) {
            cout << setw(10) << i.first.word
                 << "(" << i.first.state << ") : ";
            traverse_set(i.second);
        }
    }

    vector<string> min_path_lev_1_distance(const string &a, const string &b) {
        vector<string> min_path;

        if (graph.find(Node(a)) == graph.end() || graph.find(Node(b)) == graph.end()) {
            cout << "Words not found within dictionary" << endl;
            return min_path;
        }

        queue<Node> q;
        q.push(Node(a)); // a -> ... -> b
        const_cast<Node&>(graph.find(Node(a))->first).state = Visited;

        while (!q.empty()) {
            Node front = q.front();
            q.pop();

            // need this first direct pointer for previous
            auto *front_graph_key = &const_cast<Node&>(graph.find(front)->first);

            if (front.word == b) {
                return traverse_BFS_shortest_path(graph.find(Node(b))->first);
            }


            unordered_set<string> adj_elements = findAdj(Node(front));
            for (const string &s : adj_elements) {
                if (graph.find(Node(s))->first.state == UnVisited) {
                    q.push(Node(s));
                    // need to have assurance that the changes to the graph
                    // occur to the actual elements within the graph, not copies.
                    const_cast<Node&>(graph.find(Node(s))->first).state = Visited;
                    const_cast<Node&>(graph.find(Node(s))->first).prev = front_graph_key;
                }
            }
        }

        return vector<string>();
    }

private:
    const vector<string> words_ref;
    unordered_map<Node, unordered_set<string>> graph;

    void map_defaults() {
        for (const string &s : words_ref)
            graph.insert( {Node(s), unordered_set<string>() });
    }

    void analyize_lev1_word_rel() {
        for (int i = 0; i < words_ref.size(); i++) {
            for (int j = i + 1; j < words_ref.size(); j++) {
                // if i and j are 1 apart, then j and i are one apart
                // this will be taken care of in add_inv_graph
                if (is_distance_1_apart(words_ref[i], words_ref[j])) {
                    graph[Node(words_ref[i])].insert(words_ref[j]);
                }
            }
        }
    }

    bool is_distance_1_apart(const string one, const string two) {
        assert(one.length() == two.length());
        int diff = 0, iter2 = 0;

        for (char c : one) {
            if (diff >= 2) break;
            if (c != two[iter2++])
                diff++;
        }

        return (diff < 2);
    }

    vector<string> traverse_BFS_shortest_path(const Node &end) {
        vector<string> sp;
        sp.push_back(end.word);

        Node *iter = end.prev;
        while (iter) {
            sp.push_back(iter->word);
            iter = iter->prev;
        }
        reverse(sp.begin(), sp.end());
        return sp;
    }

    void add_inv_graph()
    {
        for (auto &node_i : graph) {
            for (auto &node_j : node_i.second) {
                graph[Node(node_j)].insert(node_i.first.word);
            }
        }
    }

    void resetStates() {
        for (auto &i : graph)
            const_cast<Node&>(i.first).state = UnVisited;
    }

    bool exists(const Node &n) {
        return (graph.find(n) != graph.end());
    }

    bool contains(const unordered_set<Node> &s, const Node &n) {
        return (s.find(n) != s.end());
    }

    void traverse_set(const unordered_set<string> &s)
    {
        for (const string &i : s)
            cout << i << ", ";
        cout << endl;
    }

    unordered_set<string>& findAdj(const Node &n)
    {
        if (!exists(n)) {
            cout << "Key does not exist" << endl;
            return unordered_set<string>();
        }
        return graph.find(n)->second;
    }

};

#define MAX_WORD_LEN 32

vector<vector<string>> cluster_by_size(const string &file_path, const int num_words)
{
    array<float, MAX_WORD_LEN> word_length_distribution =
        {0.00, 0.001, 0.006, 0.026, 0.052, 0.085, 0.122, 0.14, 0.14, 0.126, 
        0.101, 0.075, 0.052, 0.032, 0.020, 0.01, 0.006, 0.003, 0.002, 0.001, 0.0};

    int iter = 0;
    vector<vector<string>> clusters(MAX_WORD_LEN);
    for (vector<string> &v : clusters)
        v.reserve(num_words*word_length_distribution[iter++]);

    ifstream infile;
    infile.open(file_path);

    int index = 0;
    if (infile.good()) {
        string line;
        while (getline(infile, line)) {
            int length_hash = line.length();
            clusters.at(length_hash).push_back(line);
        }
    }

    return clusters;
}

void test(vector<vector<string>> &clusters)
{
    vector<Graph> g_clusters;
    g_clusters.reserve(MAX_WORD_LEN);

    // create clustors
    for (vector<string> &v : clusters) 
        g_clusters.emplace_back(v);

    // traverse a few
    for (int i : {3}) {
        g_clusters[i].traverse_all();
        cout << "\n\n";
    }

    vector<string> min_path = g_clusters[4].min_path_lev_1_distance("damp", "like");
    print(min_path);
}

int main()
{
    const string filepath = "../infiles/words.txt";
    vector<vector<string>> clusters = cluster_by_size(filepath, 475000);
    test(clusters);
}
