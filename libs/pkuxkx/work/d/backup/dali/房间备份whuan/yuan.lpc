// /d/dali/yuan

inherit ROOM;

void create()
{
    set("short", "雨花院");
    set("long", @LONG
相传当年佛祖降临天龙寺传法时，漫天遍洒雨花石。后人以石建 
院，即成此间玉花院。院中常年檀香四溢，令人心旷神怡
LONG
       );
    set("outdoors", "dali");

    set("exits", ([
                "east" : __DIR__"dining",
                "west" : __DIR__"restroom",
                "north" : __DIR__"changlang2",
                "south" : __DIR__"dadian",
                ]));
    set("objects", ([
                __DIR__"npc/benxiang" : 1,
                __DIR__"npc/shami" : 4 ]) );
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}
