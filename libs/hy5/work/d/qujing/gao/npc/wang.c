// laoyu.c

inherit NPC;inherit F_DEALER;

void create()
{
    ("wang_zhanggui");
       set_name("王掌柜", ({"wang zhanggui", "wang"}));
       set("long", "小酒馆的老板，吃的胖胖的．\n");
       set("gender", "男性");
	set("title", "酒馆老板");
	set("combat_exp", 3000);
       set("age", 46);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);


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

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say( name()+"笑咪咪地说道：这位" +
RANK_D->query_respect(ob)
                                + "，进来喝两盅吧。\n");
                        break;
	}
}
