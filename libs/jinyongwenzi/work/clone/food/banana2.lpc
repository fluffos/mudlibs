//香蕉皮
//作用：破坏一些robot
//香蕉皮只对正在做job的人有作用
//count表示移动的房间数目
//player有可能没有发生移动，原因是random出口时又回到了起点
//Yanqi 10/26/2k

#include <ansi.h>
inherit ITEM;

int flag = 0;

void create()
{
	seteuid(getuid());
	set_name(HIY"香蕉皮"NOR, ({ "xiangjiao pi","pi"}) );
	set("long", "一块香蕉皮。\n");
	set("unit", "块");
	set("value",10);
	set("no_get",1);
	set_weight(5);
	setup();
}

void init()
{
	object me = this_player();
	object env;
//	int i,count = 5;
	int num;
//	mapping exits;
//	string *dirs;

	if (flag) return;
	if (!me) return;
	if (wizardp(me) || !userp(me)) return;
	env = environment();
	if (environment(me) != env) return;

	if (me->is_busy() || me->is_fighting() || !me->query_conditions_by_type("job") || !me->query("lastroom")) return;
/*	怎么能把人乱 move 呢？容易造成 bug
	for (i=0;i<random(count);i++) {
		if (!mapp(exits = env->query("exits"))) return 0;
		dirs = keys(exits);
		if (sizeof(dirs) < 1) return;
		dirs = keys(exits);
		if (!objectp(env = load_object(exits[dirs[random(sizeof(dirs))]]))) return;
	}
*/

	if (random(3) == random(4)) {
		num = 1+random(me->query("str") * 6 / me->query_dex());
		me->start_busy(num/2);
		message_vision(HIW"\n$N一个没留意，一脚踩在一块香蕉皮上面，结果滑了一个大跟头。\n"NOR,me);
		flag = 1;
		call_out("pa", num - 1, me);
	}
        return;
}

int move(mixed dest, int silently)
{
	flag = 1;
	::move(dest, silently);
	flag = 0;
	return 1;
}

void pa(object me)
{
	flag = 0;
	if (!me) return;
	message_vision(HIW"半晌$N才爬了起来。$N气得不由破口大骂：“是谁把香蕉皮到处乱扔！”\n"NOR, me);
	message_vision(HIY"$N把香蕉皮一脚给踢飞了。\n"NOR,me);
	move(me->query("lastroom"), 1);
	message_vision("$N飞了过来。\n",this_object());
}
