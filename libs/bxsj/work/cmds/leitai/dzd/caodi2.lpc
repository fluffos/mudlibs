// Room: /d/dzd/caodi2.c

#include <ansi.h>

inherit __DIR__"dzd_room";

int do_zuan(string arg);

void create()
{
	set("short","草地");
	set("long",@LONG
这里是一片水草交集的湿地。地上泥泞难行。海风吹来，漫天长草之中现出倒闭着的
累累白骨，似乎提醒着你，此处虽然似乎寂静无人，却是暗藏杀机。东面和东北面被一条
溪流环绕着。
LONG
	);
	set("outdoors","大智岛");
	set("exits",([
		"north" : __DIR__"caodi3",
		"east" : __DIR__"xiliu2",
		"south" : __DIR__"caodi1",
	]));
	set("objects",([
		__DIR__"npc/snake" : 1,
	]));
	setup();	
}

void init()
{
	object room;
	::init();
	add_action("do_zuan","zuan");
	if(!room = find_object(__DIR__"caocong"))
		room = load_object(__DIR__"caocong");
	if(!wizardp(this_player()))
		tell_room(room,"透过草丛的缝隙，你看见" + this_player()->name() +"(" + this_player()->query("id")+ ")来到了这里。\n");
}

int do_zuan(string arg)
{
	object me = this_player();
	if(me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if(!arg || arg != "caocong")
		return notify_fail("你要钻到哪儿？\n");
	message_vision(HIY"$N一伏身，钻到旁边的草丛，瞬间便已不见。\n"NOR,me);
	me->move(__DIR__"caocong",1);
	message_vision(HIY"$N找了处荒草茂密之处，轻轻伏下身来。\n"NOR,me);
	return 1;
}

int valid_leave(object me,string dir)
{
	object room;
	int valid;
	
	valid = ::valid_leave(me,dir);
	if(valid && !wizardp(me) && room = find_object(__DIR__"caocong"))
		tell_room(room,"透过草丛的缝隙，你看到" + me->name() + "(" + me->query("id") + ")离开了这里。\n");
	return valid;
}
