// yuanwai.c
inherit NPC;

void create()
{
        set_name("侯员外", ({ "hou yuanwai", "hou" }));
        set("long",
                "侯员外据说是这长安镇上的首富，谁也不知道他到底有多少\n"
                "家财。他大约五十出头，长的富富态态。\n");
        set("gender", "男性");
        set("age", 52);

        set("combat_exp", 1200000);
        set_skill("unarmed", 450);
        set_skill("force", 620);
        set_skill("dodge", 350);
        set_temp("apply/attack", 135);
        set_temp("apply/defense", 142);

        setup();
        carry_object(__DIR__"obj/jinduan")->wear();
        add_money("silver",120);
}

