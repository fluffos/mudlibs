// Room: /shenlongjiao/shanyao.c
// kiden 06/08/25

inherit ROOM;

void create()
{
        set("short", "山腰");
        set("long", @LONG
行了七八里，来到三间竹屋前停下。那屋子的墙壁顶均由碗口大小的粗竹所编，看来甚是坚实。
江南河北，均未见过如此模样的竹屋。
LONG
        );
        set("outdoors", "city");

        set("exits", ([
                "northup" : __DIR__"shijie4",        
                "southeast" : __DIR__"keting",
//                "south" : __DIR__"shulin5",
                "south" : __DIR__"shijie3",                
        ]));

   set("objects", ([
         __DIR__"npc/xunshandizi":1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}

