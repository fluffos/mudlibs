// Room: /d/emei/shanmen.c 峨嵋派 山门
// create by host dec,12

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "山门");
    set("long", @LONG
这里是峨嵋的山脚下，几座山峰在云雾中隐约可见，一条石阶向山上
延伸，走着几个进香客。一座巨大的牌坊横架在石阶中间，牌坊正上银钩
铁划般的刻着两个斗大的字：『峨嵋』。
LONG
    );

    set("exits", ([
        "north":__DIR__"shanlu3",
        "southup": __DIR__"baoguosi",
    ]));

    set("outdoors", "emei");
    set("objects",([
    ]));
    setup();
}