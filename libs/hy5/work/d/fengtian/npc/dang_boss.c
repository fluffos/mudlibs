// dang_boss.c

inherit NPC;

void create()
{
	set_name("当铺老板", ({ "dangpu laoban" }) );
	set("gender", "男性" );
	set("age", 42);
	set("long","这是一位满脸奸诈的中年人，爱搭不
理的看了你一眼。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = previous_object()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob
        || (environment(ob) != environment())
        || file_name(environment()) != this_object()->query("startroom"))
                return;
        command("say 本号全天营业，信誉卓著，欢迎惠顾。\n");
}
