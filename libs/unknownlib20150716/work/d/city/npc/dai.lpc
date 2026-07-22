inherit NPC;
string send_mail();
string receive_mail();

void create()
{
        set_name("戴文重", ({"dai wenzhong", "dai"}));
        set("age", 42);
        set_level(6);
        set("gender", "男性");
        set("long",
"驿站里的当家，长的圆圆胖胖的。\n");
	set("title", "驿站当家");
        set("attitude", "peaceful");

        set("combat_exp", 40000);
  set("daoxing", 20000);

        set("shen_type", 1);
	set("max_force", 300);
	set("force", 300);
	set("force_factor", 5);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        set_skill("parry", 40);
        

	setup();
        carry_object(0,"cloth",random(2))->wear();
}