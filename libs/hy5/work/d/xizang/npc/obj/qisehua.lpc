 // medicine.c
inherit ITEM;
#include <ansi.h> 
void create()
{
    set_name(RED"七色雨虹花"NOR,({"qisehua"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "一棵七彩的雨虹花，藏人传说这种花只有在雨果虹现时才能绽放，而那时的雨虹花\n才是最具功效的，可以用（yong）来补精 。\n");
        set("unit","棵");
        set("value", 18000);
        }
} 
void init()
{
  if(this_player()==environment())
        add_action("apply_medicine","yong");
} 
int apply_medicine()
{
    int value = 250;
        int diff; 
        if(this_player()->is_fighting())
            return notify_fail("战斗中不能用药！！\n");
        diff = this_player()->query("max_jing")-this_player()->query("eff_gin");
        if(!(diff))    return notify_fail("你没有受伤！\n");
        if(value > diff) value = diff;
            
    message_vision("$N缓缓嚼下一棵七色雨虹花，精力逐渐有所恢复。。\n",this_player());
        this_player()->add("eff_gin",value);
        destruct(this_object());
        return 1;
}        
