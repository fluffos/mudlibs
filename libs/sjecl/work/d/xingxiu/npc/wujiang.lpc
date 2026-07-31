// wujiang.c 武将
inherit NPC;
void create()
{
        set_name("回族武将", ({ "wu jiang", "wu", "jiang" }));
        set("gender", "男性");
        set("age", random(10) + 30);
        set("str", 35);
        set("int", 19);
        set("con", 30);
        set("dex", 20);
        set("long", "他是伊犁城的守将。\n");
        set("combat_exp", 70000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set_skill("unarmed", 55);
        set_skill("force", 55);
        set_skill("sword", 55);
        set_skill("dodge", 55);
        set_skill("parry", 55);
        set_temp("apply/attack", 55);
        set_temp("apply/damage", 30);
        set("chat_chance", 10);
        set("chat_msg", ({
           (: random_move :)
        }) );          
        set("jiali", 10);
        setup();
        carry_object(BINGQI_D("gangjian"))->wield();
        carry_object(ARMOR_D("armor"))->wear();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && living(this_object()) &&
                (ob->query_condition("killer") || ob->query_temp("xx_rob"))) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 0, ob);
        }
}