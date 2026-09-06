/*
** Valery, an elven maiden
**
** Valery's goal in life is to rid the world of all vampires. She is
**   aggressive against vampires only, and equipped with some special
**   equipment against vampires and their psycho attacks
**
** Author: Analena@Nightfall, 10feb97
** Update:
** Cloned by: /d/archwiz/common/defence/example/room/room3.c
*/

#include <guild.h>
#include <rooms.h>
#include <properties.h>
#include <combat.h>

inherit "/std/npc";

#define WEAPON(x) "/p/school/examples/combat/weapon/" x
#define GARLIC "/d/archwiz/common/obj/garlic"

void create()
{
  seteuid(getuid());
  ::create();
  SetName("Valery");
  SetRace("elf");
  SetLevel(11);
  SetStandard(QueryLevel());
  SetShort("Valery, an elven maiden");
  SetLong("Valery is a young elf. She is a friendly girl, but will turn "
    "into a deadly adversary if she stumbles across a vampire.\n");
  SetGender(GENDER_FEMALE);
  SetSize(PSIZE_NORMAL);
  SetInt(14);
  SetDex(12);
  SetStr(10);
  SetAlign(150);
  SetAggressive(1);

    // she will only act aggressive against players and pets with either
    //   race or guildclass vampire as specified through the function
    //   IsFriend.
  AddItem(WEAPON("stake"),REFRESH_REMOVE,#'wieldme,2);
    // Valery is wielding a stake in each hand which gives a bonus on
    //   attacks against vampires.

  AddItem("/std/armour",REFRESH_REMOVE,#'wearme /*'*/,
    ({
      ([
        P_STANDARD:             ({AT_HELMET,0,PSIZE_NORMAL})
      ]),
      ([
        P_SHORT:                "a silver headband",
        P_LONG:                 "A headband made of silver.\n",
        P_IDS:                  ({"band","headband"}),
        P_ADS:                  ({"silver"}),
        P_DEFENCES:             ({0,0,0,0,0,0,0,0,0,0,0,0,5})
    // you may directly set the defences-array of any armour this
    //   way, including the intrinsic AC on array position 0 (DT_INTR).
    //   This example could have been set by
    //     SetAC(0);
    //     AddDefence(DT_PSYCHO,5);
    //   if we had written an extra file for this armour which is
    //   recommended in this case as it is much better readable.

    // Note: This armour clearly doesn't meet the 'average defences'-
    //       rule stated in the preceeding example since the average
    //       of all defences is above 0. Exceptions like these are
    //       possible as long as the average defences against
    //       conventional damage types is 0 or below but have to be
    //       approved by the department of defence.

      ])
    }) );
  AddItem(GARLIC,REFRESH_REMOVE);
    // equiping your npcs with garlic makes them less vulnerable to vampire
    //   attacks ;)
}

int IsFriend(object enemy)
{
    // the function IsFriend checks if the given enemy is a friend of
    //   this living. Per default, IsFriend returns 1 if both the enemy
    //   and this living either are players or npcs. IsFriend is called
    //   whenever any aggressive npc tries to auto-attack another
    //   living. If IsFriend returns 1, the attack is cancled.

  if(::IsFriend(enemy))
    return 1;

    // always check the underlying IsFriend-routine first and return 1
    //   if it is true or else you might end up with your monsters killing
    //   each other!

  if( (enemy->QueryRace()=="vampire") || (enemy->QueryGuild()==GC_VAMPIRE) )
    return 0;
  else
    return 1;

    // Valery is a friend of all livings except vampires, so this routine
    //   will only return 0 if the enemy is a vampire, making her
    //   aggressive against vampires only.
}

// Equipping your npc with garlic or a cross makes it less vulnerable
//   against a vampire's attack. If you intend to build an npc that
//   needs to be killed, especially for quest purposes, this isn't a
//   good idea though since it would almost make it impossible for a
//   vampire to succeed.

// Give vampires a chance, don't flood the world with garlic and
//   crosses!
