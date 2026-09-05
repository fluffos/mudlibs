// Room: /d/beijing/zijin/longfumen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"隆福门"NOR);
	set("long",
HIC"这是连接后三宫和西六宫的一个门,东边就是交泰殿,西边是通往
西六宫的通道。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"west" : __DIR__"tongdao2",
  	"east" : __DIR__"jiaotaidian",
]));
	set("outdoors", "beijing");
	setup();
	replace_program(ROOM);
}
