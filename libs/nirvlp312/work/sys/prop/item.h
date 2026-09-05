/*
 *  <prop/item.h>
 */

#ifndef _sys_prop_item_h
#define _sys_prop_item_h

// for identifying if something is really a weapon or not.
#define P_WEAPON        "weapon"
#define P_ARMOUR        "armour"

#define P_NOT_HOLDABLE  "not_holdable"
#define P_NOT_PORTABLE  "not_portable"
#define P_NOT_WIELDABLE "not_wieldable" // should be made obsolete
#define P_NOT_BUYABLE   "not_buyable"
#define P_NOT_SELLABLE  "not_sellable"
#define P_NOT_TOSSABLE  "not_tossable"


// it's better that those objects that are wieldable say so
#ifndef P_WIELDABLE
#  define P_WIELDABLE   "wieldable"
#endif

#ifndef P_WEARABLE
#  define P_WEARABLE    "wearable"
#endif

/*
 * P_NOT_DROPPABLE and P_DESTRUCT_ON_DROP can be either just set. Or
 * they can be set to something which is understood by message. This
 * text will then be printed if the item is tried to be dropped. 
 */
#define P_NOT_DROPPABLE         "not_droppable"
#define P_DESTRUCT_ON_DROP      "destruct_on_drop"

/*
 * P_DESTRUCT_ON_DEATH must be defined for all (invis) items which
 * have a move-prevention (like curses, poison and so on), that have to
 * be destructed at the death of the "owning" player.
 */
#define P_DESTRUCT_ON_DEATH     "destruct_on_death"

/*
 * P_STATE_DESCRIPTION should contain an array of state descriptions of the
 * item like "worn", "wielded" or "open" or something other of this kind which
 * is suitable to be given out in parantheses behind the description of the
 * item
 */
#define P_STATE_DESCRIPTION "state_description"

#define P_SURFACE       "surface"
#define P_CONTAINER     "container"
#define P_LIQUID_CONTAINER "liquid_container"
#define P_KEY           "key"
#define P_PICKLOCK      "picklock"

#define P_SMOKABLE      "smokable"
#define P_ENCHANTMENTS  "enchantments"
/* should be a mapping enchantment-type -> enchantment-data */

#define P_SITTABLE      "sittable"      /* you can sit on it */
#define P_EATABLE       "eatable"       /* you can eat it */
#define P_DRINKABLE     "drinkable"     /* you can drink it */
/* A room can also define, that a fakeitem should be drinkable. In such a case,
 * the value of the property is an array of fakeitems, for which the drink 
 * action will be performed by COMMANDS_CONSUME. 
 * Example: set_property(P_DRINKABLE, ({ "water" })); */

/* defines for certain substances */
#define P_LIQUID        "liquid"
#define P_POISON        "poison"
// this should contain a string identifying the kind of poison so that
// same kinds are merged into one when moved into the same environment,

/* defines for states of substances */
#ifndef P_BURNING       // also defined in <prop/elements.h>
#define P_BURNING       "burning"
#endif

// Items with that property are saved by lib/persistence, but destructed.
// This should be used by items, which allow a certain amount of clones,
// to prevent clones in /etc/equipment_store.
#define P_UNIQUE        "unique"

// this can be set to a smell a thing has.
#define P_SMELL         "smell"

#define P_AREA_SIZE     "area_size"   // a surface, skin, fur etc. which has a
                                      // certain area size.

#define P_MUSIC_INSTRUMENT      "music_instrument"
#define P_FUR           "fur"           // it has a fur.
#define P_SKIN          "skin"          // it has a skin.
#define P_TANNED        "tanned"        // the fur or leather was tanned,

#define P_OMIT_FROM_ROOMINV "omit_from_roominv"

#endif /* _sys_prop_item_h */


