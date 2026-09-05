// qixing-array.c

#include <ansi.h>

inherit SKILL;

int valid_enable(string usage)  { return (usage == "array")||(usage == "parry"); }

int form_array(object leader)
{
	object *member;

	member = leader->query_team();
	if( sizeof(member) > 7 )
		return notify_fail("北斗七星阵最多七人，多一个都不行。\n");
	message_vision( HIG "$N率领众人四下站定方位，组成了「北斗七星阵」！\n" NOR, leader);
	return 1;
}

int valid_learn(object me)
{
  if ( ((int)me->query_skill("qixing-array", 1) >100 ) && ((int)me->query_skill("xiantian-gong", 1) <= (int)me->query_skill("qixing-array",1)) )
                return notify_fail("你的先天功火候太浅。\n");
  return 1;
}
int practice_skill( object me )
{
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够。\n");
    me->receive_damage("qi", 30);
    return 1;
}
