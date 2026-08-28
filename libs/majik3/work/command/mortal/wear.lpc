int
main (string str)
{
  object o;

  if (!str)
    {
      notify_fail ("Usage: wear <armour>\n");
      return 0;
    }

  o = present (str, THIS);

  if (!o)
    {
      write ("You don't have "+str+".\n");
      return 1;
    }

  if (!o->is_armour())
    {
      write (o->query_cap_name()+" is not a armour.\n");
      return 1;
    }

  if (THIS->add_armour (o))
    {
      write ("You wear "+o->query_maybe_cap_name()+".\n");
      act (THIS, "$n wears "+o->query_maybe_cap_name()+".");
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
  return "This is used when you want to wear an armour. It tries to wear <item>"
  + " after checking if there are enough slots free";
}

query_see_also()
{
  return "remove(1), wield(1), slots(1)";
}

query_synopsis()
{
  return "wear <item>";
}

query_example()
{
  return "wear breastplate";
}
query_position()
{
  return POS_STANDING;
}

