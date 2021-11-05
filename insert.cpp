#include<iostream>

using namespace std;

class BTree{
  /* Node statement */
  class Node{
    public:
      /* Node attributes */
      Node **children;
      int *keys;
      bool leaf;
      int M;
      int size;

      /* Node construct */
      Node(
        int M,
        bool leaf
      ) : M(M),
          leaf(leaf),
          size(0){
        this->keys = new int[2 * M - 1];
        this->children = new Node *[2 * M];
      }

      /* Node public methods */
      void traverse(){
        int i;
        for(i = 0; i < this->size; i ++){
          if(!this->leaf){
            this->children[i]->traverse();
          }
          cout<<this->keys[i]<<"\t";
        }

        if(!this->leaf){
          this->children[i]->traverse();
        }
      }
      Node* search(int key){
        int i = 0;
        while(i < this->size && key > this->keys[i]){
          i ++;
        }

        if(this->keys[i] == key){
          return this;
        }

        if(this->leaf){
          return nullptr;
        }

        return this->children[i]->search(key);
      }
      void insert(int key){
        int i = this->size - 1;
        if(this->leaf){
          while(i >= 0 && this->keys[i] > key){
            this->keys[i + 1] = this->keys[i];
            i --;
          }

          this->keys[i + 1] = key;
          this->size ++;
        }else{
          while(i >= 0 && this->keys[i] > key){
            i --;
          }
          if(this->children[i + 1]->size == 2 * this->M - 1){
            this->splitChild(i + 1, this->children[i + 1]);

            if(this->keys[i + 1] < key){
              i ++;
            }
          }

          this->children[i + 1]->insert(key);
        }
      }
      void splitChild(int i, Node* node){
        Node *nodeTmp = new Node(node->M, node->leaf);
        nodeTmp->size = this->M - 1;

        for(int j = 0; j < this->M - 1; j ++){
          nodeTmp->keys[j] = node->keys[j + this->M];
        }

        if(!node->leaf){
          for(int j = 0; j < this->M; j ++){
            nodeTmp->children[j] = node->children[j + this->M];
          }
        }

        node->size = this->M - 1;

        for(int j = this->size; j >= i + 1; j --){
          this->children[j + 1] = this->children[j];
        }

        this->children[i + 1] = nodeTmp;

        for(int j = this->size - 1; j >= i; j --){
          this->keys[j + 1] = this->keys[j];
        }

        this->keys[i] = node->keys[this->M - 1];

        this->size ++;
      }
  };

  private:
    /* Attributes */
    Node* root;
    int M;

  public:
    /* Construct */
    BTree(int M)
      : M(M), root(nullptr){}

    /* Public methods */
    void traverse(){
      if(root) root->traverse();
      cout<<endl;
    }
    Node* search(int key){
      return (
        this->root
          ? this->root->search(key)
          : nullptr
      );
    }
    void insert(int key){
      if(this->root){
        if(this->root->size == 2 * M - 1){
          Node *nodeTmp = new Node(this->M, false);

          nodeTmp->children[0] = this->root;

          nodeTmp->splitChild(0, this->root);

          int i = 0;

          if(nodeTmp->keys[0] < key){
            i ++;
          }

          nodeTmp->children[i]->insert(key);

          this->root = nodeTmp;
        }else{
          this->root->insert(key);
        }
      }else{
        this->root = new Node(this->M, true);
        this->root->keys[0] = key;
        this->root->size = 1;
      }
    }
};

int main(){
  BTree tree(3);
  tree.insert(10);
  tree.insert(20);
  tree.insert(5);
  tree.insert(6);
  tree.insert(12);
  tree.insert(30);
  tree.insert(7);
  tree.insert(17);

  tree.traverse();

  int targets[] = { 6, 15 };
  for(int i = 0; i < 2; i ++){
    const int target = targets[i];
    if(tree.search(target)){
      cout<<target<<" is present"<<endl;
    }else{
      cout<<target<<" is not present"<<endl;
    }
  }

  return 0;
} 