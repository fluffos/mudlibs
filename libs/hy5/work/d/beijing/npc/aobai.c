// aobai.c
inherit NPC;
inherit F_UNIQUE;
#include <ansi.h>
void create()
{
	set_name("鳌拜", ({ "ao bai", "ao", "bai"}));
	set("long",
		"他就是满洲第一勇士，身穿一袭金边锦缎。他身材魁梧，\n"
		"相貌狰狞，太阳穴高高鼓起，似乎身怀绝世武功。\n"
	);

	set("nickname", "满洲第一勇士");
	set("title", HIC"少保"HIR"一等超武公"HIY"镶黄旗旗主"NOR);
	set("gender", "男性");
	set("attitude", "aggressive");

	set("age", 50);
	set("shen_type", -1);
	set("str", 65);
	set("int", 25);
	set("con", 25);
	set("dex", 65);
	set("max_qi", 55000);
	set("max_jing", 55000);
	set("neili", 55000);
	set("max_neili", 55000);
	set("jiali", 150);
	set("combat_exp", 3850000);
	set("score", 50000);


		set_skill("zhuihun-biao", 280);
		set_skill("liuxing-biao", 280);
	set_skill("pili-biao",280);
	set_skill("force", 280);
	set_skill("biyun-xinfa", 280);
	set_skill("dodge", 280);
	set_skill("qiulinshiye", 280);
	set_skill("strike", 250);
	set_skill("unarmed",280);
	set_skill("biye-wu", 280);
	set_skill("parry", 280);
	set_skill("throwing", 280);
	set_skill("zimu-zhen", 280);
	set_skill("literate", 250);
	
	set_skill("dusha-zhang", 280);
	set_skill("lansha-shou", 280);
	set_skill("hand", 280);
	set_skill("strike", 280);
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "dusha-zhang");
	map_skill("unarmed","biye-wu");
	map_skill("parry", "biye-wu");
	map_skill("throwing", "zimu-zhen");
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	prepare_skill("strike", "dusha-zhang");
	prepare_skill("hand", "lansha-shou");
	


	set("chat_chance_combat", 98);
	set("chat_msg_combat", ({

		(: perform_action, "parry.wandu" :),
		(: perform_action, "parry.meng" :),
		(: perform_action, "strike.tianxie" :),
		(: perform_action, "strike.hantian" :),
		(: perform_action, "hand.canglong" :),
		(: perform_action, "hand.xiangyi" :),
		(: perform_action, "hand.luanpo" :),									
						
	}) );

        set("chat_chance_combat", 10);  
        set("chat_msg_combat", ({
                " 鳌拜怒道：你敢不让我睡觉，老子宰了你 ！\n",
                (: command("say 老子宰了你这" + RANK_D->query_rude(this_player())+"!\n") :),
		(: command("pain") :),
                      }) );
        setup();
        carry_object("/d/beijing/obj/anmenkey")->wield();
        carry_object("/d/beijing/obj/jinduan")->wear();
        carry_object("/d/beijing/obj/yaodai")->wear();
        carry_object("/d/beijing/obj/yaoshi")->wield();
        add_money("gold",2);
}

void die()
{
		int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
who->add_temp("book732",1);
        message("vision","\n鳌拜狂叫道：想不到我一世威名竟然毁于你手！\n","/d/beijing/aobai6");        	 
        message("vision","鳌拜顿了一顿，叹道：唉，只可惜我的那么多宝贝啊！\n","/d/beijing/aobai6");        	 
        message_vision("$N哀嚎一声，死了！\n", this_object());

        ::die();
}

