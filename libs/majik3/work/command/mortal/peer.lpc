int main (string str)
{
  string *dest_dir, *dest;
  int i, true;

  if (!str)
    {
      notify_fail ("usage: peer <direction>\n"); 
      return 0;
    }

  dest_dir = ENV(THIS)->query_exit_dir();
  dest     = ENV(THIS)->query_exit_dest();

  for(i=0;i<sizeof(dest_dir);i++)
    {
      if (dest_dir[i] == str) {
        if (ENV(THIS)->query_no_wrap() == 0)
         {
        message ("misc", "You peer " + dest_dir[i] + ":\n" +
        sprintf("%-=*s", 78, dest[i]->query_long()+"\n"), THIS);
         }
        else
         {
        message ("misc", "You peer " + dest_dir[i] + ":\n" +
        dest[i]->query_long(), THIS);
         }
        message ("environent", capitalize(THIS->query_name()) + " peers "+dest_dir[i]+".\n",
          ENV(THIS), THIS);
        true = 1;
      }
    }

  if (!true)
    {
      write ("You don't see anything special.\n");
    }

return 1;
}

query_author()
{
  return "namhas";
}

query_help()
{
  return "Peer is used when you want to have a peek into another"
  + " room adjacent to your current location. The normal conditions"
  + " on visibility apply.";
}

query_synopsis()
{
  return "peer <direction>";
}

query_see_also()
{
  return "look(1), blook(1)";
}

query_position ()
{
  return POS_STANDING;
}

