// /d/guiyunzhuang/obj/nvwashi.c
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL"女娲石"NOR, ({"nvwa shi", "shi", "stone" }));
        set("unit", "枚");
        set("long", "一枚晶莹剔透的女娲石，服食之后有增长内力的功效。\n");
        set("value", 100000);
	set("medicine", 1);
        setup();
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();
	if (!id(arg))
        return notify_fail("你要吃什么？\n");

	if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成。\n");

	me->add("max_neili", 20);
	me->add("eff_neili", 20);
	me->add("neili", 20);

	tell_object(me, HIY"你张口将"NOR + YEL"女娲石"HIY"囫囵吞下，随即闭气运功，似乎内功大有进步。\n"NOR);

        message("vision", MAG + me->name() + "吞下一颗"NOR + YEL"女娲石"MAG"，随即开始闭气运功。\n"NOR,
			environment(me), ({me}));
	me->start_busy(5);
	destruct(this_object());
	return 1;
}

