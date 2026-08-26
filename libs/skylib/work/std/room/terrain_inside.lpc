/**
 * This is the inside terrain room inherit.
 * This is to be used for indoors rooms.
 * @author Sandoz, 2002
 */

inherit ROOM_OBJ;
inherit ROOM_DIR "/basic/terrain";

/** @ignore yes */
void dest_me() {
    terrain::dest_me();
    basic_room::dest_me();
} /* dest_me() */

/** @ignore yes */
void event_exit( object thing, string message, object to ) {
    basic_room::event_exit( thing, message, to );
    terrain::event_exit( thing, message, to );
} /* event_exit() */

/** @ignore yes */
mixed stats() { return basic_room::stats() + terrain::stats(); }
