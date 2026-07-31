// /d/yixing/npc/cl_qiu.c 邱山风
// Last Modified by winder on Jul. 12 2002


#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("邱山风", ({ "qiu shanfeng", "qiu" }));
	set("party/party_name", HIC"长乐帮"NOR);
	set("party/rank", "虎猛堂香主");
	set("long", "他是一位三十多岁的彪形大汉。\n");
	set("gender", "男性");
	set("age", 32);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 25);
	set("int", 20);
	set("con", 28);
	set("dex", 25);

	set("max_qi", 700);
	set("max_jing", 400);
	set("max_neili", 600);
	set("neili", 600);
	set("jiali", 30);
	set("combat_exp", 150000);
	set("score", 7000);
set("max_qi",8300+random(1690));
  set("max_jing",8300+random(1890));
  set("max_sen",8300+random(1890));
  set("max_neili",8300);
  set("max_mana",8300+random(1890));
  set("eff_neili",8300+random(1390));
  set("neili",8300);
        set("per", 28);
        set("age", 22);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 3800000+random(2000000));
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.leitingpili" :),
                (: perform_action, "sword.kuang" :),

        }) );
        set_skill("force",300);
        set_skill("taiji-shengong",200);
        set_skill("unarmed", 180+random(180));
        set_skill("sword", 180+random(180));
        set_skill("parry", 180+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-jian", 280+random(380));
        
        map_skill("sword", "kuang-jian");
        map_skill("parry", "kuang-jian");
        map_skill("force", "taiji-shengong");
        set_temp("apply/attack", 120);
        set_temp("apply/defense",150);
        set_temp("apply/armor", 150);
        set_temp("apply/damage", 180);

	set("inquiry", ([
		"长乐帮" : "这里就是长乐帮总舵所在地。",
		"司徒横" : "我对我们帮主老人家的景仰之情，有如滔滔江水连绵不绝。",
		"虎猛堂" : "虎猛堂自从我当香主后，一日千里，哈！哈！哈！",
		"香主" : "各位香主的任命由帮主老人家说了算。",
		"贝海石" : "贝大夫在弊帮劳苦功高，颇得帮主信任。",
		"帮主" : "我家帮主司徒大爷乃威镇江南的“东霸天”也。",
	]));

	setup();
carry_object("/clone/weapon/changjian")->wield();
carry_object("/clone/misc/cloth")->wear();
}

