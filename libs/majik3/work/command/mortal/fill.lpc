int
main (string str)
{
  int i;
  string s1, s2;
  object o1, o2;

  if (!str)
    {
      notify_fail ("Fill what from what?\n");
      return 0;
    }

  if (sscanf(str, "%s from %s", s1, s2) != 2)
    {
      notify_fail ("Fill container from what?\n");
      return 0;
    }

  o1 = present (s1);

  if (!o1)
    {
      write ("There is no "+s1+" nearby.\n");
      return 1;
    }

  if (ENV(THIS)->query_water() && (s2 == "water" || s2 == "river" || s2 == "lake"))
    {
      emote ("$n {fill} "+o1->query_maybe_cap_name()+" from "+
        lower_case(ENV(THIS)->query_short())+".", THIS, 0, ENV(THIS));

      o1->add_liters (o1->query_max_liters());
      return 1;
    }

  o2 = present (s2);

  if (!o2)
    {
      write ("There is no "+s2+" nearby.\n");
      return 1;
    }

  if (!o1->is_liquid())
    {
      write ("You can't fill "+o1->query_maybe_cap_name()+"!\n");
      return 1;
    }

  if (!o2->is_liquid())
    {
      write ("You can't fill from "+o2->query_maybe_cap_name()+"!\n");
      return 1;
    }

  if (o2->query_liters() < 1)
    {
      write (o2->query_cap_name()+" is empty!\n");
      return 1;
    }

  o1->add_liters (o1->query_max_liters());
  o2->add_liters (-o1->query_max_liters());

  emote ("$n {fill} "+o1->query_maybe_cap_name()+" from "+o2->query_maybe_cap_name()+".", THIS, 0, ENV(THIS));
  return 1;
}

query_author ()
{
  return "namhas";
}

query_help ()
{
  return "Using this command you can fill a liquid container.";
}

query_synopsis ()
{
  return "fill <item1> from <item2>";
}
