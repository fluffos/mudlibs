// precurosor.h

int do_clone(object me, object ob)
{
	object *inv, new1;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i;
	mapping my;

	my = query_entire_dbase();

	seteuid( geteuid(me) );

	FAMILY_D->set_family_master(ob->query("family/family_name"),ob);

	my["winner"] = ob->query("id");

/* delete and copy skills */

	delete_all_skills();

	if ( mapp(skill_status = ob->query_skills()) )
	{
		skill_status = ob->query_skills();
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++)
		{
			set_skill(sname[i], skill_status[sname[i]]);
		}
	}

	if ( mapp(map_status = ob->query_skill_map()) )
	{
		mname  = keys(map_status);
		for(i=0; i<sizeof(map_status); i++)
		{
			map_skill(mname[i], map_status[mname[i]]);
		}
	}

/* delete and copy skill prepares */

	if ( mapp(prepare_status = ob->query_skill_prepare()) )
	{
		pname  = keys(prepare_status);
		for(i=0; i<sizeof(prepare_status); i++)
		{
			prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}

/* unwield and remove weapon & armor */

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
	{
		if(inv[i]->query("equipped"))
			inv[i]->unequip();
		destruct(inv[i]);
	}

/* wield and wear weapon & armor */


/* copy entire dbase values */

	hp_status = ob->query_entire_dbase();

	my["str"] = hp_status["str"];
	my["int"] = hp_status["int"];
	my["con"] = hp_status["con"];
	my["dex"] = hp_status["dex"];
	my["spi"] = hp_status["spi"];
	my["cor"] = hp_status["cor"];
	my["cou"] = hp_status["cou"];
	my["per"] = hp_status["per"];
	my["kar"] = hp_status["kar"];

	my["age"] = 	hp_status["age"];
	my["long"] = 	hp_status["long"];
	my["gender"] = 	hp_status["gender"];
	my["level"] = 	hp_status["level"];
	my["attributive"] = hp_status["attributive"];

	my["max_qi"] = 	hp_status["max_qi"];
	my["eff_qi"] = 	hp_status["eff_qi"];
	my["qi"] = 	hp_status["qi"];
	my["max_jing"] = hp_status["max_jing"];
	my["eff_jing"] = hp_status["eff_jing"];
	my["jing"] = 	hp_status["jing"];
	my["max_neili"] = hp_status["max_neili"];
	my["neili"] = 	hp_status["neili"];
	my["jiali"] = 	hp_status["jiali"];

	this_object()->clear_condition();
	if(save())
		tell_object(ob, "状态储存完毕。\n");

	restore();
	return 1;
}
