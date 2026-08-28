#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include "std.h"

#define ENV         environment
#define CAP         capitalize
#define LOW         lower_case
#define FN          file_name
#define BN	    base_name
#define POS	    possessive

#define TP          this_player()
#define TPQN        ((string)TP->query_name())
#define TPQCN       ((string)TP->query_cap_name())
#define TPQP        ((string)TP->query_possessive())

#define TO          this_object()

#define PO          previous_object()

#define QCN	    query_cap_name()

#endif
