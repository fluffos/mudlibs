// xiaoshan.c 单小山
// by pishou

#include <ansi.h>

inherit NPC;

void create()
{
    set_name("单小山", ({ "shan xiaoshan", "shan", "xiaoshan" }) );
	set("gender", "男性");
        set("age", 25);
	set("long",
        "他是泰山“铁面判官”单正的小儿子单小山。\n"
        "浓眉大汉, 与众兄弟容貌甚为相似。\n");
        set("combat_exp", 30000);
        set("shen_type", 1);
	set("attitude", "heroism");
        set("unique", 1);

        set("str", 28);
        set("con", 26);
	set("int", 20);
	set("dex", 24);
        set("per", 26);

	set("max_qi", 400);
	set("eff_qi", 400);
	set("qi", 400);
	set("max_jing", 200);
	set("jing", 200);
	set("neili", 300);
	set("max_neili", 300);
	set("jiali", 20);
	set("shen_type", 0);

	set_temp("apply/attack",  30);
	set_temp("apply/defense", 30);

	set_skill("unarmed", 50);
	set_skill("parry", 60);
	set_skill("dodge", 60);

	setup();

        carry_object("/clone/armor/armor")->wear();
}

