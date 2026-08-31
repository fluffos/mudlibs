/* Murmur@Nightmare */

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
    "helmet" : 40, \
    "visor" : 20, \
    "body armour" : 80, \
    "armour" : 60, \
    "cloak" : 25, \
    "shield" : 30, \
    "glove" : 20, \
    "ring" : 15, \
    "belt" : 20, \
    "pants" : 50, \
    "boot" : 30, \
    "sock" : 10, \
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
    "helmet" : 1500, \
    "visor" : 150, \
    "body armour" : 10000, \
    "armour" : 20000, \
    "cloak" : 500, \
    "shield" : 500, \
    "glove" : 150, \
    "ring" : 250, \
    "belt" : 200, \
    "pants" : 700, \
    "boot" : 250, \
    "sock" : 100 \
])

#define ARMOUR_MIN_WEIGHT ([ \
    "helmet" : 200, \
    "visor" : 100, \
    "body armour" : 600, \
    "armour" : 400, \
    "cloak" : 100, \
    "shield" : 300, \
    "glove" : 50, \
    "ring" : 40, \
    "belt" : 60, \
    "pants" : 140, \
    "boot" : 120, \
    "sock" : 100 \
])

#define WEAPON_TYPES ({ \
    "blade", \
    "knife", \
    "projectile", \
    "blunt", \
    "two handed blunt", \
    "two handed blade" , \
    "axe", \
    "two handed polearm", \
    "flail", \
"two handed flail", \
})

#define WEAPON_MIN_AC ([ \
"blade" : 0, \
"knife" : 0, \
"projectile" : 0, \
"blunt" : 0, \
"two handed" : 0 \
])

#define WEAPON_MAX_AC ([ \
    "blade" : 15, \
    "knife" : 5, \
    "projectile" : 5, \
    "blunt" : 20, \
    "two handed" : 25 \
])

#define WEAPON_MIN_WC ([ \
"blade" : 1, \
"knife" : 1, \
"projectile" : 1, \
"blunt" : 1, \
"two handed" : 1 \
])

#define WEAPON_MAX_WC ([ \
    "blade" : 60, \
    "knife" : 60, \
    "projectile" : 60, \
    "blunt" : 60, \
    "two handed" : 90 \
])

#define WEAPON_MIN_VALUE ([ \
    "blade" : 1, \
    "knife" : 1, \
    "projectile" : 1, \
    "blunt" : 1, \
    "two handed" : 1 \
])

#define WEAPON_MAX_VALUE ([ \
    "blade" : 400, \
    "knife" : 400, \
    "projectile" : 400, \
    "blunt" : 400, \
    "two handed" : 400 \
])

#define WEAPON_MIN_WEIGHT ([ \
    "blade" : 350, \
    "knife" : 200, \
    "projectile" : 350, \
    "blunt" : 350, \
    "two handed" : 350 \
])

// These are the modifiers from combat that determine how much exp and skill 
// pts are given out                   
// Experience given for killing a monster
#define DEATH_EXP_MOD             1/30
// Experience given for doing damage to a monster
#define ATTACK_DAMAGE_EXP_MOD      1/2
// Attack skill points given for doing damage to a monster
#define ATTACK_ATTACK_SKILL_MOD    1/2                    
// Melee skill points given for doing damage to a monster
#define ATTACK_MELEE_SKILL_MOD     1/2                  
// Double wielding skill points given for doing damage to a monster
#define ATTACK_DOUBLE_SKILL_MOD    1/2
// Weapon type skill points given for doing damage to a monster
#define ATTACK_TYPE_SKILL_MOD      1/2
