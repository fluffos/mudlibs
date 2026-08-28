main (string str)
{
  object ob;
  int itime;
  string ftime="";

  if (!str)
    {
      write ("usage: idle <player>\n");
      return 1;
    }

  if (ob = find_player (lower_case(str)))
    {
      itime=query_idle(ob);
      if (itime >= 60*60) {
        ftime+="^c1"+itime/(60*60)+"^c0h ";
        itime-=(itime/(60*60))*60*60;
      }
      if (itime >= 60) {
        ftime+="^c1"+itime/60+"^c0m ";
        itime-=(itime/60)*60;
      }
      ftime+="^c1"+itime+"^c0s";

      message("normal", capitalize (ob->query_name()) + " has been idle for ^c1" + ftime + ".\n", THIS);
      return 1;
    }
  else
    {
      write ("No such living thing.\n");
      return 1;
    }
}

query_author ()
{
  return "namhas";
}

query_synopsis ()
{
  return "idle <player>";
}

query_help ()
{
  return "This command will display the amount of time specified player "
       + "has been idle.";
}

query_see_also ()
{
  return "who(1), wizlist(1), age(1)";
}
