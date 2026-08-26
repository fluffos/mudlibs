/**
 * The main login object.
 * <p>
 * Originally written by Pinkfish, who knows when.
 * <p>
 * Mangled bunches of times by Pinkfish since then and various other wombles
 * all over the place.
 * <p>
 * Put in the random names and the delete character menu options in
 * January 1996.
 * <p>
 * Got excited again in June 1996 and modified the random name stuff
 * and made the new player ban code a bit keener - Pinkfish.
 * <p>
 * So excited in January 1997 that I wrote a login queue.  Most of it
 * works.  Bug fixing in progress forever.
 * @author Pinkfish
 * @changed A bunch of changes concerning logging in while there is a
 * shut-down and logging in invisible. Also added support for restricting
 * login access - Sandoz, 2003.
 */

#include <random_names.h>
#include <login_handler.h>
#include <clubs.h>
#include <access.h>

inherit "/global/player/family";

#define QUOTE_HANDLER "/handlers/pqf_handler"

#define MAX_RETRIES   3
#define MIN_LEN       3
#define MAX_LEN       12

#undef DEBUG
#undef LOOKUP_IDENT

#ifdef LOOKUP_IDENT
#define IDENT         "/net/daemon/out_auth"
#endif

#define GUEST         1
#define NEW           2
#define CURRENT       3
#define DELETE        4
#define UNDELETE      5

#define LOGON_MENU    1
#define RANDOM_OR_NOT 2
#define MAIN_RANDOM   3
#define RANDOM_NAME   4

#define TIMEOUT_TIME  120
#define THROWOUT_TIME (3*TIMEOUT_TIME)

inherit OBJECT_OBJ;

int cols;
int Str;
int Dex;
int gender;
int creator;
int time_on;
int start_time;

string password;
string title;
string cap_name;
string last_on_from;

mapping new_skills;
mapping aliases;

nosave int auto_authorise;
nosave int go_invis;
nosave int no_times;
nosave int the_rows;
nosave int the_cols;
nosave int login_port;
nosave int login_start_time;
nosave string player_ob;
nosave string terminal_name;
nosave string *random_names;
nosave object other_copy;
nosave object new_copy;

// Used to get the property stuff while not logged on working.
nosave string prop_var_name = "map_prop ";

// For login queue handling.
nosave int can_login;
nosave int login_num;
nosave int net_dead;
nosave string name;

#ifdef LOOKUP_IDENT
nosave string my_ident;
nosave int got_return;
nosave object ident_player_ob;
#endif

mapping restore_stats;

private varargs void logon_menu();
protected void delete_character_menu();
void enter_name( string str, string prompt, int type, mixed *args );
varargs void name_menu(int guest);
protected void delete_character_menu();
void random_name_menu(string lang, int guest, int re_gen);
void main_random_name_menu(int guest);
protected void logon3();
protected void logon4(int bing);
protected void logon5(int new_pl);
protected void begin(int new_pl);
protected void begin2(int new_player);
protected void try_throw_out(int new_pl);
string query_player_file_name(string name);
string query_delete_player_file_name(string name);
protected void check_terms(string str, int new_pl);
void finger_player(string str);
void just_name_menu(int guest);

void create() {
    ::create();
    cols = 79;
    gender = -1;
    Str = -1;
    Dex = -1;
    start_time = time();
    map_prop = ([ ]);
    aliases = ([ ]);
    seteuid( "Root" );
    set_name( "logon" );
    player_ob = "/global/player";
} /* create() */

private void set_name( string nam ) {
    name = nam;
} /* set_name() */

/** @ignore yes */
string query_name() { return name; }

/** @ignore yes */
int query_cols() { return cols; }

/** @ignore yes */
string query_title() { return "the title-less"; }

/** @ignore yes */
int query_creator() { return creator; }

/** @ignore yes */
string query_cap_name() { return cap_name || "Logon"; }

/** @ignore yes */
int query_login_port() { return login_port; }

/** @ignore yes */
void set_login_port( int port ) {
    if( master() == PO )
        login_port = port;
} /* set_login_port() */

private int check_valid_name( string str ) {
    int i;

    for( i = 0; i < strlen(str); i++ ) {
        if( str[i] < 'a' || str[i] > 'z')
            return i;
    }

    return -1;

} /* check_valid_name() */

/** @ignore yes */
void logon() {

    if( SHUTDOWN_H->query_shutdown() < 1 ) {
        write( mud_name()+" is in the process of shutting down.\n"
            "Please try again in a few minutes...\n");
        return dest_me();
    }

    call_out("time_out", TIMEOUT_TIME );
    login_start_time = time();

    if( LOGIN_H->is_discworld_full(0) ) {
        write("***  Warning there are no player slots available  ***\n"
              "***   If you login you will be placed in a queue  ***\n");
    }

#ifdef LOOKUP_IDENT
    // This is a bit of a hassle.  Make it less likely to blow up.
    catch( IDENT->query_auth("finished_auth") );
#endif

    if( TP == TO )
        cat( choice( ({ "/doc/login/LOGON",
                        "/doc/login/LOGON2",
                        "/doc/login/LOGON3" }) ) );
//          cat("/doc/login/XMASLOGON");


    logon_menu( 1 );

} /* logon() */

/** @ignore yes */
private varargs void logon_menu( int flag ) {
    string mess;
    int i;

    if( !flag )
        write("\n");

    if( ( i = SHUTDOWN_H->query_shutdown() ) < 60 ) {
        write( repeat_string("-", cols )+"\n");
        switch( i ) {
          case 1..60 :
            write( sprintf("%|=*s", cols, mud_name()+" is shutting down "
                "in "+i+" minutes.\n") );
          break;
          default :
            write( sprintf("%|=*s", cols, mud_name()+" is shutting down "
                "NOW!\n") );
        }
        write( repeat_string("-", cols )+"\n\n");
    }

    if( i = LOGIN_H->query_login_mode() )
        write( mud_name()+" is currently running in "+
            LOGIN_H->get_login_mode( i )+".\n\n");

    // Check if the IP has been locked down due to excessive login failures.
    if( LOGIN_H->site_lockeddown(query_ip_number(TO)) ) {
        write("Sorry, your site has been locked down for excessive failed "
            "login attempts.  If you have forgotten your password please "
            "email "+ADMIN_EMAIL+".  If you have not failed to login, please "
            "try again later.\n");

        mess = sprintf("Attempted login from locked down site: %s.",
            query_ip_number(TO) );

        log_file("BAD_PASSWORD", "%s %s\n", ctime(time()), mess );
        event( efun::users(), "inform", mess, "bad-password");
        dest_me();
    }

        
    write("Please choose one of the following options:\n"
      "Q - Quit               M - Print this menu again\n"
      "N - New character      U - Short list of who is on-line\n"
      "G - Guest character    D - Delete your character\n"
      "F - Finger someone\n\n"
      "Or, enter your current character's name\n\n");

    write("Your choice [D,F,G,M,N,U,Q,<name>]: " );

    input_to("login_choice");

} /* logon_menu() */

/** @ignore yes */
void login_choice( string bing ) {
    int i;

    bing = lower_case(bing);

    while( bing[0] == ' ' || bing[0] == '\t')
        bing = bing[1..];

    if( !strlen(bing) )
        bing = "z";

    // Long string and not of the format 'f name' (for finger).
    if( strlen(bing) >= MIN_LEN && bing[0..1] != "f ") {
        // It is probably someone entering a name.
        return enter_name( bing, 0, CURRENT, ({ LOGON_MENU }) );
    }

    switch( bing[0] ) {
      case 'n' :
        if( i = LOGIN_H->query_login_mode() ) {
            write("Sorry, you cannot create a new character while "+
                mud_name()+" is running in "+LOGIN_H->get_login_mode(i)+".  "
                "Please try again later.\n");
            break;
        }

        if( BASTARDS_H->no_new_players(TO) ) {
            write("New player logins are disabled from this site.  "
                "If you wish to create a character, please email "+
                ADMIN_EMAIL+" with the player name you would like to "
                "use.\n");
            break;
        }

        write( LOGIN_H->get_message("/doc/login/NEW_USER") );
        name_menu(NEW);
        return;
      case 'g' :
        if( i = LOGIN_H->query_login_mode() ) {
            write("Sorry, you cannot login as a guest while "+
                mud_name()+" is running in "+LOGIN_H->get_login_mode(i)+".  "
                "Please try again later.\n");
            break;
        }

        if( BASTARDS_H->no_new_players(TO) ) {
            write("New player logins are disabled from this site.  "
                "If you wish to create a character, please email "+
                ADMIN_EMAIL+".\n");
            break;
        }

        write( LOGIN_H->get_message("/doc/login/GUEST_LOGIN") );
        write("Enter the name to use: ");
        input_to("enter_name", 0, "Enter the name to use: ", GUEST,
            ({ LOGON_MENU }) );
        return;
      case 'm' :
        logon_menu();
        return;
      case 'q' :
        write("Come back soon!\n");
        dest_me();
        return;
      case 'd' :
        delete_character_menu();
        return ;
      case 'u' :
        write("Here is a list of the people currently playing "+
            mud_name()+":\n"+implode( sort_array( map( filter( users(),
                (: !$1->query_invis() :) ), (: $1->query_cap_name() :) ),
                (: strcmp :) ), ", ")+"\n");
        break;
      case 'f' :
        bing = bing[1..];

        if( bing[0] == ' ') {
            while( bing[0] == ' ')
                bing = bing[1..];
            finger_player(bing);
        } else {
            write("Who do you wish to finger? ");
            input_to("finger_player");
        }
        return;
      default :
        write("Incorrect choice.\n");
        break;
    }

    write("Your choice [M,N,G,U,D,F,Q,<name>]: ");

    input_to("login_choice");
    return;

} /* login_choice() */

/** @ignore yes */
void finger_player( string str ) {
    string ret;

    if( stringp(str) && strlen(str) >=  MIN_LEN ) {
        if( !ret = FINGER_H->finger_info( str, 1 ) )
            write("I am sorry, the player "+str+" does not appear to "
                "exist.\n");
        else
            write( ret );
    } else {
        write("Invalid name, returning to the login menu.\n");
    }

    write("Your choice [M,N,G,U,D,F,Q,<name>]: ");

    input_to("login_choice");
    return;

} /* finger_player() */

/** @ignore yes */
protected void delete_character_menu() {
    write( LOGIN_H->get_message("/doc/login/DELETE") );
    write("\n\nThis is for PERMANENT deletion of your character.\n\n"
        "Which character would you like to delete? " );
    input_to("enter_name", 0, 0, DELETE, ({ LOGON_MENU }) );
} /* delete_character_menu() */

/**
 * @ignore yes
 * Name is set to the name of the character to delete.
 */
protected void delete_character() {
    if( find_player(query_name()) ) {
        write("\n\n"+query_name()+" is currently logged in, unable to "
            "delete.\n\n");
        logon_menu();
        return;
    }

    // To delete ourselves, we move the player file from where it is now
    // into the deleted character dir.
    if( !unguarded( (: rename, query_player_file_name(query_name())+".o",
        query_delete_player_file_name( query_name() )+".o" :) ) ) {
        // Update the time.
        unguarded( (: write_file,
            query_delete_player_file_name(query_name())+".o", "junk 0\n" :) );
        write("\n\nPLEASE READ:\nCharacter deleted.  You have 10 days "
            "cooling off time, during which you may reinstate your "
            "character.  To reinstate it simply log on again and it will "
            "reinstate it for you.\n\n\n");
    } else {
        write("WARNING! Unable to delete your character.\n");
    }

    logon_menu();

} /* delete_character() */

/** @ignore yes */
varargs void name_menu( int guest ) {
    if( SHUTDOWN_H->query_shutdown() < 5 ) {
        write("It is too close to the shut-down to create a new character.\n"
            "Please try again in a few minutes.\n" );
        return dest_me();
    }

    just_name_menu(guest);

} /* name_menu() */

/** @ignore yes */
void just_name_menu( int guest ) {
    write( LOGIN_H->get_message("/doc/login/NEW_USER_NAME") );
    write("\nEnter the name you wish to play on "+mud_name()+": ");
    input_to("just_name", 0, guest );
} /* just_name_menu() */

/** @ignore yes */
void random_or_not( string str, int guest ) {
    if( str[0] == 'y' || str[0] == 'Y')
        main_random_name_menu(guest);
    else if( str[0] == 'n' || str[0] == 'N')
        just_name_menu(guest);
    else
        name_menu(guest);
} /* random_or_not() */

/** @ignore yes */
void just_name( string str, int guest ) {
    if( strlen(str) >= MIN_LEN ) {
        write("\n");
        enter_name( str, 0, guest, ({ RANDOM_OR_NOT, guest }) );
        return;
    }

    switch( str[0] ) {
      case 'm' :
      case 'M' :
      case 'q' :
      case 'Q' :
        logon_menu();
      break;
      case 'r' :
      case 'R' :
        main_random_name_menu(guest);
      break;
      default :
        just_name_menu(guest);
    }

} /* just_name() */

/** @ignore yes */
void main_random_name_menu( int guest ) {
    int i;
    string *langs;

    langs = RANDOM_NAME_GENERATOR->query_languages();

    for( i = 0; i < sizeof(langs); i++ )
        langs[i] = sprintf("%c - %s", ( i + '1'), CAP( langs[i] ) );

    write("You are choosing a name for the first time on "+mud_name()+".\n"
        "You can choose a name which is generated to sound something "
        "like:\n"+implode( langs, "\n")+"\n"
        "M - Main Menu\n"
        "Q - Quit\n\n"
        "Or you can type in a name of your choice now.\n\n"
        "Your choice? ");

    input_to("name_choice", 0, sizeof(langs), guest );

} /* main_random_name_menu() */

/** @ignore yes */
void name_choice( string str, int len, int guest ) {
    string lang;

    if( strlen(str) == 1 ) {
        if( str[0] >= '1' && str[0] <= ('1'+len-1) ) {
            lang = RANDOM_NAME_GENERATOR->query_languages()[str[0]-'1'];
            random_name_menu( lang, guest, 1 );
            return;
        }

        if( str[0] == 'm' || str[0] == 'M') {
            logon_menu();
            return;
        }

        if( str[0] == 'q' || str[0] == 'Q') {
            write("See you again soon!\n");
            dest_me();
            return;
        }

        write("Incorrect choice.\n");

    } else if( str != "") {
        enter_name( str, 0, guest, ({ MAIN_RANDOM, guest }) );
        return;
    }

    main_random_name_menu(guest);

} /* name_choice() */

/** @ignore yes */
void random_name_menu( string lang, int guest, int re_gen ) {
    int i;

    write("Here is a list of 9 random names.  Please choose one:\n");
    if( re_gen ) {
        random_names = allocate(9);
        for( i = 0; i < sizeof(random_names); i++ ) {
            random_names[i] = RANDOM_NAME_GENERATOR->unique_name(lang);
            write( sprintf("%c - %s\n", i+'1', random_names[i] ) );
        }
    } else {
        for( i = 0; i < sizeof(random_names); i++ )
            write( sprintf("%c - %s\n", i+'1', random_names[i] ) );
    }

    write("M - Main Menu\n"
          "N - Name Menu\n"
          "G - Generate a new set of names\n"
          "Q - Quit\n"
          "Or, type in your name of choice\n\n"
          "Your choice? ");

    input_to("random_name_choice", 0, lang, guest );

} /* random_name_menu() */

/** @ignore yes */
void random_name_choice( string str, string lang, int guest ) {
    if( strlen(str) == 1 ) {
        switch( str[0] ) {
          case '1' :
          case '2' :
          case '3' :
          case '4' :
          case '5' :
          case '6' :
          case '7' :
          case '8' :
          case '9' :
            enter_name( random_names[ str[ 0 ] - '1' ], 0, guest,
                ({ RANDOM_NAME, lang, guest }) );
            return;
          case 'n' :
          case 'N' :
            main_random_name_menu(0);
            return;
          case 'm' :
          case 'M' :
            logon_menu();
            return;
          case 'g' :
          case 'G' :
            random_name_menu( lang, guest, 1 );
            return ;
          case 'q' :
          case 'Q' :
            write("See you again soon!\n");
            dest_me();
            return;
          default :
            write("Incorrect choice.\n");
        }
    } else if( str != "") {
        enter_name( str, 0, guest, ({ RANDOM_NAME, lang, guest }) );
        return;
    }

    random_name_menu( lang, guest, 0 );

} /* random_name_choice() */

/** @ignore yes */
void next_menu( mixed *args ) {
    switch( args[ 0 ] ) {
      case LOGON_MENU :
        return logon_menu();
      case RANDOM_OR_NOT :
        return random_or_not("n", args[ 1 ] );
      case MAIN_RANDOM :
        return main_random_name_menu( args[ 1 ] );
      case RANDOM_NAME :
        return random_name_menu( args[ 1 ], args[ 2 ], 0 );
      default :
        write("An error has occurred in next_menu().\n");
        dest_me();
    }
} /* next_menu() */

/** @ignore yes */
void enter_name( string str, string prompt, int type, mixed *args ) {
    int tmp;

    go_invis = 0;
    auto_authorise = 0;

    if( str == "")
        return next_menu( args );

    // Everything blows up on a banishment.
    if( str[0] == ':') {
        str = str[1..];
    } if( str[0] == '#') {
        go_invis = 1;
        str = str[1..];
    } else if( str[0] == '@') {
        go_invis = -1;
        str = str[1..];
    }

    if( !LOGIN_H->query_can_log_in( lower_case(str) ) ) {
        write("You cannot login right now, because "+mud_name()+" is running "
            "in "+LOGIN_H->get_login_mode( LOGIN_H->query_login_mode() )+".  "
            "Please try again later.\n");
        logon_menu();
        return;
    }

    set_name( lower_case(str) );

    if( PLAYER_H->test_banished(query_name()) ) {
        write("Sorry, the player name ["+query_name()+"] has been banished.\n");
        if( prompt ) {
            write(prompt);
            input_to("enter_name", 0, prompt, type, args );
        } else {
            next_menu( args );
        }
        return;
    }

    if( strlen(query_name()) < MIN_LEN && type != CURRENT &&
        type != DELETE ) {
        write("Sorry, the player name ["+query_name()+"] is too short (min "+
            MIN_LEN+" characters).\n");
        if( prompt ) {
            write(prompt);
            input_to("enter_name", 0, prompt, type, args );
        } else {
            next_menu( args );
        }
        return;
    }

    if( strlen(query_name()) > MAX_LEN ) {
        write("Sorry, the player name "+query_name()+" is too long (max "+
            MAX_LEN+" characters).\n");
        if( prompt ) {
            write(prompt);
            input_to("enter_name", 0, prompt, type, args );
        } else {
            next_menu( args );
        }
        return;
    }

    if( ( tmp = check_valid_name( query_name() ) ) != -1 ) {
        write("Invalid character '"+str[tmp..tmp]+"'  ("+str+").\n\n");
        if( prompt ) {
            write(prompt);
            input_to("enter_name", 0, prompt, type, args );
        } else {
            next_menu( args );
        }
        return;
    }

    switch( type ) {
      case GUEST :
        if( LOGIN_H->is_discworld_full(0) ) {
            write("Yesterday is too old, today is much newer.\n"
              "Don't give away your dreams, store them in streams.\n\n"
              "Sorry, guests cannot login currently, too many players.\n");
            logon_menu();
            return;
        }
      case NEW :
        if( sscanf( query_name(), "%*sblack%*s") == 2 ||
            sscanf( query_name(), "%*sblood%*s") == 2 ||
            sscanf( query_name(), "%*scyber%*s") == 2 ||
            sscanf( query_name(), "%*sdark%*s") == 2 ||
            sscanf( query_name(), "%*spenis%*s") == 2 ||
            sscanf( query_name(), "%*scock%*s") == 2 ||
            sscanf( query_name(), "%*spussy%*s") == 2 ||
            sscanf( query_name(), "%*sfuck%*s") == 2 ||
            sscanf( query_name(), "%*sshit%*s") == 2 ||
            sscanf( query_name(), "%*sdeath%*s") == 2 ||
            sscanf( query_name(), "%*sdragon%*s") == 2 ||
            sscanf( query_name(), "%*sfish%*s") == 2 ||
            sscanf( query_name(), "%*spimp%*s") == 2 ||
            sscanf( query_name(), "%*shell%*s") == 2 ||
            sscanf( query_name(), "%*smage%*s") == 2 ||
            sscanf( query_name(), "%*spink%*s") == 2 ||
            sscanf( query_name(), "%*slord%*s") == 2 ||
            sscanf( query_name(), "%*sevil%*s") == 2 ||
            sscanf( query_name(), "%*skiller%*s") == 2 ||
            sscanf( query_name(), "%*sslayer%*s") == 2 ) {
            write("Invalid name.  Please retry.\n");
            if( prompt ) {
                write(prompt);
                input_to("enter_name", 0, prompt, type, args );
            } else {
                next_menu( args );
            }
            return;
        }

        if( PLAYER_H->test_user( query_name() ) ||
            CLUB_HANDLER->is_family( query_name() ) ) {
            write("The name ["+query_name()+"] is already in use.\n"
                "Please choose another name.\n");
            if( prompt ) {
                write(prompt);
                input_to("enter_name", 0, prompt, type, args );
            } else {
                next_menu( args );
            }
            return;
        }

        if( type == GUEST ) {
            title = "the Guest of "+mud_name();
            add_property("guest", 1 );
            return logon3();
        }

        write("You have typed in the name ["+query_name()+"], is this "
            "correct? ");
        input_to("check_name_correct", 0, args );
        break;
      case DELETE :
      case CURRENT :
        if( unguarded( (: restore_object,
            query_delete_player_file_name( query_name() ), 1 :) ) ) {
            if( type == DELETE ) {
                write("\n\n\nYour character is already deleted.\n\n\n");
                if( prompt ) {
                    write(prompt);
                    input_to("enter_name", 0, prompt, type, args );
                } else {
                    next_menu( args );
                }
                return;
            }
        } else if( !unguarded( (: restore_object,
            query_player_file_name( query_name() ), 1 :) ) ) {
            write("The name ["+query_name()+"] is not in our annals, "
                "please try again.\n");
            if( prompt ) {
                write(prompt);
                input_to("enter_name", 0, prompt, type, args );
            } else {
                next_menu( args );
            }
            return;
        } else if( Str == -1 ) {
            type = NEW;
        }

        if( !password && type == DELETE ) {
            write("\nSorry, you cannot delete this character.\n"+
                  "Please see an admin if you have questions.\n\n");

            if( prompt ) {
                write(prompt);
                input_to("enter_name", 0, prompt, type, args );
            } else {
                next_menu( args );
            }
            return;
        }

        if( creator && type == DELETE ) {
            write("\nSorry, you cannot delete a creator character.\n"+
                  "Please ask an admin to demote you first.\n\n");
            if( prompt ) {
                write(prompt);
                input_to("enter_name", 0, prompt, type, args );
            } else {
                next_menu( args );
            }
            return;
        }

        if( BASTARDS_H->no_new_players( TO ) &&
            !query_property("authorised player") ) {
            string place, addr;
            // This is put in so it is possible to reactively allow people to
            // log in from a site, by deleting their last login address.
            if( !last_on_from )
                addr = query_ip_number(TO);
            else
                sscanf( last_on_from, "%s (%s)", place, addr );

            // If it is new player banned and we last logged on from here
            // (or another banned site -- this copes with dynamic ips :).
            // we are automatically authorised.
            // We also allow creators to log in from banned sites, and
            // players over 2 days old.
            if( !creator && time_on > -(2*24*60*60) &&
                BASTARDS_H->query_access( explode( addr, "."), "*") ==
                DEFAULT ) {
                write("This character is not authorised to play from here.\n");
                write("For more information please email "+ADMIN_EMAIL+".  "
                    "Don't forget to include your character's name!\n\n");
                user_event("inform", query_name()+" ("+addr+") tried to log "
                    "in from "+query_ip_number(TO), "cheat");
                log_file("CHEAT", "%s: %s (%s) tried to log in from %s\n",
                    ctime(time()), query_name(), addr, query_ip_number(TO) );
                return next_menu( args );
            } else {
                auto_authorise = 1;
            }
        }
            
        if( !password )
            return logon3();

        if( !creator && SHUTDOWN_H->query_shutdown() < 5 &&
            !find_player(query_name()) ) {
            write("\nSorry, you cannot log in during the shut-down sequence "
                "unless you are already logged in and want to reconnect.  "
                "Please try again in a few minutes.\n\n");
            logon_menu();
            return;
        }

        write("\n");
        if( type != DELETE )
            write( LOGIN_H->get_message("/doc/login/WELCOME") );
        write("Enter your password: ");
        input_to("logon2", 1, type, args );
        break;
      default :
        write("Break down in the system.\n");
        return dest_me();
    }

} /* enter_name() */

/** @ignore yes */
void check_name_correct( string str, mixed *args ) {
    if( strlen(str) < 1 || ( str[0] != 'y' && str[0] != 'Y') ) {
        if( str[0] == 'n' || str[0] == 'N')
            return next_menu( args );
        write("Please enter \"y\" or \"n\".\n"
            "You have typed in the name ["+query_name()+"], is this "
            "correct? ");
        input_to("check_name_correct", 0, args );
        return ;
    }

    write( LOGIN_H->get_message("/doc/login/NEW_USER_PASSWORD") );
    write("Okay, you have chosen the name ["+query_name()+"] for your time "
        "on "+mud_name()+".\n"
        "Have fun, and remember: don't explode.\n"
        "Enter password: ");

    add_property("new player", 1 );
    input_to("logon2", 1, GUEST, args );

} /* check_name_correct() */

/** @ignore yes */
int do_su( string str ) {
    object ob, tp;

    ob = TP;
    tp = TO;

    terminal_name = ob->query_cur_term();
    the_cols = ob->query_cols();
    the_rows = ob->query_rows();

    exec( tp, ob );
    ob->quit();

    login_choice(str);
    return 1;

} /* do_su() */

/** @ignore yes */
void retry_logon( int guest, mixed *args ) {
    write("Try again: ");
    input_to("logon2", 1, guest, args );
} /* retry_logon() */

/** @ignore yes */
void time_out() {
    if( !interactive( TO ) )
        return dest_me();

    // Time them out if they are not in the queue and either idle or
    // not idle but have been sitting around too long.
    if( ( query_idle(TO) > TIMEOUT_TIME ||
        ( time() > login_start_time + THROWOUT_TIME ) ) &&
        member_array( TO, LOGIN_H->query_login_queue() ) == -1 ) {
        write("Time out.\n\n");
        return dest_me();
    }

    call_out("time_out", TIMEOUT_TIME );

} /* time_out() */

/** @ignore yes */
protected void logon2( string str, int type, mixed *args ) {
    string mess;

    write("\n");

    if( !str || str == "") {
        password = 0;
        Dex = -1;
        Str = -1;
        return next_menu( args );
    }

    // Force a 6 character or greater password.
    if( Dex == -1 && !password && strlen(str) < 6 ) {
        write("Password is too short, must be at least 6 characters.\n");
        write("Enter password: ");
        input_to("logon2", 1, type, args );
        return;
    }

    str = crypt( str, password );

    // Password failure.
    if( password && str != password ) {
        // New char entering their password, don't count this as a failed
        // login, hence it's before the failed login stuff.
        if( Dex == -1 ) {
            Str = 13;
            write("The password didn't match up with first password.\n");
            write("Please enter the password again: ");
            input_to("logon2", 1, type, args );
            return;
        }

        // If they've gone over the max_retries record it as a failed login.
        if( ++no_times > MAX_RETRIES ) {
            // Record a failed login from this IP.
            LOGIN_H->failed_login( query_ip_number(TO) );

            write("Too many retries, please wait...\n");

            mess = CAP(query_name())+" failed to login, "+
                ( query_ip_name(TO) != query_ip_number(TO) ?
                  query_ip_name(TO) + " ("+query_ip_number(TO)+")" :
                  query_ip_number(TO) );

            event( users(), "inform", mess, "bad-password");
            log_file("BAD_PASSWORD", "%s: %s\n", ctime(time()), mess );
            no_times = 0;
            // Make this delay a bit.
            call_out( (: logon_menu :), 30 );
            return;
        }

        write("Wrong, please wait...\n");
        call_out( (: retry_logon :), 1, type, args );
        return;
    }

    password = str;

    if( Str == -1 ) {
        Str = 13;
        write("Please enter the password again: " );
        input_to("logon2", 1, type, args );
        return;
    }

    if( Dex == -1 )
        Dex = 13;

    // Check to see if we are reinstating a deleted character.
    if( type != DELETE ) {
        if( unguarded( (: file_size,
            query_delete_player_file_name(query_name())+".o" :) ) != -1 ) {
            if( !unguarded( (: rename,
                query_delete_player_file_name(query_name())+".o",
                query_player_file_name(query_name())+".o" :) ) ) {
                write("Reinstating deleted character!  Good to see you back "
                    "again.\n");
            } else {
                write("\n\n\nUnable to reinstate your character, please send "
                    "an email to "+ADMIN_EMAIL+" if you require further "
                    "assistance.\n\n\n");
                logon_menu();
                return;
            }
        }
        logon3();
    } else {
        delete_character();
    }

} /* logon2() */

/** @ignore yes */
protected void logon3() {
    cap_name = CAP( query_name() );
    logon4( !query_property("guest") );
} /* logon3() */

/** @ignore yes */
protected void get_sex( string str, int bing ) {
    switch( lower_case(str) ) {
      case "m" :
      case "male" :
        gender = 1;
      break;
      case "f" :
      case "female" :
        gender = 2;
      break;
      default :
        write("That's too weird even for this game!\n"
              "Try male or female: ");
        input_to("get_sex");
        return;
    }

    logon5(bing);

} /* get_sex() */

/** @ignore yes */
protected void logon4( int bing ) {
    if( gender == -1 ) {
        write("Would you like this character to be male or female? ");
        input_to("get_sex", bing );
        return;
    }

    logon5(bing);

} /* logon4() */

/** @ignore yes */
protected void check_terms( string str, int new_pl ) {
    write( LOGIN_H->get_message("/doc/login/WELCOME") );
    logon5(new_pl);
} /* check_terms() */

/** @ignore yes */
protected void logon5( int new_pl ) {
    object ob, tmp, *obs;

    if( query_name() != "root" && query_name() != "guest")
        other_copy = find_player(query_name());

    // This is the check for upgrade calls.
    if( other_copy == TP )
        return begin(new_pl);

    // Check to see if they are in the login queue already.
    if( member_array( query_name(), map( LOGIN_H->query_login_queue(),
        (: $1->query_name() :) ) ) != -1 ) {
        write("You are already in the login queue.\n");

        obs = filter( LOGIN_H->query_login_queue(),
            (: $1->query_name() == $2 :), query_name() );
        other_copy = obs[0];

        if( other_copy && other_copy->query_login_ob() ) {
            // They are already in the login queue.
            write("Reconnecting to you in the login queue.\n");
            if( interactive(other_copy) ) {
                tell_object( other_copy, "Disconnected by someone from "+
                    query_ip_name(TO)+".\n");
                ob = clone_object(OBJECT_OBJ);
                tmp = other_copy;
                exec( ob, other_copy );
                ob->dest_me();
            }
            tmp = other_copy;
            ob = TO;
            exec( other_copy, ob );
            return;
        } else {
            dest_me();
        }
        return;
    }

    // Check to see if mud is full and then shove them into the queue.
    if( LOGIN_H->is_discworld_full(WITHOUT_LOGINS_NOT_IN_QUEUE) ||
        sizeof( LOGIN_HANDLER->query_login_queue() ) ) {
        // Always allow creators and test characters.
        if( !creator && !query_property("test character") ) {
            write("Sorry, there are no player slots available.\n\n");
            LOGIN_H->add_to_login_queue(TO);
            login_num = sizeof( LOGIN_H->query_login_queue() );
            if( other_copy ) {
                // Hack!  Hack!  Warning!  No idea why reconnection to net
                // deads is not working.  So force them to quit instead.
                other_copy->quit();
                write("You were net dead when you left, shuffling you to the "
                    "start of the queue...\n");
                net_dead = 1;
            } else {
                write("Placing you in the login queue: you have position "+
                    login_num+".\nPlease wait.  Type \"quit\" to escape.\n");
            }
            remove_call_out("time_out");
            call_out("check_status", 30, new_pl );
            input_to("idle_loop", 0, new_pl );
            return;
        }
    }

    if( other_copy ) {
        try_throw_out(new_pl);
        return;
    }

    begin(new_pl);

} /* logon5() */

/*
 * This is the idle loop stuff.  It checks to see if the people want to
 * leave the queue nicely.  Not absolutely nessessary I guess.
 */
/** @ignore yes */
void idle_loop( string str, int new_pl ) {
    if( can_login == 2 )
        try_throw_out(new_pl);
    else if( can_login == 3 )
        begin(new_pl);
    else if( strlen(str) && lower_case(str)[0] == 'q')
        dest_me();
    else
        input_to("idle_loop", 0, new_pl );
} /* idle_loop() */

/*
 * This is called from the login_handler when we are ready to leave the
 * login queue.
 */
/** @ignore yes */
void remove_from_login_queue() {
    object other_copy;

    can_login = 1;
    other_copy = find_player(query_name());
    if( other_copy ) {
        can_login = 2;
    } else {
        can_login = 3;
        tell_object( TO, "\n\n\n\nYou have exited the login queue!  "
            "Please press return to continue: ");
        call_out("time_out", TIMEOUT_TIME );
    }

    // Just in case.
    LOGIN_H->remove_from_login_queue(TO);

} /* remove_from_login_queue() */

/*
 * This is the call out done now and then.  It prints the cute messages.
 */
/** @ignore yes */
void check_status(int new_pl) {
    int tmp_num;
    object other_copy;

    if( !can_login ) {
        tmp_num = member_array( TO, LOGIN_H->query_login_queue() ) + 1;
        if( tmp_num == 0 ) {
            // Oh dear, we got deleted. Put ourselves back in.
            LOGIN_H->add_to_login_queue(TO);
            tmp_num = member_array( TO, LOGIN_H->query_login_queue() ) + 1;
        }

        if( tmp_num > 0 && tmp_num != login_num && !other_copy ) {
            if( !net_dead )
                write("You now have position "+tmp_num+" in the queue.\n");
        }

        login_num = tmp_num;
        write( choice( ({
            "Yawn...",
            "This queue is boring.",
            "I wonder how much longer?",
            "I wish this would end soon.",
            }) )+"\n");

        call_out("check_status", 30, new_pl );
    }

} /* check_status() */

/** @ignore yes */
protected void try_throw_out( int new_pl ) {
    object tmp, ob;

    if( !other_copy ) {
        write("Oh dear.  Your other copy has been eaten.  "
            "Logging in normally.\n");
        begin(new_pl);
        return ;
    }

    if( interactive(other_copy) ) {
        ob = clone_object(OBJECT_OBJ);
        tmp = other_copy;
        exec( ob, other_copy );
        ob->dest_me();
    }

    tmp = other_copy;
    ob = TO;
    exec( other_copy, ob );

#ifdef LOOKUP_IDENT
    other_copy->set_my_ident(my_ident);
#endif

    // Force a look.
    other_copy->look_me();

    LOGIN_H->player_reconnected( other_copy->query_name() );

    event( ENV(other_copy), "see", other_copy->query_cap_name()+" has "
        "reconnected.\n", other_copy, ({ other_copy }) );

    if( function_exists("inform_reconnect_game", other_copy ) )
        other_copy->inform_reconnect_game();

#ifdef LOOKUP_IDENT
    if( got_return )
        return dest_me();
    ident_player_ob = other_copy;
#else
    dest_me();
#endif

} /* try_throw_out() */

/** @ignore yes */
protected void begin( int new_pl ) {
    player_ob = BASTARDS_H->query_player_ob( query_name(), 1 );

    if( !player_ob ) {
        logon_menu();
        return ;
    }

    begin2( new_pl );

} /* begin() */

/** @ignore yes */
protected void begin2( int new_player ) {
    object tp;

    // Clone the player object.
    if( catch( new_copy = clone_object(player_ob) ) ) {
        write("Oh no, someone has broken the player object!  "+
            "Come back later.\n");
        return dest_me();
    }

    if( !new_copy ) {
        write("Argh!  Something bad happened.\n");
        return dest_me();
    }

    new_copy->set_name( query_name() );
    new_copy->set_password( password );

    tp = TO;
    exec( new_copy, tp );

    if( tp != TO )
        tp->quit();

    if( query_property("guest") ) {
        new_copy->add_property("guest", 1 );
        new_copy->set_title(title);
    }

#ifdef LOOKUP_IDENT
    new_copy->move_player_to_start( query_name(),
        query_property("new player"), cap_name, my_ident, go_invis );
#else
    new_copy->move_player_to_start( query_name(),
        query_property("new player"), cap_name, 0, go_invis );
#endif

    new_copy->set_gender(gender);

    if( new_player )
        new_copy->add_skill_level("general.language.common", 100 );

    // Wheee.
    if( terminal_name )
        new_copy->terminal_type( terminal_name );

    if( the_cols && the_rows )
        new_copy->window_size( the_cols, the_rows );

    if( auto_authorise )
        new_copy->add_property("authorised player",
            query_ip_number( new_copy ) );

    if( query_ip_number(new_copy) == query_ip_name(new_copy) )
        resolve( query_ip_number(new_copy), "query_level");

#ifdef LOOKUP_IDENT
    if( got_return )
        return dest_me();
    ident_player_ob = new_copy;
#endif

    dest_me();

} /* begin2() */

/** @ignore yes */
int query_level() { return 1; }

/** @ignore yes */
int query_gender() { return gender; }

private void do_special_add_property( string fname, string prop, mixed val ) {
    string frog, *bits;
    mapping glue;
    int i, len;

    frog = read_file(fname);

    if( !frog ) {
#ifdef DEBUG
        log_file("LOGIN_ERROR", ctime(time())+ ": Could not read file "+
            fname+" .\n");
#endif
        return;
    }

    bits = explode( frog, "\n");
    len = strlen( prop_var_name ) - 1;

    for( i = 0; i < sizeof(bits); i++ ) {
        if( bits[i][0..len] == prop_var_name ) {
            glue = restore_variable( bits[i][len + 1..] );
            glue[prop] = val;
            bits[i] = prop_var_name + save_variable(glue);
            break;
        }
    }

    reset_eval_cost();

    // We really do not want to break in here...
    if( !write_file( fname, implode( bits, "\n"), 1 ) )
        error( sprintf("Failed to write to %s (prop: %s)\n", fname, prop ) );

    write_file( fname, "\n");

} /* do_special_add_property() */

/**
 * This method allows you to add properties onto players who are not
 * currently logged on.
 * @param pname name of player to change
 * @param prop the property to change
 * @param val the new value for it
 * @return 1 upon success, 0 upon failure
 */
int special_add_property( string pname, string prop, mixed val ) {
    object ob;
    string tmp_name;

    if( !stringp(prop) || !stringp(pname) )
        return 0;

    if( !PLAYER_H->test_user(pname) )
        return 0;

    if( ob = find_player(pname) ) {
        ob->add_property( prop, val );
    } else {
        tmp_name = query_player_file_name(pname)+".o";
        unguarded( (: do_special_add_property( $(tmp_name), $(prop),
            $(val) ) :) );
        PLAYER_H->special_add_property( pname, prop, val );
    }

    return 1;

} /* special_add_property() */

/**
 * @ignore yes
 * This function is called by the upgrade object.
 */
void new_player( object old ) {
    object new_pl;
    string name, ob_name;
#ifdef LOOKUP_IDENT
    string ident;

    ident = query_ident(old);
#endif

    name = old->query_name();
    cap_name = old->query_cap_name();
    creator = creatorp(old);
    terminal_name = old->query_cur_term();
    the_cols = old->query_cols();
    the_rows = old->query_rows();
    exec( TO, old );
    creator = creatorp(old);
    old->quit();
    creator = creatorp(TP);
    ob_name = BASTARDS_H->query_player_ob( name, 1 );

    if( !ob_name ) {
        logon_menu();
        return ;
    } else {
        new_pl = clone_object(ob_name);
    }

    exec( new_pl, TO );
    new_pl->terminal_type( terminal_name );
    new_pl->window_size( the_cols, the_rows );
#ifdef LOOKUP_IDENT
    new_pl->move_player_to_start( name, 0, cap_name, ident );
#else
    new_pl->move_player_to_start( name, 0, cap_name );
#endif

    dest_me();

} /* new_player() */

/** @ignore yes */
int query_prevent_shadow() { return 1; }

/**
 * @ignore yes
 * Needed so the object actually writes things to the screen.  Mildly
 * embarrassing otherwise.
 */
void do_efun_write( string str ) {
    efun::tell_object( TO, sprintf("%-=*s", cols, strip_colours( str ) ) );
} /* do_efun_write() */

/** @ignore yes */
string query_object_type() { return "X"; }

/** @ignore yes */
string query_gender_string() { return "blue"; }

#ifdef LOOKUP_IDENT
/** @ignore yes */
void finished_auth( string m_i ) {
    got_return = 1;
    my_ident = m_i;
    if( ident_player_ob ) {
#ifdef DEBUG
        TCRE("shaydz", "Found ident of "+m_i+" (player_ob) "+name+"\n");
#endif
        ident_player_ob->set_my_ident(m_i);
        dest_me();
    } else
#ifdef DEBUG
        TCRE("shaydz", "Found ident "+m_i+" "+name+"\n");
#endif
} /* found_ident() */
#endif

/** @ignore yes */
void terminal_type( string type ) { terminal_name = type; }

/** @ignore yes */
void window_size( int width, int height ) {
    the_cols = width;
    the_rows = height;
} /* window_size() */

/** @ignore yes */
int query_invis() { return 1; }

/** @ignore yes */
void net_dead() {
    LOGIN_H->remove_from_login_queue(TO);
    dest_me();
} /* net_dead() */

/** @ignore yes */
void dest_me() {
    LOGIN_H->remove_from_login_queue(TO);
    ::dest_me();
} /* dest_me() */

/**
 * This method determines if the object is a login object.
 * @return always returns 1
 */
int query_login_ob() { return 1; }

/**
 * This method tells us if the object is net dead.
 * @return 1 if they are net dead, 0 if they are not
 */
int query_net_dead() { return net_dead; }

/**
 * This method returns the path to the player file.
 * This is the player files actual normal location, it was written to
 * allow moving the player files aruond easier.
 * @param name the name of hte player whose file to find
 * @see test_user()
 * @see query_delete_player_file_name()
 */
string query_player_file_name( string name ) {
    return PLAYER_SAVE_DIR+name[0..0]+"/"+name;
} /* query_player_file_name() */

/**
 * This method returns the path to the deleted player file.
 * This is the deleted player files actual normal location, it was written to
 * allow moving the player files aruond easier.
 * @param name the name of the player whose file to find
 * @see test_user()
 * @see query_delete_player_file_name()
 */
string query_delete_player_file_name( string name ) {
    return PLAYER_SAVE_DIR+DELETE_DIR+"/"+name;
} /* query_player_file_name() */

/** @ignore yes */
string *parse_command_adjectiv_id_list() {
    return object::parse_command_adjectiv_id_list();
} /* parse_command_adjectiv_id_list() */

/** @ignore yes */
string *parse_command_plural_id_list() {
    return object::parse_command_plural_id_list();
} /* parse_command_plural_id_list() */

/** @ignore yes */
string *parse_command_id_list() {
    return object::parse_command_id_list();
} /* parse_command_id_list() */

/*
 * GRRR, THESE FUNCTIONS SHOULD BE GOTTEN RID OF.
 * BUT ONLY AFTER MAKING SURE THE LIB ISN'T USING ANY. :/
 * - SANDOZ
 */
/** @ignore yes */
int test_user(string str) { return PLAYER_H->test_user(str); }

/** @ignore yes */
int test_gender(string str) { return PLAYER_H->test_gender(str); }

/** @ignore yes */
int test_active(string str) { return PLAYER_H->test_active(str); }

/** @ignore yes */
int test_level(string str) { return PLAYER_H->test_level(str); }

/** @ignore yes */
int test_banished(string str) { return PLAYER_H->test_banished(str); }

/** @ignore yes */
string test_real_name( string str ) {
    return PLAYER_H->test_real_name(str);
} /* test_real_name() */

/** @ignore yes */
string test_email( string str ) { return PLAYER_H->test_email(str); }

/** @ignore yes */
mixed test_property(string word, string str) {
    return PLAYER_H->test_property(word, str);
} /* test_property() */

/** @ignore yes */
string test_deity(string str) { return PLAYER_H->test_deity(str); }

/** @ignore yes */
int test_age(string str) { return PLAYER_H->test_age(str); }

/** @ignore yes */
int test_last(string str) { return PLAYER_H->test_last(str); }

/** @ignore yes */
int test_start_time(string str) {
    return PLAYER_H->test_start_time(str);
} /* test_start_time() */

/** @ignore yes */
string test_family(string str) { return PLAYER_H->test_family(str); }

/** @ignore yes */
int test_password( string name, string pass ) {
    return PLAYER_H->test_password( name, pass );
} /* test_password() */

/** @ignore yes */
string query_signature(string str) {
    return PLAYER_H->query_signature(str);
} /* query_signature() */
