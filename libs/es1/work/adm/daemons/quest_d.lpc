// quest_d.c
// Added quest database maintainance and log.
// by Kyoko@Eastern.Stories (10/05/94)

#include <mudlib.h>
#include <quest.h>
#include <uid.h>

inherit SAVE;

mapping quests = ([]);
mapping quest_level = ([]);
mapping quest_points_limit = ([]);

void create()
{
	int i;

	seteuid( getuid() );
	set_persistent(1);
	save::create();
	for( i=0; i<21; i++ )
		if( undefinedp(quest_points_limit[i]) )
			quest_points_limit[i] = 0;
}

// This function is to make a quest as an legal one. Should be
// called by Root or Admin.
varargs int set_quest(string name, int level, int point)
{
	string uid;
	mapping tmp=([]);

	uid = geteuid( previous_object() );
	if( uid != ROOT_UID && !member_group(uid, "admin") ) return 0;

	if( !level || level < 1 ) level = 1;
	if( !point || point < 1 ) point = 1;
	if( undefinedp(quests[name]) )
		tmp[0] = 0;
	else tmp = quests[name];
	if( undefinedp(quest_level[name]) || level > quest_level[name] )
		quest_level[name] = level;
	tmp[level] = point;
	quests[name] = tmp;
	save_data();
	return 1;
}

// This function is to delete a leagl quest. Should be
// called by Root or Admin.
int remove_quest(string name)
{
	string uid;

	uid = geteuid( previous_object() );
	if( uid != ROOT_UID && !member_group(uid, "admin") ) return 0;

	map_delete(quests, name);
	map_delete(quest_level, name);
	save_data();
	return 1;
}

// This function is called by user->finish_quest() to confirm a
// quest's legality.
int valid_quest(string name, int level)
{
	if( undefinedp(quests[name]) ) return 0;
	if( undefinedp(quest_level[name]) || level > quest_level[name] ) return 0;
	if( undefinedp(quests[name][level]) ) return 0;
	return 1;
}

int query_quest_point(string name, int level)
{
	if( undefinedp(quests[name]) ) return 0;
	if( undefinedp(quest_level[name]) || level > quest_level[name] ) return 0;
	if( undefinedp(quests[name][level]) ) return 0;
	return quests[name][level];
}

// the extra check when advance to a wizard about quests.
int check_wizard(object user)
{
	return 1;
}

int check_quest(object user)
{
	int qpts, lvl;

	if( !user || !objectp(user) ) return 0;
	if( !CHECK_QUEST ) return 1;
	lvl = (int)user->query_level();
	if( lvl < 0 || lvl > 19 ) return 1;
	qpts = (int)user->query_quest_points();
	if( qpts < quest_points_limit[lvl+1] ) return 0;
	if( lvl == 19 ) return check_wizard(user);
	return 1;
}

int set_qpts_limit(int lvl, int number)
{
	string uid;
	
	uid = geteuid( previous_object() );
	if( uid != ROOT_UID && !member_group(uid, "admin") ) return 0;

	if( lvl < 1 || lvl > 20 ) return 0;
	quest_points_limit[lvl] = number;
	save_data();
	return 1;
}

int query_qpts_limit(int lvl)
{
	if( lvl < 1 || lvl > 20 ) return 0;
	return quest_points_limit[lvl];
}

mapping query_quests()
{
	return quests;
}

int query_quest_level(string name)
{
	if( undefinedp(quests[name]) || undefinedp(quest_level[name]) ) return 0;
	return quest_level[name];
}

int query_quests_number()
{
	return sizeof(quests);
}
