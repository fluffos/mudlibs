/*
** The std-guildobject
** You may inherit this in addition to /std/thing, /std/weapon, etc.
** to get a guildobject fully compatible to the /std/guild.
**
** It implements three functions which may be added to the guildobject
** via add_action(<function>,<command>):
** cmd_gwho - show all guildmembers (and the creator) who are online
**            Invis Players won't be shown.
** cmd_gshout - sp-free shout to all guildmembers;
**              Earmuffs and Ignored are checked
** cmd_gtp - Command for guildleaders to teleport to the guild at 'any'
**           time, i. e.
**           1. The common teleport rules are checked
**           2. The player mustn't be in a virtual room (to ensure (s)he
**              might return to the place at any time.
**           When teleported, the guildleader can't leave the guild except
**           by typing the command 'gtp' again ... or quit, which will
**           teleport her/him back, too.
** cmd_gidea
** cmd_gbug
** cmd_gtypo - These commands just work like 'idea', 'bug' and 'typo' but
**             as those will only log into the rep-file the room in which
**             someone is standing belongs to, this often doesn't help
**             if there's a bug, ... in a guild-ability
**             The reports will be saved in /log/rep/<path>, where <path>
**             is the second part of the path in the file-name, e. g.
**             /players/thragor/guildobj will save the reports to
**             /log/rep/thragor, /d/shadows/guildobj will save the reports
**             to /log/rep/shadows
**
** In the init of the guild-object you must call 'add_false_cmds()'!!!
**
** Furthermore the skills are handled inside this object, i. e. using
** them and advancing them.
**
** 04nov94 [t] Creation
** 13feb95 [t] Skill Handling
** 02jun95 [t] gbug, gidea, gtypo
** 23aug95 [t] Skill Handling moved to /obj/lib/skills
** 15oct96 [t] Guild-Who sorted
** 11dec96 [t] Report-File may be redirected
**
** [t] Thragor
*/

#include <config.h>    // MASTER
#include <secure/wizlevels.h> // IS_IMMORTAL
#include <rooms.h>     // TPORT_BOTH, ...
#include <moving.h>    // M_TELEPORT

#define ME this_object()
#define TP this_player()
#define STR "/lib/string"
#define SF(x) #'x //'

inherit "/obj/lib/skills";

private nosave string owner,guild,guildlog;
private nosave object guildob;
private nosave string gtploc;

// Added by Softbyte 14jan97
// Allows to set the location for the gtp command
int SetTPLocation(string str) {gtploc=str;return 1;}
string QueryTPLocation() {return gtploc;}

public int IdGuildobject()
// With this function the guildobject identifies itself as guildobject.
{
  return 1;
}

public string SetGuildLog(string str)
{
  return guildlog = str;
}

public string QueryGuildLog()
{
  string *names;
  if (guildlog) return guildlog;
  names = explode(object_name(),"/");
  if (sizeof(names)>1) return names[2];
  else return 0;
}

public string SetGuild(string fn)
// Set the filename of the guild
{
  return guild = fn;
}

public string QueryGuild()
{
  return guild;
}

public string SetOwner(string pl)
// Set the owner of this guildobject
{
  return owner = pl;
}

public string QueryOwner()
{
  return owner;
}

public int LoadGuild()
// Load the guild and put the objectpointer to the guild into <guildob>
{
  string err;
  if (guildob) return 1;
  if (!guild) return 0;
  if (err = catch(guildob = load_object(guild)))
    {
      MASTER->runtime_error("Guild not loadable: "+err,guild,
                            object_name(ME));
      return 0;
    }
  return 1;
}

public object QueryGuildObject()
// Get the object-pointer of the guild this guildobject belongs to
{
  LoadGuild();
  return guildob;
}

public object *guild_users()
// return an array of all members currently online
{
  if (!LoadGuild()) return 0;
  return filter(users(),symbol_function("is_member",guildob));
}

public varargs int check_owner(object pl,int silent_force)
// check if the player is thw owner of this guildobject
// silent_force is only used when a player leaves the guild. In
// this case even a wizard will loose the guildobject (force)
// and the message won't be printed (silent).
{
  pl = pl||environment();
  if (!pl) return call_out(SF(check_owner),2,pl,silent_force),0;
  if (!query_once_interactive(pl))
    {
      if (!owner) SetOwner(pl->QueryName()||pl->QueryShort());
      return 1;
    }
  if (!owner) SetOwner(getuid(pl));
  if (!LoadGuild()) return 1;
   debug_message(sprintf("pl %O guildobj %O\n", pl, guildob));
  if ((owner!=getuid(pl))
      ||(   (!IS_IMMORTAL(pl)||silent_force)
          &&pl->QueryGuild()!=guildob->QueryGuildclass()
        ) )
    {
      if (!silent_force)
        tell_object(pl,"You are not allowed to own this guildobject.\n");
      ME->remove();
      return 0;
    }
  return 1;
}

protected string who_line(object pl)
// return one line of the guild-who
{
  if (!pl) return "";
  if (!LoadGuild()) return "";
  if (pl->QueryInvis()) return "";
  return capitalize(getuid(pl))+" "+
         guildob->GuildLeveltoTitle(pl->QueryLevel(),pl->QueryGender())+" "+
         "["+pl->QueryRace()+", "+
             to_string(pl->QueryLevel())+", "+
             pl->QueryAlignString(pl->QueryAlign())+
         "]"+
         (guildob->is_leader(pl)
          ?guildob->is_creator(pl)
           ?" -CREATOR-"
	   :" -LEADER-"
          :""
         );
}

protected status who_sort(object pl1,object pl2)
{
  int lvl1,lvl2;
  status c1,c2;
  
  if (LoadGuild())
    {
      c1=guildob->is_creator(pl1);
      c2=guildob->is_creator(pl2);
    }
  if (c1!=c2)
    return c1==1;
  else
    if (c1)
      if ((lvl1=!!query_user_level(pl1))==(lvl2=!!query_user_level(pl2)))
	return getuid(pl1)>getuid(pl2);
      else
	return lvl1>lvl2;
  if ((lvl1=pl1->QueryLevel())==(lvl2=pl2->QueryLevel()))
    return getuid(pl1)>getuid(pl2);
  else
    return lvl1>lvl2;
}

protected string who_list()
// return the whole guild-who list
{
  return implode(map(sort_array(guild_users(),SF(who_sort)),
			   SF(who_line))-({""}),"\n")+"\n";
}

protected int guild_shout(object receiver,object sender,string text)
// send a guild-shout to one of the online members
{
  string spec_text;
  
  if ((receiver!=sender)&&
      receiver->QueryEarmuffs()>sender->QueryLevel())
    return 0;
  if (member(receiver->QueryIgnored(),getuid(sender))) return 0;
  spec_text = ME->InformGShout(receiver,sender,text);
  if (receiver==sender)
    if (sender->QueryEchoMode())
      tell_object(sender,
        STR->wrap(spec_text||("You shout to all guildmembers: "+text+"\n"),
                  75,3));
    else
      tell_object(sender,"Ok.\n");
  else
    tell_object(receiver,
      STR->wrap(spec_text||(sender->QueryName()+
                " shouts to all guildmembers: "+text+"\n"),75,3));
  return 1;
}

public int cmd_gshout(string txt)
// the action "gshout"
{
  if (!TP) return 0;
  if (!txt)
    return notify_fail("What do you want to shout?\n",NOTIFY_ILL_ARG),0;
  filter(guild_users(),SF(guild_shout),TP,txt);
  return 1;
}

protected int guild_emote(object receiver,object sender,string text)
// send a guild-shout to one of the online members
{
  string spec_text,guildstr;
  
  if (!LoadGuild()) return 0;
  guildstr = guildob->QueryGuildclass();
  if ((receiver!=sender)&&
      receiver->QueryEarmuffs()>sender->QueryLevel())
    return 0;
  if (member(receiver->QueryIgnored(),getuid(sender))) return 0;
  spec_text = ME->InformGEmote(receiver,sender,text);
  text = guildstr+"*"+capitalize(sender->QueryName())+" "+text+"\n";
  if (receiver==sender)
    if (sender->QueryEchoMode())
      tell_object(sender,
        STR->wrap(spec_text||text,75,3));
    else
      tell_object(sender,"Ok.\n");
  else
    tell_object(receiver,
      STR->wrap(spec_text||text,75,3));
  return 1;
}

public int cmd_gemote(string txt)
// the action "gemote"
{
  if (!TP) return 0;
  if (!txt)
    return notify_fail("What do you want to emote?\n",NOTIFY_ILL_ARG),0;
  filter(guild_users(),SF(guild_emote),TP,txt);
  return 1;
}

public int cmd_gwho(string arg)
// the action "gwho"
{
  if (!TP) return 0;
  if (arg)
    return notify_fail("Just call '"+query_verb()+"'.\n",
                       NOTIFY_NOT_OBJ),0;
  STR->smore(who_list(),TP->QueryPageSize());
  return 1;
}

public int cmd_gtp()
// the action "gtp"
{
  int tport;
  object env;
  object target;
  string err;
  
  if (!TP) return 0;
  if (!LoadGuild())
    return notify_fail("Unable to load guild.\n",NOTIFY_NOT_OBJ),0;
  if (!guildob->is_leader(TP))
    return notify_fail("You can't use this ability.\n",NOTIFY_NOT_VALID),0;
  if (sizeof((TP->QueryEnemies()||({}))-({0})))
    return notify_fail("You can't do that while fighting.\n",
		       NOTIFY_NOT_VALID),0;
  if (   !(env = environment(TP))
      || env->QueryTPort()&TPORT_OUT==0
    )
  // we need the object_name/blueprint check, because we have to ensure,
  // that the room still exists if we move the player back.
    return notify_fail("You can't do that at this place.\n",
		       NOTIFY_NOT_VALID),0;
  if (QueryTPLocation()) 
  {
    if (err = catch(target = load_object(QueryTPLocation())))
    {
      MASTER->runtime_error("Guild TP Location not loadable: "+err,QueryTPLocation(),
                            object_name(ME));
      return notify_fail("There had been an error during teleport.\n"),0;
    }
  }
  else target=guildob;
  if (env==target)
    return notify_fail("You are already in the guild.\n",NOTIFY_NOT_VALID),0;
  tport = target->QueryTPort();
  target->SetTPort(TPORT_IN);
  TP->move(target,M_TELEPORT);
  target->SetTPort(tport);
  write("You arrive in the guild.\n");
  return 1;
}

public mixed QueryAutoObject()
// You may modify this to save the data of the player to its
// /save-file or to save them to a file. But it always should
// return a value different from 0, otherwise the object is
// not autoloading
{
  return 1;
}

public mixed SetAutoObject(mixed values)
// You may modify this to load the data of the player from its
// savefile. The data will be given in <values> if saved sometime
// before. Or you may load the data from the player from an own
// savefile.
// But you should always call 'check_owner(this_player())' in this
// function, to ensure, that the user has the right to use this
// tool. (SetAutoObject is called after the 'create'-function)
{
  return check_owner(environment()||this_player());
}

public void add_false_cmds()
{
  // obsolete
}

public int cmd_skills(string str)
{
  string *skill_list,*res;
  mapping skills;
  int i;
  
  if (str)
    return notify_fail("Just type '"+query_verb()+"'\n",
      NOTIFY_ILL_ARG);
  if (!LoadGuild())
    return notify_fail("The guild can't be loaded.\n"
       "Inform the creator of the guild.\n",NOTIFY_NOT_VALID);
  if (!sizeof(skill_list = m_indices(guildob->QuerySkills(TP)||([]))))
    return notify_fail("You have no skills.\n",
      NOTIFY_NOT_VALID);
  skill_list = sort_array(skill_list,SF(>));
  skills = mkmapping(skill_list,
    map(skill_list,SF(get_skill)));
  res = ({});
  for(i=0;i<sizeof(skill_list);i++)
    res+=({STR->ladjust(skill_list[i]+": ",17,".")+" "+skills[skill_list[i]]});
  STR->smore(res,TP->QueryPageSize());
  return 1;
}

protected void smart_log(string what,string str)
{
  string creat;
  if (creat = QueryGuildLog())
    {
      "/players/thragor/lib/debug"->debug("thragor","Creat: ",creat);
      log_file("rep/"+creat, ctime()+" G"+what+" from "+getuid(TP)+
               " in "+object_name(environment(TP))+":\n"
               "Reporting Object: "+object_name()+"\n"+str+"\n");
    }
  log_file("rep/"+what,ctime()+" "+getuid(TP)+" in "
                     +object_name(environment(TP))+":\n"
           "Reporting Object: "+object_name()+"\n"+str+"\n");
}

public int cmd_gbug(string str)
{
  if (!str || str == "")
    {
      write("Enter your report-line: ");
      input_to("bug2");
      return 1;
    }
  smart_log("BUGS",str);
  write("Your guild-bug-report will be saved and checked. Thanks for help.\n");
  return 1;
}

public void bug2(string str)
{
  if (!str || str == "")
    {
      write("Bug Cancelled...\n");
      return;
    }
  smart_log("BUGS",str);
  write("Your guild-bug-report will be saved and checked. Thanks for help.\n");
}

public int cmd_gtypo(string str)
{
  if (!str || str == "")
    {
      write("Enter your report-line: ");
      input_to("typo2");
      return 1;
    }
  smart_log("TYPO",str);
  write("Thanks for report of the mispselingl ;-) . "
        "Your guild-report got saved.\n");
  return 1;
}

public void typo2(string str)
{
  if (!str || str == "")
    {
      write("Typo Cancelled...\n");
      return;
    }
  smart_log("TYPO",str);
  write("Thanks for report of the mispselingl ;-) . "
        "Your guild-report got saved.\n");
}

public int cmd_gidea(string str)
{
  if (!str || str == "")
    {
      write("Enter your report-line: ");
      input_to("idea2");
      return 1;
    }
  smart_log("IDEA",str);
  write("Guild-Idea saved. Thanks for helping to make this guild more "
        "fun playing.\n");
  return 1;
}

public void idea2(string str)
{
  if (!str || str == "")
    {
      write("Idea Cancelled...\n");
      return;
    }
  smart_log("IDEA",str);
  write("Guild-Idea saved. Thanks for helping to make this guild more "
        "fun playing.\n");
}
