inherit NPC;

void create()
{
        set_name("小流氓", ({"xiao liumang", "liumang", "punk"}) );
        set("gender", "男性" );
        set_level(4);
        set("age", 18+random(10));
        set("long",
"这是长安城里一个游手好闲的小流氓，一双眼睛贼溜溜的。\n");

        set_temp("apply/defense", 15);
        set("combat_exp", 3500);
        set("per", 15);
        set("attitude","heroism");

        set("chat_chance",10);
        set("chat_msg",
        ({
                "小流氓嘴里不干不净地嘟囔着。\n",
                "小流氓笑嘻嘻地，不怀好意地打量着你。\n",
                (: random_move :),
        }));

        setup();
	carry_object(0,"cloth",random(2))->wear();
}
