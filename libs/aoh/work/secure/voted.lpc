/*--------------------------------------------------------------------------
 * /secure/voted.c -- The voting database and interface.
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * The voted handles the voting mechanism of OSB. The blueprint holds the
 * database of all active votes; the clones handle the interaction with
 * the players.
 * The data is stored in SECURESAVEPATH/votes/, each vote in one file
 * with a filename "vote-<id>.o".
 * The directory is created when necessary.
 * Every active vote is identified by an id number (actually the time() the
 * vote was started). All sorts of log output (including results of finished
 * votes) are stored in /log/VOTED.
 *--------------------------------------------------------------------------
 * TODO: SToreNote() returns ({ id }) on success.
 * TODO: Reserve the 'voted' name.
 * TODO: EndVoting()
 * TODO: Text in logfile besser abgrenzen.
 * TODO: Logfiles je voting anlegen, name aus ShortTag ermitteln.
 */

#pragma strict_types

#include <secure/config.h>
#include <secure/wizlevels.h>
#include <news.h>

// Savepath for the votes
#define VOTEPATH  SECURESAVEPATH "votes/"

// Full pathname of the logfile
#define VOTELOG  "/log/VOTED"

// The userid of the voted
#define VOTEUID "voted"

// The newsgroups to post to
#define VOTEGROUP "votes"
#define RESULTGROUP "votes.results"

// Forward declarations
public void CheckVotings();

/* Define this for debugging facilities. */
#define DEBUG

#ifdef DEBUG
#define private
#endif

/*------------------------------------------------------------------------*/
/* These variables are the interface to the savefiles.
 */

int   tStart;        // time() of the start of the voting. This is also
                     // the id of the vote.
int   tEnd;          // time() of the scheduled end of the voting
int * VoteLevel;     // ({ min, max }) wizlevel of allowed voters.
int * OpinionLevel;  // ({ min, max }) wizlevel of allowed opinion givers.
  // A zero or empty array disallows votes/opinions.
  // -1 as maxlevel denotes it as openended.
  // If both are given, the two ranges must not overlap.
string Topic;        // One-line topic description, no trailing \n.
string Description;  // Multi-line full description, just a trailing \n.
string * Choices;    // ({ "choicedescription", ... })
  // One of the choices must be aquivalent to "No". Not more than 9
  // choices at once.
int    * Votes;      // For each Choice[2*i], Votes[i] is the number of votes.
int    * Opinions;   // For each Choice[2*i], Opinions[i] is the number of
                     // opinions.
int VoteAbstains;    // Number of abstains from voting.
int OpinionAbstains; // Number of abstains from giving an opinion.
string * Voters;     // uids of users which already voted/gave an opinion

/*------------------------------------------------------------------------*/
/* The database master keeps an internal index of all votes, for faster
 * lookup. Nevertheless, modifications are always done on the actual
 * savefiles, even though its slower.
 */

nosave mapping mIndex;
  // Key is the id of the vote, the value fields are these:
#define I_END     0  // the end time()
#define I_VOTELVL 1  // the vote level
#define I_OPLVL   2  // the opinion level
#define I_TOPIC   3  // the topic string
#define I_VOTERS  4  // the voters
#define I_SIZE    5  // the number of fields.

/*------------------------------------------------------------------------*/
public void create_obj ()

/* Initialize the voting daemon and read the data of all active
 * votings.
 */

{
  int i;

  seteuid(VOTEUID);

  if (to_string(this_object()) != VOTE_D)
  {
    write_file(VOTELOG, ctime()+" Cloned as "
                      +to_string(this_object())+"\n");
    destruct(this_object());
    raise_error("Illegal attempt.\n");
  }

  mIndex = m_allocate(0, I_SIZE);

  write_file(VOTELOG, ctime()+" Loading voted.\n");

  // Create VOTEPATH if necessary.
  i = file_size(VOTEPATH);
  if (i != -2)
  {
    if (i != -1)
      catch(rm(VOTEPATH));
    mkdir(VOTEPATH);
    write_file(VOTELOG, ctime()+" Created " VOTEPATH ".\n");
  }

  // Read the data for all the active votings
  {
    int startticks, count;
    int rc;
    string * names;

    startticks = get_eval_cost();
    count = 0;

    names = get_dir(VOTEPATH+"vote-*.o");
    for (i = 0; i < sizeof(names); i++)
    {
      if (catch(rc = restore_object(VOTEPATH+names[i][0..<3]))
       || !rc
         )
      {
        write_file(VOTELOG, ctime()+" Can't restore vote "+names[i]+".\n");
        rm(VOTEPATH+names[i]);
      }
      else
      {
        count++;
        mIndex += ([tStart:tEnd;VoteLevel;OpinionLevel;Topic;Voters]);
        // Make the copied arrays unique.
        VoteLevel = OpinionLevel = Voters = 0;
      }
    }
    write_file(VOTELOG, ctime()+" Read "+count+" votes in "
                        +(startticks - get_eval_cost())+" ticks.\n");
  }
  call_out(#'CheckVotings /*'*/, 0);
}

/*------------------------------------------------------------------------*/
public void create_clone()

/* Initialize the voting interface for one player */

{
  seteuid(VOTEUID);

  if (blueprint(this_object()) != VOTE_D)
  {
    write_file(VOTELOG, ctime()+" Cloned as "
                      +to_string(this_object())+"\n");
    destruct(this_object());
    raise_error("Illegal attempt.\n");
  }
}

/*------------------------------------------------------------------------*/
public void create_inh()

/* Forbid inheriting the voted :-) */

{
  seteuid(VOTEUID);

  write_file(VOTELOG, ctime()+" Illegal inheritage into "
                      +to_string(this_object())+"\n");
  destruct(this_object());
  raise_error("Illegal attempt.\n");
}

/*------------------------------------------------------------------------*/
public void reset()
{
  if (!is_clone(this_object()))
    CheckVotings();
}

/*------------------------------------------------------------------------*/
public int clean_up(int ref)
{
  if (ref > 1)
  {
    write_file(VOTELOG, ctime()+" "+to_string(this_object())+" cleant up.\n");
    destruct(this_object());
  }
  return this_object() && 1;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
                      /* === The Database === */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*------------------------------------------------------------------------*/
private string votingLongChoices (int bWrapIt)

/* Glue together the long descriptional data and the description of
 * the choices into one formatted string.
 */

{
  string msg, tmp;
  int i;

  if (bWrapIt)
    msg = sprintf("%-78=s", Description);
  else
    msg = Description;
  msg += "\n";

  for (i = 0; i < sizeof(Choices); i++)
  {
    tmp = sprintf("     %-73=s\n", Choices[i]);
    msg += "  "+(i+1)+". "+tmp[5..];
  }

  return msg;
}

/*------------------------------------------------------------------------*/
private string describeLevels (int minlevel, int maxlevel)

/* Return a string describing who was allowed to take part in a voting.
 * The string does not end in a newline.
 */

{
  string * tmp;

  tmp = ({});
  if (LVL_PLAYER >= minlevel)
    tmp += ({ "Players" });
  if (LVL_ANCIENT >= minlevel && (maxlevel < 0 || LVL_ANCIENT <= maxlevel))
    tmp += ({ "Elders" });
  if (LVL_WIZARD >= minlevel && (maxlevel < 0 || LVL_WIZARD <= maxlevel))
    tmp += ({ "Wizards" });
  if (maxlevel >= 0)
    return implode_list(tmp, "", ".", ",")[0..<2];
  return tmp[0]+" and up.";
}

/*------------------------------------------------------------------------*/
private string votingText()

/* Return a string describing all the data of a voting, using the values
 * in the global variables.
 */

{
  string msg;

  msg = Topic + "\n\n";
  msg += "Duration: "+ctime(tStart)+"-"+ctime(tEnd)+"\n";
  if (sizeof(VoteLevel))
    msg += "Voters:   "+describeLevels(VoteLevel[0], VoteLevel[1])+"\n";
  if (sizeof(OpinionLevel))
    msg += "Opinions: "+describeLevels(OpinionLevel[0], OpinionLevel[1])+"\n";
  msg += "\n" + votingLongChoices(1);
  return msg;
}

/*------------------------------------------------------------------------*/
private string votingResult()

/* Return a string describing the result of a voting, using the values
 * in the global variables.
 */

{
  int iVotes, iOps;  // Total number of Votes/Opinions
  int j;
  string msg;

  // Count the total number of votes and opinions.
  iVotes = 0;
  for (j = 0; j < sizeof(Votes); j++)
    iVotes += Votes[j];
  iVotes += VoteAbstains;

  iOps = 0;
  for (j = 0; j < sizeof(Opinions); j++)
    iOps += Opinions[j];
  iOps += OpinionAbstains;

  // Make up the message
  msg += "Result:\n";
  for (j = 0; j < sizeof(Choices); j++)
  {
    msg += "   -- "+(j+1)+": ";
    if (sizeof(VoteLevel))
      msg += sprintf("%3d (%4.1f) votes", Votes[j]
                    , to_float(Votes[j]) * 100.0 / to_float(iVotes||1));
    if (sizeof(OpinionLevel))
    {
      if (sizeof(VoteLevel))
        msg += ", ";
      msg += sprintf("%3d (%4.1f) opinions", Opinions[j]
                    , to_float(Opinions[j]) * 100.0 / to_float(iOps||1));
    }
    msg += "\n";
  }

  msg += "   -- -: ";
  if (sizeof(VoteLevel))
    msg += sprintf("%3d (%4.1f) votes", VoteAbstains
                  , to_float(VoteAbstains) * 100.0 / to_float(iVotes||1));
  if (sizeof(OpinionLevel))
  {
    if (sizeof(VoteLevel))
      msg += ", ";
    msg += sprintf("%3d (%4.1f) opinions", OpinionAbstains
                  , to_float(OpinionAbstains) * 100.0 / to_float(iOps||1));
  }
  msg += "\n";
  msg += "  Total: ";
  if (sizeof(VoteLevel))
    msg += sprintf("%3d        votes", iVotes);
  if (sizeof(OpinionLevel))
  {
    if (sizeof(VoteLevel))
      msg += ", ";
    msg += sprintf("%3d        opinions", iOps);
  }
  msg += "\n";

  return msg;
}

/*------------------------------------------------------------------------*/
public string DescribeVoting(int id)

/* Return a string describing the voting with id <id>.
 * If there is no such voting, 0 is returned.
 */

{
  mixed rc;

  if (is_clone(this_object()))
  {
    raise_error("DescribeVoting() called in clone.\n");
    return 0;
  }

  if (catch(rc = restore_object(VOTEPATH+"vote-"+id))
   || !rc
     )
    return 0;

  return votingText();
}

/*------------------------------------------------------------------------*/
public void CheckVotings()

/* Check all the votings in mIndex for finished ones and print the result
 * of those.
 */

{
  int * ids;
  int i;
  string logmsg, notemsg, tmp;
  mixed rc;

  if (is_clone(this_object()))
  {
    raise_error("CheckVotings() called in clone.\n");
    return;
  }

  ids = m_indices(mIndex);
  for (i = 0; i < sizeof(ids); i++)
  {
    if (mIndex[ids[i], I_END] > time()) // Voting still active.
      continue;

    // Try loading the data
    if (catch(rc = restore_object(VOTEPATH+"vote-"+ids[i]))
     || !rc
       )
      continue;  // will be removed on the next create

    // Make up the messages.
    tmp = votingText() + "\n"+ votingResult();

    logmsg = ctime()+" Vote "+ids[i]+" finished.\n"+tmp;
    notemsg = tmp + " -- The Vote Daemon\n";

    // Post the note (if possible)
    rc = ({mixed})NEWSSERVER->StoreNote("RESULT: "+Topic, notemsg
                                     , ({ VOTEGROUP, RESULTGROUP })
                                     , this_object());
    if (!intp(rc) || NEWS_OK != rc)
      logmsg += ctime()+" Posting failed: "+sprintf("%O\n", rc);
    write_file(VOTELOG, logmsg);
    m_delete(mIndex, ids[i]);
    rm (VOTEPATH+"vote-"+ids[i]+".o");
  } /* for (i in ids) */
}

/*------------------------------------------------------------------------*/
public mapping GetIndex()

/* Return a value copy of the mIndex mapping. */

{
  mapping rc;
  int i, * ids;

  if (is_clone(this_object()))
  {
    raise_error("GetIndex() called in clone.\n");
    return 0;
  }

  rc = copy(mIndex);
  ids = m_indices(rc);
  for (i = 0; i < sizeof(ids); i++)
  {
    rc[ids[i], I_VOTELVL] = rc[ids[i], I_VOTELVL] + ({});
    rc[ids[i], I_OPLVL]   = rc[ids[i], I_OPLVL] + ({});
    rc[ids[i], I_VOTERS]  = rc[ids[i], I_VOTERS] + ({});
  }

  return rc;
}

/*------------------------------------------------------------------------*/
public string StartVoting ( int _tEnd         // designated parms of the voting
                          , int * _VoteLevel
                          , int * _OpinionLevel
                          , string _Topic
                          , string _Description
                          , string * _Choices
                          )

/* Start a new voting with the given parameters.
 * Return 0 if everything is ok, or an error message.
 */

{
  string notemsg, logmsg, tmp, who;
  object starter;
  mixed rc;

  if (is_clone(this_object()))
  {
    raise_error("StartVoting() called in clone.\n");
    return "Illegal object to call.\n";
  }

  tStart = time();
  starter = this_interactive() || this_player() || this_object();
  who = ({string})starter->QueryRealName() || ({string})starter->Short() || "Something";
  who = capitalize(who);

  // Do some cursory checks on the parms.
  if (-1 < file_size(VOTEPATH+"vote-"+tStart+".o"))
    return "A vote with this id already exists. Try again later.\n";
  if (_tEnd <= tStart + 2 * 3600 * 24)
    return "End of voting is too soon.\n";
  if (!sizeof(_VoteLevel) && !sizeof(_OpinionLevel))
    return "Nobody would be allowed to vote.\n";
  if (sizeof(_Choices) < 2)
    return "Not enough choices.\n";

  // Create the savefile.
  tEnd = _tEnd;
  Topic = _Topic;
  Description = _Description;
  VoteLevel = _VoteLevel + ({});
  OpinionLevel = _OpinionLevel + ({});
  Choices = _Choices + ({});
  Votes = allocate(sizeof(Choices));
  Opinions = allocate(sizeof(Choices));
  VoteAbstains = 0;
  OpinionAbstains = 0;
  Voters = ({});
  save_object(VOTEPATH+"vote-"+tStart);

  // Add vote to mIndex
  mIndex += ([ tStart:tEnd;VoteLevel;OpinionLevel;Topic;Voters ]);

  // Make up the messages.
  tmp = votingText() + "\n";
  tmp += "Vote was started by "+who+"\n";

  logmsg = ctime()+" New vote "+tStart+" by "+to_string(starter)+".\n"+tmp;
  notemsg = tmp + " -- The Vote Daemon\n";

  // Post the note (if possible)
  rc = ({mixed}) NEWSSERVER->StoreNote("NEW VOTING: "+Topic, notemsg
                                    , ({ VOTEGROUP })
                                    , this_object());
  if (!intp(rc) || NEWS_OK != rc)
    logmsg += ctime()+" Posting failed: "+sprintf("%O\n", rc);
  write_file(VOTELOG, logmsg);

  // Stomp onto the arrays to be sure.
  VoteLevel = OpinionLevel = Voters = 0;
  return 0;
}

/*------------------------------------------------------------------------*/
public int CancelVoting ( int voteId )

/* Cancel the voting with the given <voteId>.
 * Result is 0 on success, else non-zero.
 */

{
  string notemsg, logmsg, tmp, who;
  object starter;
  mixed rc;

  if (is_clone(this_object()))
  {
    raise_error("CancelVoting() called in clone.\n");
    return 1;
  }

  starter = this_interactive() || this_player() || this_object();
  who = ({string})starter->QueryRealName() || ({string})starter->Short() || "Something";
  who = capitalize(who);

  // Do some cursory checks on the parms.
  if (-1 >= file_size(VOTEPATH+"vote-"+voteId+".o"))
    return 1;

  // Restore the data for the log output.
  if (catch(rc = restore_object(VOTEPATH+"vote-"+voteId))
   || !rc
     )
    return 1;

  // Create the logs
  tmp = votingText() + "\n";
  tmp += "Vote was cancelled by "+who+"\n";

  logmsg = ctime()+" Vote "+tStart+" cancelled by "+to_string(starter)+".\n"
                  +tmp;
  notemsg = tmp + " -- The Vote Daemon\n";

  // Post the note (if possible)
  rc = ({mixed}) NEWSSERVER->StoreNote("VOTE CANCELLED: "+Topic, notemsg
                                    , ({ VOTEGROUP })
                                    , this_object());
  if (!intp(rc) || NEWS_OK != rc)
    logmsg += ctime()+" Posting failed: "+sprintf("%O\n", rc);
  write_file(VOTELOG, logmsg);

  // Remove the voting.
  rm(VOTEPATH+"vote-"+voteId+".o");
  m_delete(mIndex, voteId);
  return 0;
}

/*------------------------------------------------------------------------*/
public int CastVote (int voteId, int choice, string name)

/* Cast a vote for voting <voteId> and user <name>. <choice> gives the
 * choice voted for (1..sizeof(choices)), or 0 for abstain.
 * Result is 0 on success, or non-zero on a failure.
 * This function must only be called by the cloned VOTE_Ds.
 */

{
  mixed rc;
  int   wlvl;

  if (is_clone(this_object()))
  {
    raise_error("CastVoting() called in clone.\n");
    return 1;
  }

#ifndef DEBUG
  if (blueprint(to_string(previous_object())) != VOTE_D)
  {
    raise_error("Illegal attempt.\n");
    return 1;
  }
#endif

  if (-1 >= file_size(VOTEPATH+"vote-"+voteId+".o")
   || catch(rc = restore_object(VOTEPATH+"vote-"+voteId))
   || !rc)
  {
    raise_error("Can't find or restore vote "+voteId+".\n");
    return 1;
  }

  if (-1 != member(Voters, name))
  {
    raise_error(name+" did already vote for "+voteId+".\n");
    return 0;
  }

  if (choice < 0 || choice > sizeof(Choices))
  {
    raise_error("Choice "+choice+" out of range for "+voteId+".\n");
    return 1;
  }

  wlvl = query_user_level(name);
  if (wlvl >= VoteLevel[0] && (VoteLevel[1] < 0 || wlvl <= VoteLevel[1]))
  {
    if (choice > 0)
      Votes[choice-1]++;
    else
      VoteAbstains++;
  }
  else if (wlvl >= OpinionLevel[0]
    && (OpinionLevel[1] < 0 || wlvl <= OpinionLevel[1]))
  {
    if (choice > 0)
      Opinions[choice-1]++;
    else
      OpinionAbstains++;
  }

  Voters += ({ name });
  save_object(VOTEPATH+"vote-"+voteId);

  mIndex[voteId, I_VOTERS] += ({ name });

  return 0;
}

/*------------------------------------------------------------------------*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
                  /* === The Voting interface === */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*------------------------------------------------------------------------*/
/***************************************************************************/
