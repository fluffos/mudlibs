int
main (string str)
{
  object *friends;

  friends = THIS->query_friends();

  if (!friends)
    {
      write ("You have no friends.\n");
    }
  else
    {
      if (sizeof(friends) == 1)
        write ("You have 1 friend:\n");
      else
        write ("You have "+sizeof(friends)+" friends:\n");

      for (int i=0;i<sizeof(friends);i++)
        {
          write (sprintf ("%2d. %-16s\n", i+1, friends[i]));
        }
    }

  return 1;
}

query_author ()
{
  return "namhas";
}

query_help ()
{
  return "This command will list your friends, if you have friends. Your friends have access to follow you.";
}

query_see_also ()
{
  return "friend(1), follow(1)";
}

query_position ()
{
  return POS_SLEEPING;
}

