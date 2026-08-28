int
main (string str)
{
  object ob;

  if (!str)
    {
      write ("Usage: freeze <player>\n");
      return 1;
    }

  ob = find_player (str);
if (ob->query_security())
{
  write("Can't freeze wizards!\n");
  return 1;
}

  if (ob && ob != THIS)
    {
      tell_object (ob, "A bitter wind suddenly rises and drains every erg of heat from your body!\n");
      write ("You freeze "+ob->query_cap_name()+".\n");
      ob->set("frozen", 1);
    }
  else
    write ("Failed.\n");

  return 1;
}
