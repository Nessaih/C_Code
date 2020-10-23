/*
C语言实现字典：测试。 
*/ 

#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct nlist { /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name; /* defined name */
    char *defn; /* replacement text */
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE]; /* pointer table */

/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
      hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
          return np; /* found */
    return NULL; /* not found */
}
//string.h宏中已经定义此函数，此处屏蔽 
//char *strdup(char *s) /* make a duplicate of s */
//{
//    char *p;
//    p = (char *) malloc(strlen(s)+1); /* +1 for ’\0’ */
//    if (p != NULL)
//       strcpy(p, s);
//    return p;
//}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
          return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else /* already there */
        free((void *) np->defn); /*free previous defn */
    if ((np->defn = strdup(defn)) == NULL)
       return NULL;
    return np;
}



void test(void)
{
	struct nlist *p;
	p = install("hx","48");
	p = p->next;
	p = install("swj","22");
	p = p->next;
	p = install("tqy","33");
	p = p->next;
	p = install("lqs","14");
	p = p->next;
	p = NULL;
	
	p = lookup("hx");
	printf("%s\n",p->defn);
}
int main(void)
{
	test();
	return 0;
}
