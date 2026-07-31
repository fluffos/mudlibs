// Room: /d/linzhi/lin06.c

// Room: /d/linzhi/lin05.c

inherit ROOM;

void create()
{
	set("short", "桃花沟");
	set("long", @LONG
你来到桃花沟，只见到处都是野生的桃树。这是一片天然的
桃林，不知从何时起有的。每年到了八月桃子成熟的季节，人们
会来这里采摘这里的桃子。据当地老人讲，这桃子是神赏赐给子
民的。你走着走着，忽然觉得迷失了方向。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin05",
  "west" : __DIR__"lin07",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}


