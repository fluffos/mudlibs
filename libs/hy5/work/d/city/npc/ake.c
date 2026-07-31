// ake.c

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("阿珂", ({ "a ke", "ke" }) );
	set("gender", "女性" );
	set("long", "阿珂为李自成与陈圆圆之女。
她容色丽都，冠绝当代，五根手指细长娇嫩，真如用白玉雕
成，手背上手指尽处，有五个小小的圆涡。
当年韦小宝一见这少女，不过十六七岁，胸口宛如被一个无
形的铁锤重重击了一记，霎时之间唇燥舌干，目瞪口呆，心
道：“我死了，我死了！哪里来的这样的美女？这美女倘若
给了我做老婆，小皇帝跟我换位也不干。韦小宝死皮赖活，
上天下地，枪林箭雨，刀山油锅，不管怎样，非娶了这姑娘
做老婆不可。”\n");
	set("age", 16);
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("per",30);
	set("no_get", 1);
	set("no_get_from", 1);
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	setup();

	carry_object(__DIR__"obj/flower_shoe")->wear();
	carry_object(__DIR__"obj/green_cloth")->wear();
}

void init()
{
	add_action("do_value", "value");
	add_action("do_pawn", "pawn");
//	add_action("do_redeem", "redeem");
}


