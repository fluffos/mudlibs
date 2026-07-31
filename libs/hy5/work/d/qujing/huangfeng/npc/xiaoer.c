// created by angell 1/1/2001
// room: /d/qujing/huangfeng/npc/xiaoer.c

inherit NPC;inherit F_DEALER;

void create()
{
    ("wang_xiaoer");
       set_name("王小二", ({"wang xiaoer", "wang","xiaoer","er","waiter" }));
       set("long", "小酒店的伙计，一副精明干练的模样．\n");
       set("gender", "男性");
	set("title", "伙计");
	set("combat_exp", 3000);
       set("age", 46);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
        set("vendor_goods", ({

                "/d/qujing/huangfeng/obj/yumi",
		    "/d/qujing/huangfeng/obj/mifan",
        }));

	setup();
       add_money("silver", 2);
	add_money("coin", random(80));
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
        add_action("do_buy", "buy");add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say( name()+"说道：这位" +
RANK_D->query_respect(ob)
                                + "，进来喝两盅吧。\n");
                        break;
	}
}
