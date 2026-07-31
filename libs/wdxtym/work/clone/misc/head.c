// head.c 脑袋

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;
inherit F_CUTABLE;
inherit F_SILENTDEST;

void eat_effect();
int is_head() { return 1; }

void create()
{
	set_name(RED "头颅" NOR, ({ "head" }));
	set_weight(1500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("value", 1);
		set("no_sell", "我的天...这...这你也拿来卖...官...官府呢？");
		//set("food_supply", 10);
		//set("food_remaining", 4);
		set("long", RED "一颗鲜血淋淋的首级，须发散乱，余血正缓缓渗出。"NOR"\n");
	}
	 if( clonep(this_object()) ) call_out("decay", 180, 1);
}

int set_from(object owner)
{
	apply_effect((: eat_effect :));
	set("owner_id",  owner->query("owner_id"));
	set("is_player", owner->query("is_player"));
	set("killed_by", owner->query("killed_by"));
	set("defeated_by", owner->query("defeated_by"));
	set("defeated_by_who", owner->query("defeated_by_who"));
	set("assist", owner->query("assist"));
	set("gender", owner->query("gender"));
	if (! stringp(owner->query("victim_name")))
	{
		set("name", "腐烂的人头");
		owner->set("name", "腐烂的无头尸体");
	} else
	{
		set("name", owner->query("victim_name") + "的人头");
		owner->set("name", "无头尸体");
	}

	if (owner->query_temp("clawed_by_jiuyin"))
	{
		set_temp("clawed_by_jiuyin", 1);
		set("long", query("long") +
			    "上面赫然有五个小洞，伸手一探，刚好可以插入。\n");
	}

	set_name(RED + query("name") + NOR, ({ "head" }));
	return 1;
}

int do_cut(object me, string part)
{
	if (! query("food_remaining"))
		return 0;

	return ::do_cut(me, part);
}

int finish_eat()
{
	set_name(WHT "骷髅头" NOR, ({ "bone" }) );
	set_weight(150);
	set("long", "一个白森森的骷髅头。\n");
	return 1;
}

void eat_effect()
{
	object me;

	me = this_player();
	me->add("combat/eatman", 1);
	if (me->query("shen") > -1000)
		me->set("shen", -1000);
}
void decay(int phase)
{
	string msg;
	object env;

       env = environment();
	//如果处于玩家身上，不发生变化
	if(env && env->is_character())
	{
		call_out("decay", 180, phase);
		return;
	}
	switch (phase)
	{
	case 1:
	      set("owner_id", "unknow");
		msg =  name(1) + "开始腐烂了，发出一股难闻的恶臭。\n";
	      delete("victim_name");
	      delete("owner_id");
		set_name(RED "腐烂的人头" NOR, ({ "head", "头颅" }));
		set("long",	"这颗人头显然已经割下来有一段时间了，正散发著一股腐尸的味道。\n");
		call_out("decay", 20, phase + 1);
		break;
	case 2:
	      delete("parts");
		msg = name(1) + "被风吹乾了，变成一个骷髅头。\n";
		set_name(HIW "骷髅头" NOR, ({ "bone" }) );
		set("long", "一个白森森的骷髅头。\n");
		call_out("decay", 10, phase + 1);
		break;
	case 3:
		msg = "一阵风吹过，把" + name(1) + "化成骨灰吹散了。\n";
		if( env )
			all_inventory(this_object())->move(env);
	      tell_room(env, msg);
		destruct(this_object());
		return;
	}

	while (env && env->is_character())
		env = environment(env);

	if (env) tell_room(env, msg);
}