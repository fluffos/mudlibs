// Room: /d/quanzhou/dengta_6.c 灯塔六层
// cgbii 96.10.4

inherit ROOM;

void create()
{
        set("short", "灯塔六层");
        set("long", @LONG
这里是灯塔的第六层，从这里的窗口往外望，可以看到一望无际的
大海。一个东洋人站在这里，嘴里嘟嘟囔囔的。再往上就是灯塔的顶层
了，看来想上去是不太容易。
LONG
        );

        set("exits", ([
                "down" : __DIR__"dengta_5",
		"up" : __DIR__"dengta_7",
        ]));

        set("objects", ([
                __DIR__"npc/wolf" : 1,
//                __DIR__"npc/obj/largebox" : 1,
        ]));

        setup();
}

int valid_leave(object me, string dir)
{

        if((objectp(present("wolf", environment(me)))) )
       {
               if (dir == "up" )
               {
                       return notify_fail("东洋鬼子冲你喊道: 你的什么的干活？快快的离开。\n");
               }
       }
       return ::valid_leave(me, dir);
}
