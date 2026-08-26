/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: fish_effect.c,v 1.1 1999/02/08 10:05:33 terano Exp $
 * $Log: fish_effect.c,v $
 * Revision 1.1  1999/02/08 10:05:33  terano
 * Initial revision
 *
 * Revision 1.1  1998/01/06 04:20:30  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "potion.alteration.female".
 * <p>
 * Describe the arguments in here.
 * @classification potion.alteration.female
 * @see help::effects
 */
inherit "/std/effect_shadow";

int div_factor;

int move(object ob, string s1, string s2) {
  if (!ob || ob->query_underwater()) {
    remove_call_out("do_underwater_damage");
    return (int)player->move(ob, s1, s2);
  }
/* Oh dear.  this is bad for them... */
  call_out("do_underwater_damage", 10);
} /* move() */

void do_underwater_damage() {
  call_out("do_underwater_damage", 10);
  if (!div_factor) {
/* Average is 2 minutes. */
    div_factor = 15+((int)player->query_con()-13)/5+random(6);
    if (div_factor <= 0)
      div_factor = 1;
  }
  tell_object(player, "You are gasping and panting, you can't breath "+
                      "out of the water.\n");
  player->adjust_hp(-((int)player->query_max_hp())/div_factor);
} /* do_underwater_damage() */

int query_water_breathing() { return 1; }
