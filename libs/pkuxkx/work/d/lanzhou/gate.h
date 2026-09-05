// Zine 兰州城

#include <ansi.h>
string look_notice()
{
	return "暂时没有通告。\n";
}
void init()
{
	object *inv,npc;
	inv=all_inventory(this_object());
	inv=filter_array(inv, (: $1->query($2) :), "XIXIA_GATE_BING");
	while (sizeof(inv)<4)
	{
		npc=new(__DIR__"npc/bing2");
		npc->move(this_object());
		inv=all_inventory(this_object());
		inv=filter_array(inv, (: $1->query($2) :), "XIXIA_GATE_BING");
	}
}