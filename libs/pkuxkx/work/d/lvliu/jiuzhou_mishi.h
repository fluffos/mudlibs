//九州密室通道

#include <ansi.h>
#include <room.h>
#include <present.h>

inherit ROOM;
int lvl;

void init()
{
	object me=this_player();
    object room;

	room = this_object();
	lvl = room->query("room_lvl");

	if (!userp(me))
	{
		me->move(__DIR__"dating");
		return;
	} //无关人等退场

	add_action("do_push","push");
	add_action("do_listen","listen");
	add_action("do_qiao","qiao");

	me->set_temp("lvliu_jiuzhou/into_mishi", time());
    me->listen_to_die(room);
}

object next_room()
{
	return load_object(__DIR__"jiuzhou"+sprintf("%d",lvl));
}

int do_push(string arg)
{
	object room,me;
	int count;
	if (!arg || arg!="door")
		return notify_fail("你要推什么？\n");
	room = next_room();
	me = this_player();
	if (!objectp(room))
	{
		tell_object(me, HIR"通道尽头的门纹丝不动，你再也过不去了！\n"NOR);
		return 1;
	}
	count = room->person_count(1);
	if (count >= 2 || (count >0 && present_npc("shouwei wushi", room)) ) // 下一个画廊人满
	{
		tell_object(me, "你推了推通道尽头的门，门轴似乎被机关锁住了，一时还打不开。\n"
			+ "门内似乎有些动静，也许你可以贴在门上听一听(listen)。\n");
		return 1;
	}
	if (count<=0)
		room->clean_up_this_room();
	me->remove_listen_to_die(this_object());
	me->move(room);
	tell_room(this_object(), HIG + me->query("name")+ HIG "轻轻推开通道尽头的小门，蹑手蹑脚地闪了进去，门马上又自动关上了。\n"NOR);
	message_vision(HIG"只见人影一晃，$N闪身进了门，门马上又悄然无声地自动关上了。\n"NOR, me);
	return 1;
}

int do_listen()
{
	object room, me;
	int count;
	room = next_room();
	me = this_player();
	if (!objectp(room))
	{
		tell_object(me, "你趴在门上听了听，什么动静也没有！\n");
		return 1;
	}
	count = room->person_count(1);
	if (count >0 && present_npc("shouwei wushi", room))
	{
		if (count == 1)
			tell_object(me, "你趴在门上听了听，隐约听到一阵刀剑交鸣，门后似乎正有一场激战！\n");
		else 
			tell_object(me, "你趴在门上听了听，隐约听到一阵密集的刀剑交鸣声，门后似乎激战正酣！\n");
	}
	else if (count>=2)
		tell_object(me, "你趴在门上听了听，隐约听到门后有人说话，但听不清说了些什么！\n");
	else tell_object(me, "你趴在门上听了听，什么动静也没有！\n");
	return 1;
}

int do_qiao(string arg)
{
	object me=this_player();
	if (time()- (int)me->query_temp("lvliu_jiuzhou/into_mishi") < 600)
		return notify_fail("你无聊地到处随意敲来敲去。\n");
	if (me->query_temp("lvliu_jiuzhou/confirm_leave"))
	{
		me->remove_listen_to_die(this_object());
		message_vision(HIC"$N在暗处发现了一块可活动的暗板，用力一敲，暗板忽然翻转开了……\n"NOR, me);
        me->move(__DIR__"dating");
		message_vision(HIY"噗通一声，$N从上方掉了下来，拍拍屁股上的尘土，长吁了一口气。\n"NOR, me);
		me->set("lvliu_jiuzhou/start",time()-(lvl-1)*120);   
		me->delete_temp("task_stat/lvliu_jiuzhou");
		me->delete_temp("lvliu_jiuzhou");
	}
	else
	{
		tell_object(me, "你忽然在暗处发现了一块可活动的暗板，只要多敲几下就可以离开这里。\n");
		tell_object(me, "如果你确定要离开这里，那就再用力多敲(qiao)一下试试吧！\n");
		me->set_temp("lvliu_jiuzhou/confirm_leave", 1);
		return 1;
	}
	return 1;
}

//当有玩家在此死亡时调用
int die_notify(object victim)
{
    if(userp(victim))
    {
        victim->remove_listen_to_die(this_object());
        victim->delete_temp("lvliu_jiuzhou");
		return 1;
    }
}