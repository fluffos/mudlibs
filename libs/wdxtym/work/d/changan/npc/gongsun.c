// gongsun.c

inherit NPC;

#include <ansi.h>

void create()
{
	set_name("公孙大娘", ({ "gongsun daniang", "daniang" }) );
	set("gender", "女性" );
	set("age", 32);
	set("str", 30);
	set("per", 40);
	set("long", @LONG
一个宫装美女，眉宇间透出一股与众不同的气质。
LONG);
	set("combat_exp", 10000);
	set("attitude", "friendly");

	set_skill("art-cognize", 500);
	set_skill("wujian-shu", 500);

	setup();
	carry_object(__DIR__"obj/skirt")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

int recognize_apprentice(object ob, string skill)
{
	object me;

	me = this_object();
	if (ob->query("gender") == "无性")
	{
		message_vision("$N看了$n一眼，皱了皱眉，没说什么。\n",
			       me, ob);
		return -1;
	}

	if (ob->query("gender") == "男性" &&
	    ob->query("weiwang") < 10000)
	{
		message_vision("$N冷冷看了$n一眼，道：“你是"
			       "什么人，我不教无名之辈。”\n",
			       me, ob);
		return -1;
	}

	return 1;
}
