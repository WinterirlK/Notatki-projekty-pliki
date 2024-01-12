#include <cstdio>
#include <cstdlib>

struct Lista {
    int id;
    struct Lista *Next;
};

struct Lista *Insert(struct Lista *Head, int id);
struct Lista *Delete(struct Lista *Head, int id);
int ifExist(struct Lista *Head, int id);
int count(struct Lista *Head);

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Lista **dane = (struct Lista **)calloc(n, sizeof(struct Lista *));

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        if (ifExist(dane[a - 1], b)) {
            dane[a - 1] = Delete(dane[a - 1], b);
        }
        else {
            dane[b - 1] = Insert(dane[b - 1], a);
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", count(dane[i]));
    }

    return 0;
}

struct Lista *Insert(struct Lista *Head, int id) {
    struct Lista *p = (struct Lista *)malloc(1 * sizeof(struct Lista));
    p->id = id;
    p->Next = Head;
    Head = p;
    return Head;
}

struct Lista *Delete(struct Lista *Head, int id) {
    struct Lista *tmp = Head;
    if (id == Head->id) {
        Head = Head->Next;
        free(tmp);
    }
    else {
        while (tmp->Next != NULL && tmp->Next->id != id) {
            tmp = tmp->Next;
        }
        struct Lista *p = tmp->Next;
        tmp->Next = p->Next;
        free(p);
    }
    return Head;
}

int ifExist(struct Lista *Head, int id) {
    while (Head != NULL) {
        if (Head->id == id) {
            return 1;
        }
        Head = Head->Next;
    }
    return 0;
}

int count(struct Lista *Head) {
    int ilosc = 0;
    while (Head != NULL) {
        ilosc++;
        Head = Head->Next;
    }
    return ilosc;
}
