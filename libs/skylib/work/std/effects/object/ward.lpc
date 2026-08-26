/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: ward.c,v 1.3 1998/12/15 06:34:06 mansarde Exp $
 * $Log: ward.c,v $
 * Revision 1.3  1998/12/15 06:34:06  mansarde
 * Fixed a couple of bugs in merge_effect:
 *  1) Tells players if the new ward is stronger.
 *  2) Keeps the old ward, if it's stronger than the new one. (but
 *     updates the other args)
 *
 * Revision 1.2  1998/01/11 17:03:41  pinkfish
 * fixed_up_the_extra_look_stuff,_tomake_them_ignored.
 *
 * Revision 1.1  1998/01/06 04:19:27  ceres
 * Initial revision
 * 
*/
/**
 * This effect protects an object by causing damage to anyone (except the 
 * warder) if they try to steal it.  It has a classification of 
 * "ritual.object.warded".
 * <p>
 * Args are: ({ duration, damage, warder's name })   Note that the first 
 * argument is no longer used, and wards don't disappear after a time.
 * <p>
 * This effect has a shadow associated with it.
 * @classification ritual.object.warded
 * @see help::effects
 */
#include <effect.h>

/* args are ({ duration, damage, caster_name }) */

/** @ignore yes */
string query_classification() { return "ritual.object.warded"; }
/** @ignore yes */
string query_shadow_ob() { return "/std/shadows/object/ward"; }
string query_name() { return "priests ward"; }
int query_indefinite() { return 1; }

/** @ignore yes */
mixed beginning( object thing, mixed args, int id ) {

//   thing->submit_ee( 0, args[ 0 ], EE_REMOVE );
   thing->add_extra_look( this_object() );
   tell_object( find_player( args[ 2 ] ),
               (string)thing->the_short() + " is warded.\n" );
   return args;
} /* beginning() */

/* simply use new args */
/** @ignore yes */
mixed merge_effect( object thing, mixed old_args, mixed new_args, int id ) {

  switch (new_args[1] > old_args[1]) {
    case 1: 
      tell_object(find_player( new_args[2] ),
                  "The ward on " + (string)thing->the_short() + " has been strengthened.\n");
      return new_args;
    default:    
      tell_object(  find_player( new_args[ 2 ] ),
                  (string)thing->the_short() + " is still warded.\n" );
  }
  // Since the old ward was stronger, keep that, but update the rest of the args.
  return ({ new_args[0], old_args[1], new_args[2] });
} /* merge_effect() */

void restart( object thing, mixed args, int id ) {
   thing->add_extra_look( this_object() );
} /* restart() */

/** @ignore yes */
void end( object thing, mixed args, int id ) {
   thing->remove_extra_look( this_object() );
} /* end() */

/** @ignore yes */
string extra_look( object thing ) {
   return "It is warded.\n";
} /* extra_look() */

