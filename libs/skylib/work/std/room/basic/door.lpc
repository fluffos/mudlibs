/**
 * Basic door object used by rooms. Typically there is no need to use any of
 * the methods in this object since they are accessible through modify_exit.
 * @author pinkfish
 */
#include <door.h>
#include <parse_command.h>

#define BEVERB        ({" is ", " are "})
#define PRONOUN       ({"it", "them"})

#define CLOSED        2
#define CLOSED_LOCKED 3

inherit "/std/basic/enchant";
inherit "/std/basic/hide_invis";
inherit "/std/basic/property";
inherit "/std/basic/close_lock";
inherit "/std/basic/trap";
inherit "/std/basic/id_match";

private int how_many;
private int one_way;
private string shrt;
private string lng;
private string my_id;
private string other_id;
private string *name;
private string *adjs;
private string *plu;
private string dest;
private object key;
private object my_room;

void create() {
   hide_invis::create();
   property::create();
   close_lock::create();

   name = ({"door"});
   lng = "It's just a door.\n";
   shrt = "door";
   adjs = ({ });
   plu = ({ });

   add_property("determinate", "the ");
   set_unlocked();

} /* create() */

/** @ignore yes */
int group_object() { return how_many > 0; }

/** @ignore yes */
int query_how_many() { return how_many; }

/** @ignore yes */
void set_how_many( int number ) { how_many = number; }

/** @ignore yes */
int query_one_way() { return one_way; }

/** @ignore yes */
void set_one_way( int number ) { one_way = number; }

/** @ignore yes */
string query_short() {  return shrt; }

/** @ignore yes */
void set_short( string words ) {
   string *bits;

   shrt = words;
   bits = explode( words, " " );

   if( member_array( bits[<1], name ) == -1 )
       name += ({ bits[<1] });

   adjs += bits[0..<2];
   plu += ({ pluralize( bits[<1] ) });

} /* set_short() */

/** @ignore yes */
string query_long() { return lng; }

/** @ignore yes */
void set_long( string word ) {lng = word;}

/** @ignore yes */
string query_my_id() { return my_id; }

/** @ignore yes */
void set_my_id( string word ) { my_id = word; }

/** @ignore yes */
string query_other_id() { return other_id; }

/** @ignore yes */
void set_other_id( string word ) { other_id = word; }

/** @ignore yes */
string *query_name() { return name; }

/** @ignore yes */
string *query_adjs() { return adjs; }

/** @ignore yes */
string *query_plu() { return plu; }

/**
 * This method returns the destination room of this door.
 * @return the destination room of the door
 */
string query_dest() { return dest; }

/**
 * This method sets the destination room of the door.
 * @param word the filename of the destination room
 */
void set_dest( string word ) { dest = word; }

/**
 * This method returns the room this door belongs to.
 * @return the room we belong to
 */
object query_my_room() { return my_room; }

/** @ignore yes */
void init() {
    add_command("knock", "on <direct:object>");
    close_lock::init();
} /* init() */

/** @ignore yes */
string query_determinate() { return "the "; }
/** @ignore yes */
string short() { return query_short(); }
/** @ignore yes */
string a_short() { return "$a_short:"+ file_name( TO ) +"$"; }
/** @ignore yes */
string one_short() { return "$one_short:"+ file_name( TO ) +"$"; }
/** @ignore yes */
string poss_short() { return "$poss_short:"+ file_name( TO ) +"$"; }
/** @ignore yes */
string the_short() { return "$the_short:"+ file_name( TO ) +"$"; }
/** @ignore yes */
string pretty_short() { return query_short(); }
/** @ignore yes */
string query_plural() { return pluralize( query_short() ); }
/** @ignore yes */
string pretty_plural() { return pluralize( query_short() ); }

/** @ignore yes */
string long() {
    return lng + ( TP->query_see_octarine() ? enchant_string() :
                   "" ) + long_status();
} /* long() */

/** @ignore yes */
int drop() { return 1; }

/** @ignore yes */
int get() { return 1; }

/** @ignore yes */
void setup_door( string word, object mine, string his, mixed *args,
                 string type ) {
    string *bits;

    my_id = word;
    my_room = mine;
    dest = his;

    switch( type ) {
      case "window":
        if( word != "window")
            shrt = word + " window";
        else
            shrt = word;

        lng = "It's just the " + shrt + ".\n";
        name = ({ shrt, "window"});
        plu = ({"windows"});
      break;
      default:
        if( word[0..5] == "enter ") {
            shrt = word[6..]+" door";
            lng = "It's just the " + shrt + ".\n";
            name += ({ shrt });
            if( !args[D_SECRET ] )
                plu = ({"doors"});
        } else {
            shrt = word +" door";
            lng = "It's just the " + shrt + ".\n";
            name += ({ shrt });
            if( !args[D_SECRET ] )
                plu = ({"doors"});
        }
    }

    bits = explode( word, " ");
    name += ({ bits[<1] });
    adjs +=  bits;
    plu += ({ pluralize( bits[<1] ) });

    args[ D_CLOSED ] ? set_open() : set_closed();
    args[ D_LOCKED ] ? set_locked() : set_unlocked();

    set_key(args[ D_KEY ] );
    set_difficulty(args[ D_DIFFICULTY ] );
    if( args[ D_SECRET ] )
        add_hide_invis( "secret", 0, 200, 0 );

    if( sizeof(args) >= D_TRANSPARENT && args[D_TRANSPARENT] )
        set_transparent();

} /* setup_door() */

/** @ignore yes */
void add_alias( string word ) {
    string *bits;

    bits = explode( word, " ");

    if( member_array( bits[<1], name ) == -1 )
        name += ({ bits[<1] });

    adjs +=  bits[0..<2];
    plu += ({ pluralize( bits[<1] ) });

} /* add_alias() */

/** @ignore yes */
int force_other() {
    if( !other_id ) {
        ROOM_H->check_door( ({ my_room, my_id,  dest }) );
        if( !other_id )
            return 0;
    }

    if( find_object( dest ) )
        dest->query_door( my_room );

    return 1;

} /* force_other() */

/** @ignore yes */
int do_open() {
    if( !::do_open() )
        return 0;

    if( !force_other() && !one_way ) {
        set_closed();
        return 0;
    }

    if( objectp( query_property("lockpicked") ) )
        query_property("lockpicked")->event_door_open( TO, TP );

    // If the door is now open, it's outdoors and this is not a move
    // (i.e. the room handler is not involved), the wind could blow it shut.
    if( my_room->query_property("location") == "outside" &&
        member_array( find_object(ROOM_H), previous_object(-1) ) == -1 )
        ROOM_H->add_door( TO );

    if( !one_way && find_object(dest) ) {
        dest->modify_exit( other_id, ({"closed", 0 }) );
        dest->tell_door( other_id, TP->a_short()+" opens the $D.\n", 0 );
    }

    return 1;

} /* do_open() */

/** @ignore yes */
int do_close() {
    if( !::do_close() )
        return 0;

    if( !force_other() && !one_way ) {
        set_open();
        return 0;
    }

    if( !one_way && find_object(dest) ) {
        if( query_autolock() ) {
            dest->modify_exit( other_id, ({"closed", 1, "locked", 1 }) );
            dest->tell_door( other_id, "Someone closes the $D which lock$s "
                "as $p close$s.\n", 0 );
        } else {
            dest->modify_exit( other_id, ({"closed", 1 }) );
            dest->tell_door( other_id, "Someone closes the $D.\n", 0 );
        }
    }

    return 1;

} /* do_close() */

/** @ignore yes */
int do_lock( object *obs ) {
    if( !::do_lock(obs) )
        return 0;

    if( !force_other() && !one_way ) {
        set_unlocked();
        return 0;
    }

    if( !one_way && find_object(dest) ) {
        dest->modify_exit( other_id, ({"locked", 1 }));
        dest->tell_door( other_id, "Someone locks the $D.\n", 0 );
    }

    return 1;

} /* do_lock() */

/** @ignore yes */
int do_unlock( object *obs ) {
    if( !::do_unlock(obs) )
        return 0;

    if( !force_other() && !one_way ) {
        set_locked();
        return 0;
    }

    if( !one_way && find_object(dest) ) {
        dest->modify_exit( other_id, ({"locked", 0 }));
        dest->tell_door( other_id, "Someone unlocks the $D.\n", 0 );
    }

    return 1;

} /* do_unlock() */

/** @ignore yes */
int do_knock() {
    if( !other_id && !one_way ) {
        ROOM_H->check_door( ({ my_room, my_id }) );
        if( !other_id )
            return 0;
    }

    if( one_way )
        return 1;

    dest->tell_door( other_id, "Someone knocks on the $D.\n", 0 );
    event( find_object(dest), "door_knock", TP, other_id );

    return 1;

} /* do_knock() */

int pick_unlock( object thing ) {
    if( !::pick_unlock(thing) )
        return 0;

    if( !force_other() && !one_way ) {
        set_locked();
        return 0;
    }

    if( !one_way && find_object(dest) ) {
        dest->modify_exit( other_id, ({"locked", 0 }) );
        dest->tell_door( other_id, "Someone unlocks the $D.\n", 0 );
    }

    return 1;

} /* pick_unlock() */

int pick_lock( object thing ) {
    if( !::pick_lock(thing) )
        return 0;

    if( !force_other() && !one_way ) {
        set_unlocked();
        return 0;
    }

    if( !one_way && find_object(dest) ) {
        dest->modify_exit( other_id, ({"locked", 1 }) );
        dest->tell_door( other_id, "Someone locks the $D.\n", 0 );
    }

    return 1;

} /* pick_lock() */

/** @ignore yes */
string *parse_command_id_list() {
    return ( TP ? name + ({ TP->find_rel(my_id) }) : name );
} /* parse_command_id_list() */

/** @ignore yes */
string *parse_command_adjectiv_id_list() { return adjs; }

/** @ignore yes */
string *parse_command_plural_id_list() { return plu; }

/** @ignore yes */
object query_parse_id( mixed *arr ) {
   if( arr[P_THING] == 0 )
       return TO;

   // specific object case.
   if( arr[P_THING] < 0 ) {
       if( ++arr[P_THING] != 0 )
           return 0;
       arr[P_THING] = -10321;
       return TO;
   }

   // lots of objects case.
   if( --arr[P_THING] != 0 )
       return TO;

   arr[P_THING] = -10101;

   return TO;

} /* query_parse_id() */

/** @ignore yes */
mixed parse_match_object( string* input, object viewer,
                          class obj_match_context context ) {
   if( input[<1] == "all")
       return 0;

   return ::parse_match_object( input, viewer, context );

} /* parse_match_object() */

/** @ignore yes */
void dest_me() { destruct(TO); }

/** @ignore yes */
void dwep() { destruct( TO ); }

/**
 * This method is used by the room object ("undoor" option in modify_exit(),
 * more specifically) to get rid of doors.
 * We will first attempt to recycle the door, and if that fails,
 * we destruct it.
 * @param flag used internally
 */
varargs void go_away( int flag ) {
    if( !flag ) {
        call_out( (: go_away :), 0, 1 );
    } else {
        if( !ROOM_H->recycle_door(TO) )
            dest_me();
    }
} /* go_away() */

/** @ignore yes */
int move() { return 1; }

int moving_open( object thing ) {
    object tp = TP;

    set_this_player(thing);

    if( !::do_open() ) {
        set_this_player(tp);
        return 0;
    }

    if( !force_other() && !one_way ) {
        set_closed();
        return 0;
    }

    thing->remove_hide_invis("sneaking");

    if( !one_way && find_object(dest) ) {
        dest->modify_exit( other_id, ({ "closed", 0 }));
        dest->tell_door( other_id, thing->a_short()+" opens the $D.\n", 0 );
    }

    tell_object( thing, "You open the "+shrt+".\n" );
    tell_room( my_room, thing->the_short()+" opens the "+shrt+".\n", thing );

    return 1;

} /* moving_open() */

int moving_close( object thing ) {
    object tp = TP;

    set_this_player(thing);

    if( !::do_close() ) {
        set_this_player(tp);
        return 0;
    }

    if( !force_other() && !one_way ) {
        set_open();
        return 0;
    }

    if( !one_way && find_object(dest) ) {
        if( query_autolock() ) {
            dest->modify_exit( other_id, ({"closed", 1, "locked", 1 }) );
            dest->tell_door( other_id, thing->the_short()+" close$s the $D "
                "which lock$s as $p close$s.\n", thing );
        } else {
            dest->modify_exit( other_id, ({ "closed", 1 }) );
            if( thing->short() )
                dest->tell_door( other_id, thing->the_short()+" close$s "
                    "the $D.\n", thing );
        }
    }

    if( query_autolock() ) {
        tell_object( thing, "You close the "+dest->call_door( other_id,
            "query_short")+" which locks as it closes.\n");
        tell_room( my_room, thing->the_short()+" closes the "+shrt+" which "
            "locks as it closes.\n", thing );
    } else {
        tell_object( thing, "You close the "+dest->call_door( other_id,
            "query_short")+".\n");
        tell_room( my_room, thing->the_short()+" closes the "+shrt+".\n",
            thing );
    }

    return 1;

} /* moving_close() */

int moving_unlock( object thing ) {
    object tp = TP;

    set_this_player(thing);

    if( !::do_unlock( INV(thing) ) ) {
        set_this_player(tp);
        return 0;
    }

    if( !one_way && find_object(dest) )
        dest->modify_exit( other_id, ({"locked", 0 }) ) ;

    tell_object( thing, "You unlock the "+shrt+".\n");

    if( thing->short() )
        tell_room( my_room, thing->the_short()+" unlocks the "+
            shrt+".\n", thing );

    return 1;

} /* moving_unlock() */

int moving_lock( object thing ) {
    object tp = TP;

    set_this_player(thing);

    if( !::do_lock( INV(thing) ) ) {
        set_this_player(tp);
        return 0;
    }

    if( !one_way && find_object(dest) )
        dest->modify_exit( other_id, ({"locked", 1 }));

    tell_object( thing, "You lock the "+dest->call_door(
        other_id, "query_short")+".\n");

    if( thing->short() )
        dest->tell_door( other_id, thing->the_short()+" locks the $D.\n",
            thing );

    return 1;

} /* moving_lock() */

void tell_door( string words, object thing ) {
    tell_room( my_room, replace( words, ({ "$D", shrt, "$p",
        PRONOUN[how_many], "$s", ({"s", ""})[how_many] })), ({ thing }) );
} /* tell_door() */

/** @ignore yes */
mixed stats() {
    return property::stats() + close_lock::stats() + ({
        ({"how many", how_many }),
        ({"one way", one_way }),
        ({"my id", my_id }),
        ({"other id", other_id }),
        ({"destination", dest }),
        ({"key object", key }),
        ({"my room", my_room }),
    });
} /* stats() */

// Mask long status from close_lock to accurated describe double doors.
string long_status() {
    string str;

    // If it is stuck in one state don't bother telling us the state.
    if( !query_stuck() ) {
        str = ( query_how_many() > 0 ? "They are" : "It is");
        switch( query_closed_locked_status() ) {
          case CLOSED_LOCKED :
            return str + " closed and locked.\n";
          case CLOSED :
            return str + " closed.\n";
          default :
            return str + " open.\nThrough "+the_short()+" you can see:\n"+
                dest->long( 0, ( TP ? TP->check_dark( dest->query_light() ) :
                0 ) );
        }
    } else {
        return "";
    }

} /* long_status() */
