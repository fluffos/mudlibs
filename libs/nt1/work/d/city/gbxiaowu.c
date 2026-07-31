// Room: gbdixiaoshi.c
// by aji

inherit ROOM;
void create()
{
        set("short", "林间小屋");
        set("long", @LONG
你走进了一间小屋。四周墙壁都由青竹篾编成，窗外是一望无际的竹
林。屋里的桌椅、床铺均为竹制。但一阵扑鼻而来的狗肉香味，却显得与
这清雅的气纷格格不入。
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "west" : __DIR__"gbandao"
        ]));
	set("objects", ([
		__DIR__"obj/zhubang": 1,
		__DIR__"obj/gourou": 1,
		__DIR__"obj/jiudai": 1,
		__DIR__"obj/jitui": 1
	]));

        set("valid_startroom", 1);
        set("sleep_room", 1);
        setup();
        (CLASS_D("gaibang") + "/hong")->come_here(); 

}

