//Validate BST
bool check(TreeNode* root,long int min,long int max){
        if(root==NULL)return true;
        if(root->val >min && root->val<max){
            bool left=check(root->left,min,root->val);
            bool right=check(root->right,root->val,max);
            return left && right;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true;
        if((root->left==NULL && root->right==NULL))return true;
        return check(root,LONG_MIN,LONG_MAX);
    }

//Preorder
vector<int> ans;
    void preorder(TreeNode* root) 
    {
        if(root==NULL)
          return;
        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root)
    {
        preorder(root);
        return ans; 
    }

//Inorder
vector<int> ans;
    void inorder(TreeNode* root) 
    {
        if(root==NULL)
          return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root)
    {
        inorder(root);
        return ans; 
    }

//Postorder
vector<int> ans;
    void postorder(TreeNode* root) 
    {
        if(root==NULL)
          return;
        postorder(root->left);
        postorder(root->right);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root)
    {
        postorder(root);
        return ans; 
    }

//Level order
 vector<vector<int>> res;
      queue <TreeNode*> q;
         q.push(root);
         if(root==NULL)
         return res;
          while(!q.empty())
          {
              vector<int> ans;
              int size= q.size();
              for(int i=0;i<size;i++)
              {
                 TreeNode* node= q.front();
                 q.pop();
                 if(node->left!=NULL)
                      q.push(node->left);
                 if(node->right!=NULL)
                      q.push(node->right);

                ans.push_back(node->val);
              }
              res.push_back(ans);
          }
        return res;

// BFS in Graph
#include<iostream>
#include<stdlib.h>
using namespace std;
int cost[10][10],i,j,k,n,qu[10],front,rare,v,visit[10],visited[10];
int main()
{
    int m;
    cout <<"Enter no of vertices:";
    cin >> n;
    cout <<"Enter no of edges:";
    cin >> m;
    cout <<"\nEDGES \n";
    for(k=1; k<=m; k++)
    {
        cin >>i>>j;
        cost[i][j]=1;
    }
    cout <<"Enter initial vertex to traverse from:";
    cin >>v;
    cout <<"Visitied vertices:";
    cout <<v<<" ";
    visited[v]=1;
    k=1;
    while(k<n)
    {
        for(j=1; j<=n; j++)
            if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
            {
                visit[j]=1;
                qu[rare++]=j;
            }
        v=qu[front++];
        cout<<v <<" ";
        k++;
        visit[v]=0;
        visited[v]=1;
    }
    return 0;
}

// DFS in Graph
#include<iostream>
#include<conio.h>
#include<stdlib.h>
int cost[10][10],i,j,k,n,stk[10],top,v,visit[10],visited[10];
int main()
{
    int m;
    cout <<"Enter no of vertices:";
    cin >> n;
    cout <<"Enter no of edges:";
    cin >> m;
    cout <<"\nEDGES \n";
    for(k=1; k<=m; k++)
    {
        cin >>i>>j;
        cost[i][j]=1;
    }
    cout <<"Enter initial vertex to traverse from:";
    cin >>v;
    cout <<"DFS ORDER OF VISITED VERTICES:";
    cout << v <<" ";
    visited[v]=1;
    k=1;
    while(k<n)
    {
        for(j=n; j>=1; j--)
            if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
            {
                visit[j]=1;
                stk[top]=j;
                top++;
            }
        v=stk[--top];
        cout<<v << " ";
        k++;
        visit[v]=0;
        visited[v]=1;
    }
    return 0;
}
