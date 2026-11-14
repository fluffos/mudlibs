// Defines fuer Palastquest, Rage Feb 00

#define MAGIERNAME "rage"
#include "../def.h"

/*#define DB(x) if(find_player("rage")) \
        tell_object(find_player("rage"),"\n\nXXX"+x+"\n\n");*/

#define EISPALASTQUEST "Die Ahnenforschung im Eispalast"
#define EISPALASTQUESTLOG "/log/quests/eispalast"
 
#define QUESTMASTER "/d/polar/rage/questmaster"
#define QLOG "d/polar/rage/log"

#define AddGenderDetail(det,male,female) \
  AddDetail( det, lambda( 0, \
          ({ \
             #'?, ({ #'==, \
                     ({ #'call_other, \
                        ({ #'this_player }), "QueryProp", "gender" }), \
                     FEMALE \
                  }), \
                  ({ #'return, female }), \
                  ({ #'return, male }) }) ) )
