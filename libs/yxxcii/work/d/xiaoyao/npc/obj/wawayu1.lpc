
// wawayu1.c  网中的娃娃鱼

#include <armor.h>

inherit CLOTH;

void create()
{
	object me;
	string new_name,new_id;
	me=this_player();
	new_id = me->query("id")+"_wawayu";
	set_name("网中的娃娃鱼", ({new_id}));
	set_weight(10000);
	new_name = me->query("name")+"捕捉的娃娃鱼";
		set("long","这条娃娃鱼是"+new_name+"。\n");
		
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "只");
	}
	setup();
}

