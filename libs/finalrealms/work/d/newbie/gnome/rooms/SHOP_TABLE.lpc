
#include "path.h"
#define ARMS "/baseobs/armours/"
#define WEPS "/baseobs/weapons/"
mapping shop_shelves;

create() {
  shop_shelves = ([
          ARMS+"leather"       :   ({ 2 , 2 }),
          ARMS+"sma_shield"    :   ({ 10, 2 }),
          ARMS+"med_shield"    :   ({ 10, 1 }),
          ARMS+"studded"       :   ({ 10, 1 }),
          WEPS+"long_sword"    :   ({ 10, 4 }),
          WEPS+"knife"         :   ({ 10, 2 }),
          WEPS+"short_sword"   :   ({ 2 , 1 }),
          WEPS+"dagger"        :   ({ 10, 4 }),
  ]);
}
mapping query_shelves() {
   return shop_shelves;
}           
