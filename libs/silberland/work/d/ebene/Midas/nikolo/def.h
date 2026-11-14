#define MAGIERNAME "Midas"
#define GEBIET "nikolo"
#include "../../def.h"

#define AddGenderDetail(x, y, z)  \
  AddDetail( x, lambda(0,({#'sprintf,"%s",\
        ({#'?,({#'==, ({#'call_other, ({#'this_player}), \
                       "QueryProp", P_GENDER}), FEMALE}),\
                  break_string(y), break_string(z) })})));


