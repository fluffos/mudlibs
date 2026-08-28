int main (string str)
{
  string kannu, uuso;
  string *last;
  object user;

  if (!str || sscanf(str, "%s %s", uuso, kannu) != 2)
    {
      notify_fail ("usage: wizlast <user> <channel>\n");
      return 0;
    }

  if (user = find_player(uuso))
    {
      last = user->query_last(kannu);

      for(int i=0;i<sizeof(last);i++)
        message ("wizlast", last[i]+"\n", THIS);
    }
  else
    {
      write ("Failed.\n");
    }

  return 1;
}

