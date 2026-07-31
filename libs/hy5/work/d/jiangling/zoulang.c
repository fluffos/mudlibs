//Edited by fandog, 01/31/2000
#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "走廊");
	set ("long", @LONG
这是一条长长的走廊。走廊西边是知府大人的书房。东边尽头的一
间房，门上披了一匹素帏，象是个灵堂。南边是东厢房，是知府大人和
家眷住的地方。几个闲着没事的衙役正和一个丫鬟调笑着。
LONG);
	set("objects", ([
		"/d/city/npc/yayi"   : 3,
		__DIR__"npc/yahuan1" : 1, 
	]));
	set("exits", ([
		"west"  : __DIR__"shufang",
		"east"  : __DIR__"lingtang",
		"south" : __DIR__"dongxiang",
		"north" : __DIR__"huayuannew",
	]));
  
	set("coor/x", -1480);
	set("coor/y", -2029);
	set("coor/z", 0);
	setup();
	//replace_program(ROOM);
}
void init()
{
	add_action("do_biqi", "biqi");
	add_action("do_biqi", "bingqi");
}

int do_biqi()
{
	object me = this_player();
	if (!me->query_temp("jinboxunhua"))
		return 0;
	me->set_temp("biqi", 1);
	message_vision(HIG"$N深吸一口气，屏住了呼吸。\n"NOR, me);
	return 1;
}

int valid_leave(object me, string dir)
{
	if (dir == "south")
		me->delete_temp("biqi");
	return ::valid_leave(me, dir);
}