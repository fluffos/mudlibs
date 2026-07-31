// Room: /u/beyond/ningbo/baoguosi.c 报国寺
// Beyond make 1997.6.8
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "报国寺");
	set("long", @LONG
你走进报国寺内，看到大殿内的全部结构不用一根钉子，完全靠着斗拱
之间的巧妙支撑。天花板上并列着三个美丽的镂空藻井，你不禁为能工巧匠
的精湛技艺所折服。
LONG
	);

	set("exits", ([
	"southdown" : __DIR__"shilu",
	]));
	setup();
        replace_program(ROOM);
}
