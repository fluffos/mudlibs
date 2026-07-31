// Room: /d/linzhi/by11.c
// Room: /d/linzhi/by10.c

inherit ROOM;

void create()
{
	set("short", "河谷丛林");
	set("long", @LONG
你来到易贡河谷的丛林区内，只见四处是高山植物，风一吹
过，哗哗在作响。你根本无法找到出路。看来只能摸着来了。背
后一哗哗地声响，你猛地回头一看，只见一道黑影嗖地窜入丛林
不见了，你心中一动，不由得加快了脚步。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"by10",
  "north" : __DIR__"by12",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 2100);
	setup();
	replace_program(ROOM);
}

