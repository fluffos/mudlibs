// Room: /d/linzhi/lin56.c

inherit ROOM;

void create()
{
	set("short", "高原斜路");
	set("long", @LONG
这里是高原斜路，你走在高低不平的斜坡道上，不由得打起
万分精神。忽然一只像老鼠又像兔子的东西从你面前窜过，眨眼
间没入草丛不见了，你觉得十分奇怪。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"lin55",
  "southeast" : __DIR__"lin57",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4100);
	setup();
	replace_program(ROOM);
}
