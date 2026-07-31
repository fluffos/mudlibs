//dizi7.c 冯坦 by river
//将原有的di yun的内容搬到这里
//by tangfeng for 连城诀quest

inherit NPC;

#include <ansi.h>

void create()
{
	set_name("冯坦", ({ "feng tan", "feng", "tan"}));
	set("title","襄阳武馆七弟子");
	set("long", "他是万震山的七弟子，沉默寡言，一副尖嘴猴腮的样子。\n");
	set("gender", "男性");
	set("age", 22); 

	set("combat_exp", 5000);
	set("shen_type", 1);
	set("unique", 1);

	set_skill("force", 35);
	set_skill("strike", 35);
	set_skill("sword", 35);

       
	setup();
}

