// /d/baituo/npc/obj/jumangdan.c
#include <ansi.h>
inherit ITEM;
void decay();

void create()
{
        set_name("巨蟒胆", ({"jumang dan", "dan" }));
        set("unit", "枚");
        set("long", "一枚深紫色的蟒蛇胆，甚是腥臭，是极好的药引。\n");
        set("value", 20000);
	set("medicine", 1);
        setup();
}

void init()
{
	remove_call_out("decay");
	call_out("decay", 300);
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();
	if (!id(arg))
        return notify_fail("你要吃什么？\n");

	if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成。\n");

	me->add("food", 50);
	me->add("water", 50);
	me->add("neili", 500);

	if(me->query("neili") > me->query("max_neili") * 2)
	me->set("neili", me->query("max_neili") * 2);

	if(me->query_temp("apply/strength") < 10)
	me->add_temp("apply/strength", 1);

	me->add("jingli", 100);
	if(me->query("jingli") > me->query("max_jingli") * 2)
	me->set("jingli", me->query("max_jingli") * 2);

	tell_object(me, MAG"你张口轻轻一咬，蛇胆外皮便即破裂，登觉满口苦汁，腥极苦极，几乎要呕将出来。\n"
			+ "可稍过片刻，你只觉呼吸顺畅，耳清目明，精神爽利，力气大增。\n"NOR);

        message("vision", MAG + me->name() + "吞下一颗巨蟒胆，精神大旺，尤胜平时。\n"NOR,
			environment(me), ({me}));
	me->start_busy(1);
	destruct(this_object());
	return 1;
}

void decay()
{
	object where = environment(this_object());
	if ( interactive(where) )
		message("vision", MAG"蛇胆啪的一声破了，弄得你一身甚是腥臭。\n"NOR,
			where);
	else
		message("vision", MAG"蛇胆啪的一声破了，汁水流了一地。\n"NOR,
			where);
	destruct(this_object());
}