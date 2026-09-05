// wujiang.c 武将

inherit NPC;

void create()
{
        set_name("巡城武将", ({ "wu jiang", "wu", "jiang" }));
        set("gender", "男性");
        set("age", 20 + random(20));
        set("str", 25+random(20));
        set("dex", 20+random(10));
        set("long", "他站在那里，的确有说不出的威风。\n");
        set("combat_exp", 100000 + random(500000));
//        set("shen_type", 1);
        set("attitude", "peaceful");
	set("max_qi", 1000);
	set("eff_qi", 1000);
	set("qi", 1000);

	set("max_jing", 1000);
	set("eff_jing", 1000);
	set("jing", 1000);

	set("jingli", 1000);
	set("max_jingli", 1000);

	set("neili", 2000);
	set("max_neili", 2000);

	set_temp("sum_power", 1);//用于雷霆斧的绝招

	set("jiali", 50);
	set_skill("force", 60 + random(100));
	set_skill("dodge", 60 + random(100));
	set_skill("cuff", 60 + random(100));
	set_skill("strike",60 + random(100));
	set_skill("hand",60 + random(100));
	set_skill("parry", 60 + random(100));
	set_skill("blade",60 + random(100));
	set_skill("sword",60 + random(100));
	set_skill("staff",60 + random(100));
	set_skill("whip",60 + random(100));
	set_skill("axe",60 + random(100));
	set_skill("halberd",60 + random(100));
	set_skill("spear",60 + random(100));
	set_skill("claw",60 + random(100));

    	set_skill("bixue-xinfa", 60 + random(100));
    	set_skill("longfeng-xiang", 60 + random(100));
    	set_skill("qingmang-jian", 60 + random(100));
    	set_skill("juemen-gun", 60 + random(100));
    	set_skill("fenglei-dao", 60 + random(100));
    	set_skill("taizu-quan", 60 + random(100));
    	set_skill("kuangfeng-dao", 60 + random(100));
    	set_skill("kuangfeng-jian", 60 + random(100));
    	set_skill("lujia-ji", 60 + random(100));
    	set_skill("bainiao-qiangfa", 60 + random(100));
    	set_skill("huzhua-shou", 60 + random(100));
    	set_skill("juehu-zhang", 60 + random(100));
    	set_skill("kuihua-zhua", 60 + random(100));
    	set_skill("duanyun-bian", 60 + random(100));
    	set_skill("leiting-axe", 60 + random(100));

    	map_skill("force", "bixue-xinfa");
    	map_skill("sword", "qingmang-jian");
    	map_skill("blade", "fenglei-dao");
    	map_skill("dodge", "longfeng-xiang");
    	map_skill("strike", "juehu-zhang");
    	map_skill("parry", "huzhua-shou");
    	map_skill("hand", "huzhua-shou");
    	map_skill("whip", "duanyun-bian");
    	map_skill("halberd", "lujia-ji");
    	map_skill("axe", "leiting-axe");
    	map_skill("claw", "kuihua-zhua");
    	map_skill("staff", "juemen-gun");
    	map_skill("spear", "bainiao-qiangfa");
    	map_skill("cuff", "taizu-quan");

    	prepare_skill("strike", "juehu-zhang");
    	prepare_skill("hand", "huzhua-shou");

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 80);
        set_temp("apply/damage", 30+random(100));

     	set ("chat_chance", 5);
     	set ("chat_msg", ({
                      (: random_move :)
                      }) );
        set("shen_type",1);set("score",5000);setup();

        carry_object("/d/city/obj/tiejia")->wear();
        switch (random(7))
        {
        	case 0:
        	carry_object("/d/city/obj/gangjian")->wield();
        	break;
        	case 1:
        	carry_object(__DIR__"obj/axe")->wield();
        	break;
        	case 2:
        	carry_object("/clone/weapon/fangtianji")->wield();
        	break;
        	case 3:
        	carry_object("/clone/weapon/changqiang")->wield();
        	break;
        	case 4:
        	carry_object("/clone/weapon/gangdao")->wield();
        	break;
        	case 5:
        	carry_object("/clone/weapon/changbian")->wield();
        	break;
        	case 6:
        	carry_object("/clone/weapon/gangzhang")->wield();
        	break;
        }
}

void init()
{
        object player = this_player();
        ::init();
    if (interactive(player) &&
	(player->query_condition("bjkiller") && player->query("class") != "officer") )
    {
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, player);
	    command("follow " + player->query("id"));
 	return;
    }

}
int accept_fight(object player)
{
	object me=this_object();
        if(living(me))
        {
        command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
        player->apply_condition("bjkiller", 100 + player->apply_condition("bjkiller"));
        me->kill_ob(player);
	}
        return 1;
}

int accept_kill(object player)
{
	object me=this_object();
        if(living(me))
        {
        command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
        player->apply_condition("bjkiller", 100 + player->apply_condition("bjkiller"));
        me->kill_ob(player);
	}
        return 1;
}
