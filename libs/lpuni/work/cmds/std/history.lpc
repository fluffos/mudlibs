/* history.c

 Tacitus @ LPUniversity
 12-AUG-06
 Command history command

*/

int main(string args)
{
    int range, i;
    string *history = ({});

    history = this_player()->query_commandHistory();

    if(stringp(args))
    {

        if(args == "all")
        {
            for(i = 0; i < sizeof(history); i++)
                printf(" %-5d %-5s %s\n", i, ":",  history[i]);
        }

        else
        {
            range = to_int(args);

            if(!intp(range) || range < 0) return notify_fail("Error [history]: Invalud argument type.\n");
            else
            {

                for(i = sizeof(history) - (range + 1); i < sizeof(history); i++)
                    printf(" %-5d %-5s %s\n", i, ":",  history[i]);
            }
        }
    }

    else
    {
        for(sizeof(history) > 16 ? i = sizeof(history) - 16 : i = 0; i < sizeof(history); i++)
            printf(" %-5d %-5s %s\n", i, ":",  history[i]);
    }

    return 1;

}

string help()
{
    return(" %^BOLD%^SYNTAX:%^RESET%^ history [range]\n\n"
    "This command allows you to view the history of commands that\n"
    "you've executed. By default is displays the last 15 commands\n"
    "executed by you but you may provide a custom ammount by providing\n"
    "an argument of 'all' to view the entire history or a number of your\n"
    "choice.\n");
}