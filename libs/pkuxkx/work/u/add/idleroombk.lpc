inherit ROOM;

void create()
{

    set("short","发呆室");
    set("long",@LONG
这里是北大侠客行发呆室，平时在这里发呆聊天的人可真不少。    
大家没什么事情别老呆中央广场，到这里发呆吧，这里还比较安全。
LONG
    );

    set("objects", ([
                //                 "/d/city/npc/lonelysword" :1,
                "/new_quest/xiaobao/manbudong" :1,
                ]));
    set("exits", ([
                "up" : __DIR__"guangchang",
                ]));
    set("no_sleep_room",1);
    set("no_quit",1);
    set("cant_drop",1);
    set("no_fight", 1);
    setup();
    "/clone/board/idle_b"->foo();
}
void init()
{
    add_action("do_none", "perform");
    add_action("do_none", "yun");
    add_action("do_none", "study");
    add_action("do_none", "du");
    add_action("do_none", "lian");
    add_action("do_none", "practice");
    add_action("do_none", "dazuo");
    add_action("do_none", "exercise");
    add_action("do_none", "tuna");
    add_action("do_none", "respirate");
    add_action("do_none", "read");
    add_action("do_none", "dz");
    add_action("do_none", "hitall");
    add_action("do_none", "killall");
    add_action("do_none", "kill");
    add_action("do_none", "exert");
    add_action("do_none", "qiecuo");
    add_action("do_none", "xiulian");
}
int do_none()
{
    return 1;
}
