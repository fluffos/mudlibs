inherit NPC;
void create()
{
        set_name("藏族妇女", ({ "zangzu funv", "woman"}));
        set("gender", "女性");
        set("age", 25);
        set("long", "一位热情好客的藏族妇女。\n");
        set("attitude", "friendly");
        set("combat_exp", 500);
        set("str", 18);
        set("int", 18);
        set("con", 18);
        set("dex", 17);
        set("max_qi", 140);
        set("max_jing", 140);
        set("neili", 100);
        set("max_neili", 100);
        set_skill("unarmed", 10);
        set_skill("parry", 10);
        set_skill("dodge", 10);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 5);
        set_temp("apply/damage", 5); 
        setup();
        set("chat_chance", 1);
        set("chat_msg", ({
"藏族妇女好奇地看着你，道: 你是从那里来的？以前没见过你。\n",
        }) );
        carry_object(ARMOR_D("pipao"))->wear();
        carry_object(FOOD_D("youcha"));

}
