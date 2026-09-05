// Room: /shenlongjiao/shijie4.c
// kiden 06/08/25

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
石阶渐渐到了劲头，往前看就是一条较为平坦的山路了。回头看去，隐隐可以看到竹屋的一角。
LONG
        );
        set("outdoors", "shenlongdao");

        set("exits", ([
                "southdown" : __DIR__"shanyao",        
                "north" : __DIR__"shanlu",        
//                "north" : __DIR__"chufang",
//                "south" : __DIR__"shulin5",
//                "west" : __DIR__"woshi",                
        ]));

   set("objects", ([
//         __DIR__"npc/liumang":1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}

