#include <ansi.h>
#include <room.h>
#include <localtime.h>
#include "nodie.h"

inherit ROOM;
void create()
{
	set("short", CYN"陷阱"NOR);
	set("long","一个很深很深的陷阱，形如枯井，抬头只能看见盘子大的一块天空。\n");
	set("exits", ([	]));
	set("item_desc", ([
		"bell" : "一个小铃铛挂在墙角处，摇摇它(shake bell)也许有人会来救你出去。\n",
		"vine" : "陷阱上方垂下来很多藤蔓，抓住它或许可以爬出去(climb)。\n",
	]));	
	setup();
}

int do_bell(string arg)
{
	object me=this_player();
	if (!arg || arg!="bell")
		return notify_fail("你要摇动什么？\n");
	if (me->is_busy())
		return notify_fail("你现在忙得很，没空去摸铃铛。\n");
	if (me->is_fighting())
		return notify_fail("你还是先解决了你的对手之后再去摸铃铛吧。\n");
	message_vision(HIC"$N犹豫了片刻，走上去拿起铃铛摇了摇，发出一阵清脆的声响。\n"NOR, me);
	call_out("move_to", 1, me);
	return 1;
}

void move_to(object me)
{
	mixed* timeinfos=localtime(time());
	string mday;
	mday = "" + timeinfos[LT_YEAR] + sprintf("%02d", timeinfos[LT_MON]) + sprintf("%02d", timeinfos[LT_MDAY]);
	if (!objectp(me) || environment(me)!= this_object())
		return;
	me->delete_temp("lvliu/move_exp"); // 直接到庄门的木有额外奖赏
	message_vision(HIY"黑暗中忽然打开了一道暗门，一位管事模样的人躬身道：「让贵客受惊了，本庄多有怠慢。」\n"NOR, me);
	me->move(__DIR__"gate");
	me->set("lvliu/move/last", mday);
	message_vision(HIY"一位庄内的管事把$N领了过来，然后躬身行礼退下。\n"NOR, me);
}

int do_climb()
{
	object me=this_player();
	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");
	message_vision(HIC"$N抓住上方垂下的藤蔓，用尽全力向陷阱上方爬去。\n"NOR , me);
	me->start_busy(18);
	call_out("move_out", 15, me);
	return 1;
}

void move_out(object me)
{
	if (!objectp(me) || environment(me)!= this_object())
		return;
	message_vision(HIY"成功了！你已经摸到了陷阱口，一个翻身爬上去。\n"NOR, me);
	me->move(__DIR__"xiaolu");
	message_vision(HIY"$N带着满身青苔和草茎，从路边的一个小洞中爬了上来。\n"NOR, me);
}

void init()
{
	this_player()->add_temp("lvliu/move_exp", 10);
	add_action("do_climb", "climb");
	add_action("do_bell", "shake");
}
