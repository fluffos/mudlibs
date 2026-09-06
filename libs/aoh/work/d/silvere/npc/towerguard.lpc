/* This is a guard for the harbour tower (north or south)
 * Each time you clone him, he will have a different name, for easier
 * identification.
 *
 * created:   Sonic [26-Jul-1997]
 *            Sonic [28-Jul-1997] far from finished. added some equipment
 * changed:   Taurec[22-May-1998] changed Choose_name()
 */

#include <silvere.h>
#include <properties.h>
#include <combat.h>
#include <macros.h>
#include <npc.h>

#define NR_NAMES 10

inherit "/std/npc";

string ChooseName(){
  string *names,name;
  names=({ "lendere","balanwer","otursan","silvio","kylan",
           "zehrone","jedalin","herdyl","anwerdan",
           "palladyne"});
  do {
    name=random_select(names);
    names-=({name});
  } while (find_living(name)&&(sizeof(names)));
  return CAP(name);
}

void create()
{
   seteuid(getuid());
   ::create();
   Set(P_LEVEL,15);
   Set(P_GENDER,GENDER_MALE);
   Set(P_IDS, ({"guard","towerguard","tower guard","tguard"}) );
   Set(P_RACE,"human");
   Set(P_NAME, ChooseName());

   Set(P_SHORT,CAP(NAME(TO))+", a tower guard");
   Set(P_LONG,
      "This guard is assigned to the tower to make sure, that only the "
      "allowed people may enter that tower.\n");
   Set(P_GO_CHANCE,0);

   AddItem(W_SWORDS("sil_tgsword1"), REFRESH_REMOVE, SF(wieldme));
   AddItem(A_MAILS("sil_tgarmour1"), REFRESH_REMOVE, SF(wearme));

   ChooseName();
}
