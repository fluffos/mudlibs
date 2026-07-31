#include <ansi.h>
inherit ITEM;

void create()
{
                
        set_name(HIG"原始森林入口"NOR, ({ "forest door","door"}) );
        set_weight(5);
        set("no_get",1);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", GRN"从这个入口可以进入原始森林迷宫副本。(enter door)\n"NOR); 
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
        if (this_player()->query("combat_exp",1) > 10000000 && !wizardp(this_player()))
                return notify_fail("你已经不是新人了，还是不要进去了！\n");

        this_player()->delete_temp("maze");
        time = this_player()->query_temp("maze/time")+180-time();
        if(time>0)
                return notify_fail("你还需要等"+CHINESE_D->chinese_period(time)+"才能进入原始森林迷宫副本。\n");
//MAZE_D->query_fuben_all();
//MAZE_D->query_fuben_list();
//MAZE_D->query_fuben_data();
        
        //MAZE_D->query_maze_dir(this_player());
        //MAZE_D->enter_fuben(this_player(), "forest");
        return 1;
}

