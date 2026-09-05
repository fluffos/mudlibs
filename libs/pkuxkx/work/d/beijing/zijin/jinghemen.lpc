// Room: /d/beijing/zijin/jinghemen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"景和门"NOR);
	set("long",
HIC"这是连接后三宫和东六宫的一个门,看起来和紫禁城中的其它宫门也没
什么不同。西边就是交泰殿,东边是通往东六宫的通道。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"west" : __DIR__"jiaotaidian",
  	"east" : __DIR__"tongdao5",
]));
        set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
