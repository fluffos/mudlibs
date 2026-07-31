#include "include/fb_main.h"

int main(object who)
{
	object fb_mem, temp;
	object *team;
	
	if (!enquire_fuben(who, fb_mem))
		return 1;
		
	fb_mem = new(__DIR__"fb_mem");
	fb_mem->set("team", who->query_team());
	create_room(fb_mem, this_object());
	link_room(fb_mem);
	create_npc(who, fb_mem);
	fb_mem->set("npc_amount", NPC_AMOUNT);
	fb_mem->set("fuben_end", time() + END_TIME);
	fb_mem->heart(1);
	team = who->query_team();
	foreach(temp in team)
		temp->set("fuben_jiaofei/last_time", time());
		
	
	return 1;
}