// team command: form

#include <ansi.h>

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string target;
        object *t;

		  if( !arg )
		  		return notify_fail("team form <阵法> - 如果队伍的领队学过阵法的话，可以将队伍中的成员组织成
                   某种阵形，组成阵形的状态只要领袖一移动就会解除。\n");	
        if (! pointerp(t = me->query_team()) || ! me->is_team_leader())
                return notify_fail("你必须是一个队伍的领袖才能组织阵形。\n");

        if (sscanf(arg,"%s to %s",arg,target) != 2)
                target = "no enemy";

        if (! me->query_skill(arg, 1))
                return notify_fail("这种阵形你没学过。\n");
        if (target == "no enemy")
                return SKILL_D(arg)->form_array(me);
        else
                return SKILL_D(arg)->form_array(me,target);
}

