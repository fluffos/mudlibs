// zhouyunqi.c 周云阳

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("周云阳", ({ "zhou yunyang", "yunyang", "zhou" }) );
	set("gender", "男性");
	set("title", "辽东天龙门北宗第六代弟子");
	set("nickname", "回龙剑");
	set("age", 43);
	set("attitude", "friendly");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 8200000);
set("max_qi", 24000);
	set("max_jing", 23000);
	set("neili", 45000);
	set("max_neili", 45000);
	set("jiali", 100);
	set("eff_jingli", 22000);
	set("jingli", 22000);
	set("combat_exp", 9500000);
	set("score", 400000);
	set_skill("art", 380);
	set_skill("goplaying", 380);
	set_skill("taxue-wuhen", 380);
	set_skill("luteplaying", 380);
        set_skill("literate", 300);
	set_skill("force", 250);
	set_skill("xuantian-wuji", 380);
	set_skill("dodge", 280);
	set_skill("kunlun-shenfa", 380);
	set_skill("strike", 380);
	set_skill("kunlun-zhang", 380);
set_skill("mantian-huayu", 380);
set_skill("qixian-jian", 380);
	set_skill("chuanyun-tui", 380);
	set_skill("zhentian-quan", 380);
	set_skill("parry", 250);
	set_skill("sword", 300);
        set_skill("cuff", 250);
	set_skill("leg", 250);
set_skill("xunlei-jian", 385);
        set_skill("finger", 280);
	set_skill("hand", 250);
set_skill("qidao", 380);
set_skill("music", 380);

	set_skill("liangyi-jian", 380);
	set_skill("throwing", 380);
	set_skill("taiji-shengong", 180);
	map_skill("throwing", "mantian-huayu");
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("strike", "kunlun-zhang");
	map_skill("parry", "qixian-jian");
	map_skill("parry", "art");
	map_skill("sword", "qixian-jian");
	//prepare_skill("strike", "kunlun-zhang");
	
	map_skill("finger", "qidao");
	map_skill("hand", "music");
	prepare_skill("finger", "qidao");
	prepare_skill("hand", "music");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "hand.gong" :),
                	(: perform_action, "hand.libie" :),
                 	(: perform_action, "hand.lv" :),
                (: perform_action, "finger.xb" :),                		
                (: perform_action, "strike.diezhang" :),
                	(: perform_action, "throwing.huayu" :),
                 	(: perform_action, "strike.liuyun" :),
                (: perform_action, "strike.yixing" :),                		
                (: command("unwield qin") :),
                (: command("wield qin") :),
                (: perform_action, "sword.ni" :),
                (: perform_action, "sword.shan" :),
                (: perform_action, "sword.yin" :),
                                (: perform_action, "sword.hebi ban" :),
            		(: command("perform sword.hebi ban") :),
                (: perform_action, "sword.zhu" :),
                (: perform_action, "parry.tianwaifeiyin" :),
        }) );


		  set_temp("apply/armor", 200);
		  set_temp("apply/damage", 200);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
