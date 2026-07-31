// tang.c

inherit NPC;

void create()
{
        set_name("唐掌柜", ({ "tang zhanggui","tang" }) );
        set("gender", "男性" );
        set("age", 42);
        set("long",
                "忠厚的脸上长着一双精明的眼睛。\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        setup();
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
	say("当铺就是穷人的银号，本号信誉卓著，欢迎惠顾。\n");
}