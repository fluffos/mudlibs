int
main (string str)
{
  object o;

  if (!str)
    {
      notify_fail ("Usage: wield <weapon>\n");
      return 0;
    }

  o = present (str, THIS);

  if (!o)
    {
      write ("You don't have "+str+".\n");
      return 1;
    }

  if (!o->is_weapon())
    {
      write (o->query_cap_name()+" is not a weapon.\n");
      return 1;
    }

  if (THIS->add_weapon (o))
    {
      write ("You wield "+o->query_maybe_cap_name()+".\n");
      act (THIS, "$n wields "+o->query_maybe_cap_name()+".");
      return 1;
    }       

  return 1;
}

query_author()
{
  return"namhas";
}

query_help()
{
  return "You wield a weapon with this command, ie you check if you can use."
  + " one more weapon and start using it if possible.";
}

query_see_also()
{
  return "remove(1), wear(1)";
}

query_synopsis()
{
  return "wield <item>";
}

query_example()
{
  return "wield dagger";
}
query_position()
{
  return POS_STANDING;
}

