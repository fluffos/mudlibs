
#include "path.h"

mapping shop_shelves, smithy_shelves;

create() {
  shop_shelves = ([
          ARMOR+"studded"          :   ({ 1 , 1 }),
          ARMOR+"padded"           :   ({ 1 , 2 }),
          WEAPON+"dagger"          :   ({ 2 , 2 }),
          WEAPON+"morning_star"    :   ({ 1 , 2 }),
          WEAPON+"mace"            :   ({ 1 , 2 }),
          WEAPON+"club"            :   ({ 2 , 2 }),
          WEAPON+"pick"            :   ({ 1 , 2 }),
          WEAPON+"whip"            :   ({ 2 , 2 }),
          WEAPON+"short_sword"     :   ({ 1 , 2 }),
  ]);
    smithy_shelves = ([
          WEAPON+"short_sword"     :   ({ 2 , 2 }),
          WEAPON+"dagger"          :   ({ 3 , 2 }),
          ARMOR+"scalemail"        :   ({ 1 , 2 }),
          ARMOR+"leather"          :   ({ 2 , 2 }),
          ARMOR+"helmet"           :   ({ 2 , 1 }),
          ARMOR+"ringmail"         :   ({ 1 , 2 }),
          ARMOR+"sma_shield"       :   ({ 2 , 2 }),
    ]);
} /* create() */

mapping query_shelves() {
    if (previous_object()->query_short()==
       "Realm of the Goblin:  Thrakis's Smithy")
        return smithy_shelves;
    if (previous_object()->query_short()==
       "Realm of the Goblin:  Parham's Smelly Shop")
        return shop_shelves;
    return 0;
}

