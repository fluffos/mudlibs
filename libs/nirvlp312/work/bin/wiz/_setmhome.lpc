int cmd_setmhome(string str)
{
 if(!str) return 0;
 if ((int)this_player()->query_level() < 20)
  return 0;
 this_player()->set_msghome(str);
 command("save silent", this_player());
 return 1;
}
