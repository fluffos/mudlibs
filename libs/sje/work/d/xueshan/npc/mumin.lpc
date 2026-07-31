inherit NPC;
void create()
{
        set_name("藏族牧民", ({ "zangzu mumin", "mu min"}));
        set("gender", "男性");
        set("age", 26);
        set("long", "一位健壮的藏族牧民，看到你，向你友好的招了招手。\n");
        set("attitude", "friendly");
        set("combat_exp", 4000 + random(500));
        set("str", 32);
        set("int", 18);
        set("con", 22);
        set("dex", 17);
        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 5);
        set_skill("unarmed", 20);
        set_skill("blade", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);

        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set_temp("apply/damage", 25);
         

        setup();
        set("chat_chance", 5);
 
        carry_object(BINGQI_D("madao"))->wield();
        carry_object(ARMOR_D("pipao"))->wear(); 
}
