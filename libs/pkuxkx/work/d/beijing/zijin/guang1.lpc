// Room: /d/beijing/zijin/guang1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"殿前广场"NOR);
	set("long",
HIC"这是太和殿前的大广场。中间一条白玉石路通向太和殿，两边各
有一排石狮护拥着着这条白玉路。每一各石狮边上都站立一名带刀侍
卫，目不斜视，纹丝不动。\n"NOR
	);
	set("exits", ([ /* sizeof() == 10 */
   	"northeast" : __DIR__"zhongzuomen",
  	"south" : __DIR__"taihemen",
  	"east" : __DIR__"zuoyimen",
  	"northwest" : __DIR__"zhongyoumen",
   	"west" : __DIR__"youyimen",
  	"north" : __DIR__"taihedian",

]));
	set("objects", ([
		"/d/beijing/npc/shiwei1" : 6,
		"/d/beijing/npc/shiwei2" : 6,
		"/d/beijing/npc/zhangkangnian" : 1,
		]) );

	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
