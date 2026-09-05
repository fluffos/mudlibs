// tzhroad6.c
// by wolf

inherit ROOM;

void create()
{
	set("short", "小路的边缘");
	set("long", @LONG
    这里是小路的边缘，东面是一条小村庄。听说这里的人都很有钱，特别是这里的
大财主张八爷。因为这里离铁掌帮很近的缘故，村里面的人一般武功都很高，东面是村庄
的外围，南面是村庄的西边。
LONG
	);
        set("outdoors", "tzh-bang");

	set("exits", ([
		"west" : __DIR__"tzhroad5",
		"east" : __DIR__"tzhroad7",
                                     "south" : __DIR__"tzhroad9",
	]));

	setup();
	replace_program(ROOM);
}

