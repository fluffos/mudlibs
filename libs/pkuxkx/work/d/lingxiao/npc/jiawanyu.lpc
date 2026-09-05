// jiawanyu.c

#include "setdizi.h"

inherit F_VENDOR;

void create()
{
	setcreate(100);
	set_name("贾万玉", ({ "jia wanyu", "jia", "wanyu" }) );
	set("gender", "男性" );
	set("age", 40);
	set("long", "他以前是个贵公子，后来家道中落，上山来拜了师，靠卖书谋生。\n");

	set("rank_info/respect", "公子");
	set("vendor_goods", ({
		__DIR__"obj/book_force",
		__DIR__"obj/book_sword",
		__DIR__"obj/book_parry",
		__DIR__"obj/book_xsjf",
	}));
	add("inquiry", ([
		"name" : "在下姓贾，恩师给在下取了个名字叫万玉。",
		"rumors" : "这凌霄城可以说几十年没发生过什么大事了，哪有什么消息呢？",
		"here" : "在下自食其力，盘了这个书铺赖以谋生。",
	]) );
	setfamily(6);

	setup();
	setequip();
}

void attempt_apprentice(object ob)
{
	setapp(ob);
}

void init()
{       
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( HIM"贾万玉点点头道：这位" + RANK_D->query_respect(ob)
				+ HIM"，书中自有千钟粟，此言不虚！\n"NOR);
			break;
		case 1:
			say( CYN"贾万玉笑着问：这位" + RANK_D->query_respect(ob)
				+ CYN"，您来选册什么书？\n"NOR);
			break;
	}
}
