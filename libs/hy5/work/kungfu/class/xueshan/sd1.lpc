// Last Modified by Winder on May. 29 2901
// Npc: /kungfu/class/nanshaolin/tianhong.c

#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("马光佐", ({ "ma guangzuo", "ma"}));
set("title", "莽夫");
	set("gender", "男性");
	set("attitude","heroism");
	set("class", "bonze");

	set("age", 71);
	set("shen_type", 1);
	set("str", 120);
	set("int", 120);
	set("con", 120);
	set("dex", 100);
	set("max_qi", 20000);
	set("max_jing", 12900);
	set("neili", 30000);
	set("max_neili", 30000);
	set("jiali",290);
	set("combat_exp", 6000000);
	set("score", 10000);
		set_skill("zhanzhuang-gong", 280);
	set_skill("shaolin-cuff", 280);
	set_skill("shaolin-leg", 280);
	set_skill("yiwei-dujiang", 280);
	set_skill("ruying-leg", 280);
	set_skill("boluomi-hand", 280);
	set_skill("jingang-strike", 280);
	set_skill("wuxiang-finger", 280);
	set_skill("literate", 100);
	set_skill("buddhism", 100);
	set_skill("parry", 290);
	set_skill("yijinjing", 290);
	set_skill("force", 290);
	set_skill("yijinjing", 290);
	set_skill("dodge", 290);
	set_skill("shaolin-shenfa", 220);
	set_skill("cuff", 290);
	set_skill("hunyuan-yiqi", 220);
	set_skill("luohan-quan", 220);
	set_skill("jingang-quan", 220);
	set_skill("leg", 290);
	set_skill("zui-gun", 220);
	set_skill("nianhua-zhi", 220);
	set_skill("hand", 290);
	set_skill("fengyun-shou", 220);
set_skill("hunyuan-yiqi", 260);
	set_skill("qianye-shou", 220);
	set_skill("strike", 290);
	set_skill("sanhua-zhang", 220);
	set_skill("sanhua-zhang", 220);
	set_skill("weituo-gun", 220);
	set_skill("banruo-zhang", 220);
	set_skill("finger", 290);
	set_skill("yizhi-chan", 220);
	set_skill("yizhi-chan", 220);
	set_skill("nianhua-zhi", 220);
	set_skill("nianhua-zhi", 220);
	set_skill("yizhi-chan", 220);
	set_skill("claw", 290);
	set_skill("qianye-shou", 220);
	set_skill("yingzhua-gong", 220);
	set_skill("longzhua-gong", 220);
	set_skill("staff", 320);
	set_skill("pudu-zhang", 220);
	set_skill("wuchang-zhang", 220);
	set_skill("blade", 290);
	set_skill("cibei-dao", 220);
	set_skill("xiuluo-dao", 220);
	set_skill("club", 290);

	set_skill("zui-gun", 220);

	set_skill("sword", 290);
	set_skill("damo-jian", 220);

	set_skill("whip", 290);
//set_skill("hellfire-whip", 280);
//set_skill("buddha-club", 280);
set_skill("lunhui-zhang", 320);
set_skill("zhanzhuang-gong", 320);
set_skill("buddhism", 350);
	//map_skill("club", "buddha-club");
	//map_skill("whip", "hellfire-whip");
	map_skill("staff", "lunhui-zhang");
		map_skill("force", "zhanzhuang-gong");
		
	map_skill("dodge", "shaolin-shenfa");
  map_skill("parry","ruying-leg");
  map_skill("unarmed","ruying-leg");
  map_skill("leg","ruying-leg");
	prepare_skill("leg", "ruying-leg");
     
	set("no_get",1);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({		

							
		 (: perform_action, "leg.ruying" :),
		(: exert_function, "powerup" :),
						
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 560);
	set_temp("apply/armor", 560);


	setup();
		//carry_object(__DIR__"obj/gstaff")->wield();
	//carry_object(__DIR__"wtgun")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	
	who->set_temp("book1051",1);
	::die();
}  