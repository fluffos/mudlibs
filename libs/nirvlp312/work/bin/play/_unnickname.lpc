
int
cmd_unnickname(string arg)
{
     object      me;


     if(!arg)
       return (write("Syntax: 'unnickname <nickname>'\n"), 1);
     
     me = this_player();
     if(!me->query_nick_definition(arg))
       return (write("You aren't using " + arg + " as a nickname.\n"), 1);
     write("Ok. Deleted " + arg + " as a nickname.\n");
     me->delete_nickname(arg);
     return 1;
}
