/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: place_ring.c,v 1.1 1998/01/06 04:19:27 ceres Exp $
 * $Log: place_ring.c,v $
 * Revision 1.1  1998/01/06 04:19:27  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "object.weddingring".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification object.weddingring
 * @see help::effects
 */
#include "path.h"
#include <library.h>

/** @ignore yes */
string query_classification() { return "object.weddingring"; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS +"place_ring"; }

int query_indefinite() { return 1; }

/*
 * The start arg should be the player being targeted...
 */
/** @ignore yes */
mixed beginning( object thing, object args, int id ) {
  args->add_command("place", thing, "<direct:object> on <indirect:living>");
} /* beginning() */

void restart( object thing, mixed *args, int id ) {
} /* restart() */

/** @ignore yes */
void end( object thing, mixed *args, int id ) {
} /* end() */
