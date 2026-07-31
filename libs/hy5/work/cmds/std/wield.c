// wield.c
#include <ansi.h>
inherit F_CLEAN_UP;

int do_wield(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;
	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");
    if (me->is_exert()) return notify_fail("你正在使用"+me->query_exert()+"。\n");
    if (me->is_perform()) return notify_fail("你正在使用"+me->query_perform()+"。\n");

	if( !arg ) return notify_fail("你要装备什么武器？\n");

	if(arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if((int)me->query("max_neili") < (int)inv[i]->query("wield_maxneili")) continue;
			if((int)me->query("neili") < (int)inv[i]->query("wield_neili")) continue;
			if((int)me->query_str() < (int)inv[i]->query("wield_str")) continue;
			if(do_wield(me, inv[i]) ) count ++;
		}
		write("Ok.\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if( ob->query("equipped") )
		return notify_fail("你已经装备著了。\n");

	if((int)me->query("max_neili") < (int)ob->query("wield_maxneili"))
		return notify_fail("你感觉全身气息翻腾，原来你内力不够，不能装备"+ob->name()+"。\n");
	if((int)me->query("neili") < (int)ob->query("wield_neili"))
		return notify_fail("你感觉全身气息翻腾，原来你真气不够，不能装备"+ob->name()+"。\n");
	if((int)me->query_str() < (int)ob->query("wield_str"))
		return notify_fail("你想举起"+ob->name()+"，怎奈力量不够，只好作罢。\n");

	return do_wield(me, ob);
}

int do_wield(object me, object ob)
{
	string str;

	if( ob->wield() ) {
		if( !stringp(str = ob->query("wield_msg")) )
			str = "$N装备$n作武器。\n";
		message_vision(str, me, ob);

if (!me->query_temp("item/wield") && (ob->query("makeritem")||ob->query("systemmake")))
{	
    if (ob->query("weapon_prop/neili"))
{
    	me->add("neili",ob->query("weapon_prop/neili")*500);
message_vision(HIB + ob->query("name") + HIB"射出一道柔和的蓝光，$N在神光的沐浴下感到内力异常的充沛！\n"NOR, me);
me->set_temp("item/wield",1);
}    
    if (ob->query("weapon_prop/qi"))
{
    	me->add("max_qi",ob->query("weapon_prop/qi")*300);
    	me->add("eff_qi",ob->query("weapon_prop/qi")*300);
      me->add("qi",ob->query("weapon_prop/qi")*300);
message_vision(HIR + ob->query("name") + HIR"射出一道耀眼的红光，$N在神光的沐浴下感到体力异常的充沛！\n"NOR, me);
me->set_temp("item/wield",1);
}    
    if (ob->query("weapon_prop/jing"))
{
    	me->add("max_jing",ob->query("weapon_prop/jing")*300);
    	me->add("eff_jing",ob->query("weapon_prop/jing")*300);
      me->add("jing",ob->query("weapon_prop/jing")*300);
message_vision(HIY + ob->query("name") + HIY"射出一道夺目的黄光，$N在神光的沐浴下感到精力异常的充沛！\n"NOR, me);
me->set_temp("item/wield",1);
}   
    
    if (ob->query("weapon_prop/jingli"))
{
      me->add("max_jingli",ob->query("weapon_prop/jingli")*300);
      me->add("eff_jingli",ob->query("weapon_prop/jingli")*300);
      me->add("jingli",ob->query("weapon_prop/jingli")*300);
message_vision(HIC + ob->query("name") + HIC"射出一道夺目的绿光，$N在神光的沐浴下感到精神异常的充沛！\n"NOR, me);
me->set_temp("item/wield",1);
}
}

if (userp(me) && me->query_temp("xmud")) 
{
	seteuid(getuid());
	me->force_me("xnventory");
}
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
指令格式：wield <装备名称>
 
这个指令让你装备某件物品作武器, 你必需要拥有这样物品.
 
HELP
    );
    return 1;
}
