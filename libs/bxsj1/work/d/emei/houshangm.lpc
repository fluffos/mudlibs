// emei 灌木丛

#include <room.h>
inherit ROOM;


void create()
{
        set("short", "灌木丛");
        set("long", @LONG
这里是一片一人多高的灌木丛，这里已经罕见足迹。一阵风吹过，灌木丛
发出沙沙的声音。东南西北都是矮树灌木，这里没有路，每走一步，荆棘都会
钩刺到衣裤，划破你的身体。
LONG
        );

        set("exits", ([
                "northeast" : __DIR__"houshangm",
                "southwest" : __DIR__"houshangm",
                "eastdown" : __DIR__"houshangm",
                "westup" : __DIR__"houshangm",
        ]));

        set("outdoors", "峨眉山");
        setup();
}

int valid_leave(object me, string dir)
{
    me->set_temp("last_damage_from", "在灌木丛里筋疲力尽累");
    me->receive_damage("jingli", random(200) );
    if (dir == "eastdown" && me->query("family/master_id") == "guhong zi") {
        me->delete_temp("steps");
        me->move(__DIR__"houshangm1");
        return notify_fail("你终于走出了灌木丛。\n");
    }
    if ( dir == "eastdown" ) me->add_temp("steps", random(30));
    if ( dir == "westup" ) me->add_temp("steps", - random(20));
    if ( dir == "northeast" ) me->add_temp("steps", random(10));
    if ( dir == "southwest" ) me->add_temp("steps", -random(10));
    if ( (int)me->query_temp("steps") < 110 && (int)me->query_temp("steps") >100 ) {
        me->delete_temp("steps");
        me->move(__DIR__"houshangm1");
        return notify_fail("你终于走出了灌木丛。\n");
    }
    return ::valid_leave(me, dir);

} 
