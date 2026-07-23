inherit ROOM;

void create()
{
	set("short", "睢宁");
	set("long", @LONG
这里就是徐州的重镇睢宁了，因为现在天下大乱，各路英豪接竿而
起，战火不断，这里的驻军就明显增多，而且对过往的客商盘查的十分
严格，不时有快马从城里飞驰而过。	
LONG );

	set("exits", ([
	        "north"      : __DIR__"edao5",
		"west"      : __DIR__"edao6",
		
	]));
	set("objects", ([
		__DIR__"npc/bing" : 1,
	]));

 	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}



