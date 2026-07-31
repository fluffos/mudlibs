
// Room: /d/snow/eroad1.c

inherit ROOM;

void create()
{
    set("coor",({0,4850,10}));
	set("short", "驿站小径");
	set("long",
"从这条青石官道往西行就可以到达宁远城衙门。往东是一条石板路，往南则是去宁远城的中\n"
"心广场。\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"nroad1",
  "west" : __DIR__"postoffice",
  "north" : __DIR__"crossroad",
]));
	set("no_clean_up",0);
	set("outdoors", "ny");
//    set("objects",());
	setup();
	replace_program(ROOM);
}
