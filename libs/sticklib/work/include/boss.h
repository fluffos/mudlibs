#ifndef _BOSS_H
#define _BOSS_H

#ifndef _AREAS_H
#include "areas.h"
#endif

#ifndef _GENERIC_ITEMS_H
#include "generic_items.h"
#endif

#define POTION_DETECT_MAGIC             "/std/obj/potion_detm"
#define POTION_REGENERATION             "/std/obj/potion_regen"
#define POTION_REFRESHING               "/std/obj/potion_refr"
#define POTION_MANA                     "/std/obj/potion_mana"
#define POTION_HEALING                  "/std/obj/potion_heal"

#define SCROLL_ENCHANT_ARMOUR           "/std/obj/earm_scroll"
#define SCROLL_ENCHANT_WEAPON           "/std/obj/ewpn_scroll"
#define SCROLL_OF_HEALING               "/std/obj/scroll_of_healing"
#define SCROLL_OF_RECALL                GENERIC_SCROLL_OF_RECALL
#define SCROLL_OF_TIME_DISTORTION       "/std/obj/reset_scroll"
#define SCROLL_OF_LOCATION              "/std/obj/locate_scroll"
#define SCROLL_OF_ABJURATION            "/std/obj/abjure_scroll"

#define LEAF_COCA                       GENERIC_COCA
#define MAGIC_LOCKPICK                  GENERIC_MAGIC_LOCKPICK

#endif /* _BOSS_H */
