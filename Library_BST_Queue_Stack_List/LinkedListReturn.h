#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct Node{
    ElementType value;// gia tri cua phan tu
    struct Node* next;
};

typedef struct Node Node;
Node* first;

Node* makeNode(ElementType v){
    Node* p ;// malloc
    p = malloc(sizeof(Node));
    p->value = v;
    p->next = NULL;// chua lien ket
    return p;
}

// chen 1 phan tu co gia tri v vao sau nut co gia tri x tren ds f
Node* insertAfter(Node* f, ElementType v, ElementType x){
   Node* cur;
   Node* pre;
   Node* new = makeNode(v);

   cur = f;

   while(pre->value != x && cur != NULL)
   {
      pre = cur;
       cur = cur->next;
   }

   if(cur != NULL){
      new->next = pre->next;
      pre->next = new;
   }
   else
      printf("Khong ton tai node co gia tri %d\n", x);


    return f;
}

// chen 1 phan tu co gia tri v vao truoc phan tu co gia tri x tren ds f
Node* insertBefore(Node* f, ElementType v, ElementType x){
    Node* new = makeNode(v);
    Node* cur;
    Node* pre;

    if(f->value == x){
      new->next = f;
      f = new;
    }
    else
    {
       cur = f;
       pre = NULL;

       while(cur != NULL && cur->value != x )
       {
          pre = cur;
          cur = cur->next;
       }

       if(cur != NULL){
         pre->next = new;
         new->next = cur;
       }
       else
         printf("Khong ton tai node co gia tri = %d\n",x);
    }

    return f;
}

Node* insertFirst(Node* f, ElementType v){
    Node* p = makeNode(v);
    p->next = f;
    return p;
}

Node* insertLast(Node* f, ElementType v){
    // tao moi 1 phan tu co gia tri v, chen va cuoi danh sach
    Node* p = makeNode(v);
    if(f == NULL) return p;

    Node* q = f;
    while(q->next != NULL) q = q->next;
    q->next = p;
    return f;
}

Node* insertLastRecursive(Node* f, ElementType v){
    if(f == NULL) return makeNode(v);
    f->next = insertLastRecursive(f->next,v);
    return f;
}

Node* Remove(Node* f, ElementType v){
    if(f == NULL) return NULL;
    if(f->value == v){
        Node* p = f->next;
        free(f);
        return p;
    }
    Node*q = f;
    while(q->next != NULL){
        if(q->next->value == v) break;
        q = q->next;
    }
    if(q->next != NULL){
        Node* p = q->next;
        q->next = q->next->next;
        free(p);
    }
    return f;
}
Node* RemoveRecursive(Node* f, ElementType v){
    if(f == NULL) return NULL;
    if(f->value == v){
        Node* p = f;
        f = f->next;
        free(p);
        return f;
    }
    f->next = RemoveRecursive(f->next,v);
    return f;
}

int count(Node* f){
    int c = 0;
    Node* p = f;
    while(p != NULL){
        c = c + 1;
        p = p->next;
    }
    return c;
}

int countRecursive(Node* f){
    if(f == NULL) return 0;
    return 1+countRecursive(f->next);
}

void printList(Node* f){
    // hien thi cac phan tu cua danh sach duoc tro bo f
    Node* p = f;// con tro chay, ban dau gan bang f
    while(p != NULL){
        printf("%d ",p->value);
        p = p->next;// cho o tro vao phan tu tiep theo
    }

    printf(", so phan tu cua danh sach la %d\n",count(f));
}
