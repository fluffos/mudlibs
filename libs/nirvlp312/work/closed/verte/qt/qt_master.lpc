#define perc "%"

int cmd_percperc(string x)
{
  int size, num;
  object myself;
  string cmd;

  if(!(myself=this_player()))
    return 0;

  if(!x)
  {
    write("Repeating last command.\n");
    size=((int)myself->query_action_ticker()-1);
    if(size > 29) size = 29;

    cmd=(string)myself->query_action_history_position(size);
    sscanf(cmd, "%d: %s", num, cmd);
    caller()->set_qt_status(1);
    command(cmd, myself);
     caller()->set_qt_status(0);
    return (write("Done.\n"), 1);
  }

  else
  {
    write("Executing ");
    size=((int)myself->query_action_ticker()-1);
    if(size > 29) size=29;
    cmd=(string)myself->query_action_history_position(size);
    sscanf(cmd, "%d: %s", num, cmd);
    write(cmd + " " + x + ".\n");
    caller()->set_qt_status(1);
    command(cmd + " " + x, myself);
    caller()->set_qt_status(0);
    return (write("Done.\n"), 1);
  }
}

int cmd_perc(string x)
{
  object myself;
  string cmd;
  int    num;

  if(!(myself=this_player()))
    return 0;
  if(!x || !sscanf(x, "%d", num))
    return (write("Usage: '%<#>' where <#> is the numbered command you want\n" +
                  "executed in your history.  See \"history\" for details.\n"), 1);
  else
  {
    string *hist;
    int i,y;
    hist=(string*)myself->query_action_history();
    if(!hist) hist=({});
    y=sizeof(hist);
    for(i=0;i<y;i++)
    {
      if(sscanf(hist[i], num+": %s", cmd))
      {
        write("Repeating command #" + num + "...\n");
        caller()->set_qt_status(1);
        command(cmd, this_player());
        caller()->set_qt_status(0);
        return (write("Done.\n"), 1);
      }
    }
    write("Invalid number.  You may only pick one of the\n"+
          "numbers listed in \"history\".\n");
    return 1;
  }
}
