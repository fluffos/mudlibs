//#pragma save_binary

// guild_d.c 
// This is the guild daemon, which used for check whether belong to a guild.
// Created by Kyoko@Eastern.Stories 11-09-93

#include <mudlib.h>
#include <guilds.h>
#include <uid.h>

inherit DAEMON;

int is_guild(string guild);
string *query_guild_names();

void create()
{
	seteuid( ROOT_UID );
}

// this daemon will never be swapped.
int clean_up() { return 0; }

nomask  int valid_guildd_check(object ob)
{
	string euid;

	euid = geteuid(ob);
	if( euid == ROOT_UID ) return 1;
	if( member_group( euid, "admin" ) ) return 1;
	if( is_guild(euid) ) return 1;
	return 0;
}

int is_guild(string guild)
{
	int i;

	if( !guild || guild == "" ) return 0;
	guild = lower_case(guild);
	i = member_array(guild, CLASS_NAMES);
	i++ ;
	return i;
}

string *query_class_names()
{
	return CLASS_NAMES;
}

object find_guild(string guild)
{
	int i;

	if( !(i=is_guild(guild)) ) return 0;
	return find_object_or_load(GUILD_FILES[i]);
}
