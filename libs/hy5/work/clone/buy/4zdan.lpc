// shenliwan.c 福缘丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "五转丹" NOR, ({ "5z wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗七彩的五转丹，据说吃了可以转换五转武功。\n");
                set("value", 10000);
		set("no_put",1);
		set("unit", "颗");
	}
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;

        if (! id(arg))
                return notify_fail("你要吃什么？\n");

        me = this_player();
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);
        if (!me->query("4zhuan") && !me->query("5zhuan"))
        {
                message_vision("$N眨眨眼。\n", me);
                tell_object(me, "你觉得这药没啥味道，还不如花生好吃。\n");
        } else
{


if (me->query("zhuanfinal/7",1)==1 && me->query_skill("yinyang-shiertian",1) >=1)
{
me->delete("zhuanfinal/7");
me->delete_skill("yinyang-shiertian");
me->set("zhuanfinal/8",1);
me->set_skill("never-defeated",105);
write(HIY"转换 获得武功【不败神功】!\n"NOR);
}
else if (me->query("zhuanfinal/8",1)==1  && me->query_skill("never-defeated",1) >=1)
{
me->delete("zhuanfinal/8");
me->delete_skill("never-defeated");
me->set("zhuanfinal/7",1);
me->set_skill("yinyang-shiertian",105);
write(HIY"转换 获得武功【阴阳十二重天】!\n"NOR);
}


                tell_object(me, HIR "你觉得似乎自己发生了变化。\n" NOR);
                //me->add("expmax", 10);
}
        destruct(this_object());
	return 1;
}
