/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: alarm.c,v 1.1 1998/01/06 04:19:27 ceres Exp $
 * $Log: alarm.c,v $
 * Revision 1.1  1998/01/06 04:19:27  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "object.alarm".
 * <p>
 * Describe the arguments in here.
 * @classification object.alarm
 * @see help::effects
 */
#include <effect.h>

/** @ignore yes */
string query_classification() { return "object.alarm"; }

/** @ignore yes */
void beginning( object thing, mixed *args, int id ) {
   thing->submit_ee( "say_message", ({ 30, 90 }), EE_CONTINUOUS );
   thing->submit_ee( 0, args[ 1 ], EE_REMOVE );
} /* beginning() */

void say_message( object thing, mixed *args, int id ) {
   object place, carrier;
   place = environment( thing );
   if ( !place )
      return;
   while ( environment( place ) ) {
      carrier = place;
      place = environment( place );
   }
   if ( !carrier ) {
      tell_room( place, "A voice comes from "+ (string)thing->the_short() +
            ": "+ args[ 0 ] +"\n" );
      return;
   }
   if ( living( carrier ) && ( environment( thing ) == carrier ) ) {
      tell_room( place, "A voice comes from "+ (string)thing->poss_short() +
            ": "+ args[ 0 ] +"\n" );
      return;
   }
   tell_room( place, "A voice comes from somewhere near "+
         (string)carrier->the_short() +": "+ args[ 0 ] +"\n", carrier );
   tell_object( carrier, "A voice comes from somewhere nearby: "+
         args[ 0 ] +"\n" );
} /* say_message() */
