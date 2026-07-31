inherit ROOM;

void create()
{
	set("short", "铜山县");
	set("long", @LONG
这里就是徐州的风景区铜山县了，因为现在天下大乱，各路英豪接
竿而起，战火不断，这里的驻军就明显增多，而且对过往的客商盘查
的十分严格，不时有快马从城里飞驰而过。向东在过了沛县就是徐州
了。	
LONG );

	set("exits", ([
	        "east"      : __DIR__"wushui",
		"southwest"      : __DIR__"edao5",
		
	]));
	set("objects", ([
		__DIR__"npc/bing" : 1,
	]));

 	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}



