//To be used by all weapons to state their type. Orig by Casper
#ifndef _WEAPON_H
#define _WEAPON_H

/*
 * Weapon Types
 */
#define WEAPON_LONGSWORD        1
#define WEAPON_DAGGER           2
#define WEAPON_TWO_HANDED_SWORD 4
#define WEAPON_SHORTSWORD       8
#define WEAPON_BOW              16
#define WEAPON_CROSS_BOW        32
#define WEAPON_FISTS            64
#define WEAPON_PIKE             128
#define WEAPON_CLUB             256
/*
#define RESERVED          512
#define RESERVED          1024
#define RESERVED          2048
#define RESERVED          4098
#define RESERVED          8192
#define RESERVED          16348
#define RESERVED          32768
#define RESERVED          65536
#define RESERVED          131072
#define RESERVED          262144
#define RESERVED          524288
#define RESERVED          1048576
#define RESERVED          2097152
#define RESERVED          4194304
#define RESERVED          8388608
#define RESERVED          16777216
#define RESERVED          33554432
#define RESERVED          67108864
#define RESERVED          134217728
#define RESERVED          268435456
#define RESERVED          536870912
#define RESERVED          1073741824
#define RESERVED          2147483648
*/

#define WEAPON_TYPE ({"Longsword","Dagger","Shortsword","Bow","Cross bow","Unarmed","Pike","Club"})

#define WEAP_SKILL_LONGSWORD 0
#define WEAP_SKILL_DAGGER 1
#define WEAP_SKILL_TWO_HANDED_SWORD 2
#define WEAP_SKILL_SHORTSWORD 3
#define WEAP_SKILL_BOW 4
#define WEAP_SKILL_CROSS_BOW 5
#define WEAP_SKILL_FISTS 6
#define WEAP_SKILL_PIKE 7
#define WEAP_SKILL_CLUB 8
/*
 * weapon_info array indexes
 */
#define DMG_BONUS  0
#define DMG_RANGE  1
#define TOHT_BONUS 2
#define PARRY_MOD  3
#define HTVBS_ACT  4
#define HTVBS_PASS 5
#define MSVBS_ACT  6
#define MSVBS_PASS 7
#define WEAP_NAMES 8
#define WEAP_TYPE 9
#define WEAP_OBJ  10
#define HAND_PAIR 11

#endif /* _WEAPON_H */
