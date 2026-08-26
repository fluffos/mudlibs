/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: brokenfingers.c,v 1.1 1998/01/06 04:36:02 ceres Exp $
 * $Log: brokenfingers.c,v $
 * Revision 1.1  1998/01/06 04:36:02  ceres
 * Initial revision
 * 
*/
inherit "/std/effect_shadow";

string *query_limbs() {
   return ({ "right hand" });
} /* query_limbs() */

int query_free_limbs() {
   return sizeof( query_limbs() ) - sizeof( player->query_holding() - ({ 0 }) );
} /* query_free_limbs() */
