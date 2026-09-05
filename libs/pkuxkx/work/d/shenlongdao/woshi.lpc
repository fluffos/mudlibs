// Room: /shenlongjiao/woshi.c
// kiden 06/08/25

inherit ROOM;

void create()
{
        set("short", "卧室");
        set("long", @LONG
这里就是应该就是主人的卧室了。卧室虽小，但干净整洁。窗前有一个小小的桌子，
摆着一面古铜镜，上面摆了一些瓶瓶罐罐，不知道里面是什么呢？
LONG
        );

        set("exits", ([
                "east" : __DIR__"keting",        
//                "out" : __DIR__"shanyao",
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

