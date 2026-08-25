
#include "path.h"
mapping shop_shelves, smithy_shelves;

create() {
  shop_shelves = ([
          ARMOUR+"padded"	:   ({ 2, 2 }),
          ARMOUR+"studded"	:   ({ 2, 2 }),
          ARMOUR+"leather"	:   ({ 2, 2 }),
          ARMOUR+"ringmail"	:   ({ 1, 1 }),
          WEAP+"dagger"   	:   ({ 3, 1 }),
          WEAP+"flail"          :   ({ 2, 2 }),
          WEAP+"glaive"         :   ({ 2, 1 }),
          WEAP+"long_sword"     :   ({ 1, 1 }),
          WEAP+"morning_star"   :   ({ 2, 1 }),
   ]);

  smithy_shelves = ([
          ARMOUR+"scalemail"	:   ({ 1, 1 }),
          ARMOUR+"chainmail"	:   ({ 1, 1 }),
          ARMOUR+"leather"	:   ({ 2, 2 }),
          ARMOUR+"helmet"	:   ({ 2, 2 }),
          ARMOUR+"med_shield"	:   ({ 1, 2 }),
          ARMOUR+"sma_shield"	:   ({ 2, 1 }),
  ]);
} /* create() */

mapping query_shelves() {
    if(file_name(previous_object())==
      TOWN+"town09")
      return smithy_shelves;
    if (previous_object()->query_short()==
       "Realm of the Orc:  Snaga's Equipment Shop")
        return shop_shelves;
    return 0;
}
