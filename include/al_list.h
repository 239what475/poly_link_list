//
// Created by zhuzh on 2022/6/17.
//

#ifndef DATA_STRUCTURE_AL_LIST_H
#define DATA_STRUCTURE_AL_LIST_H

#define OK 1
#define ERROR 0

#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct {
    float coef;
    int expn;
} term;

#define ElemType term

typedef int Status;

typedef struct ALNode {
    ElemType data;
    struct ALNode *next;
} *ALink, ALNode;
// 保证链表的最后一个结点的 next 为 NULL

typedef struct {
    ALink head, tail;
    int len;
} ALinkList;

/**
 * 分配由 p 指向的值为 e 的结点
 * @param p 分配的节点的指针
 * @param e 值
 * @return OK / ERROR
 */
Status MakeNode_AL(ALink *p, ElemType e);

/**
 * 释放 p 指向的结点
 * @param p 结点指针
 */
void FreeNode_AL(ALink *p);

/**
 * 构造一个空的线性链表 L
 * @param L 链表指针
 * @return OK / ERROR
 */
Status InitList_AL(ALinkList **L);

/**
 * 销毁线性链表 L
 * @param L 链表指针
 * @return OK / ERROR
 */
Status DestroyList_AL(ALinkList **L);

/**
 * 删除头结点后的第一个结点并返回
 * @param L 链表指针
 * @param q 被删除的结点
 * @return OK / ERROR
 */
Status DelFirst_AL(ALinkList *L, ALink *q);

/**
 * 将指针 s 所指的一串结点链接在线性链表 L 的最后一个结点，并改变链表 L 的尾指针指向新的尾节点
 * @param L 链表指针
 * @param s 新的结点
 * @return OK / ERROR
 */
Status Append_AL(ALinkList *L, ALink s);

/**
 * 已知 p 指向线性链表 L 中的一个结点，将 s 所指结点插入在 p 所指结点之后，并修改指针 p 指向新插入的结点
 * @param L 链表指针
 * @param p 结点指针
 * @param s 插入的结点
 * @return OK / ERROR
 */
Status InsAfter_AL(ALinkList *L, ALink *p, ALink s);

/**
 * 已知 p 指向线性链表 L 中的一个结点，返回 p 所指结点中数据元素的值
 * @param p 结点指针
 * @return p 的值
 */
ElemType GetCurElem_AL(ALink p);

/**
 * 判断链表是否为空
 * @param L 链表指针
 * @return bool
 */
bool ListEmpty_AL(ALinkList *L);

/**
 * 返回链表中元素个数
 * @param L 链表指针
 * @return 列表长度
 */
int ListLength_AL(ALinkList *L);

/**
 * 返回线性链表 L 中第一个数据节点的指针
 * @param L 链表指针
 * @return 第一个数据结点指针
 */
ALink GetFirst_AL(ALinkList *L);

/**
 * 返回线性链表 L 中第 i 个结点的指针
 * @param L 链表指针
 * @param i 结点位序
 * @param p 第 i 个结点的指针
 * @return OK / ERROR
 */
Status LocatePos_AL(ALinkList *L, int i, ALink *p);

#endif //DATA_STRUCTURE_AL_LIST_H
