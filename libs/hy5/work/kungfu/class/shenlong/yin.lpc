// yin.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_join(string arg);

void create()
{
	set_name("殷锦", ({ "yin jin", "yin"}));
	set("title", HIY"神龙教"YEL"黄龙使"NOR);
	set("long", "这是个汉子, 一脸奸相, 明显是个小人.\n" );
	set("gender", "男性");
	set("age", 44);
	set("str", 35);
	set("dex", 20);
	set("max_qi",3000);
        set("qi",3000);
	set("max_jing",1000);
        set("jing",1000);
	set("combat_exp", 500000);
	set("score", 20000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("force", 80);
	set_skill("dodge", 90);
	set_skill("strike", 90);
	set_skill("claw", 90);
	set_skill("parry", 80);
	set_skill("staff", 80);
	set_skill("literate", 50);
	set_skill("huagong-dafa", 80);
	set_skill("zhaixinggong", 85);
	set_skill("chousui-zhang", 100);
	set_skill("sanyin-wugongzhao", 100);
	set_skill("shenlong-xinfa", 80);
	set_skill("shedao-qigong", 80);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("strike", "chousui-zhang");
	map_skill("parry", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	prepare_skill("strike", "chousui-zhang");

	create_family("神龙教",2,"弟子");

	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 100);
        set("inquiry", ([
		"神龙教" :  "一般人是入不了我神龙教的(join shenlongjiao).\n",
		"入教" :  "一般人是入不了我神龙教的(join shenlongjiao).\n",
		"洪安通" :  "教主脾气不好,要讨他欢心才好。\n",
		"教主" :  "教主脾气不好,要讨他欢心才好。\n",
		"口号" : "万年不老!永享仙福!寿与天齐!文武仁圣!\n",
       ]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 10);
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {

		remove_call_out("greeting");
		call_out("greeting", 50, ob);
	}
	add_action("do_join","join");
}

void greeting(object ob)
{
	object obj;
       if (ob)
{
        if (interactive(ob))
        {
	if (obj = present("usedgao", ob))          
	   set("combat_exp",100000);
	   set("qi",100);
	   set("jing",100);
	}
}
	return;
}

void attempt_apprentice(object ob)
{
	command("say 我不收徒, 你自便吧! ");
	return;
}
#include "/kungfu/class/shenlong/shenlong.h"; 
