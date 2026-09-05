// Room: /d/beijing/zijin/huayuan.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"宁寿宫花园"NOR);
	set("long",
HIC"园内布满亭、台、楼、阁，苍松翠柏，曲径通幽。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"south" : __DIR__"gzxd5",
  	"east" : __DIR__"leshoutang",
]));
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
