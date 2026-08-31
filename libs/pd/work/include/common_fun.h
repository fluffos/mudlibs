#ifndef __COMMON_FUN_H__
#define __COMMON_FUN_H_

#define TP this_player()
#define TO this_object()
#define PO previous_object()
#define QA query_alignment()
#define QCL query_class()
#define QSC query_subclass()
#define QN query_name()
#define QCN query_cap_name()
#define QP query_possessive()
#define QO query_objective()
#define QS query_subjective()
#define QG this_player()->query_gender()
#define QST(x) query_stats(x)
#define QBS(x) query_base_stats(x);
#define QSK(x) query_skill(x)
#define CAP(x) capitalize(x)
#define ENV(x) environment(x)
#define QPP(x) query_property(x)
#define EN environment()

#endif
