#ifndef _sys_combat_h
#define _sys_combat_h

#include "combat/libs.h"
#include "bodypart.h"
#include "damage.h"
#include "wound.h"

#ifndef P_WEARABLE
#define P_WEARABLE "wearable"
#endif
#ifndef P_WIELDABLE
#define P_WIELDABLE "wieldable"
#endif

#define SHADOW_BODY "global/combat/shadow_body"

#define COMBAT_SERVER "global/server/combat"
#define COMBAT_COORDINATOR "global/combat/coordinator"

/* This is all old stuff and should be thrown out sometime */
#define C_CONCENTRATION        "combat_concentration"
#define C_RESOURCES            "combat_resources"
#define C_SHARED_RESOURCES     "combat_shared_resources"
#define C_ADDITIONAL_RESOURCES "combat_additional_resources"
#define C_PRERUNTIME           "combat_preruntime"
#define C_POSTRUNTIME          "combat_postruntime"
#define C_FIGHTPLAN_KEY        "combat_fightplan_key"
#define C_MOVE_TIME            500 /* time for a move out of a combat */

#define IMMEDIATE 0
#define FAST 1
#define NORMAL 2

#define COMBAT (COMBAT_SERVER->get_combat_coordinator(this_object()))

#define GET_ARMOR(x) (LIB_ARMOR->get_armor_data(x))
#define GET_LAYER(x) (LIB_ARMOR->get_layer(x))
#define GET_RIGID(x) (LIB_ARMOR->get_rigid(x))
#define GET_PROTECTION(x) (LIB_ARMOR->get_protection(x))

#define GET_WOUND(x) (LIB_WOUND->get_wound_data(x))
#define GET_STRENGTH(x) (LIB_WOUND->get_wound_strength(x))
#define GET_SPEED(x) (LIB_WOUND->get_wound_speed(x))
#define GET_HEALING(x) (LIB_WOUND->get_healing_rate(x))
#define DAMAGE2WOUND(x,y) (LIB_WOUND->damage2wound(x,(y)))

#define E_PARRY "parry"
#define E_DODGE "dodge"

#define MODIFY_PRIO 700
#define REACTION_PRIO (-500)

#define MAX_ACTIONS_PER_HB 10
#define USED_EVAL_COST_IN_HB 100000

#ifndef BASIC_DIR
#define BASIC_DIR       "basic/"
#endif

#ifndef COMPLEX_DIR
#define COMPLEX_DIR     "complex/"
#endif

#ifndef NEW_PREFIX
#define NEW_PREFIX      "new_"
#endif

#define ACTION          BASIC_DIR "action/" 

#define BASIC_TOOL      BASIC_DIR "tool"

#define BASIC_HOLD      BASIC_DIR "hold"
#define BASIC_ATTACK    BASIC_DIR "attack"
#define BASIC_DEFENSE   BASIC_DIR "defense"
#define BASIC_WEAPON    BASIC_DIR NEW_PREFIX "weapon"

#define WEAPON          COMPLEX_DIR "weapon"
#define ARMOUR          COMPLEX_DIR "armour"
#define BLOOD           COMPLEX_DIR "blood"

#define WEAPON_DIR      WEAPON "/"
#define ARMOUR_DIR      ARMOUR "/"

#endif /* _sys_combat_h */
