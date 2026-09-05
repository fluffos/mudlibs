// Room: /shenlongjiao/shanyao.c
// kiden 06/08/25

inherit ROOM;

void create()
{
        set("short", "客厅");
        set("long", @LONG
走进竹屋，你发现这里原来是一个客厅，中间放了几张檀木桌椅，挂了几幅字画，简单而大气。
一个美丽的妇人坐在椅子上刺绣，看到你进来了抬头看了你一眼，接着低下头去继续刺绣。
LONG
        );

        set("exits", ([
                "east" : __DIR__"shufang",        
                "north" : __DIR__"huilang",        
                "northwest" : __DIR__"shanyao",
                "west" : __DIR__"woshi",                
        ]));

   set("objects", ([
//         __DIR__"npc/liumang":1,
        "/d/shenlongdao/npc/lufuren":1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}

