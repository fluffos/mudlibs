#define COND_MAX 1000 // 100% condition
#define COND_RANGE 250 // the max spread between max_cond and cond
#define COND_FAIL 0 // arbitrary breakage factor.
               // raise to increase chance, lower to decrease chance.
#define ARMOUR_MOD ({1,1,1.1,1.2,1.3,2,1.7,3,2,2,2,2,2,2,2,2})
// 0:default/none 1:bodyarmour  2:shield 3: helmet 4: boots 5: amulet
// 6:cloak 7: ring 8:gloves 9: belt 10: backpack 11:trousers
// 12 shirt ++++

#define MATERIAL_MOD ({1,1.5,1,2,4,1,1,1,1,1,1,1})   
//0: default/none 1: wood 2:metal 3:leather 4:cloth +++

#define COND_MOD ({2,1,1,0,0,-1,-1,-2,-2,-3,-3,0,0,0,0,0,0})
//Above: condition of the item 10 being MAX_COND
//mods to the damage done

#define AC_MOD ({1,1,1.1,1.2,1.3,2,1.7,3,2,2,2,2,2,2,2,2})

