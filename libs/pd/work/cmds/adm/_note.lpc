//      /bin/user/_mudidea.c
//      from the Nightmare mudlib
//      created by Descartes of Borg 20 october 1992
// Pallando (93-05-26) Changed environment(this_object()) to use this_player()
// a dungeonware.net production change 20-Dec-00
#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_note(string text);
void help();


int
cmd_note(string text)
{
    string file;

        if( !text )
        {
                help();
                return 1;
        }
        file = file_name(environment(this_player()));
        seteuid(UID_LOG);
        log_file("+capitalize( (string)this_player()->query_name())+ notes", ""+ctime(time())+"\n");
        log_file("+capitalize( (string)this_player()->query_name())+ notes", file+": "+text+"\n");
        seteuid(getuid());
        write("Now noted.\n");
        return 1;
}

void help() {
        write(
      "Syntax: <note [message]>\n\n"
      "Logs an note for an imm to read later.\n"
    );
}
