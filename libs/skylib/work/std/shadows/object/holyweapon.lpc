/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: holyweapon.c,v 1.1 1998/01/06 04:40:23 ceres Exp $
 * $Log: holyweapon.c,v $
 * Revision 1.1  1998/01/06 04:40:23  ceres
 * Initial revision
 * 
*/
inherit "/std/effect_shadow";
#include <tune.h>

int modify_damage( int damage, string attack_name ) { 
   int him_align, me_align;
   object him, me;
   
   if ( attack_name != "holyweapon" )
     return damage; 
   
   me = environment( player );
   him = me->query_target();

   me_align = me->query_al();
   him_align = him->query_al();

   if ( me_align * him_align > 0 )
     return 0;

   if ( me_align < 0 )
     me_align = -me_align;

   event( environment( player ), "inform", (string)me->query_name() +
         " has "+ attack_name + " scaled by " + 
         ( ( 100 * me_align ) / MAX_AL ) +
         "%" , "combat" );

   return ( damage * me_align ) / MAX_AL ;

}
