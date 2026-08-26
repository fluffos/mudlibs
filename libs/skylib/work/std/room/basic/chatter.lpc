/**
 * The standard chatter inheritable for room chats.
 * @author Pinkfish
 * @changed Added day/night chat code - Sandoz, 2001.
 * @changed Added support for interactive chat parsing - Sandoz, 2002.
 * @changed Removed clean_up() so that our recycled chatters wouldn't
 * be cleaned up by the driver, because the garbage handler will get
 * unreferenced chatters anyway - Sandoz, 2nd Oct. 2002.
 * @see /std/room/basic_room.c
 * @see room_chat
 */

nosave int _off;
nosave object _room;
nosave mixed _chats, _night_chats;

/**
 * Allows the chat interval to be changed.
 * @param min minimum interval between chats (seconds)
 * @param max maximum interval between chats (seconds)
 */
void set_chat_min_max( int min, int  max ) {
    if( _chats ) {
        _chats[0] = min;
        _chats[1] = max;
    }
} /* set_chat_min_max() */

/**
 * Allows the night chat interval to be changed.
 * @param min minimum interval between chats (seconds)
 * @param max maximum interval between chats (seconds)
 */
void set_night_chat_min_max( int min, int  max ) {
    if( _night_chats ) {
        _night_chats[0] = min;
        _night_chats[1] = max;
    }
} /* set_chat_min_max() */

/**
 * Gives the chatter a room to chat at and the chat args.
 * @param my_room room object
 * @param chat_args chat data: ({ min, max, chats array })
 * @see room_chat
 * @see query_room_chats
 * @see /std/room/basic/chatter
 */
void setup_chatter( object my_room,  mixed chat_args ) {
    _off = 1;
    _room = my_room;
    _chats = chat_args + ({ 0 });
} /* setup_chatter() */

/**
 * Gives the chatter a room to chat at and the chat args
 * for the night chats.
 * @param my_room room object
 * @param chat_args chat data: ({ min, max, chats array })
 * @see room_chat
 * @see query_room_chats
 * @see /std/room/basic/chatter
 */
void setup_night_chatter( object my_room,  mixed chat_args ) {
    _off = 1;
    _room = my_room;
    _night_chats = chat_args + ({ 0 });
} /* setup_chatter() */

/** @ignore yes */
void dest_me() { destruct(TO); }

/** @ignore yes */
string expand_vis( string str, int visible ) {
    string pre, bright, dark, post;

    while( sscanf( str, "%s$%s|%s$%s", pre, bright, dark, post ) == 4 )
           str = pre + ( visible ? bright : dark ) + post;

    return replace_string( str, "%%", "$")+"\n";

} /* expand_vis() */

/** @ignore yes */
string expand_i( string str, object ob ) {
    string fname;

    fname = file_name(ob);

    return replace( str, ({
               "%Iposs", "$poss_short:"+fname+"$",
               "%Ip", ob->HIS,
               "%Io", ob->HIM,
               "%Ir", ob->HE,
               "%I", "$the_short:"+fname+"$",
               }) );

} /* expand_i() */

/** @ignore yes */
void print_chat( string chat, object *vis ) {
    object *dark, ob;
    string tmp;

    ob = choice(vis);
    vis -= ({ ob });

    tmp = expand_vis( chat, !ob->check_dark( _room->query_light() ) );
    tmp = replace( tmp, ({
        "%Iposs", "your",
        "%Ip", "your",
        "%Io", "you",
        "%Ir", "you",
        "%I", "you",
        }) );

    tell_object( ob, tmp );

    if( !sizeof(vis) )
        return;

    dark = filter( vis, (: $1->check_dark( _room->query_light() ) :) );
    vis -= dark;

    if( sizeof(vis) ) {
        tmp = expand_vis( chat, 1 );
        map( vis, (: tell_object( $1, $2 ) :), expand_i( tmp, ob ) );
    }

    if( sizeof(dark) ) {
        tmp = expand_vis( chat, 0 );
        map( dark, (: tell_object( $1, $2 ) :), expand_i( tmp, ob ) );
    }

} /* print_chat() */

/** @ignore yes */
void make_chat() {
    int saying;
    mixed stuff;
    object *obs;

    if( !sizeof( obs = filter( INV( _room ), (: interactive($1) :) ) ) ) {
        _off = 1;
        return;
    }

    if( !WEATHER_H->query_day() && _night_chats && sizeof(_night_chats[2]) ) {
        saying = random( sizeof( _night_chats[ 2 ] ) );
        if( saying == _night_chats[ 3 ] )
            saying = ( saying + 1 ) % sizeof( _night_chats[ 2 ] );
        _night_chats[ 3 ] = saying;
        stuff = _night_chats[ 2 ][ saying ];
        saying = _night_chats[ 0 ] + random( _night_chats[ 1 ] -
                 _night_chats[ 0 ] + 1 );
    } else if( !_chats || !sizeof(_chats[2]) ) {
        _off = 1;
        return;
    } else {
        saying = random( sizeof( _chats[ 2 ] ) );
        if( saying == _chats[ 3 ] )
            saying = ( saying + 1 ) % sizeof( _chats[ 2 ] );
        _chats[ 3 ] = saying;
        stuff = _chats[ 2 ][ saying ];
        saying = _chats[ 0 ] + random( _chats[ 1 ] - _chats[ 0 ] + 1 );
    }

    if( stringp(stuff) ) {
        if( stuff[ 0 ] == '#' )
            call_other( _room, stuff[1..] );
        else if( stuff[ 0 ] == '@' ) {
            print_chat( (string)call_other( _room, stuff[1..] ), obs );
        } else {
            print_chat( stuff, obs );
        }
    }

    if( functionp( stuff ) )
        print_chat( evaluate( stuff ), obs );

    if( intp( stuff ) )
        map( filter( INV( _room ), (: $1 && living( $1 ) && creatorp($1) :) ),
            (: tell_creator( $1, "Warning: room_chat array contains integer "
            "argument. Did you mix up the syntax with load_chat()'s?\n") :) );

    ROOM_H->add_chatter( TO, saying );

} /* make_chat() */

/**
 * Checks that the chatter is on and being activated
 * properly from the room_handler.
 * @see /std/room/basic/chatter
 * @see /handlers/room_handler
 */
void check_chat() {
    int delay;

    if( !_off || ( !pointerp( _chats ) && !pointerp( _night_chats ) ) )
        return;

    _off = 0;

    delay = ( ( !WEATHER_H->query_day() && _night_chats ) ?
            _night_chats[ 0 ] + random( _night_chats[ 1 ] -
            _night_chats[ 0 ] + 1 ) : ( !pointerp( _chats ) ? 0 :
            _chats[ 0 ] + random( _chats[ 1 ] - _chats[ 0 ] + 1 ) ) ) / 2;

    if( delay )
        ROOM_H->add_chatter( TO, delay );

} /* check_chat() */

/**
 * Adds more chats to the existing set of room chats
 * managed by this chatter object.
 * @param new_chats an array of new chat strings
 * @see remove_room_chats
 * @see query_room_chats
 * @see /std/room/basic/chatter
 */
void add_room_chats( string *new_chats ) {
    if( sizeof(new_chats) ) {
        if( sizeof(_chats[2]) )
            _chats[2] = _chats[2] + new_chats;
        else
            _chats[2]= new_chats;
    }
} /* add_room_chats() */

/**
 * Adds more chats to the existing set of room night chats
 * managed by this chatter object.
 * @param new_chats an array of new chat strings
 * @see remove_room_chats
 * @see query_room_chats
 * @see /std/room/basic/chatter
 */
void add_room_night_chats( string *new_chats ) {
    if( sizeof(new_chats) ) {
        if( _night_chats && sizeof(_night_chats[2]) )
            _night_chats[2] = _night_chats[2] + new_chats;
        else
            _night_chats[2]= new_chats;
    }
} /* add_room_night_chats() */

/**
 * Removes chats from the set of room chats
 * managed by this chatter object.  If there are no chats
 * left the chatter is recycled or destructed.
 * @param dead_chats an array of chat strings to remove
 * @see add_room_chats
 * @see query_room_chats
 * @see /std/room/basic/chatter
 */
void remove_room_chats( string *dead_chats ) {
    if( sizeof(_chats[2]) )
        _chats[2] = _chats[2] - dead_chats;
    if( !sizeof( _chats[2] ) && ( !_night_chats ||
        !sizeof( _night_chats[2] ) ) ) {
        if( _room )
            _room->stop_room_chats(); // Try recycling us.
        if( _room )
            dest_me();
    }
} /* remove_room_chats() */

/**
 * Removes chats from the set of room night chats
 * managed by this chatter object.  If there are no chats
 * left the chatter is destructed.
 * @param dead_chats an array of chat strings to remove
 * @see add_room_chats
 * @see query_room_chats
 * @see /std/room/basic/chatter
 */
void remove_room_night_chats( string *dead_chats ) {
   if( _night_chats && sizeof(_night_chats[2]) )
       _night_chats[2] = _night_chats[2] - dead_chats;
    if( !sizeof( _chats[2] ) && ( !_night_chats ||
        !sizeof( _night_chats[2] ) ) ) {
        if( _room )
            _room->stop_room_chats(); // Try recycling us.
        if( _room )
            dest_me();
    }
} /* remove_room_night_chats() */

/**
 * Returns the the set of room chats
 * managed by this chatter object.
 * @return pointer to the mixed array of chat args
 * @example
 *  ({ 120, 240, ({ "A frog gimbles the curtains.",
 *                  "A truly revolting smell drifts insidiously "
 *                  "from the rug." }) })
 * @see add_room_chats
 * @see remove_room_chats
 * @see room_chat
 * @see /std/room/basic/chatter
 */
mixed query_room_chats() { return _chats; }

/**
 * Returns the the set of room night chats
 * managed by this chatter object.
 * @return pointer to the mixed array of chat args
 * @see query_room_chats()
 * @see remove_room_chats
 * @see room_chat
 * @see /std/room/basic/chatter
 */
mixed query_room_night_chats() { return _night_chats; }

/** @ignore yes */
object query_my_room() { return _room; }
