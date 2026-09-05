// Room: /shenlongjiao/shanlu4.c
// kiden 06/08/25

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
远远看去，隐隐可以看到北方山峰中有飞檐显出。
行不多时，只见树上、草上、路上，东一条，西一条，全是毒蛇。

LONG
        );
        set("outdoors", "shenlongdao");

        set("exits", ([
                "southdown" : __DIR__"shanlu5",        
                "northup" : __DIR__"shanlu7",        
               
        ]));

   set("objects", ([
         __DIR__"npc/snake"+random(7):1,
         __DIR__"npc/snake"+random(7):1,
         __DIR__"npc/snake"+random(7):1,
         __DIR__"npc/snake"+random(7):1,
         __DIR__"npc/snake"+random(7):1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}

