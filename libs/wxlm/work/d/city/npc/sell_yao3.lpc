// huoji. 药铺伙计

#include <medical.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("北药铺伙计", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 18);
	set("long", "他是平神医从乡下招来帮忙的。\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		  HERB("xiefen"),	 // 蝎粉
		HERB("xijiao"),	 // 犀角
		HERB("xiongdan"),       // 熊胆
		HERB("xionghuang"),     // 雄黄
		HERB("xuejie"),	 // 血竭
		HERB("xuelian"),	// 雪莲
		HERB("yanwo"),	  // 燕窝
		HERB("yjhua"),	  // 洋金花
		HERB("yuanzhi"),	// 远志
		HERB("zihua"),	  // 紫花
		HERB("zzfen"),	  // 珍珠粉
		HERB("shedan"),	  // 蛇胆
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
