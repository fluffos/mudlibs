/**
 * The login handler lets you have a funct called as a player logs in or out.
 * The funct you setup will be called when the player logs in or out.  The
 * object will also give you a list of all the people who are logged in. This is
 * a by product of its method of operation rather than anything important.
 * It is quite possibly more useful to call users().
 * <p>
 * The funct which is to be called only needs to be called once as
 * the objects state is saved.  When a player enters, logsout or goes
 * net dead the funct will be called on the specified object.  The
 * funct will have two parameters, the first will be the player
 * name logging in/out and the last will be a define from /include/login.h
 * specifying which sort of event has occured.
 * <p>
 * A new temporary method of adding a call back to the login_handler has been
 * added.  This will allow you to add a call that is not saved,
 * so you can use an object reference instead of a file name.
 * @changed Added the possibility to restrict login access - Sandoz, 2003.
 * @author Furball
 * @see /secure/login
 * @see efun::users()
 * @see /include/login.h
 */

#include <login.h>
#include <colors.h>

#define SAVE_TIME     900
#define SAVE_NAME     "/save/login_handler"
#define LOG_FILE      "/secure/log/ENTER"

#define LOCKDOWN_TIME 900
#define MAX_FAILURES  3

class login_information {
    // When saved, this can only be a string.
    // If not it can be an object of function pointer.
    mixed ob;
    // This is not used with a function pointer.
    string funct;
}

mapping _static_login_calls;
private int login_mode;
private string mud_name;

nosave mapping _dynamic_login_calls;
nosave string _best;
nosave string _worst;
nosave string *_players_on;
nosave object *_login_queue;
nosave mapping messages;
nosave mapping lockdowns;

nosave int _creators;
nosave int _players;
nosave int _login_q;
nosave int _next_user_log;
nosave int _title_call;
nosave int _save_call;
nosave int _out_q;
nosave int _q_time;

int is_discworld_full( int test_login_queue );
void save_users();
private void store_user_count();
private void log_user_count();
protected void check_all_titles( string player );
private void do_all_calls( string player, string event );
private void do_call( class login_information login_inf, string player, int event );

private void create() {
    _static_login_calls = ([ ]);
    _dynamic_login_calls = ([ ]);

    seteuid("Root");

    mud_name = mud_name();

    unguarded( (: restore_object, SAVE_NAME :) );

    // If the mud name has changed, switch to creator only mode.
    // This is useful for running a Dev mud from a backup in
    // creator only mode automatically.
    if( !mud_name || ( mud_name != mud_name() && !login_mode ) ) {
        login_mode = 2;
        mud_name = mud_name();
        unguarded( (: save_object, SAVE_NAME :) );
    }

    _players_on = map( users(), (: $1->query_name() :) );

    _login_queue = ({ });
    _save_call = call_out("save_users", SAVE_TIME );
    _next_user_log = time() + 3601 - ( time() % 3600 );

} /* create() */

/**
 * This method returns a description for the specified restriction
 * level in a string.
 * @param lvl the restriction level to return a description for
 * @return a string describing the restriction level
 */
string get_login_mode( int lvl ) {
    switch( lvl ) {
      case 0 :
        return "unrestricted mode";
      case 1 :
        return "playtester only mode";
      case 2 :
        return "creator only mode";
      default :
        return 0;
    }
} /* get_login_mode() */

/**
 * This method sets the restriction level for loggin in.
 * This can be used to restrict access to the mud at three levels.
 * 0 - unrestricted
 * 1 - restricted to playtesters
 * 2 - restricted to creators
 * @param lvl the restriction level
 * @return 1 upon success, 0 upon failure
 * @see query_login_mode()
 */
int set_login_mode( int lvl ) {
    string mess;

    if( file_name(PO) != "/secure/cmds/lord/logintool")
        return 0;

    if( lvl == login_mode ) {
        write( mud_name()+" is already running in "+
            get_login_mode(lvl)+".\n");
        return 1;
    }

    switch( lvl ) {
      case 0..2 :
        mess = RED + mud_name() + " is now running in "+
               get_login_mode( lvl ) + ".\n"+RESET;
        write(mess);
        shout(mess);
      break;
      default :
        write("Invalid restriction level.\n");
        return 0;
    }

    login_mode = lvl;
    unguarded( (: save_object, SAVE_NAME :) );
    return 1;

} /* set_login_mode() */

/**
 * This method returns our login restriction level.
 * The return value is one of the following.
 * 0 - unrestricted
 * 1 - restricted to playtesters
 * 2 - restricted to creators
 * @return 0, 1 or 2
 * @see set_login_mode()
 */
int query_login_mode() { return login_mode; }

/**
 * This method tests to see whether a specific person can
 * log on at the time.
 * @param who the name of the person trying to log in
 * @return 1 if they are allowed to log in, 0 if not
 */
int query_can_log_in( string who ) {
    switch( login_mode ) {
      case 0 :
        return 1;
      case 1 :
        return playtesterp(who);
      case 2 :
        return creatorp(who);
    }
} /* query_can_log_in() */

/** @ignore yes */
mapping query_static_login_calls() { return copy(_static_login_calls); }

/** @ignore yes */
mapping query_dynamic_login_calls() { return copy(_dynamic_login_calls); }

/**
 * This returns the player name with the best alignment.
 * @return player name with the best alignment
 */
string query_best() { return _best; }

/**
 * This returns the player name with the worst alignment.
 * @return player name with the worst alignment
 */
string query_worst() { return _worst; }

/**
 * This method returns a list of the current players who are
 * online.
 * @return the string names of the online players
 */
string *query_players_on() { return _players_on; }

/**
 * This method returns the current list of people in the login
 * queue.
 * @return the objects in the login queue
 */
object *query_login_queue() { return _login_queue; }

/**
 * This method adds an object to the login queue.  This is called from
 * inside /secure/login.c
 * @see /secure/login.c
 * @param login_ob the object to add to the queue
 */
void add_to_login_queue( object login_ob ) {
    _login_queue += ({ login_ob });
} /* add_to_login_queue() */

/**
 * This method returns the top element of the login queue and removes
 * them from it.
 * @return the top element of the login queue, 0 if none
 */
object pop_from_login_queue() {
    object ob;

    if( !sizeof(_login_queue) )
        return 0;

    if( time() != _q_time ) {
        _q_time = time();
        _out_q = 0;
    }

    _out_q++;

    // Let net dead and creators on first.
    foreach( ob in _login_queue ) {
        if( ob->query_net_dead() || creatorp(ob) ||
            ob->query_property("test character") ) {
            _login_queue = _login_queue - ({ ob });
            return ob;
        }
    }

    ob = _login_queue[0];
    _login_queue = _login_queue[1..];
    return ob;

} /* pop_from_login_queue() */

/**
 * This method removes an object from the login queue, if they log out
 * or something.
 * @param ob the object to remove from the queue
 */
void remove_from_login_queue( object ob ) { _login_queue -= ({ ob }); }

/**
 * This method adds a funct to be called whenever a player logs
 * in.  The funct and object both need to be strings so that
 * they are saved correctly.  This will be saved to the save file
 * and restored over logins.
 * <p>
 * The function will be called with two parameters, the first is the
 * name of the player and the second is the type of the event.  The
 * event types are defined in /include/login.h  The event will be one
 * of RECONNECT, LOGIN, LOGOUT, NETDEATH.
 * @param player specfic player to look for "all" for everyone
 * @param func the funct to call
 * @param obj the object to call the funct on
 * @return 0 on failure and 1 on success
 * @see remove_static_login_call()
 * @see add_dynamic_login_call()
 */
int add_static_login_call( string player, mixed funct, mixed obj ) {
    class login_information login_inf;

    if( !stringp(funct) || !stringp(obj) || !stringp(player) )
        return 0;

    // Don't allow calls to creators own files.  They invariably get left
    // behind well after their usefulness is over and cause runtime errors.
    if( obj[0..3] == "/w/")
        return 0;

    // Check for dups, we get too many of those.
    if( _static_login_calls[player] ) {
        foreach( login_inf in _static_login_calls[player] ) {
            if( login_inf->ob == obj && login_inf->funct == funct )
                return 1;
        }
    }

    if( !_static_login_calls[player] )
        _static_login_calls[player] = ({ });

    login_inf = new( class login_information, funct : funct, ob : obj );
    _static_login_calls[player] += ({ login_inf });

    catch( unguarded( (: save_object, SAVE_NAME :) ) );
    return 1;

} /* add_static_login_call() */

/**
 * This method removes a login call.
 * @param player the player specifier
 * @param funct the funct name
 * @param obj the object to call the funct on
 * @return 0 on failure and 1 on success
 * @see add_static_login_call()
 * @see add_dynamic_login_call()
 */
int remove_static_login_call( string player, mixed funct, mixed obj ) {
    class login_information login_inf;

    if( !stringp(funct) || !stringp(obj) || !stringp(player) )
        return 0;

    if( _static_login_calls[player] ) {
        foreach( login_inf in _static_login_calls[player] ) {
            if( login_inf->ob == obj && login_inf->funct == funct ) {
                _static_login_calls[player] -= ({ login_inf });

                // Clean it out if they don't have any left.
                if( !sizeof( _static_login_calls[player] ) )
                    map_delete( _static_login_calls, player );

                catch( unguarded( (: save_object, SAVE_NAME :) ) );
                return 1;
            }
        }
    }

    return 0;

} /* remove_static_login_call() */

/**
 * This method adds a funct to be called whenever a player logs
 * in.  The funct and object are stored only for this reboot
 * so they may be object references or funct pointers.
 * @param player specfic player to look for "all" for everyone
 * @param func the funct to call
 * @param obj the object to call the funct on
 * @return 0 on failure and 1 on success
 * @see remove_dynamic_login_call()
 * @see add_static_login_call()
 */
int add_dynamic_login_call( string player, mixed funct, mixed obj ) {
    class login_information login_inf;

    if( stringp(obj) || objectp(obj) ) {
        if( !stringp(funct) )
            return 0;
    } else if( !functionp(funct) ) {
        return 0;
    }

    if( !_dynamic_login_calls[player] )
        _dynamic_login_calls[player] = ({ });

    login_inf = new( class login_information, funct : funct, ob : obj );
    _dynamic_login_calls[player] += ({ login_inf });

    return 1;

} /* add_dynamic_login_call() */

/**
 * This method removes a login call.
 * @param player the player specifier
 * @param funct the funct name
 * @param obj the object to call the funct on
 * @return 0 on failure and 1 on success
 * @see add_dynamic_login_call()
 * @see add_static_login_call()
 */
int remove_dynamic_login_call( string player, mixed funct, mixed obj ) {
    class login_information login_inf;

    if( stringp(obj) || objectp(obj) ) {
        if( !stringp(funct) )
            return 0;
    } else if( !functionp(funct) ) {
        return 0;
    }

    if( _dynamic_login_calls[player] ) {
        foreach( login_inf in _dynamic_login_calls[player] ) {
            if( login_inf->ob == obj && login_inf->funct == funct ) {
                _dynamic_login_calls[player] -= ({ login_inf });
                return 1;
            }
        }
    }

    return 0;

} /* remove_dynamic_login_call() */

/** @ignore yes */
int player_logon( string player, int guest, string ip ) {
    int pos;

    if( lower_case(player) != PO->query_name() )
        return 0;

    // Update the players_on array.
    pos = member_array( player, _players_on );
    if( pos == -1 )
        _players_on += ({ player });

    // Figure out if there are any functions to call.
    do_all_calls( player, LOGIN );

    if( find_call_out(_title_call) == -1 )
        _title_call = call_out("check_all_titles", 5, player );

    log_file( LOG_FILE, "%s [Enter] %-15s %s%s\n",
        ctime(time())[4..18], player, guest ? "(guest) " : "", ip );

} /* player_login() */

private void do_all_calls( string player, string event_t ) {
    class login_information login_inf;

    if( _static_login_calls[player] ) {
        foreach( login_inf in _static_login_calls[player] )
            call_out( (: do_call :), 1, login_inf, player, event_t );
    }

    if( _static_login_calls["all"] ) {
        foreach( login_inf in _static_login_calls["all"] )
            call_out( (: do_call :), 1, login_inf, player, event_t );
    }

    if( _dynamic_login_calls[player] ) {
        foreach( login_inf in _dynamic_login_calls[player] )
            call_out( (: do_call :), 1, login_inf, player, event_t );
    }

    if( _dynamic_login_calls["all"] ) {
        foreach( login_inf in _dynamic_login_calls["all"] )
            call_out( (: do_call :), 1, login_inf, player, event_t );
    }

} /* do_all_calls() */

/** @ignore yes */
private void do_call( class login_information login_inf, string player,
                      int event_t ) {
    object ob;

    if( ( ob = find_player(player) ) && ob->query_invis() < 2 ) {
        if( !functionp( login_inf->funct ) ) {
            if( login_inf->ob && login_inf->funct )
                call_other( login_inf->ob, login_inf->funct, player, event_t );
        } else {
            evaluate( login_inf->funct, player, event_t );
        }
    }

} /* do_call() */

/** @ignore yes */
int player_logout( string player ) {
    int pos;
    object ob;

    pos = member_array( player, _players_on );
    do_all_calls( player, LOGOUT );

    if( pos != -1 ) {
        _players_on = delete( _players_on, pos, 1 );

        if( find_call_out(_title_call) == -1 )
            _title_call = call_out("check_all_titles", 5, player );
        if( find_call_out(_save_call) == -1 )
            _save_call = call_out("save_users", SAVE_TIME );
    }

    // Always do this bit.
    while( !is_discworld_full(WITHOUT_ANY_LOGINS) && sizeof(_login_queue) ) {
        ob = pop_from_login_queue();
        if( ob )
            ob->remove_from_login_queue();
    }

    log_file( LOG_FILE, "%s %-7s %15-s\n", ctime(time())[4..18],
        "[Exit]", player );

    return 1;

} /* player_logout() */

/** @ignore yes */
int player_net_dead( string player ) {
    int pos;
    object ob;

    pos = member_array( player, _players_on );
    if( pos != -1 ) {
        _players_on = delete( _players_on, pos, 1 );

        do_all_calls( player, NETDEATH );

        if( find_call_out(_title_call) == -1 )
            _title_call = call_out("check_all_titles", 5, player );
    }

    // Always do this bit.
    while( !is_discworld_full(WITHOUT_ANY_LOGINS) && sizeof(_login_queue) ) {
        ob = pop_from_login_queue();
        if( ob )
            ob->remove_from_login_queue();
    }

    log_file( LOG_FILE, "%s %-7s %15-s\n", ctime(time())[4..18],
          "[NDead]", player );

    return 1;

} /* player_net_dead() */

/** @ignore yes */
int player_reconnected( string player ) {
    int pos;

    pos = member_array( player, _players_on );
    if( pos == -1 )
        _players_on += ({ player });

    do_all_calls( player, RECONNECT );

    if( find_call_out(_title_call) == -1 )
        _title_call = call_out("check_all_titles", 5, player );

    log_file( LOG_FILE, "%s %-7s %15-s\n", ctime(time())[4..18],
        "[Recon]", player );

} /* player_reconnected() */

/** @ignore yes */
protected void check_all_titles( string player ) {
    int al, good, bad;
    object good_thing, bad_thing, thing, *things;

    good = -250;
    bad = 250;

    things = users();

    foreach( thing in things ) {
        if( !thing || creatorp(thing) )
            continue;

        al = thing->query_al();
        if( al > bad ) {
            bad = al;
            bad_thing = thing;
        }

        if( al < good ) {
            good = al;
            good_thing = thing;
        }
    }

    if( bad_thing ) {
        if( stringp( _worst ) && _worst != player )
            thing = find_player( _worst );
        else
            thing = 0;

        if( bad_thing != thing ) {
            if( thing )
                thing->remove_title("align");

            switch ( bad_thing->query_gender() ) {
              case 1 :
//              bad_thing->set_title("align", "Lord of Darkness");
              break;
              case 2 :
//              bad_thing->set_title("align", "Lady of Darkness");
              break;
              default :
//              bad_thing->set_title("align", "Monster of Darkness");
            }
            _worst = bad_thing->query_name();
        }
    }

    if( good_thing ) {
        if( stringp( _best ) && _best != player )
            thing = find_player( _best );
        else
            thing = 0;

        if( good_thing != thing ) {
            if( thing )
                thing->remove_title("align");

            switch( good_thing->query_gender() ) {
              case 1 :
//              good_thing->set_title("align", "Lord of Light");
              break;
              case 2 :
//              good_thing->set_title("align", "Lady of Light");
              break;
              default :
//              good_thing->set_title("align", "Creature of Light");
            }
            _best = good_thing->query_name();
        }
    }

} /* check_all_titles() */

/** @ignore yes */
void save_users() {
    int number;
    string word;
    object thing;

    number = sizeof( _players_on );

    if( !number ) {
        _save_call = call_out("save_users", SAVE_TIME );
        return ;
    }

    store_user_count();

    // Log the number of players and creators.
    if( _next_user_log < time() )
        log_user_count();

    word = _players_on[ 0 ];
    thing = find_player( word );

    if( objectp( thing ) ) {
        if( ENV( thing ) )
            thing->save();

        _players_on[0..number-2] = _players_on[1..];
        _players_on[number-1] = word;
    } else {
        _players_on = delete( _players_on, 0, 1 );
    }

    _save_call = call_out("save_users", SAVE_TIME / number );

} /* save_users() */

/**
 * Try and figure out if the mud is full or not.  Counts the number
 * of players and returns a true or false value.
 * @see /include/login.h#WITHOUT_LOGINS_NOT_IN_QUEUE
 * @see /include/login.h#WITHOUT_LOGIN_QUEUE
 * @see /include/login.h#WITHOUT_ANY_LOGINS
 * @param logins a flag
 * @return 1 if the mud is full, 0 if it is not
 */
int is_discworld_full( int logins ) {
    object *players;
    int ext = 0;

    players = users();

    switch( logins ) {
      case WITHOUT_LOGINS_NOT_IN_QUEUE :
        players = filter( players, (: objectp($1) && !$1->query_login_ob() &&
                          !creatorp($1) :) ) + _login_queue;
      break;
      case WITHOUT_LOGIN_QUEUE :
        players -= _login_queue;
        players = filter( players, (: objectp($1) && !creatorp($1) :) );
      break;
      case WITHOUT_ANY_LOGINS :
        players = filter( players, (: objectp($1) && !$1->query_login_ob() &&
                          !creatorp($1) :) );
        ext = _out_q;
      break;
      default :
        players = filter( players, (: objectp($1) && !creatorp($1) :) );
    }

    if( time() != _q_time ) {
        _out_q = 0;
        _q_time = time();
    }

    return ( sizeof(players) + ext ) > MAX_PLAYERS;

} /* is_discworld_full() */

private void store_user_count() {
    object pl;
    string *logins_n;
    int current_players, current_creators, current_login_q;

    foreach( pl in users() ) {
        if( pl && !pl->query_login_ob() ) {
            if( creatorp(pl) )
                current_creators++;
            else
                current_players++;
        }
    }

    logins_n = map( LOGIN_H->query_login_queue(),
        (: $1->query_cap_name() :) );
    logins_n = sort_array( logins_n, 1 );

    current_login_q = sizeof(logins_n);

    if( current_players + current_login_q > _players + _login_q ) {
        _players = current_players;
        _creators = current_creators;
        _login_q = current_login_q;
    }

} /* store_user_count() */

private void log_user_count() {
    log_file("USERS", "%s %d %d %d\n", ctime(time()), _creators, _players,
        _login_q );

    _creators = 0;
    _players = 0;
    _login_q = 0;
    _next_user_log = time() + 3601 - (time() % 3600);

} /* log_user_count() */

/** @ignore yes */
void dest_me() { destruct(TO); }

/**
 * This function is used to cache the login messages used by /secure/login
 * it costs a bit in memory but saves us having to re-read the same text
 * file everytime someone logs in.
 * For security reasons this function will only work with files in /doc
 * @param the filename of the file to be returned
 * @return the text of the file.
 */
string get_message( string mess_name ) {
    if( !messages )
        messages = ([ ]);

    // Prevent it working on anything except in /doc to avoid any
    // security risks.
    if( mess_name[0..4] != "/doc/")
        return 0;

    if( !messages[mess_name] )
        messages[mess_name] = read_file(mess_name);

    return messages[mess_name];

} /* get_message() */

/** @ignore yes */
void clear_messages() { messages = ([ ]); }

/** @ignore yes */
int site_lockeddown( string ip_addr ) {
    if( !lockdowns )
        lockdowns = ([ ]);

    if( lockdowns[ip_addr] && sizeof(lockdowns[ip_addr]) >= MAX_FAILURES &&
        lockdowns[ip_addr][0] > time() - LOCKDOWN_TIME )
        return 1;

    return 0;

} /* site_lockeddown() */

/** @ignore yes */
void failed_login( string ip_addr ) {
    int i;

    if( !lockdowns )
        lockdowns = ([ ]);

    if( !lockdowns[ip_addr] )
        lockdowns[ip_addr] = ({ time() });
    else {
        // Needed because of occasional runtimes when something in
        // the login object eats all CPU, and the thread gets here.
        reset_eval_cost();

        // Trim the last failures.
        for( i = 0; i < sizeof(lockdowns[ip_addr]); i++ )
            if( lockdowns[ip_addr][i] < time() - LOCKDOWN_TIME ) {
                lockdowns[ip_addr] -= ({ lockdowns[ip_addr][i] });
                i--;
            }

            lockdowns[ip_addr] += ({ time() });
            if( sizeof(lockdowns[ip_addr]) > MAX_FAILURES ) {
                lockdowns[ip_addr] = lockdowns[ip_addr][
                    sizeof(lockdowns[ip_addr])-MAX_FAILURES..];
        }
    }
} /* failed_login() */

/** @ignore yes */
void clear_lockdowns() { lockdowns = ([ ]); }

/**
 * This method prints all the locked down sites.
 */
void query_lockdowns() { printf("%O\n", lockdowns ); }

/** @ignore yes */
mixed stats() {
    return ({
        ({"login mode", get_login_mode( login_mode ) }),
        ({"saved mud name", mud_name }),
    });
} /* stats() */
