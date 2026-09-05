inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
你不知不觉走进了一片树林中，极目青绿，苍松翠柏，高大异常，
更有诸般奇花异树，皆为中土所无。树林到此已是尽头，东面火光
冲天，不知是何所在。北面隐隐约约有个山洞。
LONG
	);

	set("exits", ([
                 "east" : __DIR__"huoshan",
		 "west" : __DIR__"shulin3",
		 "north": __DIR__"bhdong",
                ]));

	set("outdoors", "diaoyudao");
	setup();
	replace_program(ROOM);
}
