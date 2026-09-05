// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit ITEM;
void down_price()
{
	set("value",0);
}
void create()
{
        set_name("抗毒素", ({ "kangdu su","su" }) );
		set("long","这是一瓶抗毒素，喝下去可以临时抗毒。\n");
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
				set("value",1000);
                set("unit", "瓶");
             
        }
		set("no_sell",1);
		set("no_pawn",1);
		set("no_store",1);
		set("no_sell_in_playershop",1);
        setup();
		call_out("down_price",1);
}

void init()
{
	add_action("do_drink","drink");
}

int do_drink()
{
	object me=this_player();
	me->set_temp("apply/PoisonProof/Effect/2",50);
	me->set_temp("apply/PoisonProof/Effect/3",50);
	message_vision("$N喝下一瓶$n.\n",me,this_object());
	return 1;
}
