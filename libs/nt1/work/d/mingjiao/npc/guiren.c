inherit NPC;
void create()
{
        set_name("´ï¹Ù¹óÈË", ({ "gui ren", "gui", "ren" }));
	set("gender", "ÄĞĞÔ");
	set("age", 20+random(40));
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set("apply/attack", 15);
	set("apply/defense", 15);
	set("apply/damage", 5);
	set("combat_exp", random(2000)+1000);
	set("shen_type", 1);
	setup();
        add_money("silver", 1);
}
	
