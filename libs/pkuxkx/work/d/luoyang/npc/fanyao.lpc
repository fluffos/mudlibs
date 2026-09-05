// fanyao.c -- 苦头陀-范遥
//Zone: 万安寺
//Create by ddid
//2009-6-18

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("范遥", ({ "fan yao", "fanyao", "fan", "yao" }));
	set("long", 
						"他是一个长发披肩的头陀，身材魁伟，满面横七竖八的都是刀疤，本来相貌已全不可辨。\n");

	set("gender", "男性");
	set("age", 43);

	set("nickname", YEL "苦头陀" NOR);
	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("shen_type", -1);
  set("shen", 10000);
	set("attitude", "peaceful");	

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 13);

	set("combat_exp", 6000000);
			set_skill("unarmed", 300);
			set_skill("force", 300);
			set_skill("parry", 300);
			set_skill("dodge", 300);
			set_skill("sword", 300);
			set_skill("blade", 300);
			set_temp("apply/attack", 200);
			set_temp("apply/defense", 200);
			set_temp("apply/armor", 200);
			set_temp("apply/damage", 200);

			set("neili", 6000); 
			set("max_neili", 6000);
			set("jiali", 300);

	setup();
	
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object(__DIR__"obj/huipao")->wear();
}

int accept_fight(object me)
{
	command("say 一边去，没心情和你打架。");
	return 0;
}