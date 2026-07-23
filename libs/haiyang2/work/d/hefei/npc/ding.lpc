
inherit NPC;
inherit F_DEALER;

void create()
{
//   reload("hf_ding");
   set_name("丁掌柜",({ "ding zhanggui","ding"}) );
        set("gender", "男性" );
        set("age", 42);
   set("long", "这是药店的老板,他这里的药种类很多的。\n");
    set("shop_id",({ "ding zhanggui","ding"}) );
   set("combat_exp", 200000);
   set("str", 25);
   set("per", 24);
 
   set("attitude", "peaceful");
	set("vendor_goods", ({
	  __DIR__"obj/yangjingdan",
	   __DIR__"obj/buxuedan",
	   __DIR__"obj/huishenwan",
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
