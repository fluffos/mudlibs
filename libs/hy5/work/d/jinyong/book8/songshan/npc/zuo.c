// zuo.c

inherit NPC;
#include <ansi.h>
int ask_me();

void create()
{
	set_name("左冷禅", ({ "zuo lengchan", "zuo" }) );
	set("title", HIR"五岳剑派盟主"HIY"嵩山派第十三掌门"NOR);
	set("gender", "男性");
	set("class", "swordsman");
	set("age", 55);
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 120000);
	set("max_neili", 120000);
	set("jiali", 230);
	set("max_qi",120000);
	set("max_jing",120000);
	set("combat_exp", 8000000);
	set("shen", -200000);

	set_skill("literate", 100);
	set_skill("strike", 400);
	set_skill("hand", 400);
	set_skill("sword", 400);
	set_skill("force", 400);
	set_skill("parry", 400);
	set_skill("dodge", 400);

	set_skill("construction", 380);
	set_skill("painting", 380);


	set_skill("songshan-sword", 400);
        set_skill("songshan-jian", 400);
        set_skill("songshan-qigong", 400);
        set_skill("dodge", 400);
        set_skill("zhongyuefeng", 400);
        set_skill("strike", 400);
        //set_skill("songyang-zhang", 380);
        set_skill("hanbing-zhenqi", 400);
        set_skill("parry", 400);
        set_skill("sword", 400);
        set_skill("songshan-jian", 400);

        set_skill("literate", 250);
	set_skill("hanbing-shenzhang", 400);
	set_temp("apply/armor", 200);
	set_temp("apply/damage", 200);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	set_skill("songshan-sword", 400);
	set_skill("songyang-strike", 400);
	set_skill("poyun-hand", 400);
	set_skill("hanbing-zhenqi", 400);
	set_skill("fuguanglueying", 400);
	
	set_skill("taoism", 388);
	set_skill("club", 400);
	set_skill("wuyue-spear", 400);
	set_skill("luoyan-jian", 400);
	set_skill("shiba-pan", 400);
	set_skill("songshan-jian", 400);
	set_skill("liuhe-dao", 400);
	set_skill("hengshan-jian", 400);

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
		(: perform_action, "club.buhui" :),
		(: perform_action, "club.fengchan" :),
		(: perform_action, "club.qianghun" :),		
		(: perform_action, "sword.feiwu" :),
		(: perform_action, "sword.jianqi" :),
		(: perform_action, "sword.suiyuan" :),
		(: perform_action, "strike.yinyang" :),
		(: perform_action, "strike.junji" :),	
		(: perform_action, "hand.chanyun" :),
		(: perform_action, "dodge.feng" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
		(: exert_function, "shield" :),	
			(: exert_function, "fenglei" :),	
	}) );
	set("inquiry",([
		"比武"	     : (: ask_me :),
	]));

	create_family("嵩山派", 13, "掌门");
	setup();

	carry_object(__DIR__"obj/kuojian")->wield();
	carry_object(__DIR__"obj/yellow-cloth")->wear();
}

int ask_me()
{
	object me = this_player();
	message_vision("$N说道：无名小辈也敢来挑战五岳剑派，好，就让你见识见识嵩山剑法！\n",this_object());
	me->set_temp("jinyong/book8/wuyue_songshan",1);
	return 1;
}