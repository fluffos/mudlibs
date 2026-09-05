nomask mixed cmd_shutdown(string str)
{
  int time_shut;

  if((int)this_player()->query_level() < 1000)
    return 0;
  if(!str) str = "5";
  else if(lower_case(str) == "now")
  return shutdown();
  else if(sscanf(str, "%d", time_shut) != 1)
  {
    write("Not a valid time.\n");
    return 1;
  }

  shout("!Game is being shut down by "+(string)this_player()->query_name()+" in "+
         str+" minutes.\n");
  write("Game will shut down in "+time_shut+" minutes.\n");
 
  log_file("SHUTDOWN",
    "Game is being shut down by " + (string)this_player()->query_name()+
    " in "+str+" minutes.\n");
 
  "/obj/shut"->shut(time_shut);
  return 1;
}
