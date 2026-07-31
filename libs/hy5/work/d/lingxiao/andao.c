//LUCAS 2000-6-18

inherit ROOM;
void create()
{
        set("short","暗道");
        set("long",@LONG 
这是一条凌霄城的暗道，看来是凌霄城里什么人出入的秘密
通道。在墙上插着的几根火把所散发出的光芒下，可以看到地下
有一本书，不知道是哪个粗心鬼掉在这里的。
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "out"  : __DIR__"muwu",
            "northdown"  : __DIR__"didi",
        ]));
        set("objects", ([
                __DIR__"obj/swordbook" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

