/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:
    string bfs(TreeNode* root){
        string s="";
        
        queue<TreeNode*> q;
        if(!root) {
        return "";}
        q.push(root);
        
        while(!q.empty()){
           
                TreeNode* temp=q.front();
                q.pop();
                if(temp)q.push(temp->left);
                if(temp)q.push(temp->right);
                if(temp!=nullptr) {s+= to_string(temp->val);
                s+=",";}
                else { 
                    s+="N,";
                continue;}
            
        }
        return s;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      return bfs(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return nullptr;
        queue<TreeNode*>q;
        vector<string>v;
        string s ="";
        for(char c:data){
            if(c!=','){
                s+=c;
            }
            else{
                v.push_back(s);
                s="";
            }
        }
        if (!s.empty()) {
          v.push_back(s);  
       }
       
       TreeNode* root=new TreeNode(stoi(v[0]));
       q.push(root);
       int i=1;
       while(i<v.size()-1){
          TreeNode* temp=q.front();
          q.pop();
          if(v[i] != "N"){TreeNode* newLeft = new TreeNode(stoi(v[i]));
           temp-> left= newLeft ;
           q.push(newLeft);}

          if(v[i+1] != "N"){
            TreeNode* newRight= new TreeNode(stoi(v[i+1]));
            temp-> right=newRight;
            q.push(newRight);}
          
          
          i+=2;
       }
       return root;
    }
};
