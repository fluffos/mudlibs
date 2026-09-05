// File		: kongzhong.c
// Created By	: iszt@pkuxkx, 2007-02-25

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "空中");
	set("long", @LONG
你正在空中急速下坠，耳边风呼呼的刮着，全身的重量如同全部消失一般，
白晃晃的雪地正在飞快的逼近你的眼前，你感到马上就要窒息，手足拼命的舞动，
却是茫茫然不知所措！
LONG);

	set("outdoors", "凌霄城");

	setup();
}

void init()
{
	call_out("fall", 2, this_player());
}

void fall(object me)
{
	if(!me)
		return;
	message_vision("四周的景物正在不断闪过……\n", me);
	call_out("fallb", 2, me);
	return;
}

void fallb(object me)
{
	if(!me)
		return;
	message_vision("眼前的一片雪地越来越近……\n", me);
	call_out("fallc", 2, me);
	return;
}

void fallc(object me)
{
	int i;
	object* ob = deep_inventory(me);

	if(!me)
		return;

	me->start_busy(1);
	message_vision("只听「噗哧」一声，$N踩进了松软的积雪中！\n", me);
	me->move(__DIR__"gudi", 1);
	for(i=0; i<sizeof(ob); i++)
		if(ob[i]->is_character())
		{
			ob[i]->set_temp("last_damage_from", me);
			message_vision(HIR"慌乱中$N早已顾不上$n，$n竟直挺挺的插进雪中！\n"NOR, me, ob[i]);
			ob[i]->die();
		}
	if(me->query_skill("dodge") < 300)
	{
		message_vision("$N头上脚下的落了下来，正撞在一块石头上，顿时脑浆迸流。\n", me);
		me->die();
	}
	message_vision("$N只觉雪从口鼻中灌了进来，脑袋一震，什么也不知道了……\n", me);
	me->unconcious();

	destruct(this_object());
	return;
}