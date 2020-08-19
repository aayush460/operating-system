//assignment 2.b
#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<unistd.h>

struct Node 
{ 
    int data; 
    Node* left, * right; 
}; 
struct Node* newNode(int data) 
{ 
    struct Node* node = (Node*)malloc(sizeof(Node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 
struct Node* insertLevelOrder(int arr[], Node* root, int i, int n) { 
    if (i < n) 
    { 
        struct Node* temp = newNode(arr[i]); 
        root = temp; 
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n); 
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n); 
    } 
    return root; 
} 
int maxDepth(struct Node* node)  { 
   if (node==NULL)  
       return 0; 
   else { 

       int lDepth = maxDepth(node->left); 
       int rDepth = maxDepth(node->right); 
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else return(rDepth+1); 
   } 
}

int main() {
    
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    pid_t pid = fork();
    Node* root = NULL;
    if(pid == 0){
        insertLevelOrder(a, root, 0, n);
        printf("Child Process\n");
        
        printf("Tree Created\n");
    }
    else{
        printf("Parent Started\n");
        wait(NULL);
        printf("Child Terminated\n");
        maxDepth(root);
        printf("Parent Process\n");
        
        printf("%d\n",maxDepth(root));
    }
    
    
}
