
// Room: /d/snow/droad2.c

inherit ROOM;

void create()
{
        set("coor",({-20,5020,15}));
	set("short", "山路");
	set("long",
"这是一条杂草从生的小路，已多年没有人从这里走过，路旁树上栖息着几只乌鸦，不时传来\n"
"凄惨又令人毛骨竦然的叫声，向北望去隐约可见一座高山。\n"
);
	set("exits", ([ /* sizeof() == 2 */
    "north" : "/d/yanjing/to_yj",
  "southdown" : __DIR__"droad1",
]));
	set("outdoors", "ny");
	set("objects", ([
                __DIR__"npc/snake": 1 ]) );

	setup();
	replace_program(ROOM);
}
