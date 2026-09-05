// Room: /d/beijing/kangqin/tianjing.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"天井"NOR);
	set("long",
MAG"这是一个宽大的练武场，有几个武师在这里练功。其中一个秃顶和尚，
东走走，西看看，好象是这儿的领头。还有一个身材瘦高的武师，两手别
在腰后，似乎也有一身好武功。南面是后堂。\n"NOR
	);
	set("exits", ([ /* sizeof() == 4 */
  	"south" : __DIR__"houtang",
  	"west" : __DIR__"zhoulang4",
  	"north" : __DIR__"dating",
  	"east" : __DIR__"zhoulang3",
]));
	set("objects", ([
		"/d/beijing/npc/shenzhao" : 1,
		"/d/beijing/npc/qi" : 1,
	]));
	set("outdoors", "beijing");
	setup();
	replace_program(ROOM);
}
