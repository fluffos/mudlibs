/**
 * This file contains all the file related commands and information
 * for the creators.
 * @author Pinkfish
 */

#include <creator.h>

inherit "/global/creator/wiz_object_comm";
inherit "/global/player";
inherit "/global/creator/wiz_info_comm";
inherit "/global/creator/wiz_inter_comm";

private int invis;
private string *allowed;
private nosave string *dir_list;
private nosave mixed last_location;

private int change_dir(string str);
private int pushd(string str);
private int popd();
private int set_home_dir(string str);
private int visible();
private int invisible(string level);
private int allow(string word);
private int disallow(string word);

protected void create() {
    player::create();
    wiz_object_comm::create();
    allowed = ({ });
} /* create() */

/**
 * This method adds in all the creator commands to the player.  This
 * will be called when the play initialy logs onto the game.
 */
protected void wiz_commands() {
    mixed lvl;

    /* Get the commands from the inherited objects. */
    wiz_object_comm::wiz_commands();
    wiz_info_comm::wiz_commands();
    wiz_inter_comm::wiz_commands();

    /* Setup our local commands. */
    add_command("cd", TO, "<string'directory'>", (: change_dir($4[0]) :) );
    add_command("cd", TO, "", (: change_dir(0) :) );
    add_command("pushd", TO, "<string'directory'>", (: pushd($4[0]) :) );
    add_command("pushd", TO, "", (: pushd(0) :) );
    add_command("popd", TO, "", (: popd() :) );
    add_command("homedir", TO, "<string'directory'>", (: set_home_dir($4[0]) :) );
    add_command("visible", TO, "", (: visible() :) );
    add_command("vis", TO, "", (: visible() :) );

    lvl = ({ });

    if( creatorp(TO) )
        lvl += ({"1"});
    if( lordp(TO) )
        lvl += ({"2"});
    if( adminp(TO) )
        lvl += ({"3"});

    if( sizeof(lvl) > 1 ) {
        lvl = "{"+implode( lvl, "|")+"}";
        add_command("invis", TO, lvl, (: invisible($4[0]) :) );
        add_command("invisible", TO, lvl, (: invisible($4[0]) :) );
    }

    add_command("invis", TO, "", (: invisible("1") :) );
    add_command("invisible", TO, "", (: invisible("1") :) );

    add_command("allow", TO, "<word'name'>", (: allow($4[0]) :) );
    add_command("allow", TO, "", (: allow(0) :) );
    add_command("disallow", TO, "<word'name'>", (: disallow($4[0]) :) );
    add_command("disallow", TO, "all", (: disallow("all") :) );

} /* wiz_commands() */

/**
 * This method returns the current invisibility level of the object.
 * This will return 0 if the object is not invisible, 1 for creator
 * invisible, 2 for lord invisible and 3 for high lord invisible.
 * @return the current invisibility level
 */
nomask int query_invis() { return invis; }

/**
 * This method is used to set invisibility internally.
 */
protected nomask int set_invis( int level ) {
    if( PO != TO && base_name(PO) != LOGIN_OBJ )
        return 0;

    switch( level ) {
      case 3 :
        if( !adminp(TO) )
            return 0;
      break;
      case 2 :
        if( !lordp(TO) )
            return 0;
      break;
      default :
        // Seriously this could never happen. But lets be redundant.
        if( !creatorp(TO) )
            return 0;
    }

    invis = level;

    return invis;

} /* set_invis() */

/**
 * This method returns the current list of people in the allowed array for
 * the creator.
 * @return the current list of allowed people
 */
nomask string *query_allowed() { return copy(allowed); }

/**
 * This method is called by the visible command to make the creator
 * become visible.
 * @return 1 on success
 */
private int visible() {
    if( GetForced() )
        return 0;

    if( !query_invis() )
        return notify_fail("You are already visible.\n");

    if( invis >= 2 ) {
        invis = 0;
        LOGIN_H->player_logon(query_name());
    } else {
        invis = 0;
    }

    write("You appear.\n");
    return 1;

} /* visible() */

/**
 * This method is called by the invisible command to make the creator
 * turn invisible.
 * @return 1 on success, 0 on failure
 */
private int invisible( string word ) {
    int max, type;

    if( GetForced() )
        return 0;

    if( !word ) {
       word = sprintf("%d", query_invis() );
       if( word == "0")
           word = "1";
    }

    max = 1;

    if( lordp(query_name()) )
        max++;

    if( adminp(query_name()) )
        max++;

    if( !sscanf( word, "%d", type ) || type > max || type < 1 ) {
        return notify_fail("Syntax: invisible [1"+( max > 1 ? "|2" : "")+
                          ( max > 2 ? "|3" : "")+"]\n");
    }

    word = ({"creator", "Lord", "Admin"})[type-1];

    if( type == query_invis() )
        return notify_fail("You are already "+ word +" invisible.\n");

    if( type < invis && type < 2 && invis >= 2 ) {
        invis = type;
        LOGIN_H->player_login(query_name());
    } else {
        invis = type;
    }

    write("You become "+word+" invisible.\n");
    return 1;

} /* invisible() */

/**
 * This method adds someone to the current allow list of the creator.
 * People on the allow list can see the creator while they are
 * invisible.
 * @param word the person to add to the allow string
 * @return 1 on success, 0 on failure
 */
private int allow( string word ) {
    if( !word ) {
        if( !sizeof(allowed) ) {
            write("You are not allowing anyone to refer to you.\n");
        } else {
            string *ret = allowed;

            if( member_array("friends", allowed ) != -1 )
                ret += map( query_friends() - allowed, (: $1+" (friend)" :) );

            if( member_array("playtesters", allowed ) != -1 )
                ret += map( PLAYTESTERS_H->query_playtesters() - allowed -
                    query_friends(), (: $1+" (PT)" :) );

            write("You are currently allowing "+query_multiple_short(
                map( sort_array( ret, 1 ), (: CAP( $1 ) :) ) )+" to refer "
                "to you.\n");
        }
        return 1;
    }

    word = lower_case(word);

    if( word != "friends" && word != "playtesters" &&
        !PLAYER_H->test_user(word) )
        return notify_fail("There is no user called "+CAP(word)+".\n");

    if( member_array( word, allowed ) != -1 )
        return notify_fail("You have already allowed "+CAP(word)+" to "
                           "refer to you.\n");

    if( member_array("friends", allowed ) != -1 && TO->query_friend(word) )
        return notify_fail("You have already allowed "+CAP(word)+" to "
                           "refer to you (as a friend).\n");

    if( member_array("friends", allowed ) != -1 && playtesterp(word) )
        return notify_fail("You have already allowed "+CAP(word)+" to "
                           "refer to you (as a playtester).\n");

    allowed += ({ word });

    write( word+" is now allowed to refer to you while invisible.\n");
    return 1;

} /* allow() */

/**
 * This method removes someone from the current allow list of the
 * creator.  People on the allow list can see the creator while they are
 * invisible.
 * @param word the person to remove to the allow string
 * @return 1 on success, 0 on failure
 */
private int disallow( string word ) {
    if( word == "all" ) {
        allowed = ({ });
        write("Your allow list has been cleared.\n");
    } else {
        word = lower_case(word);
        if( member_array( word, allowed ) == -1 ) {
            string him;

            switch( PLAYER_H->test_gender( word ) ) {
              case 1:  him = "him"; break;
              case 2:  him = "her"; break;
              default: him = "it";
            }

            if( member_array("friends", allowed ) != -1 &&
                TO->query_friend(word) )
                return notify_fail( word+" is allowed to refer to you as a "
                    "friend and you cannot disallow "+him+" separately.\n"
                    "Please use 'disallow friends' or remove "+him+" from "
                    "your friends list instead.\n");

            if( member_array("playtesters", allowed ) != -1 &&
                playtesterp(word) )
                return notify_fail( word+" is allowed to refer to you as a "
                    "playtester and you cannot disallow "+him+" separately.\n"
                    "Please use 'disallow playtesters' instead.\n");

            return notify_fail( word+" is already not on your allow list.\n");

        }
        allowed -= ({ word });
        write( word+" is no longer allowed to refer to you.\n");
    }

    return 1;

} /* disallow() */

/**
 * This method returns the current visibility status of this creator
 * in respect to the other object.  This does the allow level checking
 * and all sorts of exciting things.
 * <p>
 * It will return 1 for creator invisible, 2 for lord invisible, 3 for
 * high lord invisible.
 * @param thing the object to test the visibility against
 * @return 0 if not invisible, non-zero if invisible
 */
int query_visible( object thing ) {
    string word;

    if( thing == TO )
        return 1;

    // NOTE: If you change this function, then don't forget to change the
    // reference_allowed simul_efun/efun as well.
    // - Sandoz.
    word = thing->query_name();

    if( ( member_array( word, allowed ) != -1 ) ||
        ( member_array("friends", allowed ) != -1 && query_friend(word) ) ||
        ( member_array("playtesters", allowed ) != -1 && playtesterp(word) ) )
        return ::query_visible(thing);

    switch( query_invis() ) {
      case 3 :
        return adminp(word);
      case 2 :
        return lordp(word);
      case 1 :
        return creatorp(thing);
      default :
        return ::query_visible(thing);
    }

} /* query_visible() */

/**
 * This method is called by the cd command and causes the
 * creator to change their current working directory.
 * @param str the new working directory
 * @return 1 on success, 0 on failure
 */
private int change_dir( string str ) {
    string *filenames;
    object *obs;

    if( GetForced() )
        return 0;

    if( !str ) {
        if( !query_home_dir() )
            return notify_fail("You have no home directory.  "
                "Use 'homedir' to set it.\n");
        str = query_home_dir();
    }

    switch( sizeof( filenames = get_files(str) ) ) {
      case 0:
        switch( sizeof( obs = WIZ_PRESENT->wiz_present( str, TO ) ) ) {
          case 0:
            return notify_fail("No such directory.\n");
          case 1:
            filenames = map( obs, (: sprintf("/%s",
                implode( explode( file_name($1), "/")[0..<2], "/") ) :) );
          break;
          default:
            return notify_fail("Ambiguous directory.\n");
        }
      break;
      case 1:
      break;
      default:
        return notify_fail("Ambiguous directory.\n");
    }

    if( !dir_exists( str = filenames[0] ) )
        printf("cd: %s: Not a directory.\n", str );
    else
        set_current_path(str);

    printf("%s\n", query_current_path() );
    return 1;

} /* change_dir() */

/**
 * This method is called by the pushd command.
 * @return 1 on success, 0 on failure
 * @param str the new working directory
 */
private int pushd( string str ) {
    if( !dir_list )
        dir_list = ({ });

    dir_list += ({ query_current_path() });

    return change_dir(str);

} /* pushd() */

/**
 * This method is called by the popd command.
 * @return 1 on success, 0 on failure
 */
private int popd() {
    if( sizeof(dir_list) ) {
        string dest = dir_list[<1];
        dir_list = dir_list[0..<2];
        return change_dir(dest);
    }

    return 0;

} /* popd() */

/**
 * This method sets the home directory of the player.  It is called
 * by the homedir command.
 * @param str the new home directory
 * @return 0 on failure and 1 on success
 */
private int set_home_dir( string str ) {
    if( GetForced() )
        return 0;

    if( str )
        ::set_home_dir( get_path(str) );

    printf("Home directory set to %s.\n", query_home_dir() );
    return 1;

} /* set_home_dir() */

/**
 * This method returns the saved setup for the inbuild ed command.  THis
 * allows certain flag settings to be saved between sessions.
 * @return the current ed setup flags
 * @see set_ed_setup()
 */
int query_ed_setup() { return query_property("ed_setup"); }

/**
 * This method sets the current flags for the inbuild ed command.  THis
 * allows certain flag settings to be saved between sessions.
 * @param i the new flags for the ed command
 * @see query_ed_setup()
 */
void set_ed_setup( int i ) { add_property("ed_setup", i ); }

/**
 * This method prints out any interesting bits of reviewable information
 * available on the creator.  This is used by the review command.
 * @return always returns 1
 */
int review() {
    player::review();
    wiz_info_comm::review();
    return 1;
} /* review() */

/**
 * This method stores the last location of the creator for use by goback.
 * @param string location
 */
void set_last_location(mixed loc) { last_location = loc; }

/**
 * This method returns the last location of the creator for use by goback.
 * @return string last location.
 */
mixed query_last_location() { return last_location; }
