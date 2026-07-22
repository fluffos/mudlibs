inherit NPC;

void create()
{
        set_name("花忍", ({"hua ren", "hua"}));
        set("age", 27);
        set_level(21);
        set("gender", "男性");
        set("long",
"脸上一道长长的刀疤，可怕之极。\n");
	set("title", "二堂主");
        set("attitude", "peaceful");

        set("combat_exp", 40000);
        set("shen_type", 1);
	set("max_force", 200);
	set("force", 200);
	set("force_factor", 5);
        set_skill("unarmed", 240);
	set_skill("changquan", 420);
        set_skill("dodge", 260);
        set_skill("parry", 260);
	map_skill("unarmed", "changquan");
	setup();
	carry_object(0,"cloth",random(2))->wear();
	carry_object(0,"unarmed",random(2))->wield();
	carry_object(0,"shoes",random(2))->wear();
}


