// Room: some place in 西牛贺洲
// inside2.c

inherit ROOM;

void create()
{
  set ("short", "练功场");
  set ("long", @LONG

一个小小的练功场．场内一个中年道士在教一些小道们武功。周
围兵器架上放着一些兵器。
LONG);
set("exits", ([ /* sizeof() == 4 */
"west": __DIR__"gate1",
"east": __DIR__"inside7",
"north": __DIR__"inside8",
"south": __DIR__"sleep",
]));
set("objects", ([
                __DIR__"npc/xiao": 3, 
		__DIR__"obj/rack": 1,
]) );
        set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
}

