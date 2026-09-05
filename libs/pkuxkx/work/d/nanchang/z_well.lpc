
// edit: by zine Aug 21 2010


#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"古井"NOR);
	set("long", @LONG
这里是一口古井，很多年来，一直是这个壮寨的水源地。
LONG
	);
	set("exits", ([ 		
        "northwest" : __DIR__"z_guangchang",
        
		
    ]));
	set("no_task",1);
    set("resource/water", 1);
    set("outdoors", "nanchang");
	setup();
	
}


void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me;
        me = this_player();
        if(arg)
                return 0;
        current_water = me->query("water");
        max_water = (int)me->max_water_capacity();
        if (current_water<max_water) {
                me->add("water", 450);
                message("vision", me->name()+"对着古井一阵牛饮，水真甜呐。\n",
                        environment(me), ({me}) );
                write("你弯下腰，对着水井痛快的喝起水来。\n");
        }
        else write("你已经喝饱了。\n");

        return 1;
}
