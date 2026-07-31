//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "陈麻婆豆腐店");
        set("long", @LONG
这里就是闻名天下的陈麻婆豆腐店。店堂里整齐的摆放着
十几张红漆方桌，一般客人就在这里品尝陈麻婆豆腐。几个伙
计忙的是晕头转向.柜台上摆着两坛“老妈红”和一把算盘，后
面端坐着的就是陈麻婆。东面是有个厨房。
LONG
        );

        set("exits", ([
                "west" : __DIR__"beijie1",                
                "east" : __DIR__"chufang",
        ]));
        set("objects", ([
                "/d/city3/npc/mapo" : 1,
        ]));
      
        setup();
        replace_program(ROOM);
}

 
