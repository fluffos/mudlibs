// dao.c 黄土路
// by oooc

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。这里
是四川境界，据说经常有土匪出没，不可久留。
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "northeast" : __DIR__"dao1",
                "south" : __DIR__"dadao2",
	]));

	setup();
	replace_program(ROOM);
}

