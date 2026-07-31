// Room: /d/linzhi/inn02.c

inherit ROOM;

void create()
{
	set("short", "牲口圈");
	set("long", @LONG
这里是客店存牲口的地方，南面围栏内是一群活羊，北面木
桩上栓着几头牛，旁边围栏内是一些鸡兔什么的。如有客人点什
么肉，伙计们就来这里现抓现宰。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"inn",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
