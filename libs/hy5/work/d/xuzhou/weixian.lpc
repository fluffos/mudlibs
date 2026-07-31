inherit ROOM;

void create()
{
	set("short", "丰县");
	set("long", @LONG
这里就是徐州的重镇丰县了，徐县自古是兵家要地，丰县是控
制中原的关键地点之一，现在天下大乱，各路英豪接竿而起，战
火不断，这里的驻军就明显增多，而且对过往的客商盘查的十分严
格，不时有快马从城里飞驰而过。	
LONG );

	set("exits", ([
	        "east"      : __DIR__"shanlu",
		"southwest"      : __DIR__"edao",
		
	]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
		__DIR__"npc/wujiang":1,
	]));

 	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}



