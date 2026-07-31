// Room: /d/fengtian/wuguan2.c

inherit ROOM;

void create()
{
	set("short", "练功场");
	set("long", @LONG
这里是新月武馆的练功场，平时弟子们都在这里练功，场子
中央摆放着各种练功器械。
LONG
	);
	set("cannot_build_home", 1);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"obj/shisuo" : 2,
  __DIR__"npc/dizi" : 5,
]));
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"wuguan4",
  "west" : __DIR__"wuguan3",
  "south" : __DIR__"wuguan",
]));
	set("outdoors", "fengtian");

	setup();
	replace_program(ROOM);
}
