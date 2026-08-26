/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: hooded_cloak.c,v 1.1 1998/01/06 04:06:32 ceres Exp $
 * $Log: hooded_cloak.c,v $
 * Revision 1.1  1998/01/06 04:06:32  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "mudlib.clothing.hooded-cloak".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification mudlib.clothing.hooded-cloak
 * @see help::effects
 */
#include "path.h"
#include <effect.h>

/** @ignore yes */
string query_classification() { return "mudlib.clothing.hooded-cloak"; }

int query_indefinite() { return 1; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS +"hooded_cloak"; }

/** @ignore yes */
int merge_effect( object player, int old_state, int new_state ) {
   return old_state | new_state;
} /* merge_effect() */
