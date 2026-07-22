#pragma save_binary
// Room: /d/goathill/temple1.c

inherit ROOM;

void create()
{
	set("coor",({50,5000,10}));
	set("short", "小土地庙");
	set("long",
"你现在正站在一间小土地庙中，这座庙的南北两面都是利用了山\n"
"壁而建的，只有东面一面土墙，墙上嵌著一个小小的神□，里面\n"
"供著一尊残破不堪的土地爷爷，庙门在你的西边。\n"
);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"mroad3",
	]));
	set("objects", ([
     //   __DIR__"npc/bandit_hwang" : 1,
	]) );

	setup();
}
void init()
{
    if(this_player())
        this_player()->set_explore("north#26");
}
