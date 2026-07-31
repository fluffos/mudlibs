// square.c

inherit ROOM;

void create()
{
        set("short", "练武场");
	set("long", @LONG
这里是华山派的练武场，场上立这几个木人，东边是兵器库，西边是
个小店。通常有许多华山派弟子在此习武练剑。北边的房屋门上挂着一块
匾，上书「群仙观」，西北方似乎有条小道通往山上。
LONG );
        set("exits", ([ /* sizeof() == 2 */
            "northwest" : __DIR__"chaopath1",
            "south"     : __DIR__"yunu",
            "north"     : __DIR__"qunxianguan",
            "west"      : __DIR__"shop",
            "east"      : __DIR__"bingqifang",
            "southwest" : __DIR__"hsforest1",
        ]));
        set("objects", ([
            "/d/shaolin/npc/mu-ren" : 5,
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
}
 
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam=(mapping)me->query("family");
	if ((!myfam ||myfam["family_name"] != "华山派") && (dir == "east"))
                return notify_fail(
"那边是华山派的兵器库，这位" + RANK_D->query_respect(me) + "请止步。\n");
        return ::valid_leave(me, dir);
}
 
