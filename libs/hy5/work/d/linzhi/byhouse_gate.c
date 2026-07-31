// Room: /d/linzhi/byhouse_gate.c

inherit ROOM;

void create()
{
	set("short", "巴府大门");
	set("long", @LONG
你来到巴依老爷府第大门前，只见两个身着藏袍，手持腰刀
的巴府守卫威风的站在门口。看见你走来，凶巴巴的看着你。看
起来不太好惹。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
 // "east" : __DIR__"byhouse_gate",
  "west" : __DIR__"by05",
  "north" : __DIR__"by06",
]));

  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/cityguard" : 2,  	
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
