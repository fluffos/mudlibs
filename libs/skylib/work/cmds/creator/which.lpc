
#include <command.h>
#include <user_parser.h>

inherit COMMAND_BASE;

/** @ignore yes */
int cmd( string str ) {
    mixed coms;
    class command cmd;
    string *files;

    files = ({ });

    cmd = new( class command, verb : str );
    if( CMD_D->HandleStars(cmd) &&
        sizeof( ( coms = CMD_D->GetPaths(cmd->verb) & TP->GetSearchPath() ) ) )
        files += map( coms, (: $1 + "/" + $(cmd->verb) :) );

    if( ( coms = TP->query_parse_command(str) ) )
        files += map(coms, (: base_name($1[OBJS]) :));

    if( ( coms = SOUL_H->query_soul_command(str) ) )
        files += ({ SOUL_H });

    if( !sizeof(files) )
        return notify_fail("Command " + str + " not found.\n");

    printf("List of files defining '%s', in search order:\n%s",
        str, implode( files, (: $1 + "    " + $2 + "\n" :), "") );
    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
  return ({ "<word'command'>", (: cmd($4[0]) :) });
} /* query_patterns() */
