// wu-shi2.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("红衣武士", ({ "wei shi", "shi", "guard" }) );
	set("gender", "男性");
	set("age", 35);
	set("long",
		"这是位红衣武士，身披钢甲，手执长剑，双目精光炯炯，警惕地巡视着四周的情形。\n");
	set("combat_exp", 140000);
        set("shen_type", 1);
	set("attitude", "heroism");

        set("str", 23);
	set("con", 23);
	set("int", 20);
        set("dex", 23);
        set("no_get",1);
	set("max_qi", 500);
	set("eff_qi", 500);
	set("qi", 450);
	set("max_jing", 200);
	set("jing", 200);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 25);
	set("shen_type", 0);

	set_temp("apply/attack",  40);
	set_temp("apply/defense", 40);

	set_skill("sword", 90);
	set_skill("unarmed", 60);
	set_skill("parry", 90);
	set_skill("dodge", 90);

	setup();

        carry_object(__DIR__"obj/changjian")->wield();
        carry_object(__DIR__"obj/tiejia")->wear();
}

