// dengbingchun.c
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("邓炳春", ({"deng bingchun", "deng", "bingchun"}));
	set("title",HIY"神龙教"HIG"青龙使"NOR"座下弟子");
	set("nickname",HIY"假宫女"NOR);
	set("long","一个三十岁左右的的秃头汉子。\n");

	set("gender", "男性");
	set("attitude", "peaceful"); 
	set("age", 36);
	set("shen_type", -1);
	set("per", 14);
	set("str", 25+random(10));
	set("dex", 25+random(10));
	     set("max_qi", 15000);
	set("max_jing", 15000);
	set("neili",18000);
	set("max_neili", 18000);
//	set("jiali", 100);
	set("combat_exp", 5500000);
	set("score", 2400000);
        set_skill("claw", 100);
        set_skill("strike", 100);
	set_skill("dulong-shenzhua", 200);
	set_skill("xuanming-zhang", 200);
        set_skill("force", 250);
	set_skill("shenlong-xinfa", 150);
        set_skill("dodge", 250);
	set_skill("yixingbu", 200);
        set_skill("hand", 200);
	set_skill("shenlong-bashi", 280);
        set_skill("strike", 280);
	set_skill("huagu-mianzhang", 280);
        set_skill("parry", 250);
        set_skill("staff", 250);
        set_skill("sword", 250);
        set_skill("zhaosheshu", 250);
        set_skill("yangsheshu", 250);
	set_skill("shedao-qigong", 200);
	set_skill("literate", 190);

	
	map_skill("force", "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "juehu-shou");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "juehu-shou");
        map_skill("staff", "shedao-qigong");
	prepare_skill("strike", "huagu-mianzhang");
	prepare_skill("hand", "shenlong-bashi");
	prepare_skill("hand", "juehu-shou");


	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
(: perform_action, "strike.bujue" :),
(: perform_action, "strike.hua" :),
(: perform_action, "strike.lianhuan" :),
                (: perform_action, "strike.hua" :),
                (: perform_action, "hand.bada" :),
                (: perform_action, "hand.shenlongtuwu" :),
                (: perform_action, "hand.shewu" :),
                (: perform_action, "hand.flower" :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang3" :),
                (: perform_action, "staff.cui" :),
                (: perform_action, "staff.fei" :),
                (: perform_action, "staff.wanshe" :),
                (: perform_action, "staff.xian" :),
                (: perform_action, "parry.luanhuan" :),
                (: perform_action, "parry.juehu	" :),                
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                      }) );

	setup();
	//carry_object(VEGETABLE_DIR"xionghuang");
	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",5);
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 10, ob);
	}
}

void greeting(object ob)
{
	object obj;
        if (interactive(ob))
        {
	if (obj = present("usedgao", ob))          
		kill_ob(ob);
	}
	return;
}
