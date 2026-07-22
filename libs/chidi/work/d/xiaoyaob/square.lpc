// square.c

inherit ROOM;

void create()
{
        set("short", "练武场");
        set("long", @LONG
这里是逍遥派的练武场，场上立这几个木人，南边是打铁屋，
通常有许多逍遥派弟子在此习武练剑。
LONG );
        set("exits", ([ /* sizeof() == 2 */         
            "south"     : __DIR__"bingqif"
        ]));
        set("objects", ([
            "/d/shaolin/npc/mu-ren" : 5,
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
}


