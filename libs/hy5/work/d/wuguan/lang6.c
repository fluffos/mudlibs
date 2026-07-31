//cool 98.4.18

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
这是个长廊，往北通向休息室，南面是物品房，这里静悄悄的，人们
走路都也小心翼翼的，怕吵着北面休息室里休息的人。
LONG);
	set("exits", ([
	       "north" : __DIR__"woshi1",
	       "south" : __DIR__"wupinfang",
        ]));
	setup();
        replace_program(ROOM);
}

