int
cmd_resume()
{
     object me;
     me = this_player();

     if(!me->query_do_cmds())
       return (write("You do command queue is empty.\n"), 1);
     if(!me->query_do_pause())
       return (write("Your do command queue isn't paused.\n"), 1);

     me->set_do_pause(0);
      return (write("Ok.  Resumed.\n"), 1);
}
