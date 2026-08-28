int
main (string str)
{
  string *friends;
  object o;

  if (!str)
    {
      notify_fail ("Usage: friend <name>\n");
      return 0;
    }

  str = lower_case(str);

  friends = THIS->query_friends();

  if (friends && member_array(str, friends) > -1)
    {
      THIS->remove_friend(str);
      write (capitalize(str) + " is no longer your friend.\n");
      return 1;
    }

  o = present(str);

  if (!o)
    {
      write ("There is no "+capitalize(str)+" nearby.\n");
      return 1;
    }

  if (o==THIS)
    {
      write ("Conceited fool!\n");
      return 1;
    }

  write (o->query_cap_name() + " is now your friend.\n");
  tell_object (o, THIS->query_cap_name() + " considers you as a friend.\n");
  THIS->add_friend (o->query_name());

  return 1;
}

query_author ()
{
  return "namhas";
}

query_synopsis ()
{
  return "friend <player>";
}

query_help ()
{
  return "You can consider someone as friend using friend command "
       + "and if you use friend command again to the same player "
       + "then you will not consider he/she as your friend anymore.";
}

query_see_also ()
{
  return "friends(1), follow(1)";
}

query_position ()
{
  return POS_RESTING;
}

