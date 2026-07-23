 inherit NPC;
void create()
{
        set_name("塔僧", ({ "tower guard", "guard" }) );
        set("gender", "男性" );
        set("age", 35);
        set("str", 30);
        set("long", @LONG
一个负责看管舍利塔的藏僧。
LONG
);
        set("attitude", "heroism"); 
        set("neili", 300);
        set("max_neili", 300);
        set("force_factor", 2);  
        set("combat_exp", 20000+random(10000)); 
        set_skill("unarmed", 50);
        set_skill("bloodystrike", 50);
        set_skill("force", 40);
        set_skill("parry", 50);
        map_skill("unarmed", "bloodystrike");
        set_skill("iron-cloth", 100);
        set_skill("jin-gang", 30);
        map_skill("iron-cloth", "jin-gang");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.fefawubian" :),
        }) );  
        setup(); 
        carry_object(__DIR__"obj/redcloth")->wear();
}  
