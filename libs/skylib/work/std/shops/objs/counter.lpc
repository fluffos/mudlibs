/**
 * Pub counter for the pub_shop.c inheritable.  It will automatically clear
 * away any empty items on it that have the property "pub item" on them every
 * 10 seconds.
 * @author Lemming
 * @started 28/10/1999
 * @changed Changed to clear things more smartly, so that we wouldn't end up
 * with counters bursting with half-full glasses - Sandoz, 20 April, 2003.
 */

inherit "/std/surface";

private object my_pub;

private void clear_pub_item( object item );

/** @ignore */
void create() {
    ::create();
    set_name("counter");
    set_short("counter");

    set_long("The counter seems to be where you should leave glasses and "
        "plates to be cleared away.\n");

    reset_get();

    // So that we could send an event to the pub room,
    // or let the pub room itself clean the counter.
    if( function_exists("clear_pub_item", PO ) ||
        function_exists("event_clear_pub_item", PO ) )
        my_pub = PO;

} /* create() */

/** @ignore */
private void clear_pub_item( object item ) {
    if( ENV(item) != TO )
        return;

    if( my_pub ) {
        if( my_pub->clear_pub_item(item) )
            return;
        my_pub->event_clear_pub_item(item);
    }

    item->move("/room/rubbish");

} /* clear_item() */

/** @ignore */
void event_enter( object ob, string mess, object from ) {
    if( ob->query_property("pub item") || ob->query_liquid() )
        call_out( (: clear_pub_item :), 10, ob );
} /* event_enter() */

/** @ignore yes */
object query_my_pub() { return my_pub; }
