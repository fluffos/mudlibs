
inherit NPC;
int ask_me();

#include <ansi.h>
void create()
{
	object ob;
	set_name("莫大", ({ "mo da", "mo" }) );
	set("nickname", "潇湘夜雨");
	set("gender", "男性");
	set("class", "swordsman");
	set("age", 55);
	set("attitude", "peaceful");
	set("per", 22);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 50000);
	set("max_neili", 50000);
	set("jiali", 60);
	set("max_qi",50000);
	set("max_jing",50000);
	set("combat_exp", 8000000);
	set("shen_type", 1);

	set_skill("hand", 400);
	set_skill("unarmed",400);
	set_skill("sword", 400);
	set_skill("force", 400);
	set_skill("parry", 400);
	set_skill("dodge", 400);
	set_skill("strike", 400);
	set_skill("hengshan-sword", 400);
	set_skill("luoyan-jian", 400); 
	set_skill("huiyan-xinfa",400);
	set_skill("luoyan-hand",400);
	set_skill("biluo-zhang",400);
	set_skill("qiuyan-nanhui",400);
	set_skill("literate",180);
	//set_skill("luteplaying",180);
	set_skill("goplaying", 380);
	set_skill("luteplaying", 380);
	set_skill("jiutian-sword", 380);
	map_skill("sword", "jiutian-sword");
	map_skill("parry", "hengshan-sword");
	map_skill("dodge", "qiuyan-nanhui");
	map_skill("force", "huiyan-xinfa");
	map_skill("hand", "luoyan-hand");
	map_skill("strike", "biluo-zhang");
	prepare_skill("hand", "luoyan-hand");
	prepare_skill("strike", "biluo-zhang");
  	set("inquiry", ([
		"比武" : (: ask_me :),
	]));	 
	set("env/wimpy", 60);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: command("haha") :),
		(: perform_action, "sword.xiangsi" :),
		(: perform_action, "sword.wuyun" :),
		(: perform_action, "sword.xiaofeng" :),
		(: perform_action, "parry.luoyan" :),
		(: perform_action, "parry.yunwu" :),
		(: perform_action, "dodge.nanhui" :),
		(: perform_action, "hand.jinghan" :),
		(: perform_action, "strike.huan" :),
		(: exert_function, "shield" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );
	create_family("衡山派", 13, "掌门");
	set_temp("apply/armor", 500);
	set_temp("apply/damage", 500);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	setup();

	carry_object(__DIR__"obj/qinjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}


int ask_me()
{
	object me = this_player();
	message_vision("$N说道：勇气可嘉，今日我们点到为止！\n",this_object());
	me->set_temp("jinyong/book8/wuyue_hengshan",1);
	return 1;
}

void unconcious()
{
	die();
}
void die()
{
	message_vision("$N说道：果然长江后浪推前浪，衡山派从此不再参与五岳剑派之争。\n" NOR,this_object());
	destruct(this_object());
}