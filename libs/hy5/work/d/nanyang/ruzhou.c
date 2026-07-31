// Room: /d/nanyang/ruzhou.c
// Last Modified by winder on Nov. 20 2001

inherit ROOM;

void create()
{
	set("short", "驿道关口");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的行商，
赶着大车的马夫，上京赶考的书生，熙熙攘攘，非常热闹。不时还有两
三骑快马从身边飞驰而过，扬起一路尘埃。道路两旁是整整齐齐的杨树
林。附近离汝州城不远，可以看到远处的城墙
LONG );
	set("exits", ([
		"south" : __DIR__"yidao3",
		"westdown"  : "/d/songshan/taishique",
		"northwest" : "/d/cangzhou/sroad4",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 3,
		"/d/city/npc/bing" : 3,
	]));
	set("outdoors", "nanyang");
	set("coor/x", 10);
	set("coor/y", 700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
