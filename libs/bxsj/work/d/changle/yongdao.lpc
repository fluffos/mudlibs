// Room: /d/changle/yongdao.c
// River 2003.2.26
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", GRN"甬道"NOR);
	set("long", @long
长长的甬道通向一个石室，旁边壁上每隔不远便有一盏油灯，头上是高高
的拱顶，显得有些阴森可怖。几名帮众在这里把守，闲杂人等不能随意前进。
long
	);

	set("exits", ([
		"south" : __DIR__"huayuan",
		"east" : __DIR__"shishi",
	]));

	set("objects", ([
		__DIR__"npc/bangzhong" : 1,
	]));

	set("outdoors", "长乐帮");
	setup();
}
