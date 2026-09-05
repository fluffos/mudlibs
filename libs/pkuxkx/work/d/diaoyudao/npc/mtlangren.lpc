//langren.c
//cgbii 96.10.5
// change by hongdou 98.09.13
inherit NPC;

void create()
{
        set_name("东瀛浪人", ({ "langren","ren"}) );
        set("gender", "男性");
       set("age",35);
        set("long",
               "这是一个东瀛武士，正挥舞着武士刀，凶神恶煞地往你身上砍了过来。\n");
        set("combat_exp",18000);
        set("shen_type", -1);
         set("attitude", "heroism");
        set_skill("unarmed",50);
         set_skill("blade",50);
        set_skill("parry",45);
        set_skill("dodge",45);

        setup();

        carry_object(__DIR__"obj/wushi_dao")->wield();
        carry_object(__DIR__"obj/he_fu")->wear();

        add_money("silver",15);

}
