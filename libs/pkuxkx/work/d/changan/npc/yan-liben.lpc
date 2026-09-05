#include <ansi.h>
inherit NPC;

int ask_title();

void create()
{
	set_name("阎立本", ({ "gongbu shangshu", "shangshu" }));
	set("title",YEL"工部尚书"NOR);
  set("gender", "男性");
	set("age", 50);
	set("long", "唐朝著名画家和工程学家，父亲阎毗、兄弟阎立德和他三人都以擅长绘画、工艺和建筑而著名。\n");
	
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