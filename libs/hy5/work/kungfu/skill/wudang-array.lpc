// sword.c

#include <ansi.h>

inherit SKILL;

int valid_enable(string usage) { return usage=="array"; }

int form_array(object leader)
{
	object *member;

	member = leader->query_team();
	if( sizeof(member) > 4 )
		return notify_fail("四象两仪阵最多4人，多一个都不行。\n");
	message_vision( HIG "$N率领众人分四象站定方位，组成了「四象两仪阵」！\n" NOR, leader);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"wudang-array/" + action;
}

