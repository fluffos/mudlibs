/*  Effect added to make food dried and preserved :-)
 *  @author Wenda :-)
 *  @classification object.dried
 *
 *  @args to this efect: none
 *  @duration: indefinite
 */

#include <effect.h>

/** @ignore yes */
string query_classification() { return "object.dried"; }

/** @ignore yes */
mapping beginning( object thing ) {

  if( thing->query_edible()==1 ) {   // Doesn't work if not food.

    // These next two properties are there to record the object's
    // original short() and decay_speed, so that if the property
    // has to be taken off the object for whatever reason, it can
    // be restored to its original state.
    thing->add_property( "former decay_speed", 
                        thing->query_decay_speed() );
    thing->add_property( "former short", thing->query_short() );
    // Make it not decay
    thing->set_decay_speed( 0 );
    // add an extra_look and 'dried' adjective for flavour text
    thing->add_extra_look( this_object() );
    thing->set_short( "dried " + thing->query_short() );
    thing->add_adjective( "dried" );
    // As was so prudently pointed out to me, a dried object should weigh
    // less than its moist counterpart.  This will make the weight of
     // any dried object equal to 1, recording its former weight to be
     // restored if the effect is removed.
    thing->add_property( "former weight", thing->query_weight() );
    thing->set_weight( 1 );
  }

} /*beginning()*/

mapping restart( object thing ) {

    // extra_look must be added at restart() as it isn't saved
    // over logins.  Everything else is though :-)

    thing->add_extra_look( this_object() );  

} /*restart()*/

/** @ignore yes */
void merge_effect() {}

int query_indefinite() { return 1; }  // Doesn't run out

/** @ignore yes */
void end( object thing ) {
    
    // Set decay_speed and short() back to normal, and get rid of
    // the properties
    // Also set weight back to normal.
    thing->set_decay_speed( thing->query_property( "former "
                           "decay_speed" ) );
    thing->set_short( thing->query_property( "former short" ) );
    thing->set_weight( thing->query_property( "former weight" ) );
    thing->remove_property( "former decay_speed" );
    thing->remove_property( "former short" );
    thing->remove_property( "former weight" );
    // Remove adjective and extra_look
    thing->remove_adjective( "dried" );
    thing->remove_extra_look( this_object() );
}

string extra_look() {

  return "It is all dry and shrivelled up.\n";

} /*extra_look()*/
