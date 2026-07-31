// ywaiter.c

inherit NPC;

void create()
{
        set_name("小伙计", ({ "waiter" }) );
        set("title", "王记药铺");
        set("gender", "男性" );
        set("age", 17);
        set("long", "他是药铺的小伙计，正学着配药。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set_skill("unarmed", 30);
        set_skill("parry", 10);
        set_skill("dodge", 10);

        set("inquiry", ([
                "抓药" : "我们这里的药最好，您要买什么？",
        ]) );

       setup();
        add_money("coin", 50);
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "小伙计称了几味药，包做个纸包。\n");
                        break;
                case 1:
                        say( "伙计微笑着说道：这位"  
                                + RANK_D->query_respect(ob)
                                + "，买药？\n");
                        break;
        }
}
