// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** quests.c
**
** Show you all the quests on the mud.
**
** Created 24-NOV-95, Rust
*/

inherit CMD; 

nomask private void main()
{
  outf("%s目前有以下的 quest ：\n", mud_name());
  out(implode(QUEST_D->get_goals_for_quests_cmd(),"\n"));
  out("\n\n用 help <quest name> 来获取 quest 的详细内容。\n");

}
