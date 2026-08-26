/**
 * This file contains the code to handle forcing.
 * The method used will be to ask the object to do the command.
 * While this is similar to the original method of doing this
 * it will be used to be more in the style of asking things to
 * do things, rather than the making things do things without
 * asking them first.
 * @author Furball
 */

#include <player.h>

#define FORCE_COST 1
#define ILLEGAL_FORCE ({ "alias", "unalias", "mv", "mkdir", "call", "rm", \
                         "force", "kill", "gauge", "exec", "promote", \
                         "skullwarn", "fry", "meteor", "swat", "whoop", "hammer", \
                         "new_domain", "rmdir", "cd", "history", "echoall", \
                         "shout" })

nosave int no_force_me;

protected int no_force(string str);
protected int do_force(object *obs, string str);

/**
 * These are the commands which will allow people to force others.
 * @see no_force()
 * @see do_force()
 */
void force_commands() {
    if( seniorp(TO) ) {
        add_command("force", "<indirect:distant-living> <string'command'>",
          (: do_force( $1, $4[1] ) :) );
    }
    if( lordp(TO) ) {
        add_command("noforce", "{on|off}", (: no_force($4[0]) :));
        add_command("noforce", "", (: no_force(0) :));
    }
} /* force_commands() */

/**
 * This method is used to set the ability to let yourself be forced on and
 * off.
 * @param str the string which is on, off or 0
 * @see force_commands()
 */
protected int no_force(string str) {
    if( str == "on" ) {
        no_force_me = 1;
        write("Ok, forcing you disabled.\n");
        return 1;
    }
    if( str == "off" ) {
        no_force_me = 0;
        write("Ok, forcing you enabled.\n");
        return 1;
    }
    write("Forcing you is currently ");
    if( no_force_me ) {
        write("disabled.\n");
    } else {
        write("enabled.\n");
    }
    return 1;
} /* no_force() */

/**
 * This is the function which forces another player to do something.
 * @see do_force_on_me()
 * @see force_commands()
 */
protected int do_force( object *obs, string str ) {
    object ob;

#ifdef PLAYERS_CAN_FORCE
    if( userp(TP) && !TP->query_property("force") ) {
        notify_fail("You do not have the ability to do that yet.\n");
        return 0;
    }
    if( TP->adjust_social_points(-FORCE_COST) < 0 ) {
        notify_fail("Insufficient social points.\n");
        return 0;
    }
#endif

    foreach( ob in obs ) {
        if( !ob->do_force_on_me( str ) ) {
            write( CAP( ob->query_name() )+" didn't want to do that.\n");
        }
    }
    write("Ok.\n");
    return 1;
} /* do_force() */

/**
 * This is the method called to do the actual force.
 * @param str the string to force us to do
 * @see do_force()
 */
nomask int do_force_on_me( string str ) {
    string temp1, temp2;
    object forcer;

    forcer = this_player(1);
    if( !forcer || ( TP != PO ) ) {
        if( interactive( PO ) ) {
            forcer = PO;
        } else {
            log_file("FORCE", "Attempted illegal force from "+
              file_name(PO)+"\n");
            return 0;
        }
    }

    log_file("FORCE", ctime(time()) + " " + forcer->query_name()+" "+
      TO->query_name()+" : " + str );
    tell_object( TO, forcer->query_cap_name()+" tries to force you to : "+str+"\n");
    if( no_force_me ) {
        event( users(), "inform", forcer->query_cap_name()+" forces "+
          TO->query_name()+" to "+str+" (failed)", "force");
        log_file("FORCE", " (failed)\n");
        return 0;
    }
    if( sscanf( str, "%s %s", temp1, temp2 ) != 2 ) {
        temp1 = str;
    }

    /* delete this at your own peril */
    if( member_array( temp1, ILLEGAL_FORCE ) != -1 && !adminp(forcer) ) {
        event( users(), "inform", forcer->query_cap_name()+" forces "+
          TO->query_name()+" to : "+str+" (failed)", "force");
        log_file("FORCE", " (failed)\n");
        return 0;
    }

    if( function_exists("eventForce", TO ) ) {
        TO->eventForce(str);
        event( users(), "inform", forcer->query_cap_name()+" forces "+
          TO->query_name()+" to : "+str, "force");
        log_file("FORCE", " (succeeded)\n");
    } else {
        event( users(), "inform", forcer->query_cap_name()+" forces "+
          TO->query_name()+" to : "+str+" (failed)", "force");
        log_file("FORCE", " (failed)\n");
    }

    return 1;

} /* do_force_on_me() */
