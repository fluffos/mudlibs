// Room: /shenlongjiao/zhuwu.c
// kiden 06/08/25

inherit ROOM;

void create()
{
        set("short", "竹屋");
        set("long", @LONG
室内布置非常简单，一榻一桌一竹椅而已，但是窗外风景优美，这是守山弟子的住所。
LONG
        );

        set("sleep_room",1);
        set("exits", ([
//                "west" : __DIR__"shulin10",        
//                "northup" : __DIR__"shanjiao",
                "west" : __DIR__"shanjiao",                
        ]));

   set("objects", ([
              __DIR__"npc/dizi" : 2,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}

