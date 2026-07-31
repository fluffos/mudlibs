// houshan.c 后山
// zly 99.7.28

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"后山"NOR);
        set("long", @LONG
这里是后山的一个隐蔽的小山谷，长年人迹罕至。谷中古树参天，
绿荫森森。不失为一个修炼功夫的好地方，偶尔从远处传来几声悠扬的
鸟语，伴随着阵阵花香，简直让人疑心自己到了世外桃源。
LONG
        );
        set("exits", ([
            "south" : __DIR__"shulin",
        ]));

        set("objects", ([
             //__DIR__"npc/xiaozh" : 1,
             __DIR__"npc/yuangn" : 1,
        ]));

        setup();
}
