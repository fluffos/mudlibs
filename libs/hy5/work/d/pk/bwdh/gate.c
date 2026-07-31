//试剑山庄  gate.c

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short",HIR"试剑山庄"NOR);
        set("long", @LONG
眼面的庄院就是名满天下的试剑山庄了，你不觉松了一口气，前往山庄的地
上打扫的一尘不染，汉白玉砌成的台阶豪华典雅，古红木定制的大门紧闭着，使
人无法洞悉门内的一切，三丈多高的琉璃墙在透过树叶的阳光照耀下闪闪发亮，
寂静的四周只闻的远方鸟儿的鸣嘀声。
LONG
        );
        set("exits", ([
        "southdown" : "/d/pk/pk/turen9",        
        "north" : __DIR__"qianting",
        ]));
        
        set("no_death",1);set("bwdhpk",1);
        set("outdoors", "试剑山庄");

        setup();
}

