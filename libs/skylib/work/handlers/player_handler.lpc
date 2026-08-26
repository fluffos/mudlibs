/**
 * A hander to allow the testing of values on players when they aren't logged
 * in.  These methods used to exist in the login object but now they're here.
 * <p>
 * @author Ceres
 * @change Partly rewritten to make it faster, and added support for finger
 * info - Sandoz, 2002.
 */

#include <finger.h>

inherit "/global/player/family";

#define MAX_CACHE_SIZE 100
#define CACHE_TIMEOUT  900
#define INACTIVE_LIMIT 604800

class player_info {
    int cached;
    int touched;
    int gender;
    int active;
    int level;
    int age;
    int last;
    int start_time;
    string password;
    string real_name;
    string email;
    string icq;
    string homepage;
    string birthday;
    string location;
    string home_dir;
    string last_on_from;
    string deity;
    string family_name;
    string signature;
    string project;
    string plan;
    string reference;
    mapping map_prop;
}

private int gender, time_on, last_log_on, activity_counter, start_time;
private string password, deity, last_on_from, home_dir;
private mapping aliases, map_prop, new_skills, player_info;

private nosave mapping player_cache;
private nosave int requests, cache_hits;

/** @ignore yes */
void create() {
    player_cache = ([ ]);
} /* create() */

/** @ignore yes */
void clean_cache() {
    string name;

    foreach( name in keys(player_cache) )
        if( player_cache[name]->cached < time() - CACHE_TIMEOUT )
            map_delete( player_cache, name );

} /* clean_cache() */

/** @ignore yes */
private varargs string make_sig( mixed stuff, int flag ) {
    string ret;
    int i, lines;

    if( !sizeof(stuff) ) {
        if( flag )
            return 0;
        return "";
    }

    ret = replace( (string)FINGER_H->make_string( stuff ), ";", "\n");

    if( flag )
        return ret;

    ret += "\n";

    for( i = lines = 0; i < sizeof( ret ) && lines < 4; i++ ) {
        if( ret[ i ] == '\n')
            lines++;
    }

    return "\n--\n"+ret[0..i-1]+"%^RESET%^";

} /* make_sig() */

/** @ignore yes */
private int validate_name( string name ) {
    if( !name || !stringp(name) || name == "logon" || name[0] == '.' ||
        ( sscanf( name, "%*s %*s") == 2 ) || strlen(name) < 2 ||
        sizeof( explode( name, "..") ) > 1 )
        return 0;

    return 1;

} /* validate_name() */

/**
 * This method will load in the player file.  It will return 0 if the player
 * file either does not exist or the input string is incorrect.
 * @param name the name to try and read in
 * @return 1 if the player file exists, 0 if not
 */
int load_player( string name ) {
    class player_info tmp;
    string pfile, dfile;
    mixed file;
    int diff;

    if( !validate_name(name) )
        return 0;

    requests++;

    // Check if we have a cached copy of this file.
    // If so, only use the cached copy if the cached time * 10 is less
    // than the last touched time ie. files which were modified recently
    // should be cached for less time.
    if( player_cache[name] ) {
        if( ( time() - player_cache[name]->cached ) * 10 <
            ( time() - player_cache[name]->touched ) ) {
            cache_hits++;
            return 1;
        }
    }

    pfile = LOGIN_OBJ->query_player_file_name(name);
    dfile = LOGIN_OBJ->query_delete_player_file_name(name);

    // Check if the file exists and get info about it.
    file = unguarded( (: get_dir, pfile+".o", -1 :) );
      if( !sizeof(file) || file[0][1] < 0 ) {
        file = unguarded( (: get_dir, dfile+".o", -1 :) );
        if( !sizeof(file) || file[0][1] < 0 )
            return 0;
    }

    // If we've got a cached copy of this file see if the original's touched
    // time is the same as that for our copy, if so use the cached copy
    // and update the 'cached' time.
    if( player_cache[name] && player_cache[name]->touched == file[0][2] ) {
        player_cache[name]->cached = time();
        cache_hits++;
        return 1;
    }

    // Restore the file and setup the data.
    if( !unguarded( (: restore_object, pfile :) ) &&
        !unguarded( (: restore_object, dfile :) ) )
        return 0;

    if( !mapp( map_prop ) )
        map_prop = ([ ]);
    if( !mapp(aliases) )
        aliases = ([ ]);
    if( !mapp(player_info) )
        player_info = ([ ]);

    tmp = new( class player_info,
               cached       : time(),
               touched      : file[0][2],
               gender       : gender,
               active       : 0,
               level        : 0,
               age          : time_on,
               last         : last_log_on,
               start_time   : start_time,
               password     : password,
               real_name    : player_info["real_name"],
               email        : player_info["email"],
               icq          : player_info["icq"],
               homepage     : player_info["homepage"],
               birthday     : player_info["birthday"],
               location     : player_info["location"],
               home_dir     : home_dir,
               last_on_from : last_on_from,
               deity        : deity,
               family_name  : query_family_name(),
               signature    : make_sig( aliases[".signature"] ),
               project      : make_sig( aliases[".project"], 1 ),
               plan         : make_sig( aliases[".plan"], 1 ),
               reference    : make_sig( aliases[".reference"], 1 ),
               map_prop     : map_prop );

    // Are they active.
    diff = ( time() - last_log_on ) / (3600 * 24 * 7);
    diff *= 10;
    tmp->active = ( activity_counter - diff ) > -50;

    // Calculate their level
    tmp->level = (int)STD_GUILD_OBJ->query_level(TO);
    player_cache[name] = tmp;

    if( sizeof(player_cache) > MAX_CACHE_SIZE &&
        find_call_out("clean_cache") == -1 )
        call_out("clean_cache", 60 );

    return 1;

} /* load_player() */

/**
 * This method returns all the info needed for a player's finger.
 * If the player is online, the updated values will be gotten
 * straight from the player object.
 * @param name the player to get the data for
 * @return the player info for the player
 */
class finger_info query_finger_info( string name ) {
    object ob;
    class player_info tmp;

    if( !ob = find_player(name) ) {
        if( !load_player(name) )
            return 0;
        tmp = player_cache[name];
    }

    if( ob ) {
        return new( class finger_info,
            gender       : ob->query_gender(),
            age          : ob->query_time_on(),
            last         : ob->query_last_log_on(),
            start_time   : ob->query_start_time(),
            real_name    : ob->query_real_name(),
            email        : ob->query_email(),
            icq          : ob->query_icq(),
            homepage     : ob->query_homepage(),
            birthday     : ob->query_birthday(),
            location     : ob->query_where(),
            home_dir     : ob->query_home_dir(),
            last_on_from : ob->query_last_on_from(),
            project      : make_sig( ob->query_player_alias(".project"), 1 ),
            plan         : make_sig( ob->query_player_alias(".plan"), 1 ) );
    }

    return new( class finger_info,
           gender       : tmp->gender,
           age          : tmp->age,
           last         : tmp->last,
           start_time   : tmp->start_time,
           real_name    : tmp->real_name,
           email        : tmp->email,
           icq          : tmp->icq,
           homepage     : tmp->homepage,
           birthday     : tmp->birthday,
           location     : tmp->location,
           home_dir     : tmp->home_dir,
           last_on_from : tmp->last_on_from,
           project      : tmp->project,
           plan         : tmp->plan );

} /* query_finger_info() */

/**
 * This method figures out if the user exists even if they are not on.
 * @param str the name of the user
 * @return 1 if they exist, 0 if they do not
 */
int test_user( string str ) {
    if( find_player(str) )
        return 1;

    if( !validate_name(str) )
        return 0;

    return file_size( LOGIN_OBJ->query_player_file_name(str)+".o") > 0 ||
           file_size( LOGIN_OBJ->query_delete_player_file_name(str)+".o") > 0;

} /* test_user() */

/**
 * This method determines the gender of the player even if they are
 * not currently on
 * @param str the name of the user
 * @return the player's gender
 * @see /std/living/gender.c
 */
int test_gender( string str ) {
    object ob;

    if( ob = find_player(str) )
        return ob->query_gender();

    if( !load_player(str) )
        return 0;

    return ((class player_info)player_cache[str])->gender;

} /* test_gender() */

/**
 * This method determines if a player is still active.
 * If you need to perform this on a lot of players please use the noload
 * parameter. When noload is set to 1 test_active will not attempt to load
 * the player file if it isn't currently loaded and will instead just do a
 * simple calculation of the players last login time. This is less accurate
 * but avoids lagging the mud.
 * @param player the name of the user
 * @param noload optional parameter to prevent test_active() loading the
 * player file.
 * @return active or inactive (1 or 0)
 */
varargs int test_active( string player, int noload ) {
    mixed file;

    if( find_player(player) )
        return 1;

    if( noload ) {
        if( player_cache[player] )
            return ((class player_info)player_cache[player])->active;
        file = unguarded( (: stat,
               LOGIN_OBJ->query_player_file_name(player)+".o" :) );
        return ( sizeof(file) && file[1] > time() - INACTIVE_LIMIT );
    }

    if( !load_player(player) )
        return 0;

    return ((class player_info)player_cache[player])->active;

} /* test_active() */

/**
 * This method determines the level of the player even if they are
 * not currently on
 * @param str the name of the user
 * @return the players level
 */
int test_level( string str ) {
    object ob;

    if( ob = find_player(str) )
        return ob->query_level();

    if( !load_player(str) )
        return 0;

    return ((class player_info)player_cache[str])->level;

} /* test_level() */

/** @ignore yes */
mapping query_skills()  {
    if( mapp( new_skills ) )
        return new_skills;
    return ([ ]);
} /* query_skills() */

/**
 * This method checks to see if the name is banished of not.
 * @param name the check for banishment.
 * @return 1 if it banished, 0 if not
 */
int test_banished( string name ) {
    return !(string)BASTARDS_H->query_player_ob( name, 0 );
} /* test_banished() */

/**
 * This method determines the real name of the player even if they are
 * not currently on
 * @param str the name of the user
 * @return the players real name
 */
string test_real_name( string str ) {
    object ob;

    if( ob = find_player(str) )
        return ob->query_real_name();

    if( !load_player(str) )
        return 0;

    return ((class player_info)player_cache[str])->real_name;

} /* test_real_name() */

/**
 * This method determines the ICQ number information of the player
 * even if they are not currently on.
 * @param str the name of the user
 * @return the players ICQ number as a string
 */
string test_icq( string str ) {
    object ob;

    if( ob = find_player(str) )
        return ob->query_icq();

    if( !load_player(str) )
        return 0;

    return ((class player_info)player_cache[str])->icq;

} /* test_icq() */

/**
 * This method determines the email of the player even if they are
 * not currently on.
 * @param str the name of the user
 * @return the players email
 */
string test_email( string str ) {
    object ob;

    if( ob = find_player(str) )
        return ob->query_email();

    if( !load_player(str) )
        return 0;

    return ((class player_info)player_cache[str])->email;

} /* test_email() */

/**
 * This method determines the homepage of the player even if they are
 * not currently on.
 * @param str the name of the user
 * @return the players homepage
 */
string test_homepage( string str ) {
    object ob;

    if( ob = find_player(str) )
        return ob->query_homepage();

    if( !load_player(str) )
        return 0;

    return ((class player_info)player_cache[str])->homepage;

} /* test_homepage() */

/**
 * This method returns the current value of the property on the
 * player, even if they are not currently on.
 * @param name the player name
 * @param str the property to query
 * @return the value of the property
 */
mixed test_property( string name, string str ) {
    object ob;

    if( ob = find_player(name) )
        return ob->query_property(str);

    if( !load_player(name) )
        return 0;

    return ((class player_info)player_cache[name])->map_prop[str];

} /* test_property() */

/**
 * This method updates the cached properties, it's called by
 * /secure/login.
 */
void special_add_property( string player, string prop, mixed value ) {
    if( player_cache[player] )
        player_cache[player]->map_prop[prop] = value;
} /* special_add_property() */

/**
 * This method determines the deity of the player even if they are
 * not currently on.
 * @param str the name of the user
 * @return the players deity
 */
string test_deity( string str ) {
    object ob;

    if( ob = find_player(str) )
        return ob->query_deity();

    if( !load_player(str) )
        return 0;

    return ((class player_info)player_cache[str])->deity;

} /* test_deity() */

/**
 * This method determines the age of the player even if they are
 * not currently on.
 * @param str the name of the user
 * @return the players age
 */
int test_age( string str ) {
    object ob;

    if( ob = find_player(str) )
        return ob->query_time_on();

    if( !load_player(str) )
        return 0;

    return ((class player_info)player_cache[str])->age;

} /* test_age() */

/**
 * This method determines the last log on of the player
 * even if they are not currently on.
 * @param str the name of the user
 * @return the player's last log on
 */
int test_last( string str ) {
    object ob;

    if( ob = find_player(str) )
        return ob->query_last_log_on();

    if( !load_player(str) )
        return 0;

    return ((class player_info)player_cache[str])->last;

} /* test_last() */

/**
 * This method determines the time the player started at.
 * @param str the name of the user
 * @return the player's start time
 */
int test_start_time( string str ) {
    object ob;

    if( ob = find_player(str) )
        return ob->query_start_time();

    if( !load_player(str) )
        return 0;

    return ((class player_info)player_cache[str])->start_time;

} /* test_start_time() */

/**
 * This method returns the player's family name.
 * @param str the name of the user
 * @return the player's family name
 */
string test_family( string str ) {
    object ob;

    if( ob = find_player(str) )
        return ob->query_family_name();

    if( !load_player(str) )
        return 0;

    return ((class player_info)player_cache[str])->family_name;

} /* test_family() */

/**
 * This method returns the player's birthday date.
 * @param str the name of the user
 * @return the player's birthday
 */
string test_birthday( string str ) {
    object ob;

    if( ob = find_player(str) )
        return ob->query_birthday();

    if( !load_player(str) )
        return 0;

    return ((class player_info)player_cache[str])->birthday;

} /* test_birthday() */

/**
 * This method returns the player's location.
 * @param str the name of the user
 * @return the player's location
 */
string test_location( string str ) {
    object ob;

    if( ob = find_player(str) )
        return ob->query_where();

    if( !load_player(str) )
        return 0;

    return ((class player_info)player_cache[str])->location;

} /* test_location() */

/** @ignore yes */
int test_password( string name, string pass ) {
    if( !load_player(name) )
        return 0;

    // Have to do this since its the only function that requires restoring
    // from a file if the player is active!
    if( find_player(name) && player_cache[name]->password == "") {
        unguarded( (: restore_object,
            LOGIN_OBJ->query_player_file_name(name) :) );
        player_cache[name]->password = password;
    }

    return crypt( pass, player_cache[name]->password ) ==
                        player_cache[name]->password;

} /* test_password() */

/** @ignore yes */
string get_password( string name ) {
    if( file_name(PO) != SECURE_HANDLER_DIR "/ftp_auth")
        return "x";

    if( !load_player(name) )
        return "x";

    if( find_player(name) && player_cache[name]->password == "") {
        unguarded( (: restore_object,
            LOGIN_OBJ->query_player_file_name(name) :) );
        player_cache[name]->password = password;
    }

    return ((class player_info)player_cache[name])->password;

} /* get_password() */

/**
 * This method returns the signature to use on posts for the player
 * even when they are off line.
 * @param name the name of the player
 * @return the signature, "" if none
 */
string query_signature( string name ) {
    object ob;

    if( ob = find_player(name) )
        return make_sig( ob->query_player_alias(".signature") );

    if( !load_player(name) )
        return "";

    return ((class player_info)player_cache[name])->signature;

} /* query_signature() */

/**
 * This method returns the project to use in the player's finger,
 * even when they are off line.
 * @param name the name of the player
 * @return the project or 0, if none
 */
string query_project( string name ) {
    object ob;

    if( ob = find_player(name) )
        return make_sig( ob->query_player_alias(".project"), 1 );

    if( !load_player(name) )
        return 0;

    return ((class player_info)player_cache[name])->project;

} /* query_project() */

/**
 * This method returns the plan to use in the player's finger,
 * even when they are off line.
 * @param name the name of the player
 * @return the plan or 0, if none
 */
string query_plan( string name ) {
    object ob;

    if( ob = find_player(name) )
        return make_sig( ob->query_player_alias(".plan"), 1 );

    if( !load_player(name) )
        return 0;

    return ((class player_info)player_cache[name])->plan;

} /* query_plan() */

/**
 * This method returns the reference string to use in the player's refer,
 * even when they are off line.
 * @param name the name of the player
 * @return the reference string or 0, if none
 */
string query_reference( string name ) {
    object ob;

    if( ob = find_player(name) )
        return make_sig( ob->query_player_alias(".reference"), 1 );

    if( !load_player(name) )
        return 0;

    return ((class player_info)player_cache[name])->reference;

} /* query_reference() */

/**
 * This method should be called whenever a player logs on, or
 * is refreshed, so that we wouldn't have outdated data in the cache.
 * @param name the name of the player to delete from the cache
 */
void delete_from_cache( string name ) {
    map_delete( player_cache, name );
} /* delete_from_cache() */

/** @ignore yes */
mixed stats() {
    int percentage;

    if( requests )
        percentage = ( cache_hits * 100 ) / requests;

    return ({
        ({ "cache size", sizeof(player_cache) }),
        ({ "requests", requests }),
        ({ "cache hits", cache_hits }),
        ({ "cache misses", requests - cache_hits }),
        ({ "percentage hits", percentage }),
        });
} /* stats() */

/** @ignore yes */
nomask int query_prevent_shadow( object ob ) { return 1; }
