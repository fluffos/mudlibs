
inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
你不知不觉走进了一片树林中，极目青绿，苍松翠柏，高大异常，
更有诸般奇花异树，皆为中土所无。
LONG
	);

	set("exits", ([
                "east" : __DIR__"shulin1",
		"south" : __DIR__"shulin1",
                "west" : __DIR__"shulin1",
		"north": __DIR__"shulin1",
               "northwest" : __DIR__"haitan",
	]));

	set("outdoors", "bhdao");
	setup();
	replace_program(ROOM);
}

