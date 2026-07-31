// huoji. 药铺伙计
#include <ansi.h>
#include <medical.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("内药铺伙计", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 18);
	set("long", "他是平神医从乡下招来帮忙的。\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		 HERB("chaihu"),	 // 柴胡
		HERB("chenpi"),	 // 陈皮
		HERB("chuanwu"),	// 川乌
		HERB("dahuang"),	// 大黄
		HERB("dangui"),	 // 当归
		HERB("duhuo"),	  // 独活
		HERB("fangfeng"),       // 防风
		HERB("fuzi"),	   // 附子
		HERB("gsliu"),	  // 干石榴
		HERB("guiwei"),	 // 归尾
		HERB("hafen"),	  // 蛤粉
		HERB("heshouwu"),       // 何首乌

	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
