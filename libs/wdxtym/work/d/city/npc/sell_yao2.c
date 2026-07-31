// huoji. 药铺伙计
#include <ansi.h>
#include <medical.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("西药铺伙计", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 18);
	set("long", "他是平神医从乡下招来帮忙的。\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		HERB("ruxiang"),	// 乳香
		HERB("shadan"),	 // 鲨胆
		HERB("shancha"),	// 山茶花
		HERB("shanjia"),	// 山甲
		HERB("shengdi"),	// 生地
		HERB("shenglg"),	// 生龙骨
		HERB("sumu"),	   // 苏木
		HERB("taoxian"),	// 桃仙
		HERB("tenghuang"),      // 藤黄
		HERB("tianqi"),	 // 田七
		HERB("tugou"),	  // 土狗
		HERB("wulingzhi"),      // 五灵脂
	}));
set("icon","00973");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
