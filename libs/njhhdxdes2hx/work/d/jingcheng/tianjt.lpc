#include <ansi.h>
inherit ROOM;

void create()
{
      	set("short", HIW"科举考场"NOR);
	set("long", @LONG
这里便是京城宰相刘伯温监考的考场，朝廷每年的科举都在
这里举行。中央广场上站着宰相，周围还有一些考生。
LONG         
	);    
	set("no_beg",1); 
      	set("no_fight", 1);
    	set("no_sleep_room",1);           
	set("objects",([

		__DIR__"npc/liubw" :1,

          ]));

	set("exits", ([ 
		 "south" :__DIR__"xw5",
 	]));
	setup();
	
}

