/* Party server for OSB
*
*
*
*   30-Jun-97 [Softbyte]
*   01-Jul-97 [Mica] fixed PlayerNetdead, msg_-sefuns
*
*  V1.0: Creation and basic commands
*/

#include <properties.h>
#include <msgclass.h>

#define TP this_player()
#define PO previous_object()
#define SLIB "lib/string"

// player properties
#define P_PARTY                 "Party"            // object leader
#define P_PARTY_PROTECTING      "PartyProtecting"  // object whom
#define P_PARTY_PROTECTED       "PartyProtected"   // object whom
#define P_PARTY_APPLIED         "PartyLeader"      // object leader
#define P_PARTY_XP_SHARE        "PartyXPShare"     // int xp for each mb

// party properites
#define P_PARTY_NAME            "PartyName"        // string name
#define P_PARTY_MEMBERS         "PartyMembers"     // object *members
#define P_PARTY_XP              "PartyXP"          // int xp
#define P_PARTY_KILLS           "PartyKills"       // int kills
#define P_PARTY_TIME            "PartyTime"        // int time

#define PARTY_MSG_STATUS        1                  // status channel
#define PARTY_MSG_EMOTE         2                  // emote channel
#define PARTY_MSG_SHOUT         4                  // shout channel


#define PARTY_XP_PER_LEVEL 20     // this * leveldifferens is share XP diff in %
#define PARTY_LEVEL_DIFFERENCE 7  // this level diff is allowed in the party

// How many members are netdead
int NumberNetdead(object leader)
{
  object *members;
  if (!leader) return 0;
  members=(({object *})leader->Query(P_PARTY_MEMBERS)||({}))-({0});
  members=filter_objects(members,"QueryNetdead")||({});
  return sizeof(members);
}
// Get the time differnece in a readable format between to time()'s
string GetTimeDiff(int now,int was)
{
  int diff,h,m;
  diff=now-was;
  if (diff<0) diff=-diff;
  h=diff/3600;
  diff-=h*3600;
  m=diff/60;
  diff-=m*60;
  if (h>0) return sprintf("%2dh %2dm %2ds",h,m,diff);
  else if (m>0) return sprintf("%2dm %2ds",m,diff);
  else return sprintf("%2ds",diff);
}
// Calulates the share of XP in %% a player would get if killer would kill
// a monster
int CalculateShareXP(object pl,object killer)
{
  object leader;
  object *members;
  int i,here,away,pool,share,nets,size;
  leader=({object})pl->Query(P_PARTY);
  if (!leader) return 0;
  members=(({object *})leader->Query(P_PARTY_MEMBERS)||({}))-({0});
  size=sizeof(members);
  if (size==0) return 0;

  if (({int})pl->QueryNetdead()) return 0;

  here=0;
  for (i=0;i<size;i++)
  {
    if (({int})members[i]->QueryNetdead())
    {
      nets++;
    }
    else
    {
      if (environment(killer)==environment(members[i])) here++;
    }
  }
  size-=nets;             // do not count netdeads
  if (size<=0) return 0;

  away=size-here;         // how many are not present

  share = 1000 /size;     // share of XP in %%

  pool= away * (9*share/10);    // not present ppl have to give away XP

  if (environment(pl)==environment(killer))  // if pl is here
  {
    share+= pool/here;
  }
  else
  {
    share-= pool/away;
  }

  return share;
}


// Can a player join the party
int CanJoin(object pl,object leader)
{
  object *members;
  int i,lev,diff;
  if (!leader) return 0;
  members=(({object *})leader->Query(P_PARTY_MEMBERS)||({}))-({0});
  lev=({int})pl->QueryLevel();
  for (i=0;i<sizeof(members);i++)
  {
     diff=({int})members[i]->QueryLevel()-lev;
     if (diff>PARTY_LEVEL_DIFFERENCE ||
         diff<-PARTY_LEVEL_DIFFERENCE) return 0;
  }
  return 1;
}

// gives out a message over the party channel (status,emote,tell)
void PartyChannel(string str,int flag)
{
  object leader;
  object *members;
  string s;
  leader=({object})TP->Query(P_PARTY);
  if (!leader) return;
  members=(({object *})leader->Query(P_PARTY_MEMBERS)||({}))-({0});

  switch(flag)
  {
    case PARTY_MSG_STATUS:
       s="["+(({string})leader->Query(P_PARTY_NAME)||"party")+"] "+
        (str||"Nothing")+"\n";
    break;
    case PARTY_MSG_EMOTE:
       s="["+(({string})leader->Query(P_PARTY_NAME)||"party")+": "+
         capitalize(({string})TP->QueryRealName())+" "+str+"]"+"\n";
    break;
    case PARTY_MSG_SHOUT:
       s="["+(({string})leader->Query(P_PARTY_NAME)||"party")+": "+
         capitalize(({string})TP->QueryRealName())+"] "+str+"\n";
    break;
  }
  filter(members, #'msg_object /*'*/, CMSG_GENERIC, s );
}

// Clear all party properties for pl
int dismiss(object pl)
{
  object ob;
  if (!pl) return 0;
  pl->Set(P_PARTY,0);
  pl->Set(P_PARTY_APPLIED,0);
  pl->Set(P_PARTY_XP_SHARE,0);
  ob=({object})pl->Query(P_PARTY_PROTECTING);
  if (ob) ob->Set(P_PARTY_PROTECTED,0);
  ob=({object})pl->Query(P_PARTY_PROTECTED);
  if (ob) ob->Set(P_PARTY_PROTECTING,0);
  pl->Set(P_PARTY_PROTECTING,0);
  pl->Set(P_PARTY_PROTECTED,0);
  return 1;
}

// party emote
int cmd_pemote(string arg)
{
  if (!({object})TP->Query(P_PARTY))
  {
    return notify_fail("You are not member of any party.\n");
  }
  PartyChannel(arg,PARTY_MSG_EMOTE);
  return 1;
}
// party shout
int cmd_ptell(string arg)
{
  if (!({object})TP->Query(P_PARTY))
  {
    return notify_fail("You are not member of any party.\n");
  }
  PartyChannel(arg,PARTY_MSG_SHOUT);
  return 1;
}


// Produces statistical information about the party like this
// Leader Softbyte000 (12) paladin     1234 1234 1234567 (20%)  softbyte000
string PartyScore()
{
  string s,prot,rank;
  object leader,ob,pob, *members;
  int i;

  if (!(leader=({object})TP->Query(P_PARTY)))
  {
    return "You are not member of any party.\n";
  }
  members=(({object *})leader->Query(P_PARTY_MEMBERS)||({}))-({0});
  members-=({0});
  if (!members ||!sizeof(members)) // corrupt party
  {
    TP->Set(P_PARTY,0);
    return "Strange, you seem to be no member of a party.\n";
  }
  if (-1==member(members,TP))
  {
    TP->Set(P_PARTY,0);
	  return "Seems you have left the party.\n";
  }
  s=({string})SLIB->mkstr(75,"-")+"\n";
  s+=({string})SLIB->cadjust("+++++ "+(({string})leader->Query(P_PARTY_NAME)||"Noname")+
      " +++++",75)+"\n";
  s+=sprintf(
       "Party XP: %-6d     Killed Monster: %-3d    Time: %s\n",
          ({int})leader->Query(P_PARTY_XP),({int})leader->Query(P_PARTY_KILLS),
          GetTimeDiff(time(),({int})leader->Query(P_PARTY_TIME)));
  s+="\n";
  s+=sprintf(
   " %-7.7s %-11.11s %-4.4s %-11.11s %-4.4s %-4.4s %-5.5s %-6.6s  %-11.11s\n",
              "","Name","Lvl","Guild"," HP"," SP","   XP","Share",
			  "Protecting");

  for (i=0;i<sizeof(members);i++)
  {
    ob=members[i];
	  if (ob)
    {
      if (pob=({object})ob->Query(P_PARTY_PROTECTING))
      {
        prot=({string})pob->QueryRealName()||({string})pob->QueryName()||({string})pob->QueryShort()||
		       "Someone";
		  }
      else
        prot="Nobody";
      if (({int})members[i]->QueryNetdead())
        rank="Netdead";
      else if (({object})TP->Query(P_PARTY)==members[i])
        rank="Leader";
      else rank="";
        s+=sprintf(
       " %-7.7s %-11.11s %-4.4s %-11.11s %4.4d %4.4d %5.5d %6.6s  %-11.11s\n",
		     rank,
		     capitalize(({string})ob->QueryRealName()),
		     "("+to_string(({int})ob->QueryLevel())+")",
			 capitalize(({string})ob->QueryGuild()||"None"),
			 ({int})ob->QueryHP(),({int})ob->QuerySP(),({int})ob->Query(P_PARTY_XP_SHARE),
			 "("+to_string(CalculateShareXP(ob,TP)/10)+"%)",
			 capitalize(prot));
    }
  }
  s+=({string})SLIB->mkstr(75,"-")+"\n";
  return s;
}
// command for the party statisticl information
int cmd_pstat(string arg)
{
  if (arg) return notify_fail("No argument possible.\n"),0;
  msg_write( CMSG_GENERIC, PartyScore());
  return 1;
}
void MakeNewleader(object ob,object leader)
{
  if (({object})ob->Query(P_PARTY)) ob->Set(P_PARTY,leader);
}
// The party gets a new leader
int NewLeader(object newleader,object oldleader)
{
  object *members;
  PartyChannel(capitalize(({string})newleader->QueryRealName())+
     " is new leader of the party.", PARTY_MSG_STATUS);
  members=(({object *})oldleader->Query(P_PARTY_MEMBERS)||({}))-({0});
  newleader->Set(P_PARTY_MEMBERS,members);
  oldleader->Set(P_PARTY_MEMBERS,0);
  filter(members,#'MakeNewleader /*'*/,newleader);
  newleader->Set(P_PARTY_NAME,oldleader->Query(P_PARTY_NAME));
  oldleader->Set(P_PARTY_NAME,0);
  newleader->Set(P_PARTY_XP,oldleader->Query(P_PARTY_XP));
  oldleader->Set(P_PARTY_XP,0);
  newleader->Set(P_PARTY_KILLS,oldleader->Query(P_PARTY_KILLS));
  oldleader->Set(P_PARTY_KILLS,0);
  newleader->Set(P_PARTY_TIME,oldleader->Query(P_PARTY_TIME));
  oldleader->Set(P_PARTY_TIME,0);
  return 1;
}

// You left the party
int PartyLeave(object pl,object leader)
{
  object *members;
  PartyChannel(capitalize(({string})pl->QueryRealName())+" has left the party.",
              PARTY_MSG_STATUS);
  members=(({object *})leader->Query(P_PARTY_MEMBERS)||({}))-({0});
  members-=({pl});

  /* Leader left party */
  if (leader==pl)
  {
    if (sizeof(members)>0)
    {
      leader=members[0];
      // Set new leader
      NewLeader(leader,pl);
    }
    else
    {
      leader=0;
      PartyChannel("The party dissolves.",PARTY_MSG_STATUS);
    }
  }
  if (leader) leader->Set(P_PARTY_MEMBERS,members);
  dismiss(pl);  // throw pl out of the party
  return 1;
}

// Choose a new leader of the party
int cmd_leader(string arg)
{
  object ob;
  if (!arg) return notify_fail(
      "Who should become the new leader of the party.\n");
  if (TP!=({object})TP->Query(P_PARTY)) return notify_fail(
      "You are not leader of a party.\n");
  ob=find_player(arg);
  if (!ob || -1==member(({object *})TP->Query(P_PARTY_MEMBERS),ob) )
     return notify_fail(
       capitalize(arg)+" is no member of your party.\n");
  if (ob==TP) return notify_fail(
    "Quit funny, indeed.\n");
  NewLeader(ob,TP);
  return 1;
}

// apply to someones party, supposed he/she is a leader
int cmd_apply(string arg)
{
  object ob;
  if (!arg) return notify_fail("Apply to whose party?\n");
  if (({object})TP->Query(P_PARTY)) return notify_fail(
    "You are already member of a party. Type 'party leave' to leave it.\n");
  ob=present(arg,environment(TP));
  if (!ob || ({int})ob->Query(P_INVIS))
    return notify_fail(capitalize(arg)+" is not here.\n");
  if (ob==TP) return notify_fail(
    "Quit funny, indeed.\n");
  if (ob!=({object})ob->Query(P_PARTY) || !living(ob) )
  {
    return notify_fail(capitalize(arg)+" is no leader of a party.\n");
  }
  if (!CanJoin(TP,ob))
  {
    return notify_fail(
    "You cannot join the party. Your level must not differ more than "+
    to_string(PARTY_LEVEL_DIFFERENCE)+" levels from any member.\n"),0;
  }
  msg_object(ob, CMSG_GENERIC, capitalize(({string})TP->QueryRealName())+
      " applies to your party. Type 'recruit "+({string})TP->QueryRealName()+
      "' to accept "+({string})TP->QueryObjective()+".\n");
  msg_write( CMSG_GENERIC,"You apply to the '"+(({string})ob->Query(P_PARTY_NAME)||"Noname")+
     "' party.\n");
  TP->Set(P_PARTY_APPLIED,ob);
  return 1;
}

// take a new member in the party if it applied
int cmd_recruit(string arg)
{
  object ob;
  object *members;
  if (!arg) return notify_fail("Recruit whom?\n"),0;
  ob=present(arg,environment(TP));
  if (!ob || ({int})ob->Query(P_INVIS))
    return notify_fail(capitalize(arg)+" is not here.\n"),0;
  if (ob==TP) return notify_fail(
    "Quit funny, indeed.\n");
  if (TP!=({object})TP->Query(P_PARTY))
  {
    return notify_fail("You are no leader of a party.\n"),0;
  }
  if (TP!=({object})ob->Query(P_PARTY_APPLIED) || !living(ob) )
  {
    return notify_fail(capitalize(arg)+" has not applied to you.\n"),0;
  }
  if (({object})ob->Query(P_PARTY))
  {
    return notify_fail(capitalize(({string})TP->QueryName())+
        " is already member of a party.\n"),0;
  }
  members=(({object *})TP->Query(P_PARTY_MEMBERS)||({}))-({0});
  members+=({ob});
  TP->Set(P_PARTY_MEMBERS,members);
  dismiss(ob); // reset party
  ob->Set(P_PARTY,TP);

  PartyChannel(capitalize(({string})ob->QueryRealName())+
     " has joined the party.", PARTY_MSG_STATUS);
  return 1;
}

// List all parties
int cmd_pwho(string arg)
{
  object *usr;
  string *members;
  object ob;
  int i,j;
  string s;
  usr=users();
  s="Parties in OSB:\n";
  for (i=0;i<sizeof(usr);i++)
  {
    ob=usr[i];
    if (ob==({object})ob->Query(P_PARTY))  // leader
    {
       s+=sprintf(" + '%s' led by %s\n",
         ({string})ob->Query(P_PARTY_NAME)||"Noname",
         capitalize(({string})ob->QueryName()||"Someone"));
         members=(({object *})ob->Query(P_PARTY_MEMBERS)||({}))-({0});
         for (j=0;j<sizeof(members);j++)
         {
           if (!({int})members[j]->Query(P_INVIS))
             s+=sprintf("    - %s\n",capitalize(({string})members[j]->QueryName()));
         }

    }
  }
  msg_write( CMSG_GENERIC,s);
  return 1;
}

// open a party and become its leader
int cmd_partyon(string arg)
{
  object ob;
  ob=({object})TP->Query(P_PARTY);

  if (!arg)
  {
    if (ob)
    {
      msg_write( CMSG_GENERIC,
                 "You are member of the '"+(({string})ob->Query(P_PARTY_NAME)||"Noname")+
                 "' party.\n");
    }
    else
    {
      msg_write( CMSG_GENERIC, "You are not member of any party.\n");
    }
    return 1;
  }
  if (arg=="who") return cmd_pwho(0);
  if (ob)
  {
    if (arg=="leave" || arg=="abandon")
    {
      PartyLeave(TP,ob);
    }
    else if (arg=="disband")
    {
      if (TP!=({object})TP->Query(P_PARTY))
      {
        return notify_fail("You are not leader of the party.\n");
      }
      PartyChannel(capitalize(({string})TP->QueryRealName())+" disbands the party.",
        PARTY_MSG_STATUS);
      filter(({object *})TP->Query(P_PARTY_MEMBERS),#'dismiss /*'*/);
      TP->Set(P_PARTY_MEMBERS,0);
      TP->Set(P_PARTY_NAME,0);
      TP->Set(P_PARTY_TIME,0);
      TP->Set(P_PARTY_KILLS,0);
      TP->Set(P_PARTY_XP,0);
    }
    else
    {
      return notify_fail(
        "You are already member of a party. Use 'party leave' to leave it.\n");
    }
    return 1;
  }
  if (arg=="leave" || arg=="abandon")
  {
    return notify_fail(
      "You are not member of any party.\n");
  }
  msg_write( CMSG_GENERIC, "You open the party '"+arg+"'.\n");
  dismiss(TP);
  TP->Set(P_PARTY,TP);
  TP->Set(P_PARTY_NAME,arg);
  TP->Set(P_PARTY_MEMBERS,({TP}));
  TP->Set(P_PARTY_XP,0);
  TP->Set(P_PARTY_KILLS,0);
  TP->Set(P_PARTY_TIME,time());
  return 1;
}
// Throws a member out of the party
int cmd_dismiss(string arg)
{
  object ob;
  object *members;
  if (!arg) return notify_fail("Throw whom out of the party?\n");
  if (TP!=({object})TP->Query(P_PARTY))
  {
    return notify_fail("You are no leader of a party.\n");
  }
  ob=find_player(arg);
  members=(({object *})TP->Query(P_PARTY_MEMBERS)||({}))-({0});
  if (!ob || (-1==member(members,ob)) )
    return notify_fail(
      capitalize(arg)+" is no member of your party.\n");
  if (TP==ob) return notify_fail(
   "Use 'party leave' to leave the party.\n");
  PartyChannel(capitalize(({string})TP->QueryRealName())+" has thrown "+
    capitalize(({string})ob->QueryRealName())+" out of the party.",PARTY_MSG_STATUS);
  members-=({ob});
  TP->Set(P_PARTY_MEMBERS,members);
  dismiss(ob);

  return 1;
}
// Change the name of the party
int cmd_pname(string arg)
{
  if (!arg) return notify_fail("Change the name to what?\n"),0;
  if (TP!=({object})TP->Query(P_PARTY))
  {
    return notify_fail("You are no leader of a party.\n"),0;
  }
  PartyChannel(capitalize(({string})TP->QueryRealName())+" changed the name of "+
   "the party to '"+arg+"'.",PARTY_MSG_STATUS);
  TP->Set(P_PARTY_NAME,arg);
  return 1;
}

// Protect another player
int cmd_protect(string arg)
{
  object ob,leader,tob;
  object *members;
  if (!arg) return notify_fail("Protect whom?\n"),0;
  leader=({object})TP->Query(P_PARTY);
  if (!leader) return notify_fail(
    "You are not member of any party.\n");
  members=(({object *})leader->Query(P_PARTY_MEMBERS)||({}))-({0});

  ob=present(arg,environment(TP));
  if (!ob || (-1==member(members,ob)) )
    return notify_fail(
      capitalize(arg)+" is not here or no member of your party.\n");
  if (ob==TP) return notify_fail(
    "Quit funny, indeed.\n");
  msg_object(ob, CMSG_GENERIC, "You are now protected by "+
     capitalize(({string})TP->QueryRealName())+".\n");
  msg_write( CMSG_GENERIC,"You protect "+capitalize(({string})ob->QueryRealName())+".\n");
  tob=({object})TP->Query(P_PARTY_PROTECTING);
  if (tob) tob->Set(P_PARTY_PROTECTED,0);
  tob=({object})ob->Query(P_PARTY_PROTECTED);
  if (tob) tob->Set(P_PARTY_PROTECTING,0);
  TP->Set(P_PARTY_PROTECTING,ob);
  ob->Set(P_PARTY_PROTECTED,TP);
  return 1;
}

// Process the incoming commands
int cmd_party(string arg)
{
  switch(query_verb())
  {
    case "party": return cmd_partyon(arg);
    break;
    case "pstat": return cmd_pstat(arg);
    break;
    case "apply": return cmd_apply(arg);
    break;
    case "recruit": return cmd_recruit(arg);
    break;
    case "leader": return cmd_leader(arg);
    break;
    case "pemote": return cmd_pemote(arg);
    break;
    case "ptell": return cmd_ptell(arg);
    break;
    case "pname": return cmd_pname(arg);
    break;
    case "dismiss": return cmd_dismiss(arg);
    break;
    case "protect": return cmd_protect(arg);
    break;
    default: return notify_fail("Unknown party command.\n");
  }
  return notify_fail("Unknown party command.\n");
}

// ------------ Calls from std/player ----------------------

// arg=-1: quit, arg=0: revive, arg=1: netdead
varargs void PlayerNetdead(int arg, object pl )
{
  object leader;
  object *members;

  if ( ! pl )
    return; /* just in case of an invalid call */

  leader=({object})pl->Query(P_PARTY);
  if (leader && arg==-1) PartyLeave(pl,leader);
  if (leader==pl && arg==1)
  {
    members=(({object *})leader->Query(P_PARTY_MEMBERS)||({}))-({0});
    members-=({pl});
    if (sizeof(members)>0) NewLeader(members[0],leader);
  }
}

// spread the XP onto the party
int PartyXP(int xp,object leader)
{
  int txp,i,notspent,share;
  object *members;
  if (!leader) return xp;
  members=(({object *})leader->Query(P_PARTY_MEMBERS)||({}))-({0});
  notspent=xp;
  for (i=0;i<sizeof(members);i++)
  {
    share=CalculateShareXP(members[i],TP)*xp/1000;
    notspent-=share;
    members[i]->AddXP(share);
    txp=({int})members[i]->Query(P_PARTY_XP_SHARE);
    members[i]->Set(P_PARTY_XP_SHARE,txp+share);
  }
  // give the rest to the leader or to the killer ?
  if (notspent>0)
  {
    TP->AddXP(notspent);
    txp=({int})TP->Query(P_PARTY_XP_SHARE);
    TP->Set(P_PARTY_XP_SHARE,txp+notspent);
    notspent=0;
  }
  txp=({int})leader->Query(P_PARTY_XP);
  leader->Set(P_PARTY_XP,txp+xp-notspent);

  return notspent;
}

// Increase the party kills
int PartyKills(object leader)
{
  int kills;
  if (!leader) return 0;
  kills=({int})leader->Query(P_PARTY_KILLS);
  leader->Set(P_PARTY_KILLS,kills+1);
  PartyChannel(capitalize(({string})TP->QueryRealName())+ " has killed "+
    (({string})PO->QueryName()||({string})PO->QueryShort()||"Someone"), PARTY_MSG_STATUS);
  return kills+1;
}
