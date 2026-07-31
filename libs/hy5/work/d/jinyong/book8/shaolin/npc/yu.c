// yu.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("余沧海", ({ "yu canghai", "yu", "canghai" }));
	set("gender", "男性");
	set("age", 52);
	set("long", "他身形矮小，可是神情凝重，俨然一派大宗师气。\n");
	set("class", "taoist");
	set("combat_exp", 8000000);
	set("class", "taoist");
	set("shen_type", -1);
	set("max_neili", 80000);
	set("neili", 80000);
	set("max_jing", 80000);
	set("max_qi", 80000);
	set("jiali", 250);
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

	set("chat_chance_combat", 99);
	set("chat_msg_combat", ({		
    (: perform_action, "dodge.chuan" :),
    (: perform_action, "hammer.san" :),
 	  (: perform_action, "hammer.rimu" :),
 	  (: perform_action, "hammer.riluo" :),
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
	create_family("青城派", 5, "掌门");
	setup();

	carry_object("/clone/weapon/changjian")->wield();	
	carry_object("/d/wudang/obj/bluecloth")->wear();
}

void unconcious()
{
	die();
}
void die()
{
        object who = this_object()->query_temp("last_damage_from");
        if(who) {
		message_vision("$N说道：哼，这次算你走运，等五岳大会过后，我们再决高下。\n" NOR,this_object());
	}
	destruct(this_object());
}