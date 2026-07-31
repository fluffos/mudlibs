#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"敕建景教寺"NOR);
	set("long", @LONG
景教，也就是基督教，在唐朝时就已经传入了中国。皇帝本着“天
下菩萨都别得罪”的方针，允许传教士在京城建立自己的教堂。但
由于道教是当朝的国教，佛教虽然后来，但已大有超越道教的气势，
景教多少受了冷落。
LONG         
	);
	
	set("objects", ([ 
        __DIR__"npc/shenfu" : 1,
      ]));

	set("exits", ([ 
 "east" :__DIR__"ql1",
 	]));
	setup();
	
}

