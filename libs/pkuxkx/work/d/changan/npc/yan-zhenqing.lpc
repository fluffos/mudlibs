#include <ansi.h>
inherit NPC;

int ask_title();

void create()
{
	set_name("颜真卿", ({ "xingbu shangshu", "shangshu" }));
	set("title",HIC"邢部尚书"NOR);
  set("gender", "男性");
	set("age", 50);
	set("long", "唐朝著名书法家，和柳公权并称“颜筋柳骨”。\n");
	
	set("combat_exp", 100000);
	set("shen_type", 1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}