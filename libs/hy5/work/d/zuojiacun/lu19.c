// Room: /d/zuojiacun/lu19.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条泥泞的小路，由于刚下过大雨，前面的道路已被冲
断了。路的东面是一处住房。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
	"west" : "/d/tieflag/cape",
	"east" : __DIR__"xiaojuan",
	"north" : __DIR__"lu18",
	"south" : "/d/jinghai/zhuque5",
]));
        set("objects", ([
"quest/skills2/wunon/yu/yutan" : 5,
        ]) );

	set("outdoors", "zuojiacun");
	setup();

	replace_program(ROOM);
}
