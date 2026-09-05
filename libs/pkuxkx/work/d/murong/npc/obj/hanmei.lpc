// medicine: xuelian.c
// Jay 3/18/96

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("寒梅花露", ({"hanmei hualu", "hanmei", "hualu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "滴");
                set("long", "这是阿朱姑娘精心配置的一滴寒梅花露。\n");
                set("value", 100);
        }
        setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if(me->query("family/family_name")!="姑苏慕容")
	{
		write("想偷吃我们姑苏慕容家的东东，不害臊吗？\n");
		return 1;
	}

	if (!id(arg))
    return notify_fail("你要吃什么？\n");

    me->add("max_neili", 1);
    message_vision(HIM "$N吃下一滴寒梅花露，感到气血膨胀，内力充盈 !\n" NOR, me);

    destruct(this_object());
    return 1;
}
