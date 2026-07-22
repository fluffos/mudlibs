inherit F_VENDOR_SALE;
void create()
{
       set_name("花匠", ({"hua jiang", "jiang"}));
       set_level(4);
       set("long", "东方武馆的花匠，正提着水浇花。\n");
       set("gender", "男性");
       set("age", 26);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set_skill("unarmed",40);
       set("vendor_goods", ([ 
		"seed" : "/d/obj/misc/seed2",
	]));	
       setup();
       add_money("silver", 5);
       carry_object(0,"hand",0)->wear();
       carry_object(0,"cloth",0)->wear();
}

void init() 
{ 
	add_action("do_vendor_list", "list"); 
}