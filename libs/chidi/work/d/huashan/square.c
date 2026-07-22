// square.c
inherit ROOM;
void create()
{
    set("short", "练武场");
    set("long", @LONG
这里是华山派的练武场，通常有许多华山派弟子在此习武练剑，所以
不欢迎外人。北边的房屋门上挂着一块匾，上书「有所不为轩」，东面是
华山派弟子存放兵器的地方。
LONG
    );
    set("exits", ([ /* sizeof() == 2 */
        "south" : __DIR__"yunu",
        "north" : __DIR__"buwei1",
        "east" : __DIR__"bingqifang",
        "west" : __DIR__"xiaodian",
    ]));
    set("objects", ([ 
        __DIR__"npc/shidaizi"   : 1,
        CLASS_D("huashan")+"/yue"  : 1,
    ]));
    set("no_clean_up", 0);
    set("outdoors", "huashan" );
    setup();
        "/d/board/huashan_b"->foo();
    replace_program(ROOM);
}
