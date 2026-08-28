int
main (string str)
{
  int i;
  object o;

  if (!str)
    {
      notify_fail ("Drink what?\n");
      return 0;
    }

  if (ENV(THIS)->query_water() && (str == "water" || str == "river"))
    {
      THIS->hydrate_me (1000);     
      emote ("$n {drink} from "+lower_case(ENV(THIS)->query_short())+".",
        THIS, 0, ENV(THIS));

      return 1;
    }

  o = present (str);

  if (!o)
    {
      write ("There is no "+str+" nearby.\n");
      return 1;
    }

  if (!o->is_liquid())
    {
      write ("You can't drink from "+o->query_maybe_cap_name()+"!\n");
      return 1;
    }

  if (o->query_liters() < 1)
    {
      write (o->query_cap_name()+" is empty!\n");
      return 1;
    }

  THIS->hydrate_me (1000);
  o->add_liters (-1);

  emote ("$n {drink} from "+o->query_maybe_cap_name()+".", THIS, 0, ENV(THIS));
  return 1;
}

query_author ()
{
  return "namhas";
}

query_help ()
{
  return "Using this command you can drink when you get thristy. You can also drink from rivers.";
}

query_synopsis ()
{
  return "drink <item>";
}
