// /d/wudang/shuitan.c  水潭

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIB"水潭"NOR);
        set("long", @LONG
这是一碧绿水潭，潭水清澈，水寒刺骨，好象还有什么东西在咬你的脚趾，
还是赶快爬上岸吧。
LONG                           
        );
	set("outdoors", "武当");
        setup();

}

void init()
{
        add_action("do_pa","pa");
        add_action("do_qian",({"qian","dive"}));
}

int do_pa(string arg)
{
	object me;
        me=this_player();

        if ( !arg || arg != "up" )
            return notify_fail("你用狗爬式在水里游来游去!\n");

        if ( me->is_busy() || me->is_fighting())
            return notify_fail("你正忙着呢。\n");

        message_vision("$N浑身湿透，落汤鸡似地爬上了岸。\n", me);
        me->move(__DIR__"gudao3");
        return 1;
}

int do_qian(string arg)
{
	object me;
        me=this_player();

        if ( !arg || (arg != "down"))
            return notify_fail("你象条鱼般在水里游来游去!\n");

        if ( me->is_busy() || me->is_fighting())
            return notify_fail("你正忙着呢。\n");

        if (arg =="down") {
           message_vision("$N一个猛栽，潜了下去。\n", me);
           me->receive_damage("jingli", 60-(int)me->query_skill("dodge", 1)/20);
           me->move(__DIR__"tandi1");
           me->apply_condition("diving",1);
           tell_room(environment(me), me->name() + "从上面潜了下来。\n", ({ me }));
           return 1;
        }
        return 1;
} 
