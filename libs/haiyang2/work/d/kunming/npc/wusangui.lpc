// wusangui.c 吴三桂

inherit NPC;

void create()
{
	set_name("吴三桂", ({ "wu sangui", "wu" }));
	set("age", 58);
	set("gender", "男性");
	set("long", "这就是大名鼎鼎的引清兵入关的平西王---吴三桂\n");
	set("attitude", "peaceful");
	set("str", 30);
	set("dex", 30);
	set("combat_exp", 8000000);
	set("shen_type", -100);

	set_skill("unarmed", 280);
	set_skill("dodge", 280);
	set_skill("parry", 280);
	set_skill("blade", 280);
	set_skill("force", 280);
	set_temp("apply/attack", 180);
	set_temp("apply/defense", 180);
	set_temp("apply/damage", 180);
	set_temp("apply/armor", 180);
    set("max_neili",8500);
    set("neili",8500);
    set("qi",8500);
    set("eff_qi",8500);
    set("max_qi",8500);

    set("jing",8500);
    set("eff_jing",8500);
    set("max_jing",8500);
        set_skill("force", 380+random(180));

        set_skill("unarmed", 380+random(180));
        set_skill("blade", 380+random(180));
        set_skill("parry", 380+random(180));
        set_skill("dodge", 380+random(180));
        set_skill("kuang-blade", 380+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),

        }) );

	setup();
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/guanfu")->wear();
}


