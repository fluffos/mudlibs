inherit ROOM;

void create()
{
	set("short", "沛县");
	set("long", @LONG
这里就是刘邦故里――沛县了，因为现在天下大乱，各路英豪接竿而
起，战火不断，这里的驻军就明显增多，而且对过往的客商盘查的十分
严格，不时有快马从城里飞驰而过。向东就是徐州了。	
LONG );

	set("exits", ([
	        "west"      : __DIR__"xinxian",
		"southeast"      : __DIR__"dadao9",
		
	]));
	set("objects", ([
		__DIR__"npc/bing" : 1,
	]));

 	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}



