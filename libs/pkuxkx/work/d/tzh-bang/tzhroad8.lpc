// tzhroad8.c
// by wolf

inherit ROOM;

void create()
{
	set("short", "村庄外围");
	set("long", @LONG
    这里是村庄的外围，两边的树林非常茂密，北面是一条宽阔的石板路，隐隐约约可以
看见一个高大的牌坊，南面是村庄的东大街
LONG
	);
        set("outdoors", "tzh-bang");

	set("exits", ([
		"west" : __DIR__"tzhroad7",
		"north" : __DIR__"",
                                     "south" : __DIR__"tzhroad11",
	]));

	setup();
	replace_program(ROOM);
}

