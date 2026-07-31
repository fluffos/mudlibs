// npc: /d/xingxiu/herdsman.c
// Jay 3/18/96

inherit NPC;

void create()
{
        set_name("牧羊人", ({ "muyang ren", "ren"}));
        set("gender", "男性");
        set("age", 25 + random(10));

        set("long", "一个维吾尔族牧羊人。\n");

        set("attitude", "friendly");

        set("combat_exp", 1500);   
        set("env/wimpy", 60);
        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("whip", 20);

        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set("chat_chance", 5);
        set("chat_msg", ({
           (: random_move :)
         }) );          
        setup();       
        carry_object(BINGQI_D("bian"))->wield();
        carry_object(ARMOR_D("yangao"))->wear();
}