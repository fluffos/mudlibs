// Room: /d/linzhi/lin56.c

inherit ROOM;

void create()
{
	set("short", "高原斜路");
	set("long", @LONG
这里是高原斜路，你走在高低不平的斜坡道上，不由得打起
万分精神。忽然一只像老鼠又像兔子的东西从你面前窜过，眨眼
间没入草丛不见了。南面出现一片树林。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"lin56",
  "south" : __DIR__"lin58",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4200);
	setup();
	replace_program(ROOM);
}
