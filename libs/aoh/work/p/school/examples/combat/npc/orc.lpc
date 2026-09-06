/*
** Bodo the orc
**
** An aggressive npc with customized equipment
**
** Author: Analena@Nightfall, 10feb97
** Update:
** Cloned by: /d/archwiz/common/defence/example/room/room2.c
*/

#include <rooms.h>
#include <properties.h>

inherit "/std/npc";

#define ARMOUR(x) "/p/school/examples/combat/armour/" x

void create()
{
  (::create());
  SetName("Bodo");
  SetRace("orc");
  SetLevel(7);
  SetStandard(QueryLevel());
  SetShort("Bodo the orc");
  SetLong("Bodo is an ordinary orc. He looks a bit dull.\n");
  SetGender(GENDER_MALE);
  SetSize(PSIZE_NORMAL);
  SetStr(8);
  SetInt(6);
    // since orcs tend to be stronger than the average human and less
    //   intelligent, we change his stats accordingly.

    // Note: Since an npc'x XP depend on its level which again is used to
    //       calculate its stats, the average of the stats should not be
    //       lower than the level set. Stats variation also should be
    //       representative of the npc's race. On the other hand, an Int
    //       of 15 doesn't even out a Str of 5 in a level 10 npc. If you
    //       want to drastically lower Str or Dex, lower the npc's level,
    //       too.

  SetAggressive(1);
    // setting an npc to aggressive makes it attack all players and pets it
    //   encounters. Wizards will only be attacked if their wizmode is
    //   turned off.

  SetAlign(-95);
    // orcs are nasty

  AddItem("/std/weapon",REFRESH_REMOVE,#'wieldme,
    ({
      ([
        P_STANDARD:         ({WT_CLUB,9,PSIZE_NORMAL})
      ]),
      ([
        P_SHORT:            "a wooden club",
        P_LONG:             "This is a long club made of wood.\n",
        P_ADS:              ({"long","wooden"}),
        P_NUMBER_HANDS:     2,
      // two hands are needed to wield this club. Since SetStandard does
      //   initialize all weapons with WC <= 12 to one hand, we need to
      //   set this afterwards.

        P_WP_PER_QP:        1
      // "WPperQP" is a property describing how fast the weapon's quality
      //   will decrease from use. The lower the number, the faster the
      //   weapon will deteriorate. Default is 10.

      ])
    }) );

  AddItem("/std/armour",REFRESH_REMOVE,#'wearme,
    ({
      ([
        P_STANDARD:         ({AT_BOOTS,1,PSIZE_NORMAL})
      ]),
      ([
        P_SHORT:            "some rusty boots",
        P_LONG:             "This pair of metal boots is rather rusty.\n",
        P_ADS:              ({"metal","rusty"}),
        P_RESET_QUALITY:    67
      // the "ResetQuality" also sets the current quality of the armour to
      //   67 which again influences the armour's protection and value. As
      //   long as the armour remains in its creating object (in this case
      //   that is Bodo the orc), its quality will be reset to this reset
      //   quality every time a reset is called. Some smithies also can
      //   repair weapons and armour no better than their reset quality.

      ])
    }) );

  AddItem(ARMOUR("chainMail"),REFRESH_REMOVE,#'wearme);
    // Bodo is wearing a chain mail that offers better protection against
    //   bludgeoning and slashing weapons than against piercing attacks.

}
