//---------------------------------------------------------------------------
// /obj/tool/voter.c
//
// A simple tool for performing wizard votes in OSB
// (c) Softbyte@OSB 8dec97
// [softbyte 08dec97]  V1.0:  Basic functions
// [softbyte 10feb98]  Proposales can be prolonged and shortened
// [mordrid 30aug98]  Group name changed to be correct
//---------------------------------------------------------------------------

#include <properties.h>
#include <news.h>
#include <msgclass.h>
#include <daemons.h>
#include <secure/config.h>

inherit "/std/thing";

#define TP this_player()

int cmd_create(string str)
{
  if (!str || -1==member(
    ({"vote","new vote"}), str) ) return notify_fail(
      "Create what?\n",NOTIFY_NOT_CMD);

  if (({mixed})TP->Query("_create_vote"))
  {
    msg_write(CMSG_GENERIC,
      "Warning, overwriting old vote data!\n");
  }
  if (0==({int})VOTESERVER->CreateVote("wizards",1)) return notify_fail(
    "Cannot create a new vote.\n",NOTIFY_NOT_VALID);

  return 1;
}
int cmd_propose(string str)
{
  mixed *data;
  if (!str || -1==member(
    ({"vote"}), str) ) return notify_fail(
      "Propose what?\n",NOTIFY_NOT_CMD);

  if (!(data=({mixed})TP->Query("_create_vote"))) return notify_fail(
    "You must first create a new vote.\n",NOTIFY_NOT_VALID);

  if (0==({int})VOTESERVER->ProposeVote(data)) return notify_fail(
    "Cannot propose a new vote.\n",NOTIFY_NOT_VALID);

  TP->Set("_create_vote",0);
  return 1;
}

int cmd_list(string str)
{
  int no;
  notify_fail("List what?\n",NOTIFY_NOT_CMD);
  if (!str) return 0;

  if (1==sscanf(str,"proposal %d",no))
  {
    if (0==({int})VOTESERVER->InfoVote("wizards",no,0))
      return notify_fail(
        "Cannot list that proposal.\n",NOTIFY_NOT_VALID);
  }
  else if (1==sscanf(str,"vote %d",no))
  {
    if (0==({int})VOTESERVER->InfoVote("wizards",no,1))
      return notify_fail(
        "Cannot list that vote.\n",NOTIFY_NOT_VALID);
  }
  else if (-1!=member(({"proposal","proposals","proposed votes"}), str) )
  {
    if (0==({int})VOTESERVER->ListVotes("wizards",0,TP))
      return notify_fail(
        "Cannot list proposed vote.\n",NOTIFY_NOT_VALID);
  }
  else if (-1!=member(({"vote","votes","open votes"}), str) )
  {
    if (0==({int})VOTESERVER->ListVotes("wizards",1,TP))
      return notify_fail(
        "Cannot list votes.\n",NOTIFY_NOT_VALID);
  }
  else return 0;


  return 1;
}

int cmd_remove(string str)
{
  int no;
  notify_fail("Remove what?\n",NOTIFY_NOT_CMD);
  if (!str) return 0;

  if (1==sscanf(str,"proposal %d",no))
  {
    if (0==({int})VOTESERVER->RemoveVote("wizards",no,0))
      return notify_fail(
        "Cannot remove that proposal.\n",NOTIFY_NOT_VALID);
  }
  else if (1==sscanf(str,"vote %d",no))
  {
    if (0==({int})VOTESERVER->RemoveVote("wizards",no,1))
      return notify_fail(
        "Cannot remove that vote.\n",NOTIFY_NOT_VALID);
  }
  else return 0;
  return 1;
}

int cmd_deny(string str)
{
  int no;
  notify_fail("Deny what?\n",NOTIFY_NOT_CMD);
  if (!str) return 0;

  if (1==sscanf(str,"proposal %d",no))
  {
    if (0==({int})VOTESERVER->DenyProposal("wizards",no))
      return notify_fail(
        "Cannot deny that proposal.\n",NOTIFY_NOT_VALID);
  }
  else return 0;
  return 1;
}

int cmd_prolong(string str)
{
  int no,days;
  notify_fail("Prolong what?\n",NOTIFY_NOT_CMD);
  if (!str) return 0;
  if (2==sscanf(str,"vote %d by %d days",no,days)
    || 2==sscanf(str,"vote %d %d",no,days) )
  {
    if (0==({int})VOTESERVER->ProlongVote("wizards",no,days,1))
      return notify_fail(
        "Cannot prolong that vote.\n",NOTIFY_NOT_VALID);
  }
  else if (2==sscanf(str,"proposal %d by %d days",no,days)
    || 2==sscanf(str,"proposal %d %d",no,days) )
  {
    if (0==({int})VOTESERVER->ProlongVote("wizards",no,days,0))
      return notify_fail(
        "Cannot prolong that proposal.\n",NOTIFY_NOT_VALID);
  }
  else return 0;
  return 1;
}

int cmd_alternative(string str)
{
  string alt;
  int no,altno;
  notify_fail("Alternative add to what or remove from what?\n",NOTIFY_NOT_CMD);
  if (!str) return 0;
  if (2==sscanf(str,"%s add to proposal %d",alt,no)
      || 2==sscanf(str,"%s add %d",alt,no) )
  {
    if (0==({int})VOTESERVER->AddAlternative("wizards",no,alt))
      return notify_fail(
        "Cannot add that alternative.\n",NOTIFY_NOT_VALID);
  }
  else if (2==sscanf(str,"%d remove from proposal %d",altno,no)
      || 2==sscanf(str,"%d rem %d",altno,no) )
  {
    if (0==({int})VOTESERVER->RemoveAlternative("wizards",no,altno))
      return notify_fail(
        "Cannot remove that alternative.\n",NOTIFY_NOT_VALID);
  }
  else return 0;
  return 1;
}

int cmd_vote(string str)
{
  int no,alt,secret;
  notify_fail("Vote for what?\n",NOTIFY_NOT_CMD);
  if (!str) return 0;

  if (query_verb()=="svote") secret=1;
  else secret=0;

  if (2==sscanf(str,"for alternative %d in vote %d",alt,no)
    || 2==sscanf(str,"for alt %d in vote %d",alt,no)
    || 2==sscanf(str,"for %d in %d",alt,no)
    || 2==sscanf(str,"%d %d",alt,no) )
  {
    if (alt<1)
      return notify_fail(
        "Cannot vote for that alternative.\n",NOTIFY_NOT_VALID);
    if (0==({int})VOTESERVER->Vote("wizards",no,alt,secret))
      return notify_fail(
        "Cannot vote in that vote.\n",NOTIFY_NOT_VALID);
  }
  else return 0;
  return 1;
}

varargs void create()
{
  ::create();
  if (!is_clone()) return ;
  seteuid(getuid());
  SetShort("a portable votingbox");
  SetLong(
  "With this portable voting box you can do all wizards voting in AoH.\n"
  "Try 'help votingbox' to get more information.\n");
  Set(P_HELP_MSG,
  "The commands of the votingbox are:\n"
  "- create vote:        Create a new vote. All details will be asked.\n"
  "- propose vote:       Propose the new vote for suggestions on the board.\n"
  "- list votes:         List all ongoing votes and proposals\n"
  "- list vote ##:       Show the details of vote ## (e.g. list vote 1)\n"
  "- remove vote ##:     Remove the vote ## from the active votes.\n"
  "- remove proposal ##: Remove the proposal ## from the active ones.\n"
  "- deny proposal ##:   Reject propoal ##\n"
  "- alternative <alt> add to proposal ##:\n"
  "- alternative <alt> add ##: Add a new alternative to a proposal\n"
  "- alternative ## remove from proposal ##:\n"
  "- alternative ## rem ## : Remove an alternative from a proposal\n"
  "- prolong vote ## by ## days:\n"
  "- prolong vote ## ##    : Make the proposal last ## days longer.\n"
  "- prolong proposal ## by ## days:\n"
  "- prolong proposal ## ##: Make the vote last ## days longer.\n"
  "- vote for alternative ## in vote ##\n"
  "  vote for alt ## in vote ##\n"
  "  vote for ## in ##\n"
  "  vote ## ##          All above mean the same, namely to vote for\n"
  "                      an alternative ## in a vote ##.\n"
  "  svote ...:          Using 'svote' instead of vote will perform a\n"
  "                      especially secret vote. Its disadvantage is\n"
  "                      that you will not be shown afterwards what you\n"
  "                      have voted and cannot redo your vote.\n"
  "\n"
  "All results, proposals and votes will be posted to 'vote.wizards'\n"
  "\n"
  "Happy voting,\n"
  "Softbyte\n");
  AddId("voter");
  AddId("voting");
  AddId("votingbox");
  AddId("box");
  AddAdjective("voting");
  AddAdjective("portable");
  SetWeight(0);
  Set(P_NOGIVE,1);
  Set(P_NODROP,1);
  Set(P_NOSELL,1);
  Set(P_AUTOOBJECT,1);
}

void init()
{
  ::init();
  add_action("cmd_create","create");
  add_action("cmd_propose","propose");
  add_action("cmd_list","list");
  add_action("cmd_remove","remove");
  add_action("cmd_deny","deny");
  add_action("cmd_vote","vote");
  add_action("cmd_vote","svote");
  add_action("cmd_prolong","prolong");
  add_action("cmd_alternative","alter",1);
}
