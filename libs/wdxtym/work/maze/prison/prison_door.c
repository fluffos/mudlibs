#include <ansi.h>
inherit ITEM;

void create()
{

        set_name(RED"天牢入口"NOR, ({ "prison door","door"}) );
        set_weight(5);
        set("no_get",1);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", GRN"从这个入口可以进入地下天牢迷宫副本。(enter door)\n"NOR);
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
        time = this_player()->query_temp("maze/time")+30-time();
        //if(time>0)
         //       return notify_fail("你还需要等"+CHINESE_D->chinese_period(time)+"才能进入天牢副本。\n");
        //FUBEN_D->enter_virtual_maze(this_player(), "prison");
        return 1;
}
