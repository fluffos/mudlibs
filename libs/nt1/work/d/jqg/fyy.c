// by dubei
// Modify By River 99.5.20
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIR"飞云岩"NOR);
        set("long", @LONG
这里似洞非洞，顶上崖檐覆出，石乳倒垂。浮者若飞霞，亘者若虹霓，豁
然楼殿门阙，悬若铜鼓编磬，并有狮象蛟龙、莲荷阡陌、蜂房水涡之属。其下
澄潭邃谷，幽深无底，四面茂盛古树参天，流水潆洄。
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"xqx",
                "northup" : __DIR__"shanjing",
        ]));
        
        set("outdoors", "绝情谷");
        setup();
        replace_program(ROOM);
}
