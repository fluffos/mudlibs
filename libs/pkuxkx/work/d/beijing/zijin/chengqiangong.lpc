// Room: /d/beijing/zijin/chengqiangong.c
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY"承乾宫"NOR);
	set("long",
HIC"这是东六宫之一，原本后妃们居住的地方。但当今皇上年纪尚轻，
尚未婚配。因此暂时无人居住。有些地方已经积起了灰尘。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"east"  : __DIR__"gzxd9",
  	"west" : __DIR__"tongdao5",
]));

	setup();
	replace_program(ROOM);
}
