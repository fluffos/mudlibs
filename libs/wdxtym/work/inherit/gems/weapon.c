#include <ansi.h>
#include <weapon.h>

inherit M_WEAPON;
inherit F_GEMS;
string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

void init_sockets(object me)
{
	set("max_sockets", 3);
	if (me->query("combat_exp") > 10000000)
		add("max_sockets", 1);

        if (me->query("combat_exp") < 10000000 && (int)query("sockets/max",1)>=3)
        set("sockets/max",3);

        if (me->query("combat_exp") < 20000000 && (int)query("sockets/max",1)>=4)
        set("sockets/max",4);

        if ((int)query("sockets/max",1)>5)
        set("sockets/max",5);

	if (me->query("diablo/weapon/id") != query("id")) return;

	set("sockets", me->query("diablo/weapon/sockets"));
	set_weapon_desc();
}

void setup()
{
	init_sockets(this_player());
	::setup();
}

void spec_prop(object me, string socket, int socket_level, int mode)
{
int i;
	if (!valid_gem(socket, socket_level)) return;
	if (me->query("diablo/weapon/id") != query("id")) return;
        if (query("weapon_prop/damage") < 20) return;
	switch (socket) {
	case "ruby":
		break;
	case "topaz":
		break;
	case "sapphire":
		break;
	case "emerald":
		break;
	case "amethyst":
		break;
	case "skull":
		break;
	}
	return;
}

int wield()
{
	int i, sockets, ret;
	object me = environment();

	if (!(ret = ::wield())) return 0;
	sockets = query("sockets/max");
	for (i = 1; i <= sockets; i++)
		spec_prop(me, query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)), 1);
	return ret;
}

int unequip()
{
	int i, sockets, ret;
	object me = environment();

	if (!(ret = ::unequip())) return 0;
	sockets = query("sockets/max");
	for (i = 1; i <= sockets; i++)
		spec_prop(me, query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)), -1);
	return ret;
}

string spec_effect(object me, object victim, int damage_bonus, string socket, int socket_level)
{
	int damage;
	string msg = "";
	object weapon;

	if (!valid_gem(socket, socket_level)) return msg;
	if (random(100) + me->query_temp("apply/magic") < 70) return msg;
	if (me->query("diablo/weapon/id") != query("id")) return msg;
	switch (socket) {
	case "ruby":
		break;
	case "topaz":
		break;
	case "sapphire":
		break;
	case "amethyst":
		break;
	case "diamond":
		break;
	case "skull":
		msg = WHT"忽然间，$n只觉鬼哭狼嚎声不绝于耳，三魂六魄都给吸了出去！\n"NOR;
                damage = me->query("xixue");
		if (damage > 0) {
			if ((int)victim->query("qi")+100 > damage)
			{
				victim->add("qi", -damage);
					me->add("eff_qi", damage);
			}
			if (me->query("eff_qi") > me->query("max_qi"))
				me->set("eff_qi", me->query("max_qi"));
		}
                damage = me->query("xinei");
		if (damage >  0) {
			if ((int)victim->query("neili")+100 > damage)
			{
				victim->add("neili", -damage);
				me->add("eff_neili", damage);
			}
			if (me->query("eff_neili") > me->query("max_neili"))
				me->set("eff_neili", me->query("max_neili"));
		}
		break;
	case "windjade":
		break;
	case "firejade":

		break;
	case "icejade":
		break;
	case "thunderjade":
		break;
	case "earthjade":
		break;
	}
	return msg;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int i, sockets;
	string msg = "";

	sockets = query("sockets/max");
	for (i = 1; i <= sockets; i++)
		msg += spec_effect(me, victim, damage_bonus,
		query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)));
	return msg;
}
