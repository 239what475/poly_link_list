//
// Created by zhuzh on 2022/6/22.
//

#include "poly_list.h"

Status InsertPart_Poly(ALinkList *L, term e) {
    ALink p = L->head, s;
    // 链表按照 compare的顺序从小到大排列，
    while (p->next && (p->next->data.expn < e.expn)) {
        p = p->next;
    }
    if (!p->next || (p->next->data.expn > e.expn)) {
        // 如果没有找到与 e 满足 compare 等于 0 的元素，则将 e 插入到 p 点后面
        MakeNode_AL(&s, e);
        return InsAfter_AL(L, &p, s);
    } else {
        // 如果找到与 e 满足 compare 等于 0 的元素，则修改这个元素的数据
        p->data.coef += e.coef;
        return true;
    }
}

void CreatePoly(polynomial **P, int m) {
    InitList_AL(P);
    ElemType e;
    // q 指向插入位置的前驱结点，s 为待插入结点
    ALink q, s;
    // 输入 m 个结点，并保证次数不一样
    for (int i = 1; i <= m; ++i) {
        printf("coef = ");
        scanf("%f", &(e.coef));
        printf("expn = ");
        scanf("%d", &(e.expn));
        // 在多项式中链表中找到对应的位置，插入结点
        InsertPart_Poly(*P, e);
    }
}

void DestroyPoly(polynomial **P) {
    DestroyList_AL(P);
}

void PrintPoly(polynomial *P) {
    if (!P) {
        printf("null polynomial. \n");
        return;
    }
    printf("-------------------------------\n");
    ALink l = P->head->next;
    while (l) {
        printf(" %fx^%d ", l->data.coef, l->data.expn);
        if (l->next) printf("+");
        l = l->next;
    }
    printf("\n");
    printf("-------------------------------\n");
}

void AddPoly(polynomial *Pa, polynomial *Pb) {
    // 获取头结点，后去作为 pa 和 pb 的前序结点
    ALink ha = Pa->head,hb = Pb->head;
    // 获取第一个数据结点
    ALink pa = GetFirst_AL(Pa), pb = GetFirst_AL(Pb), q;
    // 对 Pa 和 Pb 进行遍历，每次向 Lc 中添加一个结点
    while (pa && pb) {
        // 获取当前数据
        ElemType a = GetCurElem_AL(pa), b = GetCurElem_AL(pb);
        if(a.expn == b.expn) {
            // Pa: 1   2   3   (4)   5   ...
            // Pb:               4      6...
            // ->
            // Pa: 1   2   3   4   (5)   ...
            // Pb:                      6...
            float sum = a.coef + b.coef;
            if(sum !=0) {
                pa->data.coef = sum;
                ha = pa;
            } else {
                ha->next = pa->next;
                FreeNode_AL(&pa);
            }
            DelFirst_AL(Pb,&pb);
            FreeNode_AL(&pb);
            pb = hb->next;
            pa = ha->next;
        } else if (a.expn < b.expn) {
            // Pa: (1)   3   4   5   ...
            // Pb:    2      4      6...
            // ->
            // Pa: 1   (3)   4   5   ...
            // Pb:    2      4      6...

            ha = pa;
            pa = pa->next;
        } else {
            // Pa: 1   (3)   4   5   ...
            // Pb:   2       4      6...
            // ->
            // Pa: 1   2   3   (4)   5   ...
            // Pb:               4      6...

            DelFirst_AL(Pb,&pb);
            // 将 pb 拼接到 Pa 中
            pb->next = pa;
            ha->next = pb;
            pb = hb->next;
            ha = ha->next;
        }
    }
    if(!ListEmpty_AL(Pb)) Append_AL(Pa,pb);
    hb->next = NULL;
    DestroyPoly(&Pb);
}
