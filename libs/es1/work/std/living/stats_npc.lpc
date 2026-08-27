// stats.c
// This file applys stats facilities to living objects. Stats includes
// level, experience, and attributes.
// Created by Annihilator@Eastern.Stories 09-21-93
// This file also contains the original skills.c
// It should be kept simple so as not to confuse new coders.
// original by Deishu@TMI (a.k.a. Buddha@TMI) on 6-13-92
// revised so that it might work on 9-20-92 by Buddha
// Skill improvement routines added on 9-30-92 by Mobydick
// the stats data is  so that that people can't get to it
// except through these functions.

#include <daemons.h>
//	#include <uid.h>
#include <stats.h>
//	#include <races.h>

 int			level;
 mapping			stats;
 mapping			skills;
 nosave mapping		mod_stats;
 nosave mapping		mod_skills;
 nosave mapping		special_defense;

// Prototypes
varargs void init_stats(int lvl);
void set_level(int lvl);
int query_level();
int query_max_hp();
int query_max_sp();
int query_max_fp();
int query_max_tp();

int set_perm_stat(string which, int value);
void modify_stat(string which, int value);
int query_stat(string which);
int query_perm_stat(string which);
string *query_stat_keys();
mapping query_skills();
varargs int query_skill(string what, int no_guild_effect);
int query_perm_skill(string what);
void set_skill(string what, int val);
void modify_skill(string what, int val);

int query_special_defense(string type);

// Methods

varargs int init_stats(int lvl)
{
	int i;
	string *attrs;
	object me;

	me = this_object();

	if( lvl < 1 ) level = 1;
	else level = lvl;

	attrs = STATS_D->query_stat_names();
	stats = allocate_mapping(sizeof(attrs));
	mod_stats = allocate_mapping(sizeof(attrs));
	i = sizeof(attrs);
	while( i-- ) {
		stats[ attrs[i] ] = level;
		mod_stats[ attrs[i] ] = 0;
	}

	skills = allocate_mapping(10);
	mod_skills = ([]);

	me->set("max_hp", level * 25 );
	me->set("hit_points", level * 25 );
	return 1;
}

int set_level(int lvl)
{
	if( (lvl > 0) && (lvl <= MAX_LEVEL) ) {
		init_stats(lvl);
	}
	else return 0;
}

int query_level()
{
	return level;
}

int set_perm_stat(string which, int value)
{
	string *attrs;

	if( strlen(which)==3 )	// Speed up converting
	switch( which ) {
		case "str": which = "strength";				break;
		case "int": which = "intelligence";			break;
		case "dex": which = "dexterity";			break;
		case "con": which = "constitution";			break;
		case "pie": which = "piety";				break;
		case "kar": which = "karma";				break;
		default: 	return 0;
	}
	attrs = STATS_D->query_stat_names();
	if( member_array( which, attrs ) == -1 ) return 0;
	if( !stats || !mapp(stats) ) init_stats(level);
	if( undefinedp(stats[which]) ) return 0;
	if( value > 0 &&
		value <= MAX_MONSTER_ATTRIBUTE ) {
		stats[which] = value;
		return 1;
	} else return 0;
}

int modify_stat(string which, int value)
{
	string *attrs;
	if( strlen(which)==3 )	// Speed up converting
		switch( which ) {
			case "str": which = "strength";				break;
			case "int": which = "intelligence";			break;
			case "dex": which = "dexterity";			break;
			case "con": which = "constitution";			break;
			case "pie": which = "piety";				break;
			case "kar": which = "karma";				break;
			default:	return 0;
		}
	attrs = STATS_D->query_stat_names();
	if( member_array( which, attrs ) == -1 ) return 0;
	if( !stats || !mapp(stats) ) init_stats(level);
	if( !mod_stats || !mapp(mod_stats) ) init_stats(level);
	if( undefinedp(mod_stats[which]) ) return 0;
	mod_stats[which] += value;
}

int query_stat(string which)
{
	int s, load, max_load;
	string *attrs;

	if( strlen(which)==3 )	// Speed up converting
		switch( which ) {
			case "str": which = "strength";				break;
			case "int": which = "intelligence";			break;
			case "dex": which = "dexterity";			break;
			case "con": which = "constitution";			break;
			case "pie": which = "piety";				break;
			case "kar": which = "karma";				break;
			default:	return 0;
		}
	attrs = STATS_D->query_stat_names();
	if( member_array( which, attrs ) == -1 ) return 0;
	if( !stats || !mapp(stats) ) init_stats(level);
	if( !mod_stats || !mapp(mod_stats) ) init_stats(level);
	s = stats[which] + mod_stats[which];
	if( s < 1 ) return 1;
	return s;
}

int query_perm_stat(string which)
{
	int s;
	string *attrs;

	if( strlen(which)==3 )	// Speed up converting
		switch( which ) {
			case "str": which = "strength";				break;
			case "int": which = "intelligence";			break;
			case "dex": which = "dexterity";			break;
			case "con": which = "constitution";			break;
			case "pie": which = "piety";				break;
			case "kar": which = "karma";				break;
			default:	return 0;
		}
	attrs = STATS_D->query_stat_names();
	if( member_array(which, attrs) == -1 ) return 0;
	if( !stats || !mapp(stats) ) init_stats(level);
	s = stats[which];
	if( s < 1 ) return 1;
	return s;
}

mapping query_skills()
{
	if( !skills ) return ([]);
	else return copy(skills);
}

// Okay, call this function to get someone's skill values in a particular
// skill, for example, foo  = (int)this_player()->query_skill("pick locks");
// if there is no value for that skill, 0 is returned.
// if guild_effect, then skill will be modified by his guild.
varargs int query_skill(string what, int no_guild_effect)
{
	int skill;
	object guild;
	string skills_effect;

	if( !skills || sizeof(skills) == 0 || undefinedp(skills[what]) ) return 0;
	skill = skills[what];
	if( mod_skills && sizeof(mod_skills)>0 && !undefinedp(mod_skills[what]) )
		skill += mod_skills[what];
	if( !no_guild_effect ) {
		guild = (object)this_object()->query("guild");
		if( guild && (skills_effect=(string)guild->query("skills_effect")) )
			skill = (int)call_other( guild, skills_effect, this_object(), what, skill );
	}
	if( skill < 0 ) return 0;
	return skill;
}

int query_perm_skill(string what)
{
	if( !skills || sizeof(skills) == 0 || undefinedp(skills[what]) ) return 0;
	return skills[what];
}

int clean_skills()
{
	skills = allocate_mapping(10);
	return 1;
}

int set_skill(string what, int val)
{
	if( val < 0 || val > 100 ) return 0;
	skills[what] = val;
	if( val==0 ) map_delete(skills, what);
	return 1;
}

int modify_skill(string what, int val)
{
	if( undefinedp(mod_skills[what]) )
		mod_skills += ([ what : val ]);
	else mod_skills[what] += val;
	return 1;
}

int query_special_defense(string type)
{
	string race;
	int natural;

	natural = (int)this_object()->query("special_defense/"+type);
	if( !natural && type != "none" )
		natural = (int)this_object()->query("special_defense/all");

	if( !special_defense || !mapp(special_defense)
		|| undefinedp(special_defense[type]) )
		return natural;
	else
		return (natural + special_defense[type]);
}

int apply_special_defense(string type, int value)
{
	if( !special_defense || !mapp(special_defense) )
		special_defense = ([]);
	if( !undefinedp(special_defense[type]) ) special_defense[type] += value;
	else special_defense[type] = value;
	return 1;
}
