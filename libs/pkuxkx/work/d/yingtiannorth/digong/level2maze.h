#include <ansi.h>

int valid_leave(object me,string dir)
{
	object *inv=all_inventory(this_object());
	for (int i=0;i<sizeof(inv);i++)
	if (userp(me)&&inv[i]->query("is_KARMA_ROBBER_TOMB"))
	return notify_fail(WHT+inv[i]->name()+WHT+"在一旁虎视眈眈地看着，只怕你一动，就会出手偷袭。\n"NOR);
	return ::valid_leave(me,dir);
}