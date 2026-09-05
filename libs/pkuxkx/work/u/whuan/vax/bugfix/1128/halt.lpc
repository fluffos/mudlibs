// halt.c
// By Xiang@XKX (12/17/95)
// dewolf :: when active halt, npc enemy stop busy.  2005 11 28

int main(object me, string arg)
{
	object *my_enemy;
	int i;
        if (me->is_fighting()) {
                if( wizardp(me) )
                {
                        me->remove_all_killer();
                        message_vision("$N使用巫师神力停止了这场战斗。\n",me);
                }
                else
                {
			// dewolf :: when active halt, npc enemy stop busy,  when p VS p. ........ dunno how to do
			   if ((my_enemy = me->query_enemy()) && arrayp(my_enemy))
			   {
				for (i=0;i<sizeof(my_enemy);i++)
				{
					if (my_enemy[i]->query_busy() && !userp(my_enemy[i]))
					{
						my_enemy->start_busy(0);
					}
				}
                        }
			   me->remove_all_enemy();
                        message_vision("$N身行向后一跃，跳出战圈不打了。\n", me);
                }
        }
        else if (!me->is_busy()) 
                return notify_fail("你现在不忙。\n");
        else if ((int)me->query_temp("pending/exercise") != 0) {
                message_vision("$N把正在运行的真气强行压回丹田，站了起来。\n", me);
                me->interrupt_me();
        }
        else if ((int)me->query_temp("pending/respirate") != 0) {
                message_vision("$N强行收回精气，站了起来。\n", me);
                me->interrupt_me();
        }
        else if ((int)me->delete_temp("pending/practice") != 0) {
                message_vision("$N强行收回内力，停了下来。\n", me);
                me->interrupt_me();
        }
//      else if ((int)me->query_temp("pending/respirate") != 0)
//              me->interrupt_me();
//      me->interrupt_me();

        return 1;
}
 
int help(object me)
{
        write(@HELP
指令格式: halt
 
这个指令可以让从当前的busy状态中解脱出来。
 
包括正在战斗，打坐，吐纳等状态。
 
HELP
        );
        return 1;
}
