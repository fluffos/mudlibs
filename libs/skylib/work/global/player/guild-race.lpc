/**
 * This file contains all the information relating to races
 * that is stored on the player.
 *
 * @author Pinkfish
 */

#include <player.h>
#include <command.h>

string race_ob, *known_commands;

nosave string _race;

/**
 * This method returns the title associated with this player.
 * @return the title
 */
string query_gtitle() {
    return TITLE_H->query_title(TO);
} /* query_gtitle() */

/**
 * This method sets the players current race.  This should never be
 * used, all players should be set by the login object.
 * the set functions should not be called indisciminately...
 * becareful when using them that you dont screw up a character ok?
 * @param str the players new race
 * @see query_race_ob()
 */
void set_race_ob( string str ) {
    string frog;

    if( sscanf( str, "/%s", frog ) == 1 )
        str = extract( str, 1 );

    if( str[0..strlen("std/races")-1] != "std/races" ) {
        write("Illegal path to set_race_ob.\n");
        return;
    }

    race_ob = str;

} /* set_race_ob() */

/**
 * This method returns ther current race object associated with the
 * player.
 * @return the race object
 * @see set_race_ob()
 */
string query_race_ob() { return race_ob; }

/**
 * This method returns the name of the race associated with the
 * player.
 * @return the race name
 * @see query_race_ob()
 * @see set_race_ob()
 */
string query_race() {
    if( !_race )
        _race = race_ob->query_name();
    return _race;
} /* query_race() */

/**
 * This method adds all the guild-race commands to the player
 * when they start up.
 * @see add_known_command()
 */
void race_guild_commands() {
    string command, *bing, *paths;

    paths= ({ });

    if( !known_commands )
        known_commands = ({"rearrange"});

    foreach( command in known_commands ) {
        // Totally remove commands that do not exist or are
        // not guild-race commands.
        if( !CMD_D->IsGRCommand(command) ||
            !sizeof( bing = CMD_D->GetPaths(command) ) ) {
            known_commands -= ({ command });
            continue;
        }
        // Remove any paths that aren't /cmds/guild-race.
        paths += filter( bing, (: $1[0..15] == "/cmds/guild-race" :) );
    }

    TO->AddSearchPath(paths);
    catch( query_race_ob()->start_player(TO) );
    TO->query_limbs();

} /* race_guild_commands() */

/**
 * This method returns the array of commands the player knows.
 * @return the list of commands the player knows
 * @see add_known_command()
 * @see query_known_command()
 * @see remove_known_command()
 */
string *query_known_commands() { return copy(known_commands); }

/**
 * This method checks to see if the command is known by the player.
 * @param word the command to check
 * @return 1 if known, 0 if not
 * @see add_known_command()
 * @see query_known_commands()
 * @see remove_known_command()
 */
int query_known_command( string word ) {
    return ( member_array( word, known_commands ) != -1 );
} /* query_known_command() */

/**
 * This method handles help calls associated with commands on the
 * player.  This will either return a string or a function pointer.
 * @return the help for the command
 * @param str the command to get help on
 * @see add_known_command()
 */
string help_command( string str ) {
    class command cmd = new( class command, verb : str );
    string path;
    mixed func;

    if( query_known_command(str) || creatorp(TO) &&
        CMD_D->HandleStars(cmd) ) {
        path = CMD_D->GetPaths(cmd->verb)[0]+"/"+cmd->verb;
        func = path->help_function();
        if( func )
            return func;
        return path->help();
    }

    return 0;

} /* help_command() */

/**
 * This method adds a command to the player.
 * @param str the command to add
 * @return 1 if was successfuly added, 0 if not
 * @see query_known_commands()
 * @see query_known_command()
 * @see remove_known_command()
 */
int add_known_command( string str ) {
    string *paths;

    if( query_known_command( str ) || !CMD_D->IsGRCommand(str) )
        return 0;

    if( sizeof( paths = CMD_D->GetPaths(str) ) )
        TO->AddSearchPath(paths);

    known_commands += ({ str });
    return 1;

} /* add_known_command() */

/**
 * This method removes a command from the player.
 * @param str the command to remove
 * @return 1 if it was successful, 0 if it was unsuccessful
 * @see add_known_command()
 * @see query_known_command()
 * @see query_known_commands()
 */
int remove_known_command( string str ) {
    if( !query_known_command( str ) )
        return 0;

    known_commands -= ({ str });
    return 1;

} /* remove_known_command() */
