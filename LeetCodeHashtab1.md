
## 设计哈希集合
不使用任何内建的哈希表库设计一个哈希集合

具体地说，你的设计应该包含以下的功能

+ add(value)：向哈希集合中插入一个值。
+ contains(value) ：返回哈希集合中是否存在这个值。
+ remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。

示例:
```C++
MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // 返回 true
hashSet.contains(3);    // 返回 false (未找到)
hashSet.add(2);          
hashSet.contains(2);    // 返回 true
hashSet.remove(2);          
hashSet.contains(2);    // 返回  false (已经被删除)
```

**注意：**

+ 所有的值都在 [0, 1000000]的范围内。
+ 操作的总数目在[1, 10000]范围内。
+ 不要使用内建的哈希集合库。

### 题解：
```C++
#include <iostream>

using namespace  std;

#define HASHSIZE  21

typedef struct hashnode {
    int key;
    struct hashnode *next;
}HashNode;

HashNode *hashtab[HASHSIZE];

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {

    }

    int hash(int key) {
        key = key % HASHSIZE;
        return key;
    }
    // void test(void) 
    // {
    //     for (int i = 0; i < 1000; i++)
    //         cout << "i = " << i << "  hash = " << hash(i)<<'\n';
    // }

    void add(int key) {
        HashNode *p, *node;
        int hashval;
        hashval = hash(key);
        p = hashtab[hashval];
        if (false == contains(key)) {
            node = (HashNode *)malloc(sizeof(HashNode));
            node->key = key;
            if (hashtab[hashval] == NULL){
                hashtab[hashval] = node;
                node->next = hashtab[hashval];
            }
            else {
                p = hashtab[hashval]->next;
                hashtab[hashval]->next = node;
                node->next = p;
            }
        }
    }

    void remove(int key) {
        HashNode *h, *p;
        int hashval;
        hashval = hash(key);
        h = hashtab[hashval];
        p = h;
        if (p != NULL) {
            do{
                if (p->key == key){
                    break;
                }
                h = p;
                p = p->next;
            } while (p == hashtab[hashval]);
            if (h->next == p->next)
                hashtab[hashval] = NULL;
            else 
                h->next = p->next;
            free(p);
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        HashNode *h, *p;
        int hashval;
        hashval = hash(key);
        h = hashtab[hashval];
        p = h;
        while (p != NULL) {
            if (p->key == key)
                return true;
            if (p->next != h)
                p = p->next;
            else
                break;
        }
        return false;
    }
};
int main(void)
{

    MyHashSet hashSet = MyHashSet();
    //hashSet.test();
    hashSet.add(6);
    hashSet.remove(4);
    hashSet.add(17);
    cout << hashSet.contains(14);
    hashSet.add(17);
    hashSet.remove(14);
    hashSet.add(14);
    hashSet.add(14);
    hashSet.add(18);
    hashSet.add(14);
    return 0;
}


/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
 
```
