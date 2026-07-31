// /d/yixing/npc/cl_bangzhong.c 帮众
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("帮众", ({ "changle bangzhong", "bangzhong" }));
	set("party/party_name", HIC"长乐帮"NOR);
	set("party/rank", "虎猛堂");
	set("long", "这是一个惯于为非作歹的长乐帮众。\n他眼珠乱转，似乎正在想什么坏主意。\n");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 23);
	set("int", 20);
	set("con", 20);
	set("dex", 23);

 set("max_qi",1300+random(1690));
  set("max_jing",1300+random(1890));
  set("max_sen",1300+random(1890));
  set("max_neili",2300);
  set("max_mana",1300+random(1890));
  set("eff_neili",1300+random(1390));
  set("neili",2300);
        set("per", 28);
        set("age", 22);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 400000+random(2000000));
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.leitingpili" :),
                (: perform_action, "sword.kuang" :),

        }) );
        set_skill("force",200);
        set_skill("taiji-shengong",200);
        set_skill("unarmed", 80+random(180));
        set_skill("sword", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-jian", 180+random(380));
        
        map_skill("sword", "kuang-jian");
        map_skill("parry", "kuang-jian");
        map_skill("force", "taiji-shengong");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 80);

	set("inquiry", ([
		"长乐帮" : "这里就是长乐帮总舵所在地。",
		"司徒横" : "我对我们帮主老人家的景仰之情，有如滔滔江水连绵不绝。",
		"虎猛堂" : "虎猛堂自从邱香主上任后，一日千里！",
		"邱香主" : "他在外面接待客人。",
		"邱山风" : "他在外面接待客人。",
		"香主" : "各位香主的任命由帮主老人家说了算。",
		"贝海石" : "贝大夫在弊帮劳苦功高，颇得帮主信任。",
		"帮主" : "我家帮主司徒大爷乃威镇江南的“东霸天”也。",
	]));

	setup();

 	carry_object("/clone/weapon/changjian")->wield();
}
