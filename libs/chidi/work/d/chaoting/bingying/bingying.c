#pragma save_binary
// Room: /u/cloud/dragonhill/nroad.c

inherit ROOM;

void create()
{
        set("coor",({0,4450,10}));
	set("short", "辽东兵营");
        set("long", @LONG
这里是辽东官兵大营,在此你可以看到一队队官兵正在操练，他们
是朝廷打胜仗的根本。只要你有兵符，你就可以调动数万大军与土匪
周旋。往北是辽东兵营的寨门。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
 "north" : __DIR__"bingying_gate",
//		"south" : "/d/oldpine/npath1",
]));
 set("objects", ([
                   //    __DIR__"npc/zhiqin_bing" : 2,
                      __DIR__"npc/xiong" : 1,
                              ]));
        set("outdoors", "dragonhill");

        setup();
}
