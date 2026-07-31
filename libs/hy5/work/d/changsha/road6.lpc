// /d/zhuojun/road1.c
// Room in 涿郡
// modify by yang

inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。虽然现今天下大乱，但是四周还
是人来人往。挑担子的、行商的、赶着大车的马夫，熙熙攘攘，非常热
闹。不时还有两三骑快马从身边飞驰而过，扬起一路尘埃。道路两旁是
整整齐齐的杨树林。
LONG );

	set("exits", ([
		"north"      : __DIR__"road5",
		"southeast"      : "/d/henshan/hsroad8",
		
	]));


 	set("outdoors", "zhuojun");
	setup();
	replace_program(ROOM);
}



