// xiaojie.c

inherit NPC;
void create()
{
       set_name("校尉", ({"xiao wei", "wei", "xiao"}));
       set("long","将军府的家将，看起来神气凛然．\n");
       set("gender", "男性");
       set("age", 28);
       set_level(25);
       set("attitude", "aggressive");
        set("per", 25);
        set("force", 300);
        set("max_force", 300);
        set("force_factor", 15);
	
        set("shen_type", 1);
        set("combat_exp", 15000+random(3000));
        set_skill("spear", 240);
        set_skill("parry", 240);
	set_skill("dodge", 240);
	set_skill("yanxing-steps", 225);
	set_skill("bawang-qiang", 215);
	map_skill("dodge", "yanxing-steps");
	map_skill("spear", "bawang-qiang");
	map_skill("parry", "bawang-qiang");
        setup();
        carry_object(0,"spear",random(2))->wield();
        carry_object(0,"armor",random(2))->wear();
        carry_object(0,"pifeng",random(2))->wear();
        carry_object(0,"cloth",random(2))->wear();
        carry_object(0,"kui",random(2))->wear();
        carry_object(0,"shoes",random(2))->wear();
}
