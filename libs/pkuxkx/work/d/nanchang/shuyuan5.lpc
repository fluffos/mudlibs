#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"古井"NOR);
	set("long", @LONG
这里书院的后院，一具长满青苔的古井，你可打水喝(drink)。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		
        "south" : __DIR__"shuyuan2",
	]));
    set("resource/water", 1);
	setup();
	
}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink()
{
        int current_water;
        int max_water;
        object me;
        me = this_player();
        current_water = me->query("water");
        max_water = (int)me->max_water_capacity();
        if (me->is_busy())
        {
            write("你正忙着呢。\n");
            return 1;
        }
        if (current_water<max_water) {
                me->add("water", 50);
                me->add_busy(1);
                message("vision", me->name()+"拿起井边的水瓢，畅快地喝了起来。\n",
                        environment(me), ({me}) );
                write("你拿起水瓢舀出井水来喝。\n");
        }
        else write("你已经喝饱了，还是别喝了。\n");

        return 1;
}