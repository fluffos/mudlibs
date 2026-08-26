/*
 * DS history.
 * 30/07/01, Shiannar: Added mail inform.
 * 05/08/01, Sandoz : Added refresh inform.
 * 31/01/02, Sandoz : Added someone/something expansion for darkness.
 */
/**
 * This file contains all the standard event handling code that players
 * need.  This will handle things like informs, shouts, says, tells,
 * whispers.  Everything!   It formats the message correctly and
 * sends it to the player.
 * @author Pinkfish
 */

#include <dirs.h>
#include <player.h>
#include <telnet.h>
#include <language.h>

#define SPACES "                                                              "

#ifdef OLD_THINGY
inherit "/global/player/play_parse_com";
#else
inherit "/global/player/new_parse";
#endif
inherit "/global/player/communicate";

private int earmuffs, cols, rows;
private mapping my_colours;

/*
 * This so that changeing the definitions gets fixed
 * when they log in again.  Also keeps the save
 * file smaller.
 */
private nosave mapping colour_map;
private string term_name = "network";
private string *inform_types;
private mixed tell_history;
private mixed say_history;
private nosave string _cur_term, _last_term;
private nosave object _where, *_had_shorts;
private nosave mixed _eemessages;
private nosave mixed _busy;
private nosave mapping _inform_colours = ([ "default"      : "WHITE",
                                            "logon"        : "GREEN",
                                            "death"        : "RED",
                                            "cheat"        : "RED",
                                            "multiplayer"  : "RED",
                                            "bad-password" : "RED",
                                            "link-death"   : "GREEN",
                                            "friend"       : "MAGENTA",
                                            ]);

void set_my_colours(string event_type, string colour);
mapping query_my_colours();

string find_rel(string word, int from);
private int set_our_rows(int num);
private int set_our_cols(int num);
private int do_busy(string str);
private int do_busy_player(object *players);
protected varargs int do_tell_his(string, int);
protected varargs int do_say_his(string, int);

void create() {
    languages = ({ "common" });
    cur_lang = "common";
    _eemessages = ({ });
    my_colours = ([ ]);
    inform_types = ({ });
#ifdef OLD_THINGY
    play_parse_com::create();
#else
    new_parse::create();
#endif
} /* create() */

/**
 * This method returns the current terminal name.  If this is set to
 * network then the network will be queried for the terminal type
 * (using telnet suboption negotiation).
 * @return the current terminal name
 * @see query_cur_term()
 * @see set_term_type()
 */
string query_term_name() { return term_name; }
/**
 * This method returns the current terminal type that is being used.  This
 * will be 0 if the terminal name is set to network and no response has
 * been gained from the remote site yet.  Otherwise it should be the
 * same value as the terminal name.
 * @return the current terminal type
 * @see query_term_name()
 * @see set_term_type()
 */
string query_cur_term() { return _cur_term; }
/**
 * This method tells us if the player currently has earmuffs turned on.
 * @return 1 if earmuffs are on, 0 if they are not
 * @see check_earmuffs()
 * @see toggle_earmuffs()
 */
int query_earmuffs() { return earmuffs; }

/**
 * This method returns the list of inform types this player can receive.
 * @return array of inform types
 */
string *query_inform_types() {
    string *types;

    types = ({"logon", "birthday", "mail", "friend"});

    if( creatorp(TO) ) {
        types += ({"link-death", "message", "death", "error", "guild",
                   "delete", "help", "combat", "skill", "quest",
                   "multiplayer", "bad-password", "club", "debug",
                   "changelog", "typolog", "refresh"});

        if( lordp(TO) )
            types += ({"lord", "enter", "dest", "xp", "rolls", "trans"});

        if( adminp(TO) )
            types += ({"force", "cheat", "cpu", "ftp", "admin", "calls"});

        if( adminp(TO) || DOMAIN_H->query_creator("library", TO->query_name() ) )
            types += ({"autodoc"});
    }

    return types;

} /* query_inform_types() */

/* This is pulled back into this object for security reasons... */
/**
 * This is the command to handle the inform stuff.
 * It does all the turning on/off and stuff things for the informs.
 * @param str the informs to listen to
 * @see event_inform()
 */
protected int do_inform(string str) {
    string type, *types, *on, *frog, *off, *failed;
    int i;

    types = query_inform_types();

    foreach( type in inform_types )
        if( member_array( type, types ) == -1 )
            inform_types -= ({ type });

    on = sort_array( inform_types || ({ }), 1 );

    if( !str )
        str = "";

    frog = explode( str, " ");

    if( !frog )
        frog = ({ });
    else
        frog -= ({"", 0 });

    if( !sizeof(frog) ) {
        if( TO->query_property("inform repressed") )
            write("Your informs are currently being repressed.\n");
        if( sizeof(on) )
            write("$I$5=You are being informed of "+
                query_multiple_short(on)+" events.\n");
        if( sizeof( types = sort_array( types -= on, 1 ) ) )
            write("$I$5=You are not being informed of "+
                query_multiple_short(types)+" events.\n");
        return 1;
    }

    if( sizeof(frog) == 1 ) {
        switch( frog[0] ) {
        case "on" :
          TO->remove_property("inform repressed");
          write("You are now being informed.  This is true!\n");
          write("$I$5=You will be informed of "+
              query_multiple_short(on)+" events.\n");
          return 1;
        case "off":
          TO->add_property("inform repressed", 1 );
          write("Informs are now repressed.\n");
          return 1;
        case "all":
          on = types;
          frog = frog[1..];
        break;
        case "none" :
          on = ({ });
          write("You will not be informed of anything.\n");
          frog = frog[1..];
          break;
        }
    }

    failed = off = ({ });

    for( i = 0; i < sizeof(frog); i++ ) {
        if( member_array( frog[i], types ) == -1 ) {
            failed += ({ frog[i] });
        } else {
            if( sizeof(frog) > i+1 ) {
                switch( frog[i+1] ) {
                  case "on" :
                    if( member_array( frog[i], on ) == -1 )
                        on += ({ frog[i] });
                    i++;
                  break;
                  case "off" :
                    off += ({ frog[i] });
                    i++;
                  break;
                  default :
                    if( member_array( frog[i], on ) == -1 )
                        on += ({ frog[i] });
                    else
                        off += ({ frog[i] });
                  break;
                }
            } else {
                if( member_array( frog[i], on ) == -1 )
                    on += ({ frog[i] });
                else
                    off += ({ frog[i] });
            }
        }
    }

    on -= off;

    if( sizeof(failed) )
        write("$I$5=There are no "+query_multiple_short(failed)+" events.\n");
    if( sizeof(off) )
        write("$I$5=You will now not be informed of "+
            query_multiple_short(off)+" events.\n");
    if( sizeof(on) )
        write("$I$5=You will now be informed of "+
            query_multiple_short(on)+" events.\n");

    inform_types = on;
    return 1;

} /* do_inform() */

/**
 * This method tests to see if the player can see octarine objects.
 * @return 1 if they can see octarine, 0 if they cannot
 */
int query_see_octarine() {
    if( creatorp(TO) )
        return 1;
    return 0;
} /* query_see_octarine() */

/**
 * This method will do the octarine checking for you on the message.
 * @param str the string to check
 * @see query_see_octarine()
 * @example
 * string query_long_bit() {
 *   return "Glinting and sharp looking, the long sword is an impressive "
 *          "weapon in the hands of someone knowledgeable.\n" +
 *          this_player()->octarine_message("It glows with a fluffy octarine "
 *                                          "aura.\n");
 * } /\* query_long_bit() *\/
 */
string octarine_message( string str ) {
    return ( query_see_octarine() ? str : "" );
} /* octarine_message() */

/**
 * This function returns the appropriate colour codes for the given event
 * type. It will return the players chosen colour if they've set one or
 * the default if not.
 *
 * @param event_type The type of event
 * @return a string of colour codes.
 */
string colour_event( string event_type, string default_colour ) {
    if( my_colours[event_type] )
        return replace( my_colours[event_type], " ", "" );
    return default_colour || "";
} /* colour_event() */

/**
 * This method handles the conversersions for the colour mapping which is
 * done on Discworld.  This also does octarine message expansion, if the
 * keyword %\^OCTARINE:message%\^ is embeded into a string then the
 * inside section will be replaced with a blank string if the player
 * cannot see octarine messages.
 * @param str the string to do the conversion on
 * @param width the width of the string
 * @param indent the size of the indent
 * @param args any other arguments
 * @return the fixed up string
 * @see efun::terminal_colour()
 */
varargs string fix_string( string str, int width, int indent, mixed args ... ) {
    string octmess, *bits, bit;
    int i;

    if( !stringp(str) || str == "" )
        return str;

    if( indent > width / 3 )
        indent = 4;

    if( !_cur_term )
        _cur_term = ( term_name != "network" ? term_name : "dumb" );

    if( !colour_map )
        colour_map = (mapping)TERM_H->set_term_type(_cur_term);

    if( sizeof(args) )
        str = sprintf( str, args ... );

    bits = explode( str, "%^OCTARINE:");
    foreach( bit in bits ) {
        i = strsrch( bit, "%^");
        if( i == -1 )
            continue;
        octmess = bit[0..i-1];
        if( query_see_octarine() ) {
            str = replace_string( str, sprintf("%%^OCTARINE:%s%%^", octmess ),
                octmess );
        } else {
            str = replace_string( str, sprintf("%%^OCTARINE:%s%%^",
                octmess ), "");
        }
    }

    str = terminal_colour( str, colour_map, width, indent );
    return str;

} /* fix_string() */

/* Send all the relevant junk down to get the information we want. */
/** @ignore yes */
void player_connected() {
    _last_term = 0;
    /* Turn on the option */
    printf("%c%c%c", IAC, DO, TELOPT_TTYPE );
    /* Get them to send us their first terminal type */
    printf("%c%c%c%c%c%c", IAC, SB, TELOPT_TTYPE, TELQUAL_SEND, IAC, SE );
    /* Get them to send us their window size */
    printf("%c%c%c", IAC, DO, TELOPT_NAWS );
} /* player_connected() */

/**
 * This method sets the current terminal type for the player.  If the type
 * is network, then the network will be queried for the terminal type
 * and that will be used.  This is the distiction between the current
 * terminal type and the terminal name.  The name will be the value that
 * is set by the player and the current type will be the information
 * garnered from the network (if the name is network) or the same as the
 * name.
 * @param str the new terminal type
 * @return 1 if the terminal was successful set, 0 if not
 * @see set_term()
 * @see query_term_name()
 * @see query_cur_term()
 */
int set_term_type( string str ) {
    if( !str )
        return notify_fail( sprintf("%-=*s", cols,
            "Syntax: "+query_verb()+" <term_type>\n"+
            "Where term type is one of the following: "+
            implode((string *)TERM_H->query_term_types(), ", ")+
            ".\nOr set it to \"network\", and the mud will try to "
            "figure it out itself.\n") );

    if( str != term_name ) {
        if( member_array( str, (string *)TERM_H->query_term_types() ) != -1 ||
            str == "network") {
            if( str != "network")
                colour_map = (mapping)TERM_H->set_term_type(str);
            else
                player_connected();
            term_name = str;
            _cur_term = 0;
            write("Ok, terminal type set to "+str+".\n");
            return 1;
        } else {
            return notify_fail("No such terminal type as "+str+".\n");
        }
    }

    return notify_fail("Terminal type unchanged as "+str+".\n");

} /* set_term_type() */

/** @ignore yes */
void set_term(string name) {
    term_name = name;
    _cur_term = 0;
} /* set_term() */

/**
 * This method handles the responses from the remote site informing
 * us of their terminal type.
 * @param name the terminal type gathered from the remote site
 * @return 0 if the type was not used, 1 if it was
 * @see set_term_type()
 * @see query_term_name()
 * @see query_cur_term()
 */
int set_network_terminal_type(string name) {
    if( term_name != "network")
        return 0;

    if( !name ) {
        _cur_term = "dumb";
        colour_map = 0;
    }

    if( colour_map = (mapping)TERM_H->set_network_term_type(name) ) {
        _cur_term = name;
        return 1;
    }

} /* set_network_terminal_type() */

/**
 * This method adds all the event commands onto the player.
 * This will be called in the player startup sequence.
 */
void event_commands() {
    add_command("rows", TO, "", (: set_our_rows(0) :) );
    add_command("cols", TO, "", (: set_our_cols(0) :) );
    add_command("rows", TO, "<number>", (: set_our_rows($4[0]) :) );
    add_command("cols", TO, "<number>", (: set_our_cols($4[0]) :) );
    add_command("term", TO, "{"+
      implode((string *)TERM_H->query_term_types() +
        ({"network"}), "|")+"}", (: set_term_type($4[0]) :) );
    add_command("term", TO, "", (: set_term_type(0) :) );
    add_command("inform", TO, "", (: do_inform(0) :) );
    add_command("inform", TO, "<string>", (: do_inform($4[0]) :) );

    if( creatorp(TO) ) {
        add_command("busy", TO, "{on|off}", (: do_busy($4[0]) :) );
        add_command("busy", TO, "<indirect:player>",
            (: do_busy_player($1) :) );
    }

} /* event_commands() */

/**
 * Return function pointer for do_tell_his, for history tell only.
 */
function get_htell_func() {
    if( file_name(PO) != "/cmds/player/hi_story" &&
        file_name(PO) != "/cmds/lord/hi_story")
        return 0;
    return (: do_tell_his :);
} /* get_htell_func() */

/**
 * This method is the command used to print a players tell history.
 */
protected varargs int do_tell_his(string str, int brief) {
    string ret;
    mixed bit, *filter_history;

    if( str != "")
        filter_history = filter( tell_history,
          (: strsrch( lower_case($1[0]), $(str) ) > -1 :) );
    else filter_history = tell_history;

    if( !pointerp(filter_history) || !sizeof(filter_history) )
        return notify_fail("You have not been told anything.\n");

    if( undefinedp(brief) )
        brief = 0;

    ret = "$P$Tell History$P$Your tell history is:\n";

    foreach( bit in filter_history ) {
        if( !brief )
            ret += "** "+ctime(bit[2])+" **\n";
        ret += fix_string("%s%s\n", cols, strlen(bit[0]), bit[0], bit[1] );
    }

    write(ret);
    return 1;

} /* do_tell_his() */

/**
 * Return function pointer for do_say_his, for history say only.
 */
function get_hsay_func() {
    if( file_name(PO) != "/cmds/player/hi_story" &&
        file_name(PO) != "/cmds/admin/hi_story")
        return 0;
    return (: do_say_his :);
} /* get_hsay_func() */

/**
 * This method is the command used to print a players say history.
 */
protected varargs int do_say_his(string str, int brief) {
    string ret;
    mixed bit, *filter_history;

    if( str != "")
        filter_history = filter( say_history,
          (: strsrch( lower_case($1[0]), $(str) ) > -1 :) );
    else
        filter_history = say_history;

    if( !pointerp(filter_history) || !sizeof(filter_history) )
        return notify_fail("Nobody has said anything.\n");

    if( undefinedp(brief) )
        brief = 0;

    ret = "$P$Say History$P$Your say history is:\n";

    foreach( bit in filter_history ) {
        if( !brief )
            ret += "** "+ctime(bit[2])+" **\n";
        ret += fix_string("%s%s\n", cols, strlen(bit[0]), bit[0], bit[1] );
    }

    write(ret);
    return 1;

} /* do_say_his() */

/**
 * This method handles setting the busy flag.  The busy flag can only
 * be set by liaisons and lords, why lords?  Just because :)  This
 * command was inspired by moonchild.
 * @param str the on or off string
 * @return 1 on success, 0 on failure
 */
int do_busy( string str ) {
    _busy = ( str == "on");
    write("Busy set to "+str+".\n");
    return 1;
} /* do_busy() */

/**
 * This method allows creators to set the player for whom they are currently
 * busy too.
 * @param obs the player to be busy with
 * @return 1 on success, 0 on failure
 */
int do_busy_player( object *obs ) {
    write("Ok, setting you as busy with "+query_multiple_short(obs)+".\n");
    _busy = obs;
    return 1;
} /* do_busy_player() */

/**
 * This method tells us if the player/creator/lord is currently in busy
 * mode.  This will be 1 if the creatopr is generaly busy, or
 * it will return the array of players they are busy with.
 * @return the busy mode flag
 */
mixed query_busy() {
    if( pointerp(_busy) )
        _busy -= ({ 0 });

    if( pointerp(_busy) && !sizeof(_busy) )
        _busy = 0;

    return _busy;

} /* query_busy() */

/**
 * This method will change the current value of the earmuffs on the player.
 * @see check_earmuffs()
 * @see query_earmuffs()
 */
void toggle_earmuffs() {
    earmuffs = !earmuffs;
} /* toggle_earmuffs() */

/**
 * This method checks to see if a particular event is earmuffed.
 * @param type the type of event to check
 * @return 1 if the event is earmuffed and 0 if it is not
 * @see toggle_earmuffs()
 * @see query_earmuffs()
 * @example
 *   obs = users();
 *   obs = filter( obs, (: $1->check_earmuffs("shout") :) );
 *   // Do the shout
 */
int check_earmuffs( string type ) {
    string *on;

    if( !earmuffs )
        return 0;

    on = (string *)TO->query_property("earmuffs");
    if( !on )
        return 0;

    return member_array( type, on ) != -1;

} /* check_earmuffs() */

/**
 * This method sets the number of rows on the players screen.
 * @param i the new number of rows
 * @see query_rows()
 */
void set_rows( int i ) {
    if( i < 5 )
        return;
    rows = i;
} /* set_rows() */

/**
 * This method returns the current number of rows the player has
 * set on their screen.
 * @return the number of rows on the screen
 * @see set_rows()
 */
int query_rows() { return rows; }

private int set_our_rows(int val) {
    if( !val )
        return notify_fail("Rows currently set to "+rows+
            ".\nrows <number> to set.\n");

    if( val <= 10 )
        return notify_fail("Invalid number of rows.\n");

    write("Rows set to "+val+".\n");
    rows = val;
    return 1;

} /* set_our_rows() */

/**
 * This method returns the current number of columns the player has
 * set on their screen.
 * @return the number of columns on the screen
 * @see set_cols()
 */
int query_cols() { return cols; }

/**
 * This method sets the current number of columns the player has set on
 * their screen.
 * @param i the new number of columns
 * @see query_cols()
 */
void set_cols( int i ) {
    if( i <= 10 || i > 999 )
        return;
    cols = i;
} /* set_cols() */

private int set_our_cols(int val) {
    if( !val )
        return notify_fail("Columns currently set to "+cols+
            ".\ncols <number> to set.\n");

    if( val <= 35 || val > 999 )
        return notify_fail("Invalid column size.\n");

    write("Columns set to "+val+".\n");
    cols = val;
    return 1;

} /* set_our_cols() */

/**
 * This method sets the colour codes for a given event.
 * @param event_type the type of event to set the colour for
 * @param colour the colour to set
 */
void set_my_colours( string event_type, string colour ) {
    if( colour == "default") {
        map_delete( my_colours, event_type );
        return;
    }

    if( colour == "none") {
        my_colours[event_type] = "";
        return;
    }

    my_colours[event_type] = colour;

} /* set_my_colours() */

/**
 * Return a players list of custom colours.
 * @return a mapping of the players custom colours for different events.
 */
mapping query_my_colours() { return my_colours; }

void set_looked( object thing ) { _where = thing; }

/**
 * This method does all those terrible things with messages and $'s
 * turning them into real strings.  It is a neat function if somewhat
 * complicated :)  It was written by Deutha.
 * <p>
 * The return array has two elements, the first being the reformed
 * message and the second being the reformed things array.
 * @param message the message to reform
 * @param things some bonus things to reform it with
 * @return an array consisting of two elements
 */
mixed reform_message( string message, mixed things ) {
    int last, number;
    string before, middle, after, info;

    last = -1;

    if( !things )
        things = ({ });

    if( !_where )
        _where = environment();

    after = message;

    while( sscanf( message, "%s$R$%s$R$%s", before, middle, after ) == 3 ) {
        if( sscanf( middle, "[%s]%s", info, middle ) != 2 )
            info = "";
        switch ( middle[ 0 ] ) {
          case '-' :
            number = 0;
            middle = middle[ 1 .. ];
          break;
          case '+' :
            number = 1;
            middle = middle[ 1 .. ];
          break;
          default :
            number = 2;
        }
        if( number == 2 || _where->query_relative( middle ) ) {
            if( creatorp(TO) ) {
                message = before + find_rel( middle, number ) +" ("+ middle +
                ")"+ after;
            } else {
                message = before + find_rel( middle, number ) + after;
            }
        } else {
            message = before + info + middle + after;
        }
    }

    after = message;

    while( sscanf( message, "%s$r$%s$r$%s", before, middle, after ) == 3 ) {
        if( sscanf( middle, "[%s]%s", info, middle ) != 2 )
            info = "";
        switch ( middle[ 0 ] ) {
          case '-' :
            number = 0;
            middle = middle[ 1 .. ];
          break;
          case '+' :
            number = 1;
            middle = middle[ 1 .. ];
          break;
          default :
            number = 2;
        }
        if( number == 2 || _where->query_relative( LENGTHEN[ middle ] ) ) {
            if( creatorp(TO) ) {
                message = before + SHORTEN[ find_rel( LENGTHEN[ middle ],
                    number ) ] +" ("+ middle + ")"+ after;
            } else {
                message = before + SHORTEN[ find_rel( LENGTHEN[ middle ],
                    number ) ] + after;
            }
        } else {
            message = before + info + middle + after;
        }
    }

    after = message;
    while( sscanf( after, "%s$%d$%s", before, number, after ) == 3 )
        last = number;

    while( sscanf( message, "%s$M$%s$M$%s", before, middle, after ) == 3 ) {
        last++;
        message = before +"$"+ last +"$"+ after;
        things += ({ ({ }) });
        if( strsrch(middle, "$") == -1 ) {
            things[ last ] += ({ middle });
            middle = 0;
        } else {
            while ( sscanf( middle, "$%s$%s", info, middle ) == 2 )
                things[ last ] += ({ "my_"+ info });
        }
    }

    after = message;
    message = "";

    while( sscanf( after, "%s$%s$%s", before, middle, after ) == 3 ) {
        if( sscanf( middle, "%s_short:%s", middle, info ) != 2 ) {
            message += before +"$"+ middle;
            after = "$"+ after;
            continue;
        }
        last++;
        message += before +"$"+ last +"$";
        things += ({ ({ "my_"+ middle +"_short:"+ info }) });
    }

    message += after;

    return ({ message, things });

} /* reform_message() */

/**
 * This adds a message into the current list of printable messages.  This
 * will be squided up together and printed out slightly later, this handles
 * the concatenating of enter messages, and soul messages.  Etc.
 * @param message the message to add
 * @param things the objects which are involved with the message
 * @see reform_message()
 */
void add_message( string message, mixed things ) {
    int last;
    mixed stuff;

    if( !interactive( TO ) )
        return;

    if( strsrch( message, "$" ) == -1 )
        stuff = ({ message, things });
    else
        stuff = reform_message( message, things );

    _where = 0;

    if( !sizeof( _eemessages ) ) {
        call_out( "print_messages", 2 );
        _eemessages = stuff;
    } else {
        last = sizeof( _eemessages ) - 2;
        if( stuff[ 0 ] == _eemessages[ last ] && sizeof( stuff[ 1 ] ) == 1 ) {
            if( sizeof( filter( stuff[ 1 ][ 0 ],
                (: member_array($1, $2) != -1 :),
                _eemessages[ last + 1 ][ 0 ] ) ) ) {
                _eemessages += stuff;
            } else {
                _eemessages[ last + 1 ][ 0 ] += stuff[ 1 ][ 0 ];
            }
        } else {
            _eemessages += stuff;
        }
    }

} /* add_message() */

/**
 * This method checks whether or not the room the
 * player is in is dark enough to use 'someone'
 * instead of regular shorts.
 */
int query_is_dark( object thing ) {
    if( !ENV(TO) || thing == ENV(TO) || ( ENV(thing) && ENV(thing) == TO ) ||
        TO->query_property("doing_soul") ||
        ( creatorp(TO) && !TO->query_property("always_dark") ) )
        return 0;

    return TO->check_dark( ENV(TO)->query_light() ) != 0;

} /* query_is_dark() */

/**
 * @ignore yes
 * This method is used for the reform_mesage stuff
 */
string get_pretty_short( object thing ) {
    if( !thing->query_visible( TO ) || TO->query_is_dark(thing) )
        return ( living( thing ) ? "someone" : "something" );
    return (string)thing->pretty_short( TO ) +
           (string)thing->hide_invis_string();
} /* get_pretty_short() */

/**
 * @ignore yes
 * This method is used for the reform_message stuff
 */
string get_pretty_plural( object thing ) {
    if( !thing->query_visible( TO ) || TO->query_is_dark(thing) )
        return ( living( thing ) ? "people" : "things" );
    return (string)thing->pretty_plural( TO ) +
           (string)thing->hide_invis_string();
} /* get_pretty_plural() */

/**
 * This is a special function for use with the reform message, it allows
 * the string to be echoed into the list instead of using the object's
 * value itself.  This is done specifically to handle objects with
 * variable shorts, so we get the short description correct at the
 * moment it is queried.
 */
string my_mirror_short( object thing, string arg ) {
    return arg;
} /* my_mirror_short() */

/**
 * @ignore yes
 * This method is used for the reform_mesage stuff
 */
string my_a_short( object thing ) {
    string article;

    if( !objectp( thing ) )
        return "an unknown object";

    // forget the article if it's dark.
    if( TO->query_is_dark( thing ) )
        return (string)TO->get_pretty_short( thing );

    if( !article = (string)thing->query_determinate( TO ) )
        return add_a( (string)TO->get_pretty_short( thing ) );

    return article + (string)TO->get_pretty_short( thing );

} /* my_a_short() */

/**
 * @ignore yes
 * This method is used for the reform_mesage stuff
 */
string my_the_short( object thing ) {
    string article;

    if( !objectp( thing ) )
        return "the unknown object";

    // forget the article if it's dark.
    if( TO->query_is_dark( thing ) )
        return (string)TO->get_pretty_short( thing );

    if( !( article = (string)thing->query_determinate( TO ) ) ||
        article == "a " || article == "an " )
        return "the "+ (string)TO->get_pretty_short( thing );

    return article + (string)TO->get_pretty_short( thing );

} /* my_the_short() */

/** @ignore yes */
int some_more( string word ) {
    return sizeof( filter( INV( _where ),
        (: $1->query_plural() == $(word) :) ) ) > 1;
} /* some_more() */

/**
 * @ignore yes
 * This method is used for the reform_mesage stuff
 */
string my_one_short( object thing ) {
    string article, its_plural;

    if( !objectp( thing ) )
        return "one of the unknown objects";

    _where = ( ENV(thing) && ENV( thing ) != ENV(TO) ? ENV(thing) :
               environment() );

    // forget the article if it's dark.
    if( TO->query_is_dark( thing ) )
        return (string)TO->get_pretty_short( thing );

    if( !( article = (string)thing->query_determinate( TO ) ) ||
        article == "a " || article == "an " ) {
        its_plural = (string)TO->get_pretty_plural( thing );
        if( some_more( its_plural ) )
            return "one of the "+ its_plural;
        return "the "+ (string)TO->get_pretty_short( thing );
    }

    return article + (string)TO->get_pretty_short( thing );

} /* my_one_short() */

/**
 * @ignore yes
 * This method is used for the reform_mesage stuff
 */
string my_poss_short( object thing ) {
    string article, its_plural, of_whom;

    if( !objectp( thing ) )
        return "an unknown object";

    if( living(thing) ) {
        if( thing == TO )
            return "your";
        _where = ( ENV( thing ) != ENV(TO) ? TO : environment() );
        return TO->my_one_short( thing ) + ( some_more(
            (string)TO->get_pretty_plural( thing ) ) ?
            ( TO->query_is_dark( thing ) ? "'s" : "'") : "'s" );
    }

    if( !_where = environment( thing ) )
        return my_a_short( thing );

    if( !living( _where ) && !_where->query_corpse() )
        return my_a_short( thing );

    if( _where == TO ) {
        of_whom = "your ";
    } else {
        // forget the owner if it's dark.
        if( TO->query_is_dark( thing ) )
            return (string)TO->get_pretty_short( thing );
        of_whom = ( member_array( _where, _had_shorts ) != -1 ?
                  (string)_where->query_possessive() :
                  my_the_short( _where ) +"'s" ) +" ";
    }

    if( !article || article == "a " || article == "an " ) {
        its_plural = (string)TO->get_pretty_plural( thing );
        if( thing->query_holder() ) {
            foreach( object ob in thing->query_holder()->query_holding() ) {
              if( ob && ob != thing &&
                  (string)TO->get_pretty_plural( ob ) == its_plural )
                  return "one of "+ of_whom + its_plural;
            }
            return of_whom + (string)TO->get_pretty_short( thing );
        }
        if( some_more( its_plural ) )
            return "one of "+ of_whom + its_plural;
    }

    return of_whom + (string)TO->get_pretty_short( thing );

} /* my_poss_short() */

/**
 * @ignore yes
 * This method is used for the reform_message stuff
 */
string calc_shorts( string *short_list ) {
    int i;
    string list, str, desc;
    object ob, *things;
    // These next two are tied.
    string *descs_str;
    mixed descs_ob;
    mixed parts;

    descs_str = ({ });
    descs_ob  = ({ });

    foreach( str in short_list ) {
        parts = explode( str, ":" );
        if( sizeof(parts) > 1 ) {
            ob = find_object( parts[ 1 ] );
        } else {
            ob = 0;
            parts += ({""});
        }

        if( ob )
            _had_shorts = ({ ob }) + _had_shorts;

        if( ob == TO )
            desc = ( parts[0] == "my_poss_short" ? "your" : "you" );
        else if( sizeof(parts) >= 2 )
            desc = (string)call_other( TO, parts[0], ob, parts[1] );
        else
            desc = ( sizeof(parts[0]) ? parts[0] : "something" );

        if( ( i = member_array( desc, descs_str ) ) == -1 ) {
            descs_str += ({ desc });
            descs_ob += ({ ({ ob }) });
        } else {
            descs_ob[i] += ({ ob });
        }
    }

    if( ( i = member_array( "you", descs_str ) ) != -1 &&
        i != sizeof(descs_str) - 1 ) {
        descs_str = descs_str[0..i-1] + descs_str[i+1..] + ({ "you" });
        descs_ob = descs_ob[0..i-1] +  descs_ob[i+1..] + descs_ob[i..i];
    }

    list = "";

    for( i = 0; i < sizeof( descs_str ); i++ ) {
        things = descs_ob[ i ];
        if( sizeof( things ) == 1 ) {
            list += descs_str[ i ];
        } else {
            things -= ({ 0 });
            if( sizeof(things) ) {
                list += query_num( sizeof( things ), 20 )+" "+
                    (string)TO->get_pretty_plural( things[ 0 ] );
            } else {
                list += query_num( sizeof( things ), 20 ) +" unknown objects";
            }
        }
        if( i == sizeof( descs_str ) - 1 )
            continue;
        list += ( i == sizeof( descs_str ) - 2 ? " and " : ", " );
    }

    return list;

} /* calc_shorts() */

/**
 * This method fits a message into a the current players screen size.  This
 * does all sorts of other evil stuff too, like handling indenting and
 * all sorts of things!  Most of which I do not understand so I won't
 * say anything about here.
 * @param message the message to fit in
 * @return the fitted message
 */
string fit_message( string message ) {
    int left, right, space;
    string *parts, part;
    mixed stuff;

    if( strlen( message ) < 6 )
        return message;

    if( message[0..2] != "$I$" )
        message = "$I$0=$C$" + message;

    parts = explode( message, "$C$" );
    parts = map( parts, (: CAP($1) :) );
    parts = explode( implode( parts, "" ), "$I$");

    message = "";

    foreach( part in parts ) {
        if( sscanf( part, "%s=%s", stuff, part ) != 2 ) {
            message += fix_string( "$I$"+part, cols );
            continue;
        }

        if( stuff == "") {
            message += fix_string( "$I$="+part, cols );
            continue;
        }

        if( stuff[0] == ' ' )
            space = !space;

        stuff = explode( stuff, "," );

        if( sizeof(stuff) && stuff[0] != "" ) {
            switch( stuff[0][0] ) {
            case '+' :
              if( space && left > 0 && part != "")
                  part = SPACES[0..left-1] + part;
              left += to_int( stuff[0][1..] );
            break;
            case '-' :
              left -= to_int( stuff[0][1..] );
              if( left < 0 )
                  left = 0;
              if( space && left > 0 && part != "")
                  part = SPACES[0..left-1] + part;
            break;
            default :
              left = to_int( stuff[0] );
            }
        } else {
            left = 0;
        }

        if( sizeof( stuff ) > 1 ) {
            switch( stuff[1][0] ) {
            case '+' :
              right += to_int( stuff[1][1..] );
            break;
            case '-' :
              right -= to_int( stuff[1][1..] );
              if( right < 0 )
                  right = 0;
            break;
            default :
              right = to_int( stuff[1] );
            }
        } else {
            right = 0;
        }

        message += ( left > 0 ?
            fix_string( part, cols - right, left ) :
            fix_string( part, cols - right ) );
    }

    return message;

} /* fit_message() */

/**
 * This method shows the message to the player.
 * @param message the message to show
 * @see fit_message()
 */
void show_message( string message ) {
    string bit;

    if( sscanf( message, "$P$%s$P$%s", bit, message ) == 2 ) {
        TO->more_string( fit_message( message ), bit, 1 );
        return;
    }

    efun::tell_object( TO, fit_message( message ) );

} /* show_message() */

/** @ignore yes */
protected void clear_had_shorts() { _had_shorts = ({ }); }

/**
 * This is the main evaluation routine.  This is the one that
 * co-ordinates the works...  It is used by the print_messages
 * routine to create the message to print out.
 * <p>
 * The input parameter contains two elements, the first is the
 * message and the second is the things array.  This corresponds to
 * the values returned by the fix_message method.
 * @param stuff the message to evaulate
 * @return the nice printed out string
 * @see print_messages()
 */
string evaluate_message( mixed stuff ) {
    int i;
    string message, start, finish, verb_sing, verb_plur;

    message = stuff[0];
    clear_had_shorts();

    for( i = 0; i < sizeof( stuff[1] ); i++ ) {
        // Things assume this ordering, so do not change.
        message = replace_string( message, "$"+i+"$",
            calc_shorts( stuff[1][i] ) );
        while( sscanf( message, "%s$V$"+ i +"=%s,%s$V$%s", start, verb_sing,
            verb_plur, finish ) == 4 ) {
            if( sizeof( stuff[1][i] ) == 1 && sizeof(_had_shorts) &&
                objectp( _had_shorts[0] ) ) {
                if( _had_shorts[0]->query_property("group object") ||
                    _had_shorts[0]->group_object() ) {
                    message = start+verb_plur+finish;
                } else {
                    message = start+verb_sing+finish;
                }
            } else {
                message = start+verb_plur+finish;
            }
        }
    }

    return message;

} /* evaluate_message() */

/**
 * This prints out the messages after the delay, printing out the
 * messages in a nice cute way.  It still retains the order of the
 * messages though.  This can be forced to occur by a message
 * occuring on the player object which requires something to
 * be printed.
 * @see evaluate_message()
 * @see show_message()
 */
void print_messages() {
    int i;
    string message;
    mixed messages;

    remove_call_out( "print_messages" );
    messages = _eemessages;
    _eemessages = ({ });

    for( i = 0; i < sizeof( messages ); i += 2 ) {
        message = messages[ i ];
        if( sizeof( messages[ i + 1 ] ) )
            message = evaluate_message( ({ message, messages[ i + 1 ] }) );
        show_message( message );
    }

    _where = 0;

} /* print_messages() */

/**
 * This method will handle doing exciting things to messages and
 * returning them as a usable format.
 * @param message the message to evaluate
 * @return the message in a printable (to the player) format
 * @see evaluate_message()
 */
string convert_message( string message ) {
    message = evaluate_message( reform_message( message, ({ }) ) );
    _where = 0;
    return message;
} /* convert_message() */

/**
 * This method is called when an inform event is called.
 * @param mess the message to print
 * @param which the type of inform
 * @parm thing the thing associated with the inform
 */
varargs void event_inform( object, mixed mess, string which, object thing ) {
    string *on, inform_col;
    int is_friend;

    on = inform_types || ({ });

    if( TO->query_property("inform repressed") || !sizeof( on ) )
        return;

    if( thing && creatorp(thing) && !thing->query_visible( TO ) )
        return;

    if( member_array( which, on ) == -1 )
        return;

    if( thing && member_array("friend", on ) != -1 &&
        TO->query_friend( thing->query_name() ) )
        is_friend = 1;

    if( which == "friend" && !is_friend )
        return;

    if( which == "logon" && is_friend )
        which = "friend";

    if( _inform_colours[which] )
        inform_col = colour_event( which, _inform_colours[which] );
    else
        inform_col = colour_event( which, _inform_colours["default"] );

    if( functionp(mess) )
        mess = evaluate( mess, TO );

    TO->add_message( "[%^"+ inform_col +"%^"+mess+"%^RESET%^]\n", ({ }) );

} /* event_inform() */

/**
 * This method is called when an object leaves or arrives in
 * the room.  It prints out
 * the message, well adds it to the queue of printable messages.
 * @param mess the message to print
 * @param thing the thing which is leaving/arriving
 * @param going if it is going
 */
protected void enter_exit_mess( string mess, object thing, int going ) {
    int i;
    string part, verb, *words;

    mess = replace_string( mess, "$N", "$0$" );
    words = explode( mess, " " );
    for ( i = sizeof( words ) - 1; i > -1; i-- ) {
        /*
         * If $s ends a word, it represents verb conjugation.
         * The test of the following letter is to check that it does end the word.
         */
        if ( ( sscanf( words[ i ], "%s$s%s", verb, part ) == 2 ) &&
          ( ( part[ 0 ] < 97 ) || ( part[ 0 ] > 122 ) ) ) {
            words[ i ] = "$V$0="+ pluralize( verb ) +","+ verb +"$V$"+ part;
        }
        /*
         * If we have %<verb>%, it represents verb conjugation.
         * This is unlikely to get confused with anything else...
         */
        if ( sscanf( words[ i ], "%%%s%%%s", verb, part ) == 3 ) {
            words[ i ] = "$V$0="+ pluralize( verb ) +","+ verb +"$V$"+ part;
        }
    }
    if( going ) {
        TO->add_message( implode( words, " " ) +"\n",
          ({ ({ "my_the_short:"+ file_name( thing ) }) }) );
    } else {
        TO->add_message( implode( words, " " ) +"\n",
          ({ ({ "my_a_short:"+ file_name( thing ) }) }) );
    }
} /* enter_exit_mess() */

/**
 * This method is called when an object enters the room.
 * @param thing the thing entering
 * @param mess the message to print on entering
 */
void event_enter( object thing, string mess, object ) {
    if( !stringp( mess ) )
        return;

    thing->sneak_task(TO);
    TO->perception_task(thing);

    if( !thing->query_visible( TO ) )
        return;

    enter_exit_mess( mess, thing, 0 );

} /* event_enter() */

/**
 * This method is printed when an object exits the room.
 * @param thing the object exiting
 * @param mess the message to print
 * @param to where the object is going to
 */
void event_exit( object thing, string mess, object to ) {
    ::event_exit( thing, mess, to );
    if( !stringp( mess ) )
        return;
    if( !thing->query_visible( TO ) )
        return;
    enter_exit_mess( mess, thing, 1 );
} /* event_exit() */

/** @ignore yes */
void event_death( object thing, object *, object killer,
                  string room_mess, string killer_mess ) {
    if( TO == thing )
        return;

    if( TO == killer && stringp( killer_mess ) ) {
        TO->add_message( replace( killer_mess,
            "$D",(string)thing->the_short() ), ({ }) );
        print_messages();
        return;
    }

    if( stringp( room_mess ) ) {
        if( objectp( killer ) ) {
            TO->add_message( replace( room_mess, ({
                "$D", (string)thing->the_short(),
                "$K", (string)killer->the_short() }) ), ({ }) );
        } else {
            TO->add_message( replace( room_mess, "$D",
                (string)thing->the_short() ), ({ }) );
        }
        print_messages();
    }
} /* event_death() */

/**
 * This method is called when the 'say' and 'tell_room' simul_efuns is used.
 * @param caller the object doing the say
 * @param str the message to print
 * @param avoid the people to avoid in the say
 */
void event_say(object caller, string str, mixed avoid) {
    if( pointerp(avoid) ) {
        if( member_array( TO, avoid ) != -1 )
            return;
    } else if( avoid == TO )
        return;

    if( !silenced(caller) )
        TO->add_message( str, ({ }) );

} /* event_say() */

void event_see( object caller, string words, object thing, mixed avoid ) {
    if( !thing->query_visible( TO ) )
        return;
    event_say( caller, words, avoid );
} /* event_see() */

/**
 * This method is called by the simul_efun 'write'.
 * @param caller the calling object
 * @param str the string to write
 */
void event_write( object caller, string str ) {
    TO->add_message( str, ({ }) );
    print_messages();
} /* event_write() */

/** @ignore yes */
void do_efun_write( string str ) { event_write( 0, str ); }

/**
 * This method is called by the soul to print out the soul messages.
 * @param ob the object doing the soul
 * @param str the string to print
 * @param avoid the people not to print the message to
 */
varargs void event_soul( object ob, string str, mixed avoid ) {
    int id;

    TO->add_property("doing_soul", 1 );

    if( ob != TO ) {
        if( silenced(ob) || ( sizeof(avoid) > 1 &&
            check_earmuffs("multiple-soul") ) )
            return ;

        if( !ob->query_visible(TO) )
            tell_object( ob, "Warning! "+TO->query_cap_name()+" cannot see "
                "you and will not be able to respond.\n");

        if( TO->query_property("afk") )
            tell_object( ob, TO->query_cap_name()+" is currently %^ORANGE%^"
                "AFK%^RESET%^"+( !TO->query_property("afk_string") ? "!" : " "
                "because : "+TO->query_property("afk_string") )+"\n");

        if( interactive(TO) && ( id = query_idle(TO) ) > TELL_WARN_TIME )
            tell_object( ob, TO->query_cap_name()+" has been idle for "+
                time_string(id)+".\n");

        event_say( ob, colour_event("soul", "")+"$C$"+str+"%^RESET%^",
                   avoid );
    } else
        event_write( ob, str+"%^RESET%^");

    TO->remove_property("doing_soul");

} /* event_soul() */

/**
 * This method is called when someone does an emote.
 * @param thing the object doing the emote
 * @param mess the emote to print
 */
void event_emote( object thing, string mess ) {
    if( thing == TO || silenced(thing) )
        return;
    TO->add_message( colour_event("emote", "%^CYAN%^")+mess+"%^RESET%^",
        ({ }) );
} /* event_emote() */

/**
 * @ignore yes
 * Use this on pain of death :)
 */
void add_say_history(string start, string mess) {
    if( !pointerp(say_history) )
        say_history = ({ });
    say_history +=  ({ ({ CAP(start), mess, time() }) });
    if( sizeof(say_history) > MAX_TELL_HIS )
        say_history = say_history[1..];
} /* add_say_history() */

/**
 * This method is called when someone says something.
 * @param ob the object doing the say
 * @param start the start message
 * @param mess the message to say
 * @param lang the language it is printed in
 */
void event_person_say( object ob, string start, string mess, string lang ) {
    string *args;

    if( ob == TO || silenced(ob) )
        return;

    if( lang != "common" )
        start = start[0..<3] + " in " + CAP(lang) + ": ";

    args = LANGUAGE_H->garble_say( lang, start, mess, TO, ob, SAY_TYPE );
    start = args[ 0 ];
    mess = args[ 1 ];

    add_say_history( TO->convert_message(start), TO->convert_message(mess) );

    TO->add_message("$I$5="+colour_event("say", "%^CYAN%^")+"$C$"+start+
        mess+"%^RESET%^\n", ({ }) );

} /* event_person_say() */

/**
 * @ignore yes
 * Use this on pain of death :)
 */
void add_tell_history(string start, string mess) {
    if( !pointerp(tell_history) )
        tell_history = ({ });
    tell_history +=  ({ ({ start, mess, time() }) });
    if( sizeof(tell_history) > MAX_TELL_HIS )
        tell_history = tell_history[1..];
} /* add_tell_history() */

/**
 * This method is called when a person is told something.
 * @param ob the object doing the tell
 * @param start the start bit of the message
 * @param mess the message itself
 */
void event_person_tell( object ob, string start, string mess ) {
    string *args;
    int id;

    if( silenced(ob) )
        return;

    if( ( args = TO->query_property("ignoring") ) &&
        member_array( ob->query_name(), args ) != -1 && !creatorp(ob) ) {
        tell_object( ob, TO->query_cap_name()+" is ignoring you and "
            "will not have heard what you said.\n");
        return;
    }

    if( TO->query_property("afk") )
        tell_object( ob, TO->query_cap_name()+" is currently %^ORANGE%^"
            "AFK%^RESET%^"+( !TO->query_property("afk_string") ? "!" : " "
            "because : "+TO->query_property("afk_string") )+"\n");

    start = convert_message(start);

    if( _busy && ( !pointerp(_busy) || member_array( ob, _busy ) == -1 ) ) {
        tell_object( ob, TO->query_cap_name()+" is currently busy with "
            "someone else, "+TO->HE+" has heard this message and will get "
            "back to you shortly.\n");
        start = "[BUSY] "+start;
    }

    add_tell_history( start, mess );

    efun::tell_object( TO, fix_string( replace( colour_event("tell",
        "%^YELLOW%^"), "%^", "%%^")+"%s%s%%^RESET%%^\n", cols, 5, CAP(start),
        SPEECH_BASE->mangle_tell( mess, ob ) ) );

    if( interactive(TO) && ( id = query_idle(TO) ) > TELL_WARN_TIME )
        write( TO->query_cap_name()+" has been idle for "+
               time_string(id)+".\n");

    if( TO->query_property( PASSED_OUT ) )
        write("Something tells you that "+TO->query_cap_name()+" will be "
            "unable to reply to you just yet.\n" );

} /* event_person_tell() */

/**
 * This method is called when the whisper even is generated.
 * @param ob the object whispering
 * @param start the start of the whisper message
 * @param mess the message to print
 * @param obs the objects to tell the message to
 * @param lang the lanaguage the whisper is in
 * @param me the object doing the whispering
 */
void event_whisper( object ob, string start, string mess,
                    object *obs, string lang, object me ) {
    string blue, *args;

    blue = "";
    if( me == TO || silenced(ob) )
        return;

    if( lang != "common")
        blue = " in "+lang;

    args = LANGUAGE_H->garble_say( lang, start, mess, TO, ob, WHISPER_TYPE );
    start = args[0];
    mess = args[1];

    if( member_array( TO, obs ) == -1 ) {
        TO->add_message("$I$5="+colour_event("whisper", "%^CYAN%^")+"$C$"+
            start+"to "+query_multiple_short( obs )+".%^RESET%^\n", ({ }) );
        return;
    }

    if( sizeof( obs ) == 1 ) {
        TO->add_message("$I$5="+colour_event("whisper", "%^CYAN%^")+"$C$"+
            start+"to you"+blue+": "+mess+"%^RESET%^\n", ({ }) );
        return;
    }

    TO->add_message("$I$5="+colour_event("whisper", "%^CYAN%^")+"$C$"+
        start+"to "+query_multiple_short( obs )+blue+": "+mess+
        "%^RESET%^\n", ({ }) );

} /* event_whisper() */

/**
 * This method is generated when a shout is done by a player.
 * @param thing the thing doing the shout
 * @param start the start string to print
 * @param mess the message to print
 * @param lang the language the shout is in
 * @param co_ord the co-ordinate of the shouter
 * @param range the range of the shout
 */
void event_person_shout( object thing, string start, string mess, string lang,
                         int *co_ord, int range ) {
    mixed args;

    if( TO == TP || silenced(thing) || check_earmuffs("shout") || !ENV(TO) ||
        ENV(TO)->query_property("shout zone") !=
        ENV(TP)->query_property("shout zone") ||
        sizeof( query_ignoring( ({ TP }) ) ) )
        return;

    if( lang != "common" )
        start += " in "+lang;

    args = LANGUAGE_H->garble_say( lang, start, mess, TO, thing, SHOUT_TYPE );
    start = args[0];
    mess = args[1];

    if( ENV(TO) == ENV(TP) ) {
        TO->add_message("$I$5="+colour_event("shout", "")+"$C$"+
            start+": "+mess+"%^RESET%^\n", ({ }) );
        return;
    }

    if( sizeof( co_ord ) != 3 )
        return;

    BROADCASTER->broadcast_event( ({ TO }), co_ord, start+": "+mess,
        range, 1, 0 );

} /* event_person_shout() */

/**
* This event is generated when a newbie chat event is done.
* @param thing the thing generateing the newbie chat
* @param message the message the newbie said
*/
void event_newbie( object thing, string message ) {
    if( TP == TO || check_earmuffs("newbie") ||
        sizeof( query_ignoring( ({ TP }) ) ) )
        return;

    efun::tell_object( TO, fix_string("%%^MAGENTA%%^(newbie)%%^RESET%%^ %s\n",
                       cols, 5, message ) );

} /* event_newbie() */

/**
 * This event is generated when a creator tell is done.
 * @param ob the object generating the event
 * @param start the start bit
 * @param mess the message bit
 * @param forced if it is forced to occur
 */
void event_creator_tell( object ob, string start, string mess, int forced ) {
    if( TP == TO || ob == TO || ( ( sizeof(TO->query_ignoring( ({ ob }) ) ) ||
        check_earmuffs("cre")) && !forced ) || !creatorp(TO) )
        return;

    efun::tell_object( TO, fix_string(replace(
        colour_event("cre", "%^CYAN%^"), "%^", "%%^")+
        "(cre) %s%s%%^RESET%%^\n", cols, 5, start, mess ) );

} /* event_creator_tell() */

/**
 * This event is generated when a creator tell is done.
 * @param ob the object generating the event
 * @param start the start bit
 * @param mess the message bit
 * @param forced if it is forced to occur
 */

void event_chat( object ob, string caller, string verb, string text,
                 int emote, int force ) {
    string hdr;
    object person;

    person = find_player( lower_case(caller) );

    hdr = ( emote ? "("+verb+") "+caller+" " :
      "("+( force ? "forced-" : "")+verb+") "+caller+": ");

    if( !force ) {
        if( TO->check_earmuffs("chat-channels") ||
            TO->query_property("allchat_off") ||
            TO->query_property(verb +"_off") )
            return;
        if( person )
            if( sizeof( TO->query_ignoring( ({ person }) ) ) )
                return;
    }

    efun::tell_object( ob, fix_string( replace( colour_event(
        verb, "%^CYAN%^"), "%^", "%%^")+"%s%s%%^RESET%%^\n",
        cols, strlen(verb)+2, hdr, text ) );

} /* event_chat() */

/**
 * This event is generated when a intermud creator tell is done.
 * @param ob the object generating the event
 * @param mname the name of the mud
 * @param pname the name of the player
 * @param mess the message
 * @param ig the ignore object
 * @param emote if it is an emote
 */
void event_inter_creator_tell( object ob, string mname, string pname,
                               string mess, object ig, int emote ) {

    if( !creatorp(TO) || check_earmuffs("inter-creator-tell") || TO == ig )
        return;

    efun::tell_object( TO, fix_string("%s@%s%s%s\n", cols,
        strlen(mname) + strlen(pname) + 3, pname, mname, ( emote ? " ": ": "),
        mess ) );

} /* event_inter_creator_tell() */

/**
 * This event is generated when a creator tell is done.
 * @param ob the object generating the event
 * @param mname the name of the mud
 * @param pname the name of the player
 * @param mess the message
 * @param ig the ignore object
 * @param emote if it is an emote
 */
void event_intermud_tell( object ob, string start, string mess, string channel,
                          object ig, int emote ) {

    if( TO->check_earmuffs("chat-channels") ||
        TO->query_property("allchat_off") ||
        TO->query_property(channel +"_off") )
        return;

    if( emote )
        efun::tell_object( TO, fix_string( replace( colour_event(
            channel, "%^CYAN%^"), "%^", "%%^")+"(%s): %s%s%%^RESET%%^\n",
            cols, strlen(start)+strlen(channel)+3, channel, start, mess ) );
    else
        efun::tell_object( TO, fix_string( replace( colour_event(
            channel, "%^CYAN%^"), "%^", "%%^")+"%s (%s): %s%%^RESET%%^\n",
            cols, strlen(start)+strlen(channel)+3, start, channel, mess ) );

} /* event_intermud_tell() */

/**
 * This method is called when an echo to is generated by the player.
 * @param ob the object doing the echo to
 * @param mess the message being printed
 * @param me the person generating the echo to
 */
void event_player_echo_to(object ob, string mess, object me) {
    if( lordp( (string)TO->query_name() ) )
        TO->add_message("$0$ echos to you:\n",
            ({ ({ "my_the_short:"+file_name( me ) }) }) );

    TO->add_message( colour_event("echo", "")+mess+"%^RESET%^", ({ }) );

} /* event_player_echo_to() */

/**
 * This method is called when an emoteall is generated by a player.
 * @param ob the object doing the emoteall
 * @param mess the message being printed
 */
void event_player_emote_all( object ob, string mess ) {
    if( ob == TO )
        return;

    if( lordp( (string)TO->query_name() ) )
        TO->add_message("$0$ emotes to all:\n",
            ({ ({ "my_the_short:"+file_name( ob ) }) }) );

    TO->add_message("$I$5=$C$"+replace_string( mess, "$N", "$0$"),
        ({ ({ "my_the_short:"+ file_name( ob ) }) }) );

} /* event_player_emote_all() */

/**
 * This method is called when an echo is generated by a player.
 * @param ob the object doing the echo
 * @param mess the message being printed
 */
void event_player_echo( object ob, string mess ) {
    if( ob == TO )
        return;

    if( lordp( (string)TO->query_name() ) )
        TO->add_message("$0$ echos:\n",
            ({ ({ "my_the_short:"+file_name( ob ) }) }) );

    TO->add_message( mess, ({ }) );

} /* event_player_echo() */

/**
 * This method is generated internally by the driver when this player is
 * snooping someone else.
 * @param mess the snoop message
 */
void receive_snoop( string mess ) {
    tell_object( TO, "] "+mess );
} /* receive_snoop() */

/**
 * This is a call back generated by the driver internally to tell us about
 * terminal types.
 * @param type the terminal type returned
 */
void terminal_type( string type ) {
    if( set_network_terminal_type(type) ) {
        tell_object( TO, "Setting your network terminal type to "
            "\""+type+"\".\n");
    } else {
        if( term_name == "network") {
            if( !_last_term || _last_term != type ) {
                _last_term = type;
                // Keep going until they repeat twice.
                // This is the end of the list.
                printf("%c%c%c%c%c%c", IAC, SB, TELOPT_TTYPE,
                    TELQUAL_SEND, IAC, SE );
            } else
                tell_object( TO, "Unknown terminal type \""+type+"\".\n");
        }
    }
} /* terminal_type() */

/**
 * This is a call back generated by the driver internally to tell us about
 * the window size of the remote machine.  This information in this is
 * only used if the terminal is a network type.
 * @param width the number of columns
 * @param height the number of rows
 */
void window_size( int width, int height ) {
    if( term_name == "network" ) {
        if( width > 10 && width < 256 )
            set_cols(width);
        if( height > 5 && height < 256 )
            set_rows(height);
        tell_object( TO, "Your machine told our machine that your "
            "terminal has "+height+" rows and "+width+" columns.\n");
    }
} /* window_size() */
