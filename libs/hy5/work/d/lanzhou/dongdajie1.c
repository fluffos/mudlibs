// Room: /lanzhou/dongdajie1.c
// xws 1998/10/14 
inherit ROOM;
void create()
{
	set("short", "东大街");
	set("long", @LONG
你走在一条比较冷清的街道上，西边就是兰州城的中央广场，这儿远离
了中央广场的宣闹，南边有一座土地庙。
LONG
	);
        set("outdoors", "lanzhou");
	set("exits", ([
		"north" : __DIR__"caisicang",
		"west" : __DIR__"guangchang",
		"east" : __DIR__"dongmen",
		"south" : __DIR__"tudimiao",
	]));
	setup();
	replace_program(ROOM);
}

