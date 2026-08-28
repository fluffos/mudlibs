/****
****    Command                                 use
***     Descriptions                            uses skills
**      Coder                                   Dragoness
*/



int main(string args)
{

    if (!args)
    {
	notify_fail("Usage: use '<skill>' [target]\n");
	return 0;
    }
    this_player()->cmd_skill_use(args);

    return 1;
}

query_author()
{
  return"dragoness";
}

query_help()
{
  return "You have to use your skills somehow and this is how you do it."
  + " You give the skill name as <skill> and possible target.";
}

query_see_also()
{
  return "skills(1)";
}

query_synopsis()
{
  return "use <skill> [target]";
}
query_position()
{
  return POS_STANDING;
}

