#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "食堂");
	set("long", @LONG
这里岳麓书院的食堂了，饿了可以自己取用(eat)食物。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		
        "east" : __DIR__"shuyuan2",
	]));
	setup();
	
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat()
{
        int current_food;
        int max_food;
        object me;
        me = this_player();
        current_food = me->query("food");
        max_food = (int)me->max_food_capacity();
        if (me->is_busy())
        {
            write("你正忙着呢。\n");
            return 1;
        }
        if (current_food<max_food) {
                me->add("food", 50);
                me->add_busy(1);
                message("vision", me->name()+"拿起桌上的冷馒头，一顿狂嚼。\n",
                        environment(me), ({me}) );
                write("你拿起冷馒头，小心翼翼地吃了起来。\n");
        }
        else write("你已经吃饱了，还是别吃了。\n");

        return 1;
}