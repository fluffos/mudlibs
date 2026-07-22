// dao1.c 黄土路
// by oooc

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。据说
经常有土匪出没，不可久留。
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "southwest" : __DIR__"dao",
	]));
        set("objects", ([
            __DIR__"npc/tufei2" : 1,
        ]));

	setup();
	replace_program(ROOM);
}

