// Room: /d/beijing/zijin/cininghu.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"慈宁花园"NOR);
	set("long",
HIC"这是一个大花园，有几个太监正在浇花。花的品种很多，每逢春
秋两季，百花齐放，煞是好看。旁边有一排花架。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"north" : __DIR__"ciningmen",
  	"east" : __DIR__"zaobanchu",
]));
	set("outdoors", "beijing");
	set("objects", ([
		"/d/beijing/npc/ruidong" : 1,
		]) );
	setup();
	replace_program(ROOM);
}
