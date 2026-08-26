/**
 * This is the base object for creating typo, bug, idea etc reporting
 * commands from.  You should set the error type of the
 * object in its create function.  The use_last_error flag should
 * be set for those error report types which will need to use the last
 * runtime error on the player object.
 * @example
 * inherit "/cmds/report_base";
 *
 * void create() {
 *    ::create();
 *    set_error_type("TYPO");
 * } /\* create() *\/
 */

#include <log.h>
#include <command.h>
#include <user_parser.h>

class errors {
   int type;
   string file;
   string error;
}

#define ROOM_BUG    1
#define OBJECT_BUG  2
#define RITUAL_BUG  3
#define SPELL_BUG   4
#define HELP_BUG    5
#define COMMAND_BUG 6
#define GENERAL_BUG 7
#define SOUL_BUG    8

private nosave mapping _globals;
private nosave string _error_type;
private nosave int _use_last_error;

void create() {
    _globals = ([ ]);
} /* create() */


/**
 * This sets the error type name.  The error type should be one
 * of "TYPO", "BUG", "IDEA".
 * @param type the type to set
 * @see query_verb()
 */
void set_error_type( string type ) { _error_type = type; }

/**
 * This sets the use_last_error flag.  If this flag is set to a non-zero
 * value then the last runtime error stored on the player object will
 * be attached to the error report.
 * @param error the new value of the last error flag
 */
void set_use_last_error( int error ) { _use_last_error = error; }

/**
 * This method returns the currently set value of the last error flag.
 * @return the current value of the last error flag
 */
int query_use_last_error() { return _use_last_error; }

/** @ignore yes */
int bug_room() {
    _globals[TP] = new( class errors,
                        type : ROOM_BUG,
                        error : "ROOM "+_error_type,
                        file : file_name(ENV(TP)) );

    TP->do_edit( 0, "end_of_edit");
    return 1;

} /* bug_room() */

/** @ignore yes */
int bug_general() {
    string dir, *bits, file;

    // For a general bug put it in the domains base directory.
    dir = file_name(ENV(TP));
    bits = explode( dir, "/");
    file = ( bits[0] == "d" ? implode(bits[0..1], "/")+"/general" : dir );

    _globals[TP] = new( class errors,
                        type : GENERAL_BUG,
                        error : "GENERAL "+_error_type,
                        file : file );

    TP->do_edit( 0, "end_of_edit");
    return 1;

} /* bug_general() */

/** @ignore yes */
int bug_command( string str ) {
    mixed coms;
    class command cmd;
    class errors bing;

    bing = new( class errors );
    cmd = new( class command, verb : str );
    coms = ({ });

    if( CMD_D->HandleStars(cmd) &&
        sizeof( ( coms = (mixed)CMD_D->GetPaths(cmd->verb ) &
        (mixed)TP->GetSearchPath() ) ) ) {
        bing->file = coms[0]+"/"+cmd->verb;
    } else {
        if( coms = TP->query_parse_command(str) ) {
            bing->file = base_name(coms[0][OBJS]);
        } else {
            if( coms = SOUL_H->query_soul_command(str) ) {
                bing->file = SOUL_H;
            } else if( _error_type == "IDEA") {
                bing->file = "/cmds/IDEA";
            } else {
                return notify_fail("Command "+str+" not found.\n");
            }
        }
    }

    bing->error = "COMMAND "+_error_type+" "+str;
    bing->type = COMMAND_BUG;

    _globals[TP] = bing;
    TP->do_edit(0, "end_of_edit");
    return 1;

} /* bug_command() */

/** @ignore yes */
int bug_soul( string str ) {
    mixed coms;
    class errors bing;

    bing = new( class errors );
    coms = ({ });

    if( coms = SOUL_H->query_soul_command(str) ) {
        bing->file = SOUL_H;
    } else if( _error_type == "IDEA" ) {
        bing->file = "/std/soul/IDEA";
    } else {
        return notify_fail("Soul command "+str+" not found.\n");
    }

    bing->error = "SOUL "+_error_type+" "+str;
    bing->type = SOUL_BUG;

    _globals[TP] = bing;
    TP->do_edit( 0, "end_of_edit");
    return 1;

} /* bug_soul() */

/** @ignore yes */
int bug_help( string str ) {
    mixed stuff;
    class errors bing;
    string tmp;

    bing = new( class errors );
    tmp = "/cmds/player/help"->query_synonym(str);
    if( strlen(tmp) )
        str = tmp;

    stuff = "/cmds/player/help"->query_help_on(str);
    if( !sizeof(stuff) )
        return notify_fail("Could not find the help file '"+str+"'.\n");

    sscanf( stuff[0][0], "%*s (%s)", bing->file );
    bing->error = "HELP "+_error_type+" "+str;
    bing->type = HELP_BUG;

    _globals[TP] = bing;
    TP->do_edit(0,"end_of_edit");
    return 1;

} /* bug_help() */

/** @ignore yes */
int bug_ritual( string str ) {
    mixed junk;
    class errors bing;

    if( !junk = TP->query_spell(str) ) {
        map_delete( _globals, TP );
        return notify_fail("Ritual "+str+" not found.\n");
    }

    bing = new( class errors );
    bing->file = junk[0];
    bing->error = "RITUAL "+_error_type+" "+str;
    bing->type = RITUAL_BUG;

    _globals[TP] = bing;
    TP->do_edit( 0, "end_of_edit");
    return 1;

} /* bug_ritual() */

/** @ignore yes */
int bug_spell( string str ) {
    mixed junk;
    class errors bing;

    if( !junk = TP->query_spell(str) ) {
        map_delete( _globals, TP );
        return notify_fail("Spell "+str+" not found.\n");
    }

    bing = new( class errors );
    bing->file = junk[0];
    bing->error = "SPELL "+_error_type+" "+str;
    bing->type = SPELL_BUG;

    _globals[TP] = bing;
    TP->do_edit( 0, "end_of_edit");
    return 1;

} /* bug_spell() */

/** @ignore yes */
int bug_object( object *obs, string str ) {
    object ob;
    string info, tmp;
    class errors bing;

    if( sizeof(obs) > 1 ) {
        notify_fail("More than one object can be identified with the name "+
            str+".  Please be more specific.\n");
        map_delete( _globals, TP );
        return 0;
    }

    ob = obs[0];
    bing = new( class errors );
    bing->file = base_name(ob);

    switch( bing->file ) {
      case "/std/room/basic/item" :
        bing->file = base_name(ENV(TP));
        if( sizeof( tmp = ob->short() ) )
            str = tmp;
        info = sprintf("Room item: %s.\n\n", str );
      break;
      case "/std/room/basic/door" :
        bing->file = base_name(ENV(TP));
        if( sizeof( tmp = ob->short() ) )
            str = tmp;
        info = sprintf("Room door: %s.\n\n", str );
      break;
      default:
        if( tmp = ob->query_property("virtual name") ) {
            bing->file = tmp;
            info = sprintf("VObject: %s, Object: %s\nName: %s, Short: %s\n\n",
                       tmp, bing->file, ob->query_name(), ob->short() );
        } else {
            info = sprintf("Name: %s, Short: %s\n\n",
                       ob->query_name(), ob->short() );
        }
    }

    bing->error = "OBJECT "+_error_type+" "+str;
    bing->type = OBJECT_BUG;

    _globals[TP] = bing;
    TP->do_edit( 0, "end_of_edit", 0, 0, info );
    return 1;

} /* bug_object() */

/** @ignore yes */
void end_of_edit( string body, string header ) {
    if( strlen(body) ) {
        int ending;
        string name, trace = 0;
        mapping last_error;
        class errors bing;

        bing = _globals[TP];

        if( body[<1] != '\n')
            ending = 1;

        if( ENV(TP) && bing->type != ROOM_BUG ) {
            if( ending ) {
                body += "\n";
                ending = 0;
            }
            body += sprintf("\nEnvironment: %s\n", file_name(ENV(TP)) );
        }
        body += sprintf("\nMudtime: %s\n", mudtime(time()) );

        if( _use_last_error ) {
            last_error = (mapping)TP->get_last_error();
            if( mapp(last_error) ) {
                trace = (string)master()->standard_trace( last_error, 1 );
                TP->set_last_error(0);
            }
        }

        if( ending )
            body += "\n";

        name = (string)TP->query_name();

        if( sizeof(header) )
            body = header + body;

        if( _error_type == "REPORT" ) {
            BOARD_H->add_message("ptreports", CAP(name), bing->error+" by "+
                CAP(name)+" ("+bing->file+")", body );
        } else {
            SMART_LOG->smart_log( bing->error, name, body, trace,
                bing->file );
        }

        PLAYTESTERS_H->report_made( name, bing->error, bing->file,
            body + (_use_last_error && trace ? "\nError:\n" + trace : "") );
        printf("Thank you for your "+( _error_type == "REPORT" ? "" : "%s ")+
            "report.\n", lower_case(_error_type) );
    } else {
        printf("Not saving "+( _error_type == "REPORT" ? "" : "%s ")+
            "report, aborting.\n", lower_case(_error_type) );
    }

    map_delete(_globals, TP );

} /* end_of_edit() */

/** @ignore yes */
mixed query_patterns() {
   return ({ "command <string'name'>", (: bug_command($4[0]) :),
             "soul <string'name'>", (: bug_soul($4[0]) :),
             "spell <string'name'>", (: bug_spell($4[0]) :),
             "object <indirect:wiz-present'name of NPC or item'>",
             (: bug_object($1, $4[0]) :),
             "ritual <string'name'>", (: bug_ritual($4[0]) :),
             "help <string'subject'>", (: bug_help($4[0]) :),
             "room", (: bug_room() :),
             "general", (: bug_general() :),
             });
} /* query_patterns() */
