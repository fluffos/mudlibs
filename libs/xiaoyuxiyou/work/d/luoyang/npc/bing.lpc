inherit NPC;

void create()
{
	int i;
        set_name("小兵", ({ "xiao bing", "bing" }));
        set("age", 18+random(10));
        set("gender", "男性");
        set("long","这些兵士都是少帅军中的精锐。\n");
        set("attitude", "peaceful");
	i = 9+random(20);
	set_level(i);
        set_skill("unarmed", i*10);
        set_skill("dodge", i*10);
        set_skill("parry", i*10);
        set_skill("blade", i*10);
        set_skill("force", i*10);
        setup();
        carry_object(0,"blade",random(2))->wield();
        carry_object(0,"cloth",random(2))->wear();
        carry_object(0,"armor",random(2))->wear();
        carry_object(0,"pifeng",random(2))->wear();
        carry_object(0,"kui",random(2))->wear();
        carry_object(0,"shoes",random(2))->wear();
        powerup(1,1);
}