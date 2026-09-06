/* This is a guard for the harbour tower (north or south)
 * Each time you clone him, he will have a different name, for easier
 * identification.
 * 
 * created:   Sonic [26-Jul-1997]
 * changed:   Sonic [28-Jul-1997] far from finished. added some equipment
 *            Sonic [23-Nov-1997] moved equipment to /obj
 */

#include <silvere.h>
#include <properties.h>
#include <combat.h>
#include <macros.h>
#include <npc.h>
inherit "/std/npc";

string ChooseName()
{
   /* nothing yet. I have to collect some names first. */
   // TODO: check for names and put a list together
   return "Toni";
}

void create()
{
   seteuid(getuid());
   ::create();
   Set(P_LEVEL,15);
   Set(P_GENDER,GENDER_MALE);
   Set(P_IDS, ({"guard","tower guard","towerguard","lieutnant","tguard"}) );
   Set(P_RACE,"human");
   Set(P_NAME,ChooseName());
   
   Set(P_SHORT,"a towerguard Lieutnant");
   Set(P_LONG,
      "This guard is assigned to the tower to make sure, that only the "
      "allowed people may enter that tower. His rank is lieutnant and "
      "he is commanding a group of 4 soldiers.\n");
   Set(P_GO_CHANCE,0);

   AddItem(W_SWORDS("sil_tgsword2"), REFRESH_REMOVE, SF(wieldme));
   AddItem(A_MAILS("sil_tgarmour2"), REFRESH_REMOVE, SF(wearme));
}
