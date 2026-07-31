 inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "灌木");
        set("long", @LONG
黄土路到了著里突然消失了。在这里长满了一种半人高的碧绿色的植物，
它们充斥了这里的每一个角落，并围绕在你的周围。奇怪的是，这里是死一
般的寂静，不见任何动物的踪迹。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"keng",
]));
        set("outdoors", "palace");
        set("coor/x",220);
        set("coor/y",-50);
        set("coor/z",20);
        setup();
}
int valid_leave(object me, string dir)
{
        message_vision( HIR "一阵淡淡的粉红烟雾飘过，$N不由地深吸了一口气。\n\n\n"NOR,me);
        if(!me->query_condition("red_blood"))
                me->apply_condition("red_blood",random(10)+10); 
        return 1;
}      
