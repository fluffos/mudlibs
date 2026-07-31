//shipuboss.c 冷梦石
inherit NPC;
void create()
{
        set_name("冷梦石", ({ "leng mengshi", "leng", "mengshi" }));
        set("gender", "男性");
        set("age", random(10) + 50);
        set("str", 25);
        set("title", "石辅老板");
        set("dex", 16);
        set("long","这个人是这个石辅的老板，据说他妈生他的时候梦了一块很美的\n"
"大理石，便为他定名为冷梦石。是大理一等一的好石匠\n");
        set("combat_exp", 50000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set_skill("unarmed", 60);
        set_skill("force", 60);
        set_skill("sword", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 30);
        set("neili", 400); 
        set("max_neili", 400);
        set("jiali", 10);
        set("chat_chance", 5);
        set("chat_msg", ({
        "\n本店的石屏闻名天下，客官你是不是也定做一面。\n",
        "\n小山你小心点，这一面可是李将军定做的。\n",
        }) );
 
        setup();
        carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
        ::init();
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        add_action("do_kill","kill");
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}
