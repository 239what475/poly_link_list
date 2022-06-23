//
// Created by zhuzh on 2022/6/21.
//

#ifndef DATA_STRUCTURE_POLY_LIST_H
#define DATA_STRUCTURE_POLY_LIST_H

#include "al_list.h"

typedef ALinkList polynomial;

Status InsertPart_Poly(ALinkList *L, ElemType e);

void CreatePoly(polynomial **P, int m);

void DestroyPoly(polynomial **P);

void PrintPoly(polynomial *P);

void AddPoly(polynomial *Pa, polynomial *Pb);

void SubtractPoly(polynomial *Pa, polynomial *Pb);

void MultiplyPoly(polynomial *Pa, polynomial *Pb);

#endif //DATA_STRUCTURE_POLY_LIST_H
