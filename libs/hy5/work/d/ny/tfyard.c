

inherit ROOM;

void create()
{
        set("coor",({-70,4750,10}));
	set("short", "观景台");
	set("long",
"这是一间不大的亭院平台，台前有张小方桌,中央有一棵千年榕树，轻风吹过，传来阵阵沁\n"
"人心脾的花香。在烦嚣热闹的宁远城中,竟然有这么个地方给游人们停歇的地方,一些老者们\n"
"都爱到这来,品茶谈天.\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"mstreet3",
	]));
    set("no_fight", 1);
        set("objects", ([
//               "/d/chaoting/npc/japanese" : 3,  
        ]));

	setup();
	replace_program(ROOM);
}
