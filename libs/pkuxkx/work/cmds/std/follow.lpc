// follow.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
    object *team;

	if( !arg ) return notify_fail("指令格式：follow <某人>|none。\n");

	if( arg=="none")
		if( me->query_leader() ) {
            if (arrayp(team = me->query_team()))
            {
                if ( me->is_team_leader() )
                {
                    message_vision(HIY "$N决定解散队伍。\n" NOR, me);
                    me->dismiss_team();
                }
                else 
                {
                    message_vision(HIY "$N决定脱离$n的队伍。\n" NOR, me, team[0]);
                    me->dismiss_team();
                }
            }
			me->set_leader(0);
                        write("你决定自己单独行动。\n");
			return 1;
		} else {
			write("你现在并没有跟随任何人。\n");
			return 1;
		}

	if( !objectp(ob = present(arg, environment(me))) )
		return notify_fail("这里没有 " + arg + "。\n");

	if( !ob->is_character() )
		return notify_fail("什么？跟随...." + ob->name() + "。\n");

	if( ob==me )
		return notify_fail("跟随自己？\n");

    if (arrayp(team = me->query_team()))
    {
        if ( me->is_team_leader() )
        {
            message_vision(HIY "$N决定解散队伍。\n" NOR, me);
            me->dismiss_team();
        }
        else 
        {
            message_vision(HIY "$N决定脱离$n的队伍。\n" NOR, me, team[0]);
            me->dismiss_team();
        }
    }
	me->set_leader(ob);
                if (ob->visible(me))
		{
	       message_vision("$N决定开始跟随$n一起行动。\n", me, ob);
		}

	return 1;
}

int help (object me)
{
        write(@HELP
指令格式 : follow [<生物>|none]
 
这个指令让你能跟随某人或生物。
如果输入 follow none 则停止跟随。
这个指令是组建 team 的先决条件。
 
HELP
);
        return 1;
}
