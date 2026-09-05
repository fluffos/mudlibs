// Room: /d/beijing/zijin/rijingmen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"日精门"NOR);
	set("long",
HIC"这是连接后三殿和东六宫的一个偏门。\n"NOR
	);
	set("exits", ([ /* sizeof() == 3 */
  	"south" : __DIR__"yuyaofang",
  	"north" : __DIR__"duanningdian",
  	"east" : __DIR__"neizuomen",
]));
	set("outdoors", "beijing");
	set("objects", ([
		"/d/beijing/npc/shiwei5" : 4,
		]) );
	setup();
	replace_program(ROOM);
}
