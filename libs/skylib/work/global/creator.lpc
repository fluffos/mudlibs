/**
 * This is the creator player object.  It gives the creators the
 * bonus extra commands needed by happy creators.
 * @author Pinkfish
 * @see /global/player.c
 */

#include <login_handler.h>
#include <rank.h>
#include <command.h>

inherit "/global/creator/wiz_file_comm";

private string creator_title;

#define ECHO_ALLOWED

protected int do_qsnoop( object *obs );
protected int clean_up_files( string word );
protected int bulk_delete( string word );
protected int set_creator_title( string str );

/** @ignore yes */
void move_player_to_start( string bong, int bing, string c_name,
                           string ident, int go_invis ) {

    if( base_name(PO) != LOGIN_OBJ )
        return 0;

    ::move_player_to_start( bong, bing, c_name, ident );

    cat("doc/CREATORNEWS");

    if( lordp(geteuid(TO)) )
        cat("doc/LORDNEWS");

    switch( go_invis ) {
      case -1 :
        set_invis( 0 );
      break;
      case 1 :
        set_invis( creatorp(TO) + lordp(TO) + adminp(TO) );
      break;
      default :
    }

    switch( query_invis() ) {
      case 3 :
        tell_object( TO, "===> You are currently Admin invisible! <===\n");
      break;
      case 2 :
        tell_object( TO, "===> You are currently Lord invisible! <===\n");
      break;
      case 1 :
        tell_object( TO, "===> You are currently invisible! <===\n");
      break;
      default :
    }

    add_command("cretitle", TO, "", (: set_creator_title( 0 ) :) );
    add_command("cretitle", TO, "<string'title'>",
        (: set_creator_title( $4[0] ) :) );
    add_command("cretitle", TO, "reset", (: set_creator_title("reset") :) );

    if( lordp(geteuid(TO)) )
        add_command("qsnoop", TO, "<indirect:player>",
            (: do_qsnoop($1) :) );
        add_command("qsnoop", TO, "", (: do_qsnoop :) );
        add_command("bulk_delete", TO,
            "{a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z}",
            (: bulk_delete($4[0]) :) );
        add_command("clean_up_files",  TO, "<word>",
            (: clean_up_files($4[0]) :) );

    if( adminp(geteuid(TO)) )
        AddSearchPath( ({ DIR_ADMIN_CMDS, DIR_SECURE_ADMIN_CMDS }) );

    if( lordp(geteuid(TO)) )
        AddSearchPath( ({ DIR_LORD_CMDS, DIR_SECURE_LORD_CMDS }) );

} /* move_player_to_start() */

/**
 * This method tells us if the object is a creator or not.
 * @return 1 if the object is a creator, 0 if not.
 */
int query_creator() { return 1; }

/** @ignore yes */
string query_object_type() {
    switch( rank(TO) ) {
      case ADMIN:
        return "A";
      case LORD:
        return "L";
      case SENIOR:
        return "S";
    }
    return "C";
} /* query_object_type() */

/**
 * This method is used by the snoop efun to allow creator to see
 * what other players are doing.
 * @param bing the message to receive
 */
void receive_snoop( string bing ) { tell_object( TO, "] "+bing ); }

/** @ignore yes */
void event_enter( object me, string s1, object from ) {
    if( lordp(geteuid(TO)) ) {
        if( ( !s1 || s1 == "") && interactive(me) ) {
            if( environment() == ENV(me) )
                event_inform( me, me->query_cap_name()+" invisibly enters "
                    "the room", "enter");
            else
                event_inform( me, me->query_cap_name()+" invisibly enters "
                    "your inventory", "enter");
        }
    }

    ::event_enter( me, s1, from );

} /* event_enter() */

/** @ignore yes */
void event_exit( object me, string s1, object from ) {
    if( lordp(geteuid(TO)) ) {
        if( (!s1 || s1 == "") && interactive(me) ) {
            if( environment() == ENV(me) )
                event_inform( me, me->query_cap_name()+" invisibly leaves "
                    "the room", "enter");
            else
                event_inform( me, me->query_cap_name()+" invisibly leaves "
                    "your inventory", "enter");
        }
    }

    ::event_exit( me, s1, from );

} /* event_exit() */

/** @ignore yes */
varargs int adjust_xp( int number, int shared ) {
    if( lordp(geteuid(TO)) ) {
        if( objectp(PO) )
            event_inform( PO, PO->query_name()+" ("+file_name(PO)+") gives "
                "you "+number+" xp", "xp");
    }

    return ::adjust_xp( number, shared );

} /* adjust_xp() */

/**
 * This method forces a bulk delete on a certain letter.
 * This letter will then be checked to see if any of
 * those players have timed out and should be deleted.
 * @param word the letter to bulk delete
 * @return 0 on falure and 1 on success
 */
protected int bulk_delete( string word ) {
    if( GetForced() )
        return 0;
    word = lower_case(word);
    return BULK_DELETE_H->delete_files(word);
} /* bulk_delete() */

/**
 * This method forces the clean up of certain file son the
 * bulk deleter.  This cleans up all the files associated with
 * the given player.
 * @param word the name of the player to clean up
 * @return 1 on success, 0 on failure
 */
protected int clean_up_files( string word ) {
    if( GetForced() )
        return 0;
    return BULK_DELETE_H->clean_up_files(word);
} /* clean_up_files() */

/**
 * This method is used to do a quiet snoop on a player.
 * @param str the player to snoop
 * @return 1 on success, 0 on failure
 */
protected int do_qsnoop( object *obs ) {
    object targ;

    if( GetForced() )
        return 0;

    if( !obs || !sizeof(obs) ) {
        snoop( TO, 0 );
        write("Ok, qsnoop cancelled.\n");
        return 1;
    }

    targ = obs[0];

    if( !snoop( TO, targ ) )
        return notify_fail("You fail to qsnoop "+
            targ->query_cap_name()+".\n");

    write("Ok, qsnooping "+targ->query_cap_name()+".\n");
    return 1;

} /* do_qsnoop() */

/** @ignore yes */
protected int set_creator_title( string str ) {
    string s;

    if( !str || str == "") {
        write("Your creator title is currently set to: "+creator_title+".\n");
        return 1;
    }

    if( str == "reset") {
        creator_title = "";
        write("Resetting your creator title.\n");
        return 1;
    }

    if( strlen( strip_colours(str) ) > 60 )
        return notify_fail("Titles have to be 50 chars or less.\n");

    s = lower_case( str );

    if( strsrch( s, "apprentice") != -1 ||
        strsrch( s, "creator") != -1 ||
        strsrch( s, "liaison") != -1 ||
        strsrch( s, "lord") != -1 ||
        strsrch( s, "invisible") != -1 ||
        strsrch( s, "admin") != -1 )
        return notify_fail("You cannot set your title to Admin, "
            "Apprentice, Creator, Liaison, Lord, or Invisible.\n");

    creator_title = str;

    write("You set your creator title to: "+str+".\n");
    return 1;

} /* set_creator_title */

/** @ignore yes */
string query_creator_title() { return creator_title || ""; }
