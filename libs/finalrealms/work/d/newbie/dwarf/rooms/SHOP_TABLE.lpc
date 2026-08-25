
/*  RATHBURN'S WORK */

#include "path.h"
#define ARMS "/baseobs/armours/"
#define WEPS "/baseobs/weapons/"
mapping shop_shelves, smithy_shelves;

create() {
  shop_shelves = ([
          ARMS+"leather"       :   ({ 10, 2 }),
          ARMS+"med_shield"    :   ({ 10, 1 }),
          ARMS+"helmet"        :   ({ 10, 1 }),
          MISC+"wood_bucket"   :   ({ 10, 4 }),
          WEPS+"pick"          :   ({ 10, 5 }),
          WEPS+"mace"          :   ({ 10, 2 }),
          MISC+"rope"          :   ({ 10, 4 }),
  ]);
  smithy_shelves = ([
          ARMOR+"leather"           :   ({ 10, 2 }),
          ARMS+"sma_shield"         :   ({ 10, 2 }),
          ARMOR+"dwarven_helm"      :   ({ 10, 3 }),
          ARMOR+"gloves"            :   ({ 10, 4 }),
          ARMOR+"dwarven_chain"     :   ({ 10, 2 }),
          ARMOR+"dwarven_gauntlets" :   ({ 10, 2 }),
          WEAPON+"short_sword"      :   ({ 10, 3 }),
          WEAPON+"dagger"           :   ({ 10, 3 }),
          WEAPON+"knife"            :   ({ 10, 4 }),
  ]);
} /* create() */

mapping query_shelves() {
    if (previous_object()->query_short()==
       "Realm of the Dwarf:  Darklor's Smithy")
        return smithy_shelves;
    if (previous_object()->query_short()==
       "Realm of the Dwarf:  Zundrin's Equipment Shop")
        return shop_shelves;
    return 0;
}
