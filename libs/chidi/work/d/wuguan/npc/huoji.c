// huoji. 药铺伙计
//inherit BHNPC;
//inherit F_DEALER;
inherit F_VENDOR_SALE;
void create()
{
	set_name("药房伙计", ({ "yaofang huoji", "huoji" }));
	set("str", 20);
	set("gender", "男性");
      set("area_name","扬州城东大街");
	set("age", 18);
	set("long", "他是平医师从乡下招来帮忙的。\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/jinchuang",
		__DIR__"obj/yangjing"
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
  {
       object area;
        area=new("/clone/misc/area");
        area->create(query("area_name"));
        set("banghui",(string)area->query("banghui"));
        destruct(area);   
        ::init();

/*
        add_action("do_list", "list");
        add_action("do_buy", "buy");
*/
     add_action("do_vendor_list", "list");
     add_action("do_vendor_buy", "buy");
}
