
// Room: /d/snow/school.c

inherit ROOM;

void create()
{
	set("coor",({-100,4750,10}));
	set("short", "书院");
	set("long",
"这里是一间宽敞的书院，虽然房子看起来很老旧了，但是打扫得很整洁，墙壁上挂著一幅山\n"
"水画，意境颇为不俗，书院的大门开在北边，西边有一扇木门通往边厢。\n"
);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"mstreet4",
]));

	set("objects", ([
		__DIR__"npc/teacher": 1 ]) );
	setup();
}
void init()
{
    if(this_player())
        this_player()->set_explore("north#20");
}
