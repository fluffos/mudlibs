#include <ansi.h>
inherit ITEM;

void create()
{
    		
        set_name(RED"墓园入口"NOR, ({ "necropolis door","door"}) );
        set_weight(5);
        set("no_get",1);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", GRN"从这个入口可以进入诡异墓园迷宫副本。(enter door)\n"NOR); 
                set("unit", "个");
                set("lore",1);
                set("value", 20);
        }
        setup();
}
void init()
{
	add_action("do_enter","enter");
}


int do_enter(string arg) {
	int time;
	if (arg!="door")
		return 0;
        time = this_player()->query_temp("maze/time")+180-time();
	if(time>0)
                return notify_fail("你还需要等"+CHINESE_D->chinese_period(time)+"才能进入墓园副本。\n");
	//MAZE_D->enter_maze(this_player(), "necropolis");
	return 1;
}
