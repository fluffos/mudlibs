/*
** /std/guild/member
** The handling of the members
**
**   10feb95 [t] Creation
**   11mar96 [t] Toplist Handling changed due to too long evaluations
**   26apr97 [e] Introduction of guild maintainers
**
** [e] Eilan
** [t] Thragor
*/

#include <guild.h> // MEMBER_STAT, ....
#include <config.h> // QUESTMASTER, EXPLOREMASTER
#include <secure/wizlevels.h> // IS_LEARNER

#define STR "/obj/lib/string"
#define ME this_object()
#define PD "/obj/player_dummy"

#define T_QP 0
#define T_XP 1
#define T_AGE 2
#define T_RACE 3
#define T_TITLE 4
#define T_LEVEL 5

#define T_SIZE 6

#define TOP_MEMBER "member"
#define TOP_QP "questpoints"
#define TOP_PLDATA "playerdata"
#define TOP_FUN "fun"
#define TOP_TODO "todo"
#define TOP_RESULT "result"

#define HBINT 2 // interval between two heart_beats in seconds

#define SF(x) #'x //'
#define SYM(x) 'x //'

public mapping members; // ([string name:int time of entering;int level;
                        //   string stat;string *msgs;mixed extra])
private nosave string *creators,    // the creators of this guild
                      *maintainers,// the one who keep the guild running
                      guildfile,    // where to save the guilddata
                      *Ptoplist;    // Toplist updated every reset
private nosave status load_force;   // especially needed for the adventurer
                                    // guild, because several guilds are
                                    // using the same save-file and all
                                    // need to be updated everytime.
private nosave int updated; // time when toplist got last updated

protected string dtime(int time)
// return the time in hours
{
  return to_string(time/(60*60));
}

/*
* ----------------------------------------------------------------------
* Queries, Settings, Adds
* ----------------------------------------------------------------------
*/

public string SetGuildfile(string fn)
// If the data of the guild shall be saved somewhere else (and not
// to the default filename, i. e. the path of the guild plus the
// extension ".o") then specify the guildfile.
// This is needed, if you have the guild in /d/<domain>/<wizard>/,
// because the guild can only write to /d/<domain>/common.
{
  return guildfile = fn;
}

public string QueryGuildfile()
{
  return guildfile;
}

public string *SetCreators(mixed cr)
// cr might be a string or an array of strings, i. e. you might
// specify one or several creators. The creators will appear in
// the who-list of the guild.
{
  int i;
  if (stringp(cr)) cr = ({cr});
  cr-=({0});
  for (i=0;i<sizeof(cr);i++)
    cr[i]=lower_case(cr[i]);
  return creators = cr;
}

public mixed QueryCreators()
{
  return (creators||({}))+({});
}


public string *SetMaintainers(mixed mt)
// mt might be a string or an array of strings, i. e. you might
// specify one or several maintainer. He/She will appear in
// the who-list of the guild.
{
  int i;
  if (stringp(mt)) mt = ({mt});
  mt-=({0});
  for (i=0;i<sizeof(mt);i++)
    mt[i]=lower_case(mt[i]);
  return maintainers = mt;
}

public string *SetMaintenancers(mixed mt)
{
  log_file("guilds/maintainer.log","Illegal call SetMaintenancer called from"+
    blueprint(this_object())+" on "+ctime()+" \n");
  return SetMaintainers(mt);
}

public mixed QueryMaintainers()
{
  return (maintainers||({}))+({});
}

/* List of all members including creators and maintainers */
public string *QueryMemberList()
{
string *m;
  m=m_indices(members||([]))-({});
  m=m-QueryCreators();
  m=m-QueryMaintainers();
  m=m+QueryCreators()+(QueryMaintainers()-QueryCreators());
  return m||({});
}


public string *SetTopList(string *tl)
{
  return Ptoplist = tl;
}

public string *QueryTopList()
{
  return (Ptoplist||({}))+({});
}

public varargs void LoadGuild(int force)
// Load all data for this guild from the given savefile
{
  if (members&&!force&&!load_force)
    return;  // if the data are already loaded and if
             // I'm not force to load, skip (saves time)
  if (!guildfile) guildfile = blueprint(ME);
  if (file_size(guildfile+".o")>0)
    restore_object(guildfile);
}

public void SaveGuild()
// Save all data for this guild in the given savefile
{
  if (!guildfile) guildfile = blueprint(ME);
  save_object(guildfile);
}

/*
* Status checks of players concerning the guild
* =============================================
*/

public int is_creator(mixed who)
// return 1 if <who> is one of the creators of this guild
// -> SetCreator()
{
  if (objectp(who)) who = getuid(who);
  return member(creators||({}),lower_case(who||""))!=-1;
}
public int is_maintainer(mixed who)
// return 1 if <who> is one of the maintainer of this guild
// -> SetMaintainer()
{
  if (objectp(who)) who = getuid(who);
  return member(maintainers||({}),lower_case(who||""))!=-1;
}


public int is_leader(mixed who)
// return 1 if <who> is one of the guildleaders of this guild
// (because this is used to check rights: the creator is a leader, too
// -> QueryGuildleader(), QueryViceGuildleader(), ChangeStat()
{
  LoadGuild();
  if (!members) return 0;
  if (objectp(who)) who = getuid(who);
  return (members[who,MEMBER_STAT]==G_LEADER
         ||members[who,MEMBER_STAT]==G_VICELEADER)||is_creator(who)
		 ||is_maintainer(who);
}

public int is_member(mixed who)
// return 1 if <who> is a member of this guild
// the creators are automatically members of this guild
// -> AddMember()
{
  LoadGuild();
  if (!members) return 0;
  if (objectp(who)) who = getuid(who);
  return (members[who,MEMBER_STAT]==G_MEMBER)||is_leader(who);
}

public int check_member(object who)
// check if <who> is a valid member of this guild
{
  if (!who) return 0;
  if (!interactive(who)) return 0;
  return is_member(getuid(who));
}

public string MemberList()
{
  int i;
  string *m,result;
  string tmp;
  int m1,c1;

  m = sort_array(QueryMemberList() ,SF(>));
  result = sprintf("%|11s|%|14s|%|5s|%|24s\n"
		   "%'-'11s+%'-'14s+%'-'5s+%'-'24s\n",
		   "Name","Status","Level","Last time in guild",
		   "","","","");
  for (i=0;i<sizeof(m);i++)
  {
    m1=is_maintainer(m[i]);
	c1=is_creator(m[i]);
    if ( IS_IMMORTAL(m[i]) || c1 || m1)
	{
	  if (c1&&m1) tmp="main/creator";
	  else if (c1) tmp="creator";
	  else if (m1) tmp="maintainer";
	  else tmp="wizard";
	}
	else
	{
	  if (members[m[i],MEMBER_STAT]==G_LEADER) tmp="leader";
	  else if (members[m[i],MEMBER_STAT]==G_VICELEADER) tmp="viceleader";
	  else tmp="member";
	}

    result+=sprintf("%-11s|%|14s|%5s|%24s\n",
		    capitalize(m[i]),tmp,
		    ( IS_IMMORTAL(m[i])
		      ? "---"
		      : to_string(members[m[i],MEMBER_LEVEL])
            ),
		    ctime(members[m[i],MEMBER_TIME])
		   );
  }
  return result;
}

/*
* TopScorelist related help-funs
* ==============================
*/

protected int compare_values(int val1,int val2)
// Return
//  -1 if both are equal
//   1 if val1<val2
//   0 if val1>val2
{
  return (val1!=val2?(val1<val2?1:0):-1);
}

public int check_greater(string n1,string n2,mapping values)
// This function is used to detect the Top-Player by
// comparing the stats of player <n1> and player <n2>
// <n1> is in front of <n2>, if
// 1. <n1> has more QP, or
// 2. <n1> has mor Explorer-Points, or
// 3. <n1> has more XP, or
// 4. <n1> is of a higher level, or
// 5. <n1> is less old than <n2>, or
// 6. <n1>, <n2> alphabetically sorted
// The order gives the ranking of checks. If the first
// check allready may give an order, the others are skipped.
// otherwise it will be checked until a difference is found
// between <n1> and <n2>
{
  int i;
  return ((i = compare_values(values[n1,T_QP],values[n2,T_QP]))!=-1)
    ?i
    :((i = compare_values(values[n1,T_XP],values[n2,T_XP]))!=-1)
    ?i
    :((i = compare_values(values[n1,T_AGE],values[n2,T_AGE]))!=-1)
    ?i
    :n1>n2;
}

public mixed sort_mapping(mapping to_sort,closure sort_fun)
     // Returns the sorted indizes of the mapping.
     // The sort-fun will get the two indizes to compare and the
     // mapping to_sort itself to return 1, if the first arg is
     // greater than arg 2 and else 0.
{
  mixed idx;
  idx = m_indices(to_sort);
  idx = sort_array(idx,lambda(({SYM(a1),SYM(a2)}),
			      ({sort_fun,SYM(a1),SYM(a2),to_sort})));
  return idx;
}

private void init_vals(string pl,int xp,int age,int level,
		       string race,string title)
{
  mapping props;
  props = ({mapping})PD->QueryProperties(pl);
  xp = props[P_XP];
  age = props["Age"]*HBINT;
  race = props[P_RACE];
  title = props[P_TITLE];
  level = props[P_LEVEL];
}

private string create_topscore_line(string pl,mapping mpl,string *idx)
{
  int i;
  i = member(idx,pl)+1;
  return ({string})STR->wrap(
		   ({string})STR->radjust(to_string(i),3)+". "+
		   ({string})STR->ladjust(capitalize(pl),11,".")+
		   " "+({string})STR->radjust(to_string(mpl[pl,T_LEVEL]),5,".")+" "+
		   ({string})STR->radjust(dtime(mpl[pl,T_AGE]),5,".")+" "+
		   ({string})STR->ladjcut(capitalize(mpl[pl,T_RACE]||""),10,".")+" "+
		   mpl[pl,T_TITLE],74,40);
}

private int is_testy(string str)
{
  return ({mixed})"/obj/testylib"->CheckTesty(str);
}

public varargs void update_toplist(int topstate,mapping data)
{
  mixed help;
  int i;
  while(remove_call_out(SF(update_toplist))!=-1);
  LoadGuild();
  data = data||([]);
  switch(topstate)
    {
    case 0:
      help = m_indices(members||([]));
      help-= filter(help,SF(query_user_level));
      help-= filter(help,SF(is_testy));
      data[TOP_MEMBER] = help;
      break;
    case 1:
      if (!member(data,TOP_FUN))
        data[TOP_FUN] = symbol_function("QueryQuestPoints",QUESTMASTER);
      if (!member(data,TOP_TODO))
        data[TOP_TODO] = data[TOP_MEMBER]+({});
      help = data[TOP_TODO][0..49];
      data[TOP_RESULT] = (data[TOP_RESULT]||({}))+map(help,data[TOP_FUN]);
      if (sizeof(help)<sizeof(data[TOP_TODO]))
	{
	  data[TOP_TODO] = data[TOP_TODO]-help;
	  call_out(SF(update_toplist),1,topstate,data);
	  return;
	}
      m_delete(data,TOP_FUN);
      m_delete(data,TOP_TODO);
      data[TOP_QP] = mkmapping(data[TOP_MEMBER],data[TOP_RESULT]);
      m_delete(data,TOP_RESULT);
      break;
    case 2:
      if (!member(data,TOP_RESULT))
	data[TOP_RESULT] = m_allocate(0,T_SIZE);
      if (!member(data,TOP_TODO))
        data[TOP_TODO] = data[TOP_MEMBER]+({});
      help = data[TOP_TODO][0..24];
      for(i=0;i<sizeof(help);i++)
	{
	  int xp,age,level;
	  string race,title;
	  init_vals(help[i],&xp,&age,&level,&race,&title);
	  data[TOP_RESULT][help[i],T_QP] = data[TOP_QP][help[i]];
	  data[TOP_RESULT][help[i],T_XP] = xp;
	  data[TOP_RESULT][help[i],T_AGE] = age;
	  data[TOP_RESULT][help[i],T_RACE] = race;
	  data[TOP_RESULT][help[i],T_TITLE] = title;
	  data[TOP_RESULT][help[i],T_LEVEL] = level;
	}
      if (sizeof(help)<sizeof(data[TOP_TODO]))
	{
	  data[TOP_TODO] = data[TOP_TODO]-help;
	  call_out(SF(update_toplist),1,topstate,data);
	  return;
	}
      m_delete(data,TOP_TODO);
      data[TOP_PLDATA] = data[TOP_RESULT];
      m_delete(data,TOP_RESULT);
      m_delete(data,TOP_MEMBER);
      break;
    case 3:
      data[TOP_RESULT] = sort_mapping(data[TOP_PLDATA],SF(check_greater));
      break;
    case 4:
      help = map(data[TOP_RESULT],SF(create_topscore_line),
		       data[TOP_PLDATA],data[TOP_RESULT]);
      SetTopList(help);
      updated = time();
      return;
    }
  ++topstate;
  call_out(SF(update_toplist),2,topstate,data);
}

public varargs string toplist(int size)
// returns the Top20-Players
{
  string txt,*tl;
  int i;
  if (!size) size = 19;
  if (!i = sizeof(tl = QueryTopList()))
    return updated?"The list is empty.\n":"Toplist is currently updating.\n";
  txt =  ({string})STR->cadjust("Top list of the "+(({string})ME->QueryGuildname()||"guild")+" ("+
		      to_string(i)+" member"
		      +(i==1?"":"s")+")",75)+"\n\n"+
    "     Name        Level Hours Race       Title\n"+
    ({string})STR->mkstr(75,"-")+"\n";
  txt+=implode(tl[0..size],"\n")+"\n";
  txt+="\n  Last updated: "+ctime(updated)+".\n";
  return txt;
}


/*
* Member
* ======
* ([string name:int time of entering;int level;string stat;string *msgs])
*/

public mapping SetMembers(mapping m)
// Set the mapping of members. 'Design' see above
{
  if (!mappingp(m)) return members||([]);
  members = m;
  SaveGuild();
  return members;
}

public mapping QueryMembers()
{
  LoadGuild();
  return members||([]);
}

public mapping AddMember(string name,
                         int level,
                         string stat)
// Add a member to the guild. If the member already exists, (s)he won't
// be added. The 'time'-entry will be set to the current time and the
// 'msgs' to an empty array.
{
  LoadGuild();
  if (!name) return members||([]);
  if (member(members||([]),name)) return members||([]);
  if (!members) members = m_allocate(0,MEMBER_ENTRIES);
  members[name,MEMBER_TIME]=time();
  members[name,MEMBER_LEVEL]=level;
  members[name,MEMBER_STAT]=stat;
  members[name,MEMBER_MSGS]=({});
  members[name,MEMBER_EXTRA]=0; // undefined
  SaveGuild();
  return members;
}

public mapping RemoveMember(string name)
// Remove a member from the guild and inform us. ("InformRemove")
{
  string h;
  LoadGuild();
  if (!name||!members) return members||([]);
  if (!is_member(name)) return members;
  if ((name == ({string})ME->QueryGuildleader())&&(h=({string})ME->QueryViceGuildleader()))
    ME->ChangeStat(h,G_LEADER);
  ME->InformRemove(name);
  m_delete(members,name);
  SaveGuild();
  return members;
}

public void SetExtraInfo(string name,mixed extra)
{
  LoadGuild();
  if (!name||!members) return;
  if (!member(members,name)) return;
  members[name,MEMBER_EXTRA]=extra;
  SaveGuild();
}

public mixed QueryExtraInfo(string name)
{
  LoadGuild();
  if (!name||!members) return 0;
  if (!member(members,name)) return 0;
  return members[name,MEMBER_EXTRA];
}

public void ChangeStat(string name,string stat)
// Change the status of a member (e. g. from member to guildleader)
{
  LoadGuild();
  if (!name||!members) return;
  if (!member(members,name)) return;
  members[name,MEMBER_STAT]=stat;
  SaveGuild();
}

public string QueryStat(string name)
// Return the status of a member
{
  LoadGuild();
  if (!name||!members) return 0;
  if (!member(members,name)) return 0;
  return members[name,MEMBER_STAT];
}

public string QueryGuildleader()
// Return the Guildleader of the guild; 0 if there's no leader
{
  mixed  leader;
  LoadGuild();
  leader = filter(m_indices(members||([])),
            lambda(({SYM(n)}),
                   ({SF(==),({SF(QueryStat),SYM(n)}),G_LEADER})));
  if (!sizeof(leader)) return 0;
  return leader[0];
}

public string QueryViceGuildleader()
// Return the Vice-Guildleader of the guild; 0 if there's no vice-leader
{
  mixed  leader;
  LoadGuild();
  leader = filter(m_indices(members||([])),
            lambda(({SYM(n)}),
                   ({SF(==),({SF(QueryStat),SYM(n)}),
                               G_VICELEADER})));
  if (!sizeof(leader)) return 0;
  return leader[0];
}

public void ChangeLevel(string name,int level)
// Change the level of a member
{
  LoadGuild();
  if (!name||!members) return;
  if (!member(members,name)) return;
  members[name,MEMBER_LEVEL]=level;
  SaveGuild();
}

public int QueryLevel(string name)
// Return the level of a member
{
  LoadGuild();
  if (!name||!members) return 0;
  if (!member(members,name)) return 0;
  return members[name,MEMBER_LEVEL];
}

public void UpdateTime(string name)
// Update the enter-time of a member to the current time
{
  LoadGuild();
  if (!name||!members) return 0;
  if (!member(members,name)) return 0;
  members[name,MEMBER_TIME]=time();
  SaveGuild();
}

public int QueryTime(string name)
// return the time when the member last entered
{
  LoadGuild();
  if (!name||!members) return 0;
  if (!member(members,name)) return 0;
  return members[name,MEMBER_TIME];
}

public void AddMessage(string name,string *msg)
// Add a message to the messages of a member
{
  LoadGuild();
  if (!name||!members) return;
  if (!member(members,name)) return;
  if (!members[name,MEMBER_MSGS])
    members[name,MEMBER_MSGS]=({msg});
  else
    members[name,MEMBER_MSGS]+=({msg});
  SaveGuild();
}

public void RemoveMessage(string name,string *msg)
// Remove a message
{
  LoadGuild();
  if (!name||!members) return;
  if (!member(members,name)) return;
  if (!members[name,MEMBER_MSGS]) return;
  members[name,MEMBER_MSGS]-=({msg});
  SaveGuild();
}

public void RemoveMessages(string name)
// Remove all messages
{
  LoadGuild();
  if (!name||!members) return;
  if (!member(members,name)) return;
  members[name,MEMBER_MSGS]=({});
  SaveGuild();
}

public status SetLoadForce(int i)
// especially in the adventurer guild, the guilds need to be forced to
// update the guild-data everytime.
{
  return load_force = i;
}

public status QueryLoadForce()
{
  return load_force;
}
