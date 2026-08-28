int
main (string str)
{
  object ob;

  if (!str)
    ob = ENV(THIS);
  else
    ob = (find_player(str) || find_living(str) || present(str, ENV(THIS)) || present(str, THIS) || find_object(str));

  if (ob)
    message("0", "The creator for \""+(string) ob->query_short()+"\" is "+(string) capitalize((string) author_file(file_name(ob)))+".\n", THIS);
  else
    write ("No such object found.\n");

  return 1;
}

query_author ()
{
  return "namhas";
}

query_help ()
{
  return "This command will tell you who created the environment you "
       + "are currently in.";
}

query_see_also ()
{
  return "wizlist(1), bug(1)";
}

query_position ()
{
  return POS_RESTING;
}

