// 杀人鬼

inherit NPC;

void create()
{
	set_name(HIY"幽冥鬼帝"NOR, ({ "killplayerss" }));
	set("age", 999999);
	set("gender", "无性");
	set("long", "。\n");
	set("attitude", "peaceful");

	set("con", 200);
	set("int", 200);
	set("str", 200);
	set("dex", 200);

	set("qi", 20000000);
	set("max_qi", 20000000);
	set("jing", 20000000);
	set("max_jing", 20000000);
	set("neili", 20000000);
	set("max_neili", 20000000);
	
	
	set("jiali", 2500);
    set("score", 500);
	
	
	set("combat_exp", 200000000);
	set("shen_type", -1);

	set_skill("unarmed", 2500);
	set_skill("dodge", 2500);
	set_skill("parry", 2500);
	set_skill("force", 2500);
	set_skill("xuehai-mogong", 2500);
	set_skill("bianfu-bu", 2500);
	set_skill("cuixin-zhang", 2500);
	set_skill("strike", 2500);
	set_skill("cuff", 2500);
	set_skill("claw", 2500);

	map_skill("force", "xuehai-mogong");
    map_skill("dodge", "bianfu-bu");
    map_skill("strike","cuixin-zhang");
    map_skill("parry","cuixin-zhang");

	prepare_skill("strike", "cuixin-zhang");

	set_temp("apply/attack", 17500);
	set_temp("apply/defense", 2500);
	set_temp("apply/damage", 17500);
	set_temp("apply/armor", 2500);

	set("chat_chance_combat", 120);
    set("chat_msg_combat", ({
                (: command("perform strike.cuixin") :),
                (: command("exert force.jixue") :),
                (: command("exert force.powerup") :),
        }) );

	
	setup();
	
	
	if (clonep()) 
	{
		set("chat_chance", 50);
		set("chat_msg", ({
			(:NPC_D->random_move(this_object()):),
        }) );
		
		keep_heart_beat();
	}
	
}

void init()
{
        object me,ob;
        ::init();
        if ( interactive(me = this_player()) && living(this_object()) )
        {
	if (!(ob = present("killpalyerling", this_player())))          
               {
	       remove_call_out("kill_ob");
               call_out("kill_ob", 1, me);
		}
        }
}

void die()
{
	object killer,ob;
	int exp;

	if (objectp(killer = query_last_damage_from()))
	{
		exp = this_object()->query_skill("force",1)*query_skill("force",1)*1/50;
		killer->add("combat_exp",exp);
		killer->add("yuanbao",3500);
		tell_object(killer,ZJOBLONG+ZJBR+ZJBR"你杀死"+name()+"，获得"+exp+"点修为，"ZJBR+ZJBR"3500灵石""\n");
	}
	
	::die();
}