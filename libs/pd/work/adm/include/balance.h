/* Murmur@Nightmare */
#ifndef _BALANCE_H_
#define _BALANCE_H_
#define ARMOUR_TYPES ({ \
    "helmet", \
    "visor", \
    "body armour", \
    "armour", \
    "cloak", \
    "shield", \
    "glove", \
    "ring", \
    "belt", \
    "pants", \
    "boot", \
    "sock" \
})
#define ARMOUR_MIN_AC ([ \
    "helmet" : 1, \
    "visor" : 1, \
    "body armour" : 1, \
    "armour" : 1, \
    "cloak" : 1, \
    "shield" : 1, \
    "glove" : 1, \
    "ring" : 1, \
    "belt" : 1, \
    "pants" : 1, \
    "boot" : 1, \
    "sock" : 1 \
])
#define ARMOUR_MAX_AC ([ \
    "helmet" : 2, \
    "visor" : 1, \
    "body armour" : 6, \
    "armour" : 6, \
    "cloak" : 2, \
    "shield" : 2, \
    "glove" : 2, \
    "ring" : 1, \
    "belt" : 1, \
    "pants" : 3, \
    "boot" : 2, \
    "sock" : 1, \
])
#define ARMOUR_MIN_VALUE ([ \
    "helmet" : 0, \
    "visor" : 0, \
    "body armour" : 0, \
    "armour" : 0, \
    "cloak" : 0, \
    "shield" : 0, \
    "glove" : 0, \
    "ring" : 0, \
    "belt" : 0, \
    "pants" : 0, \
    "boot" : 0, \
    "sock" : 0 \
])
#define ARMOUR_MAX_VALUE ([ \
    "helmet" : 200, \
    "visor" : 150, \
    "body armour" : 300, \
    "armour" : 300, \
    "cloak" : 200, \
    "shield" : 200, \
    "glove" : 150, \
    "ring" : 250, \
    "belt" : 150, \
    "pants" : 200, \
    "boot" : 250, \
    "sock" : 100 \
])
#define ARMOUR_MIN_WEIGHT ([ \
    "helmet" : 10, \
    "visor" : 5, \
    "body armour" : 20, \
    "armour" : 20, \
    "cloak" : 7, \
    "shield" : 4, \
    "glove" : 2, \
    "ring" : 1, \
    "belt" : 3, \
    "pants" : 7, \
    "boot" : 6, \
    "sock" : 2 \
])
#define WEAPON_TYPES ({ \
    "axe",\
    "blade", \
    "blunt", \
    "flail",\
    "knife", \
    "projectile", \
    "ranged" \
})
#define WEAPON_MIN_AC ([ \
    "axe" : 0,\
    "blade" : 0, \
    "blunt" : 0, \
    "flail" : 0,\
    "knife" : 0, \
    "projectile" : 0, \
    "ranged" : 0 \
])
#define WEAPON_MAX_AC ([ \
    "axe" : 3,\
    "blade" : 3, \
    "blunt" : 3, \
    "flail" : 3,\
    "knife" : 3, \
    "projectile" : 3, \
    "ranged" : 3 \
])
#define WEAPON_MIN_WC ([ \
    "axe" : 1,\
    "blade" : 1, \
    "blunt" : 1, \
    "flail" : 1,\
    "knife" : 1, \
    "projectile" : 1, \
    "ranged" : 1 \
])
#define WEAPON_MAX_WC ([ \
    "axe" : 20,\
    "blade" : 20, \
    "blunt" : 20, \
    "flail" : 20,\
    "knife" : 20, \
    "projectile" : 20, \
    "ranged" : 20 \
])
#define WEAPON_MIN_VALUE ([ \
    "axe" : 1,\
    "blade" : 1, \
    "blunt" : 1, \
    "flail" : 1,\
    "knife" : 1, \
    "projectile" : 1, \
    "ranged" : 1 \
])
#define WEAPON_MAX_VALUE ([ \
    "axe" : 300,\
    "blade" : 300, \
    "blunt" : 300, \
    "flail" : 300,\
    "knife" : 300, \
    "projectile" : 300, \
    "ranged" : 300 \
])
#define WEAPON_MIN_WEIGHT ([ \
    "axe" : 8,\
    "blade" : 5, \
    "blunt" : 5, \
    "flail" : 5,\
    "knife" : 3, \
    "projectile" : 6, \
    "ranged" : 3 \
])
// These are the modifiers from combat that determine how much exp and skill 
// pts are given out                   
// Experience given for killing a monster
#define DEATH_EXP_MOD              1/25  
// Experience given for doing damage to a monster
#define ATTACK_DAMAGE_EXP_MOD      1/2           
// Attack skill points given for doing damage to a monster
#define ATTACK_ATTACK_SKILL_MOD    1/2                    
// Defense skill points given for revieving damage
#define ATTACK_DEFENSE_SKILL_MOD   1/4
// Melee skill points given for doing damage to a monster
#define ATTACK_MELEE_SKILL_MOD     1/2                  
// Double wielding skill points given for doing damage to a monster
#define ATTACK_DOUBLE_SKILL_MOD    1/2
// Weapon type skill points given for doing damage to a monster
#define ATTACK_TYPE_SKILL_MOD      1/2
#endif
