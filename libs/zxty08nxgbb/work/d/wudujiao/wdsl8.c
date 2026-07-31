// by mayue

inherit ROOM;

void create()
{
	set("short", "五毒山路");
	set("long", @LONG
这里是五毒山中的山间小路，蜿蜒曲折盘旋而上。山路上寂静
无声，看不到一丝鸟兽的痕迹。你顺手拨开伸向路中的枝条，树枝
忽然一动，缩了回去，“哇...”竟然是一条形似枯枝的毒蛇。 
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//		"eastup" : __DIR__"wdsl5",
//		"southup" : __DIR__"wdsl3",
                "westdown" : __DIR__"wdsl5",
                "south" : __DIR__"sl1",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

