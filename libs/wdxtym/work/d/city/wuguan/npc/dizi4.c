//dizi4.c 孙均 by river

#include <ansi.h>
inherit NPC;
int ask_wuguan();
int ask_liguan();
int ask_xuexi1();

void create()
{
	set_name("孙均", ({ "sun jun","sun","jun", "man" }));
	set("title", "襄阳武馆四弟子");
	set("gender", "男性");
	set("age", 21);
	set("long", "他是万震山的四弟子，相貌和蔼，一天到晚笑呵呵的。\n");
	set("combat_exp", 5000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("unique", 1);

	set_skill("force", 50);
	set_skill("strike", 50);
	set_skill("sword", 50);

	setup();
}
