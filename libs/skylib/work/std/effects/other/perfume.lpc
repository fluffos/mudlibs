/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: perfume.c,v 1.1 1998/01/06 04:20:30 ceres Exp $
 * $Log: perfume.c,v $
 * Revision 1.1  1998/01/06 04:20:30  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "body.smell.perfume".
 * <p>
 * Describe the arguments in here.
 * @classification body.smell.perfume
 * @see help::effects
 */
#include <effect.h>

/** @ignore yes */
void beginning( object player, mixed *args, int id ) {
   player->submit_ee( "emit_scent", ({ 30, 30 }), EE_CONTINUOUS );
   player->submit_ee( 0, args[ 0 ], EE_REMOVE );
} /* beginning() */

/** @ignore yes */
void end( object player, mixed *args, int id ) {
   if ( !pointerp( args ) )
      return;
   if ( sizeof( args ) < 2 )
      return;
   if ( !stringp( args[ 1 ] ) )
      return;
   tell_object( player, "The scent of "+ pluralize( args[ 1 ] ) +
         " fades away.\n" );
} /* end() */
 
void emit_scent( object player, mixed *args, int id ) {
   tell_object( player, "The scent of "+ pluralize( args[ 1 ] ) +
         " pleasantly surrounds you.\n" );
   player->remove_hide_invis( "hiding" );
   tell_room( environment( player ),  "The pleasant scent of "+
         pluralize( args[ 1 ] ) +" surrounds "+
         (string)player->the_short() +".\n", player );
} /* emit_scent() */

/** @ignore yes */
string query_classification() { return "body.smell.perfume"; }

string smell_string( object player, mixed *args ) {
   return "the pleasant scent of "+ pluralize( args[ 1 ] );
} /* smell_string() */
