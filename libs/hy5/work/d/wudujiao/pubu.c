// by mayue

inherit ROOM;

void create()
{
        set("short", "瀑布");
	set("long", @LONG
这里是一处峡谷，每年雨季山洪爆发时就形成了一处蔚为壮观的
瀑布。山路行到这里，忽听远处传来隐隐水声，转过一道山梁，
只见一道白龙似的大瀑布从对面双峰之间奔腾而下，空山寂寂，
那水声在山谷中激荡回想，声势甚是惊人。

LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//              "east" : __DIR__"sl8",
//              "northwest" : __DIR__"sl4",
//              "west" : __DIR__"sl6",
//              "northeast" : __DIR__"sl5",
                "south" : __DIR__"sl3",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

