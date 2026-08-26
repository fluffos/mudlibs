/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: simple_cure.c,v 1.1 1998/01/06 04:13:03 ceres Exp $
 * $Log: simple_cure.c,v $
 * Revision 1.1  1998/01/06 04:13:03  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "fighting.warcry".
 * <p>
 * Describe the arguments in here.
 * @classification fighting.warcry
 * @see help::effects
 */
/* Basic file meant to be inherited by very simple cures.  -*- LPC -*-
 * If you change this file, remember to update
 * /doc/creator/files/std.effects.healing.simple_cure as well if I've made 
 * it yet:)
 * Olorin
 */
#include <effect.h>
#include <disease.h>
inherit BASIC_CURE;

/** @ignore yes */
int beginning( object player, int arg, int sid ) {
   if ( !player ) return 0;
   if ( !living( player ) ) return 0;
   player->submit_ee( 0, 0, EE_REMOVE );
   return arg;
} /* beginning() */

/** @ignore yes */
void end( object player, int arg, int sid ) {
   do_cure( player, arg );
} /* end() */

