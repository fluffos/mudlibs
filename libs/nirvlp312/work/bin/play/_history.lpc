int
cmd_history(string arg)
{
     int    s, history_ticker;
    int i;
     string *my_history;
     object me;


     me = this_player();

     my_history =     (string *)me->query_action_history();
     history_ticker = (int)me->query_action_ticker();

     if(!my_history || !history_ticker || !(s = sizeof(my_history)))
       return (write("No History\n"), 1);

     write("\n");
     for(i=0;i<s;i++)
       write(my_history[i] + "\n");

     write("\n");
     return 1;
}
