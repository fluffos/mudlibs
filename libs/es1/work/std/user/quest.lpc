// quest.c
// By Kyoko 10/05/94

#include <daemons.h>
#include <quest.h>

 mapping quests;
 int quest_points;

int query_quest_level(string name)
{
	if( !mapp(quests) ) quests = ([]);
	if( undefinedp(quests[name]) ) return 0;
	return quests[name];
}

varargs int finish_quest(string name, int level)
{
	int lvl;

	if( !OPEN_QUEST ) return 0;
	if( !level ) level = 1;
	if( !QUEST_D->valid_quest(name, level) ) return 0;
	lvl = query_quest_level(name);
	if( level <= lvl ) return 0;
	quest_points += (int)QUEST_D->query_quest_point(name, level) -
		(int)QUEST_D->query_quest_point(name, lvl);
	quests[name] = level;
	return 1;
}

mixed query_finish_quests()
{
	string *names, *quest;
	int i, j, lvl, level;

	if( !mapp(quests) ) quests = ([]);
	if( !sizeof(quests) || !quest = keys(quests) || !sizeof(quest) ) return 0;
	names = allocate(sizeof(quest));
	for( i=sizeof(quest)-1, j=0; i>=0; i-- ) {
		lvl = query_quest_level(quest[i]);
		level = (int)QUEST_D->query_quest_level(quest[i]);
		if( level < 1 ) {
			map_delete(quests, quest[i]);
			continue;
		}
		if( lvl > level ) quests[quest[i]] = level;
		if( lvl == level ) names[j++] = quest[i];
	}
	return names[0..(j-1)];
}

int query_quest_points()
{
	return quest_points;
}
