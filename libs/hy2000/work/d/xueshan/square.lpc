// square.c

inherit ROOM;

void create()
{
        set("short", "练武场");
        set("long", @LONG
这里是雪山派的练武场，场上立这几个木人，东边是兵器库，西边是
个广场。通常有许多学雪山派弟子在此习武练剑。
LONG );
        set("exits", ([ /* sizeof() == 2 */         
            "south"     : __DIR__"kufang"
        ]));
        set("objects", ([
            "/d/shaolin/npc/mu-ren" : 5,
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
}
 
