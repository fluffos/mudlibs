// wu-shi1.c 亲兵队长

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("亲兵队长", ({ "qinbing duizhang", "duizhang", "qinbing" }) );
	set("gender", "男性");
	set("age", 40);
	set("long",
		"他就是当今「中神通」的亲兵队长, 身披铁甲，手执钢剑。\n");

	set("combat_exp", 400000);
	set("attitude", "heroism");
        set("unique", 1);

	set("str", 24);
	set("con", 22);
	set("int", 22);
	set("dex", 22);

	set("max_qi", 800);
	set("eff_qi", 800);
	set("qi", 800);
	set("max_jing", 300);
	set("jing", 300);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 50);

	set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);

	set_skill("sword", 150);
	set_skill("unarmed", 150);
	set_skill("parry", 150);
	set_skill("dodge", 150);
        set("chat_chance", 3);

	setup();

        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/armor/armor")->wear();
}
