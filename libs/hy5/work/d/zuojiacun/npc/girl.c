inherit NPC;

void create()
{
        set_name("小娟", ({"girl","kid","xiaohai"}));
        set("gender", "女性" );
        set("age", 9);
        set("long", "看她兴高采烈的样子,看来收获不小。\n");
        set("combat_exp", 500);
        set("attitude", "peaceful");
        set_skill("dodge", 10);
        set_skill("unarmed", 20);
        set_skill("literate", 30);
        set("per", 25);
        set("max_kee", 200);
        set("max_gin", 100);
        set("max_sen", 100);
        setup();
        carry_object("/d/hainan/obj/hua-cloth")->wear();
        carry_object("/d/hainan/obj/beike2");
}


