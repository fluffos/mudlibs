// riyueyan.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "日月岩");
        set("long", @LONG
一路過來，只見光禿禿的山路兩旁，怪石林立，頗為嚇人。尤其
是前方不遠處的兩塊巨石，左邊的一塊像月亮，右邊的那塊像太陽，
夾道而立，便如一對門神，只留當中一條寬約一人多的小道，讓人通
過。往東下和北上走都是一條蜿蜒的山路。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "eastdown"  : __DIR__"shanlu10",
                "northup"   : __DIR__"shanlu11",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/song" : 1,
        ]));

	set("coor/x", -3150);
	set("coor/y", 30);
	set("coor/z", 70);
	setup();
        replace_program(ROOM);
}
