// Room: /d/emei/fuhusi.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIY "伏虎寺" NOR);
	set("long", @LONG
伏虎寺是入山第一大宝刹，隐伏在高大的乔木林间，四周楠木参天，多达
十万余株。伏虎寺气象庄严，规模宏盛，殿堂宽敞，势度巍峨。寺刹虽掩覆于
翠绿浓黛之中，但屋瓦却无一片落叶。出寺西上解脱坡便是观音堂。
LONG
	);
	set("outdoors", "峨眉山");
	set("no_clean_up", 0);
	set("exits", ([ 
	  "westup" : __DIR__"milin2",
	  "east" : __DIR__"milin",
]));
	set("objects",([
		"/d/emei/npc/dizi" : 1,
		"/d/emei/npc/dizi2" : 1,
]));
	set("coor/x",-210);
  set("coor/y",-130);
   set("coor/z",10);
   setup();
}
