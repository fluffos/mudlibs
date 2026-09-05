// Room: /d/beijing/zijin/neiyoumen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"内右门"NOR);
	set("long",
HIC"这是通往养心殿和西六宫的重要门户,由此往里是皇帝和后妃们
居住的地方。\n"NOR
	);
	set("exits", ([ /* sizeof() == 4 */
//  	"southeast" : __DIR__"qianqingmen",
  	"north" : __DIR__"tongdao1",
  	"west" : __DIR__"yangxindian",
  	"east" : __DIR__"yuehuamen",
]));
	set("outdoors", "beijing");
	setup();
	replace_program(ROOM);
}
