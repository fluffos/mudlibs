//canchang
  

inherit ROOM;

void create()
{
	set("short", "训练中心");
	set("long", @LONG
这里是平安城为新手训练武功的地方，里面有几个木人，用来和你练功。
注意,这里练功,不受平安之气的保卫.
LONG
	);
         set("no_steal",1);
//         set("pingan",1);
         set("no_beg",1); 	

	set("exits", ([
		"east" : __DIR__"nan3",
	]));
        set("objects", ([
		__DIR__"npc/mu-ren" : 1,
		__DIR__"npc/mu-ren2" : 1,
		__DIR__"npc/mu-ren3" : 1,
		__DIR__"npc/mu-ren4" : 1,
		__DIR__"npc/mu-ren5" : 1,
	]));


	setup();
	replace_program(ROOM);
}

