// nigu.c  尼姑

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("尼姑", ({ "ni gu", "ni", "gu" }) );
	set("gender", "女性" );
	set("age", 34);
	set("long", "这位尼姑正坐在铺垫上，双手捻着珠链，嘴中念念有词。\n");
	set("combat_exp", 700);
	set("attitude", "peaceful");
	set("rank_info/respect", "尼姑");
	setup();
	carry_object("/d/emei/obj/cloth")->wear();
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
			say( "尼姑施了一礼说道：这位" + RANK_D->query_respect(ob) + "，佛家人慈善为本，捐一点银两吧。\n");
			break;
		case 1:
			say( "尼姑说道：这位" + RANK_D->query_respect(ob) + "，多谢捐赠，愿佛祖保佑。\n");
			break;
	}
}
