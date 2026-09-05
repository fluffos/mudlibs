// hufa1.c
//Made by goodtaste
//1999.7.20
inherit NPC;
#include <ansi.h>
void create()
{
	set_name(HIW"银刀护法"NOR, ({ "hu fa", "hu" }) );
	set("gender", "男性" );
	set("age", 45);
	set("long",
		"杀手帮银刀护法，当年曾经是少林高手，后来追随楚云飞创立杀手帮。\n");
	set("combat_exp", 400000);
	set("attitude", "friendly");
        set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 3500);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);
	
	set("score", 800000);

// Before the modification, all the skills are 110
	set_skill("force", 180);
	set_skill("hunyuan-yiqi", 180);
	set_skill("dodge", 140);
	set_skill("shaolin-shenfa", 110);
	set_skill("finger", 180);
	set_skill("strike", 180);
	set_skill("hand", 110);
	set_skill("claw", 110);
	set_skill("parry", 110);
	set_skill("nianhua-zhi", 180);
	set_skill("sanhua-zhang", 180);
	set_skill("fengyun-shou", 110);
	set_skill("longzhua-gong", 110);
	set_skill("buddhism", 200);
	set_skill("literate", 110);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "fengyun-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "nianhua-zhi");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");
        set("chat_msg_combat", ({
		(: perform_action, "finger.fuxue" :),
		(: exert_function, "recover" :),
	}) );

	setup();
}

void init ()
{
  object me,ob;
  me=this_player();
  ob=this_object();
  if((!present("ling",me)||!me->query_temp("aping"))&&me->userp())
  {
    message("vision",""+ob->name()+"怒喝：你吃了熊心豹子胆了，竟敢创入我杀手帮禁地！\n",me);
    ob->kill_ob(me);
  }
}