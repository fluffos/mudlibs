//Cracked by Roath
inherit NPC;

void create()
{
        set_name("七修兽", ({ "qixiu shou", "shou" }) );
        set("race", "野兽");
        set("age", 50);
        set("long", "一只浑身上下披着银羽的猛虎，一双眼睛正恶狠狠地瞪著你。\n");
        set("attitude", "aggressive");
        set("bellicosity", 8000);
        set("str", 30);
        set("cor", 30);
 	set("per", 10);
        set("max_qi", 15000);
        set("max_jing", 15000);
	set("neili", 20000);
	set("max_neili", 10000);
	set("force_factor", 80);
	set("neili", 20000);
	set("max_neili", 10000);
	set("mana_factor", 80);

	set_skill("unarmed", 2000);
	set_skill("dodge", 2000);
	set_skill("parry", 2000);

        set("limbs", ({ "头部", "身体", "前脚", "後脚"}) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 800000);
  set("combat_exp", 8500000);

  set_skill("unarmed", 900+random(900));

       set_skill("dragon", 900+random(900));

      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");

    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
    (: perform_action, "unarmed.penhuo" :),
    	(: perform_action, "unarmed.yaoyao" :),           
    (: perform_action, "unarmed.tuwu" :),

 }) );
        set_temp("apply/damage", 2500);
        set_temp("apply/armor", 900);

        setup();
}

