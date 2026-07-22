// OBJ: ling.c
// Date: Look 99/04/25

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_baifang", "baifang");
}

void create()
{
        set_name("令牌", ({"ling pai", "ling"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
              set("unit", "块");
              set("long", HIY "这是块桃花岛的令牌，已经很陈旧了，四角磨的很圆滑。\n" NOR );
              set("value", 10000);
//              set("no_drop", 1);
              set("no_get", 1);
        }
        setup();
}

int do_baifang(string str)
{
        object my_object,me = this_player();
	if (!str)
	        return notify_fail("你要拜访谁啊？\n");
        if (!(my_object = present(str, environment(me))))
		return notify_fail("你要找的人不在这里。去别处找找看吧。\n");
	if ( str != "huang yaoshi")
		return notify_fail(my_object->query("name")+"说道："+RANK_D->query_respect(me)+"远道而来，里面请，里面请！\n");
        if (!living(my_object))
		return notify_fail("哦，你得先把他弄醒在说。\n");
	tell_object(me, HIC + my_object->query("name")+"深深的叹了口气。\n");
	tell_object(me, HIC + my_object->query("name")+"说道：默风他们当年也是受了别人的牵连，没想到他如今还记得我这个师傅。\n" NOR);
	tell_object(me, HIC + RANK_D->query_respect(me)+"你回告他，就说老朽再次收他回师门！\n" NOR);

	me->delete_temp("ylj/step6");
	me->set_temp("ylj/stepend", 1);
	return 1;
}
