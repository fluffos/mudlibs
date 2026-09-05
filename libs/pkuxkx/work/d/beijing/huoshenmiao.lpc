// Room: /d/beijing/huoshenmiao.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"火神庙"NOR);
	set("long",
CYN"这是一座略显破败的火神庙，红袍红脸红胡子的火神爷坐在庙正
中。从庙门望出去可以看到鼓楼，大概当初修建鼓楼时怕遭火灾，所
以修了这个火神庙，求火神爷保佑。\n"NOR
	);
	set("exits", ([ /* sizeof() == 1 */
	"out" : __DIR__"jingshan",
	]));

	setup();
	replace_program(ROOM);
}
