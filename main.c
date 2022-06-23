#include "include/poly_list.h"

int main() {
    setbuf(stdout, NULL);
    polynomial *Pa = NULL, *Pb = NULL;

    CreatePoly(&Pa, 3);
    printf("Pa:\n");
    PrintPoly(Pa);

    CreatePoly(&Pb, 2);
    printf("\nPb:\n");
    PrintPoly(Pb);

    printf("\nPa + Pb:\n");
    AddPoly(Pa, Pb);
    PrintPoly(Pa);

    return 0;
}
