
inherit NPC;
inherit F_DEALER;
void create()
{
//   reload("ty_leng");
   set_name("冷先生",({ "leng xiansheng","leng"}) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是药店的老板,他这里的药种类很多的。\n");
    set("shop_id",({ "leng xiansheng","leng"}) );
   set("combat_exp", 20000);
   set("str", 25);
   set("per", 24);
 
   set("attitude", "peaceful");
	set("vendor_goods", ({
	  	  __DIR__"obj/yangjingdan",
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
