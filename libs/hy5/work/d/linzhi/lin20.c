// Room: /d/linzhi/lin20.c

inherit ROOM;

void create()
{
	set("short", "梅里雪山旁道");
	set("long", @LONG
你走到高原山路上，东南不远就是著名的梅里雪山了。在这
种路况下，随时会有意外发生，你不由得万分小心，加快了前进
的脚步。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"lin19",
  "westup" : __DIR__"lin24",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 5400);
	setup();
	replace_program(ROOM);
}
