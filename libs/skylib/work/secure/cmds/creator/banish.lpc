
inherit COMMAND_BASE;
/*
 * Banish code removed from the patricians office by Pinkfish.
 */

int cmd(string str)
{
  string str1, temp1, ban;

  if (this_player()->GetForced())
    return 0;
  notify_fail("Syntax : banish <name> <reason>\n");
  if (!str)
    return 0;
  if (sscanf(str, "%s %s", str, str1) != 2)
    return 0;
  str = lower_case(str);
  if (sscanf(str,"%s.",temp1))
    return 0;
  if (sscanf(str, "%s/", temp1))
    return 0;
  if (file_size("/banish/"+str[0..0]+"/"+str+".o") >= 0)
  {
    notify_fail("That name is already banished.\n");
    return 0;
  }
  if ("secure/login"->test_user(str))
  {
    notify_fail("That is a player.  You must rm or mv the player file first.\n");
    return 0;
  }
  ban = "Banished by : "+(string)this_player()->query_name()+"\n";
  ban += ctime(time())+"\n";
  ban += "Banish Reason : " + str1 + "\n";
  unguarded((: write_file, "/banish/"+str[0..0]+"/"+str+".o", ban :));
  write(str + " banished.\n");
  return 1;
} /* cmd() */

string *query_patterns() {
  return ({ "", (: cmd(0) :), "<string>", (: cmd($4[0]) :) });
} /* query_patterns() */
