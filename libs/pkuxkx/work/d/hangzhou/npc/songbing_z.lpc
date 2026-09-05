// bing.c 官兵

inherit NPC;
#include <ansi.h>
void create()
{
	set_name(HIW"殿前司都虞候"NOR, ({ "du yuhou","yuhou","hou" }));
	set("age", 32);
	set("gender", "男性");
	set("long", "他是一位殿前司的都虞候。\n");
	set("attitude", "peaceful");
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 100000);
	set("shen_type", 1);

	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("blade", 200);
	set_skill("force", 200);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);


	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object(__DIR__"obj/junfu")->wear();
}

