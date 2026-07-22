// huoji. 药铺伙计
inherit BHNPC;
inherit F_DEALER;
void create()
{
	set_name("药铺伙计", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 18);
	set("long", "他十分强壮，看上去会几分武功，对药铺生意似乎并不在乎。\n");
      set("area_name","扬州城东大街");
	set("combat_exp", 2500);
	set("attitude", "friendly");
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
}
