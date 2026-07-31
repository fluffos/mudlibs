 // medicine.c
inherit ITEM;
#include <ansi.h> 
void create()
{
    set_name(WHT"雪芝"NOR,({ "xuezhi"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "一朵采自圣母雪峰的雪芝，雪白无暇，芳香扑面， 可以用（yong）来增神 。\n");
        set("unit","朵");
        set("value", 15000);
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
        diff = this_player()->query("max_jing")-this_player()->query("eff_sen");
        if(!(diff))    return notify_fail("你没有受伤！\n");
        if(value > diff) value = diff;
            
    message_vision("$N缓缓嚼下雪芝，心神感觉平和了许多。\n",this_player());
        this_player()->add("eff_sen",value);
        destruct(this_object());
        return 1;
}     
