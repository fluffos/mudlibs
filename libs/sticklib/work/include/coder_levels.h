/*
 CODER LEVELS & LEVEL CHECKING LOGICS
 
 Use these macros each and every time you check if someone is a coder
 or not. Everything except macros is subject to change.
*/
 
#ifndef CODER_LEVELS_H
#define CODER_LEVELS_H
 
#define LVL_APPRENTICE          25
#define LVL_APPRENTICE_WIZARD   LVL_APPRENTICE
 
#define LVL_NOVICE              50
#define LVL_JUNIOR              LVL_NOVICE
#define LVL_NOVICE_CODER        LVL_NOVICE
#define LVL_NOVICE_WIZARD       LVL_NOVICE
 
#define LVL_CODER               75
#define LVL_WIZARD              LVL_CODER
 
#define LVL_SENIOR              100
#define LVL_SENIOR_WIZARD       LVL_SENIOR
 
#define LVL_ELDER               250
#define LVL_ELDER_WIZARD        LVL_ELDER
 
#define LVL_ARCH                500
#define LVL_ARCH_WIZARD         LVL_ARCH
 
#define LVL_PSUEDO              750
#define LVL_COADMIN             750
#define LVL_ADMIN               1000
 
 
// un-used for Shadowchaser
#define LVL_POLICE              1
#define LVL_JUNIOR_JUDGE        101
#define LVL_JUDGE               201
 
/* The Macros: */
#define IS_ADMIN(x)             ((x) >= LVL_COADMIN)
#define IS_CODER(x)             (x > 0)
#define IS_ADMIN_OB(ob)        (interactive(ob) && IS_ADMIN((int)ob->query_coder_level()))
#define IS_CODER_OB(ob)        (interactive(ob) && IS_CODER((int)ob->query_coder_level()))
 
#define LVL_CAN_SNOOP           LVL_NOVICE
#define LVL_CAN_PROMOTE         LVL_COADMIN
 
#endif /* CODER_LEVELS_H */
