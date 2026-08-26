/**
 * This is the outside terrain room inherit.
 * It is to be used for outdoors rooms.
 * @author Sandoz, 2002
 */

inherit OUTSIDE_OBJ;
inherit ROOM_DIR "/basic/terrain";

/** @ignore yes */
void dest_me() {
    terrain::dest_me();
    outside::dest_me();
} /* dest_me() */

/** @ignore yes */
void event_exit( object thing, string message, object to ) {
    outside::event_exit( thing, message, to );
    terrain::event_exit( thing, message, to );
} /* event_exit() */

/** @ignore yes */
mixed stats() { return outside::stats() + terrain::stats(); }
