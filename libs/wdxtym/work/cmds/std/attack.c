// attack.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, *inv;
	int cost, i = 0;

	seteuid(getuid());

	if(environment(me)->query("no_fight"))
		return notify_fail("这里不许打斗！\n");
	if ( me->query_skill("training",1) < 30 )
		return notify_fail("你的驭兽术还不纯熟，无法让野兽帮你咬人！\n");
	cost = me->query("max_jing")/(me->query_skill("training",1)/10) - 10;
	if ( me->query("jing") <= cost )
		return notify_fail("现在你太累了，无法让野兽帮你咬人。\n");
	if ( !arg )
		return notify_fail("你要让什么野兽帮你咬谁？\n");
	if( !objectp(ob = present(arg, environment(me)) ))
		return notify_fail("这里没有这个东西吧？\n");

	inv = all_inventory(environment(me));
	while( i < sizeof(inv) && i >= 0 )
	{
		if( inv[i]->query_temp("owner") == me->query("id") )
		{
			if( inv[i]->is_fighting() )
				return notify_fail("已经有野兽在帮你咬人了！\n");
			if( inv[i]->is_busy() )
				return notify_fail(inv[i]->name() + "正在忙乎，没空理你！\n");
			if( (ob->query("age")< 16 ) && userp(ob))
				return notify_fail(ob->query("name")+"还是个小孩子，算了吧...！！\n");
			message_vision("只见$N冲着"+inv[i]->name()+"口中一声呼哨，它一窜就向$n扑了上去。\n",me,ob);
			me->receive_damage("jing", cost);
			inv[i]->fight_ob(ob);
			return 1;
		}
		i++;
	}
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : attack <动物>

此指令可用于让某动物帮你攻击，咬别人。对于已经驯服的动物，可以进行
下述指令：

基本指令：
	come <动物名>:		  让动物跟随主人行动。
	stay:			   停止动物的跟随状态。
	attack <某人>:		  让动物攻击敌人。
	stop <动物名>:		  让动物停止对人的攻击。
	release:			结束主奴状态，将动物放离。

特殊指令：（只对某些动物适用）
	qi(ride) <动物名>:	      骑，如骑马，虎，雕，鲨等。
	xia(unride) <动物名>:	   下，离开坐骑。
	wei(feed) <动物名>:	     替动物喂食。
	yin <动物名>:		   给动物饮水。

HELP
	);
	return 1;
}

