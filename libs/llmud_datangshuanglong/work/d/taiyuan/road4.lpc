// /d/taiyuan/road4.c
// Room in 太原
// modify by yang

inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的、行商
的、赶着大车的马夫，熙熙攘攘，非常热闹。不时还有两三骑快马从身
边飞驰而过，扬起一路尘埃。道路两旁是整整齐齐的杨树林。西面就是
太原的东门，往东是去涿郡的大道。
LONG );
	set("exits", ([
		"northeast" : __DIR__"road5",
		"west" : __DIR__"dongmen",
	]));
	
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



