#include <ansi.h>
#include "/clone/npc/bodyguard_config.h"
object bodyguard_present(object me)//保镖是否在场
{
	object *inv;
	if (!me||!environment(me)) return 0;
	if (!me->query("MyGuard")) return 0;
	inv=all_inventory(environment(me));
	inv=filter_array(inv, (: $1->query($2) :), "VIP_BODYGUARD");
	if (sizeof(inv)<1) return 0;
	for (int i=0;i<sizeof(inv);i++)
	if (inv[i]->query("owner")==me&&living(inv[i])) return inv[i];
	return 0;
}
void modify_combat_exp(object ob,int exp)
{
	object pl;
	ob->add("combat_exp",exp);
	if (ob->query("owner")&&objectp(pl=ob->query("owner")))
	tell_object(pl,HBWHT+HIG+ob->query("name")+HBWHT+HIG+"获得了"+chinese_number(exp)+"点实战经验。\n"+NOR);
}