
#define XKD_D "/d/foshan/xkdd.c"

inherit NPC;

void init()
{
	object ob = this_player();
	mapping map;
	if(userp(ob))
	{
		map = ob->query_temp("armor");
		if( !mapp(map) || !map["head"] ||  !map["head"]->query("no_animal"))
		{
			remove_call_out("kill_ob");
       			call_out("kill_ob", 1, ob);
       		}
       	}
}

void setup()
{
	int exp,lvl;
	
	exp = XKD_D->query_exp();
	set("combat_exp",exp);
	set("jiali",200);
	if(exp>1000000){
		set("max_qi",exp/1000);
		set("eff_qi",exp/1000);
		set("qi",exp/1000);
		set("max_jing",exp/1000);
		set("eff_jing",exp/1000);
		set("jing",exp/1000);
		set("max_neili",exp*2/1000);
		set("neili",exp*4/1000);
		set("max_jingli",exp/1000);
		set("eff_jingli",exp/1000);
		set("jingli",exp/1000);
	}
        for (lvl = to_int(pow(10.0 * exp, 0.3333333));to_int(lvl*lvl/10.0*lvl)<=exp;lvl++);
        lvl = lvl*5;
        lvl = lvl/4;
        set_temp("apply/attack",lvl);
	set_temp("apply/damage",lvl);
	set_temp("apply/armor",lvl);
	set_temp("apply/defense",lvl);
	::setup();
}
