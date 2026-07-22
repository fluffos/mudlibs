// guard.c

inherit F_CLEAN_UP;

mapping default_dirs = ([
	"north":        "北",
	"south":        "南",
	"east":	        "东",
	"west":	        "西",
	"northup":      "北边",
	"southup":      "南边",
	"eastup":       "东边",
	"westup":       "西边",
	"northdown":    "北边",
	"southdown":    "南边",
	"eastdown":	"东边",
	"westdown":	"西边",
	"northeast":    "东北",
	"northwest":    "西北",
	"southeast":    "东南",
	"southwest":    "西南",
	"up":           "上",
	"down":	        "下",
	"out":	        "外",
	"in" :          "里",
	"enter" :       "里面",
]);

int main(object me, string arg)
{
	string dir;
	object ob, *guards;
	mixed old_target;

	if( me->is_busy() )
		return notify_fail("你现在没有办法分心去做这类事！\n");

	old_target = me->query_temp("guardfor");

	if( !arg || arg=="" ) {
		if( !old_target )
			return notify_fail("指令格式：guard <生物> | <物品> | <方向>\n");
		if( objectp(old_target) )
			if( living(old_target) )
				write("你正在守护著" + old_target->name() + "。\n");
			else
				write("你正守在" + old_target->name() + "一旁，防止别人拿走。\n");
		else
			write("你正守住 " + old_target + " 的方向，不准任何人离开。\n");
		return 1;
	}

	ob = present(arg, environment(me));

	if( ob ) {
		if( ob==me ) return notify_fail("守卫自己？不用说你也会做，对吧。\n");
		me->set_temp("guardfor", ob);
	}
	else if( environment(me)->query("exits/" + arg) ) {
		if( environment(me)->query("no_fight") )
			return notify_fail("这里不准战斗——也不准堵住别人去路！\n");
		me->set_temp("guardfor", arg);
		me->disable_command("skill");
	}
	else if( arg!= "cancel" )
		return notify_fail("你要守卫谁，什麽，或是哪个方向？\n");

	if( objectp(old_target) ) {
		guards = old_target->query_temp("guarded");
		guards -= ({ me });
		old_target->set_temp("guarded", guards);
		if( living(old_target) )
			tell_object( old_target, me->name() + "不再保护你了。\n");
	} else if( stringp(dir = me->query_temp("pending/guarding")) ) {
		guards = environment(me)->query("guarded/" + dir);
		if( arrayp(guards) ) {
			guards -= ({ me });
			environment(me)->set("guarded/" + dir, guards);
		}
		me->enable_path();
	}
	me->delete_temp("guardfor");

	if( arg=="cancel" ) {
		write("什么也不用守了，真是好轻松。\n");
		return 1;
	}

	if( objectp(ob) ) {
		ob->add_temp("guarded", ({ me }) );
		if( living(ob) )
			message_vision("$N开始保护$n。\n", me, ob);
		else
			message_vision("$N站到地上的$n一旁守著，以免别人取走。\n", me, ob);
	} else {
		me->set_temp("pending/guarding", arg);
		environment(me)->add("guarded/" + arg, ({ me }));
		message_vision("$N开始守住往" + default_dirs[arg] + "的方向不让任何人通行。\n", me);
	}

	return 1;
}

// guard             不接任何参数会显示你目前 guard 的对象。
int help(object me)
{
	write(@TEXT
指令格式：guard [<某人>|<地上某物>|<某个出口>|cancel]

这个指令有三种作用方式，分别如後：

guard <某人>      保护<某人>，当他／她受到攻击时，保护者会自动加入战斗，并且
                  受攻击的顺位会排在被保护者前面，由於只有攻击顺位前四个目标
                  才会受到攻击，因此理论上如果有四个人  guard 你，你就不会受
                  到任何攻击。

guard <地上某物>  守住放在地上的某件东西，防止别人来拿，只要你还在这个房间，
                  而且没有忙著其他事，别人就无法拿走这件东西。若你离开后再回
                  来，只要东西还在，那仍将在你守护之下。

guard <某个出口>  守住某个出口防止所有人从这个出口离开，可以用来阻拦善於逃跑
                  的敌人或拦路打劫做坏事。
                  目前暂不开放守出口这个功能。

guard cancel      取消先前的 guard 对象。

注意，通常除了 guard <某人> 的情形以外，只要你一移动，guard 的状态就会解除。
TEXT
	);
	return 1;
}
