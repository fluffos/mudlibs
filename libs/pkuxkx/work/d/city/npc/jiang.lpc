// yang.c 杨老板 
#include <command.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("江不二", ({ "jiang buer", "jiang" }));
	set("title", "奇珍异宝阁老板");
	set("shen_type", 1);
  set("start_room","/d/city/qizhenge");

	set("gender", "男性");
	set("age", 45);
	set("long",
		"江老板据说是从遥远的波斯过来的，他的名字也是来到扬州以后取得中文名字，\n专门收集销售各地罕见的稀奇玩意儿。\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ({
    "/d/city/obj/silk_mask",
    "/d/city/obj/xyj_mask",
    "/d/city/obj/antidis_book",
    "/d/city/obj/easy_ftools",
    "/d/city/obj/normal_ftools"
	}));
	setup();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}	