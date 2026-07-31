// xuanmingzi.c 玄冥子

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("玄冥子", ({ "xuanming zi", "xuanming", "zi" }) );
	set("gender", "男性");
	set("title", "青藏派");
	set("class", "taoist");
	set("age", 43);
	set("attitude", "friendly");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
set("max_neili", 52500);
	set("neili", 52500);
	set("max_jing", 51500);
	set("max_qi", 52500);
	set("jiali", 250);
	set("apprentice_available", 3);
  set_skill("taoism",380);
  set_skill("hammer",380);
  set_skill("frht-hammer",380);
	set_skill("sword", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("strike", 250);
	set_skill("unarmed", 250);
	set_skill("force", 250);
	set_skill("hammer", 250);
	set_skill("throwing", 350);
	set_skill("literate", 100);
//	set_skill("qingzi9da", 150);
	set_skill("qingzi9da", 380);
	set_skill("liuhe-dao", 380);
//	set_skill("chengzi18po", 150);
	set_skill("chengzi18po", 380);
	set_skill("pixie-sword", 250);
	set_skill("songfeng-jian", 380);
	set_skill("chuanhua", 380);
	set_skill("wuying-leg", 380);
	set_skill("cuixin-strike", 380);
	set_skill("qingming-xuangong", 380);
	map_skill("force", "qingming-xuangong");
	map_skill("unarmed", "wuying-leg");
	map_skill("strike", "cuixin-strike");
	map_skill("dodge", "chuanhua");
	


	map_skill("sword", "songfeng-jian");
	map_skill("parry", "songfeng-jian");
			
	
	prepare_skill("unarmed", "wuying-leg");
	prepare_skill("strike", "cuixin-strike");

	set("no_get",1);
	set("chat_chance_combat", 99);
	set("chat_msg_combat", ({		
    (: perform_action, "dodge.chuan" :),
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.dieying" :),
		(: perform_action, "strike.cuixin" :),
		(: perform_action, "unarmed.fanti" :),
		(: exert_function, "powerup" :),
		(: exert_function, "shield" :),
		(: exert_function, "dingshen" :),
    (: exert_function, "fenshen" :),
	}) );
		  set_temp("apply/armor", 200);
		  set_temp("apply/damage", 200);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);


	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
