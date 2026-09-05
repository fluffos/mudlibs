// wo-kou.c
//cgbii 96.10.5

inherit NPC;

void create()
{
        set_name("倭寇", ({ "wo kou","kou"}) );
        set("gender", "男性");
        set("age", 30);
        set("long",
                "这家伙手上挥舞着武士刀，凶神恶煞往你身上砍了过来。\n");
        set("combat_exp", 15000);
        set("shen_type", -1);
        set("attitude", "aggressive");
        set_skill("unarmed", 45);
        set_skill("blade", 45);
        set_skill("parry", 40);
        set_skill("dodge", 40);

        setup();

        carry_object(__DIR__"obj/wushi_dao")->wield();
        carry_object(__DIR__"obj/he_fu")->wear();

        add_money("coin",50);

}
