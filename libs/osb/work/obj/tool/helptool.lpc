/* Helptool V1.3
 * (c) 1992,1993 by Pumuckel
 */                                  

inherit "/std/thing";
inherit "/lib/string";

#include <config.h>
#include <moving.h>
#include "./helptool.h"
#include <properties.h>
#include <secure/wizlevels.h>
#include <string.h>
#include <daemons.h>

#define BEEP ""
#define HELPTOOL        "Helptool V 1.3"
#define Q_NAME          0
#define Q_CREATOR       1
#define Q_POINTS        2
#define Q_SHORT         3
#define Q_LONG          4

#define IS_OSB_PLAYER(x) ((file_size("/save/"+x[0..0]+"/"+x+".o")>=0)?1:0)
#define OUT(x) {if (text=x) { SMore(text);return 1;} else return 0;}
#define COUNTRY(x) COUNTRY_D->resolve_ip_number(x)

create() 
{
  (::create());
  seteuid(getuid());
  SetIds(({"tool", "helptool", "htool"}));
  SetLong("This is a helptool which enables you to do different things:\n\
QP <name>         returns the Questpoints from player <name>\n\
Quests <name>     returns solved quests from player <name>\n\
QL [<name>]       returns a list with possible quests and QP\n\
QHint <number>    returns a hint for the quest #<number>\n\
WL [<name>]       returns the wizlist with rank of player <name>\n\
HP [<name>]       returns the hitpoints from living <name>\n\
beep <name>       beeps the player/wiz <name> 5 times\n\
INFO              returns the prop P_INFO of the room\n");

// who ?             returns a list of players and wizs logg in\n\
// [temporarily] removed because one might like the original who better
// (Juergen 093097)

  SetReadMsg(HELPTOOL + " (c) Pumuckel Oct 1993\n");
  Set(P_VERSION, HELPTOOL + " (c) Pumuckel Oct 1993\n");
  Set(P_NOSELL,"Do not sell wizard-tools!\n");
  SetNoDrop("Do not drop wizard-tools!\n");
  SetNoGive("You won't give it away.\n");
  Set(P_AUTOOBJECT,1);
}

init() 
{
  (::init());
  add_action("lower","",1);
  call_out("check", 5);
}

lower(string arg) {
  string text;

  switch (lower_case(query_verb())) {
  case "help": return help(arg);
  case "qp":     OUT(query_qp(arg))
  case "quests": OUT(query_quests(arg))
  case "ql":     OUT(query_quest_list(arg))
  case "wl":     {wizlist(arg||"");return 1;}
  case "hp":     OUT(query_hp(arg))
  case "info": return info(arg);
  case "beep": return beep(arg);
//  case "who": return new_who(arg);
// [temporarily] removed because one might like the original who better
// (Juergen 093097)
  case "qhint": OUT(QUESTMASTER->QueryQuestLong(to_int(arg)-1))
  }
}

check()
{
  object env;

  env = environment();
  while(env && !living(env))
    env = environment(env);
  if(env) {
    /* no helptool for players */
    if(!IS_IMMORTAL(env)) {
      write("...destructing " + HELPTOOL + ", you aren't a wizard!\n");
      if(!remove())
	destruct(this_object());
    }
  }
}

help(str)
{
  if(!str) return 0;
  if(present(str) == this_object()) {
    write(QueryLong());
    return 1;
  }
  return 0;
}

QueryShort()
{
  object env;
  string name;
  
  env = environment();
  while(env && !living(env))
    env = environment(env);
  if(env) {
    if(!(name = env->QueryRealName()))
      if(!(name = env->QueryName()))
	name = env->QueryShort();
    name = capitalize(name);
    if(name[<1] == 's' || name[<1] == 'z' || name[<1] == 'x')
      name += "'";
    else
      name += "'s";
    return name + " " + HELPTOOL;
  }
  return "Nobody's " + HELPTOOL;
}

mixed query_qp(string player) {
  object name;
  string text;
  
  if(!player) {
    notify_fail("Missing argument: <name>\n");
    return 0;
  }
  player = lower_case(player);
  text = "";
  if (IS_OSB_PLAYER(player)) {
    text += (capitalize(player) + " has " + 
	     QUESTMASTER->QueryQuestPoints(player) +
	     " Questpoints out of possible " + 
	     QUESTMASTER->QueryTotalQuestPoints() +
	     ".\n");
    return text;
  }
  FAIL("A player " + capitalize(player) + " does not exist in " MUDSHORT ".\n");
}

mixed query_quests(string player)
{
  string long, queststring;
  string *quests;
  int    count,i;
  object name;
  
  if(!player) {
    notify_fail("Missing argument: <name>\n");
    return 0;
  }
  player = lower_case(player);
  if(IS_OSB_PLAYER(player)) {
    if (count = sizeof(quests = QUESTMASTER->QueryPlayerQuests(player))) {
      long = capitalize(player) + 
	" has solved the following quest" +
	  ((count==1)?":\n":"s:\n");
      for (i=count; i--; long+=quests[i]+"\n");
    }
    else
      long = capitalize(player) + " has solved no quest.\n";
    return long;
  }
  FAIL("A player " + capitalize(player) + " does not exist in " MUDNAME ".\n");
}

mixed query_quest_list(string player)
{
  string text,text2;
  
  text  = "The following quests are installed";
  text += ((player && IS_OSB_PLAYER(player))?
	   " or solved by " + capitalize(player) + ":\n":":\n");
  text += QUESTMASTER->ListQuests(player);
  if (text2=query_qp(player))
    text+= text2;
  text += ("There are " + 
	   QUESTMASTER->QueryOfficialQP() + " + " +
	   QUESTMASTER->QueryMiniQP() + " = " + 
	   QUESTMASTER->QueryTotalQuestPoints() + " possible quest points.\n\
To become a wizard a player needs " + QUESTMASTER->QueryWizQuestPoints() + " QP's.\n");
  return text;
}

// [temporarily] removed because one might like the original who better
// (Juergen 093097)

/*
new_who2(from,to) 
{
  string text,who_text;
  object *list;
  object player;
  int    i,j,learners,are_players_there;
  
  list = users();
  who_text = "";
  for (j=from;j<=to;j++) {
    learners = j;
    for(are_players_there=0, i=sizeof(list); !are_players_there && i--;)
      are_players_there=IS_IMMORTAL(list[i])==learners;
    if(are_players_there) {
      who_text += (learners ? "Wizards:\n" : "Players:\n");
      for(i=0; i<sizeof(list); i++) {
	player=list[i];
	if(IS_IMMORTAL(player)==learners) {
	  if(!player->QueryInvis()) {
	    if(text=player->QueryPresay())
	      who_text += text;
	    who_text += capitalize(player->QueryRealName());
	    if(text=player->QueryTitle())
	      who_text += " "+text;
	    who_text += " [" + COUNTRY(player) + "]\n";
	  } 
	  else 
	    if(IS_IMMORTAL(this_player())) {
	      who_text += "(" + capitalize(player->QueryRealName()) + 
		") ["+ COUNTRY(player)+"]\n";
	    }
	}
      }
    }
    if (j!=to) who_text += "\n";
  }
  smore(who_text,TP->QueryPageSize(),0,0,1);
  return 1;
}
*/

// [temporarily] removed because one might like the original who better
// (Juergen 093097)

/*
new_who(str) {
  if(!str) str = "all";
  switch(lower_case(str)) {
  case "o": case "old":
    return 0;
  case "all": 
    new_who2(0,1);
    return 1;
  case "p": case "players":
    new_who2(0,0);
    return 1;
  case "w": case "wizards":
    new_who2(1,1);
    return 1;
  case "?":
    write("\
who, commands:\n\
\n\
who ?\t\tthis text\n\
who o|old\tthe player who command\n\
who p|players\twho for all players\n\
who w|wizards\twho for all wizards\n\
");
    return 1;
  default:
    write("Use 'who ?' for getting more information.\n");
    return 1;
  }
}
*/

string query_hp(string player)
{
  object name;
  
  if(!player)
    return ("You have " + this_player()->QueryHP() + " Hitpoints.\n");
  if (name = find_living(player))
    return (capitalize(player) + " has " + name->QueryHP() + " Hitpoints.\n");
  FAIL("There is no such living.\n"); 
}

info()
{
  string info_text;
  
  if (info_text = environment(this_player())->Query(P_INFO)) {
    write(info_text);
    return 1;
  } 
  else
    FAIL("There is no P_INFO for this room defined!\n");
}

beep(str) {
  object victim;
  
  if(!str) {
    tell_room(environment(this_player()),"BEEEP!!"+BEEP+"\n");
    return 1;
  }
  if(!(victim=find_living(str)))
    FAIL("I cannot find "+str+".\n");
  tell_object(victim,capitalize(getuid(this_player()))+" wants to have a word with you."+BEEP+"\n");   
  write(victim->QueryName()+" has been notified.\n");
  return 1;
}


