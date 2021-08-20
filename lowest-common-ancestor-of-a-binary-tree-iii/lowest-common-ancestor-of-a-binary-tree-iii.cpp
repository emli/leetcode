/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* ans;
        
        unordered_set<Node*> set;
        visit(p,set);
        findLCA(q,set,ans);
        
        return ans;
    }
    
     void findLCA(Node* q,unordered_set<Node*> &set,Node* &ans){
        if (q == nullptr){
            return;
        }
        if (set.count(q)){
            ans = q;
            return;
        }
        findLCA(q->parent,set,ans);
    }
    void visit(Node* p,unordered_set<Node*> &set){
        if (p == nullptr){
            return;
        }
        set.insert(p);
        visit(p -> parent,set);
    }
};