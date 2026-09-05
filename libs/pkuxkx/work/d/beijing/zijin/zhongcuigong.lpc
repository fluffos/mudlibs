// Room: /d/beijing/zijin/zhongcuigong.c
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY"钟粹宫"NOR);
	set("long",
HIC"东六宫之一,这是明清两代后妃们居住的地方.咸丰幼年时曾随
母亲孝全成皇后在此宫殿,以后慈安太后也在这住过。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"east"  : __DIR__"gzxd10",
  	"west" : __DIR__"tongdao6",
]));

	setup();
	replace_program(ROOM);
}
