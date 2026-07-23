// /d/zhuojun/eroad3.c
// Room in 涿郡
// modify by yang

inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。虽然现今天下大乱，但是四周还
是人来人往。挑担子的、行商的、赶着大车的马夫，熙熙攘攘，非常热
闹。眺望远处，已经能看见长沙了。
LONG );

	set("exits", ([
		"west" : __DIR__"eroad2",
                "northeast" : __DIR__"shulin1",
		
	]));

 	set("outdoors", "zhuojun");
	setup();
	replace_program(ROOM);
}



