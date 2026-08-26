/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: given.c,v 1.3 1998/10/09 10:16:16 terano Exp $
 * $Log: given.c,v $
 * Revision 1.3  1998/10/09 10:16:16  terano
 * Changes for ranma
 *
 * Revision 1.1  1998/01/06 04:39:52  ceres
 * Initial revision
 * 
*/
inherit "/std/effect_shadow";

void event_enter(object ob, string mess, object from) {
   mixed *bit;
   int ret;

   /* Check to see if it is us the object is entering... */
   if (environment(ob) == player) {
      bit = arg();
      if (functionp(bit)) {
         ret = evaluate(bit, player, ob, mess, from);
      } else if (pointerp(bit)) {
         ret = call_other(bit[0], bit[1], player, ob, mess, from);
      }
   }
   player->event_enter(ob, mess, from);
} /* event_enter() */
