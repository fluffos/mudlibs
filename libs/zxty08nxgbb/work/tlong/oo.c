// baowu.c
// by smash
#include <ansi.h>
inherit ITEM;


void create()
{
	set_name(HIG"宝物"NOR, ({"bao wu"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "你挖出来的宝物，不知道有什么作用。\n");
		set("unit", "个");
		set("value", 50);
		 set("mingjiao", 1);
	}
}
int init()
{
	add_action("do_use", "use");
}

int do_use(string arg)
{
	object me = this_player();
        int i, j;
        i = (int)me->query_skill("literate",1);
	if(arg=="bao wu")
	{
		message_vision(HIW"$N小心翼翼的将宝物打开。\n"NOR, me);
		tell_object(me,HIW"哇，好神奇，你的读书写字增加了。\n"NOR);
		me->set_skill("literate", i + 50);
		destruct(this_object());
	}
	return 1;
}
