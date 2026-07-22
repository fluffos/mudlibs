// yayi.c  官府衙役
inherit NPC;

void create()
{
        set_name("衙役", ({ "ya yi", "ya" }));
        set("gender", "男性");
        set("age", 25);

        set("long", "一个高大威猛的汉子，因为久在官府做事，脸上已经磨炼得毫无表情。\n");
        set("no_quest",1);
        set("no_bark",1);
        set("combat_exp", 17500);
        set("shen_type", 1);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        setup();
        carry_object(ARMOR_D("yayifu"))->wear();
}
        
void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && living(this_object()) &&
                (int)ob->query_condition("killer")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 0, ob);
        }
}
