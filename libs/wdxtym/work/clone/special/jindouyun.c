// sunfenger.c

#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
	set_name("筋斗云", ({ "jindou yun" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "朵");
		set("long", "这是神奇的魔法道具，可以瞬间飞往(fly)其他人身边。\n");
		set("no_sell", "这是什么东西？\n");
		set("base_value", 1);
		set("base_weight", 10);
		set("base_unit", "片");
	}
	set_amount(1);
	setup();
}

void init()
{
	add_action("do_flyto", "flyto");
}

int do_flyto(string arg)
{
	object me;
	object who;
	object env;

	if (! query_amount())
		return 0;

	if (! arg)
		return notify_fail("你想飞到谁的身边？\n");

	who = find_player(arg);
	if (! objectp(who)) who = find_living(arg);
	if (! objectp(who))
		return notify_fail("没有这个人啊！\n");

	if (! objectp(env = environment(who)))
		return notify_fail("这个人不知道在那里耶！\n");

	me = this_player();
	if (env == environment(me))
		return notify_fail("你在原地乱蹦哒的啥？\n");

	if (me->is_busy())
		return notify_fail("等你忙完了再说。\n");

	if (me->query("doing"))
		return notify_fail("等你计划完了再说。\n");

	message_vision(HIM "$N" HIM "撕下一片筋斗云，跳上去，"
		       "喝道：“太上老君急急如律敕令！疾！”\n"
		       "只听“呼”的一下，$N" HIM "不见了！"NOR"\n",
		       me);
	message("vision", HIM "忽见一朵云彩缓缓飘下，" + me->name() + HIM
			      "慢慢的踱了下来。"NOR"\n", env);
	tell_object(me, HIM "云彩飞呀飞..."NOR"\n");
	me->move(env);

	add_amount(-1);
	return 1;
}

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}
