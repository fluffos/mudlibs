/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: glowing.c,v 1.2 1998/01/11 17:03:41 pinkfish Exp $
 * $Log: glowing.c,v $
 * Revision 1.2  1998/01/11 17:03:41  pinkfish
 * fixed_up_the_extra_look_stuff,_tomake_them_ignored.
 *
 * Revision 1.1  1998/01/06 04:19:27  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "object.glowing".
 * <p>
 * Describe the arguments in here.
 * @classification object.glowing
 * @see help::effects
 */
#include <effect.h>

/* args are ({ light_level, duration, colour }) */
void give_message( object thing, string mess );

/** @ignore yes */
string query_classification() { return "object.glowing"; }

/** @ignore yes */
mixed beginning( object thing, mixed args, int id ) {
   thing->submit_ee( 0, args[ 1 ], EE_REMOVE );
   thing->add_extra_look( this_object() );
   thing->adjust_light( args[ 0 ] );
   give_message( thing, " begins to glow.\n" );
   return args;
} /* beginning() */

/* simply use new args */
/** @ignore yes */
mixed merge_effect( object thing, mixed old_args, mixed new_args, int id ) {
   thing->adjust_light( new_args[ 0 ] - old_args[ 0 ] );
   return new_args;
} /* merge_effect() */

/** @ignore yes */
void end( object thing, mixed args, int id ) {
   thing->remove_extra_look( this_object() );
   thing->adjust_light( -args[ 0 ] );
   give_message( thing, " stops glowing.\n" );
} /* end() */

void restart( object thing, mixed args, int id ) {
   thing->add_extra_look( this_object() );
} /* restart() */

/** @ignore yes */
string extra_look( object thing ) {
   int *enums;
   string glow, colour;
   mixed args;
   
   enums = (int *)thing->effects_matching( "object.glowing" );
   if ( !sizeof( enums ) )
      return "";

   args = thing->arg_of( enums[ 0 ] );
   colour = args[ 2 ];
   
   switch ( args[ 0 ] ) {
      case 0 :
         return "";
      case 1 .. 5 :
         glow = "glowing dimly";
         break;
      case 6 .. 10 :
         glow = "glowing dimly "+ colour;
         break;
      case 11 .. 30 :
         glow = "glowing "+ colour;
         break;
      case 31 .. 80 :
         glow = "glowing brilliantly "+ colour;
         break;
      default :
          glow = "glowing with a blinding "+ colour +" light";
   }
   return "It is "+ glow +".\n";
} /* extra_look() */

void give_message( object thing, string mess ) {
   object place, carrier;

   place = environment( thing );
   if ( !place )
      return;
   while ( environment( place ) ) {
      carrier = place;
      place = environment( place );
   }
   if ( !carrier ) {
      tell_room( place, (string)thing->the_short() + mess );
      return;
   }
   if ( living( carrier ) && ( environment( thing ) == carrier ) ) {
      tell_room( place, (string)thing->poss_short() + mess );
      return;
   }
   return;
} /* say_message() */
