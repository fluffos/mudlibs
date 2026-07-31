// by dubei
// Modify By River 99.5.20
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"观澜亭"NOR);
        set("long", @LONG
这座亭子四角攥尖顶，檐角飞翘，四柱拱托，古拙而又精巧。山下弧形水
渠环绕，水声潺潺，亭四周山石林立，千资百态。坐立亭中可望碧波滚滚，令
人有临海观澜之感。
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"xiaoxi",
                "east" : __DIR__"xqx",
        ]));

        set("outdoors", "绝情谷");
        setup();
        replace_program(ROOM);
}
