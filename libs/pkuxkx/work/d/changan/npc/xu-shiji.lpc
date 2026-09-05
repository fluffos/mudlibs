#include <ansi.h>
inherit NPC;

int ask_title();

void create()
{
	set_name("徐世勣", ({ "bingbu shangshu", "shangshu" }));
	set("title",HIR"兵部尚书"NOR);
  set("gender", "男性");
	set("age", 50);
	set("long", "唐初名将，凌烟阁二十四功臣之一，赐姓李，封英国公。\n");
	
	set("combat_exp", 5000000);
	set("shen_type", 1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 500);
	set_skill("dodge", 500);
	set_temp("apply/attack", 500);
	set_temp("apply/defense", 500);

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}