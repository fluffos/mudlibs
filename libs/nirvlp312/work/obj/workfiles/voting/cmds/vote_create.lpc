/* create a new vote */
#include "../DEFS.h"


void usage()
{
  write(
HIR+"Usage"+NORM+"\n"+
HIY+"vote_create <issueName> [secret|open] <cdays> <choices> <issueDescription>"+NORM+"\n"+
"  - issueDescription is meant to be a lengthy explanation,\n"+
"  - cdays is the number of days to hold the vote open.\n"+
"  - choices is a '"+CHOICE_SEP+"' delimited list of vote choices.\n"+
"  - Example: vote_create freeBadGuy open 10 yea/nay Release BadGuy from jail?\n");
}


status main(string str)
{
  string cdayMonth, cdayDay, cdayYear;
  string issueName, voteName, pub, choices, desc;
  string *test;
  int cdays, i;

  if((int)this_player()->query_level() < 100) return 0;
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

  if (call_other(VOTED, "getVotesInProgressCount") >= MAX_VOTES)
  {
    write("Maximum allowable votes in progress reached: "+MAX_VOTES+"\n");
    return 1;
  }

  cdayMonth = (string)call_other(VOTED, "query_cdayMonth");
  cdayDay   = (string)call_other(VOTED, "query_cdayDay");
  cdayYear  = (string)call_other(VOTED, "query_cdayYear");

  if (sscanf(str, "%s %s %d %s %s", issueName, pub, cdays, choices, desc) < 5)
  {
    usage();
    return 1;
  }

  issueName = lower_case(issueName);
  pub       = lower_case(pub);
  choices   = lower_case(choices);
  voteName  = issueName+"-"+cdayMonth+cdayDay+"_"+cdayYear;
  voteName  = lower_case(voteName);

  test = explode(issueName, "/");
  if (sizeof(test) > 1                ||
      extract(issueName, 0, 0) == "/" ||
      extract(issueName, strlen(issueName)-1) == "/")
  {
    write("The <issueName> cannot include slashes ('/').\n");
    return 1;
  }

  test = explode(choices, CHOICE_SEP);
  for (i=0; i < sizeof(test); i++)
  {
    if (!test[i] || test[i] == CHOICE_SEP || test[i] == "")
    {
      write("Error in choice list.\n");
      return 1;
    }
  }

  if (strlen(voteName) >= MAX_VOTENAME_LENGTH)
  {
    write("The name of your issue is too long, please shorten and try again.\n");
    return 1;
  }

  if (cdays < MIN_CDAYS || cdays > MAX_CDAYS)
  {
    write("Invalid number of cdays entered.\n"+
          "Range is "+MIN_CDAYS+" to "+MAX_CDAYS+".\n");
    return 1;
  }

  if (!(pub == "secret" || pub == "open"))
  {
    write("Voter information was not specified correctly.\n"+
          "Your choices are 'secret' or 'open'.\n");
    return 1;
  }

  if (call_other(VOTED, "voteExists", voteName))
  {
    write("Vote "+voteName+" already exists.\n");
    return 1;
  }

  find_object(VOTED)->addVote(
    voteName, 
    this_player()->query_real_name(), 
    choices, 
    cdays, 
    pub, 
    desc);
  write("You create a vote! The voteName is: " + voteName + "\n");

  write_file(LOGDIR + "/VOTES",
    TRN+" created vote "+voteName+" ("+ctime()+")\n");

  return 1;
}
