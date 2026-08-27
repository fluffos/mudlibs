//#pragma save_binary

// conditions_d.c 
// This is the condition daemon, which used to find the condition object.
// Created by Kyoko@Eastern.Stories 11-09-93

#include <mudlib.h>
#include <conditions.h>
#include <uid.h>

inherit DAEMON;

mixed find_condition(string name);

void create()
{
	seteuid( ROOT_UID );
}

// this daemon will never be swapped.
int clean_up() { return 0; }

nomask  int valid_conditionsd_check(object ob)
{
	string euid;

	euid = geteuid(ob);
	if( euid == ROOT_UID ) return 1;
	if( member_group( euid, "admin" ) ) return 1;
	return 0;
}

mixed find_condition(string name)
{
	object cond_ob;

	if( !name || name == "" ) return 0;
	name = lower_case(name);
	if( cond_ob = find_object_or_load(CONDITION_MASTER(name)) )
		return cond_ob;
	return 0;
}
