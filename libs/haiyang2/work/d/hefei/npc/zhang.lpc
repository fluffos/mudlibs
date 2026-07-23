
inherit NPC;
inherit F_DEALER;

void create()
{
//   reload("hf_zhang");
   set_name("张掌柜",({ "zhang zhanggui","zhang"}) );
        set("gender", "男性" );
        set("age", 42);
   set("long", "这是裁缝店的老板，他这里的衣服很好。\n");
    set("shop_id",({ "zhang zhanggui","zhang"}) );
   set("combat_exp", 200000);
   set("str", 25);
   set("per", 24);
 
   set("attitude", "peaceful");
	set("vendor_goods", ({
	  __DIR__"obj/chouyi",
	   __DIR__"obj/shayi",
	}));
  setup();
   carry_object(__DIR__"obj/chouyi")->wear();
  
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

int regenerate()
{
        set("called", 0);
        return 1;
}
