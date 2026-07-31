// Room: /guiyun/tiandi.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "田地");
	set("long", @LONG
这里是一片农田。不远处有一些村庄，炊烟袅袅升起。村庄周围
是一块块的田地，很有次序的排成一个个井字，田里有一些正在耕作
的农人，过路人贪近路也可以从田间井字分割的小径穿过。
LONG );
	set("outdoors", "guiyun");
//	set("no_clean_up", 0);
	set("exits", ([
		"northeast"  : __DIR__"shulin5",
		"west"       : __DIR__"yixing",
	]));
	set("objects", ([
		__DIR__"npc/banjiu" : 1,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	int c_exp,c_skill;
	me = this_player();
	if (dir == "west" )
	{
		me->receive_damage("qi", 10);
		tell_object(me,"你走上田间突起的小土垅，觉的很是狭窄，慢慢的走了进去。\n");
	}
	else
	{
		me->receive_damage("qi", 10);
		message_vision("$N踩着田间的小土垅，慢慢向前走去。\n", me);
	}
	return 1;
}

