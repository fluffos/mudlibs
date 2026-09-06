/*
** Orgo the giant
**
** An aggressive npc that attacks only with a certain chance
**
** Author: Analena@Nightfall, 10feb97
** Update:
** Cloned by: /d/archwiz/common/defence/example/room/room4.c
*/

#include <rooms.h>
#include <properties.h>

inherit "/std/npc";

#define ARMOUR(x) "/p/school/examples/combat/armour/" x

void create()
{
  (::create());
  SetName("Orgo");
  SetRace("giant");
  SetLevel(18);
  SetStandard(QueryLevel());
  SetShort("Orgo the giant");
  SetLong("Orgo is an incredibly large giant. His skin looks thick as "
    "leather.\n");
  SetGender(GENDER_MALE);
  SetSize(PSIZE_LARGE);
  SetStr(22);
  SetInt(16);
  SetDex(17);
    // if you aren't certain about what size your npc should be take a look
    //   at the race files in /obj/race/base. Npcs of one of the races
    //   available to players should always have the same size as players
    //   of that race. The stats offsets there may also give you an idea
    //   of how to change your npc's stats. For the rest, set size and
    //   race roughly as you would expect them as a player judging from
    //   the npc's descriptions. Please don't code baby rabbits with
    //   a size of PSIZE_LARGE or mountain trolls with a dexterity of 50!

  SetAlign(-222);
  SetAggressive(1);
  SetAttackChance(400);
    // setting the chance that an aggressive npc  actually attacks an
    //   enemy. Attack chance may reach from 0 (no automatic attack) to
    //   1000 (attack every time, this is default). In this case, Orgo
    //   will attack any player or pet he encounters with a chance of 40%.

  SetHands( ({ ({"left fist",0,21}),({"right fist",0,19}) }) );
    // by default, an npc has two hands, "left hand" and "right hand",
    //   each with a hand-WC of 1. Since Orgo won't have any weapons
    //   to fight with but has to fight barehanded, we give him a much
    //   higher hand-WC.

  SetWimpy(20);
    // SetWimpy in an npc has about the same effect as it has in a
    //   player using the 'whimpy'-command. In this case, Orgo will
    //   run away if his HP fall below 20. Don't hesitate to give
    //   your npc a whimpy option, especially if it is just there
    //   for killing anyway, it will make the fight more lively ;)
    //   By giving the whimpy-level as a string rather than an
    //   integer you may also set a whimpy relative to the npc's
    //   MaxHP (e.g. SetWimpy("50") will make the living run away
    //   once it lost at least half of its HP).

  AddResistance(ST_FIRE,5);
  AddResistance(ST_COLD,5);
    // you may add percentual resistances against magical damage of
    //   a certain type using AddResistance (as opposed to setting
    //   absolute resistances with AddDefence). In this case, his
    //   thick, leathery skin makes Orgo 5% resistant against fire
    //   and cold attacks.

    // Note: Please don't set any resistances or defences if your
    //       npc doesn't provied a good explanation for it. A
    //       water-resistand fire-elemental or a heat-resistanc
    //       snowman are not only illogical but highly annoying
    //       for players fighting them!

  AddItem(ARMOUR("cloak"),REFRESH_REMOVE,#'wearme);
    // Orgo wears a cloak giving a bonus protection to giants
}
