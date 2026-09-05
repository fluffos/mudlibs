#include <ansi.h>
inherit NPC;

int ask_gold();

void create()
{
	set_name("高士廉", ({ "shangshu puye", "puye" }));
	set("title",HIY"尚书右仆射"NOR);
  set("gender", "男性");
	set("age", 50);
	set("long", "长孙皇后、长孙无忌的亲舅舅，封申国公，位列凌烟阁二十四功臣之六。\n");
	
	set("combat_exp", 100000);
	set("shen_type", 1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

  set("inquiry", ([
    "俸禄" : (: ask_gold :) 
  ]) );

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

int ask_gold()
{
	write("任务正在开发中！\n");
	return 1;
}