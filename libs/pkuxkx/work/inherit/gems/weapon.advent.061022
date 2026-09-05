// by Vast@pkuxkx
// all comments added by Vast

#include <ansi.h>
#include <weapon.h>

inherit F_GEMS;
inherit EQUIP;
varargs void setup_sword(object ob, int flag);
varargs void setup_blade(object ob);
varargs void setup_whip(object ob);
varargs void setup_staff(object ob);
varargs void setup_hammer(object ob);
varargs void setup_spear(object ob);
varargs void setup_axe(object ob);
varargs void setup_halberd(object ob);
varargs void setup_club(object ob);
varargs void setup_throwing(object ob);

void init_sockets()
{
	int i, max, flag;
	string type;
	object ob = this_object();

	//1，2，3孔出现的几率为888:111:1
	//生成方式太简单，以后加强
	if(!query("sockets/max"))
	{
		i = random(1000);

		if (i < 888)
		max = 1;
		else if (i < 999)
		max = 2;
		else if (query("unqiue")) //非Unique武器最多两个孔
		max = 3;
		else
		max = 2;
		set("sockets/max", max);
	}

	if( !stringp(type = ob->query("skill_type")) )
	{
		type = "sword";
		ob->set("skill_type", "sword");
	}
	switch(type)
	{
		case "sword":
			if(query("id") == "two-handed sword") flag = 1;
			setup_sword(ob, flag);
			break;
		case "blade":
			setup_blade(ob);
			break;
		case "whip":
			setup_whip(ob);
			break;
		case "staff":
			setup_staff(ob);
			break;
                case "hammer":
                        setup_hammer(ob);
                        break;
                case "spear":
                        setup_spear(ob);
                        break;
                case "axe":
                        setup_axe(ob);
                        break;
                case "halberd":
                        setup_halberd(ob);
                        break;
                case "club":
                        setup_club(ob);
                        break;
                case "throwing":
                        setup_throwing(ob);
                        break;
		default:
			error("S-weapon: undefined type " + type + ".\n");
	}

//	set_weapon_desc();
}

void setup_sword(object ob, int flag)
{
	int hole, i;
	string longdes;

	//基本信息
	if(stringp(ob->query("weapon/name")))
	set_name(ob->query("weapon/name"), ob->parse_command_id_list());

	ob->set("unit", "柄");

	//set long_desc
	if (!stringp(ob->query("weapon/long")))
	longdes = "这是一把普通的长剑。\n";
	else
	longdes = ob->query("weapon/long");

	longdes += set_weapon_desc(ob);

	set("long", longdes);

	//材料
	if (!ob->query("material")) ob->set("material", "iron");
	//硬度
	if (!ob->query("rigidity")) ob->set("rigidity", 300);
	if (!ob->query("max_rigidity")) ob->set("max_rigidity", ob->query("rigidity"));

	//wield,unwield msg
	if (!stringp(ob->query("wield_msg")))
	set("wield_msg", "$N从腰间取出一把$n，双手紧紧握住。\n");
	else
	set("wield_msg", ob->query("wield_msg"));

	if (!stringp(ob->query("unwield_msg")))
	set("unwield_msg", "$N将$n顺手别在腰带上。\n");
	else
	set("unwield_msg", ob->query("unwield_msg"));


	// init_sword
	ob->set("flag", 2 | (int)flag | EDGED);
//	ob->set("skill_type", "sword");
	if( !ob->query("actions") )
	{
                ob->set("actions", (: call_other, WEAPON_D, "query_action" :) );
		ob->set("verbs", ({ "slash", "slice", "thrust" }) );
	}
}

void setup_blade(object ob){}
void setup_whip(object ob){}
void setup_staff(object ob){}
void setup_hammer(object ob){}
void setup_spear(object ob){}
void setup_axe(object ob){}
void setup_halberd(object ob){}
void setup_club(object ob){}
void setup_throwing(object ob){}

string spec_effect(object me, object victim, int damage_bonus, string act)
{
	int damage, magic, kar;
	string msg = "";
	object weapon;

	//成功率(可能设定简单了一点)
	magic = me->query_temp("apply/magic");
	kar = me->query_kar();
	if (kar > 40) kar = 40;
	if (random(100) + kar / 5 + kar * magic / 1000 < 90) return msg;

	switch (act) {
	case "jing":
		msg = HIY"一道黄光猛的闪过，$n只觉得意识越来越模糊！\n"NOR;
		damage = query("weapon_effect/jing");
		//if (damage > 1000) damage = 1000;
		victim->receive_damage("jing", damage, me);
		victim->receive_wound("jing", damage / 4 + random(damage * 3 / 4), me);
		if (wizardp(me))
			tell_object(me, sprintf("jing damage is: %d\n", damage));
		break;
	case "poison":
		msg = HIG"只见一道绿气迅速的从伤口渗入了$n的经脉！\n"NOR;
		victim->apply_condition("emerald_poison", victim->query_condition("emerald_poison") + query("weapon_effect/poison"));
		if (!victim->is_killing(me->query("id"))) victim->kill_ob(me);
		break;
	case "suck":
		msg = WHT"忽然间，$n只觉鬼哭狼嚎声不绝于耳，三魂六魄都给吸了出去！\n"NOR;
		damage = damage_bonus * query("weapon_effect/suck") / 10;
		if (victim->query("qi") < damage)
			damage = victim->query("qi");
		if (damage > 0)
		{
			victim->receive_damage("qi", damage, me);
			me->receive_curing("qi", damage);
			if (wizardp(me))
				tell_object(me, sprintf("suck qi: %d\n", damage));
		}
		damage /= 2;
		if (victim->query("neili") < damage)
			damage = victim->query("neili");
		if (damage >  0)
		{
			victim->add("neili", - damage);
			me->add("neili", damage);
			if (me->query("neili") > me->query("max_neili") * 2)
				me->set("neili", me->query("max_neili") * 2);
			if (wizardp(me))
				tell_object(me, sprintf("suck neili: %d\n", damage));
		}
		break;
	}
	return msg;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int i;
	mapping effect;
	string act, msg = "";

	//随机出现一种效果
	//weapon_effect/jing,poison,suck
	effect = query("weapon_effect");
	if (mapp(effect))
	{
		i = sizeof(effect);
		act = keys(effect)[random(i)];
		msg += spec_effect(me, victim, damage_bonus, act);
	}
	return msg;
}
