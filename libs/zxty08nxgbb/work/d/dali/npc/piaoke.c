inherit NPC;

void create()
{
        set_name("胖嫖客", ({ "piaoke", "ke"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "这是一位肥肥胖胖的大嫖客\n");
        set("combat_exp", 50000);
        set_skill("dodge", 100);
        set_skill("unarmed", 120);
        set("chat_chance", 10);
        set("chat_msg", ({
"胖嫖客回头骂道：什么狗屁＂湖上八娇＂，有什么了不起的！连摸两下都不可以！\n",
                (: random_move :)
        }) );
        
        setup();
        add_money("silver", 50);
        carry_object("/clone/misc/cloth")->wear();
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
