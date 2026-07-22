// xiaofan.c 小贩子

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("小贩子", ({ "xiao fan", "xiao", "fan" }) );
	set("gender", "男性" );
	set("age", 34);
	set("long",
		"这位小贩子正笑咪咪地来回忙著，还不时招呼过往的客人进来。\n");
	set("combat_exp", 300);
	set("attitude", "peaceful");
	set("rank_info/respect", "小贩子");
        set("vendor_goods", ({
		(["name":"/d/emei/obj/tieqiao" ,"number":5]),
		(["name":"/d/emei/obj/qingshui-hulu" ,"number":5]),
		(["name":BINGQI_D("zhujian"),"number": 10]),
		(["name":BINGQI_D("changjian"),"number": 10]),
		(["name":MISC_D("fire"),"number": 10]),
        }));

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	add_money("coin", 90);
}

void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}
