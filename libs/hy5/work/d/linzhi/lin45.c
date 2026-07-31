// Room: /d/linzhi/lin45.c

inherit ROOM;

void create()
{
	set("short", "高原针松林");
	set("long", @LONG
这里是一片针松林，四周都是高大的落叶松。周围十分的安
静，似乎都能听到松针落地的声音。南面不时传来阵阵的钟声，
北面是一片果林。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lin42",
  "south" : __DIR__"lin46",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4000);
	setup();
	replace_program(ROOM);
}
