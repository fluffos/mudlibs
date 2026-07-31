// /d/dzd/obj/bishou.c

#include <ansi.h>
#include <weapon.h>

inherit DAGGER;
//inherit F_UNIQUE;

void create()
{
	set_name("匕首",({"bishou","dagger"}));
	set_weight(20000);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit","柄");
		set("material","steel");
		set("value",100000);
		//set("unique",1);
		//set("treasure",1);
		set("long","匕首连柄不过一尺二寸，套在鲨鱼皮的套子之中，份量竟和寻常的长刀长剑无异。\n");
		set("wield_msg",BLU"$N左手握住剑柄，拔了出来，只觉一股寒气扑面而至,剑身如墨，却半点光泽也没有。\n"NOR);
		set("unwield_msg",BLU"$N将匕首插回剑鞘，系在衣带之上。\n"NOR);
             set("dzd",1);

	}
	init_dagger(180);
	setup();
}