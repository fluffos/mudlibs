inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	}
void create()
{
	set_name(HIW"乌鸡白凤丸"NOR, ({"wujibaifeng wan", "wan"}));
	set("unit", "颗");
        set("long", "这是一颗乌鸡白凤丸，据说可以美容护肤，清肠通便。\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("你要吃什么？\n");
        if(arg=="wan")
	{
		me->add("max_neili",50);
    me->add("max_jingli",30);
		
    message_vision(HIW"$N吃下一颗乌鸡白凤丸，只觉得一股清凉真气从丹田升起，四肢百骸说不出的舒服!\n"NOR,me);

		destruct(this_object());
	}
	return 1;
}
