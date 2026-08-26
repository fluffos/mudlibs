//  File    :  /cmds/xtra/_dest.c
//  Creator :  Huthar/Wayfarer@Portals
//  Updated :  Watcher@TMI (02/19/93) to search with get_object()
//             and an optional object wipe before destruction
//          :  Bonzo (270593) to use query_mdest()
//          :  Robocoder@TMI-2 (94.08.14) to provide global destruction
//
//  This is the wizard destruct command.

#include <mudlib.h>

inherit DAEMON;

#define SYNTAX "Syntax: dest [-ag] [object|pattern]\n"

#define GUEST_NO_DEST 1

nosave int cnt;

int strncmp(string str, string sub, int i) {
    int j;

    j = strlen(str);
    if (i > j)
        return strcmp(str, sub);
    else
        return strcmp(str[0..i-1], sub);
}

int dest_all(object act_ob, int silent) {
    int s;
    object *ob;

    ob = deep_inventory(act_ob);
    s = sizeof(ob);
    cnt += s;
    while (s--) {
        if (!ob[s])  continue;

        if (!silent)
            write("Desting: " + identify(ob[s]) + "\n");

        if (!(ob[s]->is_player() && interactive(ob[s]))) {
            catch(ob[s]->remove());
            if(ob[s])  destruct(ob[s]);
        }
    }
    return 1 ;
}

int cmd_dest(string str) {
    object ob, act_ob, *obs;
    string msg, opt;
    int clean, global, l, s;

    act_ob = previous_object();
seteuid(geteuid(act_ob));

    notify_fail( SYNTAX );
    if (!str || str == "")  return 0;

#ifdef GUEST_NO_DEST
    if (getuid(previous_object()) == "guest") {
        write ("Guest is not permitted to dest objects.\n") ;
        return 1 ;
    }
#endif

    if (str == "all")
        return dest_all(act_ob, 0);

    if (sscanf(str, "-%s %s", opt, str) == 2) {
        if (strsrch(opt, 'a') != -1)  clean = 1;
        if (strsrch(opt, 'g') != -1)  global = 1;
    }

    if (global) {
        if (!adminp(geteuid(act_ob))) {
            write("Global Dest: Permission denied.\n");
            return 1;
        }

        str = resolv_path("cwd", str);
        l = strlen(str);
        obs = objects();
        s = sizeof(obs);

        write("Global destructing: " + str + "\n");

        cnt = 0;
        while (s--) {
            if (!obs[s])  continue;
            if (strncmp(file_name(obs[s]), str, l) == 0) {
                if (clean)
                    dest_all(obs[s], 1);
                cnt++;
                if (obs[s]) {
                    catch(obs[s]->remove());
                    destruct(obs[s]);
                }
            }
        }

        write("object(s) destructed: " + cnt + "\n");
    } else {
        if (!(ob = get_object(str))) {
            write("Dest: Could not locate that object.\n");
            return 1;
        }

        if (interactive(ob) && !adminp(geteuid(act_ob))) {
            write("Dest: Permission denied.\n");
            return 1;
        }
        if (clean)  dest_all(ob, 1);

        write("Destructing: " + identify(ob) + "\n");
        msg = (string)act_ob->query_mdest(ob);

        if (environment(ob) == this_player() ||
              environment(ob) == environment(this_player()))
            say( capitalize(msg) + "\n");

        catch(ob->remove());
        if (ob)  destruct(ob);
    }

    return 1;
}

int help() {
    write( SYNTAX + "\n" +
        "This command will search for the inputed object, and remove it\n" +
        "from existence.  Only admin may remove interactive objects.  If\n" +
        "the -a flag is used, it will clean the object's inventory first.\n" +
        "If the -g flag is used, the specified pattern is used to destroy\n" +
        "objects with matching file names.  (Use with caution!)\n");

    return 1;
}
