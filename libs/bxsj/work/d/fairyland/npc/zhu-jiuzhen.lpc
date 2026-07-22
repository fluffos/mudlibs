// zhu-jiuzhen.c 朱九真

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("朱九真", ({"zhu jiuzhen", "zhu"}));
	set("long", "她长得极美，容貌娇媚，又白又腻。\n");
	set("title", HIW"雪岭双姝"NOR);
	set("gender", "女性");
	set("age", 17);
        set("per", 27);
        set("unique", 1);
	set_skill("unarmed", 38);
	set_skill("force", 30);
	set_skill("dodge", 40);
	set_skill("parry", 35);
	set_temp("apply/attack", 25);
	set_temp("apply/defense", 25);
	set_temp("apply/damage", 5);

	set("combat_exp", 25000);
	set("shen_type", 1);
	setup();
	carry_object("/clone/armor/baihu-qiu")->wear();
	carry_object("/clone/armor/necklace")->wear();
}
	
