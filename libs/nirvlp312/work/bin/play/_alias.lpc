#define MAX_ALIASES 50

int
cmd_alias(string arg)
{
     int         sa, sb;
     string      cmd;
     string      arg1, arg2, curr_alias;
     object      me;


     if(!arg)
       return (command("aliases", this_player()), 1);
     if(sscanf(arg, "%s %s", arg1, arg2) < 2)
     {
       command("unalias " + arg, this_player());
       return 1;
     }
     
    me = this_player();
    cmd = arg2;

    if(cmd == "n" || cmd == "north" || cmd == "s" || cmd == "south" ||
       cmd == "e" || cmd == "east"  || cmd == "w" || cmd == "west"  ||
       cmd == "sw"|| cmd == "southwest" || cmd == "se" || cmd == "southeast" ||
       cmd == "nw"|| cmd == "northwest" || cmd == "n" || cmd == "northeast" ||
       cmd == "d" || cmd == "down" || cmd == "u" || cmd == "up")
      return (write("Directional commands NOT ALLOWED.\n"), 1);

     if(arg1 == "alias" || arg1 == "unalias")
       return (write("That's probably not a good idea.\n"), 1);
      
     if(me->query_alias_definition(arg2))
       return (write("You already have " + arg2 + " defined as an alias.\n"), 1);


     sa = strlen(arg1)-1;
     sb = strlen(arg2)-1;

     if(arg1[sa..sa]=="\\" || arg2[sb..sb] == "\\")
      return (write("Due to a weird driver bug, aliases may not have\n" +
                    "a backslash [\\] at the end of either the alias\n" +
                    "or definition.  Sorry for any problems this may\n"+
                    "cause you.\n"), 1);
     if(curr_alias = (string)me->query_alias_definition(arg1))
       write("Ok. Changed " + arg1 + " from " + curr_alias + " to " + arg2 + ".\n");

     else
     {
       if((int)me->query_total_aliaii() == MAX_ALIASES)
         return (write("Sorry, but each player " +
                 "is only allowed " + MAX_ALIASES + " aliases!\n"), 1);
       write("Ok. Defined " + arg1 + " as " + arg2 + ".\n");
     }
     this_player()->chg_alias(arg1, arg2);
     return 1;
}
