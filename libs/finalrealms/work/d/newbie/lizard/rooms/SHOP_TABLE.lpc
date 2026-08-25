
#include "path.h"
#define MISCS "/baseobs/misc/"
mapping shop_shelves, smithy_shelves;

create() {
  shop_shelves = ([
	  ARMOR+"scalemail"	    :   ({ 10, 2 }),
	  WEAPON+"trident"	    :   ({ 10, 1 }),
	  MISCS+"torch"		    :   ({ 10, 2 }),
  ]);
  smithy_shelves = ([
	  ARMOR+"scalemail"	    :   ({ 10, 2 }),
	  WEAPON+"trident"	    :   ({ 10, 1 }),
  ]);
} /* create() */

mapping query_shelves() {
    if (previous_object()->query_short()==
       "Realm of the Lizard:  Town Smithy")
        return smithy_shelves;
    if (previous_object()->query_short()==
       "Realm of the Lizard:  Midea's Little Shop")
        return shop_shelves;
    return 0;
}
