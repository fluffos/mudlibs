/**
 * Inheritable for moving room - as ferry, stagecoach etc
 * @author Loriel
 */
/*
 * Uses mapping "destinations" for stops:
 * name = "from" (just a short name to track where we are)
 * destination[name]->to = next stop after 'name'
 * destination[name]->room = full path of room where "ferry" stops
 * destination[name]->room_exit = exit name from room to ferry
 * destination[name]->ferry_exit = exit name from ferry to room
 * destination[name]->transit_time = time travelling from this stop to next
 * destination[name]->wait_time = time waiting at this stop
 * destination[name]->room_leave_msg = message to room as ferry leaves
 * destination[name]->room_arrive_msg = message to room as ferry arrives
 * destination[name]->arrive_fn = fn to call in ferry as it arrives (room as arg)
 * destination[name]->leave_fn = fn to call in ferry as it leaves (room as arg)
 * destination[name]->room_arrive_fn = fn to call in room as ferry arrives
 * destination[name]->room_leave_fn = fn to call in room as ferry leaves
 * destination[name]->ferry_leave_msg = message to ferry as it leaves
 * destination[name]->ferry_arrive_msg = message to ferry as it arrives
 * start_location defines which 'from' the ferry starts from.
 * @changed Added set_carriage_object, query_carriage_object and the
 * @changed loading/unloading of carriage_object - Sandoz 19 April 2001
 * @changed Added exit/enter messages - Sandoz 20 April 2001
 * @changed Added set_movement_messages to set the messages from
 * @changed the actual carriage file - Sandoz 22 April 2001
 * ferry_exit_mess - message to the carriage when player leaves the carriage
 * ferry_move_mess - movement message to the player leaving the carriage
 * ferry_enter_mess - message to the destination room when player exits carriage
 * room_exit_mess - message to the room when player enters the carriage
 * room_move_mess - movement message to the player entering the carriage
 * room_enter_mess - message to the destination room (carriage) when player enters
 * location_prep - the preposition to use in the warning messages
 * @changed Changed to reuse the carriage object in different stops
 * - Sandoz, 31-Aug-2002.
 */

inherit ROOM_OBJ;

object carriage;

private mapping destinations = ([ ]);
private string start_location;

private int movement_warning_flag;
private int movement_warning_time;
private string arrival_warning;
private string departure_warning;
private string carriage_object;

void arrive( string where );
void depart( string where );
void depart_warning( string where );
void set_movement_warning( int arg );
void set_movement_warning_time( int warn_time );
void set_carriage_object( string path );
int query_movement_warning_time( int wait_time );
int query_movement_warning();
string query_carriage_object();

class destination {
    string to;
    string room;
    string room_exit;
    string ferry_exit;
    int transit_time;
    int wait_time;
    string room_arrive_msg;
    string room_leave_msg;
    string ferry_arrive_msg;
    string ferry_leave_msg;
    string arrive_fn;
    string leave_fn;
    string room_arrive_fn;
    string room_leave_fn;
}

class movemess {
    string ferry_exit_mess;
    string ferry_move_mess;
    string ferry_enter_mess;
    string room_exit_mess;
    string room_move_mess;
    string room_enter_mess;
    string location_prep;
}

#define DESTFN(name) ((class destination)destinations[name])

void create() {
    ::create();

    // Default warnings for Departure and Arrival to on.
    set_movement_warning(1);
    set_movement_warning_time(10);

} /* create() */

/**
 * Set the carriage object to load in the room the carriage is stopped in.
 * @param path The path of the object.
 * @example void set_carriage_object(string path)
 * @changed Created 19-04-2001 Sandoz
 */
void set_carriage_object( string path ) {
    carriage_object = path;
} /* set_carriage_object() */

/**
 * Return the path of the carriage object to load.
 * @return The object the carriage represents itself with.
 */
string query_carriage_object() { return carriage_object; }

/**
 * Set where the ferry/room starts when loaded.
 * @param loc The location to start at.
 * @example void set_start_location(string loc)
 */
void set_start_location(string loc) { start_location = loc; }

/**
 * Adds a destination (or stop) for the ferry.
 * @param name The destination to add.
 * @example void add_destination(string name)
 */
void add_destination( string name ) {
    class destination dest = new ( class destination );
    destinations[name] = dest;
} /* add_destination() */

/**
 * @ignore yes
 */
void destination_check(string name) {
    if( destinations[name] )
        return;
    error("Non-existent destination - " + name + "!\n");
} /* destination_check() */

/**
 * Sets full details of a destination/stop for ferry.
 * @param name The name of the original stop.
 * @param to Next stop after 'name'.
 * @param room Full path of the room where "ferry" stops.
 * @param room_exit Exit name from room to ferry.
 * @param ferry_exit Exit name from ferry to room.
 * @param transit_time Time travelling from this stop to next.
 * @param wait_time Time waiting at this stop.
 * @param ferry_arrive_msg Message to ferry as it arrives.
 * @param ferry_leave_msg Message to ferry as it leaves.
 * @param room_arrive_msg Message to room as ferry arrives.
 * @param room_leave_msg Message to room as ferry leaves.
 * @param arrive_fn Function to call in ferry as it arrives (room as arg).
 * @param leave_fn Function to call in ferry as it leaves (room as arg).
 * @param room_arrive_fn Function to call in room as ferry arrives.
 * @param room_leave_fn Function to call in room as ferry leaves.
 */
void set_full_details( string name, string to, string room,
                       string room_exit, string ferry_exit,
                       int transit_time, int wait_time,
                       string ferry_arrive_msg, string ferry_leave_msg,
                       string room_arrive_msg, string room_leave_msg,
                       string arrive_fn, string leave_fn,
                       string room_arrive_fn, string room_leave_fn ) {

    destination_check(name);

    DESTFN(name)->to = to;
    DESTFN(name)->room = room;
    DESTFN(name)->room_exit = room_exit;
    DESTFN(name)->ferry_exit = ferry_exit;
    DESTFN(name)->transit_time = transit_time;
    DESTFN(name)->wait_time = wait_time;
    DESTFN(name)->ferry_arrive_msg = ferry_arrive_msg;
    DESTFN(name)->ferry_leave_msg = ferry_leave_msg;
    DESTFN(name)->room_arrive_msg = room_arrive_msg;
    DESTFN(name)->room_leave_msg = room_leave_msg;
    DESTFN(name)->arrive_fn = arrive_fn;
    DESTFN(name)->leave_fn = leave_fn;
    DESTFN(name)->room_arrive_fn = room_arrive_fn;
    DESTFN(name)->room_leave_fn = room_leave_fn;

} /* set_full_destination() */

class movemess return_mess = new(class movemess);

/**
 * Sets the movement messages for the exits to and from the ferry.
 * @param ferry_exit_mess message to the carriage when player leaves the ferry
 * @param ferry_move_mess movement message to the player leaving the ferry
 * @param ferry_enter_mess message to the destination room when player exits ferry
 * @param room_exit_mess message to the room when player enters the ferry
 * @param room_move_mess movement message to the player entering the ferry
 * @param room_enter_mess message to the destination room (ferry) when player enters
 * @param location_prep the preposition to use in the warning messages
 * @changed Added by Sandoz 22 April 2001
 */
void set_movement_messages( string ferry_exit_mess, string ferry_move_mess,
                            string ferry_enter_mess, string room_exit_mess,
                            string room_move_mess, string room_enter_mess,
                            string location_prep ) {

    return_mess->ferry_exit_mess = ferry_exit_mess;
    return_mess->ferry_move_mess = ferry_move_mess;
    return_mess->ferry_enter_mess = ferry_enter_mess;
    return_mess->room_exit_mess = room_exit_mess;
    return_mess->room_move_mess = room_move_mess;
    return_mess->room_enter_mess = room_enter_mess;
    return_mess->location_prep = location_prep;

} /* set_movement_messages */

/**
 * Sets subsequent stop.
 * @example void set_to(string name, string to)
 */
void set_to(string name, string to) {
    destination_check(name);
    DESTFN(name)->to = to;
} /* set_to() */

/**
 * Sets room where ferry stops.
 * @example void set_room(string name, string to)
 */
void set_room(string name, string room) {
    destination_check(name);
    DESTFN(name)->room = room;
} /* set_dest_room() */

/**
 * Sets exit shown in room when ferry stops.
 * @example void set_room_exit(string name, string room_exit)
 */
void set_room_exit(string name, string room_exit) {
    destination_check(name);
    DESTFN(name)->room_exit = room_exit;
} /* set_room_exit() */

/**
 * Sets exit shown in ferry when ferry stops.
 * @example void set_ferry_exit(string name, string ferry_exit)
 */
void set_ferry_exit(string name, string ferry_exit) {
    destination_check(name);
    DESTFN(name)->ferry_exit = ferry_exit;
} /* set_ferry_exit() */

/**
 * Sets time taken by ferry to next stop.
 * @example void set_transit_time(string name, int transit_time)
 */
void set_transit_time( string name, int transit_time ) {
    destination_check(name);
    DESTFN(name)->transit_time = transit_time;
} /* set_transit_time() */

/**
 * Sets time ferry waits at this stop.
 * @example void set_wait_time(string name, int wait_time)
 */
void set_wait_time( string name, int wait_time ) {
    destination_check(name);
    DESTFN(name)->wait_time = wait_time;
} /* set_wait_time() */

/**
 * Sets message shown in room when ferry arrives.
 * @example void set_room_arrive_msg(string name, string msg)
 */
void set_room_arrive_msg( string name, string msg ) {
    destination_check(name);
    DESTFN(name)->room_arrive_msg = msg;
} /* set_room_arrive_msg() */

/**
 * Sets message shown in room when ferry leaves.
 * @example void set_room_leave_msg(string name, string msg)
 */
void set_room_leave_msg( string name, string msg ) {
    destination_check(name);
    DESTFN(name)->room_leave_msg = msg;
} /* set_room_leave_msg() */

/**
 * Sets message shown in ferry when it arrives.
 * @example void set_ferry_arrive_msg(string name, string msg)
 */
void set_ferry_arrive_msg( string name, string msg ) {
    destination_check(name);
    DESTFN(name)->ferry_arrive_msg = msg;
} /* set_ferry_arrive_msg() */

/**
 * Sets message shown in ferry when it leaves.
 * @example void set_ferry_leave_msg(string name, string msg)
 */
void set_ferry_leave_msg( string name, string msg ) {
    destination_check(name);
    DESTFN(name)->ferry_leave_msg = msg;
} /* set_ferry_leave_msg() */

/**
 * Sets function called when it arrives.
 * @example void set_arrive_fn(string name, string fn)
 */
void set_arrive_fn( string name, string fn ) {
    destination_check(name);
    DESTFN(name)->arrive_fn = fn;
} /* set_arrive_fn() */

/**
 * Sets function called when it leaves.
 * @example void set_leave_fn(string name, string fn)
 */
void set_leave_fn( string name, string fn ) {
    destination_check(name);
    DESTFN(name)->leave_fn = fn;
} /* set_leave_fn() */

/**
 * Sets function called in room when it arrives.
 * @example void set_room_arrive_fn(string name, string fn)
 */
void set_room_arrive_fn( string name, string fn ) {
    destination_check(name);
    DESTFN(name)->room_arrive_fn = fn;
} /* set_room_arrive_fn() */

/**
 * Sets function called in room when it leaves.
 * @example void set_room_leave_fn(string name, string fn)
 */
void set_room_leave_fn( string name, string fn ) {
    destination_check(name);
    DESTFN(name)->room_leave_fn = fn;
} /* set_room_leave_fn() */

/**
 * Remove call_outs which move the ferry.
 * @example void stop_ferry()
 */
void stop_ferry() {
    remove_call_out("arrive_warning");
    remove_call_out("arrive");
    remove_call_out("depart_warning");
    remove_call_out("depart");
} /* stop_ferry() */

/** @ignore yes */
int wimpy_check( string verb, object thing, string special ) {
    if( member_array("run_away", call_stack(2) ) != -1 )
        return 0;
    return 1;
} /* wimpy_check() */

/** @ignore yes */
void depart( string from ) {
    string def_msg;
    object ob;

    ob = load_object( DESTFN(from)->room );
    ob->remove_exit( DESTFN(from)->room_exit );
    TO->remove_exit( DESTFN(from)->ferry_exit );

    if( carriage && carriage->move(CARRIAGE_OBJ) )
        carriage->dest_me();

    if( query_movement_warning() )
        call_out("arrive_warning",
            query_movement_warning_time(DESTFN(from)->transit_time), from );

    call_out("arrive", DESTFN(from)->transit_time, DESTFN(from)->to );

    def_msg = TO->short()+" has departed for "+DESTFN(from)->to+".";

    tell_room( TO, ( DESTFN(from)->ferry_leave_msg || def_msg )+"\n");
    tell_room( ob, ( DESTFN(from)->room_leave_msg || def_msg )+"\n");

    if( stringp( DESTFN(from)->leave_fn ) &&
        strlen( DESTFN(from)->leave_fn ) )
        call_other( TO, DESTFN(from)->leave_fn, ob );

    if( stringp( DESTFN(from)->room_leave_fn ) &&
        strlen( DESTFN(from)->room_leave_fn ) )
        call_other( ob, DESTFN(from)->room_leave_fn );

} /* depart() */

/** @ignore yes */
void arrive( string at ) {
    string def_msg;
    object ob;

    ob = load_object( DESTFN(at)->room );

    ob->add_exit( DESTFN(at)->room_exit, base_name(TO), "path");

    ob->modify_exit( DESTFN(at)->room_exit, ({"enter mess",
        return_mess->room_enter_mess }) );
    ob->modify_exit( DESTFN(at)->room_exit, ({"exit mess",
        return_mess->room_exit_mess }) );
    ob->modify_exit( DESTFN(at)->room_exit, ({"move mess",
        return_mess->room_move_mess }) );

    ob->modify_exit( DESTFN(at)->room_exit, ({"function",
        (: wimpy_check :) }) );

    TO->add_exit( DESTFN(at)->ferry_exit, DESTFN(at)->room, "path");

    TO->modify_exit( DESTFN(at)->ferry_exit, ({"enter mess",
        return_mess->ferry_enter_mess }) );
    TO->modify_exit( DESTFN(at)->ferry_exit, ({"exit mess",
        return_mess->ferry_exit_mess }) );
    TO->modify_exit( DESTFN(at)->ferry_exit, ({"move mess",
        return_mess->ferry_move_mess }) );

    if( carriage_object ) {
        if( !carriage )
            carriage = clone_object(carriage_object);
        carriage->move(ob);
    }

    if( query_movement_warning() )
        call_out("depart_warning",
            query_movement_warning_time( DESTFN(at)->wait_time ), at );

    call_out("depart", DESTFN(at)->wait_time, at );

    def_msg = TO->short()+" has arrived at "+at+".";

    tell_room( TO, ( DESTFN(at)->ferry_arrive_msg || def_msg )+"\n");
    tell_room( ob, ( DESTFN(at)->room_arrive_msg || def_msg )+"\n");

    if( stringp( DESTFN(at)->arrive_fn ) &&
        strlen( DESTFN(at)->arrive_fn ) )
        call_other( TO, DESTFN(at)->arrive_fn, ob );

    if( stringp( DESTFN(at)->room_arrive_fn ) &&
        strlen( DESTFN(at)->room_arrive_fn ) )
        call_other( ob, DESTFN(at)->room_arrive_fn );

} /* arrive() */

/**
 * Control the warning to the arrival/departure room about imminent
 * departures and arrivals.
 * @example void set_movement_warning( int arg )
 * @changed Created 22-02-2001 Rattmanii
 */
void set_movement_warning( int arg ) {
    if( arg )
        movement_warning_flag = 1;
} /* set_movement_warning() */

/**
 * Returns flag to say whether announce to arrival/departure room about
 * imminent departures and arrivals.
 * @return returns wether or not to announce about imminent
 * departures/arrivals
 * @changed Created 22-02-2001 Rattmanii
 */
int query_movement_warning() { return movement_warning_flag; }

/**
 * Control the time that the warning appears to the arrival/departure room.
 * @example void set_movement_warning_time( int warn_time )
 * @changed Created 22-02-2001 Rattmanii
 */
void set_movement_warning_time( int warn_time ) {
    movement_warning_time = warn_time;
} /* set_movement_warning_time() */

/**
 * Get the time that the warning is to appear to the arrival/departure
 * room in a safe format (ie, non negative).
 * @return Returns the warning time
 * @changed Created 22-02-2001 Rattmanii
 */
int query_movement_warning_time( int wait_time ) {
    int warn_time;

    if( ( warn_time = wait_time - movement_warning_time ) < 0 )
        warn_time = 0;

    return warn_time;

} /* set_movement_warning_time() */

/**
 * Send a warning to the departure room that the vehicle is about to depart.
 * @example void depart_warning( string at )
 * @changed Created 22-02-2001 Rattmanii
 * @changed Modified to use the_short() instead of short()
 * - Sandoz 19 April 2001
 * @changed Added a warning to be sent into the vehicle itself
 * - Sandoz 20 April 2001
 */
void depart_warning( string at ) {
    tell_room( load_object( DESTFN(at)->room ), TO->the_short()+" is ready "
        "to depart for "+DESTFN(at)->to+".  All aboard!\n");
    tell_room( TO, TO->the_short()+" is ready to depart for "+
        DESTFN(at)->to+".  This is your last chance to get off "+
        return_mess->location_prep+" "+at+"!\n");
} /* depart_warning() */

/**
 * Send a warning to the destination room that the vehicle is about to arrive.
 * @example void arrive_warning( string from )
 * @changed Created 22-02-2001 Rattmanii
 * @changed Changed to use a_short() instead of short()
 * - Sandoz 19 April 2001
 */
void arrive_warning( string from ) {
    tell_room( load_object( DESTFN(DESTFN(from)->to)->room ),
        TO->a_short()+" is approaching from "+from+".\n");
} /* arrive_warning() */

void dest_me() {
    if( carriage )
        carriage->dest_me();
    ::dest_me();
} /* dest_me() */

/** @ignore yes */
mixed stats() {
    mixed ret;

    ret = ({ });

    if( carriage ) {
        ret += ({ ({"carriage ob" , file_name(carriage) }) });
        if( ENV(carriage) )
            ret += ({ ({"carriage env", file_name(ENV(carriage)) }) });
    }

    return ::stats() + ret;

} /* stats() */
