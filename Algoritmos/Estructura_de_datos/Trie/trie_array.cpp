#include <bits/stdc++.h> 

using namespace std; 

struct node {
    char currentCharacter;       // 'a'
    bool isWord = false;                // false 
    int countWords = 0; 
    struct node *children[27];  // sus nodos hijos  [null,null,null.....] 
}*trie; 

// Inicializar 

void init() {
    trie = new node(); //crea un nuevo nodo
    trie->countWords = 0;
}

void insertWord(string word) {   // alto 
    node *currentNode =  trie; //el puntero se posiciona en el nodo trie que es el vacio 
    for (int i = 0; i< word.length(); i++) { //recorre toda la palabra a agregarse
        int character = word[i] - 'a';       // i = 0 'a'-'a' = 0; al restar a se obtiene un numero entre 0-26 correspondiente a una letra del alfabeto
        if(currentNode->children[character] == NULL ) { //si no hay ningun nodo hijo se crea un nuevo nodo
            currentNode->children[character] = new node(); //llevar puntero a este nuevo nodo
            //currentNode->children[character]->countWords = 0; //se pone que la letra de este nuevo nodo no se repite
            
        }
        currentNode = currentNode->children[character]; //el nuevo nodo actual es el nodo hijo en la casilla 'character' del nodoa ctual anterior
        // cout<< "Insertanto el caracter "<< word[i]<< endl;
        currentNode->currentCharacter = word[i]; //se determina el caracter del nodo actual a la letra de la palabra que se estaba analizando
        //currentNode->countWords++; //se incremeta el numero de repeticines de la letra
    }
    currentNode->isWord = true; //se recorrio toda la palabra entonces se marca este nodo como fin de palabra
}

bool searchWord(string word) {   // alto 
    node *currentNode =  trie;  
    for (int i = 0; i< word.length(); i++) {
        int character = word[i] - 'a';       // i = 0 'a'-'a' = 0
        if(currentNode->children[character] == NULL ) {
           return false;
        }
        currentNode = currentNode->children[character];
    }
    return currentNode->isWord;
}



int findWords(string prefix) {   // alto 
    node *currentNode =  trie;  
    for (int i = 0; i< prefix.length(); i++) {
        int character = prefix[i] - 'a';       // i = 0 'a'-'a' = 0
        if(currentNode->children[character] == NULL ) {
           return 0;
        }
        currentNode = currentNode->children[character];
    }
    return currentNode->countWords;
}

/*
void showTrie(node currentNode ) {
    node *currentNode =  trie;  
    for (int i =0; i< 27; i++) {
        currentNode = currentCharacter = word[i];
        cout (char(i+'a'));
        showTrie(currentNode)
    }
}*/ 


void isThereWord(string word) {
    if(searchWord(word)) {
        cout<<"si existe : "<<word<<" en el trie"<<endl;
    } else {
        cout<<"No Existe :P"<<endl;
    }
}

int main() {

    // Inicializar Trie
    init(); 
    string word = "auto";
    insertWord(word);
    isThereWord(word);
    word = "automovil";   
    insertWord(word);
    isThereWord("auto");
    isThereWord(word);
    return 0;
}
