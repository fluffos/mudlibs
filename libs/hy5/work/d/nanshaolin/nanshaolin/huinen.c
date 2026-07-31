// Last Modified by Winder on May. 29 2901
// Npc: /kungfu/class/nanshaolin/tianhong.c

#include "tian2.h";
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
//inherit F_MANAGER;
string ask_me();

void create()
{
	set_name("慧能大师", ({ "huinen dashi", "huinen", "dashi"}));
	set("long",
		"他就是镇静四方的六祖慧能，身穿一袭金丝绣红袈裟。\n"
		"他身材略显佝偻，但却满面红光，目蕴慈笑，显得神完气足。\n");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 71);
	set("shen_type", 1);
	set("str", 120);
	set("int", 120);
	set("con", 120);
	set("dex", 100);
	set("max_qi", 30000);
	set("max_jing", 12900);
	set("neili", 30000);
	set("max_neili", 30000);
	set("jiali",290);
	set("combat_exp", 9000000);
	set("score", 10000);
		set_skill("zhanzhuang-gong", 360);
	set_skill("shaolin-cuff", 360);
	set_skill("shaolin-leg", 360);
	set_skill("yiwei-dujiang", 360);
	set_skill("ruying-leg", 360);
	set_skill("boluomi-hand", 360);
	set_skill("jingang-strike", 360);
	set_skill("wuxiang-finger", 360);
	set_skill("literate", 100);
set_skill("hunyuan-yiqi", 320);
	set_skill("parry", 290);
	set_skill("force", 290);
	set_skill("yijinjing", 290);
	set_skill("dodge", 290);
	set_skill("shaolin-shenfa", 300);
	set_skill("cuff", 290);
	set_skill("hunyuan-yiqi", 300);
	set_skill("luohan-quan", 300);
	set_skill("jingang-quan", 300);
	set_skill("leg", 290);
	set_skill("zui-gun", 300);
	set_skill("nianhua-zhi", 300);
	set_skill("hand", 290);
	set_skill("fengyun-shou", 300);
	set_skill("qianye-shou", 300);
	set_skill("strike", 290);
	set_skill("sanhua-zhang", 300);
	set_skill("weituo-gun", 300);
	set_skill("banruo-zhang", 300);
	set_skill("finger", 290);
	set_skill("yizhi-chan", 300);
	set_skill("nianhua-zhi", 300);
	set_skill("yizhi-chan", 300);
	set_skill("claw", 290);
	set_skill("qianye-shou", 300);
	set_skill("yingzhua-gong", 300);
	set_skill("longzhua-gong", 300);
	set_skill("staff", 290);
	set_skill("pudu-zhang", 300);
	set_skill("wuchang-zhang", 300);
	set_skill("blade", 290);
	set_skill("cibei-dao", 300);
	set_skill("xiuluo-dao", 300);
	set_skill("zui-gun", 300);
	set_skill("sword", 290);
	set_skill("damo-jian", 300);
	set_skill("whip", 290);
set_skill("club",280);
set_skill("unarmed",280);
set_skill("hellfire-whip", 360);
set_skill("buddha-club", 360);
set_skill("lunhui-zhang", 360);
set_skill("zhanzhuang-gong", 360);
set_skill("buddhism", 500);
	//map_skill("club", "buddha-club");
	map_skill("whip", "hellfire-whip");
	//map_skill("staff", "lunhui-zhang");
		
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
(: perform_action, "whip.ldlh" :),
(: perform_action, "whip.lunhui" :),
	(: perform_action, "whip.three" :),
(: perform_action, "whip.yanluo" :),
	(: perform_action, "whip.zhdp" :),			
		(: exert_function, "powerup" :),
		(: exert_function, "lianhua" :),	
		(: exert_function, "bighammer" :),	
		(: exert_function, "tianlei" :),	
		(: exert_function, "pudu" :),										
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 500);
	set_temp("apply/armor", 500);

	create_family("南少林派", 17, "祖师");
	setup();
	carry_object(__DIR__"obj/gwhip")->wield();
	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}


void init()
{
	object ob;

	::init();

	add_action("do_nod", "nod");
        add_action("do_qiecuo","qiecuo");
}