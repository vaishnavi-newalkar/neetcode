class node{
    public:
       int key,val;
       node* prev;
       node* next;

       node(int k, int v){
        key=k;
        val=v;
        prev=next=NULL;
       }
};


class LRUCache {
public:
    int capacity;
    unordered_map<int,node*> mp;

    node* head;
    node* tail;

    void add(node* newNode){
    newNode-> next= head->next;
    newNode-> prev= head;

    head->next->prev = newNode;
    head->next= newNode;
}

void remove(node* delNode){
    delNode->prev->next = delNode->next;
    delNode->next->prev = delNode->prev;
}

void moveToFront(node* n){
    remove(n);
    add(n);
}

    LRUCache(int capacity) {
        this->capacity=capacity;

        head= new node(0,0);
        tail=new node(0,0);
        head->next= tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        node* n = mp[key];
        moveToFront(n);
        return n->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!= mp.end()){
            node* n = mp[key];
            n->val = value;
            moveToFront(n);
        }
        else{
            if(mp.size()==capacity){
                node* lru = tail->prev;
                remove(lru);
                mp.erase(lru->key);
            }
            node* newNode = new node(key,value);
            add(newNode);
            mp[key] = newNode;
        }
    }
};
