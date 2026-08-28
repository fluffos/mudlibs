/****
****    Command                                 use
***     Descriptions                            uses skills
**      Coder                                   Dragoness
*/



int main(string args)
{
  if (THIS->list_true_names() == "")
    {
      write ("You don't know anything about truenames.\n");
      return 1;
    }
  else
    {
      write ("You know following truenames:\n");
      message("0",this_player()->list_true_names(args),THIS);
      return 1;
    }
}

query_author()
{
  return"dragoness";
}

query_help()
{
  return "This command is useful only for truename mages.";
}
query_position()
{
  return POS_RESTING;
}
