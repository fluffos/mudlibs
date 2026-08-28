int
main (string str)
{
  object o;

  if (!str)
    {
      notify_fail ("To whom do you wish to introduce yourself?\n");
      return 0;
    }

  o = present(lower_case(str));

  if (!o)
    {
      write ("There is no "+str+" nearby.\n");
      return 1;
    }

  if (!living(o))
    {
      write (capitalize(str) + " not a living being.\n");
      return 1;
    }

  if (o->query_npc())
    {
      write (capitalize(str) + " ignores you.\n");
      return 1;
    }

  if (THIS->test_known(o))
    {
      write ("You already have introduced yourself to "+o->query_objective()+".\n");
      return 1;
    }

  if (o && o == THIS)
    {
      write ("You know yourself already.\n");
      return 1;
    }

  write ("You introduce yourself to "+o->query_objective()+".\n");
  THIS->add_known (o->query_name());
  tell_object (o, THIS->query_cap_name() + " introduces "+o->query_objective()+"self to you.\n");
  act(THIS, "$n introduces "+o->query_objective()+"self to $v.", o, o);

  return 1;
}

query_author ()
{
  return "namhas";
}

query_synopsis ()
{
  return "introduce <player>";
}

query_help ()
{
  return "If you want specified player to know who are you, then "
       + "introduce yourself to him/her.";
}

query_position ()
{
  return POS_RESTING;
}

