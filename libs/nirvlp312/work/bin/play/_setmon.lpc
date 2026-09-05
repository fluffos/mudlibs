status
cmd_setmon(string str)
{
  string monitor_string;
    if(!str)
    {
      if(!(monitor_string=(string)this_player()->query_monitor_string()))
      {
         notify_fail("\
You don't have a monitor string currently set.\n");
        return 0;
      }
      
      write("\
Your current monitor string is:\n"+monitor_string + ".\n");
      return 1;
    }
    write("Your monitor string is now: " + 
    (monitor_string = str) + ".\n");
    this_player()->set_monitor_string(monitor_string);
    this_player()->print_monitor();
    return 1;
}
