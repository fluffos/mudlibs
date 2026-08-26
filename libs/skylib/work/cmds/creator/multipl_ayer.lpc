/**
 * multiplayer command to add/delete names to the list
 * of checked players
 */

#include <creator.h>

inherit COMMAND_BASE;

varargs int cmd( string command, string name, string what, string extra ) {
    if(name)
       name = lower_case(name);

    if( !PLAYER_H->test_user( name ) ) {
        write( name+" is not a player.\n");
        return 1;
    }

    switch( command ) {
      case "add" :
        if( extra && !PLAYER_H->test_user( extra = lower_case(extra) ) ) {
            write( extra+" is not a player.\n");
            return 1;
        }
        if( !call_other( MULTIPLAYER_H, "add_" + what, name, extra ) )
            printf("\"%s\" isn't known here.\n", name );
        else
            printf("\"%s\" added.\n", name );
      break;
      case "del" :
        if( !call_other( MULTIPLAYER_H, "delete_" + what, name ) )
            printf("\"%s\" isn't on the list.\n", name );
        else
            printf("\"%s\" deleted.\n", name );
      break;
      case "log" :
        MULTIPLAYER_H->mark_log( name, extra );
        printf("Marked \"multiplay\" playerinfo events "
            "for \"%s\" as \"%s\".\n", name, ( extra ? extra : "handled") );
      break;
      case "list" :
        write("The list currently consists of: $I$5=\n"+
            query_multiple_short( sort_array( call_other( MULTIPLAYER_H,
            "query_" + what ), (: strcmp( $1, $2 ) :) ) )+"$I$0=\n");
      break;
    }

    return 1;

} /* cmd */

/** @ignore yes */
mixed *query_patterns() {
    return ({
        "{gits|list gits}",  (: cmd("list", 0, "gits") :),
        "{allow|list allow}", (: cmd("list", 0, "allowed") :),
        "add git <word'name'>", (: cmd("add", $4[0], "git") :),
        "add allowed <word'name'> <word'other name'>",
        (: cmd("add", $4[0], "allowed", $4[1]) :),
        "del git <word'name'>", (: cmd("del", $4[0], "git") :),
        "del allowed <word'name'>", (: cmd("del", $4[0], "allowed") :),
        "log <word'name'>", (: cmd("log", $4[0], "git") :),
        "log <word'name'> <string'log text'>",
        (: cmd("log", $4[0], "git", implode($4[1..], " ")) :)
    });
} /* query_patterns() */
