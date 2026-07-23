// Room: /d/city/jiaowai1.c
// Jan. 8.1998 by Venus
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "草地");
    set("long", @LONG
这是扬州郊外的一片芳草地，落英缤纷，蜂歌蝶舞，朝露
夕光，沁人心脾。真是好时光。偶有几对小男女结伴踏青，莺
声丽影，嬉闹动人。
LONG );

    set("exits", ([
        "north" : __DIR__"dongmen",
        "south" : __DIR__"jiaowai2",
        "west"  : __DIR__"course",
        "east"  : __DIR__"bite",
    ]));

    set("no_clean_up", 0);
    set_temp("wayao1",1);
    set("outdoors", "yangzhou");
    setup();
    create_door("east", "垂花小门", "west", DOOR_CLOSED);
    create_door("west", "垂花小门", "east", DOOR_CLOSED);
}
int valid_leave(object me, string dir)
{
    me = this_player();
    if ((me->query("id")!="course" && me->query("id")!="qixia") && dir == "west")
    {
       return notify_fail(RED"那是人家的私宅，别去讨嫌了！\n"NOR);
    }
    if ((me->query("id")!="bite" && me->query("id")!="princess") && dir == "east")
    {
       return notify_fail(RED"那是人家的私宅，别去讨嫌了！\n"NOR);
    }
    return ::valid_leave(me, dir);
}

