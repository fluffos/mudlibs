// Last Modified by Winder on May. 29 2901
// Npc: /kungfu/class/nanshaolin/tianhong.c

#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("何太冲", ({ "he taichong", "he"}));
set("title", "昆仑派");
	set("gender", "男性");
	set("attitude","heroism");
	set("class", "bonze");

	set("age", 71);
	set("shen_type", 1);
	set("str", 120);
	set("int", 120);
	set("con", 120);
	set("dex", 100);
	set("max_qi", 10000);
	set("max_jing", 12900);
	set("neili", 20000);
	set("max_neili", 20000);
	set("jiali",290);
	set("combat_exp", 3000000);
	set("score", 10000);
	set_skill("taiji-shengong", 220);
	set_skill("art", 280);
	set_skill("literate", 200);
	set_skill("force", 200);
	set_skill("xuantian-wuji", 220);
	set_skill("dodge", 240);
	set_skill("taxue-wuhen", 220);
	set_skill("strike", 220);
	set_skill("kunlun-zhang", 220);
	set_skill("parry", 265);
	set_skill("sword", 275);
	set_skill("liangyi-jian", 225);
	set_skill("xunlei-jian", 225);
	set_skill("mantian-huayu", 225);
	set_skill("throwing", 220);
	set_skill("cuff", 225);
	set_skill("zhentian-quan", 220);
set_skill("qixian-jian", 220);
	set_skill("goplaying", 280);
	set_skill("luteplaying", 280);

        set_skill("finger", 180);
	set_skill("hand", 180);	
	map_skill("throwing", "mantian-huayu");
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("cuff", "zhentian-quan");
	map_skill("parry", "liangyi-jian");
	map_skill("sword", "liangyi-jian");

	prepare_skill("leg", "chuanyun-tui");
	prepare_skill("strike", "kunlun-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                                (: perform_action, "sword.hebi ban" :),
            		(: command("perform sword.hebi ban") :),
                                (: perform_action, "sword.hebi ban" :),
            		(: command("perform sword.hebi ban") :),            			
                (: perform_action, "strike.diezhang" :),
                	(: perform_action, "throwing.huayu" :),
                 	(: perform_action, "strike.liuyun" :),
(: perform_action, "strike.yixing" :),  
                (: command("unwield qin") :),
                (: command("wield qin") :),
                (: perform_action, "sword.jianqin" :),
                (: perform_action, "sword.ren" :),
                (: perform_action, "sword.feixue" :),
                (: perform_action, "sword.juedi" :),
                (: perform_action, "parry.tianwaifeiyin" :),
        }) );
	//set_temp("apply/attack", 100);
	//set_temp("apply/defense", 100);
	set_temp("apply/damage", 560);
	set_temp("apply/armor", 560);


	setup();
		//carry_object(__DIR__"obj/gstaff")->wield();
	//carry_object(__DIR__"wtgun")->wield();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	
	who->set_temp("book1224",1);
	call_out("leavet",1);
}
void leavet()
{
        object ob = this_object();
 message_vision("$N飞身向外逃去！\n" NOR,this_object());
        destruct(this_object());
}  