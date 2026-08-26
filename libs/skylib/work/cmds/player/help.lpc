/**
 * Does all the help stuff you know and love.
 * @author Pinkfish
 * @started Tue Nov  4 14:55:39 EST 1997
 */

#include <nroff.h>

#define SYNONYMS "/doc/SYNONYMS"
#define MATCH_THRESHOLD 55

private nosave mapping help_files_player, help_files_creator, help_files_pt;
private nosave mapping synonyms;
private nosave string *player_dirs, *creator_dirs, *pt_dirs;

/**
 * Reads in the directories and places the results neatly into a mapping.
 * @param directories the directories to recursively read
 * @return a mapping with the locations of the help files
 */
private mapping read_directories( string *directories ) {
    string fname, dir;
    mixed file, files;
    mapping ret;
    int i;

    ret = ([ ]);
    for( i = 0; i < sizeof(directories); i++ ) {
        dir = directories[i];
        files = get_dir( dir+"*", -1 ) - ({"ERROR_REPORTS"});
        foreach( file in files ) {
            fname = file[0];
            if( file[1] == -2 ) {
                if( fname != "." &&
                    fname != ".." &&
                    fname != "old" &&
                    fname != "RCS") {
                    directories += ({ dir + fname + "/" });
                }
            } else if( fname != "." && fname != ".." && fname != "old") {
                if( !ret[fname] )
                    ret[fname] = ({ dir + fname });
                else
                    ret[fname] += ({ dir + fname });

                // Turn '_' into spaces.
                if( strsrch( fname, "_") > 0 ) {
                    fname = replace( fname, "_", " ");
                    if( !ret[fname] )
                        ret[fname] = ({ dir + fname });
                    else
                        ret[fname] += ({ dir + fname });
                }
            }
        }
    }

    return ret;

} /* read_directories() */

private mapping read_synonyms() {
    string *bits, bit;
    mapping tmp;

    tmp = ([ ]);
    bits = explode( read_file(SYNONYMS), "\n");

    foreach( bit in bits ) {
        bits = explode( bit, " ");
        tmp[bits[0]] = bits[1];
    }

    return tmp;

} /* read_synonyms() */

/**
 * This goes through and recreates the hash table for the dirs.
 */
void rehash_dirs() {
    help_files_player = read_directories(player_dirs);
    help_files_creator = read_directories(creator_dirs);
    help_files_pt = read_directories(pt_dirs);
    synonyms = read_synonyms();
} /* rehash_dirs() */

void create() {
    // These dirs will all be depth searched...
    player_dirs = ({ "/doc/helpdir/",
                     "/doc/concepts/",
                     "/doc/known_command/",
                     "/doc/room/",
                     "/doc/object/"
                     });

    creator_dirs = ({ "/doc/creator/",
                      "/doc/driver/",
                      "/doc/policy/",
                      "/doc/new/"
                      });

    pt_dirs = ({"/doc/playtesters/"});

    unguarded( (: rehash_dirs() :) );

} /* create() */

int *find_match_in_array( string entry, string *items )  {
    int i, j, elength, ilength, this_match, best_match, best_try;

    elength = strlen( entry );
    best_match = this_match = -1;

    for( i = sizeof( items ) - 1; i >= 0; i--, this_match = 0 )  {
        ilength = strlen( items[ i ] );
        for( j = 0; j < elength  &&  j < ilength; j++ )
            if( entry[ j ] == items[ i ][ j ] ||
                entry[ j ] == items[ i ][ j - 1 + ( j == 0 ) ]  ||
                entry[ j ] == items[ i ][ j + 1 - ( j + 1 == ilength ) ] )
                ++this_match;

        this_match = 100 * this_match / ( j == elength ? ilength : elength );

        if( this_match > best_match )  {
            best_match = this_match;
            best_try = i;
        }
    }

    return ({ best_try, best_match });

} /* find_match_in_array() */

/** @ignore yes */
private string letter_name( int letter, int size ) {
    string ret;

    if( size > 26 ) {
        ret = "aa";
        ret[0] = 'a' + ( letter / 26 );
        ret[1] = 'a' + ( letter % 26 );
        return ret;
    }

    ret = "a";
    ret[0] = 'a' + letter;
    return ret;

} /* letter_name() */

/** @ignore yes */
private string start_letter( int size ) { return letter_name( 0, size ); }

/** @ignore yes */
private string end_letter( int size ) {
    return letter_name( size - 1, size );
} /* end_letter() */

/** @ignore yes */
private int query_number_from_string( string name, int size ) {
    int pos;

    if( size > 26) {
        if( strlen(name) != 2 )
            return -1;
        name = lower_case(name);
        if( name[0] < 'a' || name[0] > 'z' )
            return -1;
        if( name[1] < 'a' || name[1] > 'z' )
            return -1;
        pos = ( name[0] - 'a' ) * 26 + name[1] - 'a';
        if( pos >= size )
            return -1;
        return pos;
    }

    if( strlen(name) != 1 )
        return -1;
    name = lower_case(name);
    if( name[0] < 'a' || name[0] > 'z' )
        return -1;
    pos = name[0] - 'a';
    if( pos >= size )
        return -1;

    return pos;

} /* query_number_from_string() */

/** @ignore yes */
void do_help( mixed stuff ) {
    string str;

    str = evaluate(stuff[1]);

    if( !str || !strlen(str) ) {
        write("Broken help file!\n");
        return;
    }

    TP->more_string( str, stuff[0] );

} /* do_help() */

/*
 * Make a string from nroff input...
 */
private string nroff_file( string name, string nroff_dir ) {
    string nroff_fn, str;

    nroff_fn = nroff_dir + replace( name, "/", ".");
    str = NROFF_H->cat_file( nroff_fn, 1 );
    if( !str ) {
        NROFF_H->create_nroff( name, nroff_fn );
        str = NROFF_H->cat_file( nroff_fn, 0 );
    }

    return str;

} /* nroff_file() */

/**
 * This method nips through the list of names doing the nroff stuff.
 * The array which is returned is an array of arrays, each internal
 * array consists of a name and help string.
 * @param names the array of names to process
 * @param nroff_dir the nroff directory to use for the output
 * @return an array of arrays
 */
mixed create_help_files( string *names, string nroff_dir ) {
    mixed ret;
    string *bits, name;

    ret = ({ });
    foreach( name in names ) {
        bits = explode( name, "/");
        ret += ({ ({ bits[<1] + " (" + name + ")",
               (: nroff_file( $(name), $(nroff_dir) ) :) }) });
    }

    return ret;

} /* create_help_files() */

/**
 * Searches the lists for things which we might have help on.
 * The array which is returned is an array of arrays, each internal
 * array consists of a name and help string.
 * @param name the help to search for
 * @param creator is this a creator searching
 * @return an array of arrays
 */
mixed query_help_on( string name, int creator, int playtester ) {
    string *files, *tmp;

    files = ({ });
    name = replace_string( name, " ", "_");

    if( help_files_player[name] )
        files += create_help_files( help_files_player[name], NROFF_DIR );

    if( playtester && help_files_pt && help_files_pt[name] )
        files += create_help_files( help_files_pt[name], NROFF_DIR );

    if( creator ) {
        if( help_files_creator && help_files_creator[name] )
            files += create_help_files( help_files_creator[name], NROFF_DIR );
        if( tmp = AUTODOC_H->query_help_on_func(name) )
            files += create_help_files( tmp, NROFF_DIR );
    }

    return files;

} /* query_help_on() */

/*
 * Returns a list of possible help files...
 */
private mixed help_list( string name ) {
    string *stuff;
    mixed str;
    object *fluff, blue;

    stuff = query_help_on( name, creatorp(TP), playtesterp(TP) );

    if( name == "room" || name == "here") {
        str = ENV(TP)->help_function();
        if( pointerp(str) )
            stuff += str;
        else if( str )
            stuff += ({ ({ ENV(TP)->short(), str }) });
    }

    if( stringp( str = TP->help_spell(name) ) )
        stuff += ({ ({ name + " (Spell)", (: $(str) :) }) });

    if( functionp(str) )
        stuff += ({ ({ name + " (Spell)", str }) });

    if( member_array( name, TP->query_channels() ) != -1 &&
        stringp( str = CHANNEL_H->channel_syntax( name, 1 ) ) )
        stuff += ({ ({ name + " (Channel)", (: $(str) :) }) });

    if( str = SOUL_H->help_string(name) )
        stuff += ({ ({ name + " (Soul)",
            (: $(SOUL_H)->help_string($(name)) :) }) });

    fluff = filter( match_objects_for_existence( name, ({ TP, ENV(TP) }) ),
        (: $1 && $1->help_function() :) );

    if( sizeof(fluff) )
        foreach( blue in fluff )
            stuff += blue->help_function();

    return stuff;

} /* help_list() */

/**
 * This method deals with the case where an entire string matches.
 * @param name the name to look for help on
 * @return 1 if the help was found, 0 if not
 */
int cmd( string name ) {
    mixed list;
    string suggestion, str;
    int *matches, i;

    list = help_list(name);

    // find out if they're looking for a synonym
    // eg. colour == colour or plan == finger.
    if( !sizeof(list) && mapp(synonyms) && synonyms[name] )
        list = help_list(synonyms[name]);

    if( !sizeof(list) ) {
        if( PLAYER_H->test_user(name) ) {
            add_failed_mess("That is a player, silly.\n");
            return 0;
        }

        // try a match for similarity.
        list = keys(help_files_player) + ({"command_list", "concepts"});
        matches = find_match_in_array( name, list );
        if( matches[1] > MATCH_THRESHOLD ) {
            suggestion = list[matches[0]];
        } else {
            // try a match for similarity among the synonyms
            list = keys(synonyms);
            matches = find_match_in_array( name, list );
            if( matches[1] > MATCH_THRESHOLD )
                suggestion = synonyms[list[matches[0]]];
        }

        if( !creatorp(TP) ) {
            log_file("MISSING_HELP", "%s %s looked for help on %s, "
                "recommended %s\n", ctime(time()), TP->query_name(),
                name, suggestion );
        }

        if( !suggestion )
            return notify_fail("Could not find any help on '"+name+"'.  You "
                "might find what you're looking for in 'help essentials'.\n");

        return notify_fail("Could not find any help on '"+name+"'.  Perhaps "
            "you are looking for "+suggestion+".\n");
    }

    if( sizeof(list) == 1 ) {
        if( creatorp(TP) )
            tell_object( TP, "Reading - "+list[0][0]+":\n");
        do_help(list[0]);
        return 1;
    }

    str = "";
    for( i = 0; i < sizeof(list); i++ )
        str += sprintf("%s) %s\n", letter_name( i, sizeof(list) ), list[i][0] );

    printf("%s help found multiple matches, please choose one of:\n"
      "%-*#s\nChoice: ", mud_name(), TP->query_cols(), str );

    input_to("help_input", 0, list );
    return 1;

} /* cmd() */

/**
 * The input loop for the help routines.
 * @param str the just inputed string
 * @param list the set of helps to choose from
 */
void help_input( string str, mixed list ) {
    int num;

    str = lower_case(str);

    if( str == "quit" || str == "**" || str == "." || str == "" ) {
        write("Ok, exiting help.\n");
        return ;
    }

    if( ( num = query_number_from_string( str, sizeof(list) ) ) == -1 ) {
        printf("Incorrect choice, must be between %s and %s.\nChoice: ",
            start_letter( sizeof(list) ), end_letter( sizeof(list) ) );
        input_to("help_input", 0, list );
        return;
    }

    if( creatorp(TP) )
        tell_object( TP, "Reading - "+list[num][0]+":\n");

    do_help(list[num]);

} /* help_input() */

/**
 * This method deals with the case where a command pattern was matched.
 * @param name the command to get help on
 * @return 0 if the command does not exist, 1 if it does exist
 */
int command_cmd( string name ) {
    mixed help;

    if( !help = TP->help_command(name) )
        return notify_fail("No such command as '"+name+"'.\n");

    if( functionp(help) )
        help = evaluate(help);

    TP->more_string( help, name );
    return 1;

} /* command_cmd() */

/**
 * This method deals with the case where a soul pattern was matched.
 * @param name the soul to get help on
 * @return 0 if the soul does not exist, 1 if it does exist
 */
int soul_cmd(string name) {
    string help;

    if( !help = SOUL_H->help_string(name) )
        return notify_fail("No such soul as '"+name+"'.\n");

    TP->more_string( help, name );
    return 1;

} /* soul_cmd() */

/**
 * This method deals with the case where a ritual or spell pattern was matched.
 * @param name the ritual or spell to get help on
 * @param spell 0 if it is a spell, 1 if it is a ritual
 * @return 0 if the ritual or spell does not exist, 1 if it does exist
 */
int spell_cmd(string name, int spell) {
    mixed help;

    if( !help = TP->help_spell(name) )
        return notify_fail("No such spell as '" + name + "'.\n");

    TP->more_string( ( functionp(help) ? evaluate(help) : help ), name );
    return 1;

} /* spell_cmd() */

/*
 * Print all the names of all the files in a dir...
 */
private void list_help( string title, string dir ) {
    string *files;

    files = get_dir( dir+"*") - ({".", "..", "ERROR_REPORTS", "RCS", "old"});
    printf("%s\n%-#*s\n", title, (int)TP->query_cols(),
        implode( files, "\n") );

} /* list_help() */

/**
 * This method gives the list of commands currently available.
 * @return always returns 1
 */
int command_list_cmd() {
    list_help("Command list, try 'help concepts' for a list of concepts.",
        "/doc/helpdir/");
    return 1;
} /* command_list_cmd() */

/**
 * This method gives the list of concepts currently available.
 * @return always returns 1
 */
int concepts_list_cmd() {
    list_help("Concepts list, try 'help command_list' for a list of commands.",
        "/doc/concepts/");
    return 1;
} /* concepts_list_cmd() */

string query_synonym( string name ) {
    if( mapp(synonyms) && synonyms[name] )
        return synonyms[name];
    return "";
} /* query_synonym() */

/**
 * This method returns the mapping of all the player help files.
 * @return the mapping of player help files
 */
mapping query_help_files_player() { return help_files_player; }

/**
 * This method returns the mapping of all the creator help files.
 * @return the mapping of creator help files
 */
mapping query_help_files_creator() { return help_files_creator; }

/**
 * This method returns the mapping of all the creator help files.
 * @return the mapping of creator help files
 */
mapping query_help_files_pt() { return help_files_pt; }

/** @ignore yes */
mixed query_patterns() {
    return ({ "<string>", (: cmd($4[0]) :),
      "command <string>", (: command_cmd($4[0]) :),
      "spell <string>", (: spell_cmd($4[0], 0 ) :),
      "ritual <string>", (: spell_cmd($4[0], 1 ) :),
      "soul <string>", (: soul_cmd($4[0]) :),
      "command_list", (: command_list_cmd() :),
      "concepts", (: concepts_list_cmd() :),
      "", (: concepts_list_cmd() :) });
} /* query_patterns() */

/** @ignore yes */
mixed stats() {
    return ({
        ({"player help files", sizeof( keys(help_files_player) ) }),
        ({"creator help files", sizeof( keys(help_files_creator) ) }),
        ({"playtester help files", sizeof( keys(help_files_pt) ) }),
        ({"autodoc help map", AUTODOC_H->query_help_map_size() }) ,
    });
} /* stats() */
