/**
 * This is the effect skelton docs.  This effect
 * has a classification of "disease.hypothermia".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification disease.hypothermia
 * @see help::effects
 */

#include <effect.h>
#include <disease.h>

inherit BASIC_DISEASE;

int cure_rate, infection_chance;
string shadow_ob;
function infection_check;

void set_cure_rate( int i ) { cure_rate = i; }
int query_cure_rate() { return cure_rate; }

void set_infection_chance( int i ) { infection_chance = i; }
int query_infection_chance() { return infection_chance; }

void set_infection_check( function f ) { infection_check = f; }

void set_shadow_ob( string str ) { shadow_ob = str; }

/** @ignore yes */
string query_shadow_ob() { return shadow_ob; }

void create() {
    do_setup++;
    ::create();
    do_setup--;
    shadow_ob = 0;
    infection_chance = 0;
    infection_check = 0;
    cure_rate = 0;
    if( !do_setup )
        TO->setup();
} /* create() */

/** @ignore yes */
int beginning( object person, int arg, int id ) {
    if( !arg = TO->disease_start( person, arg, id ) ) {
        person->submit_ee( 0, 0, EE_REMOVE );
        return 0;
    }

    person->submit_ee( "disease_tick", ( arg > 60 ) ? 60 : arg, EE_ONCE );
    return arg;

} /* beginning() */

/** @ignore yes */
int merge_effect( object person, int old_arg, int new_arg, int id ) {
    // When reinfected, get the worse of the two.
    if( old_arg < new_arg ) {
        old_arg = new_arg;
        TO->disease_worse( person, old_arg, id );
    }
    
    return old_arg;

} /* merge_effect() */

/** @ignore yes */
void end( object person, int arg, int id ) {
    TO->disease_end( person, arg, id );
} /* end() */

void disease_tick( object person, int arg, int id ) {
    object *things;
    int i;

    // This can be removed later.
    if( arg > 100000 )
        arg = 10000;
   
    arg -= ( cure_rate*( person->query_con() + 7 ) ) / 20 ;
    person->set_arg_of( person->sid_to_enum( id ), arg );
   
    if( arg < 0 ) {
        person->submit_ee( 0, 0, EE_REMOVE );
        return;
    }

    if( person && ENV(person) && file_name( ENV(person) ) != "/room/void" &&
        file_name( ENV(person) ) != "/room/rubbish" && infection_chance > 0 &&
        ( random(100) < infection_chance ) ) {
        if( functionp( infection_check ) ) {
            things = filter( INV(ENV(person)), infection_check );
        } else {
            // Something can catch diseases if it's alive, and is a non-unique NPC, or
            // is a player and is not dead.
            things = filter( INV(ENV(person)), (: living($1) &&
                ( ( !userp($1) && !$1->query_property("unique") ) ||
                     userp($1) ) && !$1->query_property("dead") :) );
        }

        if( i = sizeof( things -= ({ person }) ) ) {
            i = random( i );
            things[ i ]->add_effect( file_name(TO), arg );
#ifdef DEBUG
            log_file( "INFECTION", "%s, %s infected with %s by %s\n",
                ctime(time()), things[ i ]->query_name(),
                TO->query_name(), person->query_name() );
#endif
        }
    }
    
    person->submit_ee("disease_tick", ( arg > 60 ) ? 60 : arg, EE_ONCE );
    // If it has no heart beat, don't waste processor time in case
    // disease_action would have caused it to take damage and start
    // the heatbeat.
    if( !query_heart_beat( person ) )
        return;
    
    TO->disease_action( person, arg, id );

} /* disease_tick() */

int test_remove( object, int, int, int ) {
#ifdef DEBUG
    log_file("OLD_CURE", file_name(PO)+" "+file_name(TO)+"\n");
#endif
} /* test_remove() */
