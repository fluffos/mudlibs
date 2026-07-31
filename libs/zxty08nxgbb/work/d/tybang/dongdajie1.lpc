#include "/d/tybang/tybang.h";
inherit ROOM;
void create()
{
        set("short", HIR"东大街"NOR);
        set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。东边不时地传来人群吵
杂的声音，西边人声嘈杂。北边则是一个石室，半月形的门口上方写着"寒冰
室"三个烫金大字，苍劲有力。远远看去里面烟雾迷茫，似是十分神秘。
LONG
        );
        set("outdoors", "tybang");
        set("exits", ([
                "west" : __DIR__"guangchang",
                "north" : __DIR__"hanbing",                
                "east" : __DIR__"dongdajie2",                
        ]));
        set("objects", ([
        ]));
        setup();
}

