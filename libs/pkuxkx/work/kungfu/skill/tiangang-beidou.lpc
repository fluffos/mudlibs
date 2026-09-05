// sword.cen.c

#include <ansi.h>

inherit SKILL;

int valid_enable(string usage) { return usage=="array"; }

int form_array(object leader)
{
        object *member;

        member = leader->query_team();
        if( sizeof(member) != 7 )
                return notify_fail("天罡北斗阵共需七人，少一个多一个都不行。\n")
;
        message_vision( HIG "$N率领众人四下站定七星方位，组成了「天罡北斗阵」！\n"
 NOR, leader);
        return 1;
}
