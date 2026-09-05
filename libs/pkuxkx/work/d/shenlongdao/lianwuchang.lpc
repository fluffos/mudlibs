// Room: /shenlongjiao/lianwuchang.c
// kiden 06/08/25

inherit ROOM;

void create()
{
        set("short", "练武场");
        set("long", @LONG
    这里是一片平坦的空地，看起来是练武场，还有几个弟子在不远处练剑。
北边是一条长廊，通向北边的一个大房子，门口还挂了一个大匾，不过太远了，看不清是什么字。

LONG
        );
        set("outdoors", "shenlongdao");

        set("exits", ([
                "north" : __DIR__"changlang1",  
                "south" : __DIR__"fengding",                     
                "west" : __DIR__"xiaoting",                     
                "east" : __DIR__"xiaodao",                     
//                "northwest" : __DIR__"dragon1",    
//                                                              "northeast" : __DIR__"dragon2",                       
        ]));

   set("objects", ([
              __DIR__"npc/dizi" : 2,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}

