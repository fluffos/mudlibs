 // COPYRIGHT (C) Apstone, Inc. 1998
inherit NPC;
void create()
{
        set_name("双手如鸡爪的老妇", ({ "old woman", "ugly old woman" }) );
        set("long",
"此人身穿黑纱袍，将整个脸都遮住了，只露出一双如鸡爪的手。
全身在不停地抽搐着．．．\n");
        set("attitude", "heroism");
        set("gender", "女性");
        set("per", 3);
        set("age",69);
        set("chat_chance", 1);
        set("chat_msg", ({
"老妇盯着你道：你为什么不问我是谁把我弄到现在的地步？（ask old woman about whom）\n",
        }) );
        set("inquiry", ([
                "whom" : "他，他就是那个＂不带刀的人＂！\n",
        ]) );
        set("combat_exp", 1000000);
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("move", 150);
        set_skill("nine-moon-claw",100);
        set_skill("chaos-steps",100);
        map_skill("unarmed","nine-moon-claw");
        map_skill("dodge","chaos-steps");
        map_skill("move","chaos-steps");
        setup();
        carry_object(__DIR__"obj/blackcloth")->wear();
}    
