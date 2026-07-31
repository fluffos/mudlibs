// judgement.c for help robot dropping treasures


#define COUNTROOM "/d/wizard/robot_court"

#include <login.h>
#include <ansi.h>

int update_condition(object me, int duration)
{
	object *mine;
        int i;
	
        if (duration < 1)
        {
        	if (base_name(environment(me)) == COUNTROOM)
                duration = 11;
            me->clear_condition("judgement");
        }
        if (!duration)
        	return 0;
        if (base_name(environment(me)) != COUNTROOM)
                me->clear_condition("judgement");
        mine = deep_inventory(me);

        if (base_name(environment(me)) == COUNTROOM
         && sizeof(mine)
         && (duration == 4 || duration == 8))
        {
        	for (i=0;i<sizeof(mine);i++)
        	{
                if (mine[i]->query("treasure") || mine[i]->query("unique"))
        		{
        			tell_object(me,"机器人法官发现你似乎有所动作，立刻将你的"+mine[i]->name()+NOR"没收了。\n");
        			destruct(mine[i]);
        			break;
        		}
        	}
        }
        me->apply_condition("judgement", duration - 1);
        return 1;
}
