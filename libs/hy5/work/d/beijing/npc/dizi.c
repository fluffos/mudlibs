// dizi.c
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("弟子", ({"dizi"}));
	set("title", HIY"神龙教"NOR);
	set("long", "这是一个神龙教弟子，混身透着一股邪气。\n");

	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 20+random(30));
	set("shen_type", -1);
	set("str", 25+random(10));
	set("dex", 25+random(10));
set("max_qi", 8000);
	set("max_jing", 8000);
	set("neili", 8000);
	set("max_neili", 8000);
//	set("jiali", 100);
	set("combat_exp", 1500000);
	set("score", 2400000);
        set_skill("claw", 100);
        set_skill("strike", 100);
	set_skill("dulong-shenzhua", 200);
	set_skill("xuanming-zhang", 200);
        set_skill("force", 150);
	set_skill("shenlong-xinfa", 150);
        set_skill("dodge", 150);
	set_skill("yixingbu", 200);
        set_skill("hand", 200);
	set_skill("shenlong-bashi", 200);
        set_skill("strike", 200);
	set_skill("huagu-mianzhang", 200);
        set_skill("parry", 150);
        set_skill("staff", 150);
        set_skill("sword", 150);
        set_skill("zhaosheshu", 150);
        set_skill("yangsheshu", 150);
	set_skill("shedao-qigong", 200);
	set_skill("literate", 190);

	
	map_skill("force", "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "juehu-shou");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "juehu-shou");
        map_skill("staff", "shedao-qigong");
	prepare_skill("strike", "huagu-mianzhang");
	prepare_skill("hand", "shenlong-bashi");
	prepare_skill("hand", "juehu-shou");


	set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({
		(: command("smile") :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang3" :),
                (: perform_action, "parry.luanhuan" :),
                (: perform_action, "parry.luanhuan" :),
                (: perform_action, "parry.juehu" :),
                (: perform_action, "parry.juehu" :),                
                (: perform_action, "parry.juehu	" :),                
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                      }) );
	setup();
		set("chat_chance", 3);
        set("chat_msg", ({
"神龙教弟子忽然高声叫道:教主宝训,时刻在心,建功克敌,无事不成!\n",
"神龙教弟子忽然齐声叫道:众志齐心可成城,威震天下无比伦!\n",
"神龙教弟子忽然齐声叫道:神龙飞天齐仰望,教主声威盖八方!\n",
"神龙教弟子忽然齐声叫道:乘风破浪逞英豪,教主如同日月光!\n",
"神龙教弟子齐声叫道:教主永享仙福,寿与天齐!\n",
        }) );

	setup();
	carry_object(__DIR__"obj/xionghuang");
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 10, ob);
	}
}

void greeting(object ob)
{
	object obj;
        if (interactive(ob))
        {
	if (obj = present("usedgao", ob))          
		unconcious();
	}
	return;
}

void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	who->add_temp("book722",1);
	::die();
}