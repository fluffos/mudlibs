// Room: /d/quanzhou/debgta_2.c
// cgbii 96.10.4

inherit ROOM;




void create()
{
        set("short", "灯塔二层");
        set("long", @LONG
这个楼层上都铺设了结实的青石板，墙身上则开了两扇大
窗。从窗孔看，墙体也是极为厚实。从这里往外眺望，可以看
到围绕灯塔周围的海滩，从窗外面吹来阵阵海风。
LONG
        );

        set("exits", ([
                "up" : __DIR__"dengta_3",
                "down" : __DIR__"dengta_1",
        ]));
        set("objects", ([
                 __DIR__"npc/wo_kou":4,
         ]));
        setup();

}

int valid_leave(object me,string dir)
{
if (dir=="up"){
if (objectp(present("wo kou",environment(me))))
return notify_fail("倭寇拦住你怒喝道：八格呀路！你哪里来的！死啦死啦的你.....\n");
                             }
    return::valid_leave(me,dir);
}
