// /d/beijing/npc/saixishi.c
// Npc: 赛西施
// Date: 2003.3
// by vast
// Modified by iszt@pkuxkx, 2007-03-27, added wanzi

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("赛西施", ({"sai xishi", "sai",}));
	set("title", HIY"食为天老板娘"NOR);
	set("long",
		"她是食为天的老板娘，一手一流的烹饪技术，此时正在笑脸迎客。\n"
		"她人长的美，心灵也美，你不禁也想到店里面坐坐，吃点东西了。\n"
	);


	set("gender", "女性");
	set("attitude", "peaceful");
	set("rank_info/respect", "老板娘");

	set("age", 20);
	set("per", 25 + random(20));
	set("shen_type",1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 900);
	set("max_jing", 900);
	set("neili", 900);
	set("max_neili", 900);
	set("combat_exp", 10000);
	set("vendor_goods", ({
		__DIR__"obj/shizitou",
		__DIR__"obj/wanzi",
	}));
	setup();

	carry_object("/clone/cloth/female3-cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}