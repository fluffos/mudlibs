// File		: liangroom.c
// Created By	: iszt@pkuxkx, 2007-02-16

inherit ROOM;

void create()
{
	set("short", "梁自进居所");
	set("long", @LONG
这是梁自进的居所，他生性单纯，与廖自励正好相反。他自小便在凌霄城中
练功习武，连雪山也未下过一步，所以武功在同辈弟子中仅次于白自在。这里的
一切朴素自然，仅有一床一桌。除此之外，别无他物。 
LONG);

	set("indoors", "凌霄城");
	set("exits", ([
		"south" : __DIR__"stonew4",
	]));

        set("objects", ([
                __DIR__"npc/liangzijin" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
