/* force.c

 Tacitus @ LPUniversity
 05-JULY-06
 Admin force command

*/

/* Last edited by Tacitus on October 6th, 2006 */

#include <logs.h>

int main(string args)
{
    string target, cmd;

    if(!adminp(previous_object())) 
        return notify_fail("Error [force]: Access denied.\n");

    if(!stringp(args) || sscanf(args, "%s %s", target, cmd) != 2)
        return(notify_fail("Error [force]: Syntax force <user> <cmd>\n"));

    target = lower_case(target);

    if(target == "all")
    {
        foreach(object ob in users())
        {
            if(adminp(ob)) continue;

            write("Success [force]: You force '" + capitalize(ob->query_name())
                + "' to "    + cmd + "\n");
            tell_object(ob, capitalize(this_player()->query_name())
                + " forces you to " + cmd + "\n");

            ob->force_me(cmd);
            log_file(LOG_FORCE, capitalize(query_privs(this_player())) + 
                " forces " + ob->query_cap_name() + " to '" + cmd + "' on " 
                + ctime(time()) + "\n");
        }
        

        return 1;
    }

    else
    {
        object ob;

        ob = find_player(target);

        if(!objectp(ob)) return notify_fail("Error [force]: User "
            + capitalize(target) + " not found.\n");
        if(adminp(ob))
            return notify_fail("Error [force]: You may not force an admin.\n");

        write("Success [force]: You force '" + capitalize(target ) + "' to "
            + cmd + "\n");
        tell_object(ob, capitalize(this_player()->query_name())
            + " forces you to " + cmd + "\n");

        ob->force_me(cmd);
        log_file(LOG_FORCE, capitalize(query_privs(this_player())) + 
                " forces " + ob->query_cap_name() + " to '" + cmd + "' on " 
                + ctime(time()) + "\n");
        return 1;
    }
}

string help()
{
    string ret = "%^BOLD%^ SYNTAX:%^RESET%^ force <living> <cmd>\n\n"
    "This command allows you to force a living object to execute\n"
    "a command as if they had typed it themself. This means that\n"
    "the command must be in their path or added by an add_action.\n"
    "Normal developers may not force interactive objects (ie.\n"
    "users).\n";

    if(adminp(this_player())) ret +=
    "\nAdmins: There exists a seperate command to force interactives\n"
    "in the admin command directory. The mud will automatically use\n"
    "that command if you try to force an interactive - nothing special\n"
    "is required on your part for this to occur.\n";

    return ret;
}
