#include <iostream>
#include <stack>

using namespace std;


/*
struct Node
{
   struct Node *left;
   struct Node *right;
   char caracter;
};

struct Node* newNode(){
    struct Node *root = (struct Node*)malloc(sizeof(Node));
    root->left = NULL;
    root->right = NULL;
    return root;
}

*/

struct Node
{
    struct Node *right;
    struct Node *left;
    char caracter;

    Node(){
        right = NULL;
        left = NULL;
    }
};

void posfixa(char *entrada)
{
    stack<char> op,saida;

    int i = 0;

    char *topToken;

    char prioridade[95],reverso[301];

    prioridade['+'] = 1;
    prioridade['-'] = 1;
    prioridade['*'] = 2;
    prioridade['/'] = 2;
    prioridade['^'] = 3;
    int tam;

    while(entrada[i] != '\0')
        {

            if (
                ((entrada[i] >= 48) && (entrada[i] <= 57)) || 
                ((entrada[i] >= 65) && (entrada[i] <= 90)) || 
                ((entrada[i] >= 97) && (entrada[i] <= 122)) 
                ) 
            {
                saida.push(entrada[i]);
            }
            else if(entrada[i] == '(')
            {
                op.push(entrada[i]);
            }
            else if(entrada[i] == ')')
            {
                topToken = &op.top();
                op.pop();
            
                while(*topToken != '(')
                {
                    //cout << *topToken << endl;
                    saida.push(*topToken);
                    topToken = &op.top();
                    op.pop();
                }
            }
            else
            {
                
                while(!op.empty() && (prioridade[op.top()] >= prioridade[entrada[i]])){
                    saida.push(op.top());
                    op.pop();
                    
                }
                op.push(entrada[i]);
            }
            

            i++;
        }
        
        while(!op.empty())
        {
            saida.push(op.top());
            op.pop();
        }
        
        tam = saida.size();

        for(int j = 0; j < tam; j++){
            reverso[j] = saida.top();
            saida.pop();
        }
        for (int i = tam - 1; i >= 0; i--)
        {
            if(reverso[i] != '\0')
            {
                cout << reverso[i];
            }
        }
        
        cout << "\n" ;
}

int main(){

    //struct Node *node = new Node();
    
    char *entrada = (char*)malloc(301*sizeof(char));
    int itr;
    
    cin >> itr;
    
    while(itr)
        {
        cin >> entrada;
        posfixa(entrada);
        itr--;
    }
    
    return 0;
    
}