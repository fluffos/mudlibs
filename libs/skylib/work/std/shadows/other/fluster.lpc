/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: fluster.c,v 1.1 1998/01/06 04:42:56 ceres Exp $
 * $Log: fluster.c,v $
 * Revision 1.1  1998/01/06 04:42:56  ceres
 * Initial revision
 * 
*/
#define REDUCTION 20

inherit "/std/effect_shadow";

varargs int query_skill_bonus( string word, int true ) {
   int bonus;
   bonus = (int)player->query_skill_bonus( word, true );
   if ( true )
      return bonus;
   return ( ( 100 - REDUCTION ) * bonus ) / 100;
} /* query_skill_bonus() */
