// team.c

#include <ansi.h>

int main(object me, string arg)
{
	object ob, *team;

	team = me->query_team();

	if ( !arg )
	{
		if ( !arrayp( team ) )
			return notify_fail("现在你的队伍中没有任何成员！\n");
		write( "现在你所在队伍的成员有：\n\n" );
        printf("  ※  %-14s %-14s %-14s\n", "姓名", "ＩＤ", "气血");
		for (int i=0; i<sizeof(team); i++)
            printf("  ※  %-14s %-14s %d\n", team[i]->query("name"), "("+team[i]->query("id")+")", team[i]->query("qi"));
		printf("\n");
		return 1;
	}

	if ( arg == "none" )
	{
		if ( !arrayp(team) )
			return notify_fail("你现在没有加入任何队伍！\n");
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
		return 1;
	}

	if ( !(ob = present( arg, environment(me) )) )
		return notify_fail("想把谁加入到你的队伍中？\n");

	if ( !ob->is_character() )
		return notify_fail("看清楚点儿，那并不是活物！\n");

      if ( !userp(ob))
            return notify_fail("不能跟npc一组！\n");

	if ( ob == me )
		return notify_fail("这 ... 这有用吗？\n");

	if ( ob->query_leader() != me )
		return notify_fail("看样子对方并没有加入的意思。\n");

	if ( arrayp(team) && (team[0] != me) )
		return notify_fail("你没有这个权力！\n");

	if ( !me->add_team_member(ob) )
	{
		message_vision(HIY "$N决定将$n驱逐出队伍。\n" NOR, me, ob);
		return me->dismiss_team(ob);
	}
	else
	{
		message_vision(HIY "$N决定让$n加入队伍。\n" NOR, me, ob);
		return 1;
	}
}

int help()
{
	write(@HELP

指令格式：team [ none | <某人> ]

ＴＥＡＭ  ＬＥＡＤＥＲ可以用这个指令来加入、开除
一个成员或者解散一个队伍，ＴＥＡＭ  ＭＥＭＢＥＲ
可以用这个指令来查看队伍的状态，以及脱离队伍。另
外，ＦＯＬＬＯＷ别的人将自动脱离或解散队伍。
　　例如：
	team abc   加入或开除一个成员(Team Leader)
	team none  解散队伍(Team Leader)
	team none  脱离队伍(Team Member)
	team       查看队伍中各人的状态

see also : follow

HELP
	);
	return 1;
}
