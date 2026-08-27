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
#include <uid.h>
#include <stats.h>
#include <races.h>

 int			level, experience;
 mapping			stats;
 mapping			skills;
 mapping			knowledges;
 nosave mapping		mod_stats;
 nosave mapping		mod_skills;
 nosave mapping		mod_knowledges;
 nosave mapping		special_defense;

// Prototypes
varargs int init_stats(int lvl);
int set_level(int lvl);
int query_level();
int query_max_hp();
int query_max_sp();
int query_max_fp();
int query_max_tp();
int query_critical_med_res();

int set_experience(int exp);
int gain_experience(int exp);
int query_experience();

int set_perm_stat(string which, int value);
int modify_stat(string which, int value);
int query_stat(string which);
int query_perm_stat(string which);
string *query_stat_keys();
mapping query_skills();
varargs int query_skill(string what, int no_guild_effect);
int query_perm_skill(string what);
int set_skill(string what, int val);
int modify_skill(string what, int val);
int query_max_load();
int advance_cost(string what);
int train_cost(string what);
int block_wield(object obj);
int block_wear(object obj);

int query_special_defense(string type);

// Methods

// The security checks. by Annihilator Oct 14, 1993
// Updated by Kyoko. 4-28-94
// Updated by Mad, Aug 8,1996
// Updated by Yueh, Sep 29,1996
nomask int valid_modify(object ob)
{
	string temp,temp1;
	// object in /u/ only can modify object in /u/ or wizard, Added by Yueh
        if ((this_object()->query("user"))&&(!wizardp(this_object())))
	{
                temp=explode(base_name(previous_object()),"/")[0];
		if ((temp== "u")||(temp=="open")){
			temp1=explode(base_name(this_object()),"/")[0];
			if ((temp1!= "u")&&(temp1!="open"))
				return 0;
		}
	}
	if( geteuid(ob)==ROOT_UID ) return 1;
	if( member_group(geteuid(ob), "admin") ) return 1;
	if( member_group(geteuid(this_object())) ) return 1;
	if( geteuid(previous_object()) == ROOT_UID ) return 1;
	if( !this_object()->query("user") ) return 1;
	return 0;
}

// The security checks. by Yueh Sep 29, 1996
nomask int valid_modify1(object ob)
{
	string temp,temp1;
	// object in /u/ only can modify object in /u/ or wizard, Added by Yueh
        if ((this_object()->query("user"))&&(!wizardp(this_object())))
	{
                temp=explode(base_name(previous_object()),"/")[0];
		if ((temp== "u")||(temp=="open")){
			temp1=explode(base_name(this_object()),"/")[0];
			if ((temp1!= "u")&&(temp1!="open"))
				return 0;
		}
	}
	return 1;
}

// The security checks. by Annihilator Oct 14, 1993
// Updated by Kyoko. 4-28-94
// Updated by Yueh, Sep 29,1996
nomask int valid_master_only_modify(object ob)
{
	string temp,temp1;
	// object in /u/ only can modify object in /u/ or wizard, Added by Yueh
	if (!wizardp(this_object()))
	{
		temp=explode(base_name(ob),"/")[0];
		if ((temp== "u")||(temp=="open")){
			temp1=explode(base_name(this_object()),"/")[0];
			if ((temp1!= "u")&&(temp1!="open"))
				return 0;
		}
	}
	if( geteuid(ob)==ROOT_UID ) return 1;
	if( member_group(geteuid(ob), "admin") ) return 1;
	if( !this_object()->query("user") ) return 1;
	return 0;
}

varargs int init_stats(int lvl)
{
	int i ;
	string *attrs;
	object me;

	if( !valid_master_only_modify(previous_object()) ) return 0;
	me = this_object();

	if( lvl < 1 ) level = 1;
	else level = lvl;

	experience = STATS_D->query_level_exp(level);
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
	knowledges = allocate_mapping(10);
	mod_knowledges = ([]);

	if( !this_object()->query("user") ) {
		me->set("max_hp", level * 25 );
		me->set("hit_points", level * 25 );
//		me->set("max_sp", level * 25 );
//		me->set("spell_points", level * 25 );
	} else {
		me->set("max_hp", "@@query_max_hp");
		me->set("hit_points", query_max_hp());
		me->set("max_sp", "@@query_max_sp");
		me->set("spell_points", query_max_sp());
	}
	return 1;
}

int change_level(int lvl)
{
	string guild;
	if( !valid_master_only_modify(previous_object()) ) return 0;
	if( (lvl > 0) && (lvl <= MAX_LEVEL) ) {
		level = lvl;
		return 1;
	}
	return 0;
}

int set_level(int lvl)
{
	if( !valid_master_only_modify(previous_object()) ) return 0;
	if( (lvl > 0) && (lvl <= MAX_LEVEL) ) {
		if( userp(this_object()) )
			return (change_level(lvl));
		else
			return init_stats(lvl);
	}
	else return 0;
}

int query_level()
{
	return level;
}

int query_max_hp()
{
	return 20 + query_stat("con") * 10;
}

int query_max_sp()
{
	return 20 + query_stat("int") * 10;
}

int query_max_fp()
{
	if( !this_object()->query("force_effect") ) return 0;
	return (int)this_object()->query_skill("inner-force") *
		(int)this_object()->query("force_effect");
}

int query_max_tp()
{
	if( !query_level() ) return 0;
    return 30 + query_level() * 30;
}

int query_critical_med_res()
{
	return 200 + 10 * query_stat("con") +
		(int)this_object()->query("constitution") * query_level();
}

int set_experience(int exp)
{
	if( !valid_modify(previous_object()) ) return 0;
	if( exp >= 0 ) experience = exp;
	return 1;
}

int gain_experience(int exp)
{
	string temp;
	if(!wizardp(this_object())){
		temp=explode(base_name(previous_object()),"/")[0];
		if ((temp== "u")||(temp=="open")) return 0;
	}
        experience += exp;
        if( experience < 0 ) experience = 0;

	return 1;
}

int query_experience()
{
	return experience;
}

int set_perm_stat(string which, int value)
{
	string *attrs;

        if( !valid_modify(previous_object()) )
        {
   ANNOUNCE->log_file1("BAD_MODIFY",base_name(previous_object())+
                        " try to modify "+this_object()->query("name")+
                        "'s stats "+which+" "+value+"\n");
                return 0;
        }
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
		value <= (userp(this_object())?MAX_ATTRIBUTE:MAX_MONSTER_ATTRIBUTE) ) {
		stats[which] = value;
		return 1;
	} else return 0;
}

int modify_stat(string which, int value)
{
	string *attrs;
	if( !valid_modify1(previous_object()) ) return 0;
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
	// Mounted player won't have encumbered problem. - Annihilator
	if( which == "dexterity" && userp(this_object())
	&& !this_object()->query_temp("mounting") ) {
		load = (int)this_object()->query("load");
		max_load = (int)this_object()->query("max_load");
		if( load >= ( max_load * 9 / 10 ) )
			s -= s*(10000*load - 9000*max_load)*5/(10000*max_load);
	}
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
	if( !valid_modify(previous_object()) ) return 0;
	skills = allocate_mapping(10);
	return 1;
}

int set_skill(string what, int val)
{
	if( !valid_modify(previous_object()) ) return 0;
	if( val < 0 || val > 100 ) return 0;
	skills[what] = val;
	if( val==0 ) map_delete(skills, what);
	return 1;
}

int modify_skill(string what, int val)
{
	if( !valid_modify1(previous_object()) ) return 0;
	if( undefinedp(mod_skills[what]) )
		mod_skills += ([ what : val ]);
	else mod_skills[what] += val;
	return 1;
}

int query_exp_stock()
{
	if( level > MAX_PLAYER_LEVEL )
		return experience - (int)STATS_D->query_level_exp(MAX_PLAYER_LEVEL-1);
	else
		return experience - (int)STATS_D->query_level_exp(level-1);
}

int advance_cost(string what)
{
	int i, l, exp;

	if( !what || what=="" )
		return (int)STATS_D->query_level_exp(level);

	if( strlen(what)==3 )	// Speed up converting
		switch(what) {
			case "str": what = "strength";			break;
			case "int": what = "intelligence";		break;
			case "dex": what = "dexterity";			break;
			case "con": what = "constitution";		break;
			case "pie": what = "piety";				break;
			case "kar": what = "karma";				break;
			default:	return -1;
		}
	if( undefinedp(stats[what]) ) return -1;
	return (int)STATS_D->query_stat_exp( stats[what] );
}

int train_cost(string what)
{
	int i, sk, exp;

	if( !what ) return -1;
	if( !STATS_D->is_skill(what) ) return -1;
	if( undefinedp(skills[what]) ) sk = 0;
	else sk = skills[what];
	return (int)STATS_D->query_skill_exp( sk + 1 );
}

int query_max_load()
{
	object ob;

	if( !ob=this_object()->query_temp("mounting") )
		return query_stat("strength") * 50 + 300;
	else
		return (int)ob->query("max_load") -(int)this_object()->query("weight");
}

int query_special_defense(string type)
{
	string race;
	int natural;

	natural = (int)this_object()->query("special_defense/"+type);
	if( !natural && type != "none" && type != "monk" && type != "scholar")
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
	if ((special_defense[type] > 70) && ( !this_object()->query("npc") ))
		special_defense[type] = 70;
	return 1;
}
