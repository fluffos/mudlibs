inherit ROOM;

void create()// square2.c


{
        set("short", "练武场");
        set("long", @LONG
这里是丐帮的练武场，场上立这几个木人，通常有许多丐帮的弟子在
此习武练剑。
LONG );
        set("exits", ([ /* sizeof() == 2 */        
            "north" : __DIR__"mishi",       
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
        if ((!myfam ||myfam["family_name"] != "丐帮") && (dir == "east"))
                return notify_fail(
"那边是丐帮的练武场，这位" + RANK_D->query_respect(me) + "请止步。\n");
        return ::valid_leave(me, dir);
}

