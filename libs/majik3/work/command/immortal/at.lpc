int
main (string str)
{
  object env, ob;
  string who, something;

  if (!str)
    {
      notify_fail ("Usage: at <who> <something>\n");
      return 0;
    }

  if(sscanf(str, "%s %s", who, something) != 2)
    {
       notify_fail ("Usage: at <who> <something>\n");
      return 0;
    }

  ob = find_living(lower_case(who));

  if (!ob)
    {
      write ("no such idiot available.\n");
      return 1;
    }

  env = ENV(THIS);
  THIS->move(ENV(ob));
  THIS->force_us(something);
  THIS->move(env);
   write ("Done.\n");
  return 1;
}
