// hufa1.c
//Made by goodtaste
//1999.7.20
inherit NPC;
#include <ansi.h>

void create()
{
	set_name(HIY"金刀护法"NOR, ({ "hu fa", "hu" }) );
	set("gender", "男性" );
	set("age", 50);
	set("long",
		"杀手帮金刀护法，当年曾经是丐帮高手，后来追随楚云飞创立杀手帮。\n");
	set("combat_exp", 400000);
	set("attitude", "friendly");
        set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("qi", 900);
	set("max_qi", 900);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 1300);
	set("max_neili", 1200);
	set("jiali", 100);
	
	set("combat_exp", 220000);
	
	
	set_skill("force", 90);				// 基本内功
	set_skill("huntian-qigong", 90);	// 混天气功
	set_skill("unarmed", 85);			// 基本拳脚
	set_skill("xianglong-zhang", 80);	// 降龙十八掌
	set_skill("dodge", 105);			// 基本躲闪
	set_skill("xiaoyaoyou", 95);		// 逍遥游
	set_skill("parry", 90);				// 基本招架
	set_skill("staff", 90);				// 基本棍杖
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("parry", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
        set("chat_msg_combat", ({
		(: perform_action, "unarmed.xianglong" :),
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