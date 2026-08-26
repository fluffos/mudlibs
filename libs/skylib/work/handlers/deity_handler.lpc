/**
 * Keeps track of all the information about deities.  Like the worshippers,
 * rituals, commands etc.
 * To set up a deity, please use the 'deitytool' command.
 * @author Olorin
 * @changed Changed to display correct alignment strings in deity finger
 * - Sandoz, 24th May 2001.
 * @changed Rewrote completely
 * - Sandoz, 20th Sept. 2002.
 */

#include <tune.h>
#include <deity.h>

#define DEITY_SAVE_DIR     HANDLER_SAVE_DIR "/deity/" // Deities Save Dir.
#define SAVE_FILE(x)       DEITY_SAVE_DIR+x+".o"      // Deities Save File.
#define TIME               ctime(time())              // Global Time.
#define CHECK_TIME         (4*60*60)                  // A deity per 4 hours.
#define MAX_AMOUNT         400                        // Used by contemplating.
#define DEITY              deities[deity]             // Mapping index.
#define SAVE               save_deity(deity)          // Saving macro.
#define CHECK              if( !check() ) return 0;   // Permission check.

class deity_data {
    int al_lower;
    int al_upper;
    int gender;
    int recruiting;
    string info;
    string title;
    string name;
    string *worshippers;
    string *rituals;
    string *commands;
}

private nosave mapping deities;
private nosave mapping contemplating;

private void check_arrays( string *all );

/** @ignore yes */
private void create() {
    string deity, *data;

    seteuid( master()->creator_file( file_name(TO) ) );

    data = map( get_dir(DEITY_SAVE_DIR+"*.o") -
        ({"contemplating.o"}), (: $1[0..<3] :) );

    deities = allocate_mapping( data, 0 );

    foreach( deity in data )
        if( file_exists( SAVE_FILE(deity) ) )
            DEITY = restore_variable( unguarded( (: read_file,
                SAVE_FILE(deity) :) ) );

    call_out( (: check_arrays :), CHECK_TIME, shuffle(keys(deities)) );

} /* create() */

/** @ignore yes */
private int check() {
    return file_name(PO) == "/secure/cmds/creator/deitytool";
} /* check() */

/** @ignore yes */
void dest_me() { destruct(TO); }

/** @ignore yes */
private void save_deity( string deity ) {
    if( undefinedp(DEITY) )
        error("No deity to save.\n");
    unguarded( (: write_file, SAVE_FILE(deity), save_variable(DEITY), 1 :) );
} /* save_deity() */

/** @ignore yes */
private void load_contemplating() {
    if( file_exists( SAVE_FILE("contemplating") ) )
        contemplating = restore_variable( unguarded( (: read_file,
            SAVE_FILE("contemplating") :) ) );

    if( !mapp(contemplating) )
        contemplating = ([ ]);

} /* load_contemplating() */

/** @ignore yes */
private void save_contemplating() {
    if( mapp(contemplating) )
        unguarded( (: write_file, SAVE_FILE("contemplating"),
            save_variable( contemplating ), 1 :) );
    else
        error("No contemplating data to save.\n");

} /* save_contemplating() */

/**
 * This method returns the names of all deities currently in the handler.
 * @return all the deity names
 */
string *query_deities() { return keys(deities); }

/**
 * This method tells if the deity exists.
 * @param deity the name of the deity to check
 * @return 1 if the deity exists, 0 if not
 */
int query_deity( string deity ) {
    deity = CAP( lower_case( deity ) );
    return !undefinedp(DEITY);
} /* query_deity() */

/**
 * @ignore yes
 * This method adds a deity to the handler.
 * It is the backend for the deitytool.
 */
int add_deity( string deity, string title, string info, int gender,
               int low, int high, int recruiting ) {
    CHECK;

    if( !undefinedp(DEITY) )
        return 0;

    DEITY = new( class deity_data,
            al_lower    : low,
            al_upper    : high,
            gender      : gender,
            recruiting  : recruiting,
            info        : info,
            title       : title,
            worshippers : ({ }),
            rituals     : ({ }),
            commands    : ({ }) );

    SAVE;

    return 1;

} /* add_deity() */

/**
 * @ignore yes
 * This method removes a deity from the handler.
 * It is the backend for the deitytool.
 */
int remove_deity( string deity ) {
    CHECK;

    if( undefinedp(DEITY) )
        return 0;

    map_delete( deities, deity );

    unguarded( (: rm, SAVE_FILE(deity) :) );

    return 1;

} /* remove_deity() */

/**
 * This method will return the whole contemplating array.
 * @return the array of contemplating people
 */
mapping query_contemplating() {
    if( !contemplating )
        load_contemplating();
    return copy(contemplating);
} /* query_contemplating() */

/**
 * This method queries the data for the given player.
 * @param player the player to get the contemplating data for
 * @return the contemplating data for the given player
 */
mapping query_player_cont_data( string player ) {
    return copy( query_contemplating()[player] );
} /* query_player_cont_data() */

/**
 * This method queries whether or not the given player has
 * finished contemplating the specified deity.
 * @param deity the deity to check
 * @param player the player to check
 * @return 1 if the player has completed contemplating
 * the specified deity, 0 if not
 */
int query_finished_contemplating( string deity, string player ) {
    mapping m;

    if( !mapp( m = query_contemplating()[player] ) )
        return 0;

    return m[deity] == -1;

} /* query_finished_contemplating() */

/**
 * This method will be called by the contemplating room.
 * It will add the specified amount of gps to the players
 * contemplating mapping.  If the amount is -1, it will
 * effectively complete the contemplation for the specified
 * deity.
 * @param player the player to update the mapping for
 * @param deity the deity the player contemplated
 * @param amount the amount of gps the player used,
 * or if it is -1, then this deity will be considered
 * as 'completed' for the player
 * @return 1 if the player has completed the contemplating
 * of the specified deity, 0 if not
 */
int complete_cont( string player, string deity, int amount ) {

    if( !player || !deity || !amount || !query_deity( deity ) )
        error("Invalid arguments to complete_cont().\n");

    if( !contemplating )
        load_contemplating();

    if( undefinedp(contemplating[player]) )
        contemplating[player] = allocate_mapping( keys(deities), 0 );

    if( amount == -1 )
        contemplating[player][deity] = amount;
    else
        contemplating[player][deity] += amount;

    save_contemplating();

    return contemplating[player][deity] == -1;

} /* complete_cont() */

/**
 * This method gives a string represtentation of the
 * alignment level.
 * @param alignment the alignment to return
 * @return alignment string
 */
string align_string( int alignment ) {
    switch( alignment ) {
      case -MAX_AL :
        return "extremely good";
      case -MAX_AL+1 .. -5001 :
        return "extremely good";
      case -5000 .. -2501 :
        return "very good";
      case -2500 .. -1251 :
        return "quite good";
      case -1250 .. -601 :
        return "good";
      case -600 .. -301 :
        return "barely good";
      case -300 .. 300 :
        return "neutral";
      case 301 .. 600 :
        return "barely evil";
      case 601 .. 1250 :
        return "evil";
      case 1251 .. 2500 :
        return "quite evil";
      case 2501 .. 5000 :
        return "very evil";
      case 5001 .. MAX_AL-1 :
        return "extremely evil";
      case MAX_AL :
        return "extremely evil";
      default :
        return "extremely evil";
    }
} /* align_string() */

/**
 * This method returns the lower alignment limit for the
 * given deity.
 * @param deity the name of the deity to query
 * @return the lower alignment limit
 */
int query_al_lower( string deity ) { return DEITY->al_lower; }

/**
 * This method sets the lower alignment limit for the
 * given deity.
 * @param deity the name of the deity
 * @return 1 upon success, 0 upon failure
 */
int set_al_lower( string deity, int number ) {
    CHECK;

    if( number < DEITY->al_upper ) {
        DEITY->al_lower = number;
        SAVE;
        return 1;
    }

    return 0;

} /* set_al_lower() */

/**
 * This method returns the upper alignment limit for the
 * given deity.
 * @param deity the name of the deity to query
 * @return the upper alignment limit
 */
int query_al_upper( string deity ) { return DEITY->al_upper; }

/**
 * This method sets the upper alignment limit for the
 * given deity.
 * @param deity the name of the deity
 * @return the upper alignment limit
 */
int set_al_upper( string deity, int number ) {
    CHECK;

    if( number > DEITY->al_lower ) {
        DEITY->al_upper = number;
        SAVE;
        return 1;
    }

    return 0;

} /* set_al_upper() */

/**
 * This method returns the middle alignment for the
 * given deity.
 * @param deity the name of the deity to query
 * @return the middle alignment value
 */
int query_al_middle( string deity ) {
    return ( DEITY->al_upper + DEITY->al_lower ) / 2;
} /* query_al_middle() */

/**
 * This method returns a random alignment between the limits for the
 * given deity.  This is used by NPCs to set themselves up
 * with a correct alignment for their deity.
 * @param deity the name of the deity
 * @return a random valid alignment
 */
int random_al( string deity ) {
    return DEITY->al_lower + roll_MdN( 10,
           DEITY->al_upper - DEITY->al_lower + 1 ) / 10 - 10;
} /* random_al() */

/**
 * This method determines if the alignment is valid for the deity.
 * @param deity the deity to check
 * @param number the alignment to check
 * @return 0 if it is valid, 1 if above upper_al, -1 if lower than lower_al
 */
int query_valid_al( string deity, int number ) {
    if( number > DEITY->al_upper )
        return 1;
    if( number < DEITY->al_lower )
        return -1;
    return 0;
} /* query_valid_al() */

/**
 * This method tells if the deity wants worshippers or not.
 * @param deity the deity to check
 * @return 1 if the deity wants worshippers, 0 if not
 */
int query_want_worshippers( string deity ) { return DEITY->recruiting; }

/**
 * This method sets if the deity wants worshippers or not.
 * @param deity the name of the deity to change
 * @param number the value of the flag
 */
void set_want_worshippers( string deity, int number ) {
    CHECK;
    DEITY->recruiting = number;
    SAVE;
} /* set_want_worshippers() */

/**
 * This method returns the gender of the deity.  The gender is the same
 * as used elsehwere in the game.  0 for neuter, 1 for male and 2 for female.
 * @see /std/living/gender.c
 * @param deity the deity name
 * @return the gender of the deity
 */
int query_gender( string deity ) { return DEITY->gender; }

/**
 * This method sets the gender of the deity.  The gender is the same
 * as used elsehwere in the game.  0 for neuter, 1 for male and 2 for female.
 * @see /std/living/gender.c
 * @param deity the deity name
 * @param number the gender to set the deity to
 */
void set_gender( string deity, int number ) {
    CHECK;
    DEITY->gender = number;
    SAVE;
} /* set_gender() */

/**
 * This method returns the pronoun for the deity.
 * @see /std/living/gender->query_pronoun()
 * @param deity the name of the deity to get the pronoun of
 * @return the pronoun of the deity
 */
string query_pronoun( string deity ) {
    return ({"it", "he", "she"})[ DEITY->gender ];
} /* query_pronoun() */

/**
 * This method returns the objective for the deity.
 * @see /std/living/gender->query_objective()
 * @param deity_name the name of the deity to get the objective of
 * @return the objective of the deity
 */
string query_objective( string deity ) {
    return ({"it", "him", "her"})[ DEITY->gender ];
} /* query_objective() */

/**
 * This method returns the possessive for the deity.
 * @see /std/living/gender->query_possessive()
 * @param deity the name of the deity to get the possessive of
 * @return the possessive of the deity
 */
string query_possessive( string deity ) {
    return ({"its", "his", "her"})[ DEITY->gender ];
} /* query_possessive() */

/**
 * This method returns information about the deity.  This is used
 * in the finger information and when querying about joining the
 * clergy.
 * @param deity the name of the deity to get information on
 * @return information about the deity
 */
string query_info( string deity ) { return DEITY->info; }

/**
 * This method sets information about the deity.  This is used
 * in the finger information and when querying about joining the
 * clergy.
 * @param deity the name of the deity to set information for
 * @param text the new value for the information
 */
void set_info( string deity, string text ) {
    CHECK;
    DEITY->info = text;
    SAVE;
} /* set_info() */

/**
 * This method returns the title for the deity.
 * @param deity the deity to get the title of
 * @return the title of the deity
 */
string query_title( string deity ) { return DEITY->title; }

/**
 * This method sets the title for the deity.
 * @param deity the deity to set the title for
 * @param text the new title of the deity
 */
void set_title( string deity, string text ) {
    CHECK;
    DEITY->title = text;
    SAVE;
} /* set_title() */

/**
 * This method returns the string used when fingering a deity.
 * @param deity the deity to finger
 * @return the information relating to the deity
 */
string query_deity_finger( string deity ) {
    string ret;
    int i;

    deity = CAP( lower_case(deity) );

    if( undefinedp(DEITY) )
        return 0;

    ret = "%^BOLD%^"+deity+", "+DEITY->title+"%^RESET%^.\n"+DEITY->info+"\n";

    if( !query_want_worshippers( deity ) ) {
        ret += CAP( query_pronoun( deity ) )+" cannot be worshipped "
            "currently.\n";
    } else {
        i = sizeof( filter( DEITY->worshippers, (: !creatorp($1) :) ) );
        ret += CAP( query_pronoun( deity ) )+" only wants worshippers "
            "who are between "+align_string( DEITY->al_lower )+" and "+
            align_string( DEITY->al_upper )+".\n";
        if( query_want_worshippers( deity ) )
            ret += CAP( query_pronoun( deity ) )+" has "+( !i ? "no" :
                query_num( i ) )+" worshipper"+( i == 1 ? "" : "s")+".\n";
        else
            ret += CAP( query_pronoun( deity ) )+" doesn't want any "
                "worshippers currently.\n";
    }

    return ret;

} /* query_deity_finger() */

/**
 * This method returns the names of all worshippers.
 * @param deity the name of the deity to query
 * @return the worshippers array
 */
string *query_worshippers( string deity ) { return copy(DEITY->worshippers); }

/**
 * This method checks if a player is the worshipper of the god
 * @param deity the name of the deity
 * @param worshipper the worshipper to check
 * @return 1 if the player is a worshipper, 0 if not
 */
int query_worshipper( string deity, string worshipper ) {
    return member_array( worshipper, DEITY->worshippers ) != -1;
} /* query_worshipper() */

/**
 * This method adds a worshipper into the worshippers array.
 * @param deity the name of the deity
 * @param worshipper the worshipper to add
 * @return returns 1 if successfully added, 0 if already exists
 */
int add_worshipper( string deity, string worshipper ) {
    if( !worshipper || member_array( worshipper, DEITY->worshippers ) != -1 )
        return 0;

    DEITY->worshippers += ({ worshipper });
    SAVE;
    log_file("DEITIES", "%s - %s added %s.\n", TIME, deity, CAP(worshipper) );

    // They won't be contemplating any more.
    if( query_player_cont_data( worshipper ) ) {
        map_delete( contemplating, worshipper );
        save_contemplating();
    }

    return 1;

} /* add_worshipper() */

/**
 * This method deletes the given worshipper.
 * @param deity the name of the deity
 * @param worshipper the worshipper to delete
 * @param reason the reason for deletion
 * @return 1 if the operation was successful, 0 if it failed
 */
int delete_worshipper( string deity, string worshipper, string reason ) {
    int i;

    CHECK;

    if( ( i = member_array( worshipper, DEITY->worshippers ) ) != -1 ) {
        DEITY->worshippers = delete( DEITY->worshippers, i, 1 );
        SAVE;
        log_file("DEITIES", "%s - %s deleted %s from %s - %s.\n",
              TIME, ( TP ? CAP( TP->query_name() ) : file_name(PO) ),
              CAP(worshipper), deity, reason );
        return 1;
    }

    return 0;

} /* delete_worshipper() */

/**
 * This method deletes the given worshipper by name from all
 * deities' arrays.  This is called by the refresh handler
 * when the player refreshes or is deleted.
 * @param worshipper the worshipper to refresh
 * @return 1 if the operation was successful, 0 if it failed
 */
void refresh_worshipper( string worshipper ) {
    int i;
    string deity;
    class deity_data data;

    if( base_name(PO) != REFRESH_H )
        error("No permission to refresh a worshipper.\n");

    foreach( deity, data in deities )
        if( ( i = member_array( worshipper, DEITY->worshippers ) ) != -1 ) {
            DEITY->worshippers = delete( DEITY->worshippers, i, 1 );
            SAVE;
            log_file("DEITIES", "%s - %s deleted %s - refreshed.\n",
                TIME, deity, CAP(worshipper) );
        }

    // Remove them from the contemplating mapping as well.
    if( query_player_cont_data( worshipper ) ) {
        map_delete( contemplating, worshipper );
        save_contemplating();
    }

} /* refresh_worshipper() */

/**
 * This method queries the commands given to worshippers.
 * @param deity the deity to get the commands for
 * @return the commands array
 */
string *query_commands( string deity ) { return copy(DEITY->commands); }

/**
 * This method adds a command to be given to the worshippers.
 * @param deity the deity to add the command for
 * @param command the name of the command
 * @return 1 if successful, 0 if not
 */
int add_command( string deity, string command ) {
    CHECK;

    if( member_array( command, DEITY->commands ) == -1 ) {
        DEITY->commands += ({ command });
        SAVE;
        return 1;
    }

    return 0;

} /* add_command() */

/**
 * This method deletes a command to be given to the worshippers.
 * @param deity the name of the deity
 * @param command the name of the command to delete
 * @return 1 if success, 0 if not
 */
int delete_command( string deity, string command ) {
    int i;

    CHECK;

    if( ( i = member_array( command, DEITY->commands ) ) != -1 ) {
        DEITY->commands = delete( DEITY->commands, i, 1 );
        SAVE;
        return 1;
    }

    return 0;

} /* delete_command() */

/**
 * This method queries the rituals given by this deity.
 * @param deity the deity to get the rituals for
 * @return the rituals array
 */
string *query_rituals( string deity ) { return copy(DEITY->rituals); }

/**
 * This method adds a ritual to the set given by the deity.
 * @param deity the name of the deity
 * @param ritual the name of the ritual to add
 * @return returns 1 if successful, 0 if not
 */
int add_ritual( string deity, string ritual ) {
    CHECK;

    if( member_array( ritual, DEITY->rituals ) == -1 ) {
        DEITY->rituals += ({ ritual });
        SAVE;
        return 1;
    }

    return 0;

} /* add_ritual() */

/**
 * This method deletes a ritual from the deity.
 * @param deity the name of the deity
 * @param ritual the ritual to delete
 */
int delete_ritual( string deity, string ritual ) {
    int i;

    CHECK;

    if( ( i = member_array( ritual, DEITY->rituals ) ) != -1 ) {
        DEITY->rituals = delete( DEITY->rituals, i, 1 );
        SAVE;
        return 1;
    }

    return 0;

} /* delete_ritual() */

/** @ignore yes */
private void check_arrays( string *all ) {
    string deity, worshipper, reason, tmp;

    if( !sizeof(all) ) {
        if( !sizeof( all = shuffle( keys(deities) ) ) )
            return;
    }

    deity = all[0];
    all = all[1..];

    call_out( (: check_arrays :), CHECK_TIME, all );

    reason = "";

    foreach( worshipper in DEITY->worshippers ) {
        tmp = 0;

        if( !PLAYER_H->test_user( worshipper ) )
            tmp = "doesn't exist anymore";
        else if( PLAYER_H->test_deity( worshipper ) != deity )
            tmp = "following another deity";

        if( tmp ) {
            reason += sprintf("%s - %s removed %s - %s.\n",
                      TIME, deity, CAP(worshipper), reason );
            deities[deity]->worshippers -= ({ worshipper });
        }
    }

    if( reason != "") {
        SAVE;
        log_file("DEITIES", reason );
    }

} /* check_arrays() */

/**
 * This method checks to see if the worshipper is valid.  This basically
 * checks to see if they exist and they are worshipping the current deity.
 * @param worshipper the worshipper to check
 * @param deity the deity they should be worshipping according to the handler
 * @return 0 if they are not valid, 1 if they are
 * @see "/handlers/player_handler"->test_deity()
 */
int valid_worshipper( string worshipper, string deity ) {
    return ( PLAYER_H->test_user( worshipper ) &&
             PLAYER_H->test_deity( worshipper ) == deity );
} /* valid_worshipper() */

/**
 * This method returns the colour for a deity, as used by the holy dust
 * and ritual messages.
 * @return the colour of the deity
 */
string query_deity_colour( string deity ) { return D_COLOUR(deity); }

/**
 * This method returns a string containing all the vital information
 * on a deity.
 * @param deity the deity to get the data for
 * @return vital info about a deity
 */
string query_deity_data( string deity ) {
    int cols = TP->query_cols();
    mixed tmp;
    string ret = "";

    switch( DEITY->gender ) {
      case 1:
        tmp = "Male";
      break;
      case 2:
        tmp = "Female";
      break;
      default:
        tmp = "Neuter";
    }

    ret += "Name        : "+deity+"\n";
    ret += "Gender      : "+tmp+"\n";
    ret += "Title       : "+DEITY->title+"\n";
    tmp = DEITY->al_lower;
    ret += "Lower AL    : "+tmp+" ("+align_string(tmp)+")\n";
    tmp = DEITY->al_upper;
    ret += "Upper AL    : "+tmp+" ("+align_string(tmp)+")\n";
    ret += "Recruiting  : "+( DEITY->recruiting ? "Yes" : "No")+"\n";
    ret += "Worshippers : "+sizeof( DEITY->worshippers )+"\n";
    ret += "Finger Info : "+indent( DEITY->info, 14, cols )[14..]+"\n";

    if( !sizeof(DEITY->rituals) )
        tmp = "None";
    else
        tmp = indent( query_multiple_short( sort_array( DEITY->rituals, 1 ) ),
            14, cols )[14..];

    ret += "Rituals     : "+tmp+"\n";

    if( !sizeof(DEITY->commands) )
        tmp = "None";
    else
        tmp = indent( query_multiple_short( sort_array( DEITY->commands, 1 ) ),
            14, cols )[14..];

    ret += "Commands    : "+tmp+"\n";

    return ret;

} /* query_deity_data() */

/**
 * This method creates an amount of holy dust for the specified deity.
 * @param amount the amount of dust to create
 * @param deity the deity to create the dust for
 * @return the newly created dust object
 */
object make_dust( int amount, string deity ) {
    object dust;
    string adj, col;

    dust = clone_object("/obj/cont_medium");
    dust->set_name("dust");

    adj = D_ADJ(deity);
    col = D_COL(deity);

    dust->add_adjective(({ adj, col, "some", "pinch", "pinches",
                           "handful", "handfuls", "hatful", "hatfuls",
                           "bucketful", "bucketfuls", "of"}) );

    dust->set_medium_alias( CAP(adj)+CAP(col)+"Dust" );

    // REUSE THE VARIABLE.
    col = query_deity_colour(deity);

    dust->set_short( col+" dust" );
    dust->set_long("This is $pile_size$ of "+col+" dust, $amount_size$.  "
                   "It has a peculiar bittersweet smell and something about "
                   "it seems to hint there is a connection between the dust "
                   "and "+deity+", "+DEITY_H->query_title(deity)+".\n");

    dust->add_property("determinate", "some ");
    dust->add_property( deity, 1 );
    dust->set_weight_unit( ({ 1, 4000 }) );
    dust->set_value_scale( 0.00001 );
    dust->set_pile_name("pile");

    dust->set_amount_types( ([ "pinch": ({ 40, "pinches" }),
                               "handful": ({ 2000, "handfuls" }),
                               "hatful": ({ 50000, "hatfuls" }),
                               "bucketful": ({ 100000, "bucketfuls" }),
                             ]) );
    dust->set_pile_types( ({ 40, "tiny",
                             10000, "small",
                             50000, "medium",
                             200000, "large",
                             "huge"
                          }) );

    dust->set_amount( amount || 40 );

    return dust;

} /* make_dust() */

/** @ignore yes */
mixed stats() {
    return ({ ({"deities", sizeof(deities) }) });
} /* test_stats() */
