// /d/dali/npc/maihua.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("卖花姑娘", ({ "maihua guniang", "guniang", }) );
	set("gender", "女性" );
	set("age", 22);
	set("per", 26);
	set("unique", 1);
	set("long","这位姑娘正忙著招呼客人，还不时给她的花浇浇水。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "小美人");
	set("vendor_goods", ({
		(["name":__DIR__"obj/hua","number":20]),
	}));
	setup();
	carry_object("/clone/armor/cloth")->wear();
}

void init()
{
	object ob = this_player();

        ::init();
        if( interactive(ob) && !is_fighting() ) {
		if ( ob->query("family/family_name") == "丐帮" && ob->query("gb/bags") < 2 ){
                        remove_call_out("saying");
                        call_out("saying", 0, ob);
                }
                else {
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                }
        }
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
	object me = this_object();
	if( !ob || environment(ob) != environment() ) return;
	if ( ! me || file_name(environment(me)) != me->query("startroom")) return;
	switch( random(2) ) {
		case 0:
			say( "卖花姑娘笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来看看茶花吧。\n");
			break;
		case 1:
			say( "卖花姑娘放下手中浇花的水壶，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
	}
}

void saying(object ob)
{
	object me = this_object();
	if( !ob || environment(ob) != environment() ) return;
	if ( ! me || file_name(environment(me)) != me->query("startroom")) return;
	say("\n卖花姑娘皱皱眉,说道:对不起,小店今日还没卖出几盆花,请去别处吧！\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);

}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;

        ob->move("/d/dali/dongjie7");
	message("vision","只听长长一声叹息," +  ob->query("name") +
		"无可奈何的离开了花店。\n", environment(ob), ob);
}
