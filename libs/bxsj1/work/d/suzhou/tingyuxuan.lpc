#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"听雨轩"NOR);
	set("long", @LONG
听雨轩是苏州城内的一处唯一的一家书店了。这里有着各种各样的书籍，
什么小说啦、风光旅游啦、手艺制作啦、基本武功啦，等等等等。只须花几
两银子就可买到你想要的书。
LONG	);
	set("exits", ([ 
		"west" : __DIR__"nandajie2",
		]));
/*	set("objects", ([ 
		__DIR__"npc/haoke": 1,
	]) );
*/	
	set("no_clean_up", 0);
	set("coor/x",120);
  set("coor/y",-250);
   set("coor/z",0);
   set("incity",1);
	setup();
}