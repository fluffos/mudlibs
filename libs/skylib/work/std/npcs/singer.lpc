/**
 * He sings! Wheee!!!!
 * Shiannar, 25/09/01, inheritized by Sandoz, 25/09/01.
 * To use the inherit you need to have a mixed query_songs()
 * function in your NPC with the desired songs array.
 * To make the NPC automatically sing at times, you can use a
 * function pointer to request_song() in load_chat().
 * @example
 *
 * void setup() {
 *     ...
 *     <insert any setup functions>
 *     ...
 *     load_chat( 50, ({
 *         1, (: request_song() :), }) );
 * }
 *
 * mixed query_songs() {
 *     return ({ ({
 *            "'This is the first line of song 1.",
 *            "'This is the second line of song 1."
 *            }),
 *            ({
 *            "'This is the first line of song 2.",
 *            "'This is the second line of song 2."
 *            }) });
 * }
 */

#define DELAY 4

inherit NPC_OBJ;

nosave string *song;

void request_song();
private void modal_song();

/** @ignore yes */
void create() {
    song = ({ });
    ::create();
    add_respond_to_with(({"@say", "sing"}), ({ (: request_song :) }) );
} /* create() */

/**
 * This method should be overwritten in the actual NPC file to
 * contain the songs you want the NPC to sing.
 * @example
 * mixed query_songs() {
 *     return ({ ({
 *            "'This is the first line of song 1.",
 *            "'This is the second line of song 1."
 *            }),
 *            ({
 *            "'This is the first line of song 2.",
 *            "'This is the second line of song 2."
 *            }) });
 * }
 * @see query_singing(), query_current_song()
 */
mixed query_songs();

/**
 * This method queries if the NPC is currently singing or not.
 * @return the amount of lines of song left to sing
 * @see query_songs(), query_current_song()
 */
int query_singing() { return sizeof(song); }

/**
 * This method returns the song the NPC is currently singing.
 * @return the song we're currently singing
 * @see query_songs(), query_singing()
 */
string *query_current_song() { return song; }

/** @ignore yes */
string *query_song() {
    mixed *songs;
    if( !sizeof( songs = TO->query_songs() ) )
        return 0;
    if( stringp( songs[ 0 ] ) )
        return songs;
    return choice( songs );
} /* query_song() */

/** @ignore yes */
void request_song() {

    if( query_singing() )
        return;

    if( TO->is_fighting(TP) ) {
        init_command("'You got some nerve!");
        return;
    }

    if( TO->query_fighting() ) {
        init_command("'Can't you see I'm sort of busy?");
        return;
    }

    if( !sizeof( song = query_song() ) ) {
        init_command("'Odd, I can't seem to recall any songs, please "
            "talk to a creator about me.");
        return;
    }

    set_chats_off( 1 );
    if( TP && TP != TO )
        init_command("'Sure, I can sing you a song.");
    init_command(":clears "+TO->HIS+" throat.", DELAY );
    call_out( (: modal_song :), DELAY * 2 );

} /* request_song() */

/** @ignore yes */
private void modal_song() {
    string text;

    if( !sizeof(song) ) {
        set_chats_off( 0 );
        do_command(":becomes silent again.");
        return;
    }

    if( TO->query_fighting() ) {
        set_chats_off( 0 );
        song = ({ });
        do_command(":hurriedly stops singing.");
        return;
    }

    text = song[0];
    if( text[0..0] == "$" )
        init_command( ":sings: "+text[1..] );
    else if( text[0..0] == "*" )
        init_command(":recites: "+text[1..]);
    else
        init_command(text);

    song = song[1..];
    call_out( (: modal_song :), DELAY );

} /* modal_song() */

/** @ignore yes */
void do_move( string move ) {
    if( query_singing() )
        return;
    return ::do_move(move);
} /* do_move() */

/** @ignore yes */
mixed *stats() {
    return ::stats() + ({ ({ "singing", query_singing() }), });
} /* stats() */
