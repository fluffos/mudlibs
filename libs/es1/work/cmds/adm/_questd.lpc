// _questd.c
// This command gives admin the power to maintance quests management.
// by Kyoko 10/05/94

#include <mudlib.h>
#include <daemons.h>
#include <quest.h>

inherit DAEMON;

int help();

int cmd_questd(string arg)
{
	mapping quests, quest;
	string *names, name, msg;
	int level, i, j, point, number;

	if( !member_group(getuid(this_player()), "admin") ) return 0;
	if( !arg ) {
		write(set_color("The quests now defined in ES are:\n", "HIY"));
		quests = (mapping)QUEST_D->query_quests();
		if( !quests || !sizeof(quests) || !names = keys(quests) ||
			!sizeof(names) )
			write(set_color("No any quests defined!!\n", "HIR"));
		else
			for( i=0; i<sizeof(names); i++ ) {
				level = (int)QUEST_D->query_quest_level(names[i]);
				printf("Name: "+set_color("%s(%s)\n", "HIG"),
					to_chinese(names[i]), names[i]);
				msg = "";
				for( j=1; j<=level; j++ )
					msg += sprintf(set_color("Level %d: %3d    ", "HIC"),
						j, QUEST_D->query_quest_point(names[i], j) );
				write(iwrap(msg));
			}
		return 1;
	}
	if( arg == "-l" ) {
		write(set_color("The quest points limit for each level:\n", "HIY"));
		for( i=1; i<21; i++ )
			printf("Level %2d: %4d Points.\n", i,
				(int)QUEST_D->query_qpts_limit(i));
		return 1;
	}

	if( sscanf(arg, "-l %d %d", level, number ) == 2 ) {
		if( level < 1 || level > 20 || number < 0 ) return help();
		QUEST_D->set_qpts_limit(level, number);
		write("Ok.\n");
		return 1;
	}

	if( sscanf(arg, "-a %s %d %d", name, level, point ) == 3 ) {
		QUEST_D->set_quest(name, level, point);
		write("Ok.\n");
		return 1;
	}

	if( sscanf(arg, "-a %s %d", name, point ) == 2 ) {
		QUEST_D->set_quest(name, 1, point);
		write("Ok.\n");
		return 1;
	}

	if( sscanf(arg, "-d %s", name) == 1 ) {
		QUEST_D->remove_quest(name);
		write("Ok.\n");
		return 1;
	}

	return help();
}

int help()
{
	int i;

	write( @TEXT
Syntax: questd
        questd -l [lvl limit]
        questd -a <name> [level] <point>
        questd -d <name>

    This command lets admins manage the quest system.
Options are:
l             - show the level <-> minimun quest points table.
l lvl limit   - set the minimun quest points of level lvl.
a <name> ...  - make a quest legal.
d <name>      - clear a legal quest.

name: the quest name.
level: the quest level of building, if the quest is first setup, set to 1,
       and if the quest is an old one then set to ( old level + 1 ).
       if level not given, default is 1.
point: the quest point of the quest in level.
lvl must be 1 to 20, and please remember the limit can't be < 0.
TEXT
	);
	return 1;
}
