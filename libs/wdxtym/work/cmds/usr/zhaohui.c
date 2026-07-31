// summon. 取回兵器

#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object weapon;
	object gold;
	object *inv;
	int i;
    me = this_player();
	inv = all_inventory(me);
	if((!me->query("weapon/make")) ){
		say("你还没有自制武器，召回什么？\n");
		return 1;
	}
	for(i=0; i<sizeof(inv); i++) {
        if((int)(inv[i]->query("weapon_prop")&&inv[i]->query("ownmake")))
		{
			tell_object(me,sprintf(GRN"你身上不是有武器吗？\n"NOR));
	return 1;
		}


        if(me->is_busy())
		{
			tell_object(me,sprintf(GRN"你上一个动作还没有完成。\n"NOR));
	return 1;
		}


	if (me->query("weapon/type")) {
		switch((string)me->query("weapon/type"))
		{
			case "剑":
			weapon = new("/d/npc/m_weapon/weapon/m_sword");
			weapon->move(me);
        me->start_busy(5);
		{
			tell_object(me,sprintf(GRN"武器召唤成功!。\n"NOR));
	return 1;
		}
			case "刀":
			weapon = new("/d/npc/m_weapon/weapon/m_blade");
			weapon->move(me);
        me->start_busy(5);
		{
			tell_object(me,sprintf(GRN"武器召唤成功!。\n"NOR));
	return 1;
		}			case "鞭":
			weapon = new("/d/npc/m_weapon/weapon/m_whip");
			weapon->move(me);
        me->start_busy(5);
		{
			tell_object(me,sprintf(GRN"武器召唤成功!。\n"NOR));
	return 1;
		}			case "杖":
			weapon = new("/d/npc/m_weapon/weapon/m_staff");
			weapon->move(me);
        me->start_busy(5);
		{
			tell_object(me,sprintf(GRN"武器召唤成功!。\n"NOR));
	return 1;
		}			case "棍":
			weapon = new("/d/npc/m_weapon/weapon/m_club");
			weapon->move(me);
        me->start_busy(5);
		{
			tell_object(me,sprintf(GRN"武器召唤成功!。\n"NOR));
	return 1;
		}		}
          }
else 
			{
			tell_object(me,sprintf(GRN"武器召唤成功!。\n"NOR));
	return 1;
		}
}

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : summon <物品的ID>

此指令可让你把某些物品呼唤过来并装备上，当然你得有一定的
精力施展仙术才行。
HELP );
	return 1;
}
