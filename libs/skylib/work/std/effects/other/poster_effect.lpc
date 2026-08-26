/**
 * This effect places a poster in the room for a time.
 * The poster will add an item to the room, which contains a
 * description and a read message.
 * <p>
 * The argument is an array of four elements.  These are time for
 * poster to remain in room, the short desc., the long desc., and
 * the message displayed when poster is read.
 * <p>
 * @classification other.poster
 * @see help::effects
 */
#include <effect.h>

/**
 * @ignore yes
 */
string query_classification() { return "other.poster"; }

/**
 * @ignore yes
 */
void beginning( object room, mixed *info, int ) {
   room->submit_ee( "vanish_mess", info[0], EE_REMOVE );
   room->add_extra_look( this_object() );
   room->add_item( info[1], ({ "long", info[2], "read", info[3] }) );
   room->add_property( "DBM poster present", 1 );
} /* beginning() */

/**
 * @ignore yes
 */
void vanish_mess( object room, mixed *info ) {
   string mess;
   room->submit_ee( 0, 0, EE_REMOVE );
   if( room->query_property( "location" ) == "outside" ) {
     switch( random( 3 ) ) {
       case 0 :
         mess = "The " + info[1] + " peels off and flutters away in a sudden "
           "breeze.\n";
         break;
       case 1 :
         mess = "A beggar tears the " + info[1] + " down and wanders away "
           "with it, muttering about firestarters.\n";
         break;
       default :
         mess = "A rat manages to rip the " + info[1] + " down and scamper "
           "off with it.\n";
         break;
     }
     tell_room( room, mess );
   }
} /* vanish_mess() */

/**
 * @ignore yes
 */
void merge_effect() { return; }

/**
 * @ignore yes
 */
void end( object room, mixed *info ) {
   room->remove_extra_look( this_object() );
   room->remove_item( info[1] );
   room->remove_property( "DBM poster present" );
} /* end() */

/**
 * @ignore yes
 */
string extra_look() {
   return "A colourful poster has been pasted here.\n";
} /* extra_look() */
