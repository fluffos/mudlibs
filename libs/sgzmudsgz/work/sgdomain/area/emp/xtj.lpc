// by fire
/* Do not remove the headers from this file! see /USAGE for more info. */
#include <ansi.h>

inherit LIVING;
inherit M_BLOCKEXITS;

private mixed handle_blocks( string dir )
{
	if(present("ysf pass",this_body())) {
		this_object()->targetted_action(
"$N对$T一鞠躬道：$R既然有圣上的手谕，里面请。\n",this_body());
		return 0;
	}
        return ::handle_blocks(dir);    
}
void setup()
{
        set_name("xiao taijian", "小太监");
        set_gender(0);
        set_in_room_desc("小太监(xiao taijian)");
        set_age(10);
        add_block("north");
        set_block_action(
"$N一挥手里的拂尘，对$T道：里面是御书房，$R请留步。没有圣上的手谕，谁也不能进。\n");
}
string long() {
	return "一个小太监。\n";
}