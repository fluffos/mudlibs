// zhangmen.h


int fully_recover (object me)
{
        object *inv;
        object ob;
        string player_name;
        object current_player;

        reset_eval_cost();

        me->set("eff_gin", me->query("max_gin"));
        me->set("gin",     me->query("max_gin"));
        me->set("eff_kee", me->query("max_kee"));
        me->set("kee",     me->query("max_kee"));
        me->set("eff_sen", me->query("max_sen"));
        me->set("sen",     me->query("max_sen"));
        me->set("force",   me->query("max_force")*2);
        me->set("mana",    me->query("max_mana")*2);

        player_name = me->query("current_player");
        if (! player_name || player_name == "none of us")
                return 1;

	// Modiby by mudring May/01/2004
	current_player = UPDATE_D->global_find_player(player_name);
	if (current_player) 
	{
		if (current_player->query("combat_exp") > me->query("combat_exp"))
            save_record (me, current_player);
	}
	UPDATE_D->global_destruct_player(current_player);

        inv = all_inventory(me);
        while (inv && sizeof(inv))
        {
                destruct (inv[0]);
                inv = all_inventory(me);
        }

        if (me->query("weapon"))
        {
                ob = new(me->query("weapon"));
                if (ob->query_unique())
                {
                     destruct(ob);
                 }
                 else  if (ob->move(me))
                 {
                     ob->wield();
                     ob->set("no_sell", "这件物品不能买卖！\n");
                  }
        }

        if (me->query("armor"))
        {
                ob = new(me->query("armor"));
                if (ob->query_unique())
                {
                     destruct(ob);
                 }
                 else  if (ob->move(me))
                 {
                        ob->wear();
                        ob->set("no_sell", "这件物品不能买卖\n");
                  }
        }

        reset_eval_cost();
        return 1;
}


void reset_me (object me)
{
	int i;
	object *inv;
	mapping skill_status, map_status;
	string *skillnames, *mapnames;
    
	reset_eval_cost();
	if ( mapp(map_status = me->query_skill_map()) )
	{
		mapnames = keys(map_status);
		for(i=0; i<sizeof(mapnames); i++)
		{
			me->map_skill(mapnames[i]);
		}
	}

	if ( mapp(skill_status = me->query_skills()) )
	{
		skillnames = keys(skill_status);
		for(i=0; i<sizeof(skillnames); i++)  
		{
			me->delete_skill(skillnames[i]);
		}
	}

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
	{
		destruct (inv[i]);
	}

	me->set_name("大师姐", ({ "zhang men", "zhangmen" }) );
	me->set("gender", "女性" );
	//me->set("title",me->query("family/family_name")+zname(me));
	me->set("title", zname(me)); //for moon only, others use above.
	me->set("short",me->query("name")+"("+capitalize(me->query("id"))+")");
	me->set("attitude", "heroism");
	me->set("current_player","none of us");

	me->set("str", 30);
	me->set("per", 30);
	me->set("int", 30);
	me->set("age", 30);

	me->set("weapon", 0);
	me->set("armor", 0);

	me->set_skill("force",  60); 
	me->set_skill("spells", 60); 
	me->set_skill("unarmed",60);
	me->set_skill("sword",  60);
	me->set_skill("dodge",  60);
	me->set_skill("parry",  60);

	me->set("max_gin", 600);
	me->set("eff_gin", 600);
	me->set("gin", 600);
	me->set("max_kee", 600);
	me->set("eff_kee", 600);
	me->set("kee", 600);
	me->set("max_sen", 600);
	me->set("eff_sen", 600);
	me->set("sen", 600);
	me->set("force", 600);
	me->set("max_force", 600);
	me->set("mana", 600);
	me->set("max_mana", 600);
	me->set("force_factor", 600);
	me->set("combat_exp", 100000);
	me->set("daoxing", 100000);

	me->setup();
	reset_eval_cost();

}

