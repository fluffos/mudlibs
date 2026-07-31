
// judge.c

inherit NPC;

void create()
{
        set_name("宝官", ({ "judge" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "他脸上的表情仿佛是看到了你口袋里的钱一般。\n");
        set("per", 25);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        set_skill("parry", 70);

        set("inquiry", ([
                "赌" : "客官您把钱给我就行了。\n",
        ]) );

        setup();
        add_money("silver", 1);
        carry_object("/clone/misc/cloth")->wear();
       // carry_object("/obj/example/dagger")->wield();
}

