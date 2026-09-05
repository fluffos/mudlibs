/* cancel a vote in progress */
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
    write("You must specify a voteName in progress to cancel.\n");
    return 1;
  }

  if (!call_other(VOTED, "voteExists", str))
  {
    write("Vote "+str+" does not exist.\n");
    return 1;
  }

  if (!call_other(VOTED, "voteInProgress", str))
  {
    write("You cannot cancel a vote that has already finished.\n"+
          "Vote cancellation is only for votes still in progress.\n");
    return 1;
  }

  voteData = (mixed*)call_other(VOTED, "getVoteData", str);
  myName = (string)this_player()->query_real_name();

  owner = voteData[INDEX_OWNER];
  if (myName != owner && !call_other(VOTED, "isVoteManager", myName))
  {
    write("Only the owner of this vote ("+capitalize(owner)+") can cancel.\n");
    return 1;
  }

  call_other(VOTED, "closeVote", str);
  call_other(VOTED, "deleteVote", str);

  write("You cancel vote "+str+".\n");
  write_file(LOGDIR + "/VOTES",
    TRN+" canceled vote "+str+" ("+ctime()+")\n");
  return 1;
}
