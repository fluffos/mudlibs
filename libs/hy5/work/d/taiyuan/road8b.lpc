// /d/taiyuan/road7.c
// Room in 太原
// modify by yang

inherit ROOM;

void create()
{
	set("short", "交叉路口");
	set("long", @LONG
这里是一个交叉路口。路边有个小小的茶棚，行路的人们口渴了，
都去买碗茶喝，东北面传来阵阵河水声，应该快到黄河渡口了，西面通
向银川府，西南有条大路，可以到达长安城。东南则是一座雄伟的大山。
LONG );
	set("exits", ([
		"west"  : __DIR__"road8c",
 		"northeast"  : __DIR__"road8",
                "southeast"  : __DIR__"road8a",
///                "southwest":"/d/changan/dadao2",
		
	]));
	
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



