/* finger.c

 Tacitus @ LPUniversity
 26-MAR-06
 Std Command
*/

int main(string user)
{
    string who, where;

    if(!user) return(notify_fail("Syntax: finger <user>\n"));

    if(sscanf(user, "%s@%s", who, where) == 2)
    FINGER_D->finger_user(who, where);
    else
    write(FINGER_D->finger_user(user));

    return 1;
}

string help()
{
    string ret =
    " %^BOLD%^SYNTAX:%^RESET%^ finger <user>\n\n"
    "This command will display information regarding an\n"
    "existing user such as their e-mail address, last login\n"
    "rank, plan, etc. This command will be able to retrieve\n"
    "the information even if they are offline.\n";
    if(devp(this_player())) ret += "\n %^BOLD%^See also:%^RESET%^ profile\n";

    return ret;
}


