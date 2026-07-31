// zhong.c
// modified by wind

inherit NPC;

void create()
{
        set_name("钟万仇", ({ "zhong wanchou","zhong" }) );
        set("gender", "男性" );
        set("age", 52);
        set("str", 13);
        set("con", 13);
        set("dex", 13);
        set("per", 13);
        set("int", 13);
        set("long",
        "钟万仇张着好长的一张马脸，眼睛生的甚高，\n"
        "一个圆圆的大鼻子却和嘴巴挤在一块，以致眼\n"
        "睛与鼻子之间，留下了一大块一无所有的空白\n"
        "地，丑陋异常。\n");

        set("attitude", "friendly");

        set("max_neili", 15000);
        set("neili", 15000);
        set("force_factor", 20);
        set("combat_exp", 350000);

        set_skill("unarmed", 300);
        set_skill("parry", 200);
        set_skill("dodge", 290);
        set_skill("sword", 200);
        set_skill("force", 290);
set_skill("literate", 100);
	set_skill("strike", 200);
	set_skill("hand", 200);
	set_skill("sword", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);

	set_skill("construction", 380);
	set_skill("painting", 380);


	        set_skill("songshan-sword", 380);
        set_skill("songshan-jian", 380);
        set_skill("songshan-qigong", 380);
        set_skill("dodge", 290);
        set_skill("zhongyuefeng", 380);
        set_skill("strike", 290);
        //set_skill("songyang-zhang", 380);
        set_skill("hanbing-zhenqi", 380);
        set_skill("parry", 290);
        set_skill("sword", 290);
        set_skill("songshan-jian", 380);
        //set_skill("songyang-zhang", 380);
        //set_skill("songyang-shou", 380);
        set_skill("literate", 250);
        set_skill("hanbing-shenzhang", 380);
		  set_temp("apply/armor", 200);
		  set_temp("apply/damage", 200);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	set_skill("songshan-sword", 380);
	set_skill("songyang-strike", 380);
	set_skill("poyun-hand", 380);
	set_skill("hanbing-zhenqi", 388);
	set_skill("fuguanglueying", 380);

set_skill("taoism", 388);
set_skill("club", 388);
set_skill("wuyue-spear", 388);
	set_skill("luoyan-jian", 200);
	set_skill("shiba-pan", 200);
	set_skill("songshan-jian", 200);
	set_skill("liuhe-dao", 200);
	set_skill("hengshan-jian", 200);


	map_skill("strike", "songyang-strike");
	map_skill("hand", "poyun-hand");

	map_skill("sword", "songshan-sword");
map_skill("parry", "songshan-sword");
	map_skill("dodge", "zhongyuefeng");
	map_skill("force", "hanbing-zhenqi");
	prepare_skill("strike", "songyang-strike");
	prepare_skill("hand", "poyun-hand");
set("chat_chance_combat", 99);
	set("chat_msg_combat", ({
		(: command("haha") :),

		(: perform_action, "strike.yinyang" :),
		(: perform_action, "strike.junji" :),	
		(: perform_action, "hand.chanyun" :),
    (: perform_action, "dodge.feng" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
		(: exert_function, "shield" :),	
			(: exert_function, "fenglei" :),	
	}) );
        setup();

        carry_object("/d/wanjiegu/npc/obj/cloth")->wear();
        carry_object("/d/wanjiegu/npc/obj/bu-shoes")->wear();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
        message_vision("钟万仇对$N说道：想要救木婉清？你去死吧！\n",ob);
                kill_ob(ob);
        }
}

