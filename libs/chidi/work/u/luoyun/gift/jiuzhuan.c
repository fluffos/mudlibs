// jiuzhuan.c 九转金丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "九转金丹" NOR, ({ "jiuzhuan jindan", "dan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗金色的仙丹，传说是太上老君"
                            "精心修炼的灵丹妙药。\n");
                set("value", 1500000);
		set("unit", "颗");
		set("only_do_effect", 1);
	}
}

int do_effect(object me)
{
        int effect;

        log_file("static/using", sprintf("%s(%s) eat 九转金丹 at %s.\n",
                 me->name(1), me->query("id"), ctime(time())));

        effect = 0;
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);
        if (me->query("gift/xiandan") < 4 && random(2))
        {
                effect++;
                write(HIM "你觉得自己的头脑更清醒了。\n" NOR);
                me->add("gift/xiandan", 1);
                me->add("int", 1);
        }

        if (me->query("gift/unknowdan") < 4 && random(2))
        {
                effect++;
                write(HIR "你觉得自己的腿脚更灵活了。\n" NOR);
                me->add("gift/unknowdan", 1);
                me->add("dex", 1);
        }

        if (me->query("gift/xisuidan") < 4 && random(2) &&
            me->query("gender") != "无性")
        {
                effect++;
                write(HIC "你觉得自己的内息更通畅了。\n" NOR);
                me->add("gift/xisuidan", 1);
                me->add("con", 1);
        }

        if (me->query("gift/shenliwan") < 4 && random(2))
        {
                effect++;
                write(HIG "你觉得自己的膂力更强健了。\n" NOR);
                me->add("gift/shenliwan", 1);
                me->add("str", 1);
        }

        if (! effect)
                tell_object(me, "不过你觉得好像没什么作用。\n");

        destruct(this_object());
	return 1;
}

