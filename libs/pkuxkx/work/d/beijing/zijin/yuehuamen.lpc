// Room: /d/beijing/zijin/yuehuamen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"月化门"NOR);
	set("long",
HIC"这是一扇月形宫门，每到月圆之时，月光洒在宫门之上，显得那
麽肃穆与威杀。这是连接后三殿和西六宫的一个偏门。\n"NOR
	);
	set("exits", ([ /* sizeof() == 3 */
  	"west" : __DIR__"neiyoumen",
  	"south" : __DIR__"nzsfang",
  	"north" : __DIR__"pibenchu",
]));
	set("outdoors", "beijing");
	set("objects", ([
		"/d/beijing/npc/shiwei5" : 4,
		]) );
	setup();
	replace_program(ROOM);
}
