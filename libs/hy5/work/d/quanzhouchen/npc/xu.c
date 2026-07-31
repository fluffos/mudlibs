// xu.c
// Last Modified by winder on May. 29 2001

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("许老板", ({ "xu laoban", "xu", "laoban", "boss" }));
	set("title", "绸缎庄老板");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 35);
	set("long", "鸿翔绸缎庄乃是许老板祖传的生意，到许老板已是第四代了。\n");
	set("attitude", "friendly");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);
	set("combat_exp", 40000);
	set("vendor_goods", ({
		__DIR__"cloth/changpao",
		__DIR__"cloth/choupao",
		__DIR__"cloth/cloudyshoe",
		__DIR__"cloth/gongpao",
		__DIR__"cloth/gongqun",
		__DIR__"cloth/huangyi",
		__DIR__"cloth/jinpao",
		__DIR__"cloth/longpao",
		__DIR__"cloth/luopao",
		__DIR__"cloth/luoyi",
		__DIR__"cloth/magua",
		__DIR__"cloth/mangpao",
		__DIR__"cloth/nichang",
		__DIR__"cloth/pink_cloth",
		__DIR__"cloth/pinkskirt",
		__DIR__"cloth/piyi",
		__DIR__"cloth/qingduanao",
		__DIR__"cloth/skirt",
		__DIR__"cloth/surcoat",
		__DIR__"cloth/wulingjin",
		__DIR__"cloth/xueshan-pao",
		__DIR__"cloth/yuanxiang",
	}));
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
