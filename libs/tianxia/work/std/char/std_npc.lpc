// std_npc.c
// by Find.

inherit NPC;

protected nosave int npc_level, auto_full_me;

int query_npc_level()
{
	return npc_level;
}

void
set_auto_full_me(int n)
{
	if(intp(n) && (n > 0))
		auto_full_me = 1;
	else
		auto_full_me = 0;
}

varargs int set_npc_level(int lvl, int weapon)
{
	int kee_l,force_l,factor_l,attr_l,skill_l,gskill_l;

	if(!intp(lvl) || (lvl < 1))
		return 0;

	switch (lvl)
	{
		case 1:
			kee_l = 200;
			attr_l = 20;
			skill_l = 50;
			set("combat_exp",20000);
			break;
		case 2:
			kee_l = 400;
			attr_l = 20;
			skill_l = 90;
			set("combat_exp",40000);
			break;
		case 3:
			kee_l = 500;
			attr_l = 25;
			skill_l = 90;
			force_l = 2000;
			factor_l = 5;
			set("combat_exp",80000);
			break;
		case 4:
			kee_l = 600;
			attr_l = 25;
			skill_l = 110;
			force_l = 2000;
			factor_l = 10;
			set("combat_exp",150000);
			break;
		case 5:
			kee_l = 800;
			attr_l = 25;
			skill_l = 120;
			gskill_l = 40;
			force_l = 4000;
			factor_l = 10;
			weapon = 1;
			set("combat_exp",250000);
			break;
		case 6:
			kee_l = 1200;
			attr_l = 28;
			skill_l = 150;
			gskill_l = 55;
			force_l = 5000;
			factor_l = 15;
			weapon = 1;
			set("combat_exp",450000);
			break;
		case 7:
			kee_l = 1500;
			attr_l = 45;
			skill_l = 150;
			gskill_l = 70;
			force_l = 6000;
			factor_l = 30;
			weapon = 1;
			set("combat_exp",700000);
			break;
		case 8:
			kee_l = 1700;
			attr_l = 55;
			skill_l = 150;
			gskill_l = 90;
			force_l = 7000;
			factor_l = 45;
			weapon = 1;
			set("combat_exp",1000000);
			break;
                case 9:
                        kee_l = 2000;
                        attr_l = 75;
                        skill_l = 200;
                        gskill_l = 120;
                        force_l = 8000;
                        factor_l = 60;
                        weapon = 1;
                        set("combat_exp",1400000);
                        break;
                case 10:
                        kee_l = 2500;
                        attr_l = 100;
                        skill_l = 250;
                        gskill_l = 180;
                        force_l = 8000;
                        factor_l = 80;
                        weapon = 1;
                        set("combat_exp",2000000);
                        break;
		default:
			return 0;
	}

	set("max_kee", kee_l);
	set("max_gin", kee_l);
	set("max_sen", kee_l);

	if(force_l)
	{
		set("max_atman", force_l);
		set("atman", force_l);
		set("max_mana", force_l);
		set("mana", force_l);
		set("max_force", force_l);
		set("force", force_l);
		set("force_factor", factor_l);
	}
	set("con", attr_l);
	set("kar", attr_l);
	set("cor", attr_l);
	set("str", attr_l);

	if(lvl >= 5)
		weapon = 1;

	set_skill("dodge", skill_l);
	set_skill("parry", skill_l);
	set_skill("force", skill_l);
	set_skill("unarmed", skill_l);

	if(weapon)
	{
		if( !query_max_encumbrance() )
			set_max_encumbrance( attr_l * 3000 );

		switch (random(3))
		{
			case 0:	// blade
				set_skill("blade",skill_l);
				if(gskill_l)
				{
					set_skill("lianhuan-blade",gskill_l);
					map_skill("blade","lianhuan-blade");
					map_skill("parry","lianhuan-blade");
				}
				carry_object(WEAPON_DIR"blade")->wield();
				break;
			case 1:	// sword
				set_skill("sword",skill_l);
				if(gskill_l)
				{
					set_skill("lianhuan-sword",gskill_l);
					map_skill("sword","lianhuan-sword");
					map_skill("parry","lianhuan-sword");
				}
				carry_object(WEAPON_DIR"sword")->wield();
				break;
			case 2:	// hammer
				set_skill("hammer",skill_l);
				if(gskill_l)
				{
					set_skill("lianhuan-chui",gskill_l);
					map_skill("hammer","lianhuan-chui");
					map_skill("parry","lianhuan-chui");
				}
				carry_object(WEAPON_DIR"hammer")->wield();
				break;
		}
	}

	return 1;
}

void full_me()
{
	mapping my = query_entire_dbase();

	my["eff_kee"] = my["max_kee"];
	my["kee"] = my["max_kee"];
	my["eff_gin"] = my["max_gin"];
	my["gin"] = my["max_gin"];
	my["eff_sen"] = my["max_sen"];
	my["sen"] = my["max_sen"];

	if(!undefinedp(my["max_force"]))
		my["force"] = my["max_force"];
	if(!undefinedp(my["max_atman"]))
		my["atman"] = my["max_atman"];
	if(!undefinedp(my["max_mana"]))
		my["mana"] = my["max_mana"];
}

int remove_enemy(object ob)
{
	int n;

	n = ::remove_enemy(ob);

	if(!auto_full_me)
		return n;

	if(!is_fighting())
		call_out("full_me",2);
	return n;
}
