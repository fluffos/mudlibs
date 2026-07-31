// shipopo.c 史婆婆

inherit NPC;
inherit F_UNIQUE;
//inherit F_SKILL;

void create()
{
        set_name("史婆婆", ({ "shi", "popo" }));
        set("title", "金乌派掌门人");
        set("gender", "女性");
        set("long", "她是雪山派掌门人白自在的妻子，虽说现在人已显得苍老，\n"
        "但几十年前提起“江湖一枝花”史小翠来，武林中却是无人不知。\n");
        set("age", 68);

        set("int", 30);
        set("str",400);

        set("qi", 50000);
        set("max_qi", 50000);
        set("jing", 5000);
        set("max_jing", 5000);
        set("shen_type", 1);

        set("combat_exp", 17500000);
        set("attitude", "friendly");

        set_skill("force", 470);
        set_skill("dodge", 470);
        set_skill("blade", 440);
        set_skill("parry", 490);
        set_skill("unarmed", 490);
       set_skill("yanfly", 70);
//      set_skill("houquan", 100);

        set_temp("apply/attack", 350);
        set_temp("apply/defense", 350);
        set_temp("apply/damage", 335);


        map_skill("blade", "jinwu-daofa");
        map_skill("parry", "jinwu-daofa");
        map_skill("dodge", "yan-fly");
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
}

