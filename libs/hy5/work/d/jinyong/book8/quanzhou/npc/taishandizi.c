inherit NPC;
#include <ansi.h>
void create()
{
	set_name("泰山派弟子", ({ "taishan dizi", "dizi" }) );
	set("gender", "男性");
	set("title", HIG"泰山派第十四代弟子"NOR);
	set("class", "taoist");
	set("age", 30);
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 50000);
	set("max_neili", 50000);
	set("max_qi", 50000);
	set("max_jing", 50000);
	set("combat_exp", 3000000);
	set("shen_type", 1);
	set_skill("taoism", 300);
	set_skill("strike", 300);
	set_skill("kuaihuo-strike", 300);
	set_skill("sword", 300);
	set_skill("taishan-sword", 300);
	set_skill("shiba-pan", 300);
	set_skill("force", 300);
	set_skill("panshi-shengong", 300);
	set_skill("parry", 300);
	set_skill("dodge", 300);
	set_skill("fengshenjue", 300);
	set_skill("dramaturgy", 300);
	set_skill("horticulture", 300);
	map_skill("sword", "taishan-sword");
	map_skill("parry", "taishan-sword");
	map_skill("dodge", "fengshenjue");
	map_skill("force", "panshi-shengong");
	map_skill("strike", "kuaihuo-strike");
	prepare_skill("strike", "kuaihuo-strike");
	set("no_get",1);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.heru" :),
		(: perform_action, "sword.ruhe" :),
		(: perform_action, "sword.wuyue" :),
		(: perform_action, "sword.18pan" :),
		(: perform_action, "strike.zhouyu" :),
(: perform_action, "dodge.fengshen" :), 
                (: exert_function, "shield" :),
                (: exert_function, "powerup" :),
                (: exert_function, "invocation" :),
                (: exert_function, "taijitu" :),
	}) );

	set_temp("apply/attack",180);
	set_temp("apply/defense",180);
	set_temp("apply/armor",600);
	set_temp("apply/damage",600);
	
	create_family("泰山派", 14, "掌门");
	setup();

	carry_object(__DIR__"obj/houjian")->wield();
	carry_object(__DIR__"obj/daopao")->wear();
}
