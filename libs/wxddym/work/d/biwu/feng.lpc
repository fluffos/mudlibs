// feng.c 风清扬

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("风清扬", ({ "feng qingyang", "feng", "qingyang" }));
	set("title", "华山第十二代剑宗长老");
	set("long", 
"这便是当年名震江湖的华山名宿风清扬。他身著青袍，神气抑郁脸如金纸。
身材瘦长，眉宇间一直笼罩着一股淡淡的忧伤神色，显然对当年的剑宗气宗
之争一直难以忘怀。\n");
	set("gender", "男性");
	set("age", 68);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("qi", 19800);
	set("max_qi", 19800);
	set("jing", 8600);
	set("max_jing", 8600);
	set("neili", 24400);
	set("max_neili", 24400);
	set("jiali", 200);

	set("combat_exp", 3050000);
	set("score", 200000);

	set_skill("cuff", 200);
	set_skill("force", 180);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 320);
	set_skill("strike", 200);
	set_skill("zixia-shengong", 380);
	set_skill("poyu-quan", 380);
	set_skill("fanliangyi-dao", 380);
	set_skill("huashan-sword", 380);
	set_skill("hunyuan-zhang", 380);
	set_skill("lonely-sword", 380);
	set_skill("feiyan-huixiang",380);
	set_skill("literate", 200);
        set_skill("zhengqijue",300);
        
	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");

	create_family("华山派", 12, "弟子");

	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.jiushi" :),
		(: perform_action, "sword.pozhao" :),
		(: perform_action, "sword.poqi" :),
		(: perform_action, "sword.pozhang" :),
		(: perform_action, "sword.pojian" :),
		(: perform_action, "sword.podao" :),
		(: perform_action, "sword.zongjue" :),
	}) );

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
	int student_num;
	string temp;
	string line;

	if ((int)ob->query("betrayer") )
	{
		command("say 依我看" + RANK_D->query_respect(ob) + "好象拜过别派的师傅？想来你也不适合学独孤九剑？");
		return;
	}
	if ((int)ob->query("mud_age") - (int)ob->query("feng_dietime") < 259200 )
	{
		command("say " + RANK_D->query_respect(ob) + "你好象原来是我的徒弟麽？");
		return;
	}

	temp = read_file("/data/FENG", 1, 1);
	student_num = atoi(temp);

	line = "风清扬说道：“我现在共有" + temp + "个徒弟。”\n";
	write(line);

//	if ( student_num == 10)
//	{
//		command("say 你来晚了，我已经收了十个徒弟了。");
//		return;
//	}

	if ((string)ob->query("family/family_name") != "华山派")
	{
		command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜老朽呢？");
		return;
	}

	if (((int)ob->query_skill("sword",1) < 80) || ((int)ob->query_skill("huashan-sword",1) < 80))
	{
		command("say 我看" + RANK_D->query_respect(ob) + "的华山剑法还没学到家吧。");
		return;
	}
	if (((int)ob->query_skill("force",1) < 80) || ((int)ob->query_skill("zixia-shengong",1) < 80))
	{
		command("say 我看" + RANK_D->query_respect(ob) + "的紫霞神功还没学到家吧。");
		return;
	}
	if (((int)ob->query_skill("dodge",1) < 80) || ((int)ob->query_skill("feiyan-huixiang",1) < 80))
	{
		command("say 我看" + RANK_D->query_respect(ob) + "的飞燕回翔还没学到家吧。");
		return;
	}
	if ( (int)ob->query_skill("literate",1) < 100)
	{
		command("say 我看" + RANK_D->query_respect(ob) + "的读书识字还没学到家吧。");
		return;
	}

	if ((int)ob->query("shen") < 50000)
	{
		command("say 我华山派乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}

	if ((int)ob->query_int() < 20)
	{
		command("say 依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合学我独孤九剑？");
		return;
	}

	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "swordsman")
		ob->set("class", "swordsman");

	student_num++;
//	temp = itoa(student_num);
	if(student_num == 1)
		temp = "1";
	else if(student_num == 2)
		temp = "2";
	else if(student_num == 3)
		temp = "3";
	else if(student_num == 4)
		temp = "4";
	else if(student_num == 5)
		temp = "5";
	else if(student_num == 6)
		temp = "6";
	else if(student_num == 7)
		temp = "7";
	else if(student_num == 8)
		temp = "8";
	else if(student_num == 9)
		temp = "9";
	else if(student_num == 10)
		temp = "10";
	write_file("/data/FENG", temp, 1);
}
