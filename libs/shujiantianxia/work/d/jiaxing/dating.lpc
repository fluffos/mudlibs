// /d/jiaxing/dating.c 大厅

inherit ROOM;
void create()
{
        set("short", "大厅");
	set("long", @LONG
这是陆家庄内的一个大厅，厅内古色古香，案上放着许多精美的古董。四
面的墙壁上挂满了字画。一处墙上有九个血淋淋的手印，现任庄主陆立鼎面带
愁容坐在椅子上，望著血手印呆呆地出神。
LONG
	);

	set("exits", ([
                "south" : __DIR__"houyuan",
                "east" : __DIR__"tianjing",
	]));

        set("objects", ([
                 __DIR__"npc/lu-liding" : 1,
        ]));
	setup();
}
