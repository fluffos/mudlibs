/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: boomerang_return.c,v 1.1 1998/09/26 10:17:13 terano Exp $
 *
 *
 */

/**
 * This is the effect skeleton docs.  This effect
 * has a classification of "body.arm.boomerang".
 * <p>
 * Describe the arguments in here.
 * <p>
 * @classification body.arm.boomerang
 * @see help::effects
 */
#include <effect.h>

int delay;
string msg = "";

/** @ignore yes */
string query_classification() { return "body.arm.boomerang"; }

/** @ignore yes */
void beginning( object player, int duration ) {
   delay = 0;
   player->submit_ee( "return_check", duration, EE_CONTINUOUS );
} /* beginning() */

/** @ignore yes*/
void return_check( object player, int duration ) {
   if( environment( player )->query_property( "location" ) != "outside" ) {
     switch( delay ) {
       case 0 :
         msg = "You get a slight feeling you have forgotten something.\n";
         break;
       case 1 :
         msg = "A sixth sense tells you that you left something behind.\n";
         break;
       case 2 :
         msg = "You remember that you threw your boomerang while outside.\n";
         break;
       case 3 :
         msg = "You guess that if you don't get outside very soon, you'll "
           "lose your boomerang forever.\n";
         break;
       default : player->submit_ee( 0, 0, EE_REMOVE );
         return;
         break;
     }
     ++delay;
     tell_object( player, msg );
     return;
   }
   player->submit_ee( 0, 0, EE_REMOVE );
} /* return_check() */

/** @ignore yes */
void end( object player ) {
   object boomerang;
   if( environment( player )->query_property( "location" ) != "outside" ) {
     tell_object( player, "You get a nasty feeling that your boomerang is "
       "not coming back.\n" );
     return;
   }
   boomerang = clone_object( "/d/am/items/boomerang" );
   boomerang->boomerang_returned( player );
} /* end() */
