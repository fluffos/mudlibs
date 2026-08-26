/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: alertness.c,v 1.1 1998/01/06 04:20:30 ceres Exp $
 * $Log: alertness.c,v $
 * Revision 1.1  1998/01/06 04:20:30  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "mind.alertness".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification mind.alertness
 * @see help::effects
 */
#include "path.h"
#include <effect.h>

/** @ignore yes */
string query_classification() { return "mind.alertness"; }

/** @ignore yes */
void beginning( object player, int duration, int id ) {
   tell_object( player, "You force yourself to be more alert and to "+
         "watch your surroundings more intently.\n" );
   player->submit_ee( 0, duration, EE_REMOVE );
} /* beginning() */

/** @ignore yes */
void end( object player, int duration, int id ) {
   tell_object( player, "Your concentration wanes and you stop "+
         "watching your surroundings as intently.\n" );
} /* end() */

/** @ignore yes */
string query_shadow_ob() { return SHADOWS +"alertness"; }
