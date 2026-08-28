#ifndef __DEF_H__
#define __DEF_H__

#define ENV         environment
#define CAP         capitalize
#define LOW         lower_case
#define FN          file_name

#define TP          this_player()
#define TPQN        ((string)TP->query_name())
#define TPQCN       ((string)TP->query_cap_name())
#define TPQP        ((string)TP->query_possessive())

#define TO          this_object()

#define PO          previous_object()

#endif
