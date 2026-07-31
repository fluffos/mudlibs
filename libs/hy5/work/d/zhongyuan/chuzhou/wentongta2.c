// 楚州文通塔内部 /d/city/chuzhou/wentongta2.c
// by lala, 1997-12-05

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", WHT"文通塔"NOR);
    set("long", @LONG
文通塔整个是木制结构，踩在木制的楼梯上，只听得楼梯吱嘎作响，一些灰
尘扑簌簌的落下来，在一道斜射进来的阳光中飞舞。塔里面很暗，只能看见四周
大约是供的释迦摩尼的神像。据说站在塔的最高层可以看见楚州城北部一直到淮
河渡口的风光。
LONG
    );
    set("not_startroom", 1);
    set("no_kill",  "yangzhou");
    set("exits", ([
        "up"        : __FILE__,
        "down"      : __FILE__
    ]));
    set("objects", ([
    ]));
    setup();
}

int valid_leave(object me, string dir)
{
    if( dir == "up" )
    {
        if( me->query_temp("wentongta") > 10 )
        {
            me->move(__DIR__"wentongta3");
            me->add_temp("wentongta", 1);
            return notify_fail("");
        }
        me->add_temp("wentongta", 1);
    }                               
    if( dir == "down" )
    {
        if( me->query_temp("wentongta") < 1 )
        {
            me->move(__DIR__"wentongta");
            me->add_temp("wentongta", -1);
            return notify_fail("");
        }
        me->add_temp("wentongta", -1);
    }        
    return ::valid_leave(me, dir);
}
    