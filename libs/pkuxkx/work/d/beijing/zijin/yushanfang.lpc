// Room: /d/beijing/zijin/yushanfang.c
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY"内膳房"NOR);
	set("long",
HIC"皇帝进膳多在养心殿、乾清宫等处，内膳房设在养心殿前很方便。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"south": __DIR__"yangxindian",
  	"north": __DIR__"yongshougong",
]));

	set("objects", ([
		"/d/beijing/npc/obj/yuchi" : 1,
		"/d/city/npc/obj/nerh": 1,
		]) );
	setup();
	replace_program(ROOM);
}
