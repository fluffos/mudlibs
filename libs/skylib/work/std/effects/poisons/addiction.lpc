/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: addiction.c,v 1.1 1998/01/06 04:21:18 ceres Exp $
 * $Log: addiction.c,v $
 * Revision 1.1  1998/01/06 04:21:18  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "poison.addictive".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification poison.addictive
 * @see help::effects
 */
#include <effect.h>
#include "path.h"

/* Simple addiction effect - it acts as a poison with increasingly drastic
   effects as time goes by. It would be used in conjunction with an object 
   (food etc.) which would add the effect if it is not present, or just reset
   it if it is. - Piecemaker June 93
*/

int query_secs_between_hb() { return 100; }

/* We don't allow addiction to run for longer than 15 heart beats. */
int begining(object player, mixed arg){
   if (arg > 15) arg = 15;
   return arg;
}

/** @ignore yes */
void end(object player){
   tell_object(player, "You are no longer addicted.\n");
}

/** @ignore yes */
string query_classification() { return "poison.addictive"; }

void reset_hb(){
//   eff_save[EFF_HBNUM] = 0;
}

int effect_heart_beat(object player, int hbnum, mixed arg, int id){
   string prompt;

/* The effects of not getting your fix are cumilative. */
   
   tell_object(player, "You need a fix.\n");

   prompt = "none";

   if (hbnum > 0){
      player->adjust_hp(-10);
   }
   if (hbnum > 1){
      player->adjust_hp(-20);
   }
   if (hbnum > 2){
      player->adjust_hp(-40);
      prompt = "You feel queasy.";
   }
   if (hbnum > 3){
      player->adjust_hp(-60);
      prompt = "You feel quite ill.";
   }
   if (hbnum > 4){
      player->adjust_hp(-100);
      prompt = "You're getting a killer headache.";
   }
   if (hbnum > 5){
      player->adjust_hp(-150);
      prompt = "You feel very ill.";
   }
   if (hbnum > 6){
      player->adjust_tmp_dex(-1);
      prompt = "You're having problems coordinating your arms and legs.";
   }
   if (hbnum > 7){
      player->adjust_tmp_str(-1);
   }
   if (hbnum > 8){
      player->adjust_tmp_con(-1);
      prompt = "You feel weak.";
   }
   if (hbnum > 9){
      player->adjust_tmp_dex(-1);
   }
   if (hbnum > 10){
      player->adjust_int(-1);
   }
   if (hbnum > 11){
      player->adjust_con(-1);
      prompt = "You want to be sick.";
   }
   if (hbnum > 12){
      player->adjust_dex(-1);
   }
   if (hbnum > 13){
      player->adjust_str(-1);
      prompt = "You feel very weak.";
   }
   if (hbnum > 14){
      player->second_life();
   }

   if (prompt != "none") tell_object(player, prompt+"\n");

/* The effect has completed it's duration - the player has gone 'cold turkey' */
   if (hbnum == arg) return REMOVE_THIS_EFFECT;
   return arg;
}

/** @ignore yes */
string query_shadow_ob() { return SHADOWS+"addiction_shadow"; }
