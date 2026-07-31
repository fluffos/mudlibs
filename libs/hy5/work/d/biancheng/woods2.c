 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "林间");
        set("long", @LONG
树林并不浓密，白杨树寬大的葉子片片向上，幾乎沒有斜生的，更不用說倒垂
了。树皮光滑而有銀色的暈圈，微微泛出淡青色。树林里，竟然摆着张小桌子。桌
子上摆着些纸人纸马，还有一柄纸刀。用白纸糊成的刀，但刀柄却涂成了黑色。
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"woods",
                "south" : __DIR__"woodcabin",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1150);
        set("coor/y",80);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
