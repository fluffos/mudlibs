/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: magic_scroll.c,v 1.2 1999/11/04 01:58:51 pinkfish Exp $
 * $Log: magic_scroll.c,v $
 * Revision 1.2  1999/11/04 01:58:51  pinkfish
 * Fix up the magic scroll effect to work with the new scroll inheritable.
 *
 * Revision 1.1  1998/01/06 04:19:27  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect to add a magic scroll element to a certain object.  It
 * has a classification of "magic.scroll".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification magic.scroll
 * @see help::effects
 */
#include "path.h"

/** @ignore yes */
string query_classification() { return "magic.scroll"; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS +"magic_scroll"; }

/** @ignore yes */
int query_indefinite() { return 1; }

/** @ignore yes */
int beginning( object thing, string spell, int id ) {
   thing->set_spell(spell);
   return 0;
} /* beginning() */

/** @ignore yes */
int restart( object thing, string spell, int id ) {
   thing->set_spell(spell);
   return 0;
} /* beginning() */
