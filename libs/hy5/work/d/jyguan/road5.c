// road5.c 官道
// west to jiayuguan,est to lanzhou
// Ver 0.1 08/14/1998 by Freeze

inherit ROOM;

void create()
{
	set("short", "官 道");
	set("long", @LONG
这是一条宽阔的大路，商队往来，一群民工在几个军汉的监
看下搬运砖石。
    西面就是军事要塞、千古雄关——嘉峪关。
LONG
	);	
        set("outdoors", "jyguan");


	set("exits", ([
		"west" : __DIR__"dongmen",
		"east" : __DIR__"road4",
               
	]));
	
//	set("objects", ([
//		__DIR__"npc/guest" : 1]));
		
	setup();
	replace_program(ROOM);
}

