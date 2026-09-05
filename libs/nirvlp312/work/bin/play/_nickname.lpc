#define MAX_NICKS 50

int
cmd_nickname(string arg)
{
     int         sa, sb;
     string      arg1, arg2, curr_nick;
     object      me;


     if(!arg)
       return (command("nicknames", this_player()), 1);
     if(sscanf(arg, "%s %s", arg1, arg2) < 2)
       return (command("unnickname " + arg, this_player()), 1);

     
     me = this_player();
     if(me->query_nick_definition(arg2))
       return (write("You already have " + arg2 + " defined as a nickname.\n"), 1);
     sa = strlen(arg1)-1;
     sb = strlen(arg2)-1;

     if(arg1[sa..sa]=="\\" || arg2[sb..sb] == "\\")
      return (write("Due to a weird driver bug, nicknames may not have\n" +
                    "a backslash [\\] at the end of either the nickname\n" +
                    "or definition.  Sorry for any problems this may\n"+
                    "cause you.\n"), 1);
     if(curr_nick = (string)me->query_nick_definition(arg1))
       write("Ok. Changed " + arg1 + " from " + curr_nick + " to " + arg2 + ".\n");
     else
     {
       if((int)me->query_total_nicks() == MAX_NICKS)
         return (write("Sorry, but each player " +
                 "is only allowed " + MAX_NICKS + " nicknames!\n"), 1);
       write("Ok. Defined " + arg1 + " as " + arg2 + ".\n");
     }
     this_player()->chg_nickname(arg1, arg2);
     return 1;
}
