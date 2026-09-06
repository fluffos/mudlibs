// A finger with some additional information.

#include "/sys/interactive_info.h"

#include <daemons.h>
#include <cmd.h>
#include <mud_name.h>
#include <player_defs.h>
#include <config.h>
#include <coder_levels.h>

#define	c_time(x)	ctime(x)

string name;
string title;
string desc;
string race;
string liege;
string guild;
string guild_object_name;
mixed guild_save;
string called_from_ip_name;
string called_from_ip;
string auto_load;
string quests;
string mailaddr;
string password;
string access_list;
int coder_level;
int level;
int max_hp, max_sp, max_fp;
int max_Str, max_Dex, max_Int, max_Con, max_Fatigue;
int experience;
int quest_points;
int luck;
int player_kills;
int age;
int gender;
int last_saved;

status
fin_cmd(string s)
{
    string gend, lvl, mchar, res;
    object ob;

    if(!CHECK) return 0;
    if(!interactive_info(this_player(), II_IP_NUMBER))
	return 0;
    // Restricted info like email, so:
    if((int)this_player()->query_coder_level() < LVL_COADMIN)
	return 0;
    if(!s)
	return notify_fail("Usage: fin <player>\n"),0;
    s = lower_case(s);
    if (!restore_object(PATH_FOR_PLAYER_SAVE(s)))
	return notify_fail("No such user.\n"),0;

    res = sprintf("\n%s %s.\n", capitalize(name), title);
    if(desc)
	res = sprintf("%sDescription:\n%s\n", res, desc);
    switch(coder_level) {
    case  -1 : lvl = "Test character"; break;
    case   0 : switch(level) {
	case 1..24 : lvl = "Player"; break;
	default    : lvl = "Lord player"; break;
	} break;
    case    1..49 : lvl = "Apprentice coder"; break;
    case   50..99 : lvl = "Junior coder"; break;
    case 100..199 : lvl = "Coder"; break;
    case 200..299 : lvl = "Senior coder"; break;
    case 300..399 : lvl = "Co-Admin"; break;
    case      400 : lvl = "Admin"; break;
    }
    if(coder_level)
	lvl = sprintf("%s (#%d)", lvl, coder_level);

    switch(gender) {
    case 0 : gend = "creature"; break;
    case 1 : gend = "male"; break;
    case 2 : gend = "female"; break;
    }

    res = sprintf("%sStatus: %s.\nExperience: %d (level %d).  Luck: %d.  \
PKs: %d.\nMax str/dex/int/con/fat: %d/%d/%d/%d/%d.  Max hp/sp/fp: \
%d/%d/%d.\nGender: %s.  Race: %s.  Liege: %s.\nGuild: %s.\nGuild object: \
%s.\nGuild save: %s.\n",
      res, lvl, experience, level, luck, player_kills, max_Str, max_Dex,
      max_Int, max_Con, max_Fatigue, max_hp, max_sp, max_fp, gend,
      (race ? race : "*human"), (liege ? capitalize(liege) : "None"),
      (guild ? capitalize(guild) : "None"),
      (guild_object_name ? guild_object_name : "None"),
      (stringp(guild_save) ? guild_save : "<NaS>"));

    age <<= 1;
    res = sprintf("%sAge: %s.\n", res, c_time(age));
    if(quests)
	res = sprintf("%sQuests solved (%d points): %s\n", res, quest_points, quests);
    if(auto_load)
	res = sprintf("%sAutoload: %s\n", res, auto_load);
    res = sprintf("%sEMail address: %s\nCrypted password: %s\n",
      res, (mailaddr ? mailaddr : "Not set"), (password ? password : "Not set"));
    if(access_list)
	res = sprintf("%sAccess list: %s", res, access_list);
    if((mchar = (string)MCHAR_D->query_multiple_char(name)))
	res = sprintf("%sRegistered multiple characters: %s\n\n", res, mchar);
    else
	res = sprintf("%sNo registered multiple characters.\n\n", res);

    if((ob = find_player(s))) {
	int loginTime, connectTime;

	if(interactive(ob))
	    res = sprintf("%s%s is currently logged in from %s.\n",
	      res, capitalize(name), interactive_info(ob, II_IP_NAME));
	else
	    res = sprintf("%s%s is currently linkdead. (%s)\n", res, capitalize(name),
	      called_from_ip_name);
	loginTime = (int)ob->query(PLR_LOGIN_TIME);
	connectTime = (int)ob->query(PLR_CONNECT_TIME);
	res = sprintf("%sLogged in on %s, %s ago.\nLocation: %s\n", res, ctime(loginTime),
	  c_time(connectTime), object_name(environment(ob)));
    }
    else
	res = sprintf("%sLast login was from %s (%s).\nLeft "+MUD_NAME+
	  " %s ago (%s).\n",
	  res, called_from_ip_name, called_from_ip, c_time(time()-last_saved),
	  ctime(last_saved));

    this_player()->tell_me(res);

    return 1;
}
