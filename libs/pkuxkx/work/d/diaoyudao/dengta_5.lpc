// Room: /d/quanzhou/dengta_5.c
// cgbii 96.10.3

inherit ROOM;


void create()
{
        set("short", "灯塔五层");
        set("long", @LONG
这里收拾得整整齐齐，中央供放着一把东瀛武士刀，你感觉
一股寒气透出刀身向你扑来，周围的墙壁上挂满了各种各样你没
有见过的武器和物品，看来是一间摆放武器的房间。
LONG
        );

        set("exits", ([
                "up" : __DIR__"dengta_6",
                "down" : __DIR__"dengta_4",
        ]));
        set("objects", ([
                 __DIR__"npc/wo_kou":6,
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
