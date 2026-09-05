// xinfa.c	东方不败的心法

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("葵花宝典心法", ({ "kuihua xinfa", "xinfa" }));
	set_weight(20000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", "这是一张薄纸，上面密密麻麻写了些字，好象是篇内功的心法。\n");
		set("value", 500);
		set("mingjiao",1);
		set("material", "paper");
	}
	setup();
}

void init()
{
        add_action("do_study", "study");
}

int do_study(string arg)
{
	object me = this_player();

        if (!id(arg))
                return 0;
	if (((string)me->query("title") != MAG "日月神教" NOR + HIR "圣姑" NOR )
		&& ((string) me->query("title") != MAG "日月神教" NOR + HIG "总管" NOR ))
	{
		tell_object(me,"你读了半天，发现与你的武功套路完全不合，没法学习。\n");
		return 1;
	}
	tell_object(me,"你研读了东方不败的武功心法，对葵花宝典上的疑难有了些理解。\n");
	me->delete_temp("crazy");
        return 1;
}

