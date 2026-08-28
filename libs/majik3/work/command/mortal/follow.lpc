int
main (string str)
{
  object o;

  if (!str)
    {
      if (THIS->query_leader())
        {
          write ("You stop following "+capitalize(THIS->query_leader())+".\n");
          THIS->set_leader(0);
          return 1;
        }
      else
        {
          write ("You are not following anyone.\n");
          return 1;
        }
    }

  str = lower_case(str);

  o = present (str);

  if (!o)
    {
      write ("There is no "+capitalize(str)+" nearby.\n");
      return 1;
    }

  if (!living(o))
    {
      write (o->query_cap_name()+" is not a living being.\n");
      return 1;
    }

  if (o==THIS)
    {
      write ("You can't follow yourself!\n");
      return 1;
    }

  if (o->query_friends() && member_array(THIS->query_name(), o->query_friends()) == -1)
    {
      write (o->query_cap_name()+" doesn't want to lead you.\n");
      tell_object (o, THIS->query_cap_name()+" tried to follow you.\n");
      return 1;
    }

  tell_object (o, THIS->query_cap_name()+" is now following you.\n");
  write ("You are now following "+o->query_cap_name()+".\n");
  THIS->set_leader (o->query_name());

  return 1;
}

query_author ()
{
  return "namhas";
}

query_synopsis ()
{
  return "follow [player]";
}

query_help ()
{
  return "Using this command you can follow your friends. You can stop following by typing follow with no argument.";
}

query_see_also ()
{
  return "friend(1), friends(1)";
}

query_position ()
{
  return POS_STANDING;
}

