/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: pegleg.c,v 1.1 1998/01/06 04:19:27 ceres Exp $
 * $Log: pegleg.c,v $
 * Revision 1.1  1998/01/06 04:19:27  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "mudlib.owned.weapon".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification mudlib.owned.weapon
 * @see help::effects
 */
#include "path.h"

#include <effect.h>

#define CLASS "object.pegleg"

/** @ignore yes */
string query_classification() { return CLASS; }

int query_indefinite() { return 1; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS "pegleg"; }

/** @ignore yes */
void beginning( object player, int amount, int id )
{
   player->add_extra_look( this_object() );
   tell_object(player, "You settle comfortably into the pegleg, and "
                       "immediately feel some of the piratic "
                       "mystique.\n");
} /* beginning() */

void restart( object player, int amount, int id )
{
/** @ignore yes */
  beginning(player, amount, id);
} /* restart() */

/** @ignore yes */
void merge_effect(object player, mixed oldarg, mixed newarg, int id)
{
  return;
}

/** @ignore yes */
void end( object player, int amount, int id )
{
   player->remove_extra_look( this_object() );
   tell_object(player, "Upon removing the pegleg, you feel as if "
                       "some fleeting and proud essence has "
                       "fled.\n");
} /* end() */

string extra_look( object player )
{
   int *enums;
   enums = (int *)player->effects_matching( CLASS );
   if ( !sizeof( enums ) )
      return "";
   return(capitalize((string )player->query_pronoun()) +
      " stands proudly on " + player->query_possessive() +
      " wooden pegleg.\n");
} /* extra_look() */
