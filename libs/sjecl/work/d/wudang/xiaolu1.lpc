// xiaolu1.c 林间小径

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"小径"NOR);
	set("long", @LONG
你走在一条小径上，两旁种满了竹子，修篁森森，绿荫满地，除了竹叶声
和鸟鸣声，听不到别的动静。东西两侧是走廊。
LONG
	);
	set("outdoors", "武当");

	set("exits", ([
		"east" : __DIR__"donglang2",
		"west" : __DIR__"donglang1",
		"south" : __DIR__"xiaolu2",
		"north" : __DIR__"sanqing",
	]));
 
	set("objects",([
		CLASS_D("wudang") + "/yu" : 1,
	]));

        setup();
}

int valid_leave(object me, string dir)
{
	mixed *local;

	local = localtime(time() * 60);
	
	if( me->query("family/family_name") != "武当派"
	 && present("yu lianzhou", environment(me))
	 && dir != "north"
	 && (local[2] < 5 || local[2] >= 20))
		return notify_fail(CYN"俞莲舟拦住你的去路，抱拳道：现已夜深，这位"+RANK_D->query_respect(me)+"非我武当弟子不得入内。\n"NOR);
	return ::valid_leave(me, dir);
}
