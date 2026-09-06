/* This is a standart teleport item.
** [?] creation
** [s] Update 1995
**
** [s] Softbyte
**
*/

#include <magic.h>
#include <properties.h>
#include <moving.h>
#include <secure/wizlevels.h>
#define TP this_player()
#define TO this_object()


public varargs int CheckTeleport(object player, int cost, int t_level) {
  object amulet;

// define undefined variables

  if (!t_level || !intp(t_level)) t_level=10;
  if (!intp(cost)) cost=30;
  if (!player) player=TP;
  if (!objectp(player)) {
    log_file("MAGIC",
      sprintf("Wrong player variable in: %O Set by: %O.\n",previous_object(),TO));
    CHANNEL_D->SendTell("error","STD_TELEPORT",
			   sprintf("[magic] %O: Wrong player Variable set by %O.",TO,previous_object()),1); 
    player=TP;
  }

// Make a wizcheck; return 1 if user is a wizard, else continue
//                  return TP_IS_WIZ if recipient is a wizard

  if (!IS_IMMORTAL(TP) || TP->Query(P_NOWIZ)) {
    if(IS_IMMORTAL(player) && !player->Query(P_NOWIZ)) {
      return TP_IS_WIZ;
    }

// Check the level of teleporter Level to low: TP_NO_LEVEL

    if(TP->QueryLevel()<t_level) {
      return TP_NO_LEVEL;
    }

// Do the teleport_amulet checking, but only if recipient!=user

  if(player != TP && player) {
    if(!amulet=present("tportamulet",player)) {
      return TP_NO_AMULET;
    }
    if(!amulet->QueryTeleport()) {
      return TP_AMULET_OFF;
    }
  }

// Combat checks

    if(player->QueryLevel()<18) {
      if (sizeof(player->Query(P_ENEMIES))) {
	if(TP==player) {
	  return TP_IS_FIGHTING;
	}
	else {
	  return TP_IS_FIGHTING;
	}
      }
    }
    if (cost && !TP->ReduceSP(cost)) {
      return TP_NO_SP;
    }
  }
  return TP_OK;
}  
    
void RestoreSP(int amount) { TP->SetSP(TP->QuerySP()+amount); }
     
     
varargs string QueryTeleportMessage(object player, int cost, int t_level) {

  if (!t_level || !intp(t_level)) t_level=10;
  if (!intp(cost)) cost=30;
  if (!player) player=TP;

  switch(CheckTeleport(player,cost,t_level)) {
  case TP_NO_SP:
    return("You don't have enough Spell Points left.\n\
It would cost "+cost+" SP.\n");
    break;
  case TP_NO_LEVEL:
    return("Teleportation is too complex for your current level.\n\
Try again later if you are more experienced.\n");
    break;
  case TP_IS_WIZ:
    tell_object(player,TP->QueryName()+" tried to teleport you.\n");
    return("Never target a wizard with a teleport!.\n");
    break;
  case TP_NO_AMULET:
    return(capitalize(player->QueryName())+" doesn't want to be teleported. "+capitalize(player->QueryPronoun())+" has\n\
no teleport amulet. Never try to teleport others who don't want\n\
to be teleported.\n");
    break;
  case TP_AMULET_OFF:
    return(capitalize(player->QueryName())+" doesn't want to be teleported. "+capitalize(player->QueryPossessive())+" amulet is switched off.\n");
    break;
  case TP_IS_FIGHTING:
    if(TP==player) {
      return("You are fighting at the moment.\n\
You are not allowed to teleport away in midst of a battle.\n");
    }
    else {
      return(player->QueryName()+" is fighting at the moment.\n\
So "+player->QueryPronoun()+" is not allowed to teleport away in midst of a battle.\n");
    }
    break;
  case TP_OK:
    return 0;
    break;
  default:
    return("You can not teleport at the moment.\n");
  }
  return("You can not teleport at the moment.\n");
}

     
varargs int QueryAllowedTeleport(object player, int cost, int t_level) 
{
string s;
  if (!t_level || !intp(t_level)) t_level=10;
  if (!intp(cost)) cost=30;
  if (!player) player=TP;

  s=QueryTeleportMessage(player,cost,t_level);  
  if (!s) return 1;
  notify_fail(s);
  return 0;
}

