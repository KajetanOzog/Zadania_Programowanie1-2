//Kajetan Ozog

template <typename KEY_TYPE, typename DATA_TYPE>
class Node
{
public:

    KEY_TYPE key;
    DATA_TYPE data;
    Node* left;
    Node* right;

    Node(KEY_TYPE k, DATA_TYPE d)
    {
        key = k;
        data = d;
        left = NULL;
        right = NULL;
    }

    ~Node(){}
};

template <typename KEY_TYPE, typename DATA_TYPE>
class QueueElem
{
public:
    Node<KEY_TYPE, DATA_TYPE>* node;
    QueueElem<KEY_TYPE, DATA_TYPE>* next;

    QueueElem(Node<KEY_TYPE, DATA_TYPE>* node1)
    {
        node = node1;
        next = NULL;
    }
};

template <typename KEY_TYPE, typename DATA_TYPE>
class Q
{
public:
    QueueElem<KEY_TYPE, DATA_TYPE>* front;
    QueueElem<KEY_TYPE, DATA_TYPE>* rear;

    Q()
    {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    void in(Node<KEY_TYPE, DATA_TYPE>* node)
    {
        QueueElem<KEY_TYPE, DATA_TYPE>* temp = new QueueElem<KEY_TYPE, DATA_TYPE>(node);
        if (rear == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }

    Node<KEY_TYPE, DATA_TYPE>* out()
    {
        if (isEmpty())
        {
            return NULL;
        }
        QueueElem<KEY_TYPE, DATA_TYPE>* temp = front;
        Node<KEY_TYPE, DATA_TYPE>* data = temp->node;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete temp;
        return data;
    }
};

/*
template <typename KEY_TYPE, typename DATA_TYPE>
class Elem
{
public:
    Node<KEY_TYPE, DATA_TYPE>* node;
    Elem<KEY_TYPE, DATA_TYPE>* next;
    Elem(Node<KEY_TYPE,DATA_TYPE>* node1)
    {
        node = node1;
        next = NULL;
    }
};

template <typename KEY_TYPE, typename DATA_TYPE>
class Q
{
public:

    Elem<KEY_TYPE,DATA_TYPE>* front;
    Elem<KEY_TYPE,DATA_TYPE>* rear;

    Q()
    {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty()
    {
        return front == NULL;
    }


    void in(Node<KEY_TYPE,DATA_TYPE>* node)
    {
        Elem<KEY_TYPE, DATA_TYPE>* temp = new Elem(node);
        if (rear == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }

    Node<KEY_TYPE, DATA_TYPE>* out()
    {
        if (isEmpty())
        {
            return NULL;
        }
        Elem<KEY_TYPE, DATA_TYPE>* temp = front;
        Node<KEY_TYPE, DATA_TYPE>* data = temp->node;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete temp;
        return data;
    }
};
*/



template <typename KEY_TYPE, typename DATA_TYPE>
class BST{

public:

    Node <KEY_TYPE, DATA_TYPE>* root;

    BST()
    {
        root = NULL;
    }

    bool Insert(KEY_TYPE key, DATA_TYPE dat)
    {
        return ins(key,dat,root);
    }

    bool ins(KEY_TYPE k, DATA_TYPE d, Node<KEY_TYPE, DATA_TYPE>*& node)
    {
        if (node == NULL)
        {
            node = new Node<KEY_TYPE, DATA_TYPE>(k, d);
            return true;
        }
        else
        {
            if (k < node->key)
            {
                return ins(k, d, node->left);
            }
            else if (!(k < node->key) && !(node->key < k))
            {
                return false;
            }
            else
            {
                return ins(k, d, node->right);
            }
        }
    }

    DATA_TYPE* Search(KEY_TYPE key)
    {
        return ser(key,root);
    }

    DATA_TYPE* ser(KEY_TYPE k, Node<KEY_TYPE, DATA_TYPE>* node)
    {
        if(node == NULL)
        {
            return NULL;
        }
        else
        {
            if (k < node->key)
            {
                return ser(k, node->left);
            }
            else if (!(k < node->key) && !(node->key < k))
            {
                return &(node->data);
            }
            else
            {
                return ser(k,node->right);
            }
        }
    }

    Node<KEY_TYPE, DATA_TYPE>* mbR(Node<KEY_TYPE, DATA_TYPE>* node, KEY_TYPE k)
    {
        if (node == NULL || (node->left != NULL && !(node->left->key < k) && !(k < node->left->key) ) || (node->right != NULL && !(node->right->key < k) && !(k < node->right->key))) {
            return node;
        }

        if (k < node->key && node->left != NULL) {
            if (!(node->left->key < k) && !(k < node->left->key))
            {
                return node;
            }
            else
            {
                return mbR(node->left, k);
            }
        } else if (node->key < k && node->right != NULL) {
            if (!(node->right->key < k) && !(k < node->right->key)) {
                return node;
            } else {
                return mbR(node->right, k);
            }
        }

        return NULL;
    }

    Node<KEY_TYPE, DATA_TYPE>* mR(Node<KEY_TYPE, DATA_TYPE>* node)
    {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }


    bool Delete(KEY_TYPE key)
    {
        return del(key, root);
    }

    bool del(KEY_TYPE k, Node<KEY_TYPE, DATA_TYPE>*& node) {
        if (node == NULL) {
            return false;
        }

        if (k < node->key)
        {
            return del(k, node->left);
        }
        else if (node->key < k)
        {
            return del(k, node->right);
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                node = NULL;
                return true;
            }
            else if (node->left == NULL)
            {
                Node<KEY_TYPE, DATA_TYPE>* temp = node;
                node = node->right;
                delete temp;
                return true;
            }
            else if (node->right == NULL)
            {
                Node<KEY_TYPE, DATA_TYPE>* temp = node;
                node = node->left;
                delete temp;
                return true;
            } else {
                Node<KEY_TYPE, DATA_TYPE> *mr = mR(node->right);
                Node<KEY_TYPE, DATA_TYPE> *mbr = mbR(root, mr->key);
                if(mbr == NULL)
                {
                    return false;
                }
                if (mbr->left == mr)
                {
                    KEY_TYPE kk = mr->key;
                    DATA_TYPE dd = mr->data;
                    if(mr->right == NULL)
                    {
                        mbr->left = NULL;
                        delete mr;
                    }
                    else
                    {
                        mbr->left = mr->right;
                        delete mr;
                    }
                    node->key = kk;
                    node->data = dd;
                    return true;
                }
                if(mbr->right == mr)
                {
                    KEY_TYPE kk = mr->key;
                    DATA_TYPE dd = mr->data;
                    if(mr->right == NULL)
                    {
                        mbr->right = NULL;
                        delete mr;
                    }
                    else
                    {
                        mbr->right = mr->right;
                        delete mr;
                    }
                    node->key = kk;
                    node->data = dd;
                    return true;
                }
                return true;
            }
        }
    }

    void PreOrder()
    {
        pre(root);
    }

    void pre(Node<KEY_TYPE,DATA_TYPE>* node)
    {
        if(node == NULL)
        {
            return;
        }
        std::cout << node->key << node->data;
        pre(node->left);
        pre(node->right);
    }

    void InOrder()
    {
        in(root);
    }

    void in(Node<KEY_TYPE,DATA_TYPE>* node)
    {
        if(node == NULL)
        {
            return;
        }
        in(node->left);
        std::cout << node->key << node->data;
        in(node->right);
    }

    void PostOrder()
    {
        post(root);
    }

    void post(Node<KEY_TYPE,DATA_TYPE>* node)
    {
        if(node == NULL)
        {
            return;
        }
        post(node->left);
        post(node->right);
        std::cout << node->key << node->data;
    }

    void LevelOrder()
    {
        lev(root);
    }

    void lev(Node<KEY_TYPE, DATA_TYPE>* node)
    {
        if (node == NULL)
        {
            return;
        }

        Q<KEY_TYPE, DATA_TYPE> q;
        q.in(node);

        while (!q.isEmpty())
        {
            Node<KEY_TYPE, DATA_TYPE>* curr = q.out();
            std::cout << curr->key << curr->data;

            if (curr->left != NULL)
            {
                q.in(curr->left);
            }

            if (curr->right != NULL)
            {
                q.in(curr->right);
            }
        }
    }

    int Height()
    {
        if(root == NULL)
        {
            return -1;
        }
        if(root->left == NULL && root->right == NULL)
        {
            return 0;
        }
        int h = max(root);
        h--;
        if(h <= 0)
        {
            return -1;
        }
        else
        {
            return h;
        }
    }

    int max(Node<KEY_TYPE, DATA_TYPE>* node)
    {
        if (node == NULL)
        {
            return 0;
        }

        int l = max(node->left);
        int r = max(node->right);

        if(l > r)
        {
            return 1 + l;
        }
        else
        {
            return 1 + r;
        }
    }

    ~BST()
    {
        destroyTree(root);
    }

    void destroyTree(Node<KEY_TYPE, DATA_TYPE>* node) {
        if (node != NULL)
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }


};

