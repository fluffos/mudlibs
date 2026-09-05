/* cast a vote */
#include "../DEFS.h"


void usage()
{
  write(
HIR+"Usage"+NORM+"\n"+
"This command is used to cast your vote.\n"+
HIY+"vote_cast <voteName> <choice>"+NORM+"\n"+
"  - If you created the vote, don't forget to cast your vote.\n");
}


status main(string str)
{
  string voteName, decision, voteText, secret_voteText, voteChoices;
  string *choiceArray;
  int i;
  status validChoice;
  mixed *voteData;

  if (!call_other(VOTED, "accessAllow", (string)this_player()->query_real_name()))
  {
    write("You have no such polling authority.\n");
    return 1;
  }

  if (!str)
  {
    usage();
    return 1;
  }

  if (sscanf(str, "%s %s", voteName, decision) != 2)
  {
    usage();
    return 1;
  }

  decision = lower_case(decision);
  voteName = lower_case(voteName);

  if (!call_other(VOTED, "voteExists", voteName))
  {
    write("Vote "+voteName+" does not exist.\n");
    return 1;
  }

  if (!call_other(VOTED, "voteInProgress", voteName))
  {
    write("The deadline to vote on "+voteName+" has passed.\n");
    return 1;
  }

  voteData = (mixed*)call_other(VOTED, "getVoteData", voteName);

  if (call_other(VOTED, "hasVoted", voteData, this_player()->query_real_name()))
  {
    write("You have already voted on "+voteName+".\n");
    return 1;
  }

  voteChoices = voteData[INDEX_CHOICES];
  choiceArray = explode(voteChoices, CHOICE_SEP);
  validChoice = 0;
  for (i=0; i < sizeof(choiceArray); i++)
  {
    if (decision == choiceArray[i]) validChoice = 1;
  }
  if (!validChoice)
  {
    write("Your decision was not valid.\n"+
          "It must be one of: "+voteChoices+".\n");
    return 1;
  }

  secret_voteText = decision+" "+this_player()->query_real_name()+"\n";
  if (voteData[INDEX_PUB] == "secret")
  {
    voteText = decision+" Someone\n";
  }
  else
  {
    voteText = secret_voteText;
  }

  write_file(VOTEDIR + "/" + voteName, voteText);

  if (voteData[INDEX_PUB] == "secret")
  {
    /* store the secret name in the secret votes directory */
    write_file(SVOTEDIR + "/" + voteName, secret_voteText);
  }

  write("You cast a "+decision+" for vote "+voteName+".\n");
  return 1;
}
