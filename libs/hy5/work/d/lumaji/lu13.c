
inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条乡间小路，路的西首就是本村的赵猎户家，再向北
去是一片树林。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([

  "west" : __DIR__"liehu",
  "south" : __DIR__"lu12",
]));

	set("objects", ([
		"/clone/npc/man" : 2,
	]));

	set("outdoors", "lumaji");
	setup();


	replace_program(ROOM);
}
