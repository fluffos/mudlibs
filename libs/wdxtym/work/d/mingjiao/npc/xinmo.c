#include <ansi.h>;
inherit NPC;

void create()
{
	string *fams;

	set_name("心魔", ({"xinmo npc",}));
	set("gender", "男性");
	set("age", 25);
	set("attitude", "peaceful");

	setup();
}

void init()
{
	mapping hp_status, skill_status, map_status, prepare_status;
	mapping my;
	string *sname, *mname, *pname;
	int i, temp;
	int max_jing, max_qi, max_neili;
	int scale;
	object ob = this_player();

	my = query_entire_dbase();

	if (undefinedp(my["scale"]))
		my["scale"] = 100;

/* delete and copy skills */

	if (mapp(skill_status = ob->query_skills()))
	{
		skill_status = ob->query_skills();
		sname  = keys(skill_status);

		for (i = 0; i < sizeof(skill_status); i++)
		{
			int sk;

			sk = skill_status[sname[i]];
			set_skill(sname[i], sk);
		}
	}
	
/* delete and copy skill maps */

	if (mapp(map_status = ob->query_skill_map()))
	{
		mname  = keys(map_status);

		for (i = 0; i < sizeof(map_status); i++)
			map_skill(mname[i], map_status[mname[i]]);
	}

/* delete and copy skill prepares */

	if (mapp(prepare_status = ob->query_skill_prepare()))
	{
		pname  = keys(prepare_status);

		for (i = 0; i < sizeof(prepare_status); i++)
			prepare_skill(pname[i], prepare_status[pname[i]]);
	}

	hp_status = ob->query_entire_dbase();

	scale = my["scale"];

	my["str"] = hp_status["str"];
	my["int"] = hp_status["int"];
	my["con"] = hp_status["con"];
	my["dex"] = hp_status["dex"];

	max_jing = hp_status["max_jing"];
	if (max_jing > 7500) max_jing = 7500;
	max_qi = hp_status["max_qi"];
	if (max_qi > 1500) max_qi = 1500;
	max_neili = hp_status["max_neili"];
	if (max_neili > 1500) max_neili = 1500;

	my["max_qi"]     = max_qi    * scale / 100;
	my["eff_qi"]     = max_qi    * scale / 100;
	my["qi"]	 = max_qi    * scale / 100;
	my["max_jing"]   = max_jing  * scale / 100;
	my["eff_jing"]   = max_jing  * scale / 100;
	my["jing"]       = max_jing  * scale / 100;
	my["max_neili"]  = max_neili * scale / 100;
	my["neili"]      = max_neili * scale / 100;
	my["jiali"]      = 0;
	my["combat_exp"] = hp_status["combat_exp"];

	reset_action();
}

void die()
{
	int m,sllv,i,pot,exp,lvl;
	object weap,bo,me = this_object();
	object *inv,ob,obj;
	string *items,str;
	mapping give;

	sllv = environment()->query("sllv");

	give =  ([
		"/clone/vip/book_tianfu" : 15+sllv/3,
		"/clone/vip/dan_chongmai1" : 15+sllv/3,
	]);

	if (objectp(ob = query_last_damage_from())&&environment(me)==environment(ob))
	{
		items = keys(give);
		for(i=0;i<sizeof(items);i++)
		{
			if(random(100)<give[items[i]])
			{
				obj = new(items[i]);
				obj->move(environment(this_object()));
			}
		}

		exp = ob->improve_experience(random(50) + sllv*5);
		pot = ob->improve_potential(random(100) + sllv*6);

		tell_object(ob, sprintf(HIG "你击败"+query("name")+"，获得了%s点潜能、%s点实战体会。"NOR"\n",
				chinese_number(pot),chinese_number(exp)));

		ob->add("qianchi", 1);
		if(!ob->query("qianchilv")||ob->query("qianchilv")<ob->query("qianchi"))
			ob->set("qianchilv",ob->query("qianchi"));

		lvl = to_int(pow(to_float(ob->query("combat_exp")*10),0.333333333))/10;
		if((ob->query("qianchi")-lvl)>70)
			ob->force_me("slover1");
		else
			environment()->nextlv(3);
		destruct(me);
	}
	else
	{
		inv = all_inventory(environment());
		for(i=0;i<sizeof(inv);i++)
		{
			if(playerp(inv[i]))
				inv[i]->move("/d/fuben/qianchipu/qianchipu");
		}
		destruct(environment());
	}
}
