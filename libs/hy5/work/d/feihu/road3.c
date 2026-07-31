// 雪路3
// by steel 

inherit ROOM;

void create()
{
	set("short", "雪原");
	set("long", @LONG
	这里是北方的一片雪原,积雪终年不化,放眼望去,白茫茫的一片,
一个人影也看不到。只是西方远远传来一些吆喝音。   
LONG
	);

	set("exits", ([
		"east" : __DIR__"road2",
		"west" : __DIR__"littlehotel",
	]));
	setup();
	replace_program(ROOM);
}

