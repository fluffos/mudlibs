// Room: /d/paiyun/kongdi.c

inherit ROOM;

void create()
{
	set("short", "林间空地");
	set("long", @LONG
一片林间空地在树林中好象别有洞天，空地上有一口井，井
口上有不少青苔，看样子很久没人在这里打水了。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lin2",
  "east" : __DIR__"lin1",
]));
        set("objects",([
        __DIR__"npc/cleaner" : 1,
]));


	set("outdoors", "paiyun");

	setup();
	replace_program(ROOM);
}
