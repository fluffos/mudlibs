// Room: /d/japan/xuanguan.c

inherit ROOM;

void create()
{
	set("short", "玄关");
	set("long", @LONG
跨过高高的门坎,就是玄关,旁边摆着几副木屐,去拜访柳生的人,都
要在此换鞋后才能进去,有两个武士正等着他的接见.
LONG
	);
	set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
               __DIR__"npc/man" : 2,
            ]));
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"zoulang",
  "north" : __DIR__"liushengfu",
]));

	setup();
	replace_program(ROOM);
}
