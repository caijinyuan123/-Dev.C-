
/*
�������� 
enum RBTColor{RED, BLACK};

template <class T>
class RBTNode{
    public:
        RBTColor color;    // ��ɫ
        T key;            // �ؼ���(��ֵ)
        RBTNode *left;    // ����
        RBTNode *right;    // �Һ���
        RBTNode *parent; // �����

        RBTNode(T value, RBTColor c, RBTNode *p, RBTNode *l, RBTNode *r):
            key(value),color(c),parent(),left(l),right(r) {}
};

template <class T>
class RBTree {
    private:
        RBTNode<T> *mRoot;    // �����

    public:
        RBTree();
        ~RBTree();

        // ǰ�����"�����"
        void preOrder();
        // �������"�����"
        void inOrder();
        // �������"�����"
        void postOrder();

        // (�ݹ�ʵ��)����"�����"�м�ֵΪkey�Ľڵ�
        RBTNode<T>* search(T key);
        // (�ǵݹ�ʵ��)����"�����"�м�ֵΪkey�Ľڵ�
        RBTNode<T>* iterativeSearch(T key);

        // ������С��㣺������С���ļ�ֵ��
        T minimum();
        // ��������㣺���������ļ�ֵ��
        T maximum();

        // �ҽ��(x)�ĺ�̽�㡣��������"�����������ֵ���ڸý��"��"��С���"��
        RBTNode<T>* successor(RBTNode<T> *x);
        // �ҽ��(x)��ǰ����㡣��������"�����������ֵС�ڸý��"��"�����"��
        RBTNode<T>* predecessor(RBTNode<T> *x);

        // �����(keyΪ�ڵ��ֵ)���뵽�������
        void insert(T key);

        // ɾ�����(keyΪ�ڵ��ֵ)
        void remove(T key);

        // ���ٺ����
        void destroy();

        // ��ӡ�����
        void print();
    private:
        // ǰ�����"�����"
        void preOrder(RBTNode<T>* tree) const;
        // �������"�����"
        void inOrder(RBTNode<T>* tree) const;
        // �������"�����"
        void postOrder(RBTNode<T>* tree) const;

        // (�ݹ�ʵ��)����"�����x"�м�ֵΪkey�Ľڵ�
        RBTNode<T>* search(RBTNode<T>* x, T key) const;
        // (�ǵݹ�ʵ��)����"�����x"�м�ֵΪkey�Ľڵ�
        RBTNode<T>* iterativeSearch(RBTNode<T>* x, T key) const;

        // ������С��㣺����treeΪ�����ĺ��������С��㡣
        RBTNode<T>* minimum(RBTNode<T>* tree);
        // ��������㣺����treeΪ�����ĺ����������㡣
        RBTNode<T>* maximum(RBTNode<T>* tree);

        // ����
        void leftRotate(RBTNode<T>* &root, RBTNode<T>* x);
        // ����
        void rightRotate(RBTNode<T>* &root, RBTNode<T>* y);
        // ���뺯��
        void insert(RBTNode<T>* &root, RBTNode<T>* node);
        // ������������
        void insertFixUp(RBTNode<T>* &root, RBTNode<T>* node);
        // ɾ������
        void remove(RBTNode<T>* &root, RBTNode<T> *node);
        // ɾ����������
        void removeFixUp(RBTNode<T>* &root, RBTNode<T> *node, RBTNode<T> *parent);

        // ���ٺ����
        void destroy(RBTNode<T>* &tree);

        // ��ӡ�����
        void print(RBTNode<T>* tree, T key, int direction);

#define rb_parent(r)   ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r)   ((r)->color==RED)
#define rb_is_black(r)  ((r)->color==BLACK)
#define rb_set_black(r)  do { (r)->color = BLACK; } while (0)
#define rb_set_red(r)  do { (r)->color = RED; } while (0)
#define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
#define rb_set_color(r,c)  do { (r)->color = (c); } while (0)
};
���� 
 * �Ժ�����Ľڵ�(x)��������ת
 *
 * ����ʾ��ͼ(�Խڵ�x��������)��
 *      px                              px
 *     /                               /
 *    x                               y                
 *   /  \      --(����)-->           / \                #
 *  lx   y                          x  ry     
 *     /   \                       /  \
 *    ly   ry                     lx  ly  
 *
 *
 */
/* 
 * �Ժ�����Ľڵ�(x)��������ת
 *
 * ����ʾ��ͼ(�Խڵ�x��������)��
 *      px                              px
 *     /                               /
 *    x                               y                
 *   /  \      --(����)-->           / \                #
 *  lx   y                          x  ry     
 *     /   \                       /  \
 *    ly   ry                     lx  ly  
 *
 *
 ����
 * �������뵽�������
 *
 * ����˵����
 *     root ������ĸ����
 *     node ����Ľ��        // ��Ӧ���㷨���ۡ��е�node
 */
 /* 
template <class T>
void RBTree<T>::insert(RBTNode<T>* &root, RBTNode<T>* node)
{
    RBTNode<T> *y = NULL;
    RBTNode<T> *x = root;

    // 1. �����������һ�Ŷ�������������ڵ���ӵ�����������С�
    while (x != NULL)
    {
        y = x;
        if (node->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    node->parent = y;
    if (y!=NULL)
    {
        if (node->key < y->key)
            y->left = node;
        else
            y->right = node;
    }
    else
        root = node;

    // 2. ���ýڵ����ɫΪ��ɫ
    node->color = RED;

    // 3. ������������Ϊһ�Ŷ��������
    insertFixUp(root, node);
}

/* 
 * �����(keyΪ�ڵ��ֵ)���뵽�������
 *
 * ����˵����
 *     tree ������ĸ����
 *     key ������ļ�ֵ
 */
 /* 
template <class T>
void RBTree<T>::insert(T key)
{
    RBTNode<T> *z=NULL;

    // ����½����ʧ�ܣ��򷵻ء�
    if ((z=new RBTNode<T>(key,BLACK,NULL,NULL,NULL)) == NULL)
        return ;

    insert(mRoot, z);
} 
*/ 
/* 
 * �����������������
 *
 * ���������в���ڵ�֮��(ʧȥƽ��)���ٵ��øú�����
 * Ŀ���ǽ������������һ�ź������
 *
 * ����˵����
 *     root ������ĸ�
 *     node ����Ľ��        // ��Ӧ���㷨���ۡ��е�z

template <class T>
void RBTree<T>::insertFixUp(RBTNode<T>* &root, RBTNode<T>* node)
{
    RBTNode<T> *parent, *gparent;

    // �������ڵ���ڣ����Ҹ��ڵ����ɫ�Ǻ�ɫ��
    while ((parent = rb_parent(node)) && rb_is_red(parent))
    {
        gparent = rb_parent(parent);

        //�������ڵ㡱�ǡ��游�ڵ�����ӡ�
        if (parent == gparent->left)
        {
            // Case 1����������ڵ��Ǻ�ɫ
            {
                RBTNode<T> *uncle = gparent->right;
                if (uncle && rb_is_red(uncle))
                {
                    rb_set_black(uncle);
                    rb_set_black(parent);
                    rb_set_red(gparent);
                    node = gparent;
                    continue;
                }
            }

            // Case 2�����������Ǻ�ɫ���ҵ�ǰ�ڵ����Һ���
            if (parent->right == node)
            {
                RBTNode<T> *tmp;
                leftRotate(root, parent);
                tmp = parent;
                parent = node;
                node = tmp;
            }

            // Case 3�����������Ǻ�ɫ���ҵ�ǰ�ڵ������ӡ�
            rb_set_black(parent);
            rb_set_red(gparent);
            rightRotate(root, gparent);
        } 
        else//����z�ĸ��ڵ㡱�ǡ�z���游�ڵ���Һ��ӡ�
        {
            // Case 1����������ڵ��Ǻ�ɫ
            {
                RBTNode<T> *uncle = gparent->left;
                if (uncle && rb_is_red(uncle))
                {
                    rb_set_black(uncle);
                    rb_set_black(parent);
                    rb_set_red(gparent);
                    node = gparent;
                    continue;
                }
            }

            // Case 2�����������Ǻ�ɫ���ҵ�ǰ�ڵ�������
            if (parent->left == node)
            {
                RBTNode<T> *tmp;
                rightRotate(root, parent);
                tmp = parent;
                parent = node;
                node = tmp;
            }

            // Case 3�����������Ǻ�ɫ���ҵ�ǰ�ڵ����Һ��ӡ�
            rb_set_black(parent);
            rb_set_red(gparent);
            leftRotate(root, gparent);
        }
    }

    // �����ڵ���Ϊ��ɫ
    rb_set_black(root);
}
*/

}
