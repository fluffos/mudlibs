/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: store_ritual.c,v 1.2 1998/01/11 17:03:41 pinkfish Exp $
 * $Log: store_ritual.c,v $
 * Revision 1.2  1998/01/11 17:03:41  pinkfish
 * fixed_up_the_extra_look_stuff,_tomake_them_ignored.
 *
 * Revision 1.1  1998/01/06 04:19:27  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "faith.store_ritual".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification faith.store_ritual
 * @see help::effects
 */
#include "path.h"

/** @ignore yes */
string query_classification() { return "faith.store_ritual"; }
/** @ignore yes */
string query_shadow_ob() { return SHADOWS +"store_ritual"; }

int query_indefinite() { return 1; }

/* args are ({ "ritual name", "ritual object", bonus }) */
/** @ignore yes */
mixed *beginning( object thing, mixed *args, int id ) {
   if ( environment( thing ) )
      tell_object( environment( thing ), "A pale shimmering aura surrounds "+
            (string)thing->the_short() +".\n" );
   if ( thing->query_do_use_save() )
     thing->remove_do_use_save();
   thing->add_extra_look( this_object() );
   return args;
} /* beginning() */

void restart( object thing, mixed *args, int id ) {
   thing->add_extra_look( this_object() );
} /* restart() */

/** @ignore yes */
void end( object thing, mixed *args, int id ) {
   object shadow;
   if ( environment( thing ) )
      tell_object( environment( thing ), "The aura surrounding "+
            (string)thing->the_short() +" fades away.\n" );
   thing->remove_extra_look( this_object() );
   shadow = clone_object( SHADOWS + "after_store" );
   shadow->setup_shadow( thing );
} /* end() */

/** @ignore yes */
string extra_look( object thing ) {
   int *enums;

   enums = (int *)thing->effects_matching( "faith.store_ritual" );
   if ( !sizeof( enums ) )
      return "";
   return "The shimmering aura around this "+ thing->short() 
     +" tells you it can be used to cast the ritual "+
     thing->query_ritual_name() +".\n";
} /* extra_look() */
