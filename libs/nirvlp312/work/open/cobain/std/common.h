/*
 *  Compiled by Cobain
 *
 */

/* GENERAL */
#define TO this_object() 
#define PO previous_object() 

/* LIVING QUERIES */
#define QN query_name()
#define QRN query_real_name()
#define QP query_possessive()
#define QL query_level()
#define QXL query_extra_level()
#define QA(x) query_attrib(x)

/* THIS PLAYER */
#define TP this_player()
#define TPN TP->query_name()
#define TPRN TP->query_real_name()
#define TPL TP->query_level() 
#define TPXL TP->query_extra_level()
#define TPP TP->query_possessive() 
#define TPA(x) TP->query_attrib(x)

/* ATTACKING OBJECT */
#define ATT this_object->query_attack() 
#define ATTN ATT->query_name() 
#define ATTRN ATT->query_real_name() 
#define ATTL ATT->query_level()
#define ATTXL ATT->query_extra_level()
#define ATTP ATT->query_possessive()
#define ATTA(x) ATT->query_attrib(x)

/* ENVIRONMENTAL */
#define ENV(x) environment(x) 
#define ENVTP environment(this_player())
#define ENVTO environment(this_object())
#define ENVPO environment(previous_object())
#define TI this_interactive()

/* CODING */
#define CAP(x) capitalize(x) 
#define LOWER(x) lower_case(x) 
#define MO(x) move_object(x)
#define CO(x) clone_object(x)
#define MOCO(x) move_object(clone_object(x))
