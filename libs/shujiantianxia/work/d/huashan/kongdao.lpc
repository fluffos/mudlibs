// Room: /d/huashan/kongdao.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "孔道");
        set("long", @LONG
这是一条窄窄的孔道，黑漆漆的什么也看不清楚。
LONG);
        set("indoors", "华山" );

        setup();
}

void init()
{
        add_action("do_break", "break");
        add_action("do_use", "use");
}

int do_break(string arg)
{
        object me = this_player();
        object weapon;

        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢。\n");
        if (arg != "wall")
                return notify_fail("你要打破什么？\n");
        if (query("exits/out"))
                return notify_fail("墙壁已经被打破了。\n");

        weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "sword")
                return notify_fail("你手中无剑，如何破壁？\n");

        message_vision("$N提起"+weapon->name()+"，运足内力刺向石壁。\n", me);
        if (me->query("neili") < 200) {
                me->set("neili", 0);
                message_vision("只听拍的一声，"+weapon->name()+"断为两截，原来$N内力不足。\n", me);
                weapon->move(environment(me));
                weapon->set("name", "断掉的" + weapon->name());
                weapon->set("value", 49);
                weapon->set("weapon_prop", 0);
                me->unconcious();
        } else {
                me->add("neili", -200);
                message_vision("擦的一声，"+weapon->name()+"竟尔插入石壁之中，直至没柄，石壁上露出了一个洞口。\n", me);
                set("exits/out", __DIR__"shandong");
                call_out("close", 2);
        }
        return 1;
}

void close()
{
        tell_room(this_object(), "石块塌落下来，又堵住了洞口。\n");
        delete("exits/out");
}

int do_use(string arg)
{
        object me = this_player();

        
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢。\n");
        if (arg != "fire" || !present("fire", me) || userp(present("fire", me)))
                return notify_fail("你要用什么？\n");
        message_vision("$N点燃火折，往洞的深处走了过去。\n", me);
	 me->move(__DIR__"yongdao");
        tell_room(environment(me), me->name()+"从外面走了过来。\n", ({ me }));
        return 1;
}
