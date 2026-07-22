#pragma save_binary
// Room: /d/green/wstorage.c

inherit ROOM;

void create()
{
	set("coor",({300,4860,25}));
	set("short","武器库");
	set("long",
"这是一间不大的房子，房间的四壁挂满了各式各样的兵刃。房子\n"
"西面有一个小门，门外是一条泥土路。有几只狼狗在屋中走来走\n"
"去n"
);
		set("exits", ([ /* sizeof() == 1 */
        "east" : __DIR__"fort2",
		]));
	set("no_clean_up", 0);
	set("objects", ([ /*sizeof()=2*/
		__DIR__"npc/wolfdog" : 4 ,
		__DIR__"obj/blade" : 1,
		__DIR__"obj/sword":1,
    "/d/goathill/npc/bandit_hwang" :1,
//		__DIR__"obj/heavensword":1,
//		__DIR__"obj/dragonblade":1,
]));
	setup();
}

void init()
{ 
	object ob;

	if( interactive( ob = this_player() ))
		if(ob->query("marks/杀狗"))
			ob->set("marks/杀狗",0);
}
