
inherit NPC;

void create()
{
       set_name("游方僧人", ({"monk"}));
       set("gender", "男性");
	set("long", "一位白净脸的大和尚。\n");
       set_level(5);
       set("age", 40);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set_skill("unarmed", 35);
	set_skill("parry", 35);
	set_skill("dodge", 35);
        setup();
	add_money("coin", 20+random(50));
	carry_object("/d/obj/cloth/sengyi")->wear();
}