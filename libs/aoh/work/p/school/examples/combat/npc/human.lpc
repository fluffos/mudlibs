/*
** Daniel the human
**
** A simple, non-aggressive npc with standard equipment
**
** Author: Analena@Nightfall, 10feb97
** Update:
** Cloned by: /d/archwiz/common/defence/example/room/room1.c
*/

#include <combat.h>             // weapontypes, armourtypes and damagetypes
#include <rooms.h>              // refresh-flags for AddItem
#include <properties.h>         // property-defines

inherit "/std/npc";

#define WEAPON(x) "/p/school/examples/combat/weapon/" x
    // defining the directorz where to find example-weapons

#define ARMOUR(x) "/p/school/examples/combat/armour/" x
    // defining the directorz where to find example-armours

void create()
{
  (::create());
    // prevent the blueprint from being initialized

  SetName("Daniel");
    // set the name of the npc in proper capitalization

  SetRace("human"),
    // set the npc's race
    // every npc should have the appropriate race set or else it won't be
    //   effected by any special effects concerning its race. If you call
    //   your npc 'orc' it should be of race orc or else the player
    //   fighting it won't get any bonus from wielding the orcslayer
    //   sword. If you call your npc 'troll' it should be of race troll or
    //   else it won't get any bonus from wearing its troll boots.
  SetLevel(6);
    // set the npc's level. The level is used for computing stats,
    //   maxHP, maxSP and XP of the npc.
  SetStandard(QueryLevel());

  SetShort("Daniel the human");
  SetLong("Daniel is an ordinary human, totally uninteresting.\n");
  SetGender(GENDER_MALE);
    // give the npc a short-description, a long-description and a gender.

  SetSize(PSIZE_NORMAL);
    // set the size of the npc, showing what size of equipment it may
    //   wield or wear.

    // Note: Size restrictions of equipment are currently disabled but
    //       may be enabled again in the future.
  SetAlign(80);
    // each npc should have an alignment set, reaching from -1000 (demonic)
    //   to 1000 (godlike). Daniel is a kindly human.

  AddItem(WEAPON("shortSword"),REFRESH_REMOVE,#'wieldme);
    // this call to AddItem will clone a short sword for Daniel. The
    //   function 'wieldme' makes him automatically wield the sword
    //   after cloning. If Daniel should loose this sword, it will be
    //   refreshed, that is a new one will be cloned and wielded in the
    //   next reset.

  AddItem(ARMOUR("leatherArmour"),REFRESH_REMOVE,#'wearme);
    // the function 'wearme' takes care of Daniel automatically wearing
    //   the armour.

  AddItem("/std/armour",REFRESH_REMOVE,#'wearme,
    ({
      ([
        P_STANDARD:    ({AT_SHIELD,1,PSIZE_NORMAL})
      ]),
      ([
        P_SHORT:       "a wooden shield",
        P_LONG:        "This is a small shield made of wood.\n",
        P_ADS:         ({"small","wooden"})
      ])
    }) );

    // instead of writing an extra file you may also add a /std/armour or
    //   /std/weapon to your npc directly by using AddItem. In order
    //   to configure it correctly, use an array of two property mappings,
    //   the first one initializing the armour or weapon by a call to
    //   SetStandard, the second one setting the individial properties.
    //   This way you make certain that the initialization will take place
    //   before the rest of the settings.
}
