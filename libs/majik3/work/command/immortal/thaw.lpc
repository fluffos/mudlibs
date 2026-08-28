int
main (string str)
{
  object ob;

  if (!str)
    {
      write ("Usage: thaw <player>\n");
      return 1;
    }

  ob = find_player (str);

  if (ob && ob != THIS)
    {
      tell_object (ob, "A fireball suddenly explodes in front of you, melting the ice!\n");
      write ("You thaw "+ob->query_cap_name()+".\n");
      ob->set("frozen", 0);
    }
  else
    write ("Failed.\n");

  return 1;
}
