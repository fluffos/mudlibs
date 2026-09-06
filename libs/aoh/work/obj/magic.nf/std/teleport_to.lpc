/* This is the high security teleport _TO_ a player standart item */
/* It may be used only under very, very seldom circumstances.     */
/* Please always talk to the magic department before create a     */
/* teleport to item/room!                                         */

inherit "/std/thing";
#include "/obj/magic/standard.h"

create() {
  (::create());
  SetShort("an useles item (std teleport item)");
}

varargs QueryAllowedTeleportTo(object player, int cost, int t_level) {

// define undefined variables

  if (!t_level || t_level<10) t_level=10;
  if (!player) player=TP;

// Make a wizcheck; return 1 if user is a wizard, else continue
//                  return 0 if recipient is a wizard

  if (!IS_IMMORTAL(TP) || TP->Query(P_NOWIZ)) {
    if(IS_IMMORTAL(player) && !player->Query(P_NOWIZ)) {
      notify_fail("Never target a wizard with a teleport!.\n");
      tell_object(player,TP->QueryName()+" tried to teleport to you.\n");
      return 0;
    }

// Check the level of teleporter

    if(TP->QueryRealLevel()<t_level) {
      notify_fail("Teleportation is too complex for your current level.\n\
Try again later if you are more experienced.\n");
      return 0;
    }

// Combat checks

    if(TP->QueryRealLevel()<18) {
      if (TP->Query(P_ENEMIES) != ({}) ) {
	  notify_fail("You are fighting at the moment.\n\
You are not allowed to teleport away in midst of a battle.\n");
	  return 0;
	}
    }
    if(!TP->ReduceSP(cost)) {
      notify_fail("You don't have enough Spell Points left.\n\
It would cost "+cost+" SP.\n");
      return 0;
    }
  }
    return 1;
}

RestoreSP(int amount) { TP->SetSP(TP->QuerySP()+amount); }
     
     
     
