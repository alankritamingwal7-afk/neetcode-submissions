struct Node{
    Node* links[26];
    bool flag=false;
        Node() {   // constructor to initialize
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
        flag = false;
    }

    //check for the key 
    bool containskey(char ch){
        return (links[ch-'a']!=nullptr);
    }
    //for getting the char
    Node* get(char ch){
        return links[ch-'a'];
    }
    //for puttting the key 
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    // for setting the end
    void setend(){
        flag=true;
    }
    //check for end
    bool isend(){
        return flag;
    }
};

class PrefixTree {
private:
    Node* root;
public:
    PrefixTree() {
        //will create a new object here
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(auto i:word){
            if(!node->containskey(i)){
                //when it's not present we put it
              node->put(i,new Node);  
            } 
            //if it's present get the char
            node=node->get(i);
        }
        // set the last flag at end of string
        node->setend();
        
    }
    
    bool search(string word) {
        Node* node=root;
        for(auto i:word){
            if(!node->containskey(i)){
                return false;
            }
            node=node->get(i);
        }
        return node->isend();
        
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(auto i:prefix){
            if(!node->containskey(i)){
                return false;
            }
            node=node->get(i);

        }
        return true;
        
    }
};
