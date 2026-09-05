/* add this somewhere before the init() function in your wiztool */
int set_gname(string arg) {

  string who;
  mixed what;
  object ob;

  if (!arg) {
    notify_fail("Syntax: set_gname <who> <new guild name>\nOr:      set_gname <your new guild name>\n");
    return 0;
  }

  if (sscanf(arg,"%s %s", who, what) == 2) {
    ob = find_player(who);
    if (!ob) {
      notify_fail(who+" not found.\n");
      return 0;
    }
  }
  else  {
    ob = this_player();
    what = arg;
  }

  if (what == "none" || what == "None")
    what = 0;

  ob->set_guild_name(what);
  write("Player '"+capitalize((string)ob->query_real_name())+"'s guild name set to: "+what+".\n");
  return 1;
}

/* add, in init() in your wiztool the following line:
   add_action("set_gname","set_gname");
   and you should be all set
*/
