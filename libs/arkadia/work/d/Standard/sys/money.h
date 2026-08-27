/*
 * Copyright (c) 1991 Chalmers Computer Society
 *
 * This code may not be copied or used without the written permission
 * from Chalmers Computer Society.
 */

/*
   Specific gravities:  Copper: 8.9, Silver: 10.5, Gold: 19.3, Platinum: 21.4
*/

#define MONEY_FN "/sys/global/money.lpc"

#define MONEY_TYPES  ({ "copper", "silver", "gold", "platinum" })
#define MONEY_VALUES ({ 1       ,  12     , 144   , 1728 })
#define MONEY_WEIGHT ({ 18      ,  21     , 19    , 21  })
#define MONEY_VOLUME ({ 2       ,  2      , 1     , 1   })

#define MONEY_SPLIT(cp) call_other(MONEY_FN, "split_values", cp)

#define MONEY_MAKE_CC(num) call_other(MONEY_FN, "make_coins", "copper", num)
#define MONEY_MAKE_SC(num) call_other(MONEY_FN, "make_coins", "silver", num)
#define MONEY_MAKE_GC(num) call_other(MONEY_FN, "make_coins", "gold", num)
#define MONEY_MAKE_PC(num) call_other(MONEY_FN, "make_coins", "platinum", num)
