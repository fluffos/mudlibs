/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: fish_effect.c,v 1.1 1998/01/06 04:20:30 ceres Exp $
 * $Log: fish_effect.c,v $
 * Revision 1.1  1998/01/06 04:20:30  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "potion.alteration.female".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification potion.alteration.female
 * @see help::effects
 */
/*
 * This is the fish effect.  It makes you able to breath underwater
 * but not out of the water.
 */
inherit "/std/effects/basic";

#include "effect.h"
#include "path.h"

/** @ignore yes */
string query_shadow_ob() {
  return SHADOWS +"fish_effect";
} /* query_shadow_ob() */

void create() {
  set_boundaries( ({ -40, -20 }), ({ 0, 20 }) );
}  /* create() */

int query_heart_beat_frequency() { return 1; }

mixed effect_heart_beat(object them, int hb_no, mixed arg, int id) {
/* Its a straight forward counter... */
  if (pointerp(arg))
    return arg;
  if (arg-- <= 0) {
    tell_object(them, "Your gills subside.\n");
    tell_room(environment(them), them->one_short()+"'s gills subside.\n",
              ({ them }));
    return REMOVE_THIS_EFFECT;
  }
  return arg;
} /* mixed_effect_heart_beat() */

/** @ignore yes */
mixed beginning(object them, mixed arg, int id) {
  if (!pointerp(arg)) {
    tell_object(them, "Gills grow out of the side of your face.  You think "+
                      "you will need to find some water very quickly.\n");
    tell_room(environment(them), "Gills seem to grow out of the side of "+
                                 them->one_short()+"'s face.\n",
              ({ them }));
  }
  return arg;
} /* beginning() */

/** @ignore yes */
mixed merge_effect(object them, mixed arg1, mixed arg2) {
  if (pointerp(arg1) || pointerp(arg2))
    return ({ });
  return arg1+arg2;
} /* merge_effect() */

/* This is the potion handling stuff from here down. */

mixed *query_attrs( int *coord ) {
  int total, intens;

  total = distance_within_region( coord );
  intens = total*3;
  if (intens > 100) intens = 100;
  return ({ 5, 95, ({ }), ({ ({ "sea green", intens }) }), ({ }),
         ({ ({ "slightly salty", intens }), }) });
} /* query_attrs() */

void action_drunk( object ob, int *coord, int quantity ) {
  int total, str;

  total = distance_within_region( coord );
  str = total*quantity;
  str = str/1000;
  this_player()->add_effect(file_name(this_object()), str);
  return ;
} /* action_drunk() */

mixed *query_coordinate() { return ({ -30, 10 }); }
