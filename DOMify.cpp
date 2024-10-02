#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
public:
    virtual ~Node() {}
    virtual void print(int depth = 0) const = 0;
};

class Element : public Node {
public:
    string tagName;
    vector<Node*> children;

    Element(const string& tag) : tagName(tag) {}

    void print(int depth = 0) const override {
        cout << string(depth, ' ') << "<" << tagName << ">\n";
        for (const auto& child : children) {
            child->print(depth + 2);
        }
        cout << string(depth, ' ') << "</" << tagName << ">\n";
    }
};

class Text : public Node {
public:
    string textContent;

    Text(const string& text) : textContent(text) {}

    void print(int depth = 0) const override {
        cout << string(depth, ' ') << textContent << "\n";
    }
};

class DOM {
public:
    Node* root;

    DOM(const string& rootTag) {
        root = new Element(rootTag);
    }

    ~DOM() {
        deleteTree(root);
    }

    void deleteTree(Node* node) {
        if (node) {
            if (Element* elem = dynamic_cast<Element*>(node)) {
                for (Node* child : elem->children) {
                    deleteTree(child);
                }
            }
            delete node;
        }
    }

    void print() const {
        if (root) {
            root->print();
        }
    }
};

int main() {
    DOM myDOM("html");

    Element* body = new Element("body");
    Element* h1 = new Element("h1");
    h1->children.push_back(new Text("Hello, World!"));
    body->children.push_back(h1);
    
    Element* p = new Element("p");
    p->children.push_back(new Text("This is a paragraph."));
    body->children.push_back(p);

    Element* rootElement = static_cast<Element*>(myDOM.root);
    rootElement->children.push_back(body);

    myDOM.print();

    return 0;
}

/*
<html>
  <body>
    <h1>
      Hello, World!
    </h1>
    <p>
      This is a paragraph.
    </p>
  </body>
</html>
*/
