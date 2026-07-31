
// Room: /d/snow/yamen_square.c

inherit ROOM;

void create()
{
	set("coor",({-40,4850,10}));
	set("short", "衙门前的广场");
	set("long",
"这里是衙门前的广场，人来人往，熙熙攘攘非常热闹，经常有人叫卖着。不时有一两个衙役\n"
"穿梭其中，用警惕的目光扫视着周围。从这里往西北去就是衙门了，东面是驿站。\n"
);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"postoffice",
    "northwest" : __DIR__"yamen_gate",
  "north" : __DIR__ "nroad4",
]));
	set("objects", ([ /* sizeof() == 6 */
 // __DIR__"npc/butcher" : 1,
  __DIR__"npc/playboy" : 2,
  __DIR__"npc/seller" : 1,
  __DIR__"npc/pgirl" : 1, 
]));
        set("outdoors", "ny");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
