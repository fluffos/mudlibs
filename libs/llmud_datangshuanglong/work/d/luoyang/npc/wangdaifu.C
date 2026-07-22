
inherit F_VENDOR_SALE;
void create()
{
   reload("ly_ma");
   set_name("王大夫",({ "wang daifu","wang"}) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这位是药店的大夫,他的技术可是闻名全城的。\n");
     set("shop_id",({ "wang daifu","wang"}) ); 
   set("combat_exp", 20000);
   set("str", 25);
   set("per", 24);
 
   set("attitude", "peaceful");
   set("vendor_goods",([
	  "yao": "/d/clone/obj/medicine/jinchuang",
                "dan": "/d/clone/obj/medicine/dan",
                "yangjing-dan": "/d/clone/obj/medicine/yangjing-dan",
  ]));
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
  
}

void init()
{
	::init();
	add_action("do_vendor_list", "list");
}

int regenerate()
{
        set("called", 0);
        return 1;
}