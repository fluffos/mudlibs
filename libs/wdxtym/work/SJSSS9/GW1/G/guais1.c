// 杀人鬼

inherit NPC;

void create()
{
	set_name(HIR"域外天魔"NOR, ({ "tmsa9" }));
	set("nickname", "渡劫境");
	set("age", 999999);
	set("gender", "无性");
	set("long", "。\n");
	set("attitude", "peaceful");

	set("con", 888);
	set("int", 888);
	set("str", 888);
	set("dex", 444);

	set("qi", 90000000);
	set("max_qi", 90000000);
	set("jing", 90000000);
	set("max_jing", 90000000);
	set("neili", 1000000);
	set("max_neili", 1000000);
	set("jiali", 9000);
	set("combat_exp", 90000000);
	set("score", 9000);

    set_skill("force", 35000+random(2500));
    set_skill("unarmed", 35000+random(2500));
    set_skill("dodge", 7500+random(2500));
    set_skill("parry", 7500+random(2500));
    set_skill("sword", 35000+random(2500));
    set_skill("hand", 35000+random(2500));
    set_skill("cuff", 35000+random(2500));
    set_skill("strike", 35000+random(2500));
    set_skill("finger", 35000+random(2500));
    set_skill("claw", 35000+random(2500));
    set_skill("blade", 35000+random(2500));
    set_skill("staff", 35000+random(2500));
    set_skill("hammer", 35000+random(2500));
    set_skill("club", 35000+random(2500));
    set_skill("whip", 35000+random(2500));
    
    set_skill("xiuxian-gongfa", 35000+random(2500));
    set_skill("xiuxian-gongfa", 35000+random(2500));
    set_skill("xiuxian-gongfa", 35000+random(2500));
    set_skill("xiuxian-gongfa", 35000+random(2500));
    set_skill("xiuxian-gongfa", 35000+random(2500));
    set_skill("xiuxian-gongfa", 35000+random(2500));
    set_skill("xiuxian-gongfa", 35000+random(2500));
		
	map_skill("force", "xiuxian-gongfa");
    map_skill("sword", "xiuxian-gongfa");
    map_skill("parry", "xiuxian-gongfa");
    map_skill("unarmed", "xiuxian-gongfa");
    map_skill("dodge", "xiuxian-gongfa");
	map_skill("hand", "xiuxian-gongfa");
    map_skill("cuff", "xiuxian-gongfa");
    map_skill("strike", "xiuxian-gongfa");
    map_skill("finger", "xiuxian-gongfa");
    map_skill("claw", "xiuxian-gongfa");
	map_skill("blade", "xiuxian-gongfa");
    map_skill("staff", "xiuxian-gongfa");
    map_skill("hammer", "xiuxian-gongfa");
    map_skill("club", "xiuxian-gongfa");
    map_skill("whip", "xiuxian-gongfa");

    set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "force.xiuxianb1" :),
		(: perform_action, "force.xiuxianb2" :),
		(: perform_action, "force.xiuxianb3" :),
		(: perform_action, "force.xiuxianb4" :),
		(: perform_action, "force.xiuxianb5" :),
		(: exert_function, "force.xiuxiana1" :),
	}));
	set_temp("apply/attack", 200000);
	set_temp("apply/defense", 30000);
	set_temp("apply/unarmed_damage", 200000);
	set_temp("apply/armor", 30000);

	set("chat_chance_combat", 120);
    set("chat_msg_combat", ({
                (: command("strike.cuixin") :),
                (: command("force.jixue") :),
                (: command("force.powerup") :),
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
		exp = this_object()->query_skill("force",1)*query_skill("force",1)*1/25;
		killer->add("combat_exp",exp);
		killer->add("yuanbao",900);
		tell_object(killer,ZJOBLONG+ZJBR+ZJBR"你杀死"+name()+"，获得"+exp+"点修为，"ZJBR+ZJBR"900灵石""\n");
	}
	
	::die();
}