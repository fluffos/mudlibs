// sword.c

#include <ansi.h>

inherit SKILL;

int valid_enable(string usage) { return usage=="array"; }

int form_array(object leader)
{
	object *member;

	member = leader->query_team();
	if( sizeof(member) > 7 )
		return notify_fail("北斗七星阵最多七人，多一个都不行。\n");
	message_vision( HIG "$N率领众人四下站定方位，组成了「北斗七星阵」！\n" NOR, leader);
	return 1;
}
