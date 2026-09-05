// Room: /d/quanzhou/dengta_3.c
// cgbii 96.10.4

inherit ROOM;




void create()
{
        set("short", "灯塔三层");
        set("long", @LONG
塔身往上，楼梯也渐挤。从窗孔往外望，可以看到很远
海面，还看到一群海鸥在塔外飞翔在，在楼梯口前写了几个
字，你往前一看原来上面写着“擅入者死”。
LONG
        );

        set("exits", ([
                "up" : __DIR__"dengta_4",
                "down" : __DIR__"dengta_2",
        ]));
        set("objects", ([
                 __DIR__"npc/wo_kou":5,
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
