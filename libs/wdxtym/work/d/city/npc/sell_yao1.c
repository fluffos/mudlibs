// huoji. 药铺伙计
#include <ansi.h>
#include <medical.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("东药铺伙计", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 18);
	set("long", "他是平神医从乡下招来帮忙的。\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		HERB("honghua"),	// 红花
		HERB("hugu"),	   // 虎骨
		HERB("juhua"),	  // 菊花
		HERB("lanhua"),	 // 兰花
		HERB("lingxian"),       // 灵仙
		HERB("lingzhi"),	// 灵芝
		HERB("lurong"),	 // 鹿茸
		HERB("mahuang"),	// 麻黄
		HERB("moyao"),	  // 没药
		HERB("niuhuang"),       // 牛黄
		HERB("niuxi"),	  // 牛膝
		HERB("qianjinzi"),      // 千金子
		HERB("renshen"),	// 人参
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
