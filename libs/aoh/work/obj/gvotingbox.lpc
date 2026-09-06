/*
** Guild-Votingbox
** Written for use in the /std/guild
** Author: Thragor@Nightfall, 31oct94
** Update: Thragor@Nightfall, 06may96
*/

inherit "/obj/votingbox";

#include <config.h>
#include <guild.h>
#include <secure/wizlevels.h>

#define TP this_player()
#define TI this_interactive()
#define ME this_object()
#define SF(x) #'x //'
#define Q(x) 'x //'

#define V_TOPIC "guildleader"

#define V_DELAY 2*30*24*60*60
// Voting takes place every two month
#define V_PERIOD 14*24*60*60
// Voting takes two weeks
#define V_NAME 0
#define V_DESC 1
#define V_ALTS 2

int starttime;

public string QuerySavefile()
{
  return (::QuerySavefile())||blueprint(QueryCreator())+".votes";
}

public int SetStartTime(int t)
{
  LoadBox();
  starttime = t;
  SaveBox();
  return starttime;
}

public int QueryStartTime()
{
  LoadBox();
  if (!starttime) SetStartTime(time()-10);
  return starttime;
}

public int QueryEndTime()
// Voting takes until a guildleader is chosen and
// after 14 days.
{
  return QueryStartTime()+V_PERIOD;
}

public status CheckActive()
// A voting is active if the time is between starttime and
// endtime, or if no endtime is given, if the time is above
// the starttime.
{
  int t;
  t = time();
  return    t>QueryStartTime()
         && (t<QueryEndTime()||!QueryEndTime());
}

private int valid_candidate(mixed pl)
{
  object env;
  return    !IS_IMMORTAL(pl)
         && (env = environment())
         && env->is_member(pl);
}

public int cmd_list(string str)
// list votes list votes to topic
{
  int nr,i;
  string *Aidx,txt;
  mapping alts;
  
  if (lower_case(str||"")!="votes")
    return notify_fail("List what?\n",NOTIFY_NOT_OBJ),0;
  if (!CheckActive())
  { write("There's no voting right now.\n"); return 1; }
// Eilan 06apr97 as it collides with the player board
//	return notify_fail("There's no voting right now.\n",
//		       NOTIFY_NOT_VALID),0;
  alts = QueryVotes()[V_TOPIC];
  Aidx = QueryAlternatives(V_TOPIC);
  if (!sizeof(Aidx))
  {
      write("No candidates up to now.\n");
      return 1;
  //  return notify_fail("No candidates up to now.\n",NOTIFY_NOT_VALID),0;
  //  Softbyte 02nov96 as it collides with the players board
  }
  txt = "Votes for Guildleader\n";
  for(i=0;i<sizeof(Aidx);i++)
    txt+=sprintf("%2d. %-20s %3d votes\n",
	         i+1,capitalize(Aidx[i]),alts[Aidx[i]]);
  smore(txt,TP->QueryPageSize());
  return 1;
}

public int cmd_vote(string str)
// vote <altnr>|<candidate>
{
  string *Aidx,who;
  int Nalt;
  
  if (!TP||!str||!is_clone())
    return notify_fail("For whom do you want to vote for?\n",
		       NOTIFY_NOT_OBJ),0;
  str = lower_case(str);

  if (!CheckActive())
    return notify_fail("There's no voting right now.\n",
		       NOTIFY_NOT_VALID),0;
  Aidx = QueryAlternatives(V_TOPIC);
  if (!sizeof(Aidx))
    return notify_fail("No candidates to choose between.\n",
		       NOTIFY_NOT_VALID),0;
  if ((Nalt = member(Aidx,str))==-1)
    if (to_string(Nalt = to_int(str))!=str)
      return notify_fail(capitalize(str)+" is no candidate.\n",
			 NOTIFY_NOT_VALID),0;
    else
      {
        Nalt--;
	if (Nalt<0 || Nalt>=sizeof(Aidx))
          return notify_fail("No candidate "+str+".\n",NOTIFY_NOT_VALID),0;
        who = Aidx[Nalt];
      }
  else
    who = str;
  if (!valid_candidate(TP))
    return notify_fail(
      "You're not allowed to vote for the guildleader of this guild.\n",
      NOTIFY_NOT_VALID),0;
  if (!AddVote(V_TOPIC,who))
    return 0;
  write("Voted.\n");
  return 1;
}
  
public int cmd_candidate(string str)
{
  string *topics;
  
  if (!TP||str)
    return notify_fail("Just type 'candidate'.\n",NOTIFY_NOT_OBJ),0;
  if (!CheckActive() || !sizeof(topics = QueryTopics()) )
    return notify_fail("There's no voting taking place right now.\n",
		       NOTIFY_NOT_VALID),0;
  if (TP->QueryLevel()<QueryAlternativeLevel())
    return notify_fail("Your level is too low to candidate.\n",
		       NOTIFY_NOT_VALID),0;
  if (!valid_candidate(TP))
    return notify_fail(
      "You're not allowed to candidate for the guildleader of this guild.\n",
      NOTIFY_NOT_VALID),0;
  if (!AddAlternative(topics[0],getuid(TP)))
    return 0;
  write("Apply for Guildleader added.\n");
  return 1;
}

public int evaluate_leader(mapping votes,string leader,string vice)
{
  int *v;
  string idx;
  
  v = sort_array(m_values(votes),SF(<));
  votes = mkmapping(m_values(votes),map(m_indices(votes),
					      SF(lower_case)));
  if (   !sizeof(v)
      || v[0]==0
      || (sizeof(v)>1 && v[0]==v[1]) // no exact guildleader
      || (sizeof(v)>2 && v[1]==v[2]) // no exact vice
     )
    return 0;
  leader = votes[v[0]];
  if (sizeof(v)>1) vice = votes[v[1]];
  return 1;
}

public void reset()
{
  mapping votes;
  string leader,vice,*applies;
  object env;
  int t,i;
  if (!is_clone()||!env = environment()) return;
  t = time();
  applies = m_indices((votes = QueryVotes()[V_TOPIC]||([])));
  SetAlternativeLevel(0);
  map(applies-filter(applies,SF(valid_candidate)),
            lambda(({Q(pl)}),({SF(RemoveAlternative),V_TOPIC,Q(pl)})));
  SetAlternativeLevel(20);
  votes = QueryVotes()[V_TOPIC];
  if (   QueryEndTime()<t+60*6
      && CheckActive()
      && !evaluate_leader(votes,&leader,&vice)
     )
    {
      SetStartTime(t-V_PERIOD+24*60*60);
      // If no result could be evaluated up to now, the voting will
      // last one day longer
      return;
    }
  if (!CheckActive())
    if (sizeof(votes))
      {
	if (!evaluate_leader(votes,&leader,&vice))
	  {
	    SetStartTime(t-V_PERIOD+24*60*60);
	    return;
	  }
	Pvotes = 0;
	SaveBox();
	SetStartTime(t+V_DELAY);
	env->ChangeStat(env->QueryGuildleader(),G_MEMBER);
	env->ChangeStat(env->QueryViceGuildleader(),G_MEMBER);
	env->ChangeStat(lower_case(leader),G_LEADER);
	if (vice) env->ChangeStat(lower_case(vice),G_VICELEADER);
      }
    else if (!env->QueryGuildleader())
      SetStartTime(t);
}

public void create()
{
  (::create());
  SetShort("a voting box for guildleader");
  SetLong(
    "If the voting is active all members of the guild above level 5 might\n"
    "vote for their guildleader (and vice-guildleader). The voting will last\n"
    "as long as a guildleader is chosen. If two possible guildleaders have\n"
    "the same amount of votes the voting will last until one of them\n"
    "is leading.\n");
  SetHelpMsg(
    "You may vote for your guildleader with this voting box.\n"
    "To get all candidates for the guildleadership just type\n"
    "'list votes' and to vote just type 'vote <nr>' or 'vote <candidate>'.\n"
    "To become a candidate you have to be above level 20 and\n"
    "you have to type 'candidate'.\n"
	    );
  SetIds(({"box","votingbox","guildleader"}));
  SetAds(({"voting","simple","box","votingbox","for"}));
  SetNoGet("Don't carry the votes away!!!\n");
  if (is_clone())
    {
      LoadBox();
      AddTopic(V_TOPIC,"Guildleader",
	       "Voting for the guildleader of a guild.\n");
    }
  SetTopicLevel(-255);
  SetAlternativeLevel(20);
  SetVoteLevel(5);
}

public int cmd_add(string str) { return 0; }
public int cmd_remove(string str) { return 0; }

public void init()
{
  (::init());
  add_action("cmd_list","list");
  add_action("cmd_vote","vote");
  add_action("cmd_add","add");
  add_action("cmd_remove","remove");
  add_action("cmd_candidate","candidate");
  if (   TI
      && CheckActive()
      && valid_candidate(TI)
      && TI->QueryLevel()>4
      && !QueryVoted(V_TOPIC)
     )
    tell_object(TI,"You haven't voted for the guildleader up to now.\n");
}
