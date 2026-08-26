/**
 * Contains some simul_efuns.
 * @author Pinkfish
 */

#include <player.h>

/**
 * This method checks to see if both of the objects are able to do a
 * pk action on each other.  This will return 1 if they cannot
 * complete the action, ie: either of them are not player killers.
 * It will take an object or a string as the first parameter and attempt
 * to check for pkness, if the off_line flag is set it will even check for
 * players that are not even logged on.
 * <p>
 * If an object is passed into this method, it is first checked with the
 * method query_owner_pk_check(), if this returns a non-zero value it is
 * used as the person who owns the object.  This allows objects to be
 * pk checked when they are not players.
 * @param thing1 first object to check
 * @param thing2 second object to check
 * @param off_line allow the check to occur if they are not logged on
 * @return 1 if they cannot attack each other
 */
int pk_check( mixed thing1, mixed thing2, int off_line ) {
    int pk1, pk2;
    object ob;

    // Check to see if this some sort of object that has a pk owner.
    if( objectp(thing1) && !interactive(thing1) &&
        thing1->query_owner_pk_check() ) {
        thing1 = thing1->query_owner_pk_check();
    }

    // Get the pk value for thing1.
    if( !objectp(thing1) ) {
        ob = TO->find_player(thing1);
        if( ob )
            thing1 = ob;
    }

    if( objectp(thing1) && userp(thing1) )
        pk1 = thing1->query_property(PKER) && interactive(thing1);
    else if( stringp(thing1) && off_line && PLAYER_H->test_user(thing1) )
        pk1 = PLAYER_H->test_property( thing1, PKER );
    else
        return 0;

    // Check to see if this some sort of object that has a pk owner.
    if( objectp(thing2) && !interactive(thing2) &&
        thing2->query_owner_pk_check() )
        thing2 = thing2->query_owner_pk_check();

    // Get the pk values for thing2.
    if( !objectp(thing2) ) {
        ob = TO->find_player(thing2);
        if( ob )
            thing2 = ob;
    }

    if( objectp(thing2) && userp(thing2) )
        pk2 = thing2->query_property(PKER) && interactive(thing2);
    else if( stringp(thing2) && off_line && PLAYER_H->test_user(thing2) )
        pk2 = PLAYER_H->test_property( thing2, PKER );
    else
        return 0;

   if( objectp(thing1) && objectp(thing2) ) {
       if( thing1->query_creator() && !thing2->query_creator() )
           return 1;
       if( thing2->query_creator() && !thing1->query_creator() )
           return 1;
    }

    // Do the actual checks.
    return !pk1 || !pk2;

} /* pk_check() */

int silenced( object ob ) {
    if( !objectp(ob) )
        return 0;

    return ob->query_silenced();

} /* silenced() */

int channel_silenced( object ob ) {
    if( !objectp(ob) )
        return 0;

    if( silenced(ob) )
        return 1;

    return ob->query_channel_silenced();

} /* channel_silenced() */
