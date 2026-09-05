// Room: /d/beijing/zijin/houyoumen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"后右门"NOR);
	set("long",
HIC"从这里向北是乾清门，向南是中右门，许多太监和侍卫从这里经过。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
 	 "northeast" : __DIR__"qianqingmen",
 	 "south" : __DIR__"xiaodao1",
]));
	set("outdoors", "beijing");
	set("objects", ([
		"/d/beijing/npc/shiwei3" : 4,
		"/d/beijing/npc/shiwei4" : 4,
		]) );
	setup();
	replace_program(ROOM);
}
