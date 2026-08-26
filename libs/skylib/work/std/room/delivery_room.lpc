/**
 * This object provides a simple interface to the delivery inheritable.
 * It combines room and delivery functions.
 *
 * @author Taffyd
 */

inherit ROOM_OBJ;
inherit "/std/delivery";

/** @ignore yes */
void create() {
    delivery::create();
    basic_room::create();
} /* create() */

/** @ignore yes */
void dest_me() {
    delivery::dest_me();
    basic_room::dest_me();
} /* dest_me() */

mixed *stats() {
    return delivery::stats() + basic_room::stats();
} /* stats() */


/** @ignore yes */
int query_delivery_room() {
    return 1;
} /* query_delivery_room() */
