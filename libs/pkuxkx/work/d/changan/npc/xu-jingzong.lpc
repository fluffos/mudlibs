#include <ansi.h>
inherit NPC;

int ask_title();

void create()
{
	set_name("许敬宗", ({ "libu shangshu", "shangshu" }));
	set("title",MAG"礼部尚书"NOR);
  set("gender", "男性");
	set("age", 50);
	set("long", "这是一个学识渊博的老者，因支持高宗立武则天为后而被后人记住。\n");
	
	set("combat_exp", 100000);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}