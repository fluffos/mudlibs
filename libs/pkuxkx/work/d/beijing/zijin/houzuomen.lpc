// Room: /d/beijing/zijin/houzuomen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"后左门"NOR);
	set("long",
HIC"从这里向北是乾清门，向南是中左门，许多太监和侍卫从这里经过。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"northwest" : __DIR__"qianqingmen",
  	"south" : __DIR__"xiaodao2",
]));
	set("outdoors", "beijing");
	set("objects", ([
		"/d/beijing/npc/shiwei3" : 4,
		"/d/beijing/npc/shiwei4" : 4,
		]) );
	setup();
	replace_program(ROOM);
}
