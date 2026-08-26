/*
//      File    :   /cmds/xtra/_path.c
//      Creator :   The Folks at Portals, of course
//
//      The command is used to set your command path
//      Updated for protected path checks and path portion
//      removal by Watcher (01/93)
// 93-08-29 : Robocoder added directory existance checking
*/

#include <uid.h>
#include <mudlib.h>

inherit DAEMON ;

#define PROTECT ({ "/cmds/std", "/cmds/wiz" })

int cmd_path(string str) {
    object act_ob;
    string *path, *curpath;
    int i, s, m, add_path, rem_path;

    act_ob = previous_object();
    seteuid(ROOT_UID);

    if (!str) {
        str = (string)act_ob->query("PATH");
        if (!str) {
            notify_fail("No path set.\n");
            return 0;
        }
        notify_fail("Current path: "+str+"\n");
        return 0;
    }

    if (sscanf(str, "-add %s", str) || sscanf(str, "%s add", str)
          || sscanf(str, "%s ADD", str))
        add_path = 1;

    else if (sscanf(str, "-rem %s", str) || sscanf(str, "-remove %s", str)
          || sscanf(str, "%s rem", str) || sscanf(str, "%s remove", str)
          || sscanf(str, "%s REM", str) || sscanf(str, "%s REMOVE", str))
        rem_path = 1;

    // else set path

    curpath = explode((string)act_ob->query("PATH"), ":");
    path = explode(str, ":");

    // consistency checks
    if (add_path || rem_path) {
        s = sizeof(curpath);
        for (i = 0; i < s; i++) {
            if (file_size(curpath[i]) != -2) {
                write("The "+curpath[i]+" directory no longer exists.\n");
                curpath -= ({ curpath[i] });
                i--; s--;
            }
        }
    } else {
        s = sizeof(PROTECT);
        for (i = 0; i < s; i++) {
            if (member_array(PROTECT[i], path) == -1) {
                write("Path set aborted: You cannot exclude " + PROTECT[i] +
                      "from your path.\n");
                return 1;
            }
        }
    }

    s = sizeof(path);
    for (i = 0; i < s; i++) {
        path[i] = resolv_path("cwd", path[i]);
        if (file_size(path[i]) != -2) {
            if (!rem_path)
                write("The "+path[i]+" directory does not exist.\n");
            path -= ({ path[i] });
            i--; s--;
        } else if (add_path && member_array(path[i], curpath) != -1) {
            write("The "+path[i]+" directory is already in your path.\n");
            path -= ({ path[i] });
            i--; s--;
        } else if (rem_path) {
            if (member_array(path[i], curpath)==-1) {
                write("The "+path[i]+" directory does not exist in your path.\n");
                path -= ({ path[i] });
                i--; s--;
            } else if ((m = member_array(path[i], PROTECT))==-1) {
                // it does, so remove that path portion from user's path
                curpath -= ({ path[i] });
            } else {
                // tried to remove a protected directory
                write("Path change aborted: You cannot exclude " + PROTECT[m] +
                      " from your path.\n");
                return 1;
            }
        }
    }

    // save any changes from consistency checking
    if (add_path || rem_path)
        act_ob->set("PATH", implode(curpath, ":"));
    else
        act_ob->set("PATH", implode(path, ":"));

    if (add_path && sizeof(path))
        act_ob->add("PATH", ":" + implode(path, ":"));

    write("Path now set to:\n   "+act_ob->query("PATH")+"\n");
    return 1;
}

int help() {
    write(
        "Usage:\t\tpath\n\t\tpath <new path>\n\t\tpath -add <directory>\n" +
        "\t\tpath -remove <specific path portion>\n\n" +
        "When no argument is given, this will print your current search\n" +
        "path for commands.  When the -add flag is used, it will add the\n" +
        "directory specified to your path.  When the -rem or -remove flag\n" +
        "is used, it will remove that specified segment from your path.\n" +
        "When you wish to set your entire path, the new path is given in\n" +
        "the form dirA:dirB:dirC, for example:\n" +
        "\tpath /cmds/std:/cmds/xtra:/u/b/buddha/bin\n" +
        "will set your path to those three directories.\n" +
        "\nSee also: rehash\n"
    );
    return 1;
}
