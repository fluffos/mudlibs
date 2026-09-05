// tzhroad9.c
// by wolf

inherit ROOM;

void create()
{
	set("short", "村庄的西边");
	set("long", @LONG
    这里村庄的南街的尽头，街上有几个地痞，流氓在聊天，而且他们不时的
看看你，看样子不大友善，你还是赶快离开为妙。东面是村庄的中心，南面是一家
小食店。
LONG
	);
        set("outdoors", "tzh-bang");

	set("exits", ([
		"north" : __DIR__"tzhroad6",
		"east" : __DIR__"tzhroad10",
                                     "south" : __DIR__"tzhroad13",
	]));

	setup();
	replace_program(ROOM);
}

