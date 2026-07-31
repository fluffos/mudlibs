// Room: /d/wizhome/incahome/nroad2.c
// Date: inca 98/08/13

inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周的人不是很多。偶尔有
几个挑夫，匆匆向南走去。不时还有两三骑快马从身边飞驰而过，
扬起一路尘埃。道路两旁是整整齐齐的杨树林。从这里远远的就
可以望见北京城。
LONG
	);

	set("exits", ([
		"south"  : __DIR__"nroad1",
		"north" : __DIR__"juyguan",
	]));

        set("outdoors", "changcheng");

	setup();
	replace_program(ROOM);
}



