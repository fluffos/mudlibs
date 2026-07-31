inherit NPC;
void create()
{
    set_name("ÊÌÍ¯", ({ "shi tong", "tong" }));
    set("gender", "ÄĞĞÔ");
    set("age", 15);
    set("combat_exp", 100);
    set_skill("unarmed", 5);
    set_skill("blade", 5);
    set_skill("parry", 5);
    set_skill("dodge", 5);
        
    set_temp("apply/attack", 2);
    set_temp("apply/defense", 2);
    set_temp("apply/damage", 2);
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
