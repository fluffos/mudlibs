 // /u/beyond/hz/shanquan.c 山泉
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",HIW"山泉"NOR);
        set("long", @LONG
从山上一股清泉直流而下，在山脚汇集成一潭清水，在清水泉旁有一个
小茅舍，茅舍外面是由一圈竹篱笆圈着，一个小竹门半掩着，里面不知住的
是什么人。
LONG
        );
        set("outdoors", "hz");
        set("resource/water", 1);
        set("exits", ([
        "enter" : __DIR__"maoshe",
        "east" : __DIR__"shanquan",
        "south" : __DIR__"shanlu1",
        ]));
        setup();
}
