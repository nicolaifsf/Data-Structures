#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>

using namespace std;


class Node{
        public:
                void insert(stack<int> s){
                    if(s.size() == 0){return;}
                    int currInt = s.top();
                    s.pop();
                    Node* ptr;
                    if(vals.find(currInt) == vals.end()){
                        ptr = new Node();
                        pair<int, Node*> p(currInt, ptr);
                        vals.insert(p);
                    }
                    else{
                        ptr = vals[currInt]; 
                        s.pop();
                    }
                    vals[currInt]->insert(s);
                }
                unordered_map<int, Node*>::iterator start(){
                    if(vals.begin() == vals.end()){
                        cout << "empty" << endl;
                        return vals.end();
                    }
                    return vals.begin(); 
                }
                unordered_map<int, Node*>::iterator end(){
                    return vals.end(); 
                }

                void printOps(){
                    unordered_map<int, Node*>::iterator itr = vals.begin();
                    while(itr != vals.end()){
                        cout << itr->first << " "; 
                        ++itr;
                    }
                    cout << "end" << endl;
                }

        private:
            unordered_map<int, Node*> vals;
};

class Trie{
        public:
                Trie(Node* fN = nullptr):firstNode(fN),size(0){}
                void insert(int number){
                        stack<int> s;
                        while(number){
                                int num = number;
                                number %= 10;
                                s.push(number);
                                number = num /10;
                        }
                        /*
                        while(s.size() > 0){
                                cout << s.top() << endl;
                                s.pop();
                        }
                        */
                        if(firstNode == nullptr){
                            firstNode = new Node(); 
                        }
                        else{
                                cout << "there is something that exists here already, which is cool" << endl;
                        }
                        firstNode->insert(s);
                        ++size; 
                }
                //recursing through iterators effectively
                void print(){
                        if(size ==0){
                                cout << "empty" << endl; 
                                return;
                        }
                        unordered_map<int, Node*>::iterator itr = firstNode->start();
                        firstNode->printOps();
                        itr = firstNode->start();
                        while(true){
                        cout << "which path would you like to follow: " ;
                        int input;
                        if(input == -1){return;}
                        cin >> input;
                        while(itr->first != input){
                           ++itr; 
                        }
                        Node* currNode = itr->second;
                        currNode->printOps();
                        itr = currNode->start();
                        }
                }
        private:
                Node* firstNode;
                int size;
};
int main(){
    Trie t;
    t.insert(2345);
    t.insert(9999);
    t.print();
}
