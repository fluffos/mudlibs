/* force.c

 Tacitus @ LPUniversity
 05-JULY-06
 Developer Force Command

*/

int main(string args)
{
    string target, cmd;
    object ob;

    if(!stringp(args) || sscanf(args, "%s %s", target, cmd) != 2)
        return(notify_fail("Syntax Error [force]: force <livining> <cmd>\n"));
    if(!environment(this_player())) return 0;

    target = lower_case(target);
    ob = present(target, environment(this_player()));

    if(!objectp(ob)) return notify_fail("Error [force]: " + target + " not found.\n");
    if(!living(ob)) return notify_fail("Error [force]: That object is not living.\n");
    if(adminp(this_player()) && interactive(ob)) return 0;
    else if(interactive(ob)) return notify_fail("Error [force]: You may not force them.\n");

    write("You force " + capitalize(target ) + " to: " + cmd + "\n");
    ob->force_me(cmd);
    return 1;
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
    "\n%^RED%^Admins:%^RESET%^ There exists a seperate command to force interactives\n"
    "in the admin command directory. The mud will automatically use\n"
    "that command if you try to force an interactive - nothing special\n"
    "is required on your part for this to occur.\n";

    return ret;
}