/* view votes in progress */
#include "../DEFS.h"


status main(string str)
{
  string myName, owner;
  mixed *voteData;

  if((int)this_player()->query_level() < 100)
 return 0;
  if (!call_other(VOTED, "accessAllow", (string)this_player()->query_real_name()))
  {
    write("You have no such polling authority.\n");
    return 1;
  }

  if (!str)
  {
    write("You must specify a voteName in progress to close.\n");
    return 1;
  }

  if (!call_other(VOTED, "voteExists", str))
  {
    write("Vote "+str+" does not exist.\n");
    return 1;
  }

  if (!call_other(VOTED, "voteInProgress", str))
  {
    write("You cannot close a vote that has already finished.\n"+
          "You may close only votes still in progress.\n");
    return 1;
  }

  voteData = (mixed*)call_other(VOTED, "getVoteData", str);

  myName = (string)this_player()->query_real_name();
  owner = voteData[INDEX_OWNER];
  if (myName != owner && !call_other(VOTED, "isVoteManager", myName))
  {
    write("Only the owner of this vote ("+capitalize(owner)+") can close.\n");
    return 1;
  }

  call_other(VOTED, "closeVote", str);
  call_other(VOTED, "evaluateVote", str, 1, voteData[INDEX_PUB] == "secret");

  write("You close vote "+str+".\n");

  return 1;
}
