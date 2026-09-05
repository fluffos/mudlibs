// File		: chengroom.c
// Created By	: iszt@pkuxkx, 2007-02-16

inherit ROOM;

void create()
{
	set("short", "成自学居所");
	set("long", @LONG
这是成自学的居所。成自学为人方正，刚严不曲。他排行仅次于白自在，虽
和四位师弟一样，由白自在代师授艺，但在四位师兄弟中，最得白自在信任。这
间屋子整洁典雅，只在桌上放着几卷未写完的帛卷。
LONG);

	set("indoors", "凌霄城");
	set("exits", ([
		"south" : __DIR__"stonen4",
	]));

        set("objects", ([
                __DIR__"npc/chengzixue" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
