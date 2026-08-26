/**
 * This is the indoors dance floor inherit,
 * here we can dance to our hearts content.
 * @author Sandoz 12th October 2001.
 */

inherit OUTSIDE_OBJ;
inherit ROOM_DIR "/inherit/dance_floor";

/** @ignore yes */
void create() {
    outside::create();
    dance_floor::create();
} /* create() */

/** @ignore yes */
void init() {
    outside::init();
    dance_floor::init();
} /* init() */

/** @ignore yes */
void event_exit( object ob, string mess, object to ) {
    outside::event_exit( ob, mess, to );
    dance_floor::event_exit( ob, mess, to );
} /* event_exit() */

mixed *query_default_position( object ob ) {
    return dance_floor::query_default_position( ob );
} /* query_default_position() */

int is_allowed_position( string pos ) {
    return dance_floor::is_allowed_position( pos );
} /* is_allowed_position() */
