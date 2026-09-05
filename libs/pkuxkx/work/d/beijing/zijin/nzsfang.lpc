// Room: /d/beijing/zijin/nzsfang.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"内奏事房"NOR);
	set("long",
HIC"这里就是内奏事房，是紫禁城中的重地．每天内外臣工所进的
奏章由外奏事处接收交到这里，再从这里进呈给皇上，批复后再交
出．这里看似简朴，实则外松内紧，守备森严。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"north" : __DIR__"yuehuamen",
  	"south" : __DIR__"nanshufang",
]));

	setup();
	replace_program(ROOM);
}
