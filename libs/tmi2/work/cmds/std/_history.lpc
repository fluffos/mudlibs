//  File    :  /cmds/std/_history.c
//  Creator :  Probably Wayfarer
//
//  This command displays the list of the user's past commands
//  stored in the history stack.

#include <mudlib.h>
inherit DAEMON;

#define log( x ) log_file( "hist_err",wrap( x ) )

string help();

string *helptext;

void create() {
    ::create();
    helptext = ({
"\n",
"History",
"-------",
"Command line history very similar to such Un*x shells as csh.",
"There are several types of history access and these are listed below:",
"",
"  !<command number>\t   : This will do the command <command number>.",
"  !<string pattern>\t   : This will match the most recent command which",
"\t\t\t     starts with <string pattern>.",
"  !!\t\t\t   : This will repeat the last command.",
"  !!<args>\t\t   : This will append <args> to the last command,",
"\t\t\t     and execute it.",
"  ^^<args>\t\t   : This will prepend <args> to the last command,",
"\t\t\t     and execute it.",
"  ^<pattern 1>^<pattern 2> : This will substitute <pattern 1> in the last",
"\t\t\t     command with <pattern 2>, and execute it.",
"",
"EXAMPLES:",
"(Sample history list. Typing 'history' will show you your list!)",
"   7 grovel",
"   8 kill orc",
"   9 knock on east door",
"  10 bounce",
"  11 look",
"",
"!7\t  - will cause you to \"grovel\"",
"!-2\t  - will cause you to \"bounce\"",
"!k\t  - will cause you to \"knock on east door\"",
"!ki\t  - will cause you to \"kill orc\"",
"!!\t  - will cause you to \"look\"",
"!! board  - will cause you to \"look board\"",
"^^help    - will cause you to \"help look\" (note the space in \"^^help \")",
"^ook^s    - will cause you to \"ls\""
    });
}

int cmd_history(string str) {
    int i, tptr;
    int max, cmd_num, ptr;
    string *history_queue;
    object act_ob;

   if( adminp(geteuid( previous_object() )) &&
        str && sscanf( str, "-u %s", str ) ) {
        act_ob = find_player(str);
        if (!act_ob) {
            write("History: user not found.\n");
            return 1;
        }
    } else {
        act_ob = previous_object();
    }

    if ((int)act_ob->query_npc())
        return 0; 

    max = (int)act_ob->query_max();
    cmd_num = (int)act_ob->query_cmd_num();
    ptr = (int)act_ob->query_ptr();
    history_queue = (string *)act_ob->query_history();

    if (!history_queue || !pointerp(history_queue)) {
        write("History seems to be broken. Please inform an Admin.\n");
        return 1;
    }

    tptr = ptr;

    for (i = max - 1; i >= 0; i--) {
        if (history_queue[tptr])
            printf("%4d %s\n", cmd_num - i, history_queue[tptr]);
        tptr++;
        if (tptr == max)
            tptr = 0;
    }
    return 1;
}

string help() {
    string tmp;
    if (adminp(geteuid(this_player()))) {
	tmp = "Syntax: history [-u user]\n"+implode(helptext, "\n");
    } else {
	tmp = "Syntax: history\n"+implode(helptext, "\n");
    return tmp;
    }
}
