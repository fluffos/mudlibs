// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "大道");
	set("long", @LONG
你在大道上，两边都是杨柳树，这条路上来往的人并不多，偶尔看见有几
道姑走过，只见西首绿柳丛中，小湖旁有一角黄墙露出。
LONG
	);
        set("outdoors", "大理");
	set("exits", ([ /* sizeof() == 1 */
	    "north" : __DIR__"dadao6",
	    "southeast" : __DIR__"shangang",
            "west" : __DIR__"yuxuguanmen",
        ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
