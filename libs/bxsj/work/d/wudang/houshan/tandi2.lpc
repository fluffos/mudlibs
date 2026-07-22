// /d/wudang/tandi2.c  水潭底

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIB"水潭底"NOR);
        set("long", @LONG
你身处水潭潭底，潭底细沙如雪，潭水墨蓝，水寒刺骨，寂静一片，阴深
恐怖。
LONG                           
        );
        set("objects",([        
            "/d/wudang/npc/eyu" : 1,
        ]));
        set("outdoors", "武当");
        setup();

}
void init()
{
        add_action("do_qian",({"qian","dive"}));
}

int do_qian(string arg)
{
	object me;
        me = this_player();

        if ( !arg || (arg != "down" && arg != "up" ))
            return notify_fail("你象条鱼般在水里游来游去!\n");

        if (arg =="down")
            return notify_fail("你想当泥鳅往地下钻呀!\n");

        if ( me->is_busy() || me->is_fighting())
            return notify_fail("你正忙着呢。\n");
            
        message_vision("$N一蹬腿，往上游去。\n", me);
        me->receive_damage("jingli", 50-(int)me->query_skill("dodge", 1)/20);
        me->move(__DIR__"tandi1");
        tell_room(environment(me), me->name() + "从水下冒了上来。\n", ({ me }));
        return 1;      
}
