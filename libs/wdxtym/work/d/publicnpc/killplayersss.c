// 杀人鬼

inherit NPC;

void create()
{
	set_name(HIR"阎罗王"NOR, ({ "killplayersss" }));
	set("age", 999999);
	set("gender", "无性");
	set("long", "。\n");
	set("attitude", "peaceful");

	set("con", 250);
	set("int", 250);
	set("str", 250);
	set("dex", 250);

	set("qi", 50000000);
	set("max_qi", 50000000);
	set("jing", 50000000);
	set("max_jing", 50000000);
	set("neili", 50000000);
	set("max_neili", 50000000);
	
	
	set("jiali", 1250);
    set("score", 500);
	
	
	set("combat_exp", 100000000);
	set("shen_type", -1);

	set_skill("unarmed", 3000);
	set_skill("dodge", 3000);
	set_skill("parry", 3000);
	set_skill("force", 3000);
	set_skill("xuehai-mogong", 3000);
	set_skill("bianfu-bu", 3000);
	set_skill("cuixin-zhang", 3000);
	set_skill("strike", 3000);
	set_skill("cuff", 3000);
	set_skill("claw", 3000);

	map_skill("force", "xuehai-mogong");
    map_skill("dodge", "bianfu-bu");
    map_skill("strike","cuixin-zhang");
    map_skill("parry","cuixin-zhang");

	prepare_skill("strike", "cuixin-zhang");

	set_temp("apply/attack", 20000);
	set_temp("apply/defense", 3000);
	set_temp("apply/damage", 20000);
	set_temp("apply/armor", 3000);

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
		exp = this_object()->query_skill("force",1)*query_skill("force",1)*1/35;
		killer->add("combat_exp",exp);
		killer->add("tianji1",50);
		tell_object(killer,ZJOBLONG+ZJBR+ZJBR"你杀死"+name()+"，获得"+exp+"点修为，"ZJBR+ZJBR"50天机点""\n");
	}
	
	::die();
}