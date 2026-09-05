#include <ansi.h>

int do_bell(string arg)
{
	object me=this_player();
	if (!arg || arg!="bell")
		return notify_fail("你要摇动什么？\n");
	message_vision(HIC"$N犹豫了片刻，走上去拿起铃铛摇了摇，发出一阵清脆的声响。\n"NOR, me);
	call_out("move_to", 1, me);
	return 1;
}

void move_to(object me)
{
	if (!objectp(me) || environment(me)!= this_object())
		return;
	message_vision(HIY"通道旁忽然打开了一道暗门，一位管事模样的人躬身道：「让贵客受惊了，本庄多有怠慢。」\n"NOR, me);
	me->move(__DIR__"pingyuan0");
	message_vision(HIY"一位庄内的管事把$N领了过来，然后躬身行礼退下。\n"NOR, me);
}

void init()
{
	add_action("do_bell", "shake");
}

