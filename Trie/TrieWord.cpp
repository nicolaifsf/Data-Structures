#include<iostream>
#include<stack>
#include<string>
#include<unordered_map>

using namespace std;

class Node{
        public:
            void insert(stack<char> & s, int num){
                    if(s.size() == 0){
                            number = num; 
                            return;
                    }
                    char curr = s.top();
                    if(map.find(curr) == map.end()){
                        pair<char,Node*> p(curr, new Node); 
                        map.insert(p);
                    }
                    s.pop();
                    unordered_map<char, Node*>::iterator itr = map.find(curr);
                    itr->second->insert(s, num);
            
            }
            
            int getNumber(){
                return number; 
            }

            unordered_map<char, Node*>::iterator first(){
                return map.begin(); 
            }

            unordered_map<char,Node*>::iterator last(){
                return map.end(); 
            }

            unordered_map<char,Node*>::iterator find(char s){
                return map.find(s); 
            }

        private:
            unordered_map<char, Node*> map; 
            int number;
};


class Trie{
        public:
                Trie(Node* n = nullptr):firstNode(n),size(0){}

                void insert(string word, int num){
                        stack<char> s;
                        for(int x = word.length()-1; x >= 0; --x){
                            s.push(word[x]); 
                        }
                        if(firstNode == nullptr){
                            firstNode = new Node; 
                        }
                        firstNode->insert(s,num);
                        ++size;
                }


                void printWords(string start, int counter, Node* currNode){
                        char curr = start[counter];
                        ++counter;
                        if(currNode->first() == currNode->last()){
                            cout << currNode->getNumber() << endl; 
                            return;
                        }
                        unordered_map<char,Node*>::iterator itr = currNode->find(curr);
                        cout << itr->first << " ";
                        printWords(start,counter, itr->second);
                        // while(itr != currNode->last()){
                }

                void printWords(string start){
                        int counter = 0;
                        Node* currNode = firstNode;
                        printWords(start, counter, currNode);


                }

                void print(){
                    Node* currNode = firstNode; 
                    cout << "type a # (pound) in order to terminate"  << endl;;
                while(true){
                    if(currNode->first() == currNode->last()){
                        cout << currNode->getNumber() << endl; 
                        return;
                    }
                    char command;
                    unordered_map<char,Node*>::iterator itr = currNode->first();
                    while(itr != currNode->last() ){
                           cout << itr->first << " "; 
                           ++itr;
                    }
                    cout << "end" << endl;
                    cout << "which node do you wanna visit: ";
                    cin >> command;
                    if(command == '#'){break;}
                    unordered_map<char,Node*>::iterator findItr = currNode->find(command);
                    if(findItr == currNode->last()){
                        cout << "does not exist! " << endl;
                        continue;
                    }
                    currNode = findItr->second;
                }
                }


        private:
                Node* firstNode;
                int size;

};



int main(){
        Trie t;
        t.insert("hello", 35);
        t.insert("hey", 40);
        t.insert("ayo", 12);
        t.insert("aye", -30);
        t.insert("dog", 2000000);
        // t.print();
        t.printWords("hello");

}
