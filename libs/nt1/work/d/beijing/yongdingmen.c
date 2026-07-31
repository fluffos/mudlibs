#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "永定门");
	set("long", @LONG
这里是紫禁城永定门，高大的城门上方刻着“永定门”三个大字，
厚实坚固的古城墙高高耸立着。城门两旁整齐的站着几个卫兵，仔细的
监守着这里。每天都有许多人经过这里出入京城。出了永定门，一条笔
直的大官道向南北两边延伸。南边的官道上人来车往，尘土飞扬。北方
则是通往京城的中心。
LONG );
	set("exits", ([
		"north" : __DIR__"yongdingdao",
		"south" : __DIR__"road5",
	]));
	set("objects", ([
		__DIR__"npc/ducha" : 1,
		__DIR__"npc/bing1" : 2,
	]));
	set("outdoors", "beijing");
	setup();
	replace_program(ROOM);
}
