int cmd_xprate(string str)
{
  int x;
  int t;
  t = time() - (int)this_player()->query_time_login();
  x = (int)this_player()->query_exp_login();
  t /= 60;
  if(!t) t = 1;
  x /= t;
  write("\nCurrent XP rate:\n");
  write("\t\t"+x+"/min\n");
  write("\n");
  return 1;
}
