nosave object att;
#include "/players/exos/defs.h"

#define CHK_ATT();\
if((att=TP->query_attack()) && HERE(att,ENV(TP))) {\
ME("You are too preoccupied...\n");\
return 1;\
}

#define CHK_LVL(x);\
if(TPL<x) {\
ME("You are much too inexperienced for that!\n");\
return 1;\
}

#define CHK_SP(x);\
if(TPSP<x) {\
ME("You are too tired...\n");\
return 1;\
}

#define CHK_GHOST();\
if(TP->QGH) {\
ME("That just is not possible...\n");\
return 1;\
}
