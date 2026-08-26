/**
 * This file contains all the start position related code.  It sets up
 * and controls the start location of the player.  This was split off from
 * the main player code by Pinkfish in April 1998.
 * @see /global/player.c
 * @author Pinkfish
 */

inherit "/std/basic/virtual_quit_control";

#include <playerinfo.h>
#include <config.h>

#define MULTIPLAYER "/handlers/multiplayer"

private int  *saved_co_ords;
private string last_pos;
private string *starts;

protected void inform_entered_game();
string query_name();
string query_cap_name();
varargs int move(string pos, string messin, string messout);

void create() {
    starts = ({ });
} /* create() */

/**
 * This method returns the co-ordinates of the room in which the player
 * last saved.
 * @see check_last_pos()
 * @see move_to_start()
 * @see query_start_pos()
 * @return the last saved co-ordinates
 */
int *query_saved_co_ords() { return saved_co_ords; }

/**
 * This method sets the current start location.
 * @param last_pos the start location
 */
protected void set_last_pos(string pos) {
    if( pos[0..4] != "/room")
        last_pos = pos;
} /* set_last_pos() */

/**
 * This method returns the starting location of the player.  This the
 * location they will start at if the saved position does not work
 * for some reason.
 * @return the start position to use
 * @see query_starts()
 * @see add_start()
 * @see remove_start()
 * @see reset_starts()
 * @see set_start_location()
 */
string query_start_pos() {
    string tmp;
    object ob;

    starts -= ({ 0 });

    if( creatorp(TO) ) {
        tmp = "/w/"+query_name()+"/workroom";
        if( !catch( ob = load_object(tmp) ) && ob )
            return tmp;
    }

    tmp = ( !sizeof( starts ) ? CONFIG_START_LOCATION : starts[ 0 ] );

    if( catch( ob = load_object(tmp) ) || !ob )
        tmp = CONFIG_START_LOCATION;

    return tmp;

} /* query_start_pos() */

/**
 * This method returns the current array of possible start positions on
 * the player.
 * @return the array of possible start locations
 * @see query_start_pos()
 * @see add_start()
 * @see remove_start()
 * @see reset_starts()
 * @see set_start_location()
 */
string *query_starts() { return starts; }

/**
 * This method resets the start locations back to an empty array.
 * @see query_start_pos()
 * @see add_start()
 * @see remove_start()
 * @see query_starts()
 * @see set_start_location()
 */
void reset_starts() { starts = ({ }); }

/**
 * This method will add a new start location to the player.  The
 * description will be used in the starts command.
 * @param start_file the file name of the start location
 * @param start_desc the description of the start location
 * @see query_start_pos()
 * @see reset_starts()
 * @see remove_start()
 * @see query_starts()
 * @see set_start_location()
 * @example
 * // NB: This should be done with a define :)
 * player->add_start("/d/am/am/mendeddrum", "the mended drum");
 */
void add_start( string start_file, string start_desc ) {
    if( !stringp(start_file) || !sizeof(start_file) )
        return;

    if( !starts )
        starts = ({ });

    if( member_array( start_file, starts ) != -1 )
        return;

    starts += ({ start_file, start_desc });

} /* add_start() */

/**
 * This method will remove a start location from the player.
 * @param start_file the file name of the location to remove
 * @see query_start_pos()
 * @see reset_starts()
 * @see add_start()
 * @see query_starts()
 * @see set_start_location()
 * @example
 * // NB: This should be done with a define :)
 * player->remove_start("/d/am/am/mendeddrum");
 */
void remove_start( string start_file ) {
    int i;

    if( !starts )
        return;

    if( ( i = member_array( start_file, starts ) ) == -1 )
        return;

    starts = delete( starts, i, 2 );

} /* remove_start() */

/**
 * This method sets the start location of the player.
 * @param start_file the start location to set
 * @see query_start_pos()
 * @see reset_starts()
 * @see remove_start()
 * @see query_starts()
 * @see add_start()
 * @example
 * // NB: This should be done with a define :)
 * player->set_start_location("/d/am/am/mendeddrum");
 */
void set_start_location( string start_file ) {
    int i;

    if( !starts )
        return;

    if( ( i = member_array( start_file, starts ) ) <= 0 )
        return;

    starts = starts[i..i+1] + starts[0..i-1] + starts[i+2..];

} /* set_start_location() */

/**
 * This method moves the player to the last saved position.  This should
 * only be called in the startup sequence.  If the last location could
 * not be loaded, the the start position will be used.
 * @see query_last_pos()
 * @see quert_start_pos()
 */
protected void move_to_start_pos() {
    object ob;
    string tmp;

    if( !last_pos || catch( ob = load_object(last_pos) ) || !ob ) {
        tmp = query_start_pos();
        if( last_pos != tmp && !catch( ob = load_object(tmp) ) && ob )
            last_pos = tmp;
        else
            last_pos = CONFIG_START_LOCATION;
        saved_co_ords = 0;
    }

    move(last_pos);

    // Set the old coord if one does not already exist.
    // Otherwise don't destroy the already existing scheme.
    if( saved_co_ords && !last_pos->query_co_ord() &&
        !last_pos->query_property("no map") && !creatorp(TO) ) {
        last_pos->set_co_ord( saved_co_ords );
    }

    inform_entered_game();

} /* move_to_start_pos() */

private function query_extra_login_stuff( string start ) {
    string ip_str;
    object *obs;
    object mph;
    string alert;
    int num;
    string *dups;

    switch( TO->query_invis() ) {
      case 0 :
      break;
      case 1:
        start += " (Invisible)";
      break;
      case 2:
        start += " (Lord Invisible)";
      break;
      default :
        start += " (Admin Invisible)";
    }

    mph = load_object(MULTIPLAYER);
    obs = filter( users() - ({ TO }),
        (: query_ip_number($1) == query_ip_number(TO) &&
        !$1->query_login_ob() :) );

    if( sizeof(obs) && sizeof( ( dups = mph->check_allowed( TO, obs ) ) ) ) {
        ip_str = " ("+query_ip_name(TO)+")";
        ip_str += " Duplicate: "+query_multiple_short(dups);
    }

    if( !catch( num = PLAYERINFO_HANDLER->query_alerts_for(
        query_name() ) ) ) {
        if( num > 0 ) {
            alert = " %^BOLD%^%^RED%^"+num+" alert";
            if( num > 1 )
                alert += "s";
            alert += "%^RESET%^";
        }
    }

    if( ip_str ) {
        if( !alert )
            alert = "";
        return (: $(start) + ( creatorp($1) ?
                  $(ip_str) + $(alert) : "") :);
    } else {
        if( alert ) {
            return (: $(start) + ( creatorp($1) ? $(alert) : "") :);
        } else {
            return (: $(start) :);
        }
    }

} /* query_extra_login_stuff() */

/**
 * This method handles informing people that the
 * player has entered the game.
 * @see move_to_start_pos()
 */
protected void inform_entered_game() {
    string logon_str;

    logon_str = query_cap_name()+" enters "+mud_name();

    if( adminp( query_name() ) ) {
        logon_str += " %^BLUE%^(Admin)";
    } else if( lordp( query_name() ) ) {
        logon_str += " %^GREEN%^(Lord)";
    } else if( liaisonp( query_name() ) ) {
        logon_str += " %^YELLOW%^(Liaison)";
    } else if( seniorp( query_name() ) ) {
        logon_str += " %^RED%^(Senior Creator)";
    } else if( DOMAIN_H->query_member("sage", query_name() ) ) {
        logon_str += " %^CYAN%^(Sage)";
    } else if( DOMAIN_H->query_member("learning", query_name() ) ) {
        logon_str += " %^CYAN%^(Apprentice)";
    } else if( creatorp( query_name() ) ) {
        logon_str += " %^CYAN%^(Creator)";
    } else if( TO->query_property("guest") ) {
        logon_str += " %^MAGENTA%^(Guest)";
    } else if( TO->query_property("new player!") ) {
        logon_str += " %^WHITE%^(New Player)";
    } else if( playtesterp( query_name() ) ) {
        if( PLAYTESTERS_H->query_senior_playtester( query_name() ) ) {
            logon_str += " %^BOLD%^%^CYAN%^(Senior Playtester)";
        } else {
            logon_str += " %^CYAN%^(Playtester)";
        }
    }

    user_event( TO, "inform",
        query_extra_login_stuff(logon_str), "logon", TO );

    event( ENV( TO ), "see", query_cap_name()+" enters the game.\n",
        TO, ({ TO }) );

    last_pos->enter(TO);

} /* inform_enter_game() */

/**
 * This method is called to inform people that someone
 * has just reconnected.
 */
void inform_reconnect_game() {
    user_event("inform", query_extra_login_stuff(
        query_cap_name()+" reconnects"), "link-death", TO );
} /* inform_reconnect_game() */

/**
 * This method figured out what the last saved position was and sets it
 * on the player.  This basicly sets the last saved postion.
 * @see query_last_pos()
 */
void check_last_pos() {
    last_pos = find_start_pos( TO, environment() );
    saved_co_ords = find_start_coord( TO, environment() );
} /* check_last_pos() */
