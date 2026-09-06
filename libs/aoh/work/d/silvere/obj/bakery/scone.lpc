// Food for the bakery in Silvere
// P_SPECIAL_NAME is for the bakery, when they become daily specials
//
// created:          Tune    [24-Apr-1999]

#include <secure/config.h>    // RACEMASTER
#include <properties.h>

#define P_SPECIAL_NAME   "special_of_the_day"

string do_my_nobuy();

inherit "/std/food";

void create()
{
  ::create();
  SetShort("a raisin scone");
  SetLong("A round, crumbly raisin scone, lightly spiced with cinnamon.\n");

  Set(P_SPECIAL_NAME, "Raisin Scones");

  SetFood();
  SetFoodStuff(11);
  SetFoodHeal(7);

  Set(P_NOBUY, #'do_my_nobuy /*'*/);

  AddId( ({ "scone" }) );
  AddAdjective( ({ "raisin", "round", "crumbly", "cinnamon" }) );

  SetWeight(30);
  SetValue(0);

  SetSmell("Smells a little floury, and a bit like cinnamon.\n");

  SetFoodMsgs( ({
    "You nibble at the scone, as large chunks crumble off, making a bit "
      "of a mess.\n",
    "@@Pl_Name@@ consumes a crumbly cinnamon and raisin scone, making a "
      "bit of a mess, dropping crumbs all over the place.\n",
    "Someone eats something nearby.\n"
   }) );
}

// mostly just an example of calling a closure from P_NOBUY

string do_my_nobuy()
{
   return "Hmm, why do " +
           ({string})RACEMASTER->RacePlural( ({string})this_player()->QueryRace() ) +
          " always want to sell me day-old scones? I most certainly "
          "am not interested in your half-eaten food!\n";
}
