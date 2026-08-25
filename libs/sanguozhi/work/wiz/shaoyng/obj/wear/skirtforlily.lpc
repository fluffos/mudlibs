//by fire on Jan 10 1997 
//skirtforlily.c
#include <sanguo.h>
#include <mudlib.h>
#include <bodyslots.h>
#include <ansi.h>
inherit M_WEARABLE;
inherit M_GETTABLE;
inherit M_DAMAGE_SINK;
void setup()
{
::mudlib_setup();
set_unit("条");
set_id("skirt", "一条"+HIR+"彩虹"+HIG+"长裙"+NOR);
set_in_room_desc("一条"+HIR+"彩虹"+HIG+"长裙"+NOR);
set_gettable(1);
set_slot(LEGS);
set_removemsg("$N脱下$o，"+HIR+"彩色的光芒"+NOR+"顿时消失了。\n");
}
void do_wear()
{
    object who;
    who=owner(this_object());
    foreach (object ob2 in all_inventory(who)) 
    {
        
        if ((ob2->ob_state()==LEGS))
        {
                write("你已经穿戴了同类装备了。\n");
                return;
        }
    }   
    if(who->query_userid()=="lily")
    {
	    set_is_on(1);
	    who->simple_action("$N穿上$o，整个屋里都映出一片 "+HIR+"彩色的光芒。"+NOR+"\n", this_object());
    }
    else
    {
	who->simple_action("$N穿上$o，一下把它撑破了，露出了屁股。\n",this_object());
    }
}
