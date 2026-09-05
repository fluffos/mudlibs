
int
cmd_unalias(string arg)
{
     object      me;


     if(!arg)
       return (write("Syntax: 'unalias <alias>'\n"), 1);
     
     me = this_player();
     if(!me->query_alias_definition(arg))
       return (write("You aren't using " + arg + " as an alias.\n"), 1);
     write("Ok. Deleted " + arg + " as an alias.\n");
     me->delete_alias(arg);
     return 1;
}
