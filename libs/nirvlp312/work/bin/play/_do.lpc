int
cmd_do(string arg)
{
     object me;

     me = this_player();
     if(!arg)
     {
       if(!me->query_do_cmds())
         return (write("You don't have any do commands to pause.\n" +
                       "Syntax: 'do <cmd1, cmd2, cmd3, cmd4, etc.>',\n" +
                       "or simply 'do' to pause your command queue.\n"), 1);
       if(!me->query_do_pause())
       {
         me->set_do_pause(1);
         return (write("Ok. 'do' commands paused.\n"), 1);
       }
       return (write("Your do command queue is already paused.\n"+
                     "Type 'resume' to resume your queue.\n"), 1);
     }

     if((status)me->query_do_pause())
       write("Ok. Resumed.\n");

     if(stringp((string)me->query_do_cmds()))
       write("Skipping commands...\n");

     this_player()->set_do_cmds(arg);   

     write("Ok.\n");
     return 1;
}
