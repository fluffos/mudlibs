/**
 * The main player object.  Does all the player related stuff.
 * @author Pinkfish
 * @started December 1991
 */

#include <config.h>
#include <board.h>
#include <drinks.h>
#include <living.h>
#include <command.h>
#include <player.h>

/** These are defines for the prompt system. */
#define ON 2
#define HP 4
#define GP 8
#define XP 16
#define WD 32

/**
 * This defines the number the players stats are set to when
 * logging in for the first time, or refreshing.
 */
#define NEW_STAT 8

inherit "/global/player/line_ed";
inherit "/global/player/auto_load";
inherit "/global/player/events";
inherit "/global/player/log";
inherit "/global/player/more_string";
inherit "/global/player/finger";
inherit "/global/player/pweath";
inherit "/std/living/living";
inherit "/global/player/psoul";
inherit "/global/player/guild-race";
inherit "/global/player/more_file";
inherit "/global/player/path";
inherit "/global/player/start_position";
inherit "/global/player/family";
inherit "/global/player/channels";

#define MIN_TIME_TO_SAVE 60
#define LEVEL_CACHE 60

class player_data {
    int _hb_num;
    int _level;
    int _level_time;
    object _snoopee;
    string _my_ident;
    mapping _titles;
    int _update_tmps_call_out;
    int _save_inhibit;
    int _last_save;
    int _quitting;
} /* player_data() */

private int time_on;
private int channel_silenced;
private int all_silenced;
private int max_deaths;
private int monitor;
private int refresh_time;
private int start_time;
private int creator;
private int deaths;
private int last_log_on;
private int no_logins;
private int activity_counter;
private string last_on_from;

private nosave class player_data _player_data;

void start_player();
void public_commands();
int save();
void do_load_auto();
void set_name(string str);
void continue_start_player();
int restart_heart_beat();
int brief_verbose(string, string);
int quit_alt();
int review();
int toggle_wimpy(string);
int do_refresh(int);
int set_prompt( string str );

void create() {
    if( query_name() )
        return;

    living::create();
    events::create();
    psoul::create();
    channels::channel_commands();
    line_ed::create();
    more_string::create();
    start_position::create();
    add_property("determinate", "");

    _player_data = new( class player_data );
    _player_data->_save_inhibit = 1;
    _player_data->_titles = ([ ]);

    time_on = time();
    start_time = time();
    last_log_on = time();

    seteuid("PLAYER");

    Str = NEW_STAT;
    Dex = NEW_STAT;
    Int = NEW_STAT;
    Con = NEW_STAT;
    Wis = NEW_STAT;

    sp = 50;
    max_sp = 50;
    wimpy = 25;
    max_deaths = 100;

    set_desc(0);

    add_ac("bing1", "blunt", 15 );
    add_ac("bing2", "sharp", 15 );
    add_ac("bing3", "pierce", 15 );
    add_property("player", 1 );

    set_cols(79);
    set_rows(24);

    race_ob = CONFIG_DEFAULT_RACE;
    sscanf( file_name(TO), "%s#", my_file_name );
    add_language("common");

} /* create() */

/** @ignore yes */
void dest_me() {
    if( query_name() != "object" && objectp(TP) && TP != TO &&
        file_name(PO) != SHUTDOWN_H && base_name(TP) != LOGIN_OBJ ) {
        user_event( TO, "inform", CAP( TP->query_name() )+" dests "+
            query_cap_name(), "dest");
        tell_object( TO, "You were destructed by "+
            CAP( TP->query_name() )+".\n");
    }

    CHANNEL_H->remove_user();
    ::dest_me();

} /* dest_me() */

/**
 * This method stops the player from being able to save.  This is done while
 * the inventory is regenerating to stop problems with inventory loss due
 * to logging off before it has finished.
 * @see allow_save()
 * @see query_save_inhibit()
 */
void disallow_save() { _player_data->_save_inhibit = 1; }

/**
 * This method allows the player to save again after they have been
 * disallowed.
 * @see disallow_save()
 * @see query_save_inhibit()
 */
void allow_save() { _player_data->_save_inhibit = 0; }

/**
 * This method returns the value of the disallowing save variable.  If this
 * is a non-zero value then the player must not be saved.
 * @see allow_save()
 * @see disallow_save()
 */
int query_save_inhibit() { return _player_data->_save_inhibit; }

private int set_quitting() { _player_data->_quitting = 1; }

/**
 * This method queries whether or not the player is in the
 * middle of quitting.
 * @return 1 if we are quitting, 0 if not
 */
int query_quitting() { return _player_data->_quitting; }

/**
 * This method queries whether or not the player has been silenced.
 * @return 1 if we are silenced, 0 if not
 */
int query_silenced() { return all_silenced; }

/**
 * This method silences the player.
 * @return 1 upon success, 0 upon failure
 */
int set_silenced() {
    if( !adminp( previous_object(-1) ) || creatorp(TO) )
        return 0;

    all_silenced = 1;
    return 1;

} /* set_silenced() */

/**
 * This method removes the silencing from the player.
 * @return 1 upon success, 0 upon failure
 */
int unset_silenced() {
    if( !adminp( previous_object(-1) ) || creatorp(TO) )
        return 0;

    all_silenced = 0;
    return 1;

} /* unset_silenced() */

int query_channel_silenced() { return channel_silenced; }

int set_channel_silenced() {
    if( !adminp( previous_object(-1) ) || creatorp(TO) )
        return 0;

    channel_silenced = 1;
    return 1;

} /* set_channel_silenced() */

int unset_channel_silenced() {
    if( !adminp( previous_object(-1) ) || creatorp(TO) )
        return 0;

    channel_silenced = 0;
    return 1;

} /* unset_channel_silenced() */

/**
 * This is the date on which the character was started.  The very first
 * time the player ever logged on.
 * @return the time at which the player first logged on
 */
int query_start_time() { return start_time; }

/**
 * This method returns the current capitalised name of the player.
 * @return the capitalised name
 */
nomask string query_cap_name() { return CAP( query_name() ); }

/**
 * This method is called from within the login code to start up the
 * new player, set their name and move them into the correct
 * location on the mud.
 * @param bong the name of the player
 * @param new_flag are they a new player?
 * @param c_name their capitalized name
 * @param ident the ident from the authorisation code
 * @param go_invis whether or not we should go invis
 */
void move_player_to_start( string bong, int new_flag, string c_name,
                           string ident, int go_invis ) {
    if( base_name(PO) != LOGIN_OBJ ) {
        write("You don't have clearance to do that.\n");
        return;
    }

    seteuid( "Root" );
    set_name( bong );
    _player_data->_my_ident = ident;

    if( !new_flag )
        unguarded( (: restore_object,
            LOGIN_OBJ->query_player_file_name( query_name() ), 1 :) );

    // Reload timed properties.
    reload_player_properties();
    disallow_save(); // Don't allow saves until the autoload has finished.
    add_property("player", 1 );
    set_short( query_cap_name() );
    add_property("determinate", "");

    if( !query_cols() )
        set_cols(79);

    if( creatorp(TP) ) {
        seteuid( query_name() );
        if( file_size ("/w/"+ query_name() +"/cmds" ) == -2 )
            AddSearchPath( ({ "/w/"+ query_name() +"/cmds" }) );
        AddSearchPath( ({ DIR_PLAYER_CMDS, DIR_SECURE_PLAYER_CMDS,
            DIR_CREATOR_CMDS, DIR_SECURE_CREATOR_CMDS,DIR_PENDING_CMDS }) );
    } else {
        seteuid( "PLAYER" );
        AddSearchPath( ({ DIR_PLAYER_CMDS, DIR_SECURE_PLAYER_CMDS }) );
    }

    if( playtesterp(TP) )
        AddSearchPath( ({ DIR_PLAYTESTER_CMDS}) );

    no_logins++;

    if( time_on > 0 )
        time_on = 0;

    time_on += time();

    printf("You last logged in from %s.\n", last_on_from );

    last_on_from = query_ip_name(TO)+" ("+query_ip_number(TO)+")";

    if( new_flag ){
        add_property("death system","v2");
        add_property("new player!", 1 );
    }
    
    LOGIN_H->player_logon( bong, query_property("guest"),
      ( query_ip_name() ? query_ip_name() : query_ip_number() ) );

    write( LOGIN_H->get_message("/doc/NEWS") );
    call_out( (: continue_start_player :), 0 );

} /*  move_player_to_start() */

/** @ignore yes */
protected void move_to_start_pos() {
    int newp;

    ::move_to_start_pos();

    if( newp = query_property("new player!") )
        remove_property("new player!");

    command( ( query_verbose("look") ? "look" : "glance" ) );

    if( !finger_set() )
        write("%^BOLD%^Please set your finger information with "
            "'chfn'.%^RESET%^\n");

    no_time_left();
    START_PLAYER->logged_on_times(no_logins);

    if( newp )
        add_property("skills version", SKILL_H->query_version() );
    else
        SKILL_H->player_logon();

} /* move_to_start_pos() */

/**
 * @ignore yes
 * This function tracks a players activity to determine whether they're still
 * active or not.
 */
protected void update_activity( int logon ) {
    int offline;

    // Lower their activity score if they haven't been on for
    // more than a week.
    if( last_log_on > 0 ) {
        offline = time() - last_log_on;
        if( offline > 0 )
            activity_counter -= ( offline / (3600 * 24 * 7) ) * 10;
    }

    if( activity_counter <= -55 )
        activity_counter = -55;

    // When they logon give them a couple more activity points.
    // Give them some more for each hour they were on when they leave.
    activity_counter += ( logon ? 3 : 2 * ( (time() - last_log_on ) / 3600) );

    // Set minima and maxima to the counter.
    if( activity_counter >= 0 )
        activity_counter = 0;

    last_log_on = time();

    catch( PLAYER_H->delete_from_cache( query_name() ) );

} /* update_activity() */

/**
 * Return the current value of this players activity_counter
 * (used for debugging)
 */
int query_activity_counter() { return activity_counter; }

/** @ignore yes */
private void check_announcements() {
    mapping news_rc;
    mixed stuff;

    if( !news_rc = BOARD_H->query_newsrc( query_name() ) )
        news_rc = ([ ]);

    stuff = BOARD_H->get_subjects("announcements");

    if( sizeof(stuff) && stuff[<1][B_NAME] != query_cap_name() &&
        stuff[<1][B_TIME] > news_rc["announcements"] )
        write("\nThere are %^YELLOW%^NEW%^RESET%^ announcements.  "
          "You can read them with \"news\".\n\n");

} /* check_announcements() */

/** @ignore yes */
void continue_start_player() {
    string title;

    start_player();
    no_time_left();
    call_out( (: move_to_start_pos :), 0 );

    // Remove passed out property, unless the player is
    // in a trance, e.g. when contemplating.
    if( query_property(PASSED_OUT) && !query_property(TRANCE) )
        call_out( (: remove_property :), 10 + random(30), PASSED_OUT );

    // Check to see if the player has the afk flag.
    // If they do, then remove it along with the afk message.
    if( query_property("afk") ) {
        remove_property("afk");
        remove_property("afk_string");
    }

    remove_property(UNKNOWN_MOVE);
    remove_property(RUNNING_MOVE);

    // For effects.
    init_after_save();

    printf("%s", fix_string( MAIL_H->new_mail( query_name() ) ) );

    check_announcements();

    if( query_property("dead") )
        clone_object(DEATH_SHADOW)->setup_shadow( TO );

    if( query_property("noregen") )
        DEATH->person_died( query_name() );

    exec_alias("login", "");
    update_activity(1);

    title = LIBRARY_H->query_title( query_name() );

    if( stringp(title) )
        _player_data->_titles += (["quest" : title ]);

    if( query_property("new player!") ) {

        user_event( TO, "newbie", query_cap_name()+" arrives on "+
            mud_name()+" for the first time!");
        set_last_pos(CONFIG_NEWBIE_START_LOCATION);
        START_PLAYER->start_player();
    }

    add_language("common");
    check_family_name();

} /* continue_start_player() */

/** @ignore yes */
void start_player() {
    int number;

    if( creator && my_file_name != PLAYER_OBJ ) {
        TP->all_commands();
        TP->app_commands();
        TP->wiz_commands();
    }

    // Call this out with a delay of 2, so that our stats
    // will have time to reset first.
    // - Sandoz.
    call_out( (: do_load_auto :), 2 );

    reset_get();
    enable_commands();
    public_commands();
    channel_commands();
    parser_commands();
    force_commands();
    race_guild_commands();
    soul_commands();
    event_commands();
    finger_commands();
    communicate_commands();
    living_commands();
    logging_commands();
    editor_commands();

    set_no_check(1);

    if( TP->query_property("stats_rearranged") ) {
        set_con(Con);
        set_dex(Dex);
        set_int(Int);
        set_str(Str);
        set_wis(Wis);
    } else {
        set_con(NEW_STAT);
        set_dex(NEW_STAT);
        set_int(NEW_STAT);
        set_str(NEW_STAT);
        set_wis(NEW_STAT);
        add_known_command("rearrange");
    }

    reset_all();
    set_current_path( query_home_dir() );
    set_heart_beat(1);

    if( wimpy > 50 )
        wimpy = 25;

    if( contmp || dextmp || inttmp || strtmp || wistmp )
        _player_data->_update_tmps_call_out = call_out(
            (: update_tmps :), 900 );

    number = max_sp - query_real_max_sp();
    if( number > 0 )
        max_sp -= number;

    BIRTHDAY_H->check_player(TO);

} /* start_player() */

/** @ignore yes */
int adjust_hp( int number, object attacker, object weapon, string attack ) {
    if( !interactive( TO ) )
        return query_hp();
    return ::adjust_hp( number, attacker, weapon, attack );
} /* adjust_hp() */

/**
 * Starts the autoloading process.  This is called just after a player
 * logs in to start up the auto loading process.
 */
void do_load_auto() {
    load_auto_load_alt( query_auto_load_string(), TO, TO, (: tell_object( TO,
          "\n%^CYAN%^Inventory regeneration complete.%^RESET%^\n") :) );
    set_auto_load_string(0);
    allow_save();
} /* do_load_auto() */

/** @ignore yes */
void public_commands() {
    add_command("restart", TO, "", (: restart_heart_beat() :) );
    add_command("save", TO, "", (: save() :) );

    add_command("quit", TO, "", (: quit_alt() :) );
    add_command("review", TO, "", (: review() :) );

    add_command("wimpy", TO, "", (: toggle_wimpy(0) :) );
    add_command("wimpy", TO, "<word'number'>", (: toggle_wimpy($4[0]) :) );

    add_command("refresh", TO, "", (: do_refresh(0) :) );
    add_command("refresh", TO, "me", (: do_refresh(1) :) );

    add_command("prompt", TO, "", (: set_prompt( 0 ) :) );
    add_command("prompt", TO,
        "{on|off|hp|ep|xp"+( TO->query_creator() ? "|wd" : "")+"}",
        (: set_prompt($4[0]) :) );

} /* public_commands() */

/**
 * Force the player to glance.  Forces the player to glance in a
 * certain direction.
 * @param str the direction to glance in
 * @return 0 ifg the command failed, non zer if it succeeded
 */
int glance( string str ) {
    return command("glance" + ( str ? " "+str : "" ) );
} /* glance() */

/**
 * Force the player to look.  Forces the player to look at something
 * or just around.  If the input is set to "" then they look around.
 * @param str what to look at
 * @return 0 if it failed, non zero on success
 * @see efun::command()
 */
int look_me(string str) {
    return command( str ? "look" + str : "look");
} /* look_me() */

/** @ignore yes */
int review() {
    write("Entry  : " + query_msgin() + "\n");
    write("Exit   : " + query_msgout() + "\n");
    write("MEntry : " + query_mmsgin() + "\n");
    write("MExit  : " + query_mmsgout() + "\n");
    write("Editor : " + query_editor() + "\n");
    return 1;
} /* review() */


/**
 * Forces the player to examine something.  This does the same as the look_me
 * function.
 * @see look_me()
 * @return 0 on a failure, non zero on success.
 * @param arg the thing to look at.
 */
int examine( string arg ) {
    return look_me( arg ? " at "+arg : "" );
} /* examine() */

/** @ignore yes */
varargs string short( int dark, int verbose ) {
    string str, family, title;

    str = ( !interactive(TO) ? "the net dead statue of " : "");

    family = query_family_name();
    family = ( family ? " "+family : "");

    if( verbose )
        title = query_player_title();

    title = ( title ? title + " " : "");

    return str + title + living::short( dark ) + family;

} /* short() */

/**
 * This method changes the current value of the wimpy variables.
 * @param str the new value of the wimpy variable
 * @return 0 on failure and 1 on success
 */
int toggle_wimpy( string str ) {
    int number;

    if( !str ) {
        write( ( wimpy ? "You are in wimpy mode, you will run away at "+
            wimpy+"% of your max hps.\n" : "You are in brave mode.\n" ) );
        write("Usage: wimpy <num> (Caution!  Please read help wimpy!)\n");
        return 1;
    }

    if( sscanf( str, "%d", number ) != 1 )
        return notify_fail("You must set your wimpy to a number.\n");

    if( number < 0 || number > 50 )
        return notify_fail("Your wimpy must be between 0 and 50.\n");

    TO->set_wimpy( number );
    printf("Wimpy set to %d%%\n", wimpy );
    return 1;

} /* toggle_wimpy() */

/**
 * This method returns any extra information associated with the score.  This
 * method will mostly be overridden by shadows which wish to place more
 * information into the score command.
 * @return the extra information to place in the score
 */
string extra_score() { return ""; }

/**
 * This method queries whether or not we are old enough to be saved.
 * @return 1 if we are old enough to save, 0 if too young
 */
nomask int query_old_enough_to_save() {
    return -TO->query_time_on() > MIN_TIME_TO_SAVE;
} /* query_old_enough_to_save() */

/**
 * This method is called to save the player to disc.  It will print
 * a message to the player to inform them of the face they have
 * been saved.
 * @return always returns 1
 * @see save_me()
 */
nomask int save() {
    if( query_property("guest") ) {
        if( query_verb() == "save" )
            tell_object( TO, "Not saving for guests... Sorry.\n");
        return 1;
    }

    if( !query_old_enough_to_save() ) {
        if( query_verb() == "save")
            tell_object( TO, "Sorry, you must be at least "+
              time_string(MIN_TIME_TO_SAVE)+" old to save.\n");
        return 1;
    }

    if( my_file_name == PLAYER_OBJ || query_verb() == "save") {
        if( query_verb() == "save") {
            if( _player_data->_last_save + MIN_SAVE_REPEAT > time() ) {
                tell_object( TO, "Please use this command sparingly or it "
                  "lags the mud.\n");
                return 1;
            }
            _player_data->_last_save = time();
        }
        tell_object( TO, "Saving...\n");
    }

    TO->save_me();
    return 1;

} /* save() */

/**
 * Saves the player.  Saves the player to disc, doing all the autoload
 * stuff and such like.
 * @see save()
 */
void save_me() {
    if( query_property("guest") ) {
        if( query_verb() == "save")
            tell_object( TO, "Not saving for guests... Sorry.\n" );
        return;
    }

    if( !query_old_enough_to_save() ) {
        if( query_verb() == "save")
            tell_object( TO, "Sorry, you must be at least "+
              time_string(MIN_TIME_TO_SAVE)+" old to save.\n");
        return;
    }

    if( query_auto_loading() || query_save_inhibit() )
        return;

    if( race_ob )
        race_ob->player_save(TO);

    check_last_pos();

    // For effects.
    effect_freeze();
    effects_saving();

    // Recreating the autoload stuff.
    create_auto_load( all_inventory(), 1 );
    if( interactive(TO) )
        last_on_from = query_ip_name(TO)+" ("+query_ip_number(TO)+")";

    // Keep the time_on calculation as close to the saving as possible.
    time_on -= time();
    // Save timed properties.
    save_player_properties();
    catch( unguarded( (: save_object,
          LOGIN_OBJ->query_player_file_name( query_name() ), 1 :) ) );
    // Reload timed properties.
    reload_player_properties();
    time_on += time();
    ITEM_H->save_all_item_states( TO->query_name() );

    effect_unfreeze();

    // Clear the autoload string after saving to save memory.
    set_auto_load_string(0);

} /* save_me() */

void save_with_auto_load( mixed al ) {
    if( query_property("guest") ) {
        if( query_verb() == "save")
            tell_object( TO, "Not saving for guests... sorry.\n");
        return;
    }

    if( !query_old_enough_to_save() ) {
        if( query_verb() == "save")
            tell_object( TO, "Sorry, you must be at least "+
              time_string(MIN_TIME_TO_SAVE)+" old to save.\n");
        return;
    }

    if( query_save_inhibit() )
        return;

    if( race_ob )
        race_ob->player_save(TO);

    // For effects.
    effect_freeze();
    effects_saving();

    set_auto_load_string(al);

    // Put the time_on calculation as close to the save as possible.
    time_on -= time();
    // Save timed properties.
    save_player_properties();
    catch( unguarded( (: save_object,
          LOGIN_OBJ->query_player_file_name( query_name() ), 1 :) ) );
    // Reload timed properties.
    reload_player_properties();
    time_on += time();

    effect_unfreeze();

} /* save_with_auto_load() */

/**
 * This is the quit code called by the command 'quit'
 * @return 1 if successful, 0 if failed
 * @see quit()
 * @see do_quit()
 */
int quit_alt() {
    object frog;

    if( ENV(TO) && file_name(ENV(TO)) == "/room/departures") {
        if( TO == TP )
            tell_object( TO, "You cannot quit while already in the "
                "departures room.\n");
        return 1;
    }

    if( query_auto_loading() ) {
        if( !interactive(TO) )
            dest_me();
        else
            tell_object( TO, "You cannot quit yet: your inventory is still "
              "being generated.\n");
        return 1;
    }

    if( sizeof( filter( (object *)TO->query_attacker_list(),
        (: living( $1 ) :) ) ) && TP == TO && interactive(TO) ) {
        tell_object( TO, "You cannot quit while in combat.  Use 'stop' to "
            "stop fighting.\n");
        return 1;
    }

    set_quitting();
    check_last_pos();
    update_activity(0);

    // Added to help people tell when the player quits.
    catch( TO->event_quit(TO) );
    catch( editor_check_do_quit() );

    if( query_old_enough_to_save() && !query_property("guest") )
        tell_object( TO, "Saving your inventory.\n");

    event( ENV(TO), "see", query_cap_name()+" leaves the game.\n", TO,
        ({ TO }) );

    catch( move("/room/departures") );

    user_event( TO, "inform", query_cap_name()+" leaves "+mud_name(),
        "logon", TO );

    catch( LOGIN_H->player_logout( query_name() ) );

    if( race_ob )
        catch( race_ob->player_quit(TO) );

    frog = clone_object("/obj/monster/greco");
    frog->move("/room/departures");
    frog->get_rid_of(TO);

    return 1;

} /* quit_alt() */

/**
 * quits the player.
 * @return zero if it failed, non zero on success
 * @see quit()
 * @see quit_alt()
 */
int do_quit() {
    return quit_alt();
} /* do_quit() */

/**
 * A forced quit.
 * This is the function called by external objects to quit
 * a player. It avoids checks for things like being in combat.
 * @return 0 if it failed, non zero if it succeeded.
 * @see do_quit()
 * @see quit_alt()
 * @see efun::command()
 */
int quit() {
    set_quitting();
    check_last_pos();
    update_activity(0);

    catch( editor_check_do_quit() );

    // Added to help people tell when the player quits.
    catch( TO->event_quit(TO) );

    event( ENV(TO), "see", query_cap_name()+" leaves the game.\n", TO,
        ({ TO }) );

    user_event( TO, "inform", query_cap_name()+" leaves "+mud_name(),
        "logon", TO );

    tell_object( TO, "Thanks for playing.  See you next time.\n");

    catch( LOGIN_H->player_logout( query_name() ) );

    if( race_ob )
        catch( race_ob->player_quit(TO) );

    if( query_auto_loading() || query_save_inhibit() ) {
        tell_object( TO, "Forced to quit whilst auto loading.  "
          "Not saving...\n");
        if( catch( dest_me() ) )
            destruct(TO);
        return 1;
    }

    if( !query_old_enough_to_save() || query_property("guest") ) {
        if( catch( dest_me() ) )
            destruct(TO);
        return 1;
    }

    catch( save_me() );
    catch( INV(TO)->set_tracked_item_status_reason("QUIT") );
    catch( INV(TO)->dest_me() );
    catch( ITEM_H->save_all_item_states_delete_cache( TO->query_name() ));

    effects_quiting();

    if( catch( dest_me() ) )
        destruct(TO);

    return 1;

} /* quit() */

/**
 * This method returns the mapping of all the title associated with this
 * player.
 * @return the current mapping of titles
 * @see query_title()
 * @see set_title()
 * @see remove_title()
 */
mapping query_titles() { return copy( _player_data->_titles ); }

/**
 * This method returns the list of titles associated with this player.
 * @return the list of titles
 * @see query_titles()
 * @see set_title()
 * @see remove_title()
 */
string query_title() {
    return implode( values( _player_data->_titles ), ", " );
} /* query_title() */

/**
 * This method sets the current title type to be of a certain name.
 * @param type the type of title to set
 * @param title the string to set it to
 * @see query_title()
 * @see set_title()
 * @see remove_title()
 */
void set_title( string type, string title ) {
    _player_data->_titles[ type ] = title;
} /* set_title() */

/**
 * This method removes the title of the given type from the title mapping.
 * @param type the type of title to remove
 * @see query_title()
 * @see set_title()
 * @see remove_title()
 */
void remove_title( string type ) {
    map_delete( _player_data->_titles, type );
} /* remove_title() */

/**
 * This method returns the number of times the player has died.
 * @return the number of times the player has died
 * @see adjust_deaths()
 * @see adjust_max_deaths()
 */
int query_deaths() { return deaths; }

/**
 * This method changes the number of times the player has died.
 * @see query_deaths()
 * @see adjust_max_deaths()
 */
void adjust_deaths(int i) { deaths += i; }

/** @ignore yes */
protected void set_name( string str ) {
    if( query_name() && query_name() != "object")
        return;
    ::set_name(str);
    set_living_name( query_name() );
    set_main_plural( query_name() );
} /* set_name() */

/* No idea what these are doing here? */
/** @ignore yes */
void init_static_arg( mapping map ) { return; }
/** @ignore yes */
void init_dynamic_arg( mapping map ) { return; }

/** @ignore yes */
string long( string str, int dark ) {
    string s, tmp, title;

    title = query_player_title();
    title = ( title ? title + " " : "" );

    s = "You see "+ title + query_short();

    if( tmp = query_family_name() )
        s += " " + query_family_name();

    s += " "+TITLE_H->query_title(TO)+".\n";

    if( race_ob )
        s += race_ob->query_desc(TO);

    if( dark == 2 || dark == -2 ) {
        s += "It is too ";
        if( dark == 2 )
            s += "dark";
        else
            s += "bright";
        s += " to see "+HIS+" description or what "+HE+" is wearing or "
        "carrying.\n";
        s += calc_extra_look();
    } else {
        if( query_desc() && query_desc() != "" )
            s += CAP(HE) + " " + query_desc() + "\n";
        s += CAP(HE) + " " + TO->health_string(TO,0) + ".\n";
        s += CAP(HE) + " is " + query_position_short() + ".\n";
        if( query_property( PASSED_OUT ) )
            s += CAP(HE)+" appears to be passed out.\n";
        s += calc_extra_look();
        s += weather_extra_look();
        s += query_living_contents(0);
    }

    return s;

} /* long() */

/**
 * This method is called when the player dies.  It creates the corpse
 * and handles all the bits and pieces that should be dealth with
 * when a player dies.
 * <p>
 * If this method returns 0 then the automatic death handling code
 * in the living object is used instead of this.
 * @return always returns 1
 */
mixed second_life() {
    object corpse;

    add_property("dead", time() );

    if( !DEATH->someone_died( TO ) ) {
        if( !creatorp(TO) && !query_property("no die") )
            deaths = deaths + 11;
    } else {
        add_property( PK_KILLED, 1 );
    }

    effects_thru_death();
    corpse = make_corpse();

    if( deaths > max_deaths ) {
        tell_object( TO, "You have died your final death.  "+
            "Your name will be inscribed in the Hall of Legends.\n");
        shout( query_cap_name()+" has died for the last time.  "+
            "All mourn "+HIS+" passing.\n" );
        LIBRARY_H->complete_death( query_name() );
        corpse->add_property("Died Last Time", time() );
        corpse->set_decay( 0 );
    }

    corpse->move( environment() );
    call_out( (: save_me :), 0 );

    DEATH->person_died( query_name() );
    clone_object( DEATH_SHADOW )->setup_shadow( TO );

    gp = 0;
    hp = 0;
    sp = 0;
    xp = 0;

    spells = ([ ]);

    contmp = dextmp = inttmp = strtmp = wistmp = 0;
    remove_call_out( _player_data->_update_tmps_call_out );

    adjust_tmp_con( -2 );
    adjust_tmp_dex( -2 );
    adjust_tmp_int( -2 );
    adjust_tmp_str( -2 );
    adjust_tmp_wis( -2 );

    return corpse;

} /* second_life() */

/**
 * This method removes the ghost from the player.  This stops them
 * being a ghost and turns them back into a real person.
 * @see second_life()
 */
void remove_ghost() {
    if( deaths > max_deaths ) {
        if( TP != TO ) {
            tell_object( TO, TP->query_cap_name()+" tried to raise you, but "
                "you are completely dead.\n");
            tell_object( TP, query_cap_name()+" is completely dead, you "
                "cannot raise "+HIM+".\n");
            return;
        } else {
            tell_object( TO, "You are completely dead.  You cannot be "
                "raised.\n");
            say( query_cap_name()+" struggles to appear in a solid form, but "
                "fails.\n");
            return;
        }
    }

    remove_property("dead");
    remove_property(PK_KILLED);

    tell_object( TO, "You reappear in a more solid form.\n");
    say( query_cap_name()+" appears in more solid form.\n");

    if( query_hp() < 0 )
        set_hp( 1 );

    set_personal_temp(0);

    TO->dest_death_shadow();
    save_me();
    all_inventory()->recovery_from_death();

} /* remove_ghost() */

/**
 * Called when the player goes net dead.  This is called
 * by the driver when a player goes net dead.  Turns them into
 * a statue and stuff.
 */
void net_dead() {
    catch( editor_check_do_quit() );

    if( !environment() || file_name( environment() ) == "/room/departures")
        return;

    if( query_name() == "guest" || query_name() == "root") {
        say( query_cap_name()+" vanishes in a puff of logic.\n");
        quit();
    } else {
        event( ENV(TO), "see", query_cap_name()+" goes white, looks very "
            "chalky and turns into a statue.\n", TO, ({ TO }) );
        user_event( TO, "inform", query_cap_name()+" has lost "+HIS+" link",
            "link-death", TO );
        check_last_pos();
        LOGIN_H->player_net_dead( query_name() );
        save_me();
    }

} /* net_dead() */

/**
 * Checks to see if they have idled out.  This is called from within
 * the heart beat code.
 * @see heart_beat()
 */
void idle_out() {
    event( ENV(TO), "see", query_cap_name()+" has been idle for too long, "+
        HE+" vanishes in a puff of boredom.\n", TO, ({ TO }) );
    tell_object( TO, "You idled out, sorry.\n");
    quit();
} /* idle_out() */

/**
 * The main heart beat function.  This is called by the driver
 * every 2 seconds on the player.  Does all the maintenace
 * stuff like executing commands, fixing up hps and stuff like that.
 */
void heart_beat() {
    int idle_time;

    flush_queue();

    idle_time = ( !interactive(TO) ? time() - last_command : query_idle(TO) );

    if( idle_time > FULL_IDLE ) {
        if( ( LOGIN_H->is_discworld_full() || idle_time > MAX_IDLE ) &&
            ( !interactive(TO) || !creatorp(TO) ) ) {
            call_out( (: idle_out :), 2 );
        }
    }

    if( !interactive(TO) ) {
        if( idle_time > 60 )
            quit();
        return;
    }

    living::heart_beat();
    adjust_sp( 1 );
    living::update_volumes();

    // Reset it every hour to stop it rolling over.
    if( ++_player_data->_hb_num >= 1800 )
        _player_data->_hb_num = 0;

    // Do the news check and personal temperature calculation
    // every few minutes.
    if( !( _player_data->_hb_num % 120 ) )
        calc_personal_temp();

    if( !( _player_data->_hb_num % 900 ) )
        check_announcements();

} /* heart_beat() */

/**
 * Is the monitor turned on?  The hit point monitor which is
 * displyed during combat...
 * @return 1 if it is on, 0 if not
 */
int query_monitor() { return ( monitor & 1 ); }

/**
 * Set the hit point monitor.  This sets the value of the hit point
 * monitor flag.  If it is set to 0, the monitor is turned off.  If
 * it is set to 1 the monitor is turned on.
 * @param i the new value for the hit point monitor flag
 */
void set_monitor( int i ) {
    if( !i )
        monitor &= ~1;
    else
        monitor |= 1;
} /* set_monitor() */

/** @ignore yes */
int set_prompt( string str ) {
    if( !str ) {
        string *arr;

        arr = ({ });

        if( monitor & HP )
            arr += ({"hit points"});
        if( monitor & GP )
            arr += ({"energy points"});
        if( monitor & XP )
            arr += ({"experience points"});
        if( monitor & WD )
            arr += ({"working directory"});

        str = "Your prompt is currently displaying ";

        if( !sizeof(arr) )
            str += "nothing";
        else
            str += query_multiple_short(arr);

        if( monitor & ON ) {
            if( !sizeof(arr) )
                str += ", but has been turned on";
            else
                str += " and has been turned on";
        } else {
            if( sizeof(arr) )
                str += ", but has been turned off";
            else
                str += " and has been turned off";
        }

        write( str+".\n");
        return 1;
    }

    switch( str ) {
      case "on" :
        if( monitor & ON  ) {
            write("Your prompt is already turned on.\n");
            return 1;
        }
        monitor |= ON;
        write("You turn your prompt on.\n");
        return 1;
      case "off":
        if( !( monitor & ON )  ) {
            write("Your prompt is already turned off.\n");
            return 1;
        }
        monitor &= ~ON;
        write("You turn your prompt off.\n");
        return 1;
      case "hp":
        if( monitor & HP ) {
            monitor &= ~HP;
            write("Your prompt will not display "+str+" anymore.\n");
        } else {
            monitor |= HP;
            write("Your prompt will now display "+str+".\n");
        }
      break;
      case "ep":
        if( monitor & GP ) {
            monitor &= ~GP;
            write("Your prompt will not display "+str+" anymore.\n");
        } else {
            monitor |= GP;
            write("Your prompt will now display "+str+".\n");
        }
      break;
      case "xp":
        if( monitor & XP ) {
            monitor &= ~XP;
            write("Your prompt will not display "+str+" anymore.\n");
        } else {
            monitor |= XP;
            write("Your prompt will now display "+str+".\n");
        }
      break;
      case "wd":
        str = "working directory";
        if( monitor & WD ) {
            monitor &= ~WD;
            write("Your prompt will not display your "+str+" anymore.\n");
        } else {
            monitor |= WD;
            write("Your prompt will now display your "+str+".\n");
        }
      break;
      default:
        return notify_fail("Something has broken, please file a bug "
            "report.\n");
    }

    if( !( monitor & HP ) && !( monitor & GP ) &&
        !( monitor & XP ) && !( monitor & WD ) ) {
        monitor &= ~ON;
        write("Your prompt turns itself off as you choose it not to "
            "display "+str+" anymore.\n");
    }

    return 1;

} /* set_prompt() */

/** @ignore yes */
protected void write_prompt() {
    if( !( monitor & ON ) || ( !( monitor & HP ) && !( monitor & GP ) &&
        !( monitor & XP ) && !( monitor & WD ) ) ) {
        efun::tell_object( TO, "> ");
    } else {
        string ret;

        if( monitor & HP ) {
            ret = "Hp: ";

            switch( query_hp() * 100 / query_max_hp() ) {
              case 61..100 :
                ret += "%^GREEN%^";
              break;
              case 31..60 :
                ret += "%^YELLOW%^";
              break;
              default :
                ret += "%^RED%^";
            }

            ret += query_hp()+"%^RESET%^";
        }

        if( monitor & GP ) {
            if( !ret )
                ret = "Ep: ";
            else
                ret += " Ep: ";

            switch( query_gp() * 100 / query_max_gp() ) {
              case 61..100 :
                ret += "%^GREEN%^";
              break;
              case 31..60 :
                ret += "%^YELLOW%^";
              break;
              default :
                ret += "%^RED%^";
            }
            ret += query_gp()+"%^RESET%^";
        }

        if( monitor & XP ) {
            if( !ret )
                ret = "Xp: " + query_xp();
            else
                ret += " Xp: " + query_xp();
        }

        if( monitor & WD ) {
            if( !ret )
                ret = "Dir: "+TO->query_current_path();
            else
                ret += " Dir: "+TO->query_current_path();
        }

        efun::tell_object( TO, fix_string( ret + ">\n") );
    }

} /* write_prompt() */

/**
 * Called when the player wimpies out of a place.  This does all the run
 * away stuff and things like that.
 * @return 1 if succeeded in running away, 0 if not
 */
int run_away() {
    int number;

    become_flummoxed();
    number = ::run_away();

    if( number )
        tell_object( TO, ( number ? "Your feet run away with you!" :
            "You try to run away, but no matter how you scrabble, you can't "
            "find any way out.")+"\n");

    return number;

} /* run_away() */

/**
 * @ignore yes
 * This is needed by the driver.
 */
int query_wizard() { return creator; }

/**
 * The amount of time on line.  This is the total amount of time online
 * in seconds from when they first started playing.  The return from
 * this method is *negative*, you will need to make it positive to use it
 * most likely.
 * @return the total log on time in seconds (the return value is *negative*)
 */
nomask int query_time_on() { return time_on - time(); }

/**
 * This method determins if the player is mature or not yet.  It is based
 *  on the amount of time on.
 * @return 1 if the player is mature, 0 if they are not
 */
int query_mature() { return ( MATURITY * 60 * 60 + time_on < time() ); }

/**
 * This method checks to see if the player can see at the passed
 * in light level.
 * @return -2 or -1 if it is too dark, 1 or 2 if too bright, 0 if they can see
 */
int check_dark( int light ) {
    int i;

    if( query_property("dead") )
        return 0;

    if( race_ob )
        if( catch( i = race_ob->query_dark(light) ) )
            race_ob = CONFIG_DEFAULT_RACE;
        else
            return i;

    return CONFIG_DEFAULT_RACE->query_dark(light);

} /* check_dark() */

/**
 * This method returns the players level.
 * @return their level
 */
int query_level() {
    if( _player_data->_level_time < ( time() - LEVEL_CACHE ) ) {
        _player_data->_level =  STD_GUILD_OBJ->query_level(TO);
        _player_data->_level_time = time();
    }

    return _player_data->_level;

} /* query_level() */

/**
 * Restarts their heartbeat if it has been turned off for some reason.
 * @return always returns 1
 */
int restart_heart_beat() {
    set_heart_beat(1);
    tell_object( TO, "Ok, heart beat restarted.\n");
    return 1;
} /* restart_heart_beat() */

/** @ignore yes */
nomask void set_snoopee( object ob ) { _player_data->_snoopee = ob; }

/**
 * Returns the object snooping us.  If someone is snooping the player it
 * returns the object doing the snooping.  If no one is snooping the player
 * it returns 0.
 * @return the object snooping the player
 * @see efun::snoop()
 */
nomask object query_snoopee() { return _player_data->_snoopee; }

/** @ignore yes */
void set_creator( int i ) {
    if( PO != master() && file_name(PO) != DOMAIN_H ) {
        write("Illegal attempt to set creator!\n");
        log_file("ILLEGAL", this_player(1)->query_name()+" ("+
            file_name(this_player(1))+") Illegal attempt to set_creator "+
            "at "+ctime(time())+" from "+file_name(PO)+"\n");
        return;
    }

    creator = i;
    set_home_dir("/w/"+query_name() );
    save_me();

} /* set_creator() */

/**
 * Prevent the object from shadowing us?  This checks to see if we should
 * prevent this object from shadowing the player.
 * @return 1 if we are prventing the shadow
 */
int query_prevent_shadow( object ob ) {
    if( function_exists("query_prevent_shadow", ob ) ||
        function_exists("query_name", ob ) ||
        function_exists("query_creator", ob ) ||
        function_exists("dest_me", ob ) ||
        function_exists("query_object_type", ob ) ||
        function_exists("save_me", ob ) )
        return 1;
    return 0;
} /* query_prevent_shadow() */

/**
 * Returns the maxium number of deaths.  This is the maxium
 * number of times they can die before they are totally dead.
 * @return the maxium number fo deaths
 */
int query_max_deaths() { return max_deaths; }

/**
 * Sets the maximum number of deaths.  This sets the maximum
 * number of times a player can die.
 * @param i the number of deaths to set it to
 * @see adjust_max_deaths()
 */
void set_max_deaths(int i) { max_deaths = i; }

/**
 * Changes the current number of maxium deaths.  This adjust
 * the number of times a player can die before they are totally dead.
 * @return the current total maximum deaths
 */
int adjust_max_deaths(int i) { return ( max_deaths += i ); }

/** @ignore yes */
varargs int move( mixed dest, string msgin, string msgout ) {
    int i;
    object env;

    env = environment();

    if( !i = living::move( dest, msgin, msgout ) )
        me_moveing(env);

    return i;

} /* move() */

/** @ignore yes */
nomask protected int do_refresh( int me ) {

    if( !me )
        return notify_fail("Please read \"help refresh\" before doing "
            "this!\n");

    if( query_property("guest") )
        return notify_fail("Guest characters cannot refresh, sorry.\n");

    if( creatorp(TO) )
        return notify_fail("You cannot refresh a creator character, please "
          "ask an admin to demote you first.\n");

    write("%^BOLD%^%^RED%^WARNING!%^RESET%^%^RESET%^\nPlease make sure you "
      "have read \"help refresh\" before doing this!\nAre you certain you "
      "wish to refresh yourself?\n%^YELLOW%^Please note you are using the "
      "character "+query_cap_name()+"!%^RESET%^\nAnswer \"YES\" or \"NO\"\n");

    input_to("refresh2");
    return 1;

} /* do_refresh() */

/** @ignore yes */
protected int refresh2( string str ) {
    if( str != "YES") {
        write("Alright, not refreshing you.\n");
        return 1;
    }

    write("Ok, refreshing you.\n");
    say( query_cap_name()+" refreshes "+HIM+"self.\n");

    move_with_look( CONFIG_NEWBIE_START_LOCATION );

    Str = NEW_STAT;
    Dex = NEW_STAT;
    Int = NEW_STAT;
    Con = NEW_STAT;
    Wis = NEW_STAT;

    inttmp = dextmp = wistmp = strtmp = contmp = 0;
    race_ob = CONFIG_DEFAULT_RACE;

    set_al(0);
    set_deity(0);
    languages = ({"common"});
    set_skills(0);

    add_skill_level("general.language.common.spoken", 100 );
    add_skill_level("general.language.common.written", 100 );
    spells = ([ ]);

    xp = 0;
    deaths = 0;
    max_deaths = 100;

    refresh_time = time_on - time();
    refresh_time = -refresh_time;

    totaly_zap_bonus_cache();
    known_commands = ({"skills", "rearrange", "ep"});
    reset_starts();
    race_guild_commands();
    totaly_zap_stat_cache();

    drink_info = allocate( D_SIZEOF );

    map_prop = ([
        "determinate" : "",
        "player" : 1,
        "skills version" : SKILL_H->query_version(),
        "death system" : "v2",
        NEWS_RC : TP->query_property(NEWS_RC),
    ]);

    TO->remove_ghost();
    reset_all();
    set_family_name(0);
    _player_data->_titles = ([ ]);

    all_inventory()->dest_me();

    if( sizeof( all_inventory() ) ) {
        foreach( object ob in all_inventory() ) {
            if( ob )
                destruct(ob);
        }
    }

    // First refresh, then related files.
    REFRESH_H->player_refreshed(TO);
    BULK_DELETE_H->delete_related_files( query_name(), 0 );
    START_PLAYER->start_player();

    user_event( TO, "inform", query_name()+" refreshes "+HIM+"self",
        "refresh", TO );
    write("Done.\n");
    return 1;

} /* refresh2() */

/**
 * This method returns the one letter object type which is used in the
 * finger command to display the type of object.
 * @return the one letter object type
 */
string query_object_type() {
    if( playtesterp( query_name() ) )
        return "p";
    return " ";
} /* query_object_type() */

/** @ignore yes */
void set_my_ident( string str ) {
    if( base_name(PO) != LOGIN_OBJ ) {
        user_event( TO, "inform", "Invalid call to set_my_ident", "cheat");
        return;
    }

    _player_data->_my_ident = str;

} /* set_my_ident() */

/**
 * This method returns the ident of the player.  The ident is
 * determined using the authentication protocol.
 * @return the ident of the player
 */
string query_my_ident() {
    if( PO != find_object("/secure/simul_efun") )
        return 0;
    return _player_data->_my_ident;
} /* query_my_ident() */

/** @ignore yes */
void event_enter( object thing, string mess, object from ) {
    events::event_enter( thing, mess, from );
    living::event_enter( thing, mess, from );
} /* event_enter() */

/** @ignore yes */
void event_exit( object thing, string mess, object to ) {
    events::event_exit( thing, mess, to );
    living::event_exit( thing, mess, to );
} /* event_exit() */

/** @ignore yes */
string *parse_command_id_list() {
    return living::parse_command_id_list() +
    family::parse_command_id_list();
} /* parse_command_id_list() */

/** @ignore yes */
string *parse_command_plural_id_list() {
    return living::parse_command_plural_id_list() +
    family::parse_command_plural_id_list();
} /* parse_command_plural_id_list() */

/** @ignore yes */
string *parse_command_adjectiv_id_list() {
    return living::parse_command_adjectiv_id_list() +
    family::parse_command_adjectiv_id_list();
} /* parse_command_adjectiv_id_list() */

/**
 * This method returns the time at which the player last logged on.
 * @return the last logged on time
 */
int query_last_log_on() { return last_log_on; }

/**
 * This method returns the ip from which the player last logged on.
 * @return the ip address from which they last logged on
 */
string query_last_on_from() { return last_on_from; }

/* This is the time since the last refresh... */
/**
 * This method returns the time at which the player last refreshed.
 * @return the last refresh time
 */
int query_refresh_time() { return refresh_time; }

/**
 * This method returns the number of times the player has logged onto the mud.
 * @return the number of logins
 */
int query_no_logins() { return no_logins; }

/**
 * This method returns if the object is a creator or not.
 * @return 1 if the object is a creator, 0 if not
 */
int query_creator() { return 0; }

/**
 * This method returns the array of our friends.
 * @return our friends array
 */
string *query_friends() { return query_property("friends") || ({ }); }

/**
 * This method will return 1 if the input name is a friend.
 * @param who the person to test for friendship
 * @return 1 if the specified person is our friend or not
 */
int query_friend( string who ) {
    return member_array( who, query_friends() ) != -1;
} /* query_friend() */
