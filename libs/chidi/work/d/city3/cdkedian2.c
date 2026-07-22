// Room: /chengdu/cdkedian2.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "客栈二楼");
	set("long", @LONG
	你正走在客店二楼的走廊上，可以听到从客房里不时地呼呼
的打酣声，一阵高过一阵。不时有睡意朦胧的旅客进进出出，到楼下
的掌柜处付了钱再上来睡觉。
LONG
	);

	set("exits", ([
                "down" : __DIR__"cdkedian",
                "east" : __DIR__"cdkedian3",
                "west" : __DIR__"cdkedian4",
	]));

	setup();
	replace_program(ROOM);
}

