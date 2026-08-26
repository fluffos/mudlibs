// File: callouts.c
//   Dumps info on the status of callouts in the mud; aka Call_Out Debugger
//
// Creator: Archimedes@TMI-2
//   Mobydick got sick of seeing them lying around so made it into an
//   autoloading object :)  7-1-93, aka Arawn 1 185.
//
// Revision:
//   07-03-93 - adapted /obj/tools/cod.c into a wiz command

#include <config.h>
#include <mudlib.h>

inherit DAEMON;

int cmd_callouts(string arg) {
    int i, s;
    string *stuff, ob;
    mixed *info;

    info = call_out_info();
    s = sizeof(info);
    i = s;
    stuff = ({ });

    if (arg == "-v") {
        stuff += ({ sprintf("%-35s%-20s%-10s%-15s",
              "Object", "Function", "Delay", "Arguments") });
        stuff += ({ "------------------------------------------------------------------------------" });

        while (i--) {
            catch(ob = file_name(info[i][0]));
            stuff += ({ sprintf("%-35s%-20s%5d     ", ob, info[i][1], info[i][2])
                  + dump_variable(info[i][3]) });
        }
    } else {
        stuff += ({ sprintf("%-35s%-20s%-10s",
              "Object", "Function", "Delay") });
        stuff += ({ "------------------------------------------------------------------------------" });

        while (i--) {
            catch(ob = file_name(info[i][0]));
            stuff += ({ sprintf("%-35s%-20s%5d", ob, info[i][1], info[i][2]) });
        }
    }

    stuff += ({ "------------------------------------------------------------------------------" });
    stuff += ({ sprintf("\t\t\tTotal call_outs: %d\n", s) });

    this_player()->more(stuff, 1);

    return 1;
}

int help() {
    write( @ENDHELP
Syntax: callouts [-v]

This command prints out the number of pending call_out()'s in the system,
listing the object, the function names, and the remaining delay.
If the '-v' option is specified, an even more verbose listing of each call
out is produced, dumping the arguments to be passed to the function.
ENDHELP
    );
    return 1;
}
