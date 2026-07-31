// judge2.c

inherit NPC;

void create()
{
        set_name("赌馆小伙计", ({ "huoji" }) );
        set("gender", "男性" );
        set("age", 17);
        set("long", "他有着一双机灵的大眼睛，一看就是一个聪明透顶的小东西。\n");
        set("per", 25);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        set_skill("parry", 70);

        setup();
        add_money("silver", 1);
        carry_object("/clone/misc/cloth")->wear();

}
