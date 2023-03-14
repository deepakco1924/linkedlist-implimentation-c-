#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using new_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define endl "\n"
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define int long long
#define ff first
#define ss second
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define sp(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// LINKED LIST
// it is liner data structure and dnynamic in nature
// it is not continguish memory but node in liner

// advantage of linked list is
// 1.the size is dyanmic in nature
// 2.inserting and deleling is fast from front and end in o(1) time

// disadvatage
// 1.random acces in not allow in linked other than vertor and array
// 2.extrra memory space required for pointer_safety
// 3. array have better cache locality

// IMPLIMENTATION
class node
{
public:
    int data;
    node *next; /// the whole class is one node
    // in which one data and pointer to the next node
    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
// first take example of inseration
// 1.insert at head
// 2.insert at middle
// 3.insert at the end
void insert_athead(node *&head, int d) // poiinting the head by refreance so that it reflect in main
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    node *temp = head;
    head = new node(d);
    head->next = temp;
    return;
}
int length(node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}
void insert_at_tail(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new node(d);
    return;
}
// insert at middle
void insert_at_midddle(node *&head, int d, int pos)
{
    if (pos == 0 || head == NULL)
    {
        insert_athead(head, d);
        return;
    }
    else if (pos >= length(head))
    {
        insert_at_tail(head, d);
        return;
    }
    node *temp = head;
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    node *n = new node(d);
    n->next = temp->next;
    temp->next = n;
    return;
}
void print_list(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
    return;
}
// DELETION
// 1.at head;
// 2.from middle
// 3.from the tail
void delete_from_head(node *&head)
{
    if (head == NULL)
    {
        // head is null than do nothing
        return;
    }
    node *temp = head;
    head = head->next;
    delete temp;
    return;
}
void delete_from_tail(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    node *temp = head;
    node *prev = head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
    return;
}
void delete_from_middle(node *&head, int pos)
{
    if (head == NULL or pos >= length(head))
    {
        // do nothing
        return;
    }
    else if (pos == 0)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    // else we go to ppos
    node *temp = head;
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    node *n = temp->next;
    temp->next = temp->next->next;
    delete n;
    return;
}
// SEARching
bool search_key(node *head, int key)
{
    while (head != NULL)
    {
        if (head->data == key)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}
bool search_recursive(node *head, int key)
{
    if (head == NULL)
    {
        return false;
    }
    if (head->data == key)
    {
        return true;
    }
    return search_recursive(head->next, key);
}
// taking input from user till -1;
void build(node *&head)
{
    int d;
    cin >> d;
    while (d != -1) // till end of file
    {
        insert_at_tail(head, d);
        cin >> d;
    }
    return;
}
// operator overloading
istream &operator>>(istream &is, node *&head)
{
    build(head);
    return is;
}
ostream &operator<<(ostream &os, node *head)
{
    print_list(head);
    return os;
}
// reversing the linkedlist
// swaping is not efficent way to reverse
// but what can we. we will change the direction of node->next from front to next;
void reverse_list(node *&head)
{
    if (head == NULL or head->next == NULL)
    {
        return;
    }
    node *prev = NULL;
    node *current = head;
    node *nextelement = NULL;
    while (current != NULL)
    {
        nextelement = current->next;
        current->next = prev;
        prev = current;
        current = nextelement;
    }
    head = prev;
}
node *recursive_reverse(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *smallhead = recursive_reverse(head->next);
    node *temp = head;
    temp->next->next = head;
    temp->next = NULL;
    return smallhead;
}
int ruuner_techinique(node *head)
{
    if (head == NULL)
    {
        // if no element is their then no median
        return -1;
    }
    if (head->next == NULL)
    {
        return head->data;
    }
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}
// find the kthe node from the end
int find_kthnode(node *head, int k)
{
    // 1.apprch is that find the length of list
    // and go from lenght-k steps
    //  it take two traversel
    // 2.approch is that fast and slow
    // first fast move k step
    // than both fast and slow move with same speed one step
    if (head == NULL || k > length(head))
    {
        return -1;
    }
    node *fast = head;
    node *slow = head;
    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
        /* code */
    }
    return slow->data;
}
// solve_two mergo sorted array
//
node *merge_list(node *a, node *b)
{
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }
    node *temp;
    if (a->data > b->data)
    {
        temp = b;
        temp->next = merge_list(a, b->next);
    }
    else
    {
        temp = a;
        temp->next = merge_list(a->next, b);
    }
    return temp;
}
node *find_middle(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *fast = head->next;
    node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
node *mergesort(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *mid = find_middle(head);
    node *a = head;
    node *b = mid->next;
    mid->next = NULL;
    a = mergesort(a);
    b = mergesort(b);
    node *c = merge_list(a, b);
    return c;
}
// flowd cycle algrothm
// to detect the cycle present in the linked list
bool cycle_detect(node *head)
{
    node *fast = head;
    node *slow = fast;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}
// to remove the cycle first solve
// first find the cycle present then
// that means fast ==slow
// then slow point to head
// then move slow and fast one step
// then when they again meet is the point of intersion
void remove_the_cycle(node *&head)
{
    node *fast = head;
    node *slow = fast;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            break;
        }
    }
    slow = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
    return;
}

// circuclar linked list
// it is the list wich is cirulare in nature
//  its is used implimnet to make circular queue
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
void insert_at_head_circular(Node *&head, int d)
{
    Node *n = new Node(d);
    Node *temp = head;
    if (temp != NULL)

    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
    else
    {
        n->next = n;
    }
    head = n;
}
void print_circuarlist(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}
Node *getnode(Node *&head, int d)
{
    Node *temp = head;
    while (temp->next != head)
    {
        if (temp->data == d)
        {
            return temp;
        }
    }
    if (temp->data == d)
    {
        return temp;
    }
    return NULL;
}
void deltenode(Node *&head, int d)
{
    Node *del = getnode(head, d);
    if (del == NULL)
    {
        return;
    }
    if (head == del)
    {
        head = head->next;
    }
    Node *temp = head;
    while (temp->next != del)
    {
        temp = temp->next;
    }
    temp->next = del->next;
    delete del;
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    cout << "test the linked list " << endl;
    cout << endl
         << endl;
    node *head = NULL;
    insert_athead(head, 1);
    insert_athead(head, 2);
    insert_athead(head, 3);
    insert_athead(head, 4);
    cout << head << endl;
    insert_at_tail(head, 10);
    insert_at_tail(head, 14);
    cout << head << endl;
    insert_at_midddle(head, 25, 3);
    cout << head << endl;
    insert_at_midddle(head, 20, 2);
    cout << head << endl;
    delete_from_head(head);
    cout << head << endl;
    delete_from_tail(head);
    cout << head << endl;
    delete_from_middle(head, 3);
    cout << head << endl;

    cout << "end of line" << endl;

    return 0;
}
