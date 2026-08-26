/**
 * The standard room inheritable.  This contains all the stuff needed to
 * construct a standard room.
 * @author Pinkfish
 * @see /std/room/outside.c
 * @changed Added set_determinate() function - Shaydz - 04/03/2001
 * @changed Added room_smells and room_sounds - Shaydz 3/04/2001 12:32PM
 * @changed Fixed autodoc issues - Shiannar - 12/03/01
 * @changed Fixed stuff concerning day/night long descs - Sandoz - 25/10/01
 * @changed Changed the way day/night items work - Sandoz - 29/10/01
 * @changed Added recycling for chatters, doors and items - Sandoz - 09/09/02
 * @changed Changed the smells/sounds to use properties instead of six
 * rarely used variables - Sandoz, 20/09/02
 * @changed Changed to inherit the effects inheritable, instead of
 * using a shadow for effects. - Sandoz, 11/04/03
 */

#include <dirs.h>
#include <door.h>
#include <room.h>
#include <nroff.h>
#include <climate.h>
#include <position.h>
#include <situations.h>

#define DOOR door_control[direc]

#define DAY   1
#define NIGHT 0

// 3 heartbeats currently.
#define FAST_CLEAN_UP 3

inherit "/std/basic/cute_look";
inherit "/std/basic/desc";
inherit "/std/basic/effects";
inherit "/std/basic/extra_look";
inherit "/std/basic/light";
inherit "/std/basic/property";
inherit "/std/basic/export_inventory";
inherit "/std/basic/help_files";

nosave int do_setup, last_updated;

// Enchantment stuff.
nosave int enchant_time;
nosave int background_enchant;
nosave float dynamic_enchant;

// Exit stuff.
nosave int *co_ord, co_ord_calculated;
nosave mixed dest_other;
nosave string *exits;
nosave string long_exit, short_exit;
nosave mapping door_control;
nosave string smell;

// Other stuff.
nosave string theft_handler;
nosave object item, chatter, sitchanger, linker, wall;
nosave object *hidden_objects, *signs;
nosave mixed night_long;
private nosave int last_visited;

#ifdef FAST_CLEAN_UP
private nosave int room_create_time;
private nosave int fast_clean_up;
private nosave int room_stabilize;
#endif

int query_fast_clean_up();
void set_fast_clean_up( int i );
void heart_beat();

void set_room_size(mixed);
void set_day_long(string);
void set_night_long(string);
mixed query_night_long();

#ifdef FAST_CLEAN_UP
private void init_fast_clean_up() {
    if( room_stabilize != 1 && query_fast_clean_up() ) {
        room_stabilize = -FAST_CLEAN_UP;
        set_heart_beat( 1 );
    }
} /* init_fast_clean_up() */
#endif

/** @ignore yes */
protected void create() {
    string fname;

    desc::create();
    property::create();
    export_inventory::create();
    light::create();

#ifdef FAST_CLEAN_UP
    // Don't clean up inherits.
    if( function_exists("setup", TO ) && !TO->query_keep_room_loaded() )
        set_fast_clean_up(1);
#endif

    exits = ({ });
    door_control = ([ ]);
    dest_other = ({ });

    set_can_export_inventory();
    hidden_objects = ({ });

    fname = file_name(TO);

    seteuid( (string)master()->creator_file( fname ) );

    set_room_size(25);
    add_property("location", "inside");
    add_property("here", "on the floor");
    add_property("determinate", "");

    if( !do_setup ) {
        TO->setup();
        TO->reset();
    }

    catch( MAP_H->check_map( fname ) );

    if( WEATHER_H->query_day() ) {
        call_out("changing_to_day", 0, 1 );
        last_updated = DAY;
    } else {
        call_out("changing_to_night", 0, 1 );
        last_updated = NIGHT;
    }

#ifdef FAST_CLEAN_UP
    if( query_fast_clean_up() ) {
        room_create_time = time();
        init_fast_clean_up();
    }
#endif

} /* create() */

/** @ignore yes */
varargs mixed add_clone(string file, int num, string zone, int *move_after, int time){
    //This function will be removed once we get rid of all add_clones.
    call_out((:tell_room:),1,TO,"%^BOLD%^RED%^This room needs it's add_clone removed.\n%^RESET%^");
}

/** @ignore yes */
void add_effect( string eff, mixed arg ) {
    if( !pointerp(query_effs() ) )
        effects::create();
    effects::add_effect( eff, arg );
} /* add_effect() */

/** @ignore yes */
void set_smell(string str){
    smell = str;
} /* set_smell() */

string query_smell(){
    return smell;
} /* query_smell() */

/**
 * Returns 1 to indicate that this object is a room.
 * @return 1 to indicate that this is a room
 */
int query_is_room() { return 1; }

/** @ignore yes */
void event_weather( int has_changed ) {
    if( has_changed & NOTIFY_DAY ) {
        if( WEATHER_H->query_day() && last_updated == NIGHT ) {
            TO->changing_to_day( 0 );
            last_updated = DAY;
            if( item )
                item->do_init();
        } else if( last_updated == DAY ) {
            TO->changing_to_night( 0 );
            last_updated = NIGHT;
            if( item )
                item->do_init();
        }
    }
} /* event_weather() */

/**
 * This method adds the room to the weather handler as one
 * that needs to be notified when the day/night changes.
 */
void init_day_time() {
    WEATHER_H->weather_notify( TO, NOTIFY_DAY );
} /* init_day_time() */

/**
 * This method returns the current theft handler for the room.
 * @return the theft handler of the room
 * @see set_theft_handler()
 */
string query_theft_handler() { return theft_handler; }

/**
 * This method sets the current theft handler for the room.
 * @param word the new theft handler for the room
 * @see query_theft_handler()
 */
void set_theft_handler( string word ) { theft_handler = word; }

/**
 * This method returns the current item object.
 * @return the current item object
 * @see add_item()
 */
object query_item() { return item; }

/**
 * This method sets the custom item object should you wish to use one.
 * You have to set this before actually adding any items with add_item().
 * Note: If set to 0, this will attemp to recycle or destructs the
 * previous item object if there is one.
 * @param ob the object to use for add items
 * @see query_item()
 * @see add_item()
 */
void set_item( object ob ) {
    if( item ) {
        if( !ROOM_H->recycle_item(item) )
            item->dest_me();
        item = 0;
    }

    item = ob;

} /* set_item() */

/**
 * This method returns the current chatter object.
 * @return the chatter object
 * @see add_room_chat()
 */
object query_chatter() { return chatter; }

/**
 * This method returns the current situation changer object.
 * @return the situation changer object
 * @see add_situation()
 * @see automate_situation()
 * @see change_situation
 */
object query_situation_changer() { return sitchanger; }

/**
 * This method returns the current linker object.
 * @return the linker object
 */
object query_linker() { return linker; }

/**
 * This method returns the current wall object.
 * @return the wall object
 * @see add_room_chat()
 */
object query_wall() { return wall; }

/**
 * This returns the current array of hidden objects.  The hidden objects
 * are used to allow things to not actually be in the room description
 * but be able to be manipulated by commands.
 * @see add_hidden_object()
 * @see remove_hidden_object()
 * @return the array of hidden objects
 */
object *query_hidden_objects() { return hidden_objects; }

/**
 * This puts a hidden object into a room. A hidden object is an object that
 * exists in the room as far as all the find_match calls go. So, for look at's
 * and so on, but does not actually exist in the room so it does not show up
 * in the inventory when the player does a look. This is the method used for
 * putting signs and doors into rooms, that actually have shorts and you can
 * do things to, but do not show up in the inventory. The function init() is
 * also called on these objects when init() is called in the room.
 * <p>
 * If this sounds complicated. Think of it as an object that IS in the room, but
 * you cannot see it.
 * <p>
 * A word of warning here, the init() function will *not* be called on all
 * the players when the object is added as hidden.  This means that the
 * commands on it will not be available until the player re-enters the room.
 * @example
 * #include <room.h>
 * sign = clone_object(PATH+SIGN);
 * add_hidden_object(sign);
 * @example
 * // Add a hidden object that has actions we want players to be able to
 * // use immediately.
 * object tp, *players, player;
 *
 * add_hidden_object(fluffy_container);
 *
 * players = filter( all_inventory(), (: living($1) :) );
 * tp = TP; // Store our current this_player().
 *
 * foreach( player in players ) {
 *     set_this_player( player );
 *     TO->init();
 * }
 *
 * set_this_player(tp); // Restore our current this_player().
 *
 * // This forces init() to be recalled.  (This is a relatively icky
 * // way of doing it, but the driver does not give us many alternatives).
 *
 * @see query_hidden_object()
 * @see remove_hidden_object()
 * @param thing the hidden object to add
 * @return 1 if successful, 0 on a failure
 */
int add_hidden_object( object thing ) {
    if( member_array( thing, hidden_objects ) != -1 )
        return 0;
    hidden_objects += ({ thing });
    return 1;
} /* add_hidden_object() */

/**
 * This method removes a hidden object.
 * @param thing the hidden object to remove
 * @return 1 on success, 0 on failure
 * @see add_hidden_object()
 * @see query_hidden_objects()
 */
int remove_hidden_object( object thing ) {
    int i;

    if( ( i = member_array( thing, hidden_objects ) ) == -1 )
        return 0;

    hidden_objects = delete( hidden_objects, i, 1 );

    return 1;

} /* remove_hidden_object() */

/** @ignore yes */
int test_add( object thing, int flag ) { return 1; }

/** @ignore yes */
int test_remove( object thing, int flag, mixed dest ) { return 1; }

/** @ignore yes */
int add_weight( int number ) { return 1; }

/** @ignore yes */
int query_no_writing() { return 1; }

/** @ignore yes */
int query_decay() { return 10; }

/**
 * This method sets the default attack speed for the room.
 * This defaults to 15.
 * @return the default attack speed
 */
int attack_speed() { return 15; }

/**
 * This is the message to print instead of the room description when the
 * room is dark.  It defaults to the message "It's dark in here isn't it?".
 * @return the dark message
 * @see set_dark_mess()
 * @see long()
 * @see query_bright_mess()
 */
string query_dark_mess() {
    mixed dark_mess;

    return ( !stringp( dark_mess = query_property("dark mess") ) ?
             "It's dark here, isn't it?" : dark_mess );
} /* query_dark_mess() */

/**
 * This method sets the dark message associated with the room.
 * @param word the new dark message
 * @see query_dark_mess()
 * @see long()
 */
void set_dark_mess( string word ) { add_property("dark mess", word ); }

/**
 * This method returns the message to use when it is too bright to see in
 * the room.  It defaults to: "It's too bright to see anything!".
 * @return the message to print when it is too bright
 * @see query_dark_mess()
 * @see long()
 * @see set_bright_mess()
 */
string query_bright_mess() {
    mixed bright_mess;

    return ( !stringp( bright_mess = query_property("bright mess") ) ?
             "It's too bright to see anything!" : bright_mess );
} /* query_bright_mess() */

/**
 * This method sets the bright message associated with the room.
 * @param word the new bright message
 * @see query_bright_mess()
 * @see long()
 */
void set_bright_mess( string word ) { add_property("bright mess", word ); }

/**
 * This method returns the set of move zones for this room.  This is used
 * by NPCs to see which rooms they are allowed to move into.
 * @see add_zone()
 * @see /std/npc->add_move_zone()
 */
string *query_zones() {
    string *zones;

    if( pointerp( zones = query_property("room zone") ) )
        return zones;
    return ({"nowhere"});
} /* query_zones() */

/**
 * This method adds a move zone into the current list of movement zones
 * for the room.  The move zones are used by NPCs to see which rooms they
 * are allowed to move into.
 * @see query_zones()
 * @see /std/npc->add_move_zone()
 */
void set_zone( string zone ) {
    string *zones;

    if( !zones = query_property("room zone") )
        zones = ({ zone });
    else
        zones += ({ zone });

    add_property("room zone", zones );

} /* set_zone() */

/** @ignore yes */
void event_theft( object cmd_ob, object thief, object victim, object *obs ) {
    log_file("THEFT", "%s: %s (%s) stole %s from %s (%s) in %s\n",
        ctime( time() ), thief->query_short(), file_name( thief ),
        implode( obs->query_short(), ", " ), victim->query_short(),
        file_name( victim ), file_name() );

    if( stringp( theft_handler ) ) {
        if( theft_handler != "none" )
            theft_handler->handle_theft( TO, cmd_ob, thief, victim, obs );
    } else {
        THEFT_H->handle_theft( TO, cmd_ob, thief, victim, obs );
    }

} /* event_theft() */

/** @ignore yes */
int query_last_visited() {
    if( sizeof( filter( INV(TO), (: userp($1) :) ) ) )
        last_visited = time();
    return last_visited;
} /* query_last_visited() */

/** @ignore yes */
void event_exit( object ob, string message, object to ) {
    if( interactive(ob) )
        last_visited = time();
#ifdef FAST_CLEAN_UP
    // For runthroughs.
    init_fast_clean_up();
#endif
} /* event_exit() */

/**
 * This method adds an item description to a room.  This allows you to
 * set up objects which do not as such exist, but can be looked at for
 * instance.  There should be a lot of these in rooms.  The name of
 * the item can be multiple word, and the plural for it is
 * automagicaly added, unless the no_plural flag is set.  If the name
 * is an array all of the elements in the array respond to the
 * description.
 * <p>
 * If the desc is set to an array, you can use this for handling
 * things like read messages and so on too.  Every second element in
 * the array is the description/text to be printed and the other
 * element is the command upon which the text should be printed.  The
 * special command 'long' is used to set the long description.
 * <p>
 * The special type 'position' is used to allow people to use that
 * item to do positions on, like stand, sit, lie etc.
 * <p>
 * This method also allows you to setup add_command patterns.  If the
 * name after the verb is just a string, then the string will be printed
 * when that verb is used.  If it is just a function pointer then the
 * function will be evaluated and the return result printed.  If it
 * is an array, then the first element must be a function pointer and
 * the second optional element is the pattern to use for that method.
 * Multiple patterns and functions may be specified.
 * @param shorts the short description of the item
 * @param desc the description of the item
 * @param no_plural do not automaticaly add a plural for the item
 * @return 1 if successfully added, 0 if not
 * @example
 * add_item("green pot plant", "It is a nasty green pot plant lurking by "
 *                             "the door.\n");
 * @example
 * add_item(({ "telephone", "red phone" }),
 *          "Sitting in the corner is the red phone, it is staring unhappily "
 *          "into space thinking of cupcakes and better times.\n");
 * @example
 * add_item("small book", ({ "long", "A small red book with dots on the
 *                                   "cover.\n",
 *                           "read", "It says 'Rabbit!' in big letters.\n" }) );
 * @example
 * add_item("green leather couch",
 *          ({ "long", "The green leather couch is wonderful , so comfy!  "
 *                     " So... Comfy!\n",
 *             "position", "the green leather couch" }) );
 * @example
 * add_item("rotating hologram", (: query_current_hologram_string() :));
 * @example
 * add_item("glue stick",
 *          ({ "long", "The glue stick looks sticky, like you could slime "
 *                     "something with it.\n",
 *             "slime", ({ (: do_slime :),
 *                         "<indirect:living> with <direct:object>" }) }) );
 * @see query_item()
 * @see remove_item()
 * @see modify_item()
 */
varargs int add_item( mixed shorts, mixed desc, int no_plural ) {
    if( !desc ) {
        printf("Error!  In %O add_item(%O, 0), not added.\n",
            file_name(), shorts );
        return 0;
    }

    if( !item )
        item = (object)ROOM_H->get_item();

    item->setup_item( shorts, desc, no_plural, ITEM_COMMON );

    return 1;

} /* add_item() */

/**
 * This method will attempt to remove the item defined by the given string.
 * This will remove everything associated with that item, verbs, patterns,
 * everything.  This will _not_ remove any day/night items permanently,
 * please use remove_day_item or remove_night_item for that.
 * @param word the name of the item to remove
 * @return 1 if successful, 0 on a failure
 * @example
 * add_item("frog", "Cute, green and sitting on a lilly pad.  Yes!\n");
 * ...
 * remove_item("frog");
 * @example
 * add_item(({ "big bad chicken", "clucker" }),
 *          "The big bad chicken sits and stares at you.\n");
 * ...
 * remove_item("big bad chicken");
 * @see add_item()
 * @see query_item()
 */
int remove_item( string word ) {
    if( !item )
        return 0;
    return (int)item->remove_item( word, ITEM_COMMON );
} /* remove_item() */

/**
 * This method will modify certain bits of the specified item.  This will
 * change only the bits of the pattern that are specified.  If you wish to
 * remove elements a better method would be to remove the item and
 * then re-add it.  The format of the new_desc array is the same as in the
 * add_item code.
 * @param word the name of the item to change
 * @param new_desc the bits of the item to change
 * @see remove_item()
 * @see add_item()
 */
int modify_item( string word, mixed new_desc ) {
    if( !item )
        return 0;
    return (int)item->modify_item( word, new_desc, ITEM_COMMON );
} /* modify_item() */

/** @ignore yes */
varargs int set_linker( string *rooms, string d_prep, string s_prep,
                        string r_name ) {
    if( linker )
        return 0;

    linker = clone_object( LINKER_OBJECT );
    linker->setup_shadow( TO, rooms, d_prep, s_prep, r_name );

    return 1;

} /* set_linker() */

/** @ignore yes */
void set_wall( mixed args ) {
    if( !wall ) {
        wall = clone_object( WALL_OBJECT );
        wall->setup_shadow( TO );
    }
    wall->set_wall( args );
} /* set_wall() */

/**
 * This method sets the default position for the room.  Se the set
 * default position in the living code for a more complete
 * example of this.
 * @param pos the default position
 * @see /ostd/living/living->set_default_position()
 */
void set_default_position( mixed stuff ) {
    add_property( DEFAULT_POSITION_PROPERTY, stuff );
} /* set_default_position() */

/**
 * This method returns the current default position asigned to this
 * room.
 * @return the current default position
 */
mixed query_default_position() {
    return query_property( DEFAULT_POSITION_PROPERTY );
} /* query_default_position() */

/**
 * This method tells us if the passed i nposition is
 * allowed in this type of room.
 * @param poss the position to check
 */
int is_allowed_position( string poss ) {
    switch( poss ) {
    case SITTING :
    case STANDING :
    case KNEELING :
    case LYING :
    case MEDITATING :
    case CROUCHING :
      return 1;
    default :
      return 0;
    }
} /* is_allowed_position() */

/** @ignore yes */
void dest_me() {
    object thing, *things;

    // If this is not the void, remove contents to /room/rubbish for
    // recycling and move players to the void.
    if( file_name(TO) != VOID_ROOM ) {
        things = INV( TO );
        foreach( thing in things ) {
            if( userp( thing ) ) {
                thing->move_with_look( ROOM_VOID, "$N fall$s into the void." );
                continue;
            }
            if( thing->cleaning_room() )
                continue;
            thing->move("/room/rubbish");
        }
    }

    if( sitchanger )
        sitchanger->dest_me();

    if( linker )
        linker->destruct_shadow( linker );

    if( wall )
        wall->destruct_shadow(wall);

    if( chatter ) {
        if( !ROOM_H->recycle_chatter(chatter) )
            chatter->dest_me();
        chatter = 0;
    }

    if( item ) {
        if( !ROOM_H->recycle_item(item) )
            item->dest_me();
        item = 0;
    }

    things = filter( values(door_control), (: objectp($1) :) );

    hidden_objects -= things + ({ 0 });

    foreach( thing in things )
        if( !ROOM_H->recycle_door(thing) )
            thing->dest_me();

    foreach( thing in hidden_objects )
        if( !thing->multiple_hidden() )
            thing->dest_me();

    BURIAL_H->room_dested();
    WEATHER_H->room_dested();

    destruct(TO);

} /* dest_me() */

/**
 * This method sets the flag that enables or disables the room being
 * cleaned up.  If they flag is set to 1, then room is never cleaned up.
 * @param flag the room being cleaned up flag
 * @see query_keep_room_loaded()
 */
void set_keep_room_loaded( int flag ) {
    if( flag )
        add_property( ROOM_KEEP_PROP, flag );
    else
        remove_property(ROOM_KEEP_PROP);
} /* set_keep_room_loaded() */

/**
 * This method returns the status of the keep room loaded flag.  If they
 * flag is non-0 then the room with not be unloaded.
 * @return the status of the keep room loaded flag
 */
int query_keep_room_loaded() {
    return query_property(ROOM_KEEP_PROP);
} /* query_keep_room_loaded() */

#ifdef FAST_CLEAN_UP
/** @ignore yes */
void heart_beat() {
    if( room_stabilize != 1 && query_fast_clean_up() &&
        ( !query_last_visited() || !room_stabilize++ ) ) {
        if( sizeof(INV(TO)) || ( time() - room_create_time ) > 10 ||
            BURIAL_H->query_buried_container(TO) ) {
            // Turn off the heart beat, we are now stable.
            set_heart_beat( 0 );
            room_stabilize = 1;
        } else {
            dest_me();
        }
    }
} /* heart_beat() */

/**
 * This function allows you to disable the fast clean-up of rooms.
 * @see clean_up_room
 * @param i 1 to allow fast clean-up, 0 to disable it
 */
void set_fast_clean_up( int i ) {
    if( !i ) {
        set_heart_beat( 0 );
        room_stabilize = 1;
    }
    fast_clean_up = i;
} /* set_fast_clean_up() */

/**
 * This function allows you to check whether or not fast clean-up
 * is currently allowed.
 * @return 0 if it is disabled, 1 if it is allowed
 */
int query_fast_clean_up() {
    return fast_clean_up && !TO->query_keep_room_loaded();
} /* query_fast_clean_up() */
#endif

/** @ignore yes */
int clean_up( int parent ) {
    if( parent || TO->query_keep_room_loaded() )
        return 0;
    call_out("real_clean", 10 + random(120) );
    return 1;
} /* clean_up() */

/**
 * @ignore yes
 * This function is called either by clean_up() or directly by the
 * garbage handler.  It should always returns 1 to let the garbage handler
 * know the function completed successfully.
 * - Sandoz
 */
int real_clean() {
    /*
     * Don't clean up the room if there's a player in it,
     * there's a unique or hurt NPC in it and it's been visited
     * by a player in the last hour, it's a slave room, there's
     * a corpse in it or there are buried things in it.
     */
    if( TO->query_keep_room_loaded() || sizeof( filter( INV(TO),
        (: userp($1) || ( living($1) && ( $1->query_property("unique") ||
        $1->query_hp() < $1->query_max_hp() ) ) ||
        $1->query_corpse() || $1->query_slave() :) ) ) ||
        BURIAL_H->query_buried_container(TO) )
        return 1;

    dest_me();
    return 1;

} /* real_clean() */

/**
 * This method returns all the matchable objects in the room.  This is used
 * by find_match to determine the group of objects to select from.
 * @param words the words to match on
 * @param looker the person doing the pmacthing
 * @return the array of objects to match on
 */
object *find_inv_match( string words, object looker ) {
    object *things;

    things = INV( TO );

    if( pointerp( hidden_objects ) )
        things += hidden_objects;

    things = filter( things, (: $1 && $1->short(0) &&
             ( !$2 || $1->query_visible($2) ) :), looker );

    if( item )
        things += ({ item });

    return things;

} /* find_inv_match() */

/**
 * This method stops all the room chats for the room.  It also removes
 * all the room chats, so if you want to have any more you must
 * add them again.
 * @see room_chat()
 */
void stop_room_chats() {
    if( chatter ) {
        if( !ROOM_H->recycle_chatter(chatter) )
            chatter->dest_me();
        chatter = 0;
    }
} /* stop_room_chats() */

/**
 * Allows the chat interval to be changed.
 * @param min minimum interval between chats (seconds)
 * @param max maximum interval between chats (seconds)
 */
void set_chat_min_max( int min,int  max ) {
    if( chatter )
        chatter->set_chat_min_max(min,max);
} /* set_chat_min_max() */

/**
 * Allows the night chat interval to be changed.
 * @param min minimum interval between chats (seconds)
 * @param max maximum interval between chats (seconds)
 */
void set_night_chat_min_max( int min,int  max ) {
    if( chatter )
        chatter->set_night_chat_min_max(min,max);
} /* set_chat_min_max() */

/**
 * Adds more chats to the existing set of room chats
 * managed by this chatter object.
 * @param new_chats an array of new chat strings
 * @see remove_room_chats
 * @see query_room_chats
 * @see /std/room/basic/chatter
 */
void add_room_chats( string *new_chats ) {
    if( chatter )
        chatter->add_room_chats( new_chats );
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
    if( chatter )
        chatter->add_room_night_chats( new_chats );
} /* add_room_night_chats() */

/**
 * Removes chats from the set of room chats
 * managed by this chatter object.  If there are no chats
 * left the chatter is destructed.
 * @param dead_chats an array of chat strings to remove
 * @see add_room_chats
 * @see query_room_chats
 * @see /std/room/basic/chatter
 */
void remove_room_chats( string *dead_chats ) {
    if( chatter )
        chatter->remove_room_chats( dead_chats );
} /* remove_room_chats() */

/**
 * Removes chats from the set of room night chats managed
 * by this chatter object.  If there are no chats left the
 * chatter is destructed.
 * @param dead_chats an array of chat strings to remove
 * @see add_room_chats
 * @see query_room_chats
 * @see /std/room/basic/chatter
 */
void remove_room_night_chats( string *dead_chats ) {
    if( chatter )
        chatter->remove_room_night_chats( dead_chats );
} /* remove_room_night_chats() */

/**
 * Returns the set of room chats
 * managed by the chatter object.
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
mixed query_room_chats() {
    return ( chatter ? chatter->query_room_chats() : 0 );
} /* query_room_chats() */

/**
 * Returns the set of room night chats managed by the chatter object.
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
mixed query_room_night_chats() {
    return ( chatter ? chatter->query_room_night_chats() : 0 );
} /* query_room_night_chats() */

/**
 * This method sets up the room chats.
 * Room chats are strings which are printed at (semi) random intervals
 * in rooms.  They are used to add atmosphere to a room. A chat will
 * be picked at random from the array of chats with a frequency
 * controlled by the times min and max. ie. one will be picked every n
 * seconds where is varies between min and max seconds. Please don't
 * make the values for min and max too small or the messages just
 * become annoying!
 * <p>
 * The argument to the room_chat method is an array of the format:<br>
 * ({ int min, int max, ({ string *chats }) }).  In place of a chat
 * string you may use "#function_name", where function_name is a
 * function to be called that exists on the room object, or
 * "@function_name", where the function name is a function that
 * exists on the room object, and returns a string, that will be
 * printed.  The chat can also be a function pointer, which will then
 * be evaluated and the resulting string will be printed.  Note however
 * that function pointers as chat strings cannot be removed with
 * remove_room_chats().
 * <p>
 * Repeated calls to this function overwrite the chats for
 * the default chatter.
 * <p>
 * Note: room chats are checked against visibility (effects blindness,
 * too dark, too bright), it will be possible to use strings such as
 * "$A tall man|Someone$ walks down the street.", which will then be
 * expanded to "A tall man walks down the street." to the players who
 * can see in the room, while players who can't see will get
 * "Someone walks down the street.".
 * <p>
 * The following string expansion will also be done on the input string.
 * "%I" will be replaced with the_short() of a random interactive
 * player in the room, "%Iposs" with poss_short() of the same random
 * interactive player, "%Ip" with his/her, "%Io" with him/her,
 * and "%Ir" with he/she.
 * This allows one to make chats more random, and more interactive, because
 * they relate more closely to players.
 * @example "A dark clad figure hurries past, almost knocking %I over."
 * Which will then be printed to the randomly chosen person as -
 * "A dark clad figure hurries past, almost knocking you over."
 * and for the rest of the room - "A dark clad figure hurries past, "
 * "almost knocking Baron Shiannar von Einleck over."
 * <p>
 * @param args the room chat arguments
 * @param chatobj chatter object in case the default offends you.
 *                This argument may be omitted in which case you get
 *                /std/room/basic/chatter.c
 * @example
 * room_chat(({ 120, 240, ({
 *     "A $frog|creature$ wanders past %I and croaks at %Io.", // String.
 *     "#make_soggy_bread", // A function in the room that will be evaluated.
 *     "@do_random_chat", // A function in the room that should return a string.
 *     (: do_another_random_chat :), // A functional which should return a string.
 *     }) }) );
 * @see stop_room_chat()
 * @see add_room_chats()
 * @see remove_room_chats()
 * @see set_chat_min_max()
 */
varargs void room_chat( mixed args, object chatobj ) {
    if( !pointerp( args[ 2 ] ) ) {
        write("Error: second argument of room_chat args is not an array.\n");
        return;
    }

    if( chatter ) {
        chatter->setup_chatter( TO, args );
        return;
    }

    chatter = ( objectp(chatobj) ? chatobj : (object)ROOM_H->get_chatter() );
    chatter->setup_chatter( TO, args );

} /* room_chat() */

/**
 * This method sets up the day room chats.  See room_chat() for more info.
 * @see stop_room_chat()
 * @see add_room_chats()
 * @see remove_room_chats()
 * @see set_chat_min_max()
 * @see room_night_chat()
 * @see /std/room/basic_room->room_chat()
 */
varargs void room_day_chat( mixed args, object chatobj ) {
    init_day_time();
    room_chat( args, chatobj );
} /* room_day_chat() */

/**
 * This method sets up the night room chats.  See room_chat() for more info.
 * @see stop_room_chat()
 * @see add_room_chats()
 * @see remove_room_chats()
 * @see set_chat_min_max()
 * @see room_day_chat()
 * @see /std/room/basic_room->room_chat()
 */
varargs void room_night_chat( mixed args, object chatobj ) {
    if( !pointerp( args[ 2 ] ) ) {
        write("Error: second argument of room_chat args is not an array.\n");
        return;
    }

    if( chatter ) {
        chatter->setup_night_chatter( TO, args );
        return;
    }

    chatter = ( objectp(chatobj) ? chatobj : (object)ROOM_H->get_chatter() );
    chatter->setup_night_chatter( TO, args );
    init_day_time();

} /* room_night_chat() */

/**
 * Set a situation changer (in place of the default).
 * If there is no argument you get the default:
 * /std/room/basic/situation_changer.
 * You call this before any other situation related functions.
 * If you create your own changer it should inherit one of
 * /std/room/basic/situation_changer or
 * /std/room/basic/multiroom_situation_changer or
 * otherwsie provide the functionality of those objects.
 * @param changer optional parameter specifying either a path for
 * the changer object or an existing object to use.
 * @see add_situation
 * @see start_situation
 * @see automate_situation
 * @see change_situation
 * @example
 * If you have a special changer object used for more than one room
 * then in setup for those rooms you should have:
 * set_situation_changer(load_object("/w/me/mychanger"));
 * Where /w/me/mychanger inherits
 * /std/room/basic/multiroom_situation_changer
 */
varargs object set_situation_changer( mixed changer ) {
    if( stringp(changer) )
        sitchanger = clone_object( changer );
    else if( objectp(changer) )
        sitchanger = changer;
    else
        sitchanger = clone_object( SITUATION_CHANGER_OBJECT );

    return ( sitchanger = sitchanger->set_room(TO) );

} /* set_situation_changer() */

/**
 * Adds a situation to the room.  These situations can be
 * invoked manually with start_situation or automatically via
 * automate_situation.
 * @param label string or number labelling the situation
 * @param sit a structure (class) containing all the bits
 * of the situation you want to add.  It should be a
 * variable of class situation.  You should include
 * situations.h where this class is defined.
 * Every part is optional.
 * eg.
 * start_func  function to be called at start of situation
 *             that might be used to load NPC's or anything
 *             beyond a message.
 *
 *             The start function is passed the label,
 *             a do_start_mess flag and the room object.
 *             If the flag is 1 the situation is starting
 *             rather than being reloaded.  Thus if
 *             do_start_mess is 0 then you should avoid
 *             any obvious start messages and make it look
 *             like the situation is already underway.
 *
 * end_func    function to be called an the end of a situation.
 *             The end function is only
 *             passed the label and the room object.
 *
 * start_mess  message told to the room at start of situation
 *
 * end_mess    message told to the room at end of situation
 *
 * extra_look  extra look string appended to rooms long
 *             during the situation
 * chat_rate   an array of 2 numbers giving the minimum and
 *             maximum delay between chats.  If this is set
 *             then the chats are not merged with the
 *             existing chats but added independently with
 *             their own chat rates as given.
 *
 * chats       an array of chat strings to be active
 *             during the situation
 *
 * add_items   a mixed array of ({ item, item description })
 *             pairs to be active during the situation
 *
 * random_words  sets of words to insert into text to replace
 *               the special character #n where n is a number.
 *             The form of the array is ({  #1array, #2array, ... })
 *             where #1array = ({ "#1word1","#1word2",... }) etc.
 *             For the duration of the situation one of the strings
 *             in #1array is used to replace all instances of #1
 *             in the extra_look, start_mess, end_mess, chats
 *             and key and the long description part of the add_items.
 *             In a situation compounded of many situations
 *             the same random seed is used for choosing all #1's
 *             for each individual situation for the duration,
 *             and a different seed for all #2's etc.
 *
 * @see start_situation
 * @see end_situation
 * @see automate_situation
 * @see change_situation
 * @see add_item
 * @see room_chat
 * @see add_extra_look
 * @see set_situation_changer
 * @see make_situation_seed
 * @see /include/situation.h
 * @see goto learning  search  situation  for working examples
 * @example
 * #include <situations.h>
 *
 * class situation frogs;
 * frogs = new(class situation,
 *     start_mess: "Water seeps out of the ground to form puddles.",
 *     extra_look: "There are large puddles on the ground here.",
 *     chat_rate: ({ 120,180 }),
 *     chats: ({"A hidden frog croaks quietly.",
 *              "There is a blooping sound." }),
 *     add_items:({ ({"puddle", "The puddles are dark and murky.  "
 *                    "They will probably dry up given time." }) }) );
 * add_situation( "frogs", frogs );
 *
 * @example
 * add_situation( "ship", new(class situation,
 *      start_mess: "A #1 ship hoves into view.",
 *      extra_look: "There is a #1 ship forging up the river.",
 *      chats: ({"The #1 ship's sails flap in the breeze.",
 *               "Shouts of sailors carry over to you from the #1 ship." }),
 *      add_items: ({ ({"ship", "The #1 ship, the \"#2\" is a small "
 *                    "sailing vessel that transports cargo up and "
 *                    "down the river."}) }),
 *      random_words: ({ ({ "old","waterlogged","heavily laden" }),
 *                       ({ "Jemima", "Old Sea Dog", "Randy Mermaid" }) })
 *      ) );
 * When the situation is started a random choice (eg. "old") replaces #1
 * and a name (eg. "Jemima") replaces #2 in the text strings for
 * the duration.
 *
 * @example
 * add_situation( "frogs", new(class situation,
 *      start_mess: "Water seeps out of the ground to form puddles.",
 *      extra_look: "There are large puddles on the ground here.",
 *      chats: ({"A hidden frog croaks quietly.",
 *               "There is a blooping sound." }),
 *      add_items: ({ ({"puddle", "The puddles are dark and murky.  "
 *                      "They will probably dry up given time." }) }) ));
 * @example
 * This is an empty situation, useful for making pauses in the action.
 * add_situation( "pause", new(class situation) );
 */
void add_situation( mixed label, class situation sit ) {
    if( !sitchanger ) {
        sitchanger = clone_object( SITUATION_CHANGER_OBJECT );
        sitchanger->set_room( TO );
    }

    sitchanger->add_situation( label, sit );

} /* add_situation() */

/**
 * Makes a seed value for the random part of when
 * situations turn on and off.  The two ints should be
 * constant for a given room -- eg. the coordinates.
 * If this function is not called the seed is
 * generated from the file_name of the object.
 * For this reason, rooms that are clones will produce
 * erratic results unless this function is called.
 * @param xval integer to use to make a seed (eg. x coordinate)
 * @param yval integer to use to make a seed (eg. y coordinate)
 */
void make_situation_seed( int xval, int yval ) {
    if( sitchanger )
        sitchanger->set_seed( xval, yval );
} /* make_situation_seed() */

/**
 * Starts a situation previously added to the room.  These situations can be
 * invoked manually with start_situation or automatically via
 * automate_situation.  The call is passed to the situation
 * changer object.  If there isn't one nothing happens.
 * @param label label for the situation as passed to add_situation
 * @param do_start_mess 0 to supress the start_mess string
 *        This is to fake it that a situation has been
 *        going for a while when really you just loaded it.
 * @see add_situation
 * @see end_situation
 * @see automate_situation
 * @see change_situation
 */
void start_situation(int label, int do_start_mess) {
    if( sitchanger )
        sitchanger->start_situation( label, do_start_mess );
} /* start_situation */

/**
 * Ends a situation previously added and started on the room.
 * These situations can be invoked manually with start_situation
 * or automatically via automate_situation.
 * @param label label for the situation
 * @see add_situation
 * @see start_situation
 * @see automate_situation
 * @see change_situation
 */
void end_situation(mixed label) {
    if( sitchanger )
        sitchanger->end_situation( label );
} /* end_situation() */

/**
 * Starts one or more situations that will end after a
 * specified duration.  You can use an array and make
 * further situations commence when others end.
 * @param label (mixed) label of the situation to start up.
 * If you pass an array such as ({ "frog1", "frog2" }) for the
 * label then that set of situations are started one at
 * a time and the total duration is split evenly between them.
 * Label is usually an integer or a string or an array of
 * integers and/or strings.
 * If the string is a list of labels
 * separated by , then multiple situations
 * are started using those labels.
 * @param duration (int) total time (seconds) the overall situation
 * should last.  You can put an array of durations -- one for each
 * situation if the label lists more than one situation and then
 * the overall time is the sum of the numbers.
 * -1 is a special duration.  It means that the labelled situation goes on
 * forever (and thus nothing after it in the array will ever go).
 * @param words is a list of replacements for #n in the text OR
 * a random number seed to use to choose words from random_words.
 * eg. ({ "#1", "frog", "#2", "honey" }) or 22
 *
 * @return handle useful for halting the changes later.  It is typically
 * a small positive integer.
 * @see shutdown_situation
 * @see add_situation
 * @see automate_situation
 * @see goto learning  search  situation  for working examples
 * @example
 * handle=change_situation( ({ "sew1","sew2" }), ({ 60,60 }) );
 *
 * if (over) shutdown_situation( handle, ({ "sew1","sew2" }) );
 * @example
 * change_situation( ({ "background,sew1","background,sew2" }), 120 );
 * @example
 * change_situation( ({ "building_falling","rubble" }), ({ 120, -1 }) );
 * @example
 * add_situation( "boat1",
 *   new(class situation,
 *     start_mess: "A little fishing boat comes up to the pier.  "
 *        "It has the name \"#1\" painted on the side.\n"
 *        "A fisherman jumps off the boat and ties its painter to a post.",
 *     chats: ({"The little boat bobs up and down next to the pier.",
 *              "A fisherman hops off the little boat." }),
 *     chat_rate: ({ 20, 30 }),
 *     extra_look: "There is a little boat here.",
 *     add_items: ({ ({ ({ "#1","little boat" }),
 *       "There is little fishing boat tied up at the pier here.  "
 *       "The name \"#1\" is painted on the side."   }) }),
 *     end_mess: "The fishermen get back on board and "
 *        "the little boat moves on.",
 *     random_words: ({ ({ "Honey Toad", "Piker", "Bing" }) })
 *   )
 * );
 *
 * change_situation( "boat1", 120, ({ "#1","Floating Egg" }) );
 */
varargs mixed change_situation( mixed label, mixed duration, mixed words ) {
    if( sitchanger )
        return sitchanger->change_situation(label,duration,words,0);
    return 0;
} /* change_situation() */

/**
 * Automate starting and ending of a situation.
 * These situations can be invoked manually with start_situation.
 * The automated starting and ending is unaffected by the room
 * unloading.  When the room reloads the situation will be
 * restarted unless its duration is up.
 * You must include the file situations.h for the definitions
 * of the when masks.  The random seed needs to be set
 * consistently for the situations.  This is probably ok
 * unless your rooms are clones (see make_situation_seed).
 * @param label (mixed) label of the situation to start
 *  up.  If you pass an array such as ({ "frog1", "frog2" }) for the
 * label then that set of situations are started one at
 * a time and the total duration is split evenly between them.
 * Label is usually an integer or a string or an array of
 * integers and/or strings.
 * If the string is a list of labels
 * separated by , then multiple situations
 * are started using those labels.
 * @param duration (int) total time (seconds) the overall situation
 * should last.  You can put an array of durations -- one for each
 * situation if the label lists more than one situation and then
 * the overall time is the sum of the numbers.
 * -1 is a special duration.  It means that the situaton given that
 * duration is not part of the set but a special background or
 * default situation that occurs all the time except when
 * this automated situation is going.
 * @param when (int) a time of the day mask.  This limits when
 * the situation is allowed to occur.  The mask is composed of
 * the allowed hours in AM time ( 24 hours clock, (1<<hour) and
 * combined with | (OR) ).   You can just use these
 * predefined masks and ignore how it works:
 *  WHEN_WEE_HOURS, WHEN_EARLY_MORNING, WHEN_LATE_MORNING, WHEN_AFTERNOON
 *  WHEN_EVENING, WHEN_LATENIGHT, WHEN_MIDDAY, WHEN_MORNING,
 *  WHEN_EARLY_MORNING, WHEN_LATE_MORNING, WHEN_NIGHT, WHEN_DAY
 *  WHEN_ANY_TIME
 * The masks are defined in /include/situations.h.
 * @param chance  (int) chance in 1000 of starting the situation
 *  This is tested every duration seconds.
 * @param category (optional) if you specify a cateory for the situation
 *                 then no situations with the same category will overlap.
 *                 category would usually be a string eg. "boats".
 * @see add_situation
 * @see start_situation
 * @see end_situation
 * @see situations.h
 * @see set_situation_changer
 * @see make_situation_seed
 * @see goto learning  search  situation  for working examples
 * @example
 * #include <situations.h>
 *
 *  automate_situation( "frog", 300, WHEN_ANY_TIME, 200 );
 *
 * This will automatically start the situation labelled "frog"
 * at a random time that is any time of the day with a 200/1000
 * chance of it starting per 300 seconds.  It will last for
 * 300 seconds (5 minutes).
 * @example
 *  automate_situation( ({"frog1,pond","frog2,pond"}), 240,
 *                        WHEN_EVENING|WHEN_NIGHT, 300 );
 *
 * This will automatically start a situation that is a combination
 * of "frog1" and "pond" followed by "frog2" and "pond".  They start
 * at a random time but only in the evening or at night.
 * There will be a 300/1000 chance of
 * it starting per 240 seconds.  Both the "frog1" and "frog2"
 * situations will get half the total time (as there are two),
 * 120 seconds each, for a total duration of 240 seconds (4 minutes).
 * @example
 *  automate_situation( ({"frog1,pond","frog2,pond"}), ({ 80,160 }),
 *                        WHEN_EVENING|WHEN_NIGHT, 300 );
 * Same as previous example except the durations of the individual
 * parts are set: "frog1,pond" for 80 seconds followed by "frog2,pond"
 * for 160 seconds.  The total time is 80+160.
 */
varargs void automate_situation( mixed label, mixed duration, mixed when,
                                 mixed chance, mixed category ) {
    if( sitchanger )
        sitchanger->automate_situation( label, duration, when, chance,
            category );
} /* automate_situation() */

/**
 * Shuts down all current and pending situations.  It also turns off the
 * automated situation manager so no more are added.  It does not
 * destruct this object so all the add_situations are still loaded
 * and make be recommenced with automate_situation.  dest_me is
 * the appropriate call to permanently remove all situations.  The
 * call is passed to the situation changer object.  If none exists
 * then nothing happens.  The situation changer is created when
 * an add_situation call is performed.
 * @see add_situation
 * @see automate_situation
 * @see change_situation
 */
void shutdown_all_situations() {
    if( sitchanger )
        sitchanger->shutdown_all_situations();
} /* shutdown_all_situations() */

/**
 * Shuts down a situation or set of situations initiated with
 * change_situation based on the call_out handle
 * returned by the call to change_situation.
 * @param callout call_out handle.  If 0 then the last
 * known handle is used.
 * @param label label or array of labels of situations to clean
 * up with end_situation
 * @param the_room the room
 * @see automate_situation
 * @see change_situation
 */
void shutdown_situation( int call, mixed label ) {
    if( sitchanger )
        sitchanger->shutdown_situation( call, label );
} /* shutdown_situation() */

/**
 * This method sets the long description to display during the day time.
 * @param str the new day long description
 * @see query_day_long()
 * @see set_night_long()
 */
void set_day_long( mixed str ) {
    init_day_time();
    set_long( str );
} /* set_day_long() */

/**
 * This method sets up the night long for the room.  This will be the
 * long description displayed at night in the room.
 * @param str the new night long description
 * @see set_day_long()
 * @see query_night_long()
 */
void set_night_long( mixed str ) {
    init_day_time();
    night_long = str;
} /* set_night_long() */

/**
 * This method returns the long description of the room at night.  This is
 * used to print out different strings for rooms during the day and during
 * the night.
 * @return the night long for the room.
 */
mixed query_night_long() {
    if( functionp(night_long) )
        return evaluate(night_long);
    return ( stringp( night_long ) ? night_long : query_long() );
} /* query_night_long() */

/**
 * This method sets up an item which will only be displayed during the
 * day.  All of the standard add_item things are available with this
 * method.
 * @see /std/room/basic_room->add_item()
 * @see add_night_item()
 */
varargs int add_day_item( mixed shorts, mixed desc, int no_plural ) {
    if( !desc ) {
        printf("Error!  In %O add_day_item(%O, 0), not added.\n", file_name(),
               shorts );
        return 0;
    }

    if( !item )
        item = (object)ROOM_H->get_item();

    item->setup_item( shorts, desc, no_plural, ITEM_DAY );

    init_day_time();

    return 1;

} /* add_day_item() */

/**
 * This method will modify certain bits of the specified day item.
 * @see modify_item()
 * @see modify_night_item()
 */
int modify_day_item( string word, mixed new_desc ) {
    if( !item )
        return 0;
    return (int)item->modify_item( word, new_desc, ITEM_DAY );
} /* modify_day_item() */

/**
 * This method will attempt to remove the item defined by the given string.
 * This will remove everything associated with that item, verbs, patterns,
 * everything.  This is the preferred way of removing day items.
 * @see /std/room/basic_room->remove_item()
 * @see remove_night_item()
 */
int remove_day_item( string word ) {
    if( !item )
        return 0;
    return (int)item->remove_item( word, ITEM_DAY );
} /* remove_day_item() */

/**
 * This method sets up an item which will only be displayed during the
 * night.  All of the standard add_item things are available with this
 * method.
 * @see /std/room/basic_room->add_item()
 * @see add_day_item()
 */
varargs int add_night_item( mixed shorts, mixed desc, int no_plural ) {
    if( !desc ) {
        printf("Error!  In %O add_night_item(%O, 0), not added.\n",
            file_name(), shorts );
        return 0;
    }

    if( !item )
        item = (object)ROOM_H->get_item();

    item->setup_item( shorts, desc, no_plural, ITEM_NIGHT );

    init_day_time();

    return 1;
} /* add_night_item() */

/**
 * This method will modify certain bits of the specified night item.
 * @see modify_item()
 * @see modify_day_item()
 */
int modify_night_item( string word, mixed new_desc ) {
    if( !item )
        return 0;
    return (int)item->modify_item( word, new_desc, ITEM_NIGHT );
} /* modify_night_item() */

/**
 * This method will attempt to remove the item defined by the given string.
 * This will remove everything associated with that item, verbs, patterns,
 * everything.  This is the preferred way of removing night items.
 * @see /std/room/basic_room->remove_item()
 * @see remove_day_item()
 */
int remove_night_item( string word ) {
    if( !item )
        return 0;
    return (int)item->remove_item( word, ITEM_NIGHT );
} /* remove_night_item() */

/**
 * This method sets the determinate for the room.
 * @param str the new determinate
 * @see add_property()
 */
void set_determinate( string str ) { add_property("determinate", str ); }

/** @ignore yes */
string query_help_file_directory() { return ROOM_HELP_FILE_DIR; }

/**
 * This method sets the smell for the room.
 * @param smell the smell for the room
 */
void add_smell( mixed smell ) {
    if( pointerp(smell) )
        add_property("room_smell", smell );
    else if( stringp(smell) )
        add_property("room_smell", ({ smell }) );
} /* add_smell() */

/**
 * This method queries the smell for the room.
 */
string *query_room_smell() { return query_property("room_smell"); }

/**
 * This method sets the day smell for the room.
 * @param smell the day smell for the room
 */
void add_day_smell( mixed smell ) {
    if( pointerp(smell) )
        add_property("day_smell", smell );
    else if( stringp(smell) )
        add_property("day_smell", ({ smell }) );
    init_day_time();
} /* add_day_smell() */

/**
 * This method queries the day smell for the room.
 */
string *query_room_day_smell() { return query_property("day_smell"); }

/**
 * This method sets the night smell for the room.
 * @param smell the night smell for the room
 */
void add_night_smell( mixed smell ) {
    if( pointerp(smell) )
        add_property("night_smell", smell );
    else if( stringp(smell) )
        add_property("night_smell", ({ smell }) );
    init_day_time();
} /* add_night_smell() */

/**
 * This method queries the night smell for the room.
 */
string *query_room_night_smell() { return query_property("night_smell"); }

/**
 * This method sets the sound for a room.
 * @param sound the sound for the room
 */
void add_sound( mixed sound ) {
    if( pointerp(sound) )
        add_property("room_sound", sound );
    else if( stringp(sound) )
        add_property("room_sound", ({ sound }) );
} /* add_sound() */

/**
 * This method queries the sound for the room.
 */
string *query_room_sound() { return query_property("room_sound"); }

/**
 * This method sets the day sound for a room.
 * @param sound the day sound for the room
 */
void add_day_sound( mixed sound ) {
    if( pointerp(sound) )
        add_property("day_sound", sound );
    else if( stringp(sound) )
        add_property("day_sound", ({ sound }) );
    init_day_time();
} /* add_day_sound() */

/**
 * This method queries the day sound for the room.
 */
string *query_room_day_sound() { return query_property("day_sound"); }

/**
 * This method sets the night sound for a room.
 * @param sound the night sound for the room
 */
void add_night_sound( mixed sound ) {
    if( pointerp(sound) )
        add_property("night_sound", sound );
    else if( stringp(sound) )
        add_property("night_sound", ({ sound }) );
    init_day_time();
} /* add_day_sound() */

/**
 * This method queries the night sound for the room.
 */
string *query_room_night_sound() { return query_property("night_sound"); }

/**
 * Returns the current co-ordinates of the room.  The co-ordinates are
 * 3d, ({ x, y, z }).  So an array with three elements.
 * @return the current co-ordinates
 * @see set_co_ord()
 */
int *query_co_ord() {
    if( pointerp( co_ord ) )
        return copy(co_ord);
    return 0;
} /* query_co_ord() */

/**
 * Sets the current co-ordinates of the room.  The co-ordinates are
 * 3d, ({ x, y, z }).  So an array with three elements.
 * @param new_co_ord the new co-ordinates for the room.
 * @see query_co_ord()
 * @see query_co_ord_calculated()
 */
void set_co_ord( int *new_co_ord ) {
    if( !pointerp( new_co_ord ) )
        return write("Warning: Co-ordinate must be an array.\n");

    if( sizeof( new_co_ord ) != 3 )
        return write("Warning: The co-ordinate must have three elements.\n");

    co_ord = new_co_ord;
    co_ord_calculated = ( PO != TO );

} /* set_co_ord() */

/**
 * This tells us if the co-ordinates were set or if they were calculated.
 * If they were set with set_co_ord then the value of this will be 0
 * otherwise it will be 1.
 * @return 1 if it is calculated, 0 if it is not
 * @see query_co_ord()
 * @see set_co_ord()
 */
int query_co_ord_calculated() { return co_ord_calculated; }

/**
 * This returns the long exit string.  This is calculated when it is
 * first needed by the calc_long_exit function.
 * @return the long exit string
 * @see calc_long_exit()
 * @see long()
 */
string query_long_exit() { return long_exit; }

/**
 * This method creates the long exit description used in the room long
 * descriptions.
 * @see query_long_exit()
 */
void calc_long_exit() {
    string *words;
    int i, add;
    mixed tmp;

    words = ({ });

    for( i = 0; i < sizeof( dest_other ); i += 2 ) {
        tmp = dest_other[ i + 1 ][ ROOM_OBV ];
        if( !tmp )
            continue;
        if( intp( tmp ) && tmp )
            add = 1;
        if( stringp( tmp ) )
            add = (int)call_other( TO, tmp, dest_other[ i ] );
        if( pointerp( tmp ) )
            add = (int)call_other( tmp[ 0 ], tmp[ 1 ], dest_other[ i ] );
        if( add ) {
            words += ( dest_other[i+1][ROOM_REL] ?
                ({"$R$-"+dest_other[ i ]+"$R$"}) : ({ dest_other[i] }) );
        }
    }

    switch( sizeof( words ) ) {
      case 0 :
        long_exit = "There are no obvious exits.";
      break;
      case 1 :
        long_exit = "There is one obvious exit: "+words[ 0 ]+".";
      break;
      default :
        long_exit = "There are "+query_num( sizeof( words ), 0 )+" obvious "
                    "exits: "+query_multiple_short( words )+".";
    }

} /* calc_long_exit() */

/**
 * This method returns the current exit aliases for the room.
 * @return the exit aliases of the room
 * @see add_alias()
 * @see remove_alias()
 */
string *query_aliases() { return query_property("exit aliases") || ({ }); }

/**
 * This method adds an exit alias to the room.
 * Aliases are convenient extra forms that can be attached to certain
 * exits. In the above functions, the variable names is either a string
 * or an array of strings and is, respectively, the alias or aliases
 * for the direction passed in. Since, sometimes, the same alias
 * could be used for more than one exit, remove_alias() requires both
 * alias(es) and direction in order to remove the correct alias(es).
 * @param names the aliases to add
 * @param direc the direction name to alias them to
 * @see query_aliases()
 * @see remove_alias()
 * @example
 * add_exit("north", PATH +"dining_hall", "corridor");
 * add_alias( ({"enter", "enter hall", "enter dining hall"}), "north");
 * @example
 * add_exit("board carriage", PATH+"carriage", "door");
 * add_alias("board", "board carriage");
 */
void add_alias( mixed names, string direc ) {
    if( stringp(names) ) {
        string *aliases;

        if( !stringp(direc) )
            error("No direction to alias to.\n");

        aliases = query_aliases() + ({ direc, names });

        if( objectp( DOOR ) )
            DOOR->add_alias(names);

        add_property("exit aliases", aliases );

    } else if( pointerp( names ) ) {
        foreach( string name in names )
            add_alias( name, direc );
    } else {
        error("Alias not a string nor an array.\n");
    }

    if( find_call_out("calc_exits" ) == -1 )
        call_out("calc_exits", 1 );

} /* add_alias() */

/**
 * This method removes the exit aliases from the room.
 * Aliases are convenient extra forms that can be attached to certain
 * exits. In the above functions, the variable names is either a string
 * or an array of strings and is, respectively, the alias or aliases
 * for the direction passed in. Since, sometimes, the same alias
 * could be used for more than one exit, remove_alias() requires both
 * alias(es) and direction in order to remove the correct alias(es).
 * @param names the aliases to remove
 * @param direc the direction they were aliased to
 * @see add_alias()
 * @see query_aliases()
 * @example
 * remove_exit("board carriage");
 * remove_alias("board", "board carriage");
 */
void remove_alias( mixed names, string direc ) {
    string *aliases;

    if( !sizeof( aliases = query_aliases() ) )
        return;

    if( pointerp( names ) ) {
        foreach( string name in names )
            remove_alias( name, direc );
    } else {
        int i = sizeof( aliases );

        while( ( i -= 2 ) > -1 )
            if( aliases[ i ] == direc && aliases[ i + 1 ] == names )
                aliases = delete( aliases, i, 2 );

        if( sizeof(aliases) )
            add_property("exit aliases", aliases );
        else
            remove_property("exit aliases");

    }

} /* remove_alias() */

/**
 * This returns the current array of exits.
 * @return the exits array
 * @see add_exit()
 * @see remove_exit()
 * @see modify_exit()
 * @see reset_exits()
 */
string *query_exits() { return copy(exits); }

/**
 * This method removes all the current exits in the room.
 * @see add_exit()
 * @see remove_exit()
 * @see modify_exit()
 */
void reset_exits() { exits = ({ }); }

/**
 * This returns the information about the door in the specified direction.
 * @param direc the direction to query the door in
 * @return the door control information
 * @see modify_exit()
 */
varargs mixed query_door_control( string direc ) {
    return ( !stringp( direc ) ? copy(door_control) : DOOR );
} /* query_door_control() */

/**
 * This returns information about the exits in the room.  This is the
 * information set by modify_exit().  The values from this are probably
 * not very useful for normal coding.
 * @see modify_exit()
 * @see query_dest_dir()
 */
varargs mixed query_dest_other( string direc ) {
    int i;

    if( !stringp( direc ) )
        return copy( dest_other );

    if( ( i = member_array( direc, dest_other ) ) == -1 )
        return 0;

    return copy( dest_other[ i + 1 ] );

} /* query_dest_other() */

/**
 * Returns an array containing just the destinations and directions used to
 * get there. This is useful for monster or whatever that you want to scan a
 * room for exits to leave out of. The array is of the format. ({ direction1,
 * destination1, direction2, destination2, ... })
 * <p>
 * The thing passed in is used as the basis for the relative directions
 * if it is an object.  If it is not an object then this is ignored
 * altogether.
 * @see query_dest_other()
 * @see add_exit()
 * @param thing used to get the relative directions according to thing
 * @return the array of direction, destination pairs
 */
varargs string *query_dest_dir( object thing ) {
    int i;
    string *ret;

    ret = ({ });

    for( i = sizeof( dest_other ) - 2; i > -1; i -= 2 ) {
        if( !dest_other[ i + 1 ][ ROOM_REL ] || !objectp( thing ) )
            ret += ({ dest_other[ i ], dest_other[ i + 1 ][ ROOM_DEST ] });
        else
            ret += ({ (string)thing->find_rel( dest_other[ i ] ),
                      dest_other[ i + 1 ][ ROOM_DEST ] });
    }

    return ret;

} /* query_dest_dir() */

/**
 * This method returns a mapping of all obvious exits and destinations
 * in this room in the form of ([ "direction" : destination ]).
 * Exits with function pointers as destinations are ignored.
 * This is used for calculating wander destinations for NPCs.
 * @return a mapping of obvious exits and destinations
 */
mapping query_dest_dir_mapping() {
    mapping ret;
    int i;

    ret = ([ ]);

    for( i = sizeof( dest_other ) - 2; i > -1; i -= 2 ) {
        if( !dest_other[i+1][ROOM_REL] && dest_other[i+1][ROOM_OBV] &&
            !functionp( dest_other[i+1][ROOM_DEST] ) ) {
            if( TO->query_terrain() )
                TO->set_destination( dest_other[i] );
            if( dest_other[i+1][ROOM_DEST] != VOID_ROOM )
                ret[ dest_other[i] ] = dest_other[i+1][ROOM_DEST];
        }
    }

    return ret;

} /* query_dest_dir_mapping() */

/**
 * This method just returns all the directions available to leave from
 * the room.
 * <p>
 * The thing passed in is used as the basis for the relative directions
 * if it is an object.  If it is not an object then this is ignored
 * altogether.
 * <p>
 * <b>Strawberries</b>
 * <p>
 * Starting from a above,<br>
 * Working slowly down under.<br>
 * Sliding up the sides<br>
 * Eating a meal, fresh cream and syrup.<br>
 * <p>
 * Round and round, and round again<br>
 * Grining micheviously<br>
 * One tongue at play<br>
 * Firm and hard, fresh strawberries today.
 *
 * @see query_dest_other()
 * @see add_exit()
 * @param thing used to get the relative directions according to thing
 * @return the array of directions
 */
varargs string *query_direc( object thing ) {
    int i;
    string *ret;

    ret = ({ });

    for( i = sizeof( dest_other ) - 2; i > -1; i -= 2 ) {
        if( !dest_other[ i + 1 ][ ROOM_REL ] || !objectp( thing ) )
            ret += ({ dest_other[ i ] });
        else
            ret += ({ (string)thing->find_rel( dest_other[ i ] ) });
    }

    return ret;

} /* query_direc() */

/**
 * This method returns the destination room for an exit.
 * @param exit the exit name
 * @return the path of the destination room, or ROOM_VOID on error
 * @see query_dest_dir()
 * @example
 * mixed dest;
 *
 * dest = room->query_destination("south");
 * if( functionp(dest) )
 *     return;
 * if( dest == VOID_ROOM ) {
 *     do_error();
 * } else {
 *     do_move("south");
 * }
 */
mixed query_destination( string exit ) {
    int i;

    i = member_array( exit, dest_other );

    if( i == -1 && objectp( TP ) )
        i = member_array( (string)TP->reorient_rel( exit ), dest_other );

    if( i == -1 )
        return VOID_ROOM;

    return dest_other[ i + 1 ][ ROOM_DEST ];

} /* query_destination() */

/**
 * This method queries the size of the room.  The default size of a room
 * is 10x10x10.  A room can be any rectangular size, this method will return
 * an array of three elements if the room is a non-cube.  If it returns
 * a single number then the room is assumed to be cubic.
 * <p>
 * ({ north-south size, east-west size, up-down size })
 * <p>
 * The sizes are all radii's so they are half the actual width of the room.
 * @return the size of the room
 * @see set_room_size()
 * @see query_room_size_array()
 */
mixed query_room_size() {
    mixed room_size;

    return ( !( room_size = query_property("room size") ) ? 10 : room_size );
} /* query_room_size() */

/**
 * This method returns the size of the room as a three element array always.
 * <p>
 * ({ north-south size, east-west size, up-down size })
 * <p>
 * The sizes are all radii's so they are half the actual width of the room.
 * @return the size of the room as a three element array
 * @see query_room_size()
 * @see set_room_size()
 */
int *query_room_size_array() {
    mixed room_size;

    return ( pointerp( room_size = query_room_size() ) ? room_size :
          ({ room_size, room_size, room_size }) );
} /* query_room_size_array() */

/**
 * This method sets the rooms principle radii.  If the parameter isa single
 * number then the room is assumed to be cubic and dimension applies in
 * all directions.  If the input is a three element array then the elements
 * apply to all the directions.<br>
 * ({ north-south size, east-west size, up-down size })
 * <p>
 * The sizes are all radii's so they are half the actual width of the room.
 * @param number the new size of the room
 * @see query_room_size()
 * @see query_room_size_array()
 */
void set_room_size( mixed number ) {
    if( intp( number ) ) {
        add_property("room size", number );
        return;
    }

    if( pointerp( number ) && sizeof( number ) == 3 ) {
        add_property("room size", number );
        return;
    }

    write("Room size must be an integer or an array of three integers.\n");

} /* set_room_size() */

/** @ignore yes */
string expand_alias( string word ) {
    string *aliases;
    int i;

    if( !sizeof( aliases = query_aliases() ) )
        return word;

    if( ( i = member_array( word, aliases ) ) == -1 )
        return word;

    return ( i % 2 ? aliases[ i - 1 ] : word );

} /* expand_alias() */

/**
 * This method returns the exit string used when in brief mode.
 * @return the brief exit string
 * @see calc_exit_string()
 */
string calc_short_exit_string() {
    int i, add;
    string *words;
    mixed tmp;

    words = ({ });

    for( i = 0; i < sizeof( dest_other ); i += 2 ) {
        tmp = dest_other[ i + 1 ][ ROOM_OBV ];
        if( !tmp )
            continue;
        if( intp( tmp ) && tmp )
            add = 1;
        if( stringp( tmp ) )
            add = (int)call_other( TO, tmp, dest_other[ i ] );
        if( pointerp( tmp ) )
            add = (int)call_other( tmp[ 0 ], tmp[ 1 ], dest_other[ i ] );
        if( add ) {
            if( tmp = SHORTEN[ dest_other[ i ] ] ) { // is there a short form?
                if( dest_other[i+1][ROOM_REL] ) // is the exit relative
                    words += ({ "$r$-"+tmp+"$r$" });
                else
                    words += ({ tmp });
            } else { // no short form
                if( dest_other[i+1][ROOM_REL]) // is the exit relative?
                    words += ({ "$r$-"+dest_other[ i ]+"$r$" });
                else
                    words += ({ dest_other[i] });
            }
        }
    }

    return ( !sizeof(words) ? " [none]" : " ["+ implode( words, "," ) +"]" );

} /* calc_short_exit_string() */

/**
 * This method returns the short exit string.  The short exit string is the
 * string used in 'brief' mode of a players look.
 * @return the short exit string
 * @see calc_short_exit_string()
 * @see query_exit_string()
 */
string query_short_exit_string() {
    string tmp;

    if( short_exit )
        return TP->colour_event("exits", "%^GREEN%^") +
                   short_exit + "%^RESET%^";

    tmp = calc_short_exit_string();

    if( !query_property("no exit cache") )
        short_exit = tmp;

    return TP->colour_event("exits", "%^GREEN%^")+tmp+"%^RESET%^";

} /* query_short_exit_string() */

/**
 * This method calculates the co-ordinates of this room.  The co-ordinates
 * are based on the surrounding rooms co-ordinates, if one of those rooms
 * are loaded.
 * @see query_co_ord()
 * @see modify_exit()
 */
void calc_co_ord() {
    int i, j, k, shift, *delta, *other_co_ord;
    mixed other;

    for( i = sizeof( dest_other ) - 2; i > -1 && !co_ord; i -= 2 ) {
        // If destination isn't loaded or isn't a string, skip it.
        if( !stringp( other = dest_other[ i + 1 ][ ROOM_DEST ] ) ||
            !find_object( other ) )
            continue;

        // If destination has no coordinates, skip it.
        other_co_ord = (int *)other->query_co_ord();
        if( !other_co_ord )
            continue;

        // If exit had a delta defined, use that.
        j = -1;
        if( delta = dest_other[ i + 1 ][ ROOM_DELTA ] ) {
            co_ord = copy( other_co_ord );
            if( pointerp(delta)) {
                k = 3;
                while ( k-- ) {
                    /*
                     * it's -= to make delta here the offset from this
                     * room to the destination
                     */
                    co_ord[ k ] -= delta[ k ];
                }
                continue;
            } else {
                j = member_array( delta, STD_ORDERS );
            }
        }

        // If the exit isn't a direction, skip it.
        if( j == -1 ) {
            j = member_array( dest_other[ i ], STD_ORDERS );
            if( j == -1 )
                continue;
        }

        co_ord = copy( other_co_ord );
        delta = query_room_size_array()+(int *)other->query_room_size_array();

        for( k = 0; k < 3; k++ ) {
            co_ord[ k ] += STD_ORDERS[ j + 1 ][ k ] *
                ( delta[ k ] + delta[ k + 3 ] );
        }

        if( j < 16 && dest_other[ i + 1 ][ ROOM_GRADE ] ) {
            // One of the lateral directions.
            switch( j ) {
              case 0 .. 1 :
                shift = delta[ 0 ] + delta[ 3 ];
                break;
              case 2 .. 3 :
                shift = delta[ 1 ] + delta[ 4 ];
                break;
              default :
                shift = delta[ 0 ] + delta[ 1 ] + delta[ 3 ] + delta[ 4 ];
            }
            co_ord[ 2 ] -= ( dest_other[ i + 1 ][ ROOM_GRADE ] * shift ) / 100;
        }
        co_ord_calculated = 1;
    }

} /* calc_co_ord() */

/**
 * This method calculates all the exit strings to be used for this room.
 */
void calc_exits() {
    int i;
    string exit, str, *aliases;

    exits = ({ });
    aliases = query_aliases();
    i = sizeof( dest_other );

    while( ( i -= 2 ) > -1 ) {
        int j = 0;

        exit = dest_other[ i ];

        if( member_array( exit, exits ) == -1 ) {
            exits += ({ exit });
            if( stringp( str = SHORTEN[ exit ] ) )
                exits += ({ str });
        }

        while( ( j = member_array( exit, aliases, j ) ) != -1 ) {
            if( !( j % 2 ) ) {
                str = aliases[ j + 1 ];
                if( member_array( str, exits ) == -1 )
                    exits += ({ str });
            }
            j++;
        }
    }

} /* calc_exits() */

/**
 * This method determines if there is an exit in the specified direction.
 * @param direc the exit to test for
 * @return 1 if it exists, 0 if it does now
 */
int query_exit( string direc ) {
    return member_array( direc, dest_other ) != -1;
} /* query_exit() */

/**
 * This method adds an exit to the room.   The direction is the direction in
 * which the exit should go.  This is something like "north" or "enter
 * gate".  The destination field is where the player will go when they
 * enter the exit.  The type is a set type that sets a whole bunch of
 * defaults for the room.
 *
 * The destination can be either a string, an object or a function pointer,
 * which will be evaluated when someone tries to go through it (with a
 * single argument - the thing trying to move), and which should return
 * the destination room we want it to use.  If using cloned rooms, make
 * sure to clean them up if the function is evaluated, but no-one ends
 * up moving into the room.
 * <p>
 * The types are controlled by /handlers/room_handler.c and the current
 * types and what this all means are:
 * <dl>
 * <dd>
 * <dl>
 * <dt>path
 * <dd>A narrower path (this is the default exit type).
 * <dt>road
 * <dd>A wide road.
 * <dt>plain
 * <dd>A very large expanse of land.
 * <dt>door
 * <dd>An exit with a door.  Defaults to closed but not locked.
 * <dt>gate
 * <dd>An exit with a gate which is larger than a regular door.
 * Defaults to closed but not locked.
 * <dt>secret
 * <dd>A secret door.  Defaults to closed but not locked.
 * <dt>window
 * <dd>A window.
 * <dt>corridor
 * <dd>A corridor.
 * <dt>stair
 * <dd>Stairs.
 * <dt>hidden
 * <dd>A hidden exit without a door.
 * </dl>
 * </dl>
 * <p>
 * The room aliases are used to expand things for exits.  However they
 * don't expand the entire exit name.  They expand it in bits.  For
 * instance, if the exit was "enter live eel", you could
 * add_alias("eel", "live eel"); and add_alias("bing", "enter"); to
 * get both of the bits of the exit.  So "bing eel", "enter eel",
 * "bing live eel" etc would work.
 * @example
 * add_exit("north", PATH + "market2", "road");
 * add_alias("eel", "live eel");
 * add_exit("enter live eel", PATH + "live_eel", "secret");
 * @example
 * object fluffy_room;
 *
 * fluffy_room = clone_object(PATH + "fluffy_room");
 * add_exit("north", fluffy_room, "road");
 * @see modify_exit()
 * @see query_dest_dir()
 * @see remove_exit()
 * @see /handlers/room_handler
 */
varargs int add_exit( string direc, mixed dest, string type ) {
    mixed stuff;

    if( !type )
        type = "path";

    if( !dest_other )
        dest_other = ({ });

    if( member_array( direc, dest_other ) != -1 )
        return 0;

    if( objectp( dest ) )
        dest = file_name( dest );

    if( stringp(dest) && dest[0] != '/' )
        dest = "/"+ dest;

    stuff = ({ dest }) + (mixed)ROOM_H->query_exit_type( type, direc );
    dest_other += ({ direc, stuff });
    stuff = (mixed)ROOM_H->query_door_type( type, direc, dest );

    if( stuff ) {
        if( functionp( dest ) )
            error("Cannot use a function pointer as a destination room "
                "with a door type exit.\n");
        load_object(dest);
        DOOR = (object)ROOM_H->get_door();
        DOOR->setup_door( direc, TO, dest, stuff, type );
        add_hidden_object( DOOR );
        door_control[ dest ] = direc;
    }

    if( find_call_out("calc_exits") == -1 )
        call_out("calc_exits", 1 );

    long_exit = 0;
    short_exit = 0;

    return 1;

} /* add_exit() */

/**
 * This method modifies the parameters for the exit.  See the docs in
 * /doc/new/room/modify_exit for more complete information.
 */
int modify_exit( mixed direc, mixed data ) {
    int i, j;

    if( pointerp(direc) ) {
        foreach( mixed dir in direc )
            modify_exit( dir, data );
        return 0;
    }

    if( ( i = member_array( direc, dest_other ) ) == -1 )
        return 0;

    for( j = 0; j < sizeof( data ); j+= 2 ) {
        switch( lower_case( data[j] ) ) {
        case "message" :
          dest_other[i+1][ROOM_EXIT] = data[j+1];
        break;
        case "exit mess" :
          dest_other[i+1][ROOM_EXIT] = data[j+1];
        break;
        case "move mess" :
          dest_other[i+1][ROOM_MESS] = data[j+1];
        break;
        case "linker mess" :
          dest_other[i+1][ROOM_LINK_MESS] = data[j+1];
        break;
        case "obvious" :
          dest_other[i+1][ROOM_OBV] = data[j+1];
          if( !intp( data[j+1] ) )
              add_property("no exit cache", 1 );
          long_exit = 0;
          short_exit = 0;
        break;
        case "function" :
          dest_other[i+1][ROOM_FUNC] = data[j+1];
        break;
        case "size" :
          dest_other[i+1][ROOM_SIZE] = data[j+1];
        break;
        case "upgrade" :
          dest_other[i+1][ROOM_GRADE] = data[j+1];
        break;
        case "downgrade" :
          dest_other[i+1][ROOM_GRADE] = -data[j+1];
        break;
        case "enter" :
          dest_other[i+1][ROOM_ENTER] = data[j+1];
        break;
        case "enter mess" :
          if( sizeof( dest_other[i+1][ROOM_ENTER] ) == 2 )
              dest_other[i+1][ROOM_ENTER] = replace( data[j+1],
                  "$F", dest_other[i+1][ROOM_ENTER][1] );
          else
              dest_other[i+1][ROOM_ENTER] = data[j+1];
        break;
        case "dest" :
          dest_other[i+1][ROOM_DEST] = data[j+1];
          if( objectp( DOOR ) ) {
              if( functionp( data[j+1] ) )
                  error("Cannot use a function pointer with a door.");
              DOOR->set_dest( data[j+1] );
              door_control[data[j+1]] = direc;
          }
        break;
        case "relative" :
          dest_other[i+1][ROOM_REL] = data[j+1];
        break;
        case "look" :
          dest_other[i+1][ROOM_LOOK] = data[j+1];
        break;
        case "look func" :
          dest_other[i+1][ROOM_LOOK_FUNC] = data[j+1];
        break;
        case "no map" :
          dest_other[i+1][ROOM_NO_MAP] = data[j+1];
        break;
        case "delta" :
          dest_other[i+1][ROOM_DELTA] = data[j+1];
        break;
        case "no follow" :
          dest_other[i+1][ROOM_NO_FOLLOW] = data[j+1];
        break;
        case "closed" :
          if( objectp( DOOR ) ) {
              if( data[j+1] )
                  DOOR->set_closed();
              else
                  DOOR->set_open();
          }
        break;
        case "open" :
          if( objectp( DOOR ) ) {
              if( data[j+1] )
                  DOOR->set_open();
              else
                  DOOR->set_closed();
          }
        break;
        case "transparent" :
          if( objectp( DOOR ) ) {
              if( data[j+1] )
                  DOOR->set_transparent();
              else
                  DOOR->reset_transparent();
          }
        break;
        case "stuck" :
          if( objectp( DOOR ) )
              DOOR->set_stuck( data[j+1] );
        break;
        case "locked" :
          if( objectp( DOOR ) ) {
              if( data[j+1] ) {
                  DOOR->set_closed();
                  DOOR->set_locked();
              } else
                  DOOR->set_unlocked();
          }
        break;
        case "unlocked" :
          if( objectp( DOOR ) ) {
              if( data[j+1] )
                  DOOR->set_unlocked();
              else
                  DOOR->set_locked();
          }
        break;
        case "autolock":
          if( objectp( DOOR ) )
              DOOR->set_autolock( data[j+1] );
        break;
        case "key" :
          if( objectp( DOOR ) )
              DOOR->set_key( data[j+1] );
        break;
        case "other" :
          if( objectp( DOOR ) )
              DOOR->set_other_id( data[j+1] );
        break;
        case "difficulty" :
          if( objectp( DOOR ) )
              DOOR->set_difficulty( data[j+1] );
        break;
        case "unlockable" :
          if( objectp( DOOR ) )
              DOOR->set_unlockable( data[j+1] );
        break;
        case "door long" :
          if( objectp( DOOR ) )
              DOOR->set_long( data[j+1] );
        break;
        case "open/close func" :
          if( objectp( DOOR ) )
              DOOR->set_open_trap( data[j+1][0], data[j+1][1] );
        break;
        case "lock/unlock func" :
          if( objectp( DOOR ) )
              DOOR->set_lock_trap( data[j+1][0], data[j+1][1] );
        break;
        case "door short" :
          if( objectp( DOOR ) )
              DOOR->set_short( data[j+1] );
        break;
        case "double doors" :
          if( objectp( DOOR ) )
              DOOR->set_how_many( data[j+1] );
        break;
        case "one way" :
          if( objectp( DOOR ) )
              DOOR->set_one_way( data[j+1] );
        break;
        case "secret" :
          if( objectp( DOOR ) ) {
              DOOR->remove_hide_invis("secret");
              if( data[j+1] > 0 )
                  DOOR->add_hide_invis("secret", 0, data[j+1], 0 );
          }
        break;
        case "undoor" :
          if( objectp( DOOR ) ) {
              DOOR->go_away();
              remove_hidden_object( DOOR );
              map_delete( door_control, direc );
              map_delete( door_control, dest_other[i+1][ROOM_DEST] );
          }
        break;
        default:
          tell_room( TO, "Error : No '"+data[j]+"' parameter in "
              "modify_exit().\n");
        }
    }

    return 1;

} /* modify_exit() */

/**
 * This method removes the specified exit from the room.
 * @see add_exit()
 * @see modify_exit()
 */
int remove_exit( string direc ) {
    int i;

    if( !dest_other ) {
        dest_other = ({ });
        return 0;
    }

    if( ( i = member_array( direc, dest_other ) ) == -1 )
        return 0;

    if( DOOR ) {
        remove_hidden_object( DOOR );
        if( !ROOM_H->recycle_door( DOOR ) )
            DOOR->dest_me();
        map_delete( door_control, direc );
        map_delete( door_control, dest_other[ i + 1 ][ ROOM_DEST ] );
    }

    dest_other = delete( dest_other, i, 2 );

    if( find_call_out("calc_exits" ) == -1 )
        call_out("calc_exits", 1 );

    long_exit = 0;
    short_exit = 0;

    return 1;

} /* remove_exit() */

/**
 * This method checks to see if the door is open.
 * @param direc the direction of the door
 * @return -1 on an error, 0 for closed, 1 for open
 * @see modify_exit()
 */
int query_door_open( string direc ) {
    return ( !objectp( DOOR ) ? -1 : (int)DOOR->query_open() );
} /* query_door_open() */

/**
 * This method checks to see if the exit is a relative one.
 * @param direc the direction to check
 * @see modify_exit()
 */
int query_relative( string direc ) {
    int i;

    if( ( i = member_array( direc, dest_other ) ) == -1 )
        return 0;

    return dest_other[ i + 1 ][ ROOM_REL ];

} /* query_relative() */

/** @ignore yes */
string query_look( string direc ) {
    int i;

    if( ( i = member_array( direc, dest_other ) ) == -1 )
        return 0;

    if( !dest_other[ i + 1 ] )
        return 0;

    return (string)evaluate(dest_other[ i + 1 ][ ROOM_LOOK ]);

} /* query_look() */

/** @ignore yes */
mixed query_look_func( string direc ) {
    int i;

    if( ( i = member_array( direc, dest_other ) ) == -1 )
        return 0;

    if( !dest_other[ i + 1 ] )
        return 0;

    return dest_other[ i + 1 ][ ROOM_LOOK_FUNC ];

} /* query_look() */

/**
 * This method returns the size of the exit.  This is used to check to make
 * sure that people can enter it.
 * @param direc the direction of the exit to check
 * @return the size of the exit
 * @see modify_exit()
 */
int query_size( string direc ) {
    int i;

    if( ( i = member_array( direc, dest_other ) ) == -1 )
        return 0;

    if( stringp( dest_other[ i + 1 ][ ROOM_SIZE ] ) )
        return (int)call_other( TO, dest_other[ i + 1 ][ ROOM_SIZE ] );

    if( pointerp( dest_other[ i + 1 ][ ROOM_SIZE ] ) )
        return (int)call_other( dest_other[ i + 1 ][ ROOM_SIZE ][ 0 ],
               dest_other[ i + 1 ][ ROOM_SIZE ][ 1 ] );

    return dest_other[ i + 1 ][ ROOM_SIZE ];

} /* query_size() */

/** @ignore yes */
void tell_door( string direc, string message, object thing ) {
    if( objectp( DOOR ) )
        DOOR->tell_door( message, thing );
} /* tell_door() */

/** @ignore yes */
varargs mixed call_door( string direc, string func, mixed arg1, mixed arg2,
                         mixed arg3 ) {
    if( objectp( DOOR ) )
        return (mixed)call_other( DOOR, func, arg1, arg2, arg3 );
} /* call_door() */

/**
 * This method determines if the specified exit is a door or not.
 * @param dest the destination to check for being a door
 * @see query_exit()
 * @see add_exit()
 */
string query_door( mixed dest ) {
    int i;
    string direc;
    mixed bing;

    if( objectp( dest ) )
        dest = file_name( dest );

    if( !stringp( dest ) )
        return 0;

    if( bing = door_control[ dest ] )
        if( !objectp( bing ) )
            direc = bing;

    if( !direc )
        return 0;

    if( objectp( bing = DOOR ) )
        return direc;

    bing = (object)ROOM_H->get_door();
    i = member_array( direc, dest_other );
    bing->setup_door( direc, TO, dest, dest_other[ i + 1 ] );
    add_hidden_object( bing );
    DOOR = bing;

    return direc;

} /* query_door() */

/**
 * Returns the current enchantment level of the room.  The enchanment
 * level controls things like what happens when you flip coins and
 * some special messages which give wizards some idea about magic
 * levels.
 * @return the current enchantment
 * @see set_enchant()
 */
int query_enchant() {
    int enchant_level =  to_int( floor( 0.5 + dynamic_enchant *
        exp( -0.693 * ( time() - enchant_time ) / ENCHANT_HALF)) +
        background_enchant );

    return ( enchant_level > 5000 ? 5000 : enchant_level );

} /* query_enchant() */

/**
 * Sets the current enchantment level of the room.  The enchanment
 * level controls things like what happens when you flip coins and
 * some special messages which give wizards some idea about magic
 * levels.
 * When called from the room itself, it sets a background level of
 * enchantment that don't decay, when called from another object it
 * sets the current enchantment which then decays towards the background
 * level.
 * @param number the new enchantment level to set
 * @see query_enchant()
 */
int set_enchant(int number) {
    number = ( number < 0 ? 0 : number );

    if( PO == TO ) {
        /* setting up the background enchantment */
        background_enchant = (float) number;
        dynamic_enchant = 0.0;
        enchant_time = time();
    } else {
        /* by design, this can result in negative dynamic enchantment
         * it is definitely possible to suck out all magic in an area,
         * but it'll seep back in if the background level is higher.
         */
        dynamic_enchant = number - background_enchant;
        enchant_time = time();
    }
    return number;
} /* set_enchant() */

/**
 * Adds number to the current enchantment level of the room.
 * The enchanment level controls things like what happens when you
 * flip coins and some special messages which give wizards some
 * idea about magic levels.
 * @param number the new enchantment level to set
 * @see query_enchant()
 */
int add_enchant( int number ) {
    dynamic_enchant = dynamic_enchant * exp( -0.693 *
           ( time() - enchant_time ) / ENCHANT_HALF ) + number;
    enchant_time = time();
    return floor( 0.5 + dynamic_enchant ) + background_enchant;
} /* add_enchant() */

/**
 * This method sets the background enchantment of the room.
 * @return the theft handler of the room
 * @see set_enchant()
 */
void set_background_enchant( int number ) {
    background_enchant = number;
} /* set_background_enchant() */

/**
 * This method sets the current dynamic enchantment of the room.
 * @return the theft handler of the room
 * @see set_enchant()
 */
void set_dynamic_enchant( float number ) {
    dynamic_enchant = number;
    enchant_time = time();
} /* set_dynamic_enchant() */

/**
 * This method returns the background enchantment of the room.
 * @return the theft handler of the room
 * @see query_enchant()
 */
int query_background_enchant() {
    return background_enchant;
} /* query_background_enchant() */

/**
 * This method returns the current dynamic enchantment of the room.
 * @return the theft handler of the room
 * @see query_enchant()
 */
float query_dynamic_enchant() {
    dynamic_enchant = dynamic_enchant * exp( -0.693 *
           ( time() - enchant_time ) / ENCHANT_HALF );
    enchant_time = time();
    return dynamic_enchant;
} /* set_dynamic_enchant() */

/** @ignore yes */
string enchant_string() {
    string words;

    words = (string)TO->query_property( "octarine_mess" );
    if( words )
        return words+"\n";
    switch( query_enchant() ) {
    case 0 .. 49 :
        return "";
    case 50 .. 149 :
        return "There is the residual taste of magic in this place.\n";
    case 150 .. 299 :
        return "This place has seen some use of magic.\n";
    case 300 .. 499 :
        return "A considerable amount of magic has been used here.\n";
    case 500 .. 749 :
        return "A very large quantity of magic has been manipulated here.\n";
    case 750 .. 1000 :
        return "You can feel the Dungeon Dimensions trying to push in.\n";
    case 1001 .. 1500 :
        return "Little sparks flash in from the Dungeon Dimensions.\n";
    case 1501 .. 2000 :
        return "Apparations of things with lots of tentacles seem to be "
        "on the edge of your vision.\n";
    default :
        return "So much magic has been expended here that the area is in "+
        "danger of dumping itself into the Dungeon Dimensions.\n";
    }
} /* enchant_string() */

/** @ignore yes */
void event_magic( object channel, int amount, object caster ) {
    add_enchant( amount / 5 );
} /* event_magic() */

/** @ignore yes */
int id( string word ) { return 0; }

/** @ignore yes */
string long( string word, int dark ) {
    int day_time;
    string ret;
    mixed bit;

    if( !long_exit )
        calc_long_exit();

    if( dark ) {
        ret = ( dark < 0 ? TO->query_dark_mess() :
                           TO->query_bright_mess() )+"\n";
        if( query_property("location") == "outside")
            ret += "$weather$";
        if( ( dark == 2 ) || ( dark == -2 ) ) {
            ret = "$C$"+ a_short() +".  "+ ret +
            TP->colour_event("exits", "%^GREEN%^")+long_exit+"%^RESET%^\n";
            if( query_contents("") != "" )
                ret += TP->colour_event("inventory", "")+
                       "Some objects you can't make out are here.%^RESET%^\n";
        }
    } else {
        day_time = WEATHER_H->query_day();
        bit = ( !day_time ? query_night_long() : query_long() );
        ret = ( functionp( bit ) ? evaluate( bit, word, dark ) : bit );
        ret = ret || "Erk, this room seems to be broken.\n";
        word = calc_extra_look();
        if( stringp( word ) && word != "")
            ret += word;
        if( TP->query_see_octarine() )
            ret += enchant_string();
        if( query_property( "location" ) == "outside")
            ret += "$weather$";
        ret += TP->colour_event("exits", "%^GREEN%^")+long_exit+"%^RESET%^\n"+
            query_contents("");
    }

    if( query_property("no exit cache") )
        long_exit = 0;

    return ret;

} /* long() */

/** @ignore yes */
string pretty_short( object thing ) {
    int dark;

    if( thing )
        dark = (int)thing->check_dark( (int)TO->query_light() );

    return ::short( dark );

} /* pretty_short() */

/** @ignore yes */
void init() {
    if( chatter )
        chatter->check_chat();

    if( sitchanger )
        sitchanger->check_situations();

    if( !sizeof( exits ) )
        calc_exits();

    if( !pointerp( co_ord ) )
        TO->calc_co_ord();

    hidden_objects -= ({ 0 });
    hidden_objects->init();

    if( item )
        item->init();

} /* init() */

/**
 * This method adds a sign into the room.  Any of these elements can
 * be set to 0, except the long description.
 * @param sign_long the long description of the sign
 * @param sign_read_mess the readable message on the sign
 * @param sign_short the short description of the sign
 * @param sign_name the name of the sign - if it's an array, the first
 * member will be used for the name, and the following members are
 * added as aliases for the sign, if it's a string, no aliases will
 * be added, additionally, if the string consists of multiple words,
 * all the words before the last are added as adjectives.
 * @param sign_language the language the sign is written in
 * @example
 *     add_sign( "This is a sign.\n", "You just read a sign.",
 *               "large wooden sign", "large wooden sign", "common" );
 * @return the object for the sign
 * @see query_signs()
 * @see remove_signs()
 * @see remove_sign_by_id()
 * @see modify_sign_by_id()
 */
varargs object add_sign( string sign_long, mixed sign_read_mess, string
                         sign_short, mixed sign_name, string sign_language ) {
    object sign;
    string *str;

    sign = clone_object(OBJECT_OBJ);

    if( !sign_name )
        sign_name = "sign";

    if( pointerp(sign_name) ) {
        str = explode( sign_name[0], " " );
        sign->add_alias( sign_name[1..] );
    } else {
        str = explode( sign_name, " " );
    }

    sign->set_name( str[<1] );

    if( sizeof( str[0..<2] ) )
        sign->add_adjective( str[0..<2] );

    sign->set_long( sign_long );

    if( !sign_language )
        sign_language = "common";

    sign->set_read_mess( sign_read_mess, sign_language );
    sign->reset_get();

    if( sign_short && sign_short != "") {
        sign->set_short( sign_short );
        sign->move(TO);
        sign->add_property("there", "here");
    } else {
        add_hidden_object( sign );
    }

    if( !pointerp( signs ) )
        signs = ({ sign });
    else
        signs += ({ sign });

    return sign;

} /* add_sign() */

/**
 * This method returns all the signs that are in the room.
 * @return the sign objects added to the room via add_sign
 * @see add_sign()
 * @see remove_signs()
 * @see remove_sign_by_id()
 * @see modify_sign_by_id()
 */
object *query_signs() {
    if( !pointerp( signs ) )
        return 0;

    signs -= ({ 0 });

    return signs;

} /* query_signs() */

/** @ignore yes */
private int match_sign( object sign, string str ) {
    string *tmp, word;

    if( !sign )
        return 0;

    tmp = explode( str, " ");

    if( !sign->id( tmp[<1] ) )
        return 0;

    foreach( word in tmp[0..<2] )
      if( !sign->id_adjective( word ) )
          return 0;

    return 1;

} /* match_sign() */

/**
 * This method allows one to modify the appearance and message of the sign.
 * @param sign_id the sign to modify
 * @param sign_long the new long description of the sign
 * @param sign_read_mess the new readable message on the sign
 * @param sign_short the new short description of the sign
 * @param sign_name the new name of the sign - if it's an array, the first
 * member will be used for the name, and the following members are
 * added as aliases for the sign, if it's a string, no aliases will
 * be added, additionally, if the string consists of multiple words,
 * all the words before the last are added as adjectives.
 * @param sign_language the language the sign is written in
 * @example
 *     add_sign( "This is a sign.\n", "You just read a sign.",
 *               "large wooden sign", "large wooden sign", "common" );
 *     add_sign( "large wooden sign", "This is an updated sign.\n",
 *               "You just read the new message.", "shabby wooden sign",
 *               "shabby wooden sign" );
 * @return the object for the sign
 * @see add_sign()
 * @see query_signs()
 * @see remove_signs()
 * @see remove_sign_by_id()
 */
varargs void modify_sign_by_id( string sign_id, string sign_long,
                                mixed sign_read_mess, string sign_short,
                                mixed sign_name, string sign_language ) {
    object sign, *tmp;
    string *str;

    if( !pointerp( signs ) || !sizeof( signs -= ({ 0 }) ) )
        return;

    if( !sizeof( tmp = filter( signs,
        (: match_sign( $1, $2 ) :), sign_id ) ) )
        return;

    sign = tmp[0];

    if( sign_name ) {
        if( pointerp(sign_name) ) {
            str = explode( sign_name[0], " " );
            sign->add_alias( sign_name[1..] );
        } else {
            str = explode( sign_name, " " );
        }
        sign->set_name( str[<1] );
        if( sizeof( str[0..<2] ) ) {
            sign->remove_adjectives( sign->query_adjectives() );
            sign->add_adjective( str[0..<2] );
        }
    }

    if( sign_long && sign_long != "")
        sign->set_long( sign_long );

    if( sign_read_mess && sign_read_mess != "") {
        if( !sign_language || sign_language != "" )
            sign_language = "common";
        sign->set_read_mess( sign_read_mess, sign_language );
    }

    if( sign_short && sign_short != "") {
        sign->set_short( sign_short );
        remove_hidden_object(sign);
    }

} /* modify_sign_by_id() */

/**
 * This method removes a sign from the room based on its
 * short description.
 * @param str the short desc of the sign to remove
 * @see add_sign()
 * @see query_signs()
 * @see remove_signs()
 * @see modify_sign_by_id()
 */
void remove_sign_by_id( string str ) {
    object *remove;

    if( !pointerp( signs ) )
        return;

    if( !sizeof( signs -= ({ 0 }) ) || !sizeof( remove = filter( signs,
        (: match_sign( $1, $2 ) :), str ) ) )
        return;

    signs -= remove;

    foreach( object ob in remove ) {
        remove_hidden_object(ob);
        ob->dest_me();
    }

} /* remove_sign_by_id() */

/**
 * This method will remove all signs from the room.
 * @see add_sign()
 * @see query_signs()
 * @see remove_sign_by_id()
 * @see modify_sign_by_id()
 */
void remove_signs() {
    if( pointerp( signs ) ) {
        signs -= ({ 0 });
        foreach( object ob in signs )
            remove_hidden_object(ob);
        signs->dest_me();
        signs = ({ });
    }
} /* remove_signs() */

/** @ignore yes */
mixed stats() {
    int i;
    mixed stuff;

    stuff = ({ });

    for( i = sizeof( dest_other ) - 2; i > -1; i -= 2 )
        stuff += ({
            ({ dest_other[ i ], dest_other[ i + 1 ][ ROOM_DEST ] }),
        });

    if( co_ord )
        stuff += ({
            ({"co-ord x", co_ord[ 0 ] }),
            ({"co-ord y", co_ord[ 1 ] }),
            ({"co-ord z", co_ord[ 2 ] })
        });

    return light::stats() + property::stats() + stuff + ({
        ({"short", short() }),
        ({"theft handler", theft_handler }),
        ({"enchantment", query_enchant() }),
        ({"background enchantment", background_enchant }),
        ({"dynamic enchantment", dynamic_enchant }),
        ({"enchantment time", enchant_time }),
#ifdef FAST_CLEAN_UP
        ({"fast clean up", fast_clean_up }),
        ({"room create time", room_create_time }),
        ({"room stabilize", room_stabilize }),
        ({"heart beat", query_heart_beat() }),
#endif
    });

} /* stats() */
