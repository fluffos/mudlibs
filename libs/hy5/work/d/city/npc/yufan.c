// yufan.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("¿‰”Ù»ª" , ({ "leng yuran", "leng" }) );
	set("rank_info/zhiye","”ÒµÍ¿œ∞Â");
	set("gender", "ƒ––‘" );
	set("age",45);
	set("combat_exp", 1500000);
	set_skill("unarmed",30);
	set_skill("dodge",30);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/yujie",
		__DIR__"obj/yudai",
		__DIR__"obj/yufa",
		__DIR__"obj/yushou",
		__DIR__"obj/yuruyi",
		__DIR__"obj/yubei",
		__DIR__"obj/yuzhan",
	}) );
	setup();
	carry_object( "/clone/cloth/male1-cloth")->wear();
}

void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if (environment(ob)==environment())
	message_vision("”ÒµÍ¿œ∞Â∂‘$P–¶¡≥œ‡”≠£∫«ÎÀÊ±„ø¥ø¥°£\n",ob);
	return;
}
