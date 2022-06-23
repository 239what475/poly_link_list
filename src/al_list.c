//
// Created by zhuzh on 2022/6/17.
//

#include "al_list.h"

Status MakeNode_AL(ALink *p, ElemType e) {
    ALink l = malloc(sizeof(ALNode));
    if (!l) return ERROR;
    l->data = e;
    l->next = NULL;
    *p = l;
    return OK;
}

void FreeNode_AL(ALink *p) {
    free(*p);
}

Status InitList_AL(ALinkList **L) {
    // 防止重复初始化
    if (*L) return ERROR;
    ElemType e = {0.0f, -1};
    ALinkList *l = malloc(sizeof(ALinkList));
    l->len = 0;
    if (!MakeNode_AL(&l->head, e)) return ERROR;
    l->head->next = NULL;
    l->tail = l->head;
    *L = l;
    return OK;
}

Status DestroyList_AL(ALinkList **L) {
    // 不重复销毁
    if (!*L) return ERROR;
    ALink p = (*L)->head, q;
    while (p) {
        q = p->next;
        FreeNode_AL(&p);
        p = q;
    }
    free(*L);
    *L = NULL;
    return OK;
}


Status DelFirst_AL(ALinkList *L, ALink *q) {
    // 如果链表被销毁或为空
    if (!L || ListEmpty_AL(L)) return ERROR;
    *q = L->head->next;
    L->head->next = L->head->next->next;
    (*q)->next = NULL;
    // 如果链表长度为 1，则需要改变链表最后一个结点的指向
    if (ListLength_AL(L) == 1) {
        L->tail = L->head;
        L->tail->next = NULL;
    }
    L->len -= 1;
    return OK;
}

Status Append_AL(ALinkList *L, ALink s) {
    // 排除空结点和链表销毁
    if (!s || !L) return ERROR;
    // 在链表尾部拼接结点 s
    L->tail->next = s;
    // 计算拼接的链表的长度，以及找到最后一个结点
    int plus = 1;
    while (s->next) {
        plus++;
        s = s->next;
    }
    L->len += plus;
    L->tail = s;
    L->tail->next = NULL;
    return OK;
}

ElemType GetCurElem_AL(ALink p) {
    return p->data;
}

bool ListEmpty_AL(ALinkList *L) {
    return L->len == 0;
}

int ListLength_AL(ALinkList *L) {
    return L->len;
}

ALink GetFirst_AL(ALinkList *L) {
    return L->head->next;
}

// 已知 p 为链表中的一个结点
Status InsAfter_AL(ALinkList *L, ALink *p, ALink s) {
    // 检查链表是否被销毁
    if (!L) return ERROR;
    // 将结点拼接到 p 的后面
    s->next = (*p)->next;
    (*p)->next = s;
    // 如果 p 是最后一个结点，则插入结点后需要改变链表的最后一个结点的指向
    if (*p == L->tail) {
        L->tail = s;
        L->tail->next = NULL;
    }
    // 并将 p 指向结点 s
    *p = s;
    // 增加链表长度
    L->len += 1;
    return OK;
}