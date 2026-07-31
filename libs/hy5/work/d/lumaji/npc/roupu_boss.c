// roupu_boss.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;


void create()
{
	set_name("肉铺老板", ({ "roupu boss", "boss" }) );
	set("gender", "男性" );
        set("age", 45);
        set("long","这是一位满脸微笑的粗大汉子。\n");
        set("combat_exp", 10000);

        set("attitude", "friendly");
	set("sell_all_day",1);

	set("chat_chance", 5);
	set("chat_msg",({
		CYN"肉铺老板说道：“老赵是咱们这有名的打猎高手,每次出猎都能带不少野味回来。”\n"NOR,
		CYN"肉铺老板说道：“听说集南的哪条小路到晚上还有人劫道这世道,唉。。。”\n"NOR,
}));
	set("vendor_goods", ({
		__DIR__"obj/turou",
		__DIR__"obj/lurou",
		__DIR__"obj/zhurou",
	}));


	set_skill("dodge",90);
	set_skill("parry",90);
	set_skill("blade",90);

        setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/tigu_blade")->wield();
}

void init()
{	
	object ob;

	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
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

	say( CYN"肉铺老板微笑着说道：这位" + RANK_D->query_respect(ob)
		+ "，来尝尝咱们这的野味吧。\n"NOR);

}
