// Made by goodtaste
//1999.6.3
#include <weapon.h>
#include <ansi.h>

inherit F_UNIQUE;
inherit BLADE;
int return_normal(object ppl,object ob);
void create()
{
	set_name(HIW"屠龍刀"NOR, ({ "tulong dao","dao" }));
	set_weight(10000);
	set("value",1000000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", HIW+"一柄乌沉沉的刀，非金非铁，不知是何物所制!\n"+NOR);
		set("value", 500000);
		set("no_drop",this_object()->query("name")+HIR"是武林至宝，多少人为它丢掉了性命，你竟然舍得把他扔掉？\n"NOR);
		set("no_give",this_object()->query("name")+HIR"是武林至宝，多少人为它丢掉了性命，你竟然舍得把他送给别人？\n"NOR);
		set("no_steal",1);
		set("unique",1);
		set("material", "steel");
		set("weapon_prop/strength", 5);
		set("weapon_prop/dexerity",-2);
		set("weapon_prop/intelligence",2);
		set("wield_msg", HIW"$N从身后拔出一柄乌沉沉的宝刀，霎时间，如雪的刀光映在$N脸上。\n$N手持宝刀，纵声狂笑：\n"HIR
			+"武林至尊....................\n"
			+"宝刀屠龙....................\n"
			+"号令天下....................\n"
			+"莫敢不从....................\n"+NOR);
		set("unwield_msg", "寒光一闪，$N已把"+query("name")+"插回鞘中。\n");
	}
	init_blade(250);
	setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object weapon;
//        me->add_temp("apply/attack",30);
//        me->add_temp("apply/dodge", 30);
	me->add_temp("apply/damage",30);
	if(!objectp(weapon=victim->query_temp("weapon")))
		message_vision(HIW"\n刀光一闪，$N眼看刀锋便要扫到自己身上，却避无可避。"NOR,victim);
	else if(weapon->query("unique"))
		message_vision(HIW"\n$N的"+this_object()->query("name")+HIW+
						"与$n手中的"+weapon->query("name")+HIW+
						"相击，竟都安然无恙。"NOR,me,victim);
	else
	{
		message_vision(HIW"\n只听“嚓”的一声，$N手中的$n已被"+
			this_object()->query("name")+HIW+"斩成两截！"NOR,victim,weapon);
		weapon->unequip();
		weapon->move(environment(victim));
		weapon->set("name", "断掉的" + weapon->query("name"));
		weapon->set("value", 0);
		weapon->set("weapon_prop", 0);
		me->reset_action();
	}
	call_out("return_normal",60,me,this_object());
	return NOR;
}

int return_normal(object ppl,object ob)
{
//        ppl->add_temp("apply/attack",-30);

//        ppl->add_temp("apply/dodge", -30);
	ppl->add_temp("apply/damage",-30);
	return 1;
}

string query_autoload()
{
	return query("name");
}

void autoload()
{}
