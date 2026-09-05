// xiu.c 秀才
// CLEANSWORD 1996/2/2

inherit NPC;

void create()
{
        set_name("秀才", ({ "xiu cai", "xiu" }));
        set("long", "秀才多次参考，均未考上，只好在村里教书。\n");
        set("gender", "男性");
        set("age", 55);

        set_skill("literate", 150);

        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 20);

        set("combat_exp", 40000);
        set("shen_type", 1);
        setup();

}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("mark/朱"))
                return 0;
        ob->add_temp("mark/朱", -1);
        return 1;
}

int accept_object(object who, object ob)
{
        if (!(int)who->query_temp("mark/朱"))
                who->set_temp("mark/朱", 0);
        if (ob->query("money_id") && ob->value() >= 100) {
                message_vision("秀才同意指点$N一些读书写字的问题。\n", who);
                who->add_temp("mark/朱", ob->value() / 25);
                return 1;
        }
        return 0;
}
