/**
 * Deals out random gossip to people who request it.
 * <p>
 * Add rumours!
 * @author Pinkfish
 */

#include <gossip.h>

private class gossip_data *gossip, *rumours;

private nosave int call_id, next;

void create() {
    seteuid( master()->creator_file( file_name( TO ) ) );
    gossip = ({ });
    rumours = ({ });
    unguarded( (: restore_object(GOSSIP_SAVE_FILE) :) );
} /* create() */

private void save_me() {
    int i;

    call_id = 0;

    if( ( i = sizeof(gossip) ) > GOSSIP_KEEP_LEVEL )
        gossip = gossip[i-GOSSIP_KEEP_LEVEL..];

    if( ( i= sizeof(rumours) ) > RUMOUR_KEEP_LEVEL )
        rumours = rumours[i-RUMOUR_KEEP_LEVEL..];

    unguarded( (: save_object(GOSSIP_SAVE_FILE) :) );

} /* save_me() */

/**
 * This method returns whether or not we are accepting new gossip.
 * @return 1 if we are accepting new gossip, 0 if not
 */
int query_accept_gossip() {
    return sizeof(gossip) < GOSSIP_KEEP_LEVEL || next < time();
} /* query_accept_gossip() */

/**
 * This method adds a gossip string and is called by the gossip
 * effects on NPCs.
 * @see /std/shadows/npc/gossip.c
 * @param data the gossip data to add
 */
void add_gossip( class gossip_data data ) {
    if( !data->who || !data->what || !query_accept_gossip() )
        return;

    gossip += ({ data });

    next = time() + GOSSIP_FREQUENCY;

    save_me();

} /* add_gossip() */

/**
 * This method removes all gossips with the specified
 * gossip string from the gossip array.
 * @param match the string to remove
 */
void remove_gossip( string match ) {
    if( !match || match == "")
        return;

    gossip = filter( gossip, (: $1->what != $2 :), match );
    save_me();

} /* remove_gossip() */

/**
 * Rumours are another method of dealing out gossip.
 * Rumours are added by creators...
 * @param name the name of the person saying the rumour
 * @param mess the rumour message
 */
void add_rumour( string name, string mess ) {
    rumours += ({ new( class gossip_data, who : name, what : mess ) });
    save_me();
} /* add_rumour() */

/**
 * This method removes all rumours with the specified
 * rumour string from the rumour array.
 * @param match the string to remove
 */
void remove_rumour( string match ) {
    if( !match || match == "")
        return;

    rumours = filter( rumours, (: $1->what != $2 :), match );
    save_me();

} /* remove_rumour() */

/**
 * This method returns a random piece of gossip.
 * This is a class of two elements - the person
 * who said the gossip and what they said.
 * @return a class of gossip data
 */
class gossip_data query_random_gossip() {
    int i;

    if( ( i = sizeof(rumours) ) && random(2) )
        return rumours[random(i)];
    else if( i = sizeof(gossip) )
            return gossip[random(i)];
    else
            return 0;

} /* query_random_gossip() */

/**
 * This method returns the complete gossip array
 * which NPCs are drawing from.
 * @return an array of gossip classes
 * @see query_random_gossip()
 */
class gossip_data *query_gossip() { return gossip; }

/**
 * This method returns all of the current rumours.
 * @return an array of rumour classes
 * @see query_random_gossip()
 */
class gossip_data *query_rumours() { return rumours; }

/** @ignore yes */
mixed stats() {
    return ({
        ({"gossip", sizeof(gossip) }),
        ({"rumours", sizeof(rumours) }),
        ({"next", next }),
        ({"accepting gossip", query_accept_gossip() }),
    });
} /* stats() */
