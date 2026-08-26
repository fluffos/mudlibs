/**
 * A command which shows what commands the player has.
 * Added 'commands playtester' which shows the commands
 * currently in playtesting - Sandoz, 13th September 2001.
 */
#include <command.h>
inherit COMMAND_BASE;

int cmd( int pt ) {
    string *cmds;
    int i;

    if( pt && playtesterp(TP) ) {
        if( !sizeof( cmds = CMD_D->GetCommands( DIR_PLAYTESTER_CMDS ) ) ) {
            add_failed_mess("There are no commands currently in "
                "playtesting.\n");
            return 0;
        }
        for( i = 0; i < sizeof(cmds); i++ )
          cmds[i] = replace( cmds[i], ({ "_", "" }) );

        write( "The commands currently in playtesting are:\n"+
               sprintf( "%-#*s\n", (int)TP->query_cols(),
               implode( sort_array( cmds, 1 ), "\n" ) ) );
        return 1;
    }
    
    write( "Your current commands are:\n"+ sprintf( "%-#*s\n",
         (int)TP->query_cols(), implode( sort_array(
         (string *)TP->query_known_commands(), 1 ), "\n" ) ) );
    if(playtesterp(TP)){
        if( !sizeof( cmds = CMD_D->GetCommands( DIR_PLAYTESTER_CMDS )-({"report"}) ) ) {
            write("None of these are currently in "
                "playtesting.\n");
            return 1;
        }
        for( i = 0; i < sizeof(cmds); i++ )
          cmds[i] = replace( cmds[i], ({ "_", "" }) );

        write( "\nThe commands currently in playtesting are:\n"+
               sprintf( "%-#*s\n", (int)TP->query_cols(),
               implode( sort_array( cmds, 1 ), "\n" ) ) );

    }
    return 1;
} /* cmd() */

mixed *query_patterns() {
  mixed pat = ({ "", (: cmd(0) :) });
  if( !playtesterp(TP) )
      return pat;
  else
      return pat + ({ "playtester", (: cmd(1) :) });
} /* query_patterns() */