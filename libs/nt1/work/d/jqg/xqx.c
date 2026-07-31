// by dubei
// Modify By River 99.5.20
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG"响琴榭"NOR);
        set("long", @LONG
榭为三间，东南北三面为敞选，中为明间，顶部平直，结构灵巧。榭下是
就是引泉入池的渠道，上有响琴桥，当流水击石时，声若琴瑟。气爽风清，到
是个读书做画的好去处。
LONG
        );

        set("exits", ([
                "northup" : __DIR__"fyy",
                "west" : __DIR__"glt",
        ]));

        set("outdoors", "绝情谷");
        setup();
        replace_program(ROOM);
}
