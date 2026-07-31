// jinsha.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "藏宝图" NOR, ({ "cang baotu" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一张黑风山藏宝图。\n");
		set("unit", "张");
		set("value", 10);
		set("where", "/d/city/jiaowai7");
		set("fuben_type", "heifeng");
		set("only_do_effect", 1);
		set("weight", 10);
	}
	setup();
}

int do_effect(object me)
{
	string family,*skills;
	int i;

	message_vision(CYN "$N" CYN "拿着一张" + name() + CYN "，开始对比着观察四周。"NOR"\n", me);
	if(base_name(environment(me))!=query("where"))
	{
		tell_object(me,"你对照藏宝图在这里仔细搜索了一阵，结果却毫无收获。\n");
		return 1;
	}

	if(FUBEN_D->create_fuben(me,query("fuben_type")))
	{
		message_vision(CYN "$N" CYN "发现了一个神秘的洞口，不知通向哪里？"NOR"\n", me);
		destruct(this_object());
	}

	return 1;
}
