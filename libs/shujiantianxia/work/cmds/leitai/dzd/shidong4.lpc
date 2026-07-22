// Room: /d/dzd/shidong4.c

#include <ansi.h>

int do_tie(string arg);

inherit __DIR__"dzd_room";

void create()
{
	set("short","钟乳石洞");
	set("long",@LONG
天然形成的钟乳石洞，洞中有的地段很直；有的地段又很弯；有的地段曲如园中的九曲
回廊；漫步前进，自有车到山前必有路之奇；更有的地段曲如林中幽径，漫步游览，自有柳
暗花明又一村之感。洞中光线阴暗，隐隐有腥风吹过。
LONG
	);
	set("exits",([
		"southeast" : __DIR__"shidong3",
		"southwest" : __DIR__"shidong1",
		"south" : __DIR__"shidong2",
	]));
	setup();
}

void init()
{
	object room;
	::init();
	add_action("do_tie","tie");
	if(!room = find_object(__DIR__"shibi"))
		room = load_object(__DIR__"shibi");
	if(!wizardp(this_player()))
		tell_room(room,"透过微弱的光线，你看见" + this_player()->name() +"("+this_player()->query("id")+")来到了石洞。\n");
}

int do_tie(string arg)
{
	object me = this_player();
	if(me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if(!arg || arg != "shibi")
		return notify_fail("你要贴到哪儿去？\n");
	message_vision(HIY"$N深吸一口气，犹如一只巨大的蝙蝠掠地而起，轻轻的贴到一块凸起的石壁上。\n"NOR,me);
	me->move(__DIR__"shibi",1);
	message_vision(HIY"$N体内真气流转，犹如壁虎一般紧紧的贴在了石壁上。\n"NOR,me);
	return 1;
}

int valid_leave(object me,string dir)
{
	object room;
	int valid;
	
	valid = ::valid_leave(me,dir);
	if(valid && !wizardp(me) && room = find_object(__DIR__"shibi"))
		tell_room(room,"透过微弱的光线，你看到" + me->name() + "(" + me->query("id") + ")离开了石洞。\n");
	return valid;
}
