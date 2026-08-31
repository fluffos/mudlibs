// ranger.h
// contains information for the ranger guild
// created by Thrace Merin June 13 1999

// Ranger Definitions

#define DIR_RANGER "/std/thrace/ranger"
#define RANGER_OBJ DIR_RANGER+"/obj"

#define FUNC DIR_RANGER+"/ranger_func.lpc"

// Standard Definitions

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
