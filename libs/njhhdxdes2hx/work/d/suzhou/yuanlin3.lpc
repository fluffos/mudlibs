//ROOM:/d/suzhou/yuanlin3.c
//by dwolf
//97.11.7 
         
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"苏州园林"NOR);
	set("long", @LONG
        	穿过一层竹篱、花嶂编的月洞门，在你眼前出现的是那由粉墙环护
，绿柳周垂的翠嶂。两边分别是游廊相接通往桃花林与长廊曲洞。在这儿一棵西府牡
丹吸引你的注意，只见其势若盘，丝垂翠缕，葩吐丹砂，十分漂亮。西边是小亭。
LONG
	);                                        
	set("exits", ([
		"west" : __DIR__"yuanlin5",  
		"south" : __DIR__"yuanlin2",
]));
	setup();
	replace_program(ROOM);
}
  

