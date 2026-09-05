int cmd_logins(string arg) 
{
  int i, siz;
  string *info;

  if ((string)this_player()->query_real_name() == "hercules")
  {
    notify_fail("You hath annoyed the Earwax over this, therefore you do without.\n");
    return 0;
  }

  write("Most recent logins: \n");
  siz = sizeof(info = (string *)"/daemons/logins"->query_logins());

  if (!siz)
  {
    write("No login information at this time.\n");
    return 1;
  }

  for (i = 0; i < siz; i++)
    write(info[i]);

  return 1;
}
