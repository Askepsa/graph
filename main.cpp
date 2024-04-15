#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Vertex {
private:
  char data;
  vector<Vertex *> edges;
  bool is_visited;

public:
  Vertex(char c) : data{c}, is_visited{false}, edges{} {}

  void insert_edge(Vertex *edge) {
    if (find(edges.begin(), edges.end(), edge) == edges.end()) {
      edges.push_back(edge);
      edge->edges.push_back(this);
    }
  }

  // shows edges of vertices
  void check_edges() {
    cout << this->data << " -> ";

    for (auto v : this->edges) {
      cout << v->data << ' ';
    }

    cout << endl;
  }

  void dfs() {
    stack<Vertex *> s{};

    s.push(this);

    while (!s.empty()) {
      Vertex *vertex = s.top();

      s.pop();

      if (vertex->is_visited)
        continue;

      cout << vertex->data << ' ';

      vertex->is_visited = true;

      for (auto v : vertex->edges) {
        if (!v->is_visited)
          s.push(v);
      }
    }

    cout << endl;
  }

  void bfs() {
    queue<Vertex *> q{};

    q.push(this);

    while (!q.empty()) {
      Vertex *vertex = q.front();

      q.pop();

      if (vertex->is_visited)
        continue;

      cout << vertex->data << ' ';

      vertex->is_visited = true;

      for (auto v : vertex->edges) {
        if (!v->is_visited)
          q.push(v);
      }
    }

    cout << endl;
  }

  ~Vertex() { free(this); }
};

int main(void) {
  // Construct Vertex
  auto *a = new Vertex('A');
  auto *b = new Vertex('B');
  auto *c = new Vertex('C');
  auto *d = new Vertex('D');
  auto *e = new Vertex('E');
  auto *f = new Vertex('F');
  auto *g = new Vertex('G');
  auto *h = new Vertex('H');
  auto *i = new Vertex('I');
  auto *j = new Vertex('J');

  // Insert edges for vertices here
  a->insert_edge(b);
  a->insert_edge(e);
  b->insert_edge(f);
  c->insert_edge(g);
  d->insert_edge(h);
  e->insert_edge(d);
  e->insert_edge(h);
  f->insert_edge(j);
  f->insert_edge(g);
  h->insert_edge(i);
  i->insert_edge(f);
  j->insert_edge(g);

  // Check if edges are valid
  a->check_edges();
  b->check_edges();
  c->check_edges();
  d->check_edges();
  e->check_edges();
  f->check_edges();
  g->check_edges();
  h->check_edges();
  i->check_edges();
  j->check_edges();

  // You can only run these function once
  // as classes' is_visited attribute must be set to false again
  cout << endl << "BFS" << endl;
  a->bfs();

  // cout << endl << "DFS" << endl;
  // a->dfs();

  return 0;
}
